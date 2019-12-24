//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg)
{
    if (!arg)
    {
        addSpecification("type", "professional");
        addSpecification("name", "journeyman engineer");
        addSpecification("description", "You are an adept engineer");
        addSpecification("root", "engineer");
        addSpecification("opinion", 1);
        addSpecification("bonus engineering", 10);
        addSpecification("bonus mathematics", 5);
        addSpecification("bonus physics", 5);

        "baseTrait"::reset(arg);
    }
}