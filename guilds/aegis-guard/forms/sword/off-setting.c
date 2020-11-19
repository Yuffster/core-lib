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
        addSpecification("name", "Off-setting");
        addSpecification("source", "Aegis Guard");
        addSpecification("description", "This skill provides the user with the "
            "knowledge of a maneuver wherein a hew or thrust is "
            "deflected at the same time as a counter-stab is initiated.");
        
        addSpecification("limited by", (["equipment":({
            "long sword", "hand and a half sword", "two-handed sword" })]));

        addPrerequisite("level", 
            (["type":"level", 
              "guild": "Aegis Guard",
              "value": 17 ]));

        addPrerequisite("guilds/aegis-guard/forms/sword/stabbing.c",
            (["type":"research"]));
        addPrerequisite("guilds/aegis-guard/forms/sword/over-hew.c",
            (["type":"research"]));
        addPrerequisite("guilds/aegis-guard/forms/sword/dance-of-death.c",
            (["type":"research"]));

        addSpecification("scope", "self");
        addSpecification("research type", "points");
        addSpecification("research cost", 1);
        addSpecification("bonus dodge", 4);
        addSpecification("bonus attack", 1);
        addSpecification("equivalence", "off-setting");
    }
}
