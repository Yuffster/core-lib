//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/guilds/scion/common/blood/soulstrike.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    WeaponType = "mace";

    addSpecification("limited by", (["equipment":({ "mace", "flail" })]));
}
