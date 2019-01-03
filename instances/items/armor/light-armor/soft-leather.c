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
        set("name", "Soft leather");
        set("short", "Soft leather");
        set("aliases", ({ "armor", "leather", "soft leather" }));
        set("blueprint", "soft leather");
    }
}
