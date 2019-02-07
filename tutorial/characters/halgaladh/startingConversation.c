//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addTopic("aye but how", "@S@`Aye, but how?' @D@asks "
        "Halgaladh as he steps up next to Galadhel.");
    addTopicInterjection("aye but how",
        "/lib/tutorial/characters/galadhel/galadhel.c",
        "I do not know", 1);

    addTopic("stinks too", "@S@`He's been dead quite "
        "some time by the smell of him.' @D@notes "
        "Halgaladh as he investigates the corpse.");

    addResponse("stinks too", "@I@Examine corpse@E@", "@D@@C@##InitiatorName## "
        "##ResponseInfinitive::examine## the corpse closely and "
        "##ResponseInfinitive::say##, @S@`Yet I would bet Halgaladh's meal "
        "tonight that this was the killer. All of the signs point to it - "
        "the bow and arrows, the trail we've followed...'");
    addResponseEffect("stinks too", "@I@Examine corpse@E@", 
        (["experience": ([ "guild": "background", "amount": 25 ])]));

    addResponse("stinks too", "It does stink...", "@D@@C@##InitiatorName## "
        "##ResponseInfinitive::wrinkle## ##InitiatorPossessive## nose and "
        "##ResponseInfinitive::say##, @S@`Yet I would bet Halgaladh's meal "
        "tonight that this was the killer. All of the signs point to it - "
        "the bow and arrows, the trail we've followed...");

    addTopic("stinks part two", "");
    addResponseTopic("stinks too", "@I@Examine corpse@E@", "stinks part two");
    addResponseTopic("stinks too", "It does stink...", "stinks part two");
    addTopicInterjection("stinks part two",
        "/lib/tutorial/characters/galadhel/galadhel.c",
        "What are we missing", 1);

    addTopic("no more mushroom farmers", "@D@As Halgaladh sees Galadhel train "
        "her bow on her target, he snickers and adds, @S@`Galadhel, what "
        "you're 'aiming' to do doesn't look like a bad plan of action. At "
        "least we won't have to worry about him siring more mushroom "
        "farmers.");

    addTopic("wake up sir", "@D@Halgaladh stares at Donald's inert form, torn "
        "between anger and the need to move on before the enemy renews their "
        "attack. He walks over to Donald and shakes him. @S@`Sir?'");
    addTopicInterjection("wake up sir",
        "/lib/tutorial/characters/donald/donald.c",
        "donald regains consciousness", 1);

    addTopic("think before you leap", "@D@Halgaladh grabs hold of Donald's "
        "shoulder, firmly restraining him from getting up. @S@`Sir! You're a "
        "bit muddled and not thinking straight. We need a plan first!' @D@He "
        "turns to Galadhel and states, @S@`Based on what I heard just now, "
        "you have every right to be angry, but keep your anger focused on "
        "our foes! You and Donald can discuss this later.'");
    addTopicInterjection("think before you leap",
        "/lib/tutorial/characters/alberich/alberich.c",
        "good. a blissful interlude", 1);
}
