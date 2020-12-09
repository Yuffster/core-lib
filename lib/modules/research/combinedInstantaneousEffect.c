//*****************************************************************************
// Class: instantaneousEffect
// File Name: instantaneousEffect.c
//
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************

virtual inherit "/lib/core/specification.c";
virtual inherit "/lib/core/prerequisites.c";
virtual inherit "/lib/commands/baseCommand.c";
virtual inherit "/lib/modules/research/effectModifier.c";

private string *validEffects = ({ 
    "increase hit points", 
    "increase spell points",
    "increase stamina points", 
    "decrease intoxication",
    "decrease druggedness", 
    "decrease soaked", 
    "decrease stuffed",
    "damage hit points", 
    "damage spell points", 
    "damage stamina points",
    "increase intoxication", 
    "increase druggedness", 
    "increase soaked",
    "increase stuffed" 
});

private string *validCombinationTypes = ({
    "must include only one of",
    "must include any of",
    "can include only one of",
    "can include any of",
});

private mapping combinationResearchItems = ([]);

/////////////////////////////////////////////////////////////////////////////
private nomask int isValidFormula(mapping *formulas)
{
    int ret = 0;
    
    if(formulas && pointerp(formulas) && sizeof(formulas))
    {
        ret = 1;
        
        // At the end of the loop, this MUST be 100
        int cumulativeProbability = 0;
        
        foreach(mapping formula in formulas)
        {
            ret &&= (formula && mappingp(formula) && 
                member(formula, "probability") && 
                intp(formula["probability"])) &&
                ((member(formula, "base damage") && 
                intp(formula["base damage"]) &&
                member(formula, "range") && 
                intp(formula["range"])) || 
                (member(formula, "custom method") &&
                stringp(formula["custom method"]) &&
                function_exists(formula["custom method"], this_object())));
                
            if(ret)
            {
                cumulativeProbability += formula["probability"];
            }
        }
        
        ret &&= cumulativeProbability == 100;
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask int validateCombinationSet(mapping combinations)
{
    int ret = 0;

    if (mappingp(combinations) && sizeof(combinations))
    {
        ret = 1;
        object dictionary = getDictionary("research");
        foreach(string key in combinations)
        {
            ret &&= (member(validCombinationTypes, key) > -1) &&
                pointerp(combinations[key]) &&
                sizeof(combinations[key]);

            if (ret)
            {
                foreach(string researchItem in combinations[key])
                {
                    object researchObj =
                        dictionary->researchObject(researchItem);

                    ret &&= objectp(researchObj);
                    if (ret)
                    {
                        string itemName = lower_case(researchObj->query("name"));

                        if (member(combinationResearchItems, itemName))
                        {
                            raise_error(sprintf("ERROR - "
                                "combinedInstantaneousEffect: items (%s) can only "
                                "be placed once in only one of 'must include only "
                                "one of', 'must include any of', 'can include only "
                                "one of', or 'can include any of'.\n", researchItem));
                        }
                        combinationResearchItems[itemName] = researchItem;
                    }
                }
            }
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
protected nomask int applyFormula(object initiator, int initialAmount,
    string type)
{
    int ret = 0;
    
    if(member(specificationData, type) && isValidFormula(specificationData[type]))
    {
        // First, build the probability dictionary
        mapping formulaDictionary = ([ ]);
        
        int currentProbability = 0;
        foreach(mapping formula in specificationData[type])
        {      
            int bottomOfRange = currentProbability;
            int topOfRange = bottomOfRange + formula["probability"];
            
            int tmpFormula = 0;
            // If this exists, we already know that we have this method 
            // available since we passed the call to isValidFormula.
            if(member(formula, "custom method"))
            {
                tmpFormula = initialAmount +
                    call_other(this_object(), formula["custom method"], 
                               initiator);
            }
            else
            {
                tmpFormula = initialAmount +
                    formula["base damage"] + random(formula["range"] + 1);
            }

            for(int i = bottomOfRange; i < topOfRange; i++)
            {
                formulaDictionary[i] = tmpFormula;
            }
                
            currentProbability += formula["probability"];       
        }
        
        ret = formulaDictionary[random(100)];
        
        if(member(specificationData, "modifiers"))
        {
            ret = applyModifiers(ret, initiator, specificationData["modifiers"]);
        }
    }    
    return ret;    
}

/////////////////////////////////////////////////////////////////////////////
protected nomask int addInstantaneousSpecification(string type, mixed value)
{
    int ret = 0;

    switch(type)
    {
        case "increase hit points":
        case "increase spell points":
        case "increase stamina points":
        case "decrease intoxication":
        case "decrease druggedness":
        case "decrease soaked":
        case "decrease stuffed":
        {
            specificationData["is beneficial"] = 1;
            // This should fall through to the next session.
        }
        case "damage hit points":
        case "damage spell points":
        case "damage stamina points":        
        case "increase intoxication":
        case "increase druggedness":
        case "increase soaked":
        case "increase stuffed":
        {
            if(isValidFormula(value))
            {
                specificationData[type] = value;
                ret = 1;
            }
            else
            {
                raise_error(sprintf("ERROR - combinedInstantaneousEffect: "
                    "the '%s' specification must be a properly formatted "
                    "formula.\n" , type));
            }
            break;
        }
        case "max combination chain modifier":
        case "modifiers":
        {
            if(value && pointerp(value) && sizeof(value) && mappingp(value[0]))
            {
                int validModifier = 1;
                foreach(mapping modifierValue in value)
                {
                    validModifier &&= isValidModifier(modifierValue);
                }
                if(validModifier)
                {
                    specificationData[type] = value;
                    ret = 1;
                }
                else
                {
                    raise_error(sprintf("ERROR - combinedInstantaneousEffect: "
                        "the '%s' specification must be a properly formatted "
                        "modifier.\n" , type));
                }                
            }
            else
            {
                raise_error(sprintf("ERROR - combinedInstantaneousEffect: "
                    "the '%s' specification must be a properly formatted "
                    "modifier.\n" , type));
            }
            break;
        }      
        case "damage type":
        {
            object attacks = getDictionary("attacks");
            if(stringp(value) && attacks && attacks->isValidDamageType(value))
            {
                specificationData[type] = value;
                ret = 1;
            }
            else
            {
                raise_error("ERROR - combinedInstantaneousEffect: the "
                    "'damage type' specification must be a valid attack type "
                    "as defined in attacksDictionary.\n");
            }
            break;
        }
        case "maximum combination chain":
        {
            object attacks = getDictionary("attacks");
            if(intp(value) && (value > 0))
            {
                specificationData[type] = value;
                ret = 1;
            }
            else
            {
                raise_error("ERROR - combinedInstantaneousEffect: the "
                    "'maximum combination chain' specification must be a "
                    "positive integer.\n");
            }
            break;
        }
        case "combination rules":
        {
            if (validateCombinationSet(value))
            {
                specificationData[type] = value;
                ret = 1;
            }
            else
            {
                raise_error("ERROR - combinedInstantaneousEffect: the "
                    "'combination rules' specification must be a "
                    "valid rule set.\n");
            }
            break;
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
protected int applyBeneficialEffect(object initiator, object *combo)
{
    return 0;
}

/////////////////////////////////////////////////////////////////////////////
protected int applyEffect(object initiator, object target, object *combo)
{
    return 0;
}
   
/////////////////////////////////////////////////////////////////////////////
private nomask int getMaximumSizeOfChainedCombination(object owner)
{
    int ret = specificationData["maximum combination chain"];
        
    if(member(specificationData, "max combination chain modifier"))
    {
        ret = applyModifiers(ret, owner,
            specificationData["max combination chain modifier"]);
    }

    if (!ret)
    {
        raise_error("ERROR - combinedInstantaneousEffect: the "
            "'maximum combination chain' specification must be set.\n");
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask mapping getComboRulesFor(string *comboItems, string type)
{
    mapping ret = ([]);

    if (sizeof(comboItems) == sizeof(filter(comboItems, 
        (: (member($2, $1) > -1) :), m_indices(combinationResearchItems))))
    {
        mapping rules = specificationData["combination rules"];
        string *list = member(rules, type) ? filter(comboItems,
            (: (member($2[$3], combinationResearchItems[$1]) > -1) :), 
            rules, type) : ({});

        ret = filter(combinationResearchItems,
            (: (member($3, $1) > -1) :), list);
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
protected nomask object *getCombinationList(string unparsedCommand, 
    object owner)
{
    object *ret = ({});
    string *comboItems = explode(regreplace(unparsedCommand,
        "combination (.*)( at .*)*", "\\1"), " ");

    if ((sizeof(comboItems) > 1) &&
        (sizeof(comboItems) <= getMaximumSizeOfChainedCombination(owner)))
    {

        mapping validComboItems = 
            getComboRulesFor(comboItems, "must include only one of") +
            getComboRulesFor(comboItems, "must include any of") +
            getComboRulesFor(comboItems, "can include only one of") +
            getComboRulesFor(comboItems, "can include any of");

        object dictionary = getDictionary("research");

        foreach(string item in m_values(validComboItems))
        {
            if (owner->isResearched(item))
            {
                ret += ({ dictionary->researchObject(item) });
            }
        }
        ret -= ({ 0 });
    }

    if (sizeof(ret) != sizeof(comboItems))
    {
        displayMessage("That is an invalid combination.\n",
            owner, owner);
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
protected nomask int applyAllFormulas(object *combo, object owner,
    string type)
{
    int ret = 0;

    if (combo && sizeof(combo))
    {
        object dictionary = getDictionary("research");
        foreach(string item in combo)
        {
            object research = dictionary->researchObject(item);
            if (research && research->query(type))
            {
                mapping researchData = research->getEffectsToApply(owner);
                if (member(researchData["effects"], type))
                {
                    ret += researchData["effects"][type];
                }
            }
        }
    }
    return applyFormula(owner, ret, type);
}

/////////////////////////////////////////////////////////////////////////////
private nomask string getComboMessage(string initialMessage, object *combo)
{
    string ret = initialMessage;

    string *messages = ({});
    if (sizeof(combo))
    {
        object dictionary = getDictionary("research");

        foreach(string item in combo)
        {
            if (item->query("use combination message"))
            {
                messages += ({ item->query("use combination message") });
            }
        }
    }

    ret += sizeof(messages) ? regreplace(messages, 
        implode(messages, (sizeof(messages) == 2) ? " and " : ", "),
        ", ([^,]+)$", ", and \\1", 1) : "";
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
protected nomask int executeOnSelf(string unparsedCommand, object owner,
    string researchName)
{
    int ret = 0;

    // checks for this item being researched are already done in execute()
    // as are checks to verify that owner is a living object. We don't
    // allow the caster to do negative things to themselves here...    
    object *combo = getCombinationList(unparsedCommand, owner);
    ret = applyBeneficialEffect(owner, combo);

    if(ret && member(specificationData, "use ability message") &&
       stringp(specificationData["use ability message"]))
    {
        displayMessage(getComboMessage(
            specificationData["use ability message"], combo),
            owner, owner);
    }   
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
protected nomask int executeOnTarget(string unparsedCommand, object owner,
    object researchName)
{
    int ret = 0;
    object target = getTarget(owner, unparsedCommand);

    if(target)
    {
        object *combo = getCombinationList(unparsedCommand, owner);

        if(member(specificationData, "use ability message") &&
           stringp(specificationData["use ability message"]))
        {
            displayMessage(getComboMessage(
                specificationData["use ability message"], combo),
                owner, target);
        }
        ret = applyEffect(owner, target, combo);
    }
    else
    {
        displayMessageToSelf("You must specify a target.\n", owner);
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
protected nomask int executeInArea(string unparsedCommand, object owner,
    string researchName)
{
    int ret = 1;

    object *environmentObjects = filter(all_inventory(environment(owner)),
        (: $1 != $2 :), owner);

    object *combo = getCombinationList(unparsedCommand, owner);

    foreach(object target in environmentObjects)
    {
        if(function_exists("has", target) && target->has("combat"))
        {
            ret += applyEffect(owner, target, combo);
        }
    }
          
    if(member(specificationData, "use ability message") 
       && stringp(specificationData["use ability message"]))
    {
        displayMessage(getComboMessage(
            specificationData["use ability message"], combo),
            owner, owner);
    }
    return ret;
}
