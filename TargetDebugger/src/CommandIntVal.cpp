/********************************************************************
	Rhapsody	: 9.0.1 
	Login		: Y9DSYU706
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: CommandIntVal
//!	Generated Date	: Thu, 4, Nov 2021  
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\CommandIntVal.cpp
*********************************************************************/

#include "CommandIntVal.h"
#include "TargetInformation.h"
//## package LogicLevel::Logging::DataContainer::ReceivedCommands

//## class CommandIntVal
CommandIntVal::CommandIntVal(TargetInformation* target, unsigned int value, ModelInstance* instance) : Command( target )
{
    //#[ operation CommandIntVal(TargetInformation,unsigned int,ModelInstance)
    commandIdentifier = debugIntValue;
    this->instance = instance;
    this->intValue = value;
    //#]
}

CommandIntVal::~CommandIntVal()
{
}

/*********************************************************************
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\CommandIntVal.cpp
*********************************************************************/
