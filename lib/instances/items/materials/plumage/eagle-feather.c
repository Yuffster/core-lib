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
        set("name", "Eagle Feather");
        set("short", "Eagle Feather");
        set("aliases", ({ "feather", "eagle feather" }));
        set("blueprint", "eagle feather");
    }
}
