//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/region.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setRegionName("Eledhel-southern-wainwright");
    setRegionType("wooden building");
    setDimensions(5, 5);

    setCoordinate(0, 0,
        "/lib/tutorial/eledhel/southern-city/inn/0x0.c", "room");
}
