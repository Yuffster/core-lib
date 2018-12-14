//*****************************************************************************
// Copyright (c) 2018 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    Name("brendan");
    Gender(1);
    Race("maegenstryd");
    SetUpPersonaOfLevel("keeper of the night", 3);
    addTrait("lib/modules/traits/educational/educated.c");

    addConversation("/lib/tutorial/characters/brendan/startingConversation.c");
}
