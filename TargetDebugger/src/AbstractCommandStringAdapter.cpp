/********************************************************************
	Rhapsody	: 9.0.1 
	Login		: Y9DSYU706
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: AbstractCommandStringAdapter
//!	Generated Date	: Thu, 4, Nov 2021  
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\AbstractCommandStringAdapter.cpp
*********************************************************************/

#include "AbstractCommandStringAdapter.h"
#include "TargetInformation.h"
//## package LogicLevel::Logging::Adapter::StringAdapter

//## class AbstractCommandStringAdapter
AbstractCommandStringAdapter::AbstractCommandStringAdapter(const Command::commandType& p_commandType) : CommandAdapter(p_commandType)
{
    //#[ operation AbstractCommandStringAdapter(commandType)
    //#]
}

AbstractCommandStringAdapter::AbstractCommandStringAdapter()
{
}

AbstractCommandStringAdapter::~AbstractCommandStringAdapter()
{
}

QString AbstractCommandStringAdapter::adapt(const Command& command)
{
    //#[ operation adapt(Command)
    return QString("%1: target=%2, %3").arg(getCommandName(), command.getItsTargetInformation()->getName(), getCommandProperties(command));
    //#]
}

/*********************************************************************
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\AbstractCommandStringAdapter.cpp
*********************************************************************/
