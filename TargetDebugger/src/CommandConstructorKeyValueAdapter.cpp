/********************************************************************
	Rhapsody	: 9.0.1 
	Login		: Y9DSYU706
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: CommandConstructorKeyValueAdapter
//!	Generated Date	: Thu, 4, Nov 2021  
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\CommandConstructorKeyValueAdapter.cpp
*********************************************************************/

#include "CommandConstructorKeyValueAdapter.h"
#include "Command.h"
#include "CommandConstructor.h"
#include "ModelClass.h"
#include "ModelInstance.h"
#include <QList.h>
#include "TargetInformation.h"
//## package LogicLevel::Logging::Adapter::KeyValueAdapter

//## class CommandConstructorKeyValueAdapter
CommandConstructorKeyValueAdapter::CommandConstructorKeyValueAdapter() : AbstractCommandKeyValueAdapter(Command::commandType::constructorCommand)
{
    //#[ operation CommandConstructorKeyValueAdapter()
    //#]
}

CommandConstructorKeyValueAdapter::~CommandConstructorKeyValueAdapter()
{
}

void CommandConstructorKeyValueAdapter::addProperties(QHash<QString,QString>& keyValues, const Command& command)
{
    //#[ operation addProperties(QHash<QString,QString>&,Command)
    const CommandConstructor& constructorCommand = (const CommandConstructor&)command;
    
    keyValues.insert("modelInstance", QString::number(constructorCommand.getItsModelInstance()->getAddress()));
    keyValues.insert("ticks", QString::number(constructorCommand.getTicks()));
    keyValues.insert("targetInformation", QString::number(constructorCommand.getItsTargetInformation()->getId()));
    //#]
}

/*********************************************************************
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\CommandConstructorKeyValueAdapter.cpp
*********************************************************************/
