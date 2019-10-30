//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/lib/environment/interiors/wood-interior-shop.c");
    addItem("/lib/environment/items/lighting/window.c", "west");
    addItem("/lib/environment/items/shops/grocer.c");

    addDecorator("2x1 building 0x0 door");
    addExit("west", "/lib/tutorial/eledhel/southern-city/20x9.c");
    addExitWithDoor("east", "/lib/tutorial/eledhel/southern-city/22x9.c");
}