//*****************************************************************************
// Copyright (c) 2018 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";

object Player;
object Selector;

/////////////////////////////////////////////////////////////////////////////
void Setup()
{
    Selector = clone_object("/lib/modules/domains/seneschalSelector.c");

    Player = clone_object("/lib/tests/support/services/mockPlayer.c");
    Player->Name("bob");
    Player->addCommands();

    move_object(Selector, Player);
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    destruct(Player);
    destruct(Selector);
}

/////////////////////////////////////////////////////////////////////////////
void TopLevelMenuWithoutAnyPrereqsMetDisplaysCorrectly()
{
    Selector->initiateSelector(Player);

    ExpectEq("[0;36mDomain Management - [0m[0;37;1mMain Menu[0m:\n"
        "[[0;31;1m1[0m] - [0;31mAdministration Projects                  [0;35m(Missing Prerequisites)[0m\n"
        "[[0;31;1m2[0m] - [0;31mBuilding Projects                        [0;35m(Missing Prerequisites)[0m\n"
        "[[0;31;1m3[0m] - [0;31mResources and Holdings                   [0;35m(Missing Prerequisites)[0m\n"
        "[[0;31;1m4[0m] - [0;31mHire New Henchmen                        [0;35m(Missing Prerequisites)[0m\n"
        "[[0;31;1m5[0m] - [0;31mManage Tasks                             [0;35m(Missing Prerequisites)[0m\n"
        "[[0;31;1m6[0m] - [0;32mExit Domain Management Menu[0m\n"
        "[0;32;1mYou must select a number from 1 to 6.\n[0m"
        "[0;32mType 'exit' if you do not wish to make a selection at this time.\n[0m"
        "[0;32mFor details on a given choice, type 'describe X' (or '? X') where\nX is the option about which you would like further details.\n[0m[0;32;1m[0m",
        Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void SelectUnavailableOptionReturnsToMainMenu()
{
    Selector->initiateSelector(Player);
    command("2", Player);

    ExpectEq("[0;36mDomain Management - [0m[0;37;1mMain Menu[0m:\n"
        "[[0;31;1m1[0m] - [0;31mAdministration Projects                  [0;35m(Missing Prerequisites)[0m\n"
        "[[0;31;1m2[0m] - [0;31mBuilding Projects                        [0;35m(Missing Prerequisites)[0m\n"
        "[[0;31;1m3[0m] - [0;31mResources and Holdings                   [0;35m(Missing Prerequisites)[0m\n"
        "[[0;31;1m4[0m] - [0;31mHire New Henchmen                        [0;35m(Missing Prerequisites)[0m\n"
        "[[0;31;1m5[0m] - [0;31mManage Tasks                             [0;35m(Missing Prerequisites)[0m\n"
        "[[0;31;1m6[0m] - [0;32mExit Domain Management Menu[0m\n"
        "[0;32;1mYou must select a number from 1 to 6.\n[0m"
        "[0;32mType 'exit' if you do not wish to make a selection at this time.\n[0m"
        "[0;32mFor details on a given choice, type 'describe X' (or '? X') where\nX is the option about which you would like further details.\n[0m[0;32;1m[0m",
        Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void TopLevelMenuWithAdministrationProjectPrereqMetDisplaysCorrectly()
{
    ExpectTrue(Player->initiateResearch("lib/instances/research/domains/administration/basicAdministration.c"), "added research");
    Selector->initiateSelector(Player);

    ExpectEq("[0;36mDomain Management - [0m[0;37;1mMain Menu[0m:\n"
        "[[0;31;1m1[0m] - [0;32mAdministration Projects[0m\n"
        "[[0;31;1m2[0m] - [0;31mBuilding Projects                        [0;35m(Missing Prerequisites)[0m\n"
        "[[0;31;1m3[0m] - [0;31mResources and Holdings                   [0;35m(Missing Prerequisites)[0m\n"
        "[[0;31;1m4[0m] - [0;31mHire New Henchmen                        [0;35m(Missing Prerequisites)[0m\n"
        "[[0;31;1m5[0m] - [0;31mManage Tasks                             [0;35m(Missing Prerequisites)[0m\n"
        "[[0;31;1m6[0m] - [0;32mExit Domain Management Menu[0m\n"
        "[0;32;1mYou must select a number from 1 to 6.\n[0m"
        "[0;32mType 'exit' if you do not wish to make a selection at this time.\n[0m"
        "[0;32mFor details on a given choice, type 'describe X' (or '? X') where\nX is the option about which you would like further details.\n[0m[0;32;1m[0m",
        Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void TopLevelMenuWithBuildingProjectPrereqMetDisplaysCorrectly()
{
    ExpectTrue(Player->initiateResearch("lib/instances/research/domains/construction/basicBuilding.c"), "added research");
    Selector->initiateSelector(Player);

    ExpectEq("[0;36mDomain Management - [0m[0;37;1mMain Menu[0m:\n"
        "[[0;31;1m1[0m] - [0;31mAdministration Projects                  [0;35m(Missing Prerequisites)[0m\n"
        "[[0;31;1m2[0m] - [0;32mBuilding Projects[0m\n"
        "[[0;31;1m3[0m] - [0;31mResources and Holdings                   [0;35m(Missing Prerequisites)[0m\n"
        "[[0;31;1m4[0m] - [0;31mHire New Henchmen                        [0;35m(Missing Prerequisites)[0m\n"
        "[[0;31;1m5[0m] - [0;31mManage Tasks                             [0;35m(Missing Prerequisites)[0m\n"
        "[[0;31;1m6[0m] - [0;32mExit Domain Management Menu[0m\n"
        "[0;32;1mYou must select a number from 1 to 6.\n[0m"
        "[0;32mType 'exit' if you do not wish to make a selection at this time.\n[0m"
        "[0;32mFor details on a given choice, type 'describe X' (or '? X') where\nX is the option about which you would like further details.\n[0m[0;32;1m[0m",
        Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void TopLevelMenuWithHiringPrereqMetDisplaysCorrectly()
{
    ExpectTrue(Player->initiateResearch("lib/instances/research/domains/hiring/basicHiring.c"), "added research");
    Selector->initiateSelector(Player);

    ExpectEq("[0;36mDomain Management - [0m[0;37;1mMain Menu[0m:\n"
        "[[0;31;1m1[0m] - [0;31mAdministration Projects                  [0;35m(Missing Prerequisites)[0m\n"
        "[[0;31;1m2[0m] - [0;31mBuilding Projects                        [0;35m(Missing Prerequisites)[0m\n"
        "[[0;31;1m3[0m] - [0;31mResources and Holdings                   [0;35m(Missing Prerequisites)[0m\n"
        "[[0;31;1m4[0m] - [0;32mHire New Henchmen[0m\n"
        "[[0;31;1m5[0m] - [0;31mManage Tasks                             [0;35m(Missing Prerequisites)[0m\n"
        "[[0;31;1m6[0m] - [0;32mExit Domain Management Menu[0m\n"
        "[0;32;1mYou must select a number from 1 to 6.\n[0m"
        "[0;32mType 'exit' if you do not wish to make a selection at this time.\n[0m"
        "[0;32mFor details on a given choice, type 'describe X' (or '? X') where\nX is the option about which you would like further details.\n[0m[0;32;1m[0m",
        Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void TopLevelMenuWithHoldingsPrereqMetDisplaysCorrectly()
{
    ExpectTrue(Player->initiateResearch("lib/instances/research/domains/holdings/basicHoldings.c"), "added research");
    Selector->initiateSelector(Player);

    ExpectEq("[0;36mDomain Management - [0m[0;37;1mMain Menu[0m:\n"
        "[[0;31;1m1[0m] - [0;31mAdministration Projects                  [0;35m(Missing Prerequisites)[0m\n"
        "[[0;31;1m2[0m] - [0;31mBuilding Projects                        [0;35m(Missing Prerequisites)[0m\n"
        "[[0;31;1m3[0m] - [0;32mResources and Holdings[0m\n"
        "[[0;31;1m4[0m] - [0;31mHire New Henchmen                        [0;35m(Missing Prerequisites)[0m\n"
        "[[0;31;1m5[0m] - [0;31mManage Tasks                             [0;35m(Missing Prerequisites)[0m\n"
        "[[0;31;1m6[0m] - [0;32mExit Domain Management Menu[0m\n"
        "[0;32;1mYou must select a number from 1 to 6.\n[0m"
        "[0;32mType 'exit' if you do not wish to make a selection at this time.\n[0m"
        "[0;32mFor details on a given choice, type 'describe X' (or '? X') where\nX is the option about which you would like further details.\n[0m[0;32;1m[0m",
        Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void TopLevelMenuWithTaskPrereqMetDisplaysCorrectly()
{
    ExpectTrue(Player->initiateResearch("lib/instances/research/domains/tasks/basicTasks.c"), "added research");
    Selector->initiateSelector(Player);

    ExpectEq("[0;36mDomain Management - [0m[0;37;1mMain Menu[0m:\n"
        "[[0;31;1m1[0m] - [0;31mAdministration Projects                  [0;35m(Missing Prerequisites)[0m\n"
        "[[0;31;1m2[0m] - [0;31mBuilding Projects                        [0;35m(Missing Prerequisites)[0m\n"
        "[[0;31;1m3[0m] - [0;31mResources and Holdings                   [0;35m(Missing Prerequisites)[0m\n"
        "[[0;31;1m4[0m] - [0;31mHire New Henchmen                        [0;35m(Missing Prerequisites)[0m\n"
        "[[0;31;1m5[0m] - [0;32mManage Tasks[0m\n"
        "[[0;31;1m6[0m] - [0;32mExit Domain Management Menu[0m\n"
        "[0;32;1mYou must select a number from 1 to 6.\n[0m"
        "[0;32mType 'exit' if you do not wish to make a selection at this time.\n[0m"
        "[0;32mFor details on a given choice, type 'describe X' (or '? X') where\nX is the option about which you would like further details.\n[0m[0;32;1m[0m",
        Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void SelectingTasksMovesToTaskMenu()
{
    ExpectTrue(Player->initiateResearch("lib/instances/research/domains/tasks/basicTasks.c"), "added research");
    Selector->initiateSelector(Player);
    command("5", Player);

    ExpectSubStringMatch("Exit Task Management Menu",
        Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void SelectingAdministrationsMovesToTaskMenu()
{
    ExpectTrue(Player->initiateResearch("lib/instances/research/domains/administration/basicAdministration.c"), "added research");
    Selector->initiateSelector(Player);
    command("1", Player);

    ExpectSubStringMatch("Exit Administration Projects Menu",
        Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void SelectingBuildingMovesToTaskMenu()
{
    ExpectTrue(Player->initiateResearch("lib/instances/research/domains/construction/basicBuilding.c"), "added research");
    Selector->initiateSelector(Player);
    command("2", Player);

    ExpectSubStringMatch("Exit Building Projects Menu",
        Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void SelectingHoldingsMovesToTaskMenu()
{
    ExpectTrue(Player->initiateResearch("lib/instances/research/domains/holdings/basicHoldings.c"), "added research");
    Selector->initiateSelector(Player);
    command("3", Player);

    ExpectSubStringMatch("Exit Resources and Holdings Menu",
        Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void SelectingHiringMovesToTaskMenu()
{
    ExpectTrue(Player->initiateResearch("lib/instances/research/domains/hiring/basicHiring.c"), "added research");
    Selector->initiateSelector(Player);
    command("4", Player);

    ExpectSubStringMatch("Exit Hiring Menu",
        Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void DescriptionsAreDisplayed()
{
    Selector->initiateSelector(Player);
    command("? 1", Player);
    ExpectSubStringMatch("This option lets you administer to your realm - "
        "be it the taxation of your subjects or the assigning of workers to "
        "the various projects in your domain.",
        Player->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void ExitCleansUpSelector()
{
    object subscriber = clone_object("/lib/tests/support/events/onSelectorCompletedEventSubscriber.c");
    Selector->registerEvent(subscriber);
    Selector->initiateSelector(Player);
    ExpectEq(0, subscriber->TimesEventReceived());

    ExpectTrue(present(Selector, Player));
    command("6", Player);
    ExpectSubStringMatch("You have selected 'Exit Domain Management Menu'",
        Player->caughtMessage());

    ExpectEq(1, subscriber->TimesEventReceived());
}
