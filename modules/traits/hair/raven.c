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
        addSpecification("name", "raven black hair");
        addSpecification("description", "Your hair is glossy black with faint bluish highlights.");
        addSpecification("root", "hair");
        "baseTrait"::reset(arg);
    }

}

