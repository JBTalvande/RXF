/********************************************************************
	Rhapsody	: 9.0.1 
	Login		: Y9DSYU706
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: CommandTraceEvent
//!	Generated Date	: Thu, 4, Nov 2021  
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\CommandTraceEvent.cpp
*********************************************************************/

#include "CommandTraceEvent.h"
#include "ModelEventType.h"
#include "ModelInstance.h"
#include "TargetInformation.h"
//## package LogicLevel::Logging::DataContainer::ReceivedCommands

//## class CommandTraceEvent
CommandTraceEvent::CommandTraceEvent(int ticks, ModelInstance* sourceInstance, ModelInstance* destinationInstance, ModelEventType* modelEventType, const QString& currentStatesString, TargetInformation* targetInformation) : Command( targetInformation ), destinationInstance( destinationInstance ), itsModelEventType( modelEventType ), sourceInstance( sourceInstance )
{
    //#[ operation CommandTraceEvent(int,ModelInstance,ModelInstance,ModelEventType,QString,TargetInformation)
    this->ticks = ticks;
    this->stateAfterEventConsumption = currentStatesString;
    this->commandIdentifier = commandType::traceEventCommand;
    //#]
}

CommandTraceEvent::~CommandTraceEvent()
{
    cleanUpRelations();
}

void CommandTraceEvent::cleanUpRelations()
{
    if(destinationInstance != NULL)
        {
            destinationInstance = NULL;
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
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\CommandTraceEvent.cpp
*********************************************************************/
