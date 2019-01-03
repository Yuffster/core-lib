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
        addSpecification("type", "persona");
        addSpecification("name", "hell hound");
        addSpecification("description", "You are a hell hound.");
        addSpecification("root", "creature persona");
        addSpecification("bonus resist fire", 50);
        addSpecification("bonus resist evil", 50);
        "baseTrait"::reset(arg);
    }
}
