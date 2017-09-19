//*****************************************************************************
// Copyright (c) 2017 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************

private mapping environmentalElements = ([
    "terrain":([]),
    "interior": ([]),
    "feature": ([]),
    "building": ([]),
    "item": ([])
]);

private mapping aliasesToElements = ([]);

private mapping exits = ([]);
private string State = "default";
private nosave string Description = "[0;33m%s\n[0m";
private nosave string Exits = "[0;30;1m -=-=- %s\n[0m";
private nosave string InventoryItem = "[0;36m%s\n[0m";

/////////////////////////////////////////////////////////////////////////////
private object environmentDictionary()
{
    return load_object("/lib/dictionaries/environmentDictionary.c");
}

/////////////////////////////////////////////////////////////////////////////
public nomask varargs string currentState(string newState)
{
    if (newState && stringp(newState))
    {
        State = newState;
    }
    return State;
}

/////////////////////////////////////////////////////////////////////////////
protected nomask string capitalizeSentences(string message)
{
    string ret = regreplace(message, "^[a-z]", #'upper_case, 1);
        ret = regreplace(ret, "[.!?] +[a-z]", #'upper_case, 1);
            ret = regreplace(ret, "  ", " ");
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask void setUpAliases(string element)
{
    object environmentalObj = environmentDictionary()->environmentalObject(element);
    foreach(string state in environmentalObj->states())
    {
        aliasesToElements[state] = ([]);
        foreach(string alias in environmentalObj->aliases(state))
        {
            aliasesToElements[state][alias] = program_name(environmentalObj);
        }
    }
}

/////////////////////////////////////////////////////////////////////////////
private nomask int addEnvironmentalElement(string element, string type, string location)
{
    int ret = 1;
    if (!environmentDictionary()->isValidEnvironmentItem(element))
    {
        ret = environmentDictionary()->registerElement(element, type);
        if (ret)
        {
            element = load_object(element)->Name();
        }
        else if(environmentDictionary()->isValidEnvironmentItem(element))
        {
            raise_error(sprintf("ERROR in environment.c: Unable to register '%s'. "
                "A conflicting item with that name already exists.\n", element));
        }
        else
        {
            raise_error(sprintf("ERROR in environment.c: Unable to register '%s'. "
                "Be sure that the file exists and inherits a valid environmental "
                "element.\n", element));
        }
    }

    if (ret && environmentDictionary()->isValidEnvironmentItem(element, type))
    {
        if (!member(environmentalElements[type], element))
        {
            environmentalElements[type][element] = ({});
        }
        environmentalElements[type][element] =
            m_indices(mkmapping(environmentalElements[type][element] +
                ({ location }) - ({ 0 })));
        setUpAliases(element);
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
protected nomask varargs void addFeature(string feature, string location)
{
    if (!addEnvironmentalElement(feature, "feature", location))
    {
        raise_error(sprintf("ERROR in environment.c: '%s' is not a "
            "valid feature.\n", feature));
    }
}

/////////////////////////////////////////////////////////////////////////////
protected nomask varargs void addItem(string item, string location)
{
    if (!addEnvironmentalElement(item, "item", location))
    {
        raise_error(sprintf("ERROR in environment.c: '%s' is not a "
            "valid item.\n", item));
    }
}

/////////////////////////////////////////////////////////////////////////////
protected nomask varargs void addExit(string direction, string path, string state)
{
    if (!state)
    {
        state = "default";
    }
    if (!stringp(direction) || !stringp(path))
    {
        raise_error(sprintf("ERROR in environment.c: '%s' must be a string and "
            "'%s' must be a valid destination file.\n", direction, path));
    }
    if (!member(exits, state))
    {
        exits[state] = ([]);
    }
    exits[state][direction] = path;
}

/////////////////////////////////////////////////////////////////////////////
protected nomask varargs void addBuilding(string feature, string location, string path, string state)
{
    if (addEnvironmentalElement(feature, "building", location) && stringp(path))
    {
        addExit(location, path, state);
    }
    else
    {
        raise_error(sprintf("ERROR in environment.c: '%s' is not a "
            "valid building.\n", feature));
    }
}

/////////////////////////////////////////////////////////////////////////////
protected nomask void setTerrain(string terrain)
{
    if (sizeof(environmentalElements["terrain"]) ||
        sizeof(environmentalElements["interior"]))
    {
        raise_error("ERROR in environment.c: Only one terrain OR one "
            "interior can be set.\n");
    }
    else if (!addEnvironmentalElement(terrain, "terrain", "none"))
    {
        raise_error(sprintf("ERROR in environment.c: '%s' is not a "
            "valid terrain.\n", terrain));
    }
}

/////////////////////////////////////////////////////////////////////////////
protected nomask void setInterior(string interior)
{
    if (sizeof(environmentalElements["terrain"]) ||
        sizeof(environmentalElements["interior"]))
    {
        raise_error("ERROR in environment.c: Only one terrain OR one "
            "interior can be set.\n");
    }
    else if (!addEnvironmentalElement(interior, "interior", "none"))
    {
        raise_error(sprintf("ERROR in environment.c: '%s' is not a "
            "valid interior.\n", interior));
    }
}

/////////////////////////////////////////////////////////////////////////////
private string getFeatureDescriptions()
{
    string ret = "";

    if (sizeof(environmentalElements["feature"]))
    {
        string *features = sort_array(
            m_indices(environmentalElements["feature"]), (: $1 > $2 :));
        foreach(string feature in features)
        {
            string directions = "";

            if (sizeof(environmentalElements["feature"][feature]))
            {
                directions = " to the " + 
                    implode(environmentalElements["feature"][feature], ", ");
                directions = regreplace(directions, ",([^,]+)$", " and\\1");
            }

            object featureObj = 
                environmentDictionary()->environmentalObject(feature);
            if (featureObj)
            {
                ret += directions + " you see " +
                    featureObj->description(currentState()) + ".";
            }
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private string getBaseDescriptionForType(string type)
{
    string ret = 0;
    if (member(environmentalElements, type) && sizeof(environmentalElements[type]))
    {
        string element = m_indices(environmentalElements[type])[0];
        object base = environmentDictionary()->environmentalObject(element);
        if (base)
        {
            ret = base->description(currentState());
        }
        else
        {
            raise_error(sprintf("ERROR in environment.c: Failed to load "
                "%s '%s'.\n", type, element));
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private string getExitDescription()
{
    string ret = "";

    string *exitList = ({});
   
    if (member(exits, currentState()))
    {
        exitList += m_indices(exits[currentState()]);
    }
    if (member(exits, "default"))
    {
        exitList += m_indices(exits["default"]);
    }
    exitList = m_indices(mkmapping(exitList));

    int numExits = sizeof(exitList);
    if(numExits)
    {
        ret = sprintf(Exits, sprintf("There %s %s obvious exit%s: %s",
            numExits == 1 ? "is" : "are",
            environmentDictionary()->convertNumberToString(numExits),
            numExits == 1 ? "" : "s",
            implode(exitList, ", ")));
    }
    else
    {
        ret = sprintf(Exits, "There are no obvious exits.");
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private string getInventoryDescription()
{
    string ret = "";
    object *environmentInventory = all_inventory(this_object());
    if (sizeof(environmentInventory))
    {
        foreach(object environmentItem in environmentInventory)
        {
            string shortDesc = environmentItem->short();
            if (shortDesc && (shortDesc != ""))
            {
                ret += sprintf(InventoryItem, capitalize(shortDesc));
            }
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public string long(string item)
{
    string ret = getBaseDescriptionForType("terrain");
    if (!ret)
    {
        ret = getBaseDescriptionForType("interior");
    }

    if (ret)
    {
        ret += getFeatureDescriptions();
    }
    else
    {
        raise_error("ERROR in environment.c: Either a valid terrain or "
            "interior must be set.\n");
    }
    return sprintf(Description, capitalizeSentences(ret)) + 
        getExitDescription() + getInventoryDescription();
}

/////////////////////////////////////////////////////////////////////////////
public nomask int isEnvironmentalElement(string item)
{
    return member(aliasesToElements, currentState()) &&
        member(aliasesToElements[currentState()], item);
}

/////////////////////////////////////////////////////////////////////////////
public nomask object getEnvironmentalElement(string item)
{
    object ret = 0;

    if (isEnvironmentalElement(item))
    {
        ret = load_object(aliasesToElements[currentState()][item]);
        ret->currentState(currentState());
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public int move(string str)
{
    string direction = query_verb();
    string destination = 0;

    if (member(exits, currentState()) && 
        member(exits[currentState()], direction))
    {
        destination = exits[currentState()][direction];
    }
    else if (member(exits, "default") &&
        member(exits["default"], direction))
    {
        destination = exits["default"][direction];
    }
    if (destination)
    {
        this_player()->move(destination, direction);
    }
    return destination && stringp(destination);
}

/////////////////////////////////////////////////////////////////////////////
public void init()
{
    string *directions = ({});
    if (member(exits, currentState()) && sizeof(exits[currentState()]))
    {
        directions += m_indices(exits[currentState()]);
    }
    if (member(exits, "default") && sizeof(exits["default"]))
    {
        directions += m_indices(exits["default"]);
    }

    if (sizeof(directions))
    {
        directions = m_indices(mkmapping(directions));
        foreach(string direction in directions)
        {
            add_action("move", direction);
        }
    }
}

/////////////////////////////////////////////////////////////////////////////
public int moveFromIsAllowed(object user, object fromLocation)
{
    return 1;
}

/////////////////////////////////////////////////////////////////////////////
public int moveToIsAllowed(object user, object toLocation)
{
    return 1;
}
