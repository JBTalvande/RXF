/********************************************************************
	Rhapsody	: 9.0.1 
	Login		: Y9DSYU706
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: CommandEventEndDispatch
//!	Generated Date	: Thu, 4, Nov 2021  
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\CommandEventEndDispatch.cpp
*********************************************************************/

#include "CommandEventEndDispatch.h"
#include "CommandEventStartDispatch.h"
#include "TargetInformation.h"
//## package LogicLevel::Logging::DataContainer::ReceivedCommands

//## class CommandEventEndDispatch
CommandEventEndDispatch::CommandEventEndDispatch(unsigned int eventID, CommandEventStartDispatch* startEvent, const QString& currentStatesString, TargetInformation* target) : CommandEventTripletData( target )
{
    itsCommandEventStartDispatch = startEvent;
    //#[ operation CommandEventEndDispatch(unsigned int,CommandEventStartDispatch,QString,TargetInformation)
    this->eventID = eventID;
    this->stateAfterEventConsumption = currentStatesString;
    commandIdentifier = eventEndDispatchCommand;   
    //#]
}

CommandEventEndDispatch::~CommandEventEndDispatch()
{
    cleanUpRelations();
}

void CommandEventEndDispatch::cleanUpRelations()
{
    if(itsCommandEventStartDispatch != NULL)
        {
            itsCommandEventStartDispatch = NULL;
        }
}

/*********************************************************************
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\CommandEventEndDispatch.cpp
*********************************************************************/
