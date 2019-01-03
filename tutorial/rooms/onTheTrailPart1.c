//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

object StateMachine;

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/cottonwoodStand.c", "west");
    addFeature("/lib/environment/features/cottonwoodStand.c", "south");

    // First test
    addExit("east", "/lib/tutorial/rooms/battleScene.c", "on the trail");
    addExit("north", "/lib/tutorial/rooms/onTheTrailPart2.c", "on the trail");
    addExit("south", "/lib/tutorial/rooms/onTheTrailPart1b.c", "on the trail");

    StateMachine = load_object("/lib/tutorial/stateMachines/introStateMachine.c");
    setStateMachine(StateMachine);
}

/////////////////////////////////////////////////////////////////////////////
public void continueOnTrailPart2()
{
    StateMachine->moveSquad("north",
        "/lib/tutorial/rooms/onTheTrailPart2.c");
}

/////////////////////////////////////////////////////////////////////////////
public void continueOnTrail()
{
    StateMachine->beginConversation("baddies went north");
    call_out("continueOnTrailPart2", 1);
}

/////////////////////////////////////////////////////////////////////////////
public void init()
{
    environment::init();

    if (this_player()->isRealizationOfPlayer() &&
        (StateMachine->getCurrentState() == "on the trail") &&
        present("alberich"))
    {
        call_out("continueOnTrail", 2);
    }
}
