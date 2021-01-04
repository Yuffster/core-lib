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
        set("name", "Nectarine");
        set("short", "Nectarine (Wood)");
        set("aliases", ({ "wood", "nectarine" }));
        set("blueprint", "nectarine");
    }
}
