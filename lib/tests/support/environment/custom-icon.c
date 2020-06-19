//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/lib/environment/interiors/ruin.c");
    addDecorator("ruined interior west wall");
}

/////////////////////////////////////////////////////////////////////////////
public string **customIcon(string **baseIcon, string color, string charset)
{
    mapping colors = ([
        "dais":([
            "none": "",
            "3-bit": "\x1b[0;35m",
            "8-bit": "\x1b[0;48;5;17;38;5;75m",
            "24-bit": "\x1b[0;48;2;0;0;60;38;2;90;175;255m",
        ]),
        "arms":([
            "none": "",
            "3-bit": "\x1b[0;34;1m",
            "8-bit": "\x1b[0;48;5;88;38;5;80;1m",
            "24-bit": "\x1b[0;48;2;60;0;0;38;2;160;200;255;1m",
        ])
    ]);

    baseIcon[0][1] = sprintf("%s%s%s", colors["arms"][color],
        (charset == "unicode") ? "\xe2\x95\xb2" : "\\",
        (colors["arms"][color] != "") ? "\x1b[0m" : "");
    baseIcon[1][1] = sprintf("%s%s%s", colors["dais"][color],
        (charset == "unicode") ? "\xf0\x9f\x94\xae" : "*",
        (colors["arms"][color] != "") ? "\x1b[0m" : "");
    baseIcon[2][1] = sprintf("%s%s%s", colors["arms"][color],
        (charset == "unicode") ? "\xe2\x95\xb1" : "/",
        (colors["arms"][color] != "") ? "\x1b[0m" : "");

    return baseIcon;
}
