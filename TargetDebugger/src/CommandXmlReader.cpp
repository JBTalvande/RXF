/********************************************************************
	Rhapsody	: 9.0.1 
	Login		: Y9DSYU706
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: CommandXmlReader
//!	Generated Date	: Thu, 4, Nov 2021  
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\CommandXmlReader.cpp
*********************************************************************/

#include "CommandXmlReader.h"
#include "Command.h"
#include "CommandConstructor.h"
#include "CommandDestructor.h"
#include "CommandEventCreated.h"
#include "CommandEventEndDispatch.h"
#include "CommandEventStartDispatch.h"
#include "CommandIntVal.h"
#include "CommandOperationCall.h"
#include "CommandTraceEvent.h"
#include "TargetList.h"
//## package LogicLevel::Importer

//## class CommandXmlReader
CommandXmlReader::CommandXmlReader(QXmlStreamReader& p_xmlReader) : xmlReader(p_xmlReader)
{
    itsTargetList = NULL;
    //#[ operation CommandXmlReader(QXmlStreamReader)
    //#]
}

CommandXmlReader::~CommandXmlReader()
{
    cleanUpRelations();
}

Command* CommandXmlReader::readCommand()
{
    //#[ operation readCommand()
    Command* newCommand = NULL;
    // ensure that we are at a start element
    if(xmlReader.isStartElement())
    {
        QStringRef xmlElementName = this->xmlReader.name();
    
        if(xmlElementName == "CommandConstructor")
        {
            newCommand = this->readConstructorCommand();
        }
        else if(xmlElementName == "CommandDestructor")
        {
            newCommand = this->readDestructorCommand();
        }
        else if(xmlElementName == "CommandTraceEvent")
        {
            newCommand = this->readTraceEventCommand();
        }
        else if(xmlElementName == "CommandIntVal")
        {
            newCommand = this->readIntValCommand();
        }
        else if(xmlElementName == "CommandEventCreated")
        {
            newCommand = this->readEventCreatedCommand();
        }
        else if(xmlElementName == "CommandEventStartDispatch")
        {
            newCommand = this->readEventStartDispatchCommand();
        }
        else if(xmlElementName == "CommandEventEndDispatch")
        {
            newCommand = this->readEventEndDispatchCommand();
        }
        else if(xmlElementName == "CommandOperationCall")
        {
            newCommand = this->readOperationCalledCommand();
        }
        else
        {
            // read to end of unknown command incl. child elements
            while(xmlReader.readNextStartElement() || xmlReader.name() != xmlElementName);
        }
    }
    
    return newCommand;
    //#]
}

CommandConstructor* CommandXmlReader::readConstructorCommand()
{
    //#[ operation readConstructorCommand()
    CommandConstructor* constructorCommand = NULL;
    
    bool isValid;
    
    uint modelInstanceAddress;
    int targetInformationId;
    int ticks;
    
    // read attributes of ConstructorCommandElement
    for(QXmlStreamAttribute constructorCmdAttribute : this->xmlReader.attributes())
    {
        if(constructorCmdAttribute.name() == "modelInstance") {
            modelInstanceAddress = constructorCmdAttribute.value().toUInt(&isValid, 16);
        }
        else if(constructorCmdAttribute.name() == "targetInformation") {
            targetInformationId = constructorCmdAttribute.value().toInt(&isValid);
        }
        else if(constructorCmdAttribute.name() == "ticks") {
            ticks = constructorCmdAttribute.value().toInt(&isValid);
        }
    }
    
    if(isValid)
    {
        TargetInformation* target = this->itsTargetList->getTarget(targetInformationId);
        if(target != NULL)
        {
            ModelInstance* instance = target->getInstance(modelInstanceAddress);
    
            constructorCommand = new CommandConstructor(instance, target);
            constructorCommand->setTicks(ticks);
        }
        else
        {
            // TODO do error handling using exceptions
        }
    }
    
    // read to end of CommandConstructor
    while(this->xmlReader.readNextStartElement());
    
    return constructorCommand;
    //#]
}

