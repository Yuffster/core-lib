//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/guilds/scion/common/electricity/tempest.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    WeaponType = "mace";
    WeaponSkill = "mace";

    addSpecification("limited by", (["equipment":({ "mace", "flail" })]));
}
