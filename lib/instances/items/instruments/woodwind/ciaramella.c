//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/instrument.c";

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg) 
{
    if (!arg) 
    {
        set("name", "Ciaramella");
        set("short", "Ciaramella");
        set("aliases", ({ "ciaramella", "pipes" }));
        set("blueprint", "ciaramella");
    }
}
