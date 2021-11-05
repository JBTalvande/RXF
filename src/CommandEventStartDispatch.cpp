/********************************************************************
	Rhapsody	: 9.0.1 
	Login		: Y9DSYU706
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: CommandEventStartDispatch
//!	Generated Date	: Thu, 4, Nov 2021  
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\CommandEventStartDispatch.cpp
*********************************************************************/

#include "CommandEventStartDispatch.h"
#include "CommandEventCreated.h"
#include "CommandEventEndDispatch.h"
#include "TargetInformation.h"
//## package LogicLevel::Logging::DataContainer::ReceivedCommands

//## class CommandEventStartDispatch
CommandEventStartDispatch::CommandEventStartDispatch(unsigned int eventID, unsigned int ticks, CommandEventCreated* prevCreateEvent, TargetInformation* target) : CommandEventTripletData( target )
{
    itsCommandEventEndDispatch = NULL;
    itsCommandEventCreated = prevCreateEvent;
    //#[ operation CommandEventStartDispatch(unsigned int,unsigned int,CommandEventCreated,TargetInformation)
    this->eventID = eventID;
    this->ticks = ticks;
    commandIdentifier = eventStartDispatchCommand;   
    
    //#]
}

CommandEventStartDispatch::~CommandEventStartDispatch()
{
    cleanUpRelations();
}

void CommandEventStartDispatch::cleanUpRelations()
{
    if(itsCommandEventCreated != NULL)
        {
            itsCommandEventCreated = NULL;
        }
    if(itsCommandEventEndDispatch != NULL)
        {
            itsCommandEventEndDispatch = NULL;
        }
}

/*********************************************************************
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\CommandEventStartDispatch.cpp
*********************************************************************/
