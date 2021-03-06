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
        addSpecification("name", "open-minded");
        addSpecification("description", "You are a free thinker who is very "
            "open to considering the arguments of others.");
        addSpecification("root", "open-minded");
        addSpecification("opinion", 15);
        addSpecification("bonus diplomacy", 1);
        "baseTrait"::reset(arg);
    }
}
