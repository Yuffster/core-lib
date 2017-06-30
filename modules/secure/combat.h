//*****************************************************************************
// Copyright (c) 2017 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************

private int hitPoints;
private int maxHitPoints;
private int spellPoints;
private int maxSpellPoints;
private int staminaPoints;
private int maxStaminaPoints;
private int wimpy;
private int timeToHealHP;
private int timeToHealSP;
private int timeToHealST;
private int onKillList;

private nosave int IntervalBetweenHealing = 10;
private nosave int WasSlowedLastRound = 0;

private mapping combatStatistics = ([]);

private nosave int combatDelay;
private nosave int spellAction;
private nosave mapping hostileList = ([]);
private nosave mapping *attacks = ({});

/////////////////////////////////////////////////////////////////////////////
static nomask void loadCombat(mapping data, object persistence)
{
    if (isValidPersistenceObject(persistence))
    {
        hitPoints = persistence->extractSaveData("hitPoints", data);
        maxHitPoints = persistence->extractSaveData("maxHitPoints", data);
        spellPoints = persistence->extractSaveData("spellPoints", data);
        maxSpellPoints = persistence->extractSaveData("maxSpellPoints", data);
        staminaPoints = persistence->extractSaveData("staminaPoints", data);
        maxStaminaPoints = persistence->extractSaveData("maxStaminaPoints", data);
        wimpy = persistence->extractSaveData("wimpy", data);
        timeToHealHP = persistence->extractSaveData("timeToHealHP", data);
        timeToHealSP = persistence->extractSaveData("timeToHealSP", data);
        timeToHealST = persistence->extractSaveData("timeToHealST", data);
        onKillList = persistence->extractSaveData("onKillList", data);
    }
}

/////////////////////////////////////////////////////////////////////////////
static nomask mapping sendCombat()
{
    return ([
        "hitPoints": hitPoints,
        "maxHitPoints": maxHitPoints,
        "spellPoints": spellPoints,
        "maxSpellPoints": maxSpellPoints,
        "staminaPoints": staminaPoints,
        "maxStaminaPoints": maxStaminaPoints,
        "wimpy": wimpy,
        "timeToHealHP": timeToHealHP,
        "timeToHealSP": timeToHealSP,
        "timeToHealST": timeToHealST,
        "onKillList": onKillList
    ]);
}