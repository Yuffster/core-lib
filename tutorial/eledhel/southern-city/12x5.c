//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/city.c");

    addExit("north", "/lib/tutorial/eledhel/southern-city/12x6.c");
    addExit("south", "/lib/tutorial/eledhel/southern-city/12x4.c");
    addExit("west", "/lib/tutorial/eledhel/southern-city/11x5.c");
}