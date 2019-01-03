//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/armor.c";

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg) 
{
    if (!arg) 
    {
        set("name", "Scale armor");
        set("short", "Scale armor");
        set("aliases", ({ "armor", "scale", "scale armor" }));
        set("blueprint", "scale armor");
    }
}
