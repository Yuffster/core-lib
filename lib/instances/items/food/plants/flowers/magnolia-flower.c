//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/food.c";

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg) 
{
    if (!arg) 
    {
        set("name", "Magnolia Flower");
        set("short", "Magnolia Flower");
        set("aliases", ({ "magnolia flower", "magnolia" }));
        set("blueprint", "magnolia flower");
    }
}
