/********************************************************************
	Rhapsody	: 9.0.1 
	Login		: Y9DSYU706
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: CommandOperationCall
//!	Generated Date	: Thu, 4, Nov 2021  
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\CommandOperationCall.cpp
*********************************************************************/

#include "CommandOperationCall.h"
#include "ModelEventType.h"
#include "ModelInstance.h"
#include "TargetInformation.h"
//## package LogicLevel::Logging::DataContainer::ReceivedCommands

//## class CommandOperationCall
CommandOperationCall::CommandOperationCall(unsigned int ticks, ModelInstance* p_sourceInstance, ModelEventType* eventType, ModelInstance* p_destinationInstance, TargetInformation* target) : Command( target )
{
    sourceInstance = p_sourceInstance;
    itsModelEventType = eventType;
    destinationInstance = p_destinationInstance;
    //#[ operation CommandOperationCall(unsigned int,ModelInstance,ModelEventType,ModelInstance,TargetInformation)
    this->ticks = ticks;
    commandIdentifier = operationCalled;
    //#]
}

CommandOperationCall::~CommandOperationCall()
{
    cleanUpRelations();
}

void CommandOperationCall::cleanUpRelations()
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
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\CommandOperationCall.cpp
*********************************************************************/
