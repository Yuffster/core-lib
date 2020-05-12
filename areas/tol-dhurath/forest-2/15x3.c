//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/water/canyon-dry-bed.c", "east");
    addFeature("/lib/environment/features/landforms/ridge.c", "east");

    addExit("east", "/areas/tol-dhurath/forest-2/16x3.c");
    addFeature("/lib/environment/features/paths/path.c", "east");
    addExit("north", "/areas/tol-dhurath/forest-2/15x4.c");
    addFeature("/lib/environment/features/paths/path.c", "north");
}
