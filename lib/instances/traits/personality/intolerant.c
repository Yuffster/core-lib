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
        addSpecification("name", "intolerant");
        addSpecification("description", "The world is peopled with those of "
            "lesser... well... everything. These wretches should be treated "
            "with scorn and disdain. They are unworthy of your time or "
            "consideration.");
        addSpecification("root", "arrogant");
        addSpecification("opposing root", "humble");
        addSpecification("opinion", 5);
        addSpecification("opposing opinion", -15);
        addSpecification("penalty to diplomacy", 1);
        "baseTrait"::reset(arg);
    }
}
