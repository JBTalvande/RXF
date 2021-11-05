/********************************************************************
	Rhapsody	: 9.0.1 
	Login		: Y9DSYU706
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: CommandOperationCallStringAdapter
//!	Generated Date	: Thu, 4, Nov 2021  
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\CommandOperationCallStringAdapter.cpp
*********************************************************************/

#include "CommandOperationCallStringAdapter.h"
#include "Command.h"
#include "CommandOperationCall.h"
#include "ModelEventType.h"
#include "ModelInstance.h"
#include "ReceivedEventParameter.h"
#include "TargetInformation.h"
//## package LogicLevel::Logging::Adapter::StringAdapter

//## class CommandOperationCallStringAdapter
CommandOperationCallStringAdapter::CommandOperationCallStringAdapter() : AbstractCommandStringAdapter(Command::commandType::operationCalled)
{
    //#[ operation CommandOperationCallStringAdapter()
    //#]
}

CommandOperationCallStringAdapter::~CommandOperationCallStringAdapter()
{
}

QString CommandOperationCallStringAdapter::getCommandProperties(const Command& p_command)
{
    //#[ operation getCommandProperties(Command)
    const CommandOperationCall& operationCallCommand = static_cast<const CommandOperationCall&>(p_command);
    return QString("ticks=%1; eventTypeName=%2; eventParameters=%3; source=%4; destination=%5; commandInstance=%6").arg(
                QString::number(operationCallCommand.getTicks()),           // %1
                operationCallCommand.getItsModelEventType()->getName(),     // %2
                this->getReceivedEventParameters(operationCallCommand),     // %3
                operationCallCommand.getSourceInstance()->getName(),        // %4
                operationCallCommand.getDestinationInstance()->getName(),   // %5
                QString::number((quintptr)&operationCallCommand, 16)         // %6
                );
    //#]
}

QString CommandOperationCallStringAdapter::getReceivedEventParameters(const CommandOperationCall& p_command)
{
    //#[ operation getReceivedEventParameters(CommandOperationCall)
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
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\CommandOperationCallStringAdapter.cpp
*********************************************************************/
