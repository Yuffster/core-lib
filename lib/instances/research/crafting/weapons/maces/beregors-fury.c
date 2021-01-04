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
        addSpecification("name", "Beregor's Fury");
        addSpecification("source", "crafting");
        addSpecification("description", "This skill provides the user with the "
            "amazing techniques mastered by the great maegenstryd smith Beregor.");
        addSpecification("research type", "points");
        addSpecification("research cost", 1);

        addPrerequisite("lib/instances/research/crafting/weapons/maces/beregors-legacy.c", 
            (["type":"research"]));
        addPrerequisite("weapon smithing", (["type":"skill", "value" : 26]));
        addPrerequisite("blacksmithing", (["type":"skill", "value" : 23]));
        addPrerequisite("metal crafting", (["type":"skill", "value" : 23]));
        addPrerequisite("gem crafting", (["type":"skill", "value" : 21]));

        addSpecification("limited by", (["crafting type": ({"mace", "flail"})]));

        addSpecification("bonus crafting value multiplier", 30);
        addSpecification("bonus crafting weapon class", 1);
        addSpecification("bonus crafting defense class", 1);
        addSpecification("bonus crafting attack", 2);
    }
}
