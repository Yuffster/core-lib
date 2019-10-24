//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/lib/environment/interiors/limestone-interior-shop.c");
    addItem("/lib/environment/items/lighting/sconce.c", "north");
    addItem("/lib/environment/items/lighting/sconce.c", "south");
    addItem("/lib/environment/items/lighting/window.c", "east");

    addExit("west", "/lib/tutorial/eledhel/southern-city/swordsmith/0x1.c");
    addExitWithDoor("east", "/lib/tutorial/eledhel/southern-city/20x8.c");
}
