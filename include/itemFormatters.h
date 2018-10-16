//*****************************************************************************
// Copyright (c) 2018 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
#ifndef itemFormatters_h
#define itemFormatters_h

private nosave string Unidentified = "\x1b[0;36m%s\x1b[0m";
private nosave string UseIsPenalized = "\x1b[0;30;1m%s\x1b[0m";
private nosave string NormalEquipment = "\x1b[0;37;1m%s\x1b[0m";
private nosave string StrongEnchantment = "\x1b[0;35;1m%s\x1b[0m";
private nosave string SpecialAttack = "\x1b[0;31m%s\x1b[0m";
private nosave string WellCrafted = "\x1b[0;32m%s\x1b[0m";
private nosave string Value = "\x1b[0;33m%s\x1b[0m";
private nosave string Masterwork = "\x1b[0;32;1m%s\x1b[0m";
private nosave string Enchanted = "\x1b[0;35m%s\x1b[0m";

private nosave string Cyan = "\x1b[0;36m%s\x1b[0m";
private nosave string BoldBlack = "\x1b[0;30;1m%s\x1b[0m";
private nosave string Red = "\x1b[0;31m%s\x1b[0m";
private nosave string Green = "\x1b[0;32m%s\x1b[0m";
private nosave string Yellow = "\x1b[0;33m%s\x1b[0m";
private nosave string Blue = "\x1b[0;34m%s\x1b[0m";
private nosave string Magenta = "\x1b[0;35m%s\x1b[0m";

private nosave mapping decorators = ([
    "dividers":([
        "3-bit": "\x1b[0;31m",
        "8-bit": "\x1b[0;38;5;124m",
        "24-bit": "\x1b[0;38;2;100;10;0m"
    ]),
    "player guilds":([
        "any":([
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;12m",
            "24-bit": "\x1b[0;38;2;150;230;190m"
        ]),
    ]),
    "wizard levels":([
        "apprentice":([
            "3-bit": "\x1b[0;32m",
            "8-bit": "\x1b[0;38;5;133m",
            "24-bit": "\x1b[0;38;2;100;200;100m"
        ]),
        "wizard":([
            "3-bit": "\x1b[0;32m",
            "8-bit": "\x1b[0;38;5;144m",
            "24-bit": "\x1b[0;38;2;200;200;200m"
        ]),
        "creator":([
            "3-bit": "\x1b[0;32;1m",
            "8-bit": "\x1b[0;38;5;212m",
            "24-bit": "\x1b[0;38;2;100;200;10m"
        ]),
        "highwizard":([
            "3-bit": "\x1b[0;33m",
            "8-bit": "\x1b[0;38;5;202m",
            "24-bit": "\x1b[0;38;2;10;200;100m"
        ]),
        "senior":([
            "3-bit": "\x1b[0;33;1m",
            "8-bit": "\x1b[0;38;5;199m",
            "24-bit": "\x1b[0;38;2;100;20;100m"
        ]),
        "admin":([
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;178m",
            "24-bit": "\x1b[0;38;2;200;20;100m"
        ]),
        "elder":([
            "3-bit": "\x1b[0;36;1m",
            "8-bit": "\x1b[0;38;5;220m",
            "24-bit": "\x1b[0;38;2;100;20;200m"
        ]),
        "sage":([
            "3-bit": "\x1b[0;35;1m",
            "8-bit": "\x1b[0;38;5;140m",
            "24-bit": "\x1b[0;38;2;100;20;10m"
        ]),
        "archwizard":([
            "3-bit": "\x1b[0;34m",
            "8-bit": "\x1b[0;38;5;240m",
            "24-bit": "\x1b[0;38;2;10;20;100m"
        ]),
        "demigod":([
            "3-bit": "\x1b[0;34;1m",
            "8-bit": "\x1b[0;38;5;90m",
            "24-bit": "\x1b[0;38;2;80;80;80m"
        ]),
        "god":([
            "3-bit": "\x1b[0;31m",
            "8-bit": "\x1b[0;38;5;111m",
            "24-bit": "\x1b[0;38;2;130;130;130m"
        ]),
        "owner":([
            "3-bit": "\x1b[0;31;1m",
            "8-bit": "\x1b[0;38;5;20m",
            "24-bit": "\x1b[0;38;2;50;50;150m"
        ]),
    ]),
    "show":([
        "environment":([
            "3-bit": "\x1b[0;32m",
            "8-bit": "\x1b[0;38;5;2m",
            "24-bit": "\x1b[0;38;2;150;230;190m"
        ]),
        "text":([
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;92m",
            "24-bit": "\x1b[0;38;2;180;180;190m"
        ]),
        "own objects":([
            "3-bit": "\x1b[0;32;1m",
            "8-bit": "\x1b[0;38;5;12m",
            "24-bit": "\x1b[0;38;2;150;230;190m"
        ]),
        "guild objects":([
            "3-bit": "\x1b[0;35;1m",
            "8-bit": "\x1b[0;38;5;12m",
            "24-bit": "\x1b[0;38;2;150;230;190m"
        ]),
        "other objects":([
            "3-bit": "\x1b[0;35m",
            "8-bit": "\x1b[0;38;5;12m",
            "24-bit": "\x1b[0;38;2;150;230;190m"
        ]),
    ]),
    "people":([
        "ip address":([
            "3-bit": "\x1b[0;30;1m",
            "8-bit": "\x1b[0;38;5;12m",
            "24-bit": "\x1b[0;38;2;150;230;190m"
        ]),
        "name":([
            "3-bit": "\x1b[0;32m",
            "8-bit": "\x1b[0;38;5;2m",
            "24-bit": "\x1b[0;38;2;150;230;190m"
        ]),
        "level":([
            "3-bit": "\x1b[0;32;1m",
            "8-bit": "\x1b[0;38;5;12m",
            "24-bit": "\x1b[0;38;2;150;230;190m"
        ]),
        "status":([
            "3-bit": "\x1b[0;31;1m",
            "8-bit": "\x1b[0;38;5;12m",
            "24-bit": "\x1b[0;38;2;150;230;190m"
        ]),
        "location":([
            "3-bit": "\x1b[0;35m",
            "8-bit": "\x1b[0;38;5;12m",
            "24-bit": "\x1b[0;38;2;150;230;190m"
        ]),
    ]),
    "channel":([
        "header":([
            "3-bit": "\x1b[0;35m",
            "8-bit": "\x1b[0;38;5;112m",
            "24-bit": "\x1b[0;38;2;190;90;190m"
        ]),
        "body":([
            "3-bit": "\x1b[0;32m",
            "8-bit": "\x1b[0;38;5;12m",
            "24-bit": "\x1b[0;38;2;200;230;10m"
        ]),
    ]),
    "tell":([
        "message":([
            "3-bit": "\x1b[0;35m",
            "8-bit": "\x1b[0;38;5;112m",
            "24-bit": "\x1b[0;38;2;190;90;190m"
        ]),
        "block":([
            "3-bit": "\x1b[0;31;1m",
            "8-bit": "\x1b[0;38;5;20m",
            "24-bit": "\x1b[0;38;2;50;50;150m"
        ]),
        "busy":([
            "3-bit": "\x1b[0;31;1m",
            "8-bit": "\x1b[0;38;5;20m",
            "24-bit": "\x1b[0;38;2;50;50;150m"
        ]),
    ]),
    "soul":([
        "message":([
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;92m",
            "24-bit": "\x1b[0;38;2;180;180;190m"
        ]),
        "block":([
            "3-bit": "\x1b[0;31;1m",
            "8-bit": "\x1b[0;38;5;20m",
            "24-bit": "\x1b[0;38;2;50;50;150m"
        ]),
    ]),
    "shout":([
        "message":([
            "3-bit": "\x1b[0;35m",
            "8-bit": "\x1b[0;38;5;112m",
            "24-bit": "\x1b[0;38;2;190;90;190m"
        ]),
    ]),
    "say":([
        "message":([
            "3-bit": "\x1b[0;37m",
            "8-bit": "\x1b[0;38;5;15m",
            "24-bit": "\x1b[0;38;2;255;255;255m"
        ]),
    ]),
    "tutorial": ([
        "rune wall":([
            "3-bit": "\x1b[0;35m",
            "8-bit": "\x1b[0;38;5;20m",
            "24-bit": "\x1b[0;38;2;0;5;170m"
        ]),
    ]),
    "selector":([
        "number":([
            "3-bit": "\x1b[0;31;1m",
            "8-bit": "\x1b[0;38;5;9;1m",
            "24-bit": "\x1b[0;38;2;220;40;0;1m"
        ]),
        "title":([
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;80m",
            "24-bit": "\x1b[0;38;2;180;180;190m"
        ]),
        "menu name":([
            "3-bit": "\x1b[0;37;1m",
            "8-bit": "\x1b[0;38;5;15;1m",
            "24-bit": "\x1b[0;38;2;255;255;255;1m"
        ]),
        "choice enabled":([
            "3-bit": "\x1b[0;32m",
            "8-bit": "\x1b[0;38;5;2m",
            "24-bit": "\x1b[0;38;2;170;180;110m"
        ]),
        "choice disabled":([
            "3-bit": "\x1b[0;31m",
            "8-bit": "\x1b[0;38;5;9m",
            "24-bit": "\x1b[0;38;2;200;0;0m"
        ]),
        "prerequisites":([
            "3-bit": "\x1b[0;35m",
            "8-bit": "\x1b[0;38;5;20m",
            "24-bit": "\x1b[0;38;2;0;5;170m"
        ]),
        "instructions":([
            "3-bit": "\x1b[0;32;1m",
            "8-bit": "\x1b[0;38;5;2;1m",
            "24-bit": "\x1b[0;38;2;160;220;60;1m"
        ]),
        "details":([
            "3-bit": "\x1b[0;32m",
            "8-bit": "\x1b[0;38;5;144m",
            "24-bit": "\x1b[0;38;2;100;180;150m"  
        ]),
        "data" : ([
            "3-bit":"\x1b[0;33m",
            "8-bit": "\x1b[0;38;5;144m",
            "24-bit": "\x1b[0;38;2;180;180;100m"
        ]),
        "description":([
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;117m",
            "24-bit": "\x1b[0;38;2;140;180;190m"
        ]),
        "action":([
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;117m",
            "24-bit": "\x1b[0;38;2;140;180;190m"
        ]),
        "selected":([
            "3-bit": "\x1b[0;34;1m",
            "8-bit": "\x1b[0;38;5;20;1m",
            "24-bit": "\x1b[0;38;2;0;0;220;1m"
        ]),
        "information":([
            "3-bit": "\x1b[0;35;1m",
            "8-bit": "\x1b[0;38;5;20;1m",
            "24-bit": "\x1b[0;38;2;0;5;170;1m"
        ]),
        "failure":([
            "3-bit": "\x1b[0;31m",
            "8-bit": "\x1b[0;38;5;124m",
            "24-bit": "\x1b[0;38;2;140;0;0m"
        ]),
        "note":([
            "3-bit": "\x1b[0;35m",
            "8-bit": "\x1b[0;38;5;31m",
            "24-bit": "\x1b[0;38;2;80;155;175m"
        ]),
        "warning":([
            "3-bit": "\x1b[0;30;1m",
            "8-bit": "\x1b[0;38;5;238;1m",
            "24-bit": "\x1b[0;38;2;70;60;60;1m"
        ]),
        "decorator":([
            "3-bit": "\x1b[0;31m",
            "8-bit": "\x1b[0;38;5;9m",
            "24-bit": "\x1b[0;38;2;200;0;0m"
        ]),
    ]),
    "equipment":([
        "normal quality":([
            "3-bit": "\x1b[0;37;1m",
            "8-bit": "\x1b[0;38;5;231;1m",
            "24-bit": "\x1b[0;38;2;255;255;255;1m"
        ]),
        "well-crafted":([
            "3-bit": "\x1b[0;32m",
            "8-bit": "\x1b[0;38;5;144m",
            "24-bit": "\x1b[0;38;2;100;180;150m"  
        ]),   
        "masterwork":([
            "3-bit": "\x1b[0;32;1m",
            "8-bit": "\x1b[0;38;5;149;1m",
            "24-bit": "\x1b[0;38;2;100;220;150;1m"  
        ]),   
        "enchanted":([
            "3-bit": "\x1b[0;35m",
            "8-bit": "\x1b[0;38;5;31m",
            "24-bit": "\x1b[0;38;2;80;155;175m"
        ]),   
        "powerful enchantment":([
            "3-bit": "\x1b[0;35;1m",
            "8-bit": "\x1b[0;38;5;32;1m",
            "24-bit": "\x1b[0;38;2;80;155;195;1m"
        ]), 
        "unidentified": ([
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;80m",
            "24-bit": "\x1b[0;38;2;180;180;190m"
        ]),
        "field": ([
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;80m",
            "24-bit": "\x1b[0;38;2;180;180;190m"
        ]),
        "value": ([
            "3-bit": "\x1b[0;33m",
            "8-bit": "\x1b[0;38;5;190m",
            "24-bit": "\x1b[0;38;2;200;200;0m"
        ]),
        "cursed":([
            "3-bit": "\x1b[0;30;1m",
            "8-bit": "\x1b[0;38;5;238;1m",
            "24-bit": "\x1b[0;38;2;70;60;60;1m"
        ]),
        "bonus":([
            "3-bit": "\x1b[0;31m",
            "8-bit": "\x1b[0;38;5;9m",
            "24-bit": "\x1b[0;38;2;200;0;0m"
        ]),
    ]),
    "shop":([
        "unidentified":([
            "3-bit": "\x1b[0;30;1m",
            "8-bit": "\x1b[0;38;5;238;1m",
            "24-bit": "\x1b[0;38;2;70;60;60;1m"
        ]),
        "message":([
            "3-bit": "\x1b[0;32m",
            "8-bit": "\x1b[0;38;5;144m",
            "24-bit": "\x1b[0;38;2;100;180;150m"  
        ]),  
        "sell all":([
            "3-bit": "\x1b[0;30;1m",
            "8-bit": "\x1b[0;38;5;238;1m",
            "24-bit": "\x1b[0;38;2;70;60;60;1m"
        ]),
        "accounting":([
            "3-bit": "\x1b[0;37m",
            "8-bit": "\x1b[0;38;5;231m",
            "24-bit": "\x1b[0;38;2;255;255;255m"
        ]),
        "field": ([
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;80m",
            "24-bit": "\x1b[0;38;2;180;180;190m"
        ]),
        "value": ([
            "3-bit": "\x1b[0;33m",
            "8-bit": "\x1b[0;38;5;190m",
            "24-bit": "\x1b[0;38;2;200;200;0m"
        ]),
         "cost":([
            "3-bit": "\x1b[0;32m",
            "8-bit": "\x1b[0;38;5;2m",
            "24-bit": "\x1b[0;38;2;170;180;110m"
        ]),
    ]),
    "environment":([
        "description":([
            "3-bit": "\x1b[0;33m",
            "8-bit": "\x1b[0;38;5;190m",
            "24-bit": "\x1b[0;38;2;200;200;0m"
        ]),
        "exits":([
            "3-bit": "\x1b[0;35m",
            "8-bit": "\x1b[0;38;5;238;1m",
            "24-bit": "\x1b[0;38;2;60;60;70;1m"
        ]),
        "inventory": ([
            "3-bit": "\x1b[0;36m",
            "8-bit": "\x1b[0;38;5;80m",
            "24-bit": "\x1b[0;38;2;180;180;190m"
        ]),
    ]),
 ]);

#endif
