//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/guilds/scion/common/evocation/energy-barrier.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    WeaponType = "axe";

    addSpecification("limited by", (["equipment":({ "axe" })]));
}
