//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/farmland.c");

    addExit("north", "/areas/eledhel/southwest-rural-two/12x1.c");
    addFeature("/lib/environment/features/paths/road.c", "north");
    addExit("west", "/areas/eledhel/southwest-rural-two/11x0.c");
    addFeature("/lib/environment/features/paths/road.c", "west");
}

