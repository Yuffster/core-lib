//*****************************************************************************
// Copyright (c) 2017 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
private string PlayerCommands = "/lib/commands/player/";
private string WizardCommands = "/lib/commands/wizard/";
private string CannedEmotes = "/lib/commands/soul.c";
private string BaseCommand = "lib/commands/baseCommand.c";

private mapping commands = ([]);
private int IsInitialized = 0;

/////////////////////////////////////////////////////////////////////////////
private nomask void registerPlayerCommands()
{
    string *commandFiles = get_dir(PlayerCommands);
    if(sizeof(commandFiles))
    {
        foreach(string command in commandFiles)
        {
            string fullyQualifiedFile = sprintf("%s/%s", PlayerCommands, command);

            if(file_size(fullyQualifiedFile))
            { 
                object commandObj = load_object(fullyQualifiedFile);
                
                if(commandObj && (member(inherit_list(commandObj), BaseCommand) > -1))
                {
                    commands[commandObj->commandRegExp()] = fullyQualifiedFile;
                }
            }
        }
    }
}

/////////////////////////////////////////////////////////////////////////////
public nomask int isInitialized()
{
    return IsInitialized;
}

/////////////////////////////////////////////////////////////////////////////
public nomask void reset(int arg)
{
    if (!arg)
    {
        commands = ([]);
        registerPlayerCommands();

        IsInitialized = 1;
    }
}

/////////////////////////////////////////////////////////////////////////////
public nomask int executeCommand(string passedCommand, object initiator)
{
    int ret = 0;
    string *commandList = m_indices(commands);

    if(sizeof(commandList))
    {
        if (sizeof(regexp(({ passedCommand }), "^('|:|=)[^ ]")))
        {
            passedCommand = passedCommand[0..0] + " " + passedCommand[1..];
        }
        foreach(string command in commandList)
        {
            if(sizeof(regexp(({ passedCommand }), command)))
            {
                object commandObj = load_object(commands[command]);
                if(commandObj)
                {
                    ret = commandObj->execute(passedCommand, initiator);
                }
                break;
            }
        }
    }
    return ret;
}
