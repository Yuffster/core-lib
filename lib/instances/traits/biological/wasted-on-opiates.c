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
        addSpecification("type", "health");
        addSpecification("name", "wasted on opiates");
        addSpecification("description", "You are under the influence of strong opiates.");
        addSpecification("root", "biological");
        addSpecification("opinion", -50);
        addSpecification("duration", 360);
        addSpecification("expire message", "You are no longer wasted.");
        "baseTrait"::reset(arg);
    }
}
