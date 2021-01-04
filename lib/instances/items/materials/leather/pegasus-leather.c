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
        set("name", "Pegasus leather");
        set("short", "Pegasus leather");
        set("aliases", ({ "leather", "pegasus leather" }));
        set("blueprint", "pegasus leather");
    }
}