CommandDestructor* CommandXmlReader::readDestructorCommand()
{
    //#[ operation readDestructorCommand()
    CommandDestructor* destructorCommand = NULL;
    
    bool isValid;
    
    uint modelInstanceAddress;
    int targetInformationId;
    int ticks;
    
    // read attributes of ConstructorCommandElement
    for(QXmlStreamAttribute destructorCmdAttribute : this->xmlReader.attributes())
    {
        if(destructorCmdAttribute.name() == "modelInstance") {
            modelInstanceAddress = destructorCmdAttribute.value().toUInt(&isValid, 16);
        }
        else if(destructorCmdAttribute.name() == "targetInformation") {
            targetInformationId = destructorCmdAttribute.value().toInt(&isValid);
        }
        else if(destructorCmdAttribute.name() == "ticks") {
            ticks = destructorCmdAttribute.value().toInt(&isValid);
        }
    }
    
    if(isValid)
    {
        TargetInformation* target = this->itsTargetList->getTarget(targetInformationId);
        if(target != NULL)
        {
            ModelInstance* instance = target->getInstance(modelInstanceAddress);
    
            destructorCommand = new CommandDestructor(instance, target);
            destructorCommand->setTicks(ticks);
        }
        else
        {
            // TODO do error handling using exceptions
        }
    }
    
    // read to end of CommandConstructor
    while(this->xmlReader.readNextStartElement());
    
    return destructorCommand;
    //#]
}

CommandEventCreated* CommandXmlReader::readEventCreatedCommand()
{
    //#[ operation readEventCreatedCommand()
    CommandEventCreated* eventCreatedCommand = NULL;
    
    bool isValid;
    
    int targetInformationId;
    int ticks;
    uint sourceAddress;
    uint destAddress;
    uint modelEventTypeId;
    uint commandID;
    
    // read attributes of CommandEventCreated
    for(QXmlStreamAttribute cmdEventCreatedAttr : this->xmlReader.attributes())
    {
        if(cmdEventCreatedAttr.name() == "targetInformation") {
            targetInformationId = cmdEventCreatedAttr.value().toInt(&isValid);
        }
        else if(cmdEventCreatedAttr.name() == "ticks") {
            ticks = cmdEventCreatedAttr.value().toInt(&isValid);
        }
        else if(cmdEventCreatedAttr.name() == "sourceInstance") {
            sourceAddress = cmdEventCreatedAttr.value().toUInt(&isValid, 16);
        }
        else if(cmdEventCreatedAttr.name() == "destinationInstance") {
            destAddress = cmdEventCreatedAttr.value().toUInt(&isValid, 16);
        }
        else if(cmdEventCreatedAttr.name() == "modelEventType") {
            modelEventTypeId = cmdEventCreatedAttr.value().toUInt(&isValid);
        }
        else if(cmdEventCreatedAttr.name() == "commandID") {
            commandID = cmdEventCreatedAttr.value().toUInt(&isValid, 16);
        }
    }
    
    if(isValid)
    {
        TargetInformation* target = this->itsTargetList->getTarget(targetInformationId);
        if(target != NULL)
        {
            ModelInstance* sourceInstance = target->getInstance(sourceAddress);
            ModelInstance* destInstance = target->getInstance(destAddress);
            ModelEventType* modelEventType = target->getEventType(modelEventTypeId);
    
            // modelEventID is not needed when reading commands from XML
            eventCreatedCommand = new CommandEventCreated(0, ticks, sourceInstance, modelEventType, destInstance, target);
    
            // add tripple command to internal cache for referencing by other tripple commands
            this->tripletDataCache.insert(commandID, eventCreatedCommand);
    
            // read content (ReceivedEventParameters) or endElement
            while(this->xmlReader.readNextStartElement())
            {
                if(this->xmlReader.name() == "ReceivedEventParameters")
                {
                    auto receivedEventParameters = this->readReceivedEventParameters();
                    for(auto receivedEventParam : receivedEventParameters)
                    {
                        eventCreatedCommand->addItsReceivedEventParameter(receivedEventParam);
                    }
                }
            }
        }
    }
    else
    {
        qInfo("CommandEventCreated is not valid");
    }
    
    return eventCreatedCommand;
    //#]
}

