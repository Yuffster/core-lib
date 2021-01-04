//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/guilds/scion/common/blood/nefarious-barrier.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    WeaponType = "hammer";

    addSpecification("limited by", (["equipment":({ "hammer" })]));
}
