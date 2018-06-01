//*****************************************************************************
// Copyright (c) 2018 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/core/baseSelector.c";

/////////////////////////////////////////////////////////////////////////////
public nomask void reset(int arg)
{
    if (!arg)
    {
        AllowUndo = 0;
        AllowAbort = 1;
        Description = "Main Menu";
        Type = "Task Management";
        Data = ([]);
    }
}

/////////////////////////////////////////////////////////////////////////////
protected nomask void setUpUserForSelection()
{
    object dictionary = load_object("/lib/dictionaries/domainDictionary.c");
    if (dictionary)
    {
        Data = dictionary->getTaskMenu(User);
    }
    Data[to_string(sizeof(Data) + 1)] = ([
        "name":"Exit Task Management Menu",
        "type" : "exit",
        "description" : "This option lets you exit the task management menu.\n",
        "canShow" : 1
    ]);
}

/////////////////////////////////////////////////////////////////////////////
public nomask void onSelectorCompleted(object caller)
{
    if (User)
    {
        tell_object(User, displayMessage());
    }
    caller->cleanUp();
}
