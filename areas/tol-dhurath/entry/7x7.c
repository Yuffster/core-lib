//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/water/ravine-waterfall.c", "east");
    addFeature("/lib/environment/features/trees/ash-stand.c", "south");
    addFeature("/lib/environment/features/water/brook.c", "west");

    addExit("north", "/areas/tol-dhurath/entry/7x8.c");
    addFeature("/lib/environment/features/paths/path.c", "north");
    addExit("east", "/areas/tol-dhurath/entry/8x7.c");
    addFeature("/lib/environment/features/paths/path.c", "east");
}
