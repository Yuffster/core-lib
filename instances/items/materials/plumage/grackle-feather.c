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
        set("name", "Grackle Feather");
        set("short", "Grackle Feather");
        set("aliases", ({ "feather", "grackle feather" }));
        set("blueprint", "grackle feather");
    }
}
