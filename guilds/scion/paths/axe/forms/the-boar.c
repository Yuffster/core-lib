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
        addSpecification("name", "The Boar");
        addSpecification("source", "Scion of Dhuras Guild");
        addSpecification("description", "This skill provides the user with the "
            "knowledge of a defensive maneuver where the dominant foot is "
            "back and the other foot placed forward, both knees bent. The "
            "haft is held at the waist with the axe's edge pointed at the foe's "
            "face. From this position, it is possible to easily launch "
            "a reverse strike.");
        addSpecification("limited by", (["equipment":({
            "axe" })]));

        addPrerequisite("level", 
            (["type":"level", 
              "guild": "Scion of Dhuras",
              "value": 8 ]));

        addPrerequisite("guilds/scion/paths/axe/forms/eisenport.c",
            (["type":"research"]));

        addSpecification("scope", "self");
        addSpecification("research type", "points");
        addSpecification("research cost", 1);
        addSpecification("bonus defense", 1);
        addSpecification("bonus attack", 2);
        addSpecification("bonus parry", 1);
    }
}
