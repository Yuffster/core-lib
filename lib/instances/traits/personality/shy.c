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
        addSpecification("name", "shy");
        addSpecification("description", "You tend to lack confidence in "
            "yourself and generally show a lack of courage when interacting "
            "with others.");
        addSpecification("root", "coward");
        addSpecification("opinion", -1);
        addSpecification("penalty to persuasion", 1);
        "baseTrait"::reset(arg);
    }
}
