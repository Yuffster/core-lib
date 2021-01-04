//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/landforms/sinkhole.c", "east");
    addFeature("/lib/environment/features/water/brook.c", "north");
    addFeature("/lib/environment/features/landforms/hill.c", "northwest");

    addExit("south", "/areas/tol-dhurath/forest-3/0x0.c");
    addFeature("/lib/environment/features/paths/path.c", "south");
    addExit("east", "/areas/tol-dhurath/forest-3/1x1.c");
    addFeature("/lib/environment/features/paths/path.c", "east");
}
