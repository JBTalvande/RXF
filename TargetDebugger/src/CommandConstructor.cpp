/********************************************************************
	Rhapsody	: 9.0.1 
	Login		: Y9DSYU706
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: CommandConstructor
//!	Generated Date	: Thu, 4, Nov 2021  
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\CommandConstructor.cpp
*********************************************************************/

#include "CommandConstructor.h"
#include "ModelInstance.h"
#include "TargetInformation.h"
//## package LogicLevel::Logging::DataContainer::ReceivedCommands

//## class CommandConstructor
CommandConstructor::CommandConstructor(ModelInstance* instance, TargetInformation* target) : Command( target )
{
    itsModelInstance = instance;
    //#[ operation CommandConstructor(ModelInstance,TargetInformation)
    commandIdentifier = constructorCommand;
    //#]
}

CommandConstructor::~CommandConstructor()
{
    cleanUpRelations();
}

void CommandConstructor::cleanUpRelations()
{
    if(itsModelInstance != NULL)
        {
            itsModelInstance = NULL;
        }
}

/*********************************************************************
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\CommandConstructor.cpp
*********************************************************************/
