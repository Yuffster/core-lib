//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/weapon.c";

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg) 
{
    if (!arg) 
    {
        set("name", "Pollaxe");
        set("short", "Pollaxe");
        set("aliases", ({ "axe", "pollaxe", "pole axe" }));
        set("blueprint", "pollaxe");
    }
}
