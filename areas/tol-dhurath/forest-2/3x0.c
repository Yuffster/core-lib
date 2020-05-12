//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/trees/dogwood-stand.c", "northeast");
    addFeature("/lib/environment/features/water/ravine-creek.c", "northeast");

    addExit("north", "/areas/tol-dhurath/forest-2/3x1.c");
    addFeature("/lib/environment/features/paths/path.c", "north");
    addExit("east", "/areas/tol-dhurath/forest-2/4x0.c");
    addFeature("/lib/environment/features/paths/path.c", "east");
}
