/********************************************************************
	Rhapsody	: 9.0.1 
	Login		: Y9DSYU706
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: Command
//!	Generated Date	: Thu, 4, Nov 2021  
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\Command.cpp
*********************************************************************/

#include "Command.h"
#include "TargetInformation.h"
//## package LogicLevel::Logging::DataContainer::ReceivedCommands

//## class Command
Command::Command(TargetInformation* target) : ticks(-1)
{
    itsTargetInformation = NULL;
    //#[ operation Command(TargetInformation)
    itsTargetInformation = target;
    //#]
}

Command::~Command()
{
    cleanUpRelations();
}

void Command::cleanUpRelations()
{
    if(itsTargetInformation != NULL)
        {
            itsTargetInformation = NULL;
        }
}

/*********************************************************************
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\Command.cpp
*********************************************************************/
