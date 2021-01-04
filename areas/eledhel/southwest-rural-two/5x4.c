//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/farmland.c");

    addExit("west", "/areas/eledhel/southwest-rural-two/4x4.c");
    addFeature("/lib/environment/features/paths/road.c", "west");
    addExit("south", "/areas/eledhel/southwest-rural-two/5x3.c");
    addFeature("/lib/environment/features/paths/road.c", "south");
}