CommandEventEndDispatch* CommandXmlReader::readEventEndDispatchCommand()
{
    //#[ operation readEventEndDispatchCommand()
    CommandEventEndDispatch* eventEndDispatchCommand = NULL;
    
    bool isValid;
    
    int targetInformationId;
    int ticks;
    QString stateAfter;
    uint eventStartDispatchID;
    
    // read attributes of CommandEventStartDispatch
    for(QXmlStreamAttribute cmdEventStartDispatchAttr : this->xmlReader.attributes())
    {
        if(cmdEventStartDispatchAttr.name() == "targetInformation") {
            targetInformationId = cmdEventStartDispatchAttr.value().toInt(&isValid);
        }
        else if(cmdEventStartDispatchAttr.name() == "ticks") {
            ticks = cmdEventStartDispatchAttr.value().toInt(&isValid);
        }
        else if(cmdEventStartDispatchAttr.name() == "stateAfter") {
            stateAfter = cmdEventStartDispatchAttr.value().toString();
        }
        else if(cmdEventStartDispatchAttr.name() == "eventStartDispatchID") {
            eventStartDispatchID = cmdEventStartDispatchAttr.value().toUInt(&isValid, 16);
        }
    }
    
    if(isValid)
    {
        TargetInformation* target = this->itsTargetList->getTarget(targetInformationId);
        CommandEventStartDispatch* eventStartDispatch = (CommandEventStartDispatch*)this->tripletDataCache.value(eventStartDispatchID);
    
        if(target != NULL && eventStartDispatch != NULL)
        {
            eventEndDispatchCommand = new CommandEventEndDispatch(0, eventStartDispatch, stateAfter, target);
            eventStartDispatch->setItsCommandEventEndDispatch(eventEndDispatchCommand);
            eventEndDispatchCommand->setTicks(ticks);
        }
        else
        {
            qInfo("No appropriate Triplet or Target could be found for CommandEventEndDispatch");
        }
    }
    else
    {
        qInfo("CommandEventEndDispatch attributes invalid");
    }
    // read to end of CommandEventEndDispatch
    while(this->xmlReader.readNextStartElement());
    
    return eventEndDispatchCommand;
    //#]
}

CommandEventStartDispatch* CommandXmlReader::readEventStartDispatchCommand()
{
    //#[ operation readEventStartDispatchCommand()
    CommandEventStartDispatch* eventStartDispatchCommand = NULL;
    
    bool isValid;
    
    int targetInformationId;
    int ticks;
    uint eventCreatedID;
    uint commandID;
    
    // read attributes of CommandEventStartDispatch
    for(QXmlStreamAttribute cmdEventStartDispatchAttr : this->xmlReader.attributes())
    {
        if(cmdEventStartDispatchAttr.name() == "targetInformation") {
            targetInformationId = cmdEventStartDispatchAttr.value().toInt(&isValid);
        }
        else if(cmdEventStartDispatchAttr.name() == "ticks") {
            ticks = cmdEventStartDispatchAttr.value().toInt(&isValid);
        }
        else if(cmdEventStartDispatchAttr.name() == "eventCreatedID") {
            eventCreatedID = cmdEventStartDispatchAttr.value().toUInt(&isValid, 16);
        }
        else if(cmdEventStartDispatchAttr.name() == "commandID") {
            commandID = cmdEventStartDispatchAttr.value().toUInt(&isValid, 16);
        }
    }
    
    if(isValid)
    {
        TargetInformation* target = this->itsTargetList->getTarget(targetInformationId);
        CommandEventCreated* eventCreatedCommand = (CommandEventCreated*)this->tripletDataCache.value(eventCreatedID);
    
        if(target != NULL && eventCreatedCommand != NULL)
        {
            eventStartDispatchCommand = new CommandEventStartDispatch(0, ticks, eventCreatedCommand, target);
            eventCreatedCommand->setItsCommandEventStartDispatch(eventStartDispatchCommand);
            // add event to tripletDataCache for referencing by other events
            this->tripletDataCache.insert(commandID, eventStartDispatchCommand);
        }
        else
        {
            qInfo("No appropriate Triplet or Target could be found for CommandEventStartDispatch");
        }
    }
    else
    {
        qInfo("CommandEventStartDispatch attributes invalid");
    }
    // read to end of CommandEventStartDispatch
    while(this->xmlReader.readNextStartElement());
    
    return eventStartDispatchCommand;
    //#]
}

