/********************************************************************
	Rhapsody	: 9.0.1 
	Login		: Y9DSYU706
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: CommandEventCreatedStringAdapter
//!	Generated Date	: Thu, 4, Nov 2021  
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\CommandEventCreatedStringAdapter.cpp
*********************************************************************/

#include "CommandEventCreatedStringAdapter.h"
#include "Command.h"
#include "ModelEventType.h"
#include "ModelInstance.h"
#include "ReceivedEventParameter.h"
#include "TargetInformation.h"
//## package LogicLevel::Logging::Adapter::StringAdapter

//## class CommandEventCreatedStringAdapter
CommandEventCreatedStringAdapter::CommandEventCreatedStringAdapter() : AbstractCommandStringAdapter(Command::commandType::eventPutToMessageQueueCommand)
{
    //#[ operation CommandEventCreatedStringAdapter()
    //#]
}

CommandEventCreatedStringAdapter::~CommandEventCreatedStringAdapter()
{
}

QString CommandEventCreatedStringAdapter::getCommandProperties(const Command& p_command)
{
    //#[ operation getCommandProperties(Command)
    const CommandEventCreated& eventCreatedCommand = static_cast<const CommandEventCreated&>(p_command);
    return QString("ticks=%1; eventID=%2; eventTypeName=%3; eventParameters=%4; source=%5; destination=%6; commandInstance=%7").arg(
                QString::number(eventCreatedCommand.getTicks()),        // %1
                QString::number(eventCreatedCommand.getEventID()),      // %2
                eventCreatedCommand.getItsModelEventType()->getName(),  // %3
                getReceivedEventParameters(eventCreatedCommand),        // %4
                eventCreatedCommand.getSourceInstance()->getName(),     // %5
                eventCreatedCommand.getDestinationInstance()->getName(),// %6
                QString::number((quintptr)&eventCreatedCommand, 16)     // %7
                );
    //#]
}

QString CommandEventCreatedStringAdapter::getReceivedEventParameters(const CommandEventCreated& p_command)
{
    //#[ operation getReceivedEventParameters(CommandEventCreated)
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
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\CommandEventCreatedStringAdapter.cpp
*********************************************************************/
