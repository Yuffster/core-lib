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
        set("name", "Hummingbird Feather");
        set("short", "Hummingbird Feather");
        set("aliases", ({ "feather", "hummingbird feather" }));
        set("blueprint", "hummingbird feather");
    }
}
