//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/material.c";

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg) 
{
    if (!arg) 
    {
        set("name", "Crow Feather");
        set("short", "Crow Feather");
        set("aliases", ({ "feather", "crow feather" }));
        set("blueprint", "crow feather");
    }
}
