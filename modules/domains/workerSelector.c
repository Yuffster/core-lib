//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/core/baseSelector.c";

private string Location;
private string WorkerType;

private mapping WorkerData = 0;
private object dictionary = load_object("/lib/dictionaries/domainDictionary.c");
private object SubselectorObj;

/////////////////////////////////////////////////////////////////////////////
public nomask void setLocation(string location)
{
    mapping info = dictionary->getPlayerHolding(User, location);
    if (mappingp(info))
    {
        Location = location;
    }
}

/////////////////////////////////////////////////////////////////////////////
public nomask void setWorkerData(mapping data, string name)
{
    WorkerData = data;
}

/////////////////////////////////////////////////////////////////////////////
public nomask void setWorkerType(string type)
{
    WorkerType = type;
}

/////////////////////////////////////////////////////////////////////////////
public nomask void reset(int arg)
{
    if (!arg)
    {
        AllowUndo = 0;
        AllowAbort = 1;
        SuppressColon = 1;
        NumColumns = 2;
        Description = "Assign Workers";
        Type = "Building Projects";
        Data = ([]);
    }
}

/////////////////////////////////////////////////////////////////////////////
protected nomask void setUpUserForSelection()
{
    object dictionary = load_object("/lib/dictionaries/domainDictionary.c");

    if (dictionary && WorkerData)
    {
        Description = "Assign Workers:\n" +
            configuration->decorate(format(sprintf("From this menu, you can "
                "select the %s who will be executing your %s project "
                "in your holdings at %s.", 
                dictionary->pluralizeValue(WorkerType, 1),
                WorkerData["display name"],
                dictionary->getLocationDisplayName(Location)), 78),
                "description", "selector", colorConfiguration) +
            dictionary->getWorkersOfType(User, WorkerType, WorkerData);

        Data = dictionary->getWorkersByTypeMenu(User, Location, WorkerType,
            WorkerData);
    }
}

/////////////////////////////////////////////////////////////////////////////
public nomask void onSelectorCompleted(object caller)
{
    if (User)
    {
        setUpUserForSelection();
        tell_object(User, displayMessage());
    }
    caller->cleanUp();
}

/////////////////////////////////////////////////////////////////////////////
protected nomask string displayDetails(string choice)
{
    string ret = sprintf("%9s", "");
    if ((Data[choice]["type"] == "construct") &&
        (User->colorConfiguration() == "none"))
    {
        ret = sprintf("%-9s", "N/A");
    }
    else if (member(WorkerData, "workers") &&
        (member(m_indices(WorkerData["workers"]), Data[choice]["type"]) > -1))
    {
        ret = configuration->decorate(sprintf("%-9s",
            (User->charsetConfiguration() == "unicode") ? "   (\xe2\x80\xa0)" :
            "   (*)"),
            "selected", "selector", colorConfiguration);
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
protected string choiceFormatter(string choice)
{
    string choiceColor = member(Data[choice], "is disabled") &&
        Data[choice]["is disabled"] ? "choice disabled" : "choice enabled";

    return sprintf("[%s]%s - %s%s%s",
        configuration->decorate("%s", "number", "selector", colorConfiguration),
        padSelectionDisplay(choice),
        configuration->decorate("%-23s", choiceColor, "selector", colorConfiguration),
        displayDetails(choice),
        Data[choice]["layout panel"] || "");
}

/////////////////////////////////////////////////////////////////////////////
protected nomask int processSelection(string selection)
{
    int ret = -1;
    if (User)
    {
        ret = (Data[selection]["type"] == "exit") || (selection == "abort");

        if (!ret)
        {
            ret = 0;
            if (Data[selection]["type"] == "auto-select")
            {
                User->buildDomainUpgrade(Location,
                    WorkerData["type"],
                    WorkerData["value"]);
                ret = 0;
            }
            else if (Data[selection]["type"] == "workers")
            {
                SubselectorObj =
                    clone_object("/lib/modules/domains/workerSelector.c");
                SubselectorObj->setWorkerData(Data[selection]["data"]);
                SubselectorObj->setLocation(Location);

                move_object(SubselectorObj, User);
                SubselectorObj->registerEvent(this_object());
                SubselectorObj->initiateSelector(User);
            }
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
protected nomask int suppressMenuDisplay()
{
    return objectp(SubselectorObj);
}
