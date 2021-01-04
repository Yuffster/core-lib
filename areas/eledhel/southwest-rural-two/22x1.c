//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/generatedEnvironment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/farmland.c");

    addExit("east", "/areas/eledhel/southwest-rural-two/23x1.c");
    addFeature("/lib/environment/features/paths/road.c", "east");
    addExit("north", "/areas/eledhel/southwest-rural-two/22x2.c");
    addFeature("/lib/environment/features/paths/road.c", "north");
}

