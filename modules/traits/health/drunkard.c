//*****************************************************************************
// Copyright (c) 2017 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg)
{
    if (!arg)
    {
        addSpecification("type", "health");
        addSpecification("name", "drunkard");
        addSpecification("description", "You have a rather unhealthy relationship with the bottle.");
        addSpecification("root", "sickly");
        addSpecification("opposing root", "hale");
        addSpecification("opinion", -10);
        addSpecification("penalty to dexterity", 1);
        addSpecification("penalty to constitution", 2);
        addSpecification("penalty to heal hit points rate", 5);
        addSpecification("cost", -1);
        "baseTrait"::reset(arg);
    }
}