CommandIntVal* CommandXmlReader::readIntValCommand()
{
    //#[ operation readIntValCommand()
    CommandIntVal* intValCommand = NULL;
    
    int targetInformationId;
    int ticks;
    uint instanceAddress;
    uint intValue;
    
    bool isValid = false;
    
    // read attributes of CommandIntVal
    for(QXmlStreamAttribute intValCmdAttribute : this->xmlReader.attributes())
    {
        if(intValCmdAttribute.name() == "instance") {
            instanceAddress = intValCmdAttribute.value().toUInt(&isValid, 16);
        }
        else if(intValCmdAttribute.name() == "targetInformation") {
            targetInformationId = intValCmdAttribute.value().toInt(&isValid);
        }
        else if(intValCmdAttribute.name() == "ticks") {
            ticks = intValCmdAttribute.value().toInt(&isValid);
        }
        else if(intValCmdAttribute.name() == "intValue") {
            intValue = intValCmdAttribute.value().toUInt(&isValid);
        }
    }
    
    if(isValid)
    {
        TargetInformation* target = this->itsTargetList->getTarget(targetInformationId);
        if(target != NULL)
        {
            ModelInstance* instance = target->getInstance(instanceAddress);
            intValCommand = new CommandIntVal(target, intValue, instance);
            intValCommand->setTicks(ticks);
        }
    }
    
    // read to end of CommandIntVal
    while(this->xmlReader.readNextStartElement());
    
    return intValCommand;
    //#]
}

CommandOperationCall* CommandXmlReader::readOperationCalledCommand()
{
    //#[ operation readOperationCalledCommand()
    CommandOperationCall* operationCalledCommand = NULL;
    
    int targetInformationId;
    int ticks;
    uint sourceAddress;
    uint destAddress;
    uint modelEventTypeId;
    
    bool isValid;
    
    // read attributes of CommandTraceEventElement
    for(QXmlStreamAttribute cmdOperationCalledAttr : this->xmlReader.attributes())
    {
        if(cmdOperationCalledAttr.name() == "targetInformation") {
            targetInformationId = cmdOperationCalledAttr.value().toInt(&isValid);
        }
        else if(cmdOperationCalledAttr.name() == "ticks") {
            ticks = cmdOperationCalledAttr.value().toInt(&isValid);
        }
        else if(cmdOperationCalledAttr.name() == "sourceInstance") {
            sourceAddress = cmdOperationCalledAttr.value().toUInt(&isValid, 16);
        }
        else if(cmdOperationCalledAttr.name() == "destinationInstance") {
            destAddress = cmdOperationCalledAttr.value().toUInt(&isValid, 16);
        }
        else if(cmdOperationCalledAttr.name() == "modelEventType") {
            modelEventTypeId = cmdOperationCalledAttr.value().toUInt(&isValid);
        }
    }
    
    if(isValid)
    {
        TargetInformation* target = this->itsTargetList->getTarget(targetInformationId);
        if(target != NULL)
        {
            ModelInstance* sourceInstance = target->getInstance(sourceAddress);
            ModelInstance* destInstance = target->getInstance(destAddress);
            ModelEventType* modelEventType = target->getEventType(modelEventTypeId);
    
            operationCalledCommand = new CommandOperationCall(ticks, sourceInstance, modelEventType, destInstance, target);
    
            // read content (ReceivedEventParameters) or endElement
            while(this->xmlReader.readNextStartElement())
            {
                if(this->xmlReader.name() == "ReceivedEventParameters")
                {
                    auto receivedEventParameters = this->readReceivedEventParameters();
                    for(auto receivedEventParam : receivedEventParameters)
                    {
                        operationCalledCommand->addItsReceivedEventParameter(receivedEventParam);
                    }
                }
            }
        }
    }
    
    return operationCalledCommand;
    //#]
}

