//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/trees/oak-stand.c", "southeast");
    addFeature("/lib/environment/features/water/pond.c", "southeast");
    addFeature("/lib/environment/features/landforms/glen.c", "southeast");

    addExit("east", "/areas/tol-dhurath/forest-2/14x0.c");
    addFeature("/lib/environment/features/paths/path.c", "east");
    addExit("west", "/areas/tol-dhurath/forest-2/12x0.c");
    addFeature("/lib/environment/features/paths/path.c", "west");
}
