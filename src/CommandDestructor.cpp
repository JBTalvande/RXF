/********************************************************************
	Rhapsody	: 9.0.1 
	Login		: Y9DSYU706
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: CommandDestructor
//!	Generated Date	: Thu, 4, Nov 2021  
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\CommandDestructor.cpp
*********************************************************************/

#include "CommandDestructor.h"
#include "ModelInstance.h"
#include "TargetInformation.h"
//## package LogicLevel::Logging::DataContainer::ReceivedCommands

//## class CommandDestructor
CommandDestructor::CommandDestructor(ModelInstance* instance, TargetInformation* target) : Command( target )
{
    itsModelInstance = instance;
    //#[ operation CommandDestructor(ModelInstance,TargetInformation)
    commandIdentifier = destructorCommand;
    //#]
}

CommandDestructor::~CommandDestructor()
{
    cleanUpRelations();
}

void CommandDestructor::cleanUpRelations()
{
    if(itsModelInstance != NULL)
        {
            itsModelInstance = NULL;
        }
}

/*********************************************************************
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\CommandDestructor.cpp
*********************************************************************/