QVector<ReceivedEventParameter*> CommandXmlReader::readReceivedEventParameters()
{
    //#[ operation readReceivedEventParameters()
    QVector<ReceivedEventParameter*> receivedEventParameters;
    while(this->xmlReader.readNextStartElement())
    {
        if(this->xmlReader.name() == "ReceivedEventParameter")
        {
            QString name;
            QString value;
    
            // read receivedEventParameter attributes
            for(QXmlStreamAttribute receivedEventParamAttr : this->xmlReader.attributes())
            {
                if(receivedEventParamAttr.name() == "name") {
                    name = receivedEventParamAttr.value().toString();
                }
                else if(receivedEventParamAttr.name() == "value") {
                    value = receivedEventParamAttr.value().toString();
                }
            }
    
            // TODO: probably avoid creating implicit types and write/read argument types to xml instead
            ModelEventArgumentType* implicitType = new ModelEventArgumentType(name, NULL);
            ReceivedEventParameter* receivedEventParameter = new ReceivedEventParameter(implicitType, value);
            receivedEventParameters.append(receivedEventParameter);
    
            // read to end of ReceivedEventParameter
            while(this->xmlReader.readNextStartElement());
        }
    }
    
    return receivedEventParameters;
    //#]
}

CommandTraceEvent* CommandXmlReader::readTraceEventCommand()
{
    //#[ operation readTraceEventCommand()
    CommandTraceEvent* traceEventCommand = NULL;
    
    bool isValid;
    
    int targetInformationId;
    int ticks;
    uint sourceAddress;
    uint destAddress;
    uint modelEventTypeId;
    QString stateBefore;
    
    // read attributes of CommandTraceEventElement
    for(QXmlStreamAttribute cmdTraceEventAttr : this->xmlReader.attributes())
    {
        if(cmdTraceEventAttr.name() == "targetInformation") {
            targetInformationId = cmdTraceEventAttr.value().toInt(&isValid);
        }
        else if(cmdTraceEventAttr.name() == "ticks") {
            ticks = cmdTraceEventAttr.value().toInt(&isValid);
        }
        else if(cmdTraceEventAttr.name() == "sourceInstance") {
            sourceAddress = cmdTraceEventAttr.value().toUInt(&isValid, 16);
        }
        else if(cmdTraceEventAttr.name() == "destinationInstance") {
            destAddress = cmdTraceEventAttr.value().toUInt(&isValid, 16);
        }
        else if(cmdTraceEventAttr.name() == "modelEventType") {
            modelEventTypeId = cmdTraceEventAttr.value().toUInt(&isValid);
        }
        else if(cmdTraceEventAttr.name() == "stateBefore") {
            stateBefore = cmdTraceEventAttr.value().toString();
        }
    }
       
    if(isValid)
    {
        TargetInformation* target = this->itsTargetList->getTarget(targetInformationId);
        if(target != NULL)
        {
            ModelInstance* sourceInstance = target->getInstance(sourceAddress);
            ModelInstance* destInstance = target->getInstance(destAddress);
            ModelEventType* modelEventType = target->getEventType(modelEventTypeId);
    
            traceEventCommand = new CommandTraceEvent(ticks, sourceInstance, destInstance, modelEventType, stateBefore, target);
    
            // read content (ReceivedEventParameters) or endElement
            while(this->xmlReader.readNextStartElement())
            {
                if(this->xmlReader.name() == "ReceivedEventParameters")
                {
                    auto receivedEventParameters = this->readReceivedEventParameters();
                    for(auto receivedEventParam : receivedEventParameters)
                    {
                        traceEventCommand->addItsReceivedEventParameter(receivedEventParam);
                    }
                }
            }
        }
        else
        {
            // TODO do error handling using exceptions
            qInfo("No target found for TraceEvent");
        }
    }
    else
    {
        // TODO error handling for this case
        qInfo("Attributes not valid for TraceEvent");
    }
    
    
    return traceEventCommand;
    //#]
}

void CommandXmlReader::cleanUpRelations()
{
    if(itsTargetList != NULL)
        {
            itsTargetList = NULL;
        }
}

/*********************************************************************
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\CommandXmlReader.cpp
*********************************************************************/
