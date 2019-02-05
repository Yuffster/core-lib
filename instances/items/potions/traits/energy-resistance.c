//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg)
{
    if (!arg)
    {
        addSpecification("type", "effect");
        addSpecification("name", "Energy Resistance");
        addSpecification("description", "You have quaffed the 'Energy "
            "Resistance' potion and are currently benefitting from its effects.");
        addSpecification("root", "resisting");
        addSpecification("opposing root", "vulnerable");
        addSpecification("opinion", 1);
        addSpecification("duration", 180);
        addSpecification("bonus resist energy", 50);
        addSpecification("expire message", "The effects of the 'Energy "
            "Resistance' potion subside.");
        "baseTrait"::reset(arg);
    }
}
