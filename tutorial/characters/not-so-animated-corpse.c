//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/corpse.c";
object bow;

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg)
{
    if (!arg)
    {
        set("short", "A decaying corpse");
        set("corpse", "human");
        set("aliases", ({ "decaying corpse", "corpse" }));

        if (!bow)
        {
            move_object(clone_object("/lib/instances/items/weapons/bows/bow.c"), 
                this_object());
        }
    }
}
