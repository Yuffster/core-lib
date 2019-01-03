//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/weapon.c";

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg) 
{
    if (!arg) 
    {
        set("name", "Recurve bow");
        set("short", "Recurve bow");
        set("aliases", ({ "bow", "recurve bow" }));
        set("blueprint", "recurve bow");
    }
}
