//*****************************************************************************
// Copyright (c) 2018 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";

#define Block 1
#define Describe 2
#define Success 3

object User;
object Selector;

/////////////////////////////////////////////////////////////////////////////
void Setup()
{
    Selector = clone_object("/lib/modules/creation/eyeSelector.c");
    Selector->init();

    User = clone_object("/lib/tests/support/services/mockPlayer.c");
    User->Name("Bob");
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    destruct(User);
    destruct(Selector);
}

/////////////////////////////////////////////////////////////////////////////
void InitialCreationDisplayIsCorrectForHuman()
{
    User->Race("maegenstryd");
    Selector->initiateSelector(User);
    ExpectEq("[0;36mCharacter creation - [0m[0;37;1mChoose your eye color[0m:\n"
        "\t[[0;31;1m1[0m]  - [0;32mAmber               [0m"
        "\t[[0;31;1m2[0m]  - [0;32mBlue                [0m\n"
        "\t[[0;31;1m3[0m]  - [0;32mBlue-green          [0m"
        "\t[[0;31;1m4[0m]  - [0;32mBrown               [0m\n"
        "\t[[0;31;1m5[0m]  - [0;32mCopper-blue         [0m"
        "\t[[0;31;1m6[0m]  - [0;32mGray                [0m\n"
        "\t[[0;31;1m7[0m]  - [0;32mGreen               [0m"
        "\t[[0;31;1m8[0m]  - [0;32mHazel               [0m\n"
        "\t[[0;31;1m9[0m]  - [0;32mLight blue          [0m"
        "\t[[0;31;1m10[0m] - [0;32mLight brown         [0m\n"
        "\t[[0;31;1m11[0m] - [0;32mLight gray          [0m"
        "\t[[0;31;1m12[0m] - [0;32mLight gray-blue     [0m\n"
        "\t[[0;31;1m13[0m] - [0;32mLight green         [0m"
        "\t[[0;31;1m14[0m] - [0;32mLight violet        [0m\n"
        "\t[[0;31;1m15[0m] - [0;32mRed                 [0m"
        "\t[[0;31;1m16[0m] - [0;32mSky blue            [0m\n"
        "\t[[0;31;1m17[0m] - [0;32mViolet              [0m"
        "\t[[0;31;1m18[0m] - [0;32mDo not add an eye color[0m\n"
        "[0;32;1mYou must select a number from 1 to 18.\n[0m"
        "[0;32mFor details on a given choice, type 'describe X' (or '? X') where\nX is the option about which you would like further details.\n[0m[0;32;1m[0m",
        User->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void AmberDescriptionIsCorrect()
{
    User->Race("human");
    Selector->initiateSelector(User);
    Selector->applySelection("describe 1");
    ExpectSubStringMatch("Your eyes are amber", User->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void BlueDescriptionIsCorrect()
{
    User->Race("human");
    Selector->initiateSelector(User);
    Selector->applySelection("describe 2");
    ExpectSubStringMatch("Your eyes are blue", User->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void BlueGreenDescriptionIsCorrect()
{
    User->Race("human");
    Selector->initiateSelector(User);
    Selector->applySelection("describe 3");
    ExpectSubStringMatch("Your eyes are blue-green", User->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void BrownDescriptionIsCorrect()
{
    User->Race("human");
    Selector->initiateSelector(User);
    Selector->applySelection("describe 4");
    ExpectSubStringMatch("Your eyes are brown", User->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void CopperBlueDescriptionIsCorrect()
{
    User->Race("human");
    Selector->initiateSelector(User);
    Selector->applySelection("describe 5");
    ExpectSubStringMatch("Your eyes are blue with a copper center", User->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void GrayDescriptionIsCorrect()
{
    User->Race("human");
    Selector->initiateSelector(User);
    Selector->applySelection("describe 6");
    ExpectSubStringMatch("Your eyes are gray", User->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void GreenDescriptionIsCorrect()
{
    User->Race("human");
    Selector->initiateSelector(User);
    Selector->applySelection("describe 7");
    ExpectSubStringMatch("Your eyes are green", User->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void HazelDescriptionIsCorrect()
{
    User->Race("human");
    Selector->initiateSelector(User);
    Selector->applySelection("describe 8");
    ExpectSubStringMatch("Your eyes are hazel", User->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void LightBlueDescriptionIsCorrect()
{
    User->Race("human");
    Selector->initiateSelector(User);
    Selector->applySelection("describe 9");
    ExpectSubStringMatch("Your eyes are pale, light blue", User->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void LightBrownDescriptionIsCorrect()
{
    User->Race("human");
    Selector->initiateSelector(User);
    Selector->applySelection("describe 10");
    ExpectSubStringMatch("Your eyes are light brown", User->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void LightGrayDescriptionIsCorrect()
{
    User->Race("human");
    Selector->initiateSelector(User);
    Selector->applySelection("describe 11");
    ExpectSubStringMatch("Your eyes are pale, light gray", User->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void LightGrayBlueDescriptionIsCorrect()
{
    User->Race("human");
    Selector->initiateSelector(User);
    Selector->applySelection("describe 12");
    ExpectSubStringMatch("Your eyes are pale, light grayish-blue", User->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void LightGreenDescriptionIsCorrect()
{
    User->Race("human");
    Selector->initiateSelector(User);
    Selector->applySelection("describe 13");
    ExpectSubStringMatch("Your eyes are light green", User->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void LightVioletDescriptionIsCorrect()
{
    User->Race("human");
    Selector->initiateSelector(User);
    Selector->applySelection("describe 14");
    ExpectSubStringMatch("Your eyes are light violet", User->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void RedDescriptionIsCorrect()
{
    User->Race("human");
    Selector->initiateSelector(User);
    Selector->applySelection("describe 15");
    ExpectSubStringMatch("Your eyes are red", User->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void SkyBluerDescriptionIsCorrect()
{
    User->Race("human");
    Selector->initiateSelector(User);
    Selector->applySelection("describe 16");
    ExpectSubStringMatch("Your eyes are sky blue", User->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void VioletDescriptionIsCorrect()
{
    User->Race("human");
    Selector->initiateSelector(User);
    Selector->applySelection("describe 17");
    ExpectSubStringMatch("Your eyes are violet", User->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void NoHairColorDescriptionIsCorrect()
{
    User->Race("human");
    Selector->initiateSelector(User);
    Selector->applySelection("describe 18");
    ExpectSubStringMatch("This option does not add an eye color to the player", User->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void SelectionOfAmberSetsTraitOnUser()
{
    User->Race("human");
    Selector->initiateSelector(User);
    Selector->applySelection("1");
    ExpectTrue(User->isTraitOf("/lib/modules/traits/eyes/amber.c"));
}

/////////////////////////////////////////////////////////////////////////////
void SelectionOfBlueSetsTraitOnUser()
{
    User->Race("human");
    Selector->initiateSelector(User);
    Selector->applySelection("2");
    ExpectTrue(User->isTraitOf("/lib/modules/traits/eyes/blue.c"));
}

/////////////////////////////////////////////////////////////////////////////
void SelectionOfBlueGreenSetsTraitOnUser()
{
    User->Race("human");
    Selector->initiateSelector(User);
    Selector->applySelection("3");
    ExpectTrue(User->isTraitOf("/lib/modules/traits/eyes/blue-green.c"));
}

/////////////////////////////////////////////////////////////////////////////
void SelectionOfBrownSetsTraitOnUser()
{
    User->Race("human");
    Selector->initiateSelector(User);
    Selector->applySelection("4");
    ExpectTrue(User->isTraitOf("/lib/modules/traits/eyes/brown.c"));
}

/////////////////////////////////////////////////////////////////////////////
void SelectionOfCopperBlueSetsTraitOnUser()
{
    User->Race("human");
    Selector->initiateSelector(User);
    Selector->applySelection("5");
    ExpectTrue(User->isTraitOf("/lib/modules/traits/eyes/copper-blue.c"));
}

/////////////////////////////////////////////////////////////////////////////
void SelectionOfGraySetsTraitOnUser()
{
    User->Race("human");
    Selector->initiateSelector(User);
    Selector->applySelection("6");
    ExpectTrue(User->isTraitOf("/lib/modules/traits/eyes/gray.c"));
}

/////////////////////////////////////////////////////////////////////////////
void SelectionOfGreenSetsTraitOnUser()
{
    User->Race("human");
    Selector->initiateSelector(User);
    Selector->applySelection("7");
    ExpectTrue(User->isTraitOf("/lib/modules/traits/eyes/green.c"));
}

/////////////////////////////////////////////////////////////////////////////
void SelectionOfHazelSetsTraitOnUser()
{
    User->Race("human");
    Selector->initiateSelector(User);
    Selector->applySelection("8");
    ExpectTrue(User->isTraitOf("/lib/modules/traits/eyes/hazel.c"));
}

/////////////////////////////////////////////////////////////////////////////
void SelectionOfLightBlueSetsTraitOnUser()
{
    User->Race("human");
    Selector->initiateSelector(User);
    Selector->applySelection("9");
    ExpectTrue(User->isTraitOf("/lib/modules/traits/eyes/light-blue.c"));
}

/////////////////////////////////////////////////////////////////////////////
void SelectionOfLightBrownSetsTraitOnUser()
{
    User->Race("human");
    Selector->initiateSelector(User);
    Selector->applySelection("10");
    ExpectTrue(User->isTraitOf("/lib/modules/traits/eyes/light-brown.c"));
}

/////////////////////////////////////////////////////////////////////////////
void SelectionOfLightGraySetsTraitOnUser()
{
    User->Race("human");
    Selector->initiateSelector(User);
    Selector->applySelection("11");
    ExpectTrue(User->isTraitOf("/lib/modules/traits/eyes/light-gray.c"));
}

/////////////////////////////////////////////////////////////////////////////
void SelectionOfLightGrayBlueSetsTraitOnUser()
{
    User->Race("human");
    Selector->initiateSelector(User);
    Selector->applySelection("12");
    ExpectTrue(User->isTraitOf("/lib/modules/traits/eyes/light-gray-blue.c"));
}

/////////////////////////////////////////////////////////////////////////////
void SelectionOfLightGreenSetsTraitOnUser()
{
    User->Race("human");
    Selector->initiateSelector(User);
    Selector->applySelection("13");
    ExpectTrue(User->isTraitOf("/lib/modules/traits/eyes/light-green.c"));
}

/////////////////////////////////////////////////////////////////////////////
void SelectionOfLightVioletSetsTraitOnUser()
{
    User->Race("human");
    Selector->initiateSelector(User);
    Selector->applySelection("14");
    ExpectTrue(User->isTraitOf("/lib/modules/traits/eyes/light-violet.c"));
}

/////////////////////////////////////////////////////////////////////////////
void SelectionOfRedSetsTraitOnUser()
{
    User->Race("human");
    Selector->initiateSelector(User);
    Selector->applySelection("15");
    ExpectTrue(User->isTraitOf("/lib/modules/traits/eyes/red.c"));
}

/////////////////////////////////////////////////////////////////////////////
void SelectionOfSkyBlueSetsTraitOnUser()
{
    User->Race("human");
    Selector->initiateSelector(User);
    Selector->applySelection("16");
    ExpectTrue(User->isTraitOf("/lib/modules/traits/eyes/sky-blue.c"));
}

/////////////////////////////////////////////////////////////////////////////
void SelectionOfVioletSetsTraitOnUser()
{
    User->Race("human");
    Selector->initiateSelector(User);
    Selector->applySelection("17");
    ExpectTrue(User->isTraitOf("/lib/modules/traits/eyes/violet.c"));
}

/////////////////////////////////////////////////////////////////////////////
void SelectionOfNoEyeColorSetsTraitOnUser()
{
    User->Race("human");
    Selector->initiateSelector(User);
    Selector->applySelection("18");
    ExpectEq(sizeof(User->Traits()));
}

/////////////////////////////////////////////////////////////////////////////
void HillgarathiHighElfShowsCorrectHairList()
{
    User->Race("high elf");
    User->addTrait("/lib/modules/traits/racial/hillgarathElf.c");

    Selector->initiateSelector(User);
    ExpectSubStringMatch("You must select a number from 1 to 15",
        User->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void MoonHighElfShowsCorrectHairList()
{
    User->Race("high elf");
    User->addTrait("/lib/modules/traits/racial/echorluinElf.c");

    Selector->initiateSelector(User);
    ExpectSubStringMatch("You must select a number from 1 to 16",
        User->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void HighElfShowsCorrectHairList()
{
    User->Race("high elf");

    Selector->initiateSelector(User);
    ExpectSubStringMatch("You must select a number from 1 to 16",
        User->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void DarkElfShowsCorrectHairList()
{
    User->Race("elf");
    User->addTrait("/lib/modules/traits/racial/darkElf.c");

    Selector->initiateSelector(User);
    ExpectSubStringMatch("You must select a number from 1 to 18",
        User->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void GreyElfShowsCorrectHairList()
{
    User->Race("elf");
    User->addTrait("/lib/modules/traits/racial/greyElf.c");

    Selector->initiateSelector(User);
    ExpectSubStringMatch("You must select a number from 1 to 18",
        User->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void SeaElfShowsCorrectHairList()
{
    User->Race("elf");
    User->addTrait("/lib/modules/traits/racial/seaElf.c");

    Selector->initiateSelector(User);
    ExpectSubStringMatch("You must select a number from 1 to 17",
        User->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void WoodElfShowsCorrectHairList()
{
    User->Race("elf");
    User->addTrait("/lib/modules/traits/racial/woodElf.c");

    Selector->initiateSelector(User);
    ExpectSubStringMatch("You must select a number from 1 to 18",
        User->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void ElfShowsCorrectHairList()
{
    User->Race("elf");

    Selector->initiateSelector(User);
    ExpectSubStringMatch("You must select a number from 1 to 18",
        User->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void KhazurathiDwarfShowsCorrectHairList()
{
    User->Race("dwarf");
    User->addTrait("/lib/modules/traits/racial/khazurathiDwarf.c");

    Selector->initiateSelector(User);
    ExpectSubStringMatch("You must select a number from 1 to 18",
        User->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void MirostiDwarfShowsCorrectHairList()
{
    User->Race("dwarf");
    User->addTrait("/lib/modules/traits/racial/mirostiDwarf.c");

    Selector->initiateSelector(User);
    ExpectSubStringMatch("You must select a number from 1 to 18",
        User->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void DwarfShowsCorrectHairList()
{
    User->Race("dwarf");
    Selector->initiateSelector(User);
    ExpectSubStringMatch("You must select a number from 1 to 18",
        User->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void DraconidShowsCorrectHairList()
{
    User->Race("draconid");

    Selector->initiateSelector(User);
    ExpectSubStringMatch("You must select a number from 1 to 18",
        User->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void HalfilngShowsCorrectHairList()
{
    User->Race("halfling");

    Selector->initiateSelector(User);
    ExpectSubStringMatch("You must select a number from 1 to 15",
        User->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void GnomeShowsCorrectHairList()
{
    User->Race("gnome");

    Selector->initiateSelector(User);
    ExpectSubStringMatch("You must select a number from 1 to 11",
        User->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void HalfElfShowsCorrectHairList()
{
    User->Race("half elf");

    Selector->initiateSelector(User);
    ExpectSubStringMatch("You must select a number from 1 to 18",
        User->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void HalfOrcShowsCorrectHairList()
{
    User->Race("half orc");

    Selector->initiateSelector(User);
    ExpectSubStringMatch("You must select a number from 1 to 10",
        User->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void HalfTrollShowsCorrectHairList()
{
    User->Race("half troll");

    Selector->initiateSelector(User);
    ExpectSubStringMatch("You must select a number from 1 to 10",
        User->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void FaerieShowsCorrectHairList()
{
    User->Race("faerie");

    Selector->initiateSelector(User);
    ExpectSubStringMatch("You must select a number from 1 to 18",
        User->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void AndurathiShowsCorrectHairList()
{
    User->Race("human");
    User->addTrait("/lib/modules/traits/racial/andurathHuman.c");

    Selector->initiateSelector(User);
    ExpectSubStringMatch("You must select a number from 1 to 12",
        User->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void CelebnostiShowsCorrectHairList()
{
    User->Race("human");
    User->addTrait("/lib/modules/traits/racial/celebnostHuman.c");

    Selector->initiateSelector(User);
    ExpectSubStringMatch("You must select a number from 1 to 15",
        User->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void EledheleanShowsCorrectHairList()
{
    User->Race("human");
    User->addTrait("/lib/modules/traits/racial/eledhelHuman.c");

    Selector->initiateSelector(User);
    ExpectSubStringMatch("You must select a number from 1 to 18",
        User->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void EndurgishShowsCorrectHairList()
{
    User->Race("human");
    User->addTrait("/lib/modules/traits/racial/endurghulHuman.c");

    Selector->initiateSelector(User);
    ExpectSubStringMatch("You must select a number from 1 to 12",
        User->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void HelcarishShowsCorrectHairList()
{
    User->Race("human");
    User->addTrait("/lib/modules/traits/racial/helcarionHuman.c");

    Selector->initiateSelector(User);
    ExpectSubStringMatch("You must select a number from 1 to 15",
        User->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void HillgarathiShowsCorrectHairList()
{
    User->Race("human");
    User->addTrait("/lib/modules/traits/racial/hillgarathHuman.c");

    Selector->initiateSelector(User);
    ExpectSubStringMatch("You must select a number from 1 to 18",
        User->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void IarwatheanShowsCorrectHairList()
{
    User->Race("human");
    User->addTrait("/lib/modules/traits/racial/iarwathHuman.c");

    Selector->initiateSelector(User);
    ExpectSubStringMatch("You must select a number from 1 to 18",
        User->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void LinmiriShowsCorrectHairList()
{
    User->Race("human");
    User->addTrait("/lib/modules/traits/racial/linmirHuman.c");

    Selector->initiateSelector(User);
    ExpectSubStringMatch("You must select a number from 1 to 15",
        User->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void MenadrostiShowsCorrectHairList()
{
    User->Race("human");
    User->addTrait("/lib/modules/traits/racial/menadrostHuman.c");

    Selector->initiateSelector(User);
    ExpectSubStringMatch("You must select a number from 1 to 18",
        User->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void TirnostiShowsCorrectHairList()
{
    User->Race("human");
    User->addTrait("/lib/modules/traits/racial/tirnostHuman.c");

    Selector->initiateSelector(User);
    ExpectSubStringMatch("You must select a number from 1 to 18",
        User->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void ZhenduliShowsCorrectHairList()
{
    User->Race("human");
    User->addTrait("/lib/modules/traits/racial/zhendulachHuman.c");

    Selector->initiateSelector(User);
    ExpectSubStringMatch("You must select a number from 1 to 11",
        User->caughtMessage());
}