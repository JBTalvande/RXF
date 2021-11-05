/********************************************************************
	Rhapsody	: 9.0.1 
	Login		: Y9DSYU706
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: CommandEventCreated
//!	Generated Date	: Thu, 4, Nov 2021  
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\CommandEventCreated.cpp
*********************************************************************/

#include "CommandEventCreated.h"
#include "CommandEventStartDispatch.h"
#include "ModelEventType.h"
#include "ModelInstance.h"
#include "TargetInformation.h"
//## package LogicLevel::Logging::DataContainer::ReceivedCommands

//## class CommandEventCreated
CommandEventCreated::CommandEventCreated(unsigned int eventID, unsigned int ticks, ModelInstance* p_sourceInstance, ModelEventType* eventType, ModelInstance* p_destinationInstance, TargetInformation* target) : CommandEventTripletData( target )
{
    sourceInstance = p_sourceInstance;
    itsModelEventType = eventType;
    itsCommandEventStartDispatch = NULL;
    destinationInstance = p_destinationInstance;
    //#[ operation CommandEventCreated(unsigned int,unsigned int,ModelInstance,ModelEventType,ModelInstance,TargetInformation)
    this->eventID = eventID;
    this->ticks = ticks;
    commandIdentifier = eventPutToMessageQueueCommand;
    //#]
}

CommandEventCreated::~CommandEventCreated()
{
    cleanUpRelations();
}

void CommandEventCreated::cleanUpRelations()
{
    if(destinationInstance != NULL)
        {
            destinationInstance = NULL;
        }
    if(itsCommandEventStartDispatch != NULL)
        {
            itsCommandEventStartDispatch = NULL;
        }
    if(itsModelEventType != NULL)
        {
            itsModelEventType = NULL;
        }
    {
        itsReceivedEventParameter.clear();
    }
    if(sourceInstance != NULL)
        {
            sourceInstance = NULL;
        }
}

/*********************************************************************
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\CommandEventCreated.cpp
*********************************************************************/
