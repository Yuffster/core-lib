//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg)
{
    if (!arg)
    {
        passiveResearchItem::reset(arg);
        addSpecification("name", "An Craban");
        addSpecification("source", "Aegis Guard");
        addSpecification("description", "This skill provides the user with the "
            "knowledge of a defensive maneuver where the blade is "
            "held to the side with the pommel near the hip, tip pointed at the "
            "foe's chest.");
        addSpecification("limited by", (["equipment":({ "dagger", "short sword",
            "long sword", "hand and a half sword", "two-handed sword" })]));

        addPrerequisite("level", 
            (["type":"level", 
              "guild": "Aegis Guard",
              "value": 4 ]));

        addPrerequisite("guilds/aegis-guard/forms/sword/an-vund.c",
            (["type":"research"]));

        addSpecification("scope", "self");
        addSpecification("research type", "points");
        addSpecification("research cost", 1);
        addSpecification("bonus defense", 2);
        addSpecification("bonus parry", 2);
        addSpecification("equivalence", "the plow");
    }
}