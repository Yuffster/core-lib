//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/trees/basswood-stand.c", "northwest");
    addFeature("/lib/environment/features/water/brook.c", "south");

    addExit("north", "/areas/tol-dhurath/forest-2/22x4.c");
    addFeature("/lib/environment/features/paths/path.c", "north");
    addExit("south", "/areas/tol-dhurath/forest-2/22x2.c");
    addFeature("/lib/environment/features/paths/path.c", "south");
}
