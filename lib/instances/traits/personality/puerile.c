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
        addSpecification("name", "puerile");
        addSpecification("description", "You tend toward trivial, "
            "often childish and silly behavior. Grow up.");
        addSpecification("root", "pretentious");
        addSpecification("opinion", -10);
        addSpecification("penalty to persuasion", 1);
        addSpecification("penalty to etiquette", 1);
        addSpecification("penalty to diplomacy", 1);
        "baseTrait"::reset(arg);
    }
}
