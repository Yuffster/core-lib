//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/food.c";

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg) 
{
    if (!arg) 
    {
        set("name", "Pinto Bean");
        set("short", "Pinto Bean");
        set("aliases", ({ "bean", "pinto bean" }));
        set("blueprint", "pinto bean");
    }
}
