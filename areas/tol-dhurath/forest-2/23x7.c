//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/trees/fir-stand.c", "southwest");
    addFeature("/lib/environment/features/water/brook.c", "southwest");

    addExit("south", "/areas/tol-dhurath/forest-2/23x6.c");
    addFeature("/lib/environment/features/paths/path.c", "south");

    addRandomCreature(({"zombie","ruffian","knight of the storm","white-tail deer","red wolf"}));
}
