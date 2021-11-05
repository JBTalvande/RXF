/********************************************************************
	Rhapsody	: 9.0.1 
	Login		: Y9DSYU706
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: CommandEventEndDispatchStringAdapter
//!	Generated Date	: Thu, 4, Nov 2021  
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\CommandEventEndDispatchStringAdapter.cpp
*********************************************************************/

#include "CommandEventEndDispatchStringAdapter.h"
#include "Command.h"
#include "CommandEventCreated.h"
#include "CommandEventEndDispatch.h"
#include "CommandEventStartDispatch.h"
#include "ModelEventType.h"
#include "TargetInformation.h"
//## package LogicLevel::Logging::Adapter::StringAdapter

//## class CommandEventEndDispatchStringAdapter
CommandEventEndDispatchStringAdapter::CommandEventEndDispatchStringAdapter() : AbstractCommandStringAdapter(Command::commandType::eventEndDispatchCommand)
{
    //#[ operation CommandEventEndDispatchStringAdapter()
    //#]
}

CommandEventEndDispatchStringAdapter::~CommandEventEndDispatchStringAdapter()
{
}

QString CommandEventEndDispatchStringAdapter::getCommandProperties(const Command& p_command)
{
    //#[ operation getCommandProperties(Command)
    const CommandEventEndDispatch& eventEndDispatchCommand = static_cast<const CommandEventEndDispatch&>(p_command);
    return QString("eventID=%1; eventName=%2; stateAfterEventConsumption=%3; eventCreatedInstance=%4").arg(
                QString::number(eventEndDispatchCommand.getEventID()),                      // %1
                eventEndDispatchCommand.getItsCommandEventStartDispatch()
                    ->getItsCommandEventCreated()->getItsModelEventType()->getName(),       // %2
                eventEndDispatchCommand.getStateAfterEventConsumption(),                    // %3
                QString::number((quintptr)eventEndDispatchCommand.getItsCommandEventStartDispatch()
                                ->getItsCommandEventCreated(), 16)                          // %4
                );
    //#]
}

/*********************************************************************
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\CommandEventEndDispatchStringAdapter.cpp
*********************************************************************/
