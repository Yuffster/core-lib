//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/material.c";

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg) 
{
    if (!arg) 
    {
        set("name", "Robin Feather");
        set("short", "Robin Feather");
        set("aliases", ({ "feather", "robin feather" }));
        set("blueprint", "robin feather");
    }
}
