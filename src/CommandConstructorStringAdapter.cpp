/********************************************************************
	Rhapsody	: 9.0.1 
	Login		: Y9DSYU706
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: CommandConstructorStringAdapter
//!	Generated Date	: Thu, 4, Nov 2021  
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\CommandConstructorStringAdapter.cpp
*********************************************************************/

#include "CommandConstructorStringAdapter.h"
#include "Command.h"
#include "ModelClass.h"
#include "ModelInstance.h"
#include "TargetInformation.h"
//## package LogicLevel::Logging::Adapter::StringAdapter

//## class CommandConstructorStringAdapter
CommandConstructorStringAdapter::CommandConstructorStringAdapter() : AbstractCommandStringAdapter(Command::commandType::constructorCommand)
{
    //#[ operation CommandConstructorStringAdapter()
    //#]
}

CommandConstructorStringAdapter::~CommandConstructorStringAdapter()
{
}

QString CommandConstructorStringAdapter::getCommandProperties(const Command& p_command)
{
    //#[ operation getCommandProperties(Command)
    const CommandConstructor& constructorCommand = static_cast<const CommandConstructor&>(p_command);
    const ModelInstance* modelInstance = constructorCommand.getItsModelInstance();
    return QString("name=%1, class=%2, address=%3").arg(
                modelInstance->getName(),
                modelInstance->getItsModelClass()->getName(),
                QString::number(modelInstance->getAddress())
                );
    //#]
}

/*********************************************************************
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\CommandConstructorStringAdapter.cpp
*********************************************************************/
