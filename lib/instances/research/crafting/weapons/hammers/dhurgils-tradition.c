//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg)
{
    if (!arg)
    {
        passiveResearchItem::reset(arg);
        addSpecification("name", "Dhurgil's Tradition");
        addSpecification("source", "crafting");
        addSpecification("description", "This skill provides the user with the "
            "techniques mastered by the great smiths of Dhurgil.");
        addSpecification("research type", "points");
        addSpecification("research cost", 1);

        addPrerequisite("lib/instances/research/crafting/weapons/hammers/tengredhs-legacy.c", 
            (["type":"research"]));
        addPrerequisite("weapon smithing", (["type":"skill", "value" : 30]));
        addPrerequisite("blacksmithing", (["type":"skill", "value" : 25]));
        addPrerequisite("metal crafting", (["type":"skill", "value" : 25]));

        addSpecification("limited by", (["crafting type":"hammer"]));

        addSpecification("bonus crafting value multiplier", 30);
        addSpecification("bonus crafting encumberance reduction", 10);
        addSpecification("bonus crafting weapon class", 1);
        addSpecification("bonus crafting defense class", 1);
        addSpecification("bonus crafting attack", 1);
        addSpecification("bonus blacksmithing", 3);
        addSpecification("bonus metal crafting", 3);
        addSpecification("bonus weapon smithing", 3);
    }
}
