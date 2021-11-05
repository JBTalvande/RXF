/********************************************************************
	Rhapsody	: 9.0.1 
	Login		: Y9DSYU706
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: CommandTraceEventKeyValueAdapter
//!	Generated Date	: Thu, 4, Nov 2021  
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\CommandTraceEventKeyValueAdapter.cpp
*********************************************************************/

#include "CommandTraceEventKeyValueAdapter.h"
#include "Command.h"
#include "CommandTraceEvent.h"
#include <QList.h>
#include "ReceivedEventParameter.h"
#include "TargetInformation.h"
//## package LogicLevel::Logging::Adapter::KeyValueAdapter

//## class CommandTraceEventKeyValueAdapter
CommandTraceEventKeyValueAdapter::CommandTraceEventKeyValueAdapter() : AbstractCommandKeyValueAdapter(Command::commandType::traceEventCommand)
{
    //#[ operation CommandTraceEventKeyValueAdapter()
    //#]
}

CommandTraceEventKeyValueAdapter::~CommandTraceEventKeyValueAdapter()
{
}

void CommandTraceEventKeyValueAdapter::addProperties(QHash<QString,QString>& keyValues, const Command& command)
{
    //#[ operation addProperties(QHash<QString,QString>&,Command)
    const CommandTraceEvent& traceEventCommand = (const CommandTraceEvent&)command;
    
    keyValues.insert("sourceInstance", QString::number(traceEventCommand.getSourceInstance()->getAddress(), 16));
    keyValues.insert("destinationInstance", QString::number(traceEventCommand.getDestinationInstance()->getAddress(), 16));
    keyValues.insert("modelEventType", QString::number(traceEventCommand.getItsModelEventType()->getId()));
    keyValues.insert("ticks", QString::number(traceEventCommand.getTicks()));
    keyValues.insert("targetInformation", QString::number(traceEventCommand.getItsTargetInformation()->getId()));
    keyValues.insert("stateBefore", traceEventCommand.getStateAfterEventConsumption());
    
    // compute received event parameters value
    QString receivedEventParameters = computeReceivedEventParametersString(traceEventCommand.getReceivedEventParameters());
    if(receivedEventParameters.isEmpty() == false)
    {
        keyValues.insert("parameters", receivedEventParameters);
    }
    
    //#]
}

/*********************************************************************
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\CommandTraceEventKeyValueAdapter.cpp
*********************************************************************/
