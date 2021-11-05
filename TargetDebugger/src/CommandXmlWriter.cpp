/********************************************************************
	Rhapsody	: 9.0.1 
	Login		: Y9DSYU706
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: CommandXmlWriter
//!	Generated Date	: Thu, 4, Nov 2021  
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\CommandXmlWriter.cpp
*********************************************************************/

#include "CommandXmlWriter.h"
#include "Command.h"
#include "CommandConstructor.h"
#include "CommandEventCreated.h"
#include "CommandEventEndDispatch.h"
#include "CommandEventStartDispatch.h"
#include "CommandIntVal.h"
#include "CommandOperationCall.h"
#include "CommandTraceEvent.h"
#include "ModelInstance.h"
#include "TargetInformation.h"
//## package LogicLevel::Exporter

//## class CommandXmlWriter
CommandXmlWriter::CommandXmlWriter(QXmlStreamWriter& p_xmlWriter) : xmlWriter(p_xmlWriter)
{
    //#[ operation CommandXmlWriter(QXmlStreamWriter)
    //#]
}

CommandXmlWriter::~CommandXmlWriter()
{
}

void CommandXmlWriter::writeCommand(const Command& command)
{
    //#[ operation writeCommand(Command)
    switch(command.getCommandIdentifier())
    {
    case Command::constructorCommand:
        this->writeConstructorCommand((const CommandConstructor&)command);
        break;
    case Command::traceEventCommand:
        this->writeTraceEventCommand((const CommandTraceEvent&)command);
        break;
    case Command::eventPutToMessageQueueCommand:
        this->writeEventCreatedCommand((const CommandEventCreated&)command);
        break;
    case Command::eventStartDispatchCommand:
        this->writeEventStartDispatchCommand((const CommandEventStartDispatch&)command);
        break;
    case Command::eventEndDispatchCommand:
        this->writeEventEndDispatchCommand((const CommandEventEndDispatch&)command);
        break;
    case Command::operationCalled:
        this->writeOperationCalledCommand((const CommandOperationCall&)command);
        break;
    case Command::debugIntValue:
        this->writeIntValCommand((const CommandIntVal&)command);
        break;
    default:
        // this section should not be reached for CommandList commands
        break;
    }
    
    //#]
}

void CommandXmlWriter::writeConstructorCommand(const CommandConstructor& constructorCommand)
{
    //#[ operation writeConstructorCommand(CommandConstructor)
    this->xmlWriter.writeStartElement("CommandConstructor");
    
    this->xmlWriter.writeAttribute("targetInformation", QString::number(constructorCommand.getItsTargetInformation()->getId()));
    this->xmlWriter.writeAttribute("ticks", QString::number(constructorCommand.getTicks()));
    this->xmlWriter.writeAttribute("modelInstance", QString::number(constructorCommand.getItsModelInstance()->getAddress(), 16));
    
    this->xmlWriter.writeEndElement();
    //#]
}

void CommandXmlWriter::writeEventCreatedCommand(const CommandEventCreated& eventCreatedCommand)
{
    //#[ operation writeEventCreatedCommand(CommandEventCreated)
    this->xmlWriter.writeStartElement("CommandEventCreated");
    
    this->xmlWriter.writeAttribute("targetInformation", QString::number(eventCreatedCommand.getItsTargetInformation()->getId()));
    this->xmlWriter.writeAttribute("ticks", QString::number(eventCreatedCommand.getTicks()));
    this->xmlWriter.writeAttribute("sourceInstance", QString::number(eventCreatedCommand.getSourceInstance()->getAddress(), 16));
    this->xmlWriter.writeAttribute("destinationInstance", QString::number(eventCreatedCommand.getDestinationInstance()->getAddress(), 16));
    this->xmlWriter.writeAttribute("modelEventType", QString::number(eventCreatedCommand.getItsModelEventType()->getId()));
    this->xmlWriter.writeAttribute("commandID", QString::number((uint)&eventCreatedCommand, 16));
    
    if(eventCreatedCommand.getReceivedEventParameters().isEmpty() == false)
    {
        this->writeReceivedEventParameters(eventCreatedCommand.getReceivedEventParameters());
    }
    
    this->xmlWriter.writeEndElement();
    //#]
}

void CommandXmlWriter::writeEventEndDispatchCommand(const CommandEventEndDispatch& eventEndDispatchCommand)
{
    //#[ operation writeEventEndDispatchCommand(CommandEventEndDispatch)
    this->xmlWriter.writeStartElement("CommandEventEndDispatch");
    
    this->xmlWriter.writeAttribute("targetInformation", QString::number(eventEndDispatchCommand.getItsTargetInformation()->getId()));
    this->xmlWriter.writeAttribute("ticks", QString::number(eventEndDispatchCommand.getTicks()));
    this->xmlWriter.writeAttribute("stateAfter", eventEndDispatchCommand.getStateAfterEventConsumption());
    this->xmlWriter.writeAttribute("eventStartDispatchID", QString::number((uint)eventEndDispatchCommand.getItsCommandEventStartDispatch(), 16));
    
    this->xmlWriter.writeEndElement();
    //#]
}

