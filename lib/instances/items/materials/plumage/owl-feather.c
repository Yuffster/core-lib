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
        set("name", "Owl Feather");
        set("short", "Owl Feather");
        set("aliases", ({ "feather", "owl feather" }));
        set("blueprint", "owl feather");
    }
}
