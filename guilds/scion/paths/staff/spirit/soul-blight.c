//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/guilds/scion/common/spirit/soul-blight.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    WeaponType = "staff";
    WeaponSkill = "staff";

    addSpecification("limited by", (["equipment":({ "staff" })]));
}
