//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/guilds/scion/common/ice/ice-javelin.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    WeaponType = "mace";
    WeaponSkill = "mace";
    ValidWeaponTypes = ({ "mace", "flail" });

    addSpecification("limited by", (["equipment": ValidWeaponTypes]));
}
