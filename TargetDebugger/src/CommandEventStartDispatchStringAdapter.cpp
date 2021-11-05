/********************************************************************
	Rhapsody	: 9.0.1 
	Login		: Y9DSYU706
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: CommandEventStartDispatchStringAdapter
//!	Generated Date	: Thu, 4, Nov 2021  
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\CommandEventStartDispatchStringAdapter.cpp
*********************************************************************/

#include "CommandEventStartDispatchStringAdapter.h"
#include "Command.h"
#include "CommandEventCreated.h"
#include "CommandEventStartDispatch.h"
#include "ModelEventType.h"
#include "TargetInformation.h"
//## package LogicLevel::Logging::Adapter::StringAdapter

//## class CommandEventStartDispatchStringAdapter
CommandEventStartDispatchStringAdapter::CommandEventStartDispatchStringAdapter() : AbstractCommandStringAdapter(Command::commandType::eventStartDispatchCommand)
{
    //#[ operation CommandEventStartDispatchStringAdapter()
    //#]
}

CommandEventStartDispatchStringAdapter::~CommandEventStartDispatchStringAdapter()
{
}

QString CommandEventStartDispatchStringAdapter::getCommandProperties(const Command& p_command)
{
    //#[ operation getCommandProperties(Command)
    const CommandEventStartDispatch& eventStartDispatchCommand = static_cast<const CommandEventStartDispatch&>(p_command);
    return QString("ticks=%1; eventID=%2; eventName=%3; eventCreatedInstance=%4").arg(
                QString::number(eventStartDispatchCommand.getTicks()),                                      // %1
                QString::number(eventStartDispatchCommand.getEventID()),                                    // %2
                eventStartDispatchCommand.getItsCommandEventCreated()->getItsModelEventType()->getName(),   // %3
                QString::number((quintptr)eventStartDispatchCommand.getItsCommandEventCreated(), 16)                  // %4
                );
    //#]
}

/*********************************************************************
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\CommandEventStartDispatchStringAdapter.cpp
*********************************************************************/
