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
        addSpecification("name", "upright");
        addSpecification("description", "You are sincere in your actions and "
            "try to always act in an honorable and honest manner.");
        addSpecification("root", "honorable");
        addSpecification("opposing root", "dishonorable");
        addSpecification("opinion", 10);
        addSpecification("opposing opinion", -5);
        addSpecification("bonus persuasion", 1);
        addSpecification("penalty to bluff", 1);
        "baseTrait"::reset(arg);
    }
}
