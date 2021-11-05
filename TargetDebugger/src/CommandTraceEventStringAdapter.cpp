/********************************************************************
	Rhapsody	: 9.0.1 
	Login		: Y9DSYU706
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: CommandTraceEventStringAdapter
//!	Generated Date	: Thu, 4, Nov 2021  
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\CommandTraceEventStringAdapter.cpp
*********************************************************************/

#include "CommandTraceEventStringAdapter.h"
#include "Command.h"
#include "CommandTraceEvent.h"
#include "ModelEventType.h"
#include "TargetInformation.h"
//## package LogicLevel::Logging::Adapter::StringAdapter

//## class CommandTraceEventStringAdapter
CommandTraceEventStringAdapter::CommandTraceEventStringAdapter() : AbstractCommandStringAdapter(Command::commandType::traceEventCommand)
{
    //#[ operation CommandTraceEventStringAdapter()
    //#]
}

CommandTraceEventStringAdapter::~CommandTraceEventStringAdapter()
{
}

QString CommandTraceEventStringAdapter::getCommandProperties(const Command& p_command)
{
    //#[ operation getCommandProperties(Command)
    const CommandTraceEvent& traceEventCommand = (const CommandTraceEvent&)p_command;
    return QString("ticks=%1; eventTypeName=%2; eventParameters=%3; source=%4; destination=%5; stateAfterEventConsumption=%6").arg(
                QString::number(traceEventCommand.getTicks()),           // %1
                traceEventCommand.getItsModelEventType()->getName(),     // %2
                this->getReceivedEventParameters(traceEventCommand),     // %3
                traceEventCommand.getSourceInstance()->getName(),        // %4
                traceEventCommand.getDestinationInstance()->getName(),   // %5
                traceEventCommand.getStateAfterEventConsumption()        // %6
                );
    //#]
}

QString CommandTraceEventStringAdapter::getReceivedEventParameters(const CommandTraceEvent& p_command)
{
    //#[ operation getReceivedEventParameters(CommandTraceEvent)
    QString result = "[";
    
    if(p_command.getReceivedEventParameters().empty() == false)
    {
        QString delimiter("");
        for(auto eventParameter : p_command.getReceivedEventParameters())
        {
            result += QString("%1%2=%3").arg(
                        delimiter,
                        eventParameter->getItsModelEventArgumentType()->getName(),
                        eventParameter->getValue());
            delimiter = ", ";
        }
    
    
    }
    
    result += "]";
    return result;
    //#]
}

/*********************************************************************
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\CommandTraceEventStringAdapter.cpp
*********************************************************************/
