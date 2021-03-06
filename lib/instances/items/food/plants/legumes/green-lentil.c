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
        set("name", "Green Lentil");
        set("short", "Green Lentil");
        set("aliases", ({ "lentil", "green lentil" }));
        set("blueprint", "green lentil");
    }
}