void CommandXmlWriter::writeEventStartDispatchCommand(const CommandEventStartDispatch& eventStartDispatchCommand)
{
    //#[ operation writeEventStartDispatchCommand(CommandEventStartDispatch)
    this->xmlWriter.writeStartElement("CommandEventStartDispatch");
    
    this->xmlWriter.writeAttribute("ticks", QString::number(eventStartDispatchCommand.getTicks()));
    this->xmlWriter.writeAttribute("targetInformation", QString::number(eventStartDispatchCommand.getItsTargetInformation()->getId()));
    this->xmlWriter.writeAttribute("eventCreatedID", QString::number((uint)eventStartDispatchCommand.getItsCommandEventCreated(), 16));
    this->xmlWriter.writeAttribute("commandID", QString::number((uint)&eventStartDispatchCommand, 16));
    
    this->xmlWriter.writeEndElement();
    //#]
}

void CommandXmlWriter::writeIntValCommand(const CommandIntVal& intValCommand)
{
    //#[ operation writeIntValCommand(CommandIntVal)
    this->xmlWriter.writeStartElement("CommandIntVal");
    
    this->xmlWriter.writeAttribute("ticks", QString::number(intValCommand.getTicks()));
    this->xmlWriter.writeAttribute("targetInformation", QString::number(intValCommand.getItsTargetInformation()->getId()));
    this->xmlWriter.writeAttribute("instance", QString::number(intValCommand.getInstance()->getAddress(), 16));
    this->xmlWriter.writeAttribute("intValue", QString::number(intValCommand.getIntValue()));
    
    this->xmlWriter.writeEndElement();
    //#]
}

void CommandXmlWriter::writeOperationCalledCommand(const CommandOperationCall& operationCalledCommand)
{
    //#[ operation writeOperationCalledCommand(CommandOperationCall)
    this->xmlWriter.writeStartElement("CommandOperationCall");
    
    this->xmlWriter.writeAttribute("targetInformation", QString::number(operationCalledCommand.getItsTargetInformation()->getId()));
    this->xmlWriter.writeAttribute("ticks", QString::number(operationCalledCommand.getTicks()));
    this->xmlWriter.writeAttribute("sourceInstance", QString::number(operationCalledCommand.getSourceInstance()->getAddress(), 16));
    this->xmlWriter.writeAttribute("destinationInstance", QString::number(operationCalledCommand.getDestinationInstance()->getAddress(), 16));
    this->xmlWriter.writeAttribute("modelEventType", QString::number(operationCalledCommand.getItsModelEventType()->getId()));
    
    if(operationCalledCommand.getReceivedEventParameters().isEmpty() == false)
    {
        this->writeReceivedEventParameters(operationCalledCommand.getReceivedEventParameters());
    }
    
    this->xmlWriter.writeEndElement();
    //#]
}

void CommandXmlWriter::writeReceivedEventParameters(const QVector<ReceivedEventParameter*>& receivedEventParameters)
{
    //#[ operation writeReceivedEventParameters(const QVector<ReceivedEventParameter*>&)
    this->xmlWriter.writeStartElement("ReceivedEventParameters");
            
    for(auto receivedEventParam : receivedEventParameters)
    {
        this->xmlWriter.writeStartElement("ReceivedEventParameter");
        {
            this->xmlWriter.writeAttribute("name", receivedEventParam->getItsModelEventArgumentType()->getName());
            this->xmlWriter.writeAttribute("value", receivedEventParam->getValue());
        }
        this->xmlWriter.writeEndElement();
    }
    
    this->xmlWriter.writeEndElement();
    //#]
}

void CommandXmlWriter::writeTraceEventCommand(const CommandTraceEvent& traceEventCommand)
{
    //#[ operation writeTraceEventCommand(CommandTraceEvent)
    this->xmlWriter.writeStartElement("CommandTraceEvent");
    
    this->xmlWriter.writeAttribute("targetInformation", QString::number(traceEventCommand.getItsTargetInformation()->getId()));
    this->xmlWriter.writeAttribute("ticks", QString::number(traceEventCommand.getTicks()));
    this->xmlWriter.writeAttribute("sourceInstance", QString::number(traceEventCommand.getSourceInstance()->getAddress(), 16));
    this->xmlWriter.writeAttribute("destinationInstance", QString::number(traceEventCommand.getDestinationInstance()->getAddress(), 16));
    this->xmlWriter.writeAttribute("modelEventType", QString::number(traceEventCommand.getItsModelEventType()->getId()));
    this->xmlWriter.writeAttribute("stateBefore", traceEventCommand.getStateAfterEventConsumption());
    
    if(traceEventCommand.getReceivedEventParameters().isEmpty() == false)
    {
        this->writeReceivedEventParameters(traceEventCommand.getReceivedEventParameters());
    }
    
    this->xmlWriter.writeEndElement();
    //#]
}

/*********************************************************************
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\CommandXmlWriter.cpp
*********************************************************************/
