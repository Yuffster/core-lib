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
        addSpecification("type", "genetic");
        addSpecification("name", "slow");
        addSpecification("description", "You are a bit of a simpleton.");
        addSpecification("root", "unintelligent");
        addSpecification("opposing root", "intelligent");
        addSpecification("opinion", -5);
        addSpecification("penalty to intelligence", 2);
        addSpecification("cost", -1);
        "baseTrait"::reset(arg);
    }
}

