//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg)
{
    if (!arg)
    {
        addSpecification("type", "personality");
        addSpecification("name", "righteous");
        addSpecification("description", "You feel that you are always on the "
            "moral high-ground - and you can prove it to any that will listen.");
        addSpecification("root", "arrogant");
        addSpecification("opposing root", "humble");
        addSpecification("opinion", 5);
        addSpecification("opposing opinion", -5);
        addSpecification("penalty to diplomacy", 1);
        "baseTrait"::reset(arg);
    }
}
