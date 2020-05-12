//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/trees/cottonwood-stand.c", "southeast");
    addFeature("/lib/environment/features/landforms/hill.c", "southeast");

    addExit("south", "/areas/tol-dhurath/forest-2/5x7.c");
    addFeature("/lib/environment/features/paths/path.c", "south");
    addExit("north", "/areas/tol-dhurath/forest-2/5x9.c");
    addFeature("/lib/environment/features/paths/path.c", "north");
    addExit("west", "/areas/tol-dhurath/forest-2/4x8.c");
    addFeature("/lib/environment/features/paths/path.c", "west");

    addRandomCreature(({"zombie","ruffian","coyote"}));
}
