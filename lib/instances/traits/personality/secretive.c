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
        addSpecification("name", "secretive");
        addSpecification("description", "You are inclined to conceal your "
            "motivations and feelings.");
        addSpecification("root", "secretive");
        addSpecification("opinion", -5);
        "baseTrait"::reset(arg);
    }
}
