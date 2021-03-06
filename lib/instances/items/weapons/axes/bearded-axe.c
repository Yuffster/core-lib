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
        set("name", "Bearded axe");
        set("short", "Bearded axe");
        set("aliases", ({ "axe", "bearded axe" }));
        set("blueprint", "bearded axe");
    }
}
