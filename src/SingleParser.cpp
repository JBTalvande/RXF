/********************************************************************
	Rhapsody	: 9.0.1 
	Login		: Y9DSYU706
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: SingleParser
//!	Generated Date	: Thu, 4, Nov 2021  
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\SingleParser.cpp
*********************************************************************/

#include "SingleParser.h"
#include "CommandConstructor.h"
#include "CommandDestructor.h"
#include "CommandEventCreated.h"
#include "CommandEventEndDispatch.h"
#include "CommandEventStartDispatch.h"
#include "CommandIntVal.h"
#include "CommandOperationCall.h"
#include "CommandTraceEvent.h"
#include "MainWindow.h"
#include "ModelEventType.h"
#include "ModelInstance.h"
#include "ReceivedCommandsLogger.h"
#include "RemoteControll.h"
#include "TargetInformation.h"
//## package LogicLevel::DataTransmission::DataParser

//## class SingleParser
bool SingleParser::processConstructorCalls(true);

bool SingleParser::processDestructorCalls(true);

SingleParser::SingleParser() : parallelStateCount(4), stateSize(1), brokenReceivedEventParameter(0, 0), itsModelEventArgumentType("Parse Argumets Failed", NULL)
{
    itsRemoteControll = NULL;
    initRelations();
    //#[ operation SingleParser()
    //#]
}

SingleParser::~SingleParser()
{
    cleanUpRelations();
}

void SingleParser::analyzeCommand(unsigned char* command, unsigned int commandSize)
{
    //#[ operation analyzeCommand(unsigned char*,unsigned int)
    switch ( command[ 0 ] )
    {
    
        case eventStartDispatch:
        {
            commandEventStartDispatch( command );
            break;
        }
    
        case eventEndDispatch:
        {
            commandEventEndDispatch( command );
            break;
        }
    
        case eventPutToMessageQueue:
        {
            commandEventPutToMessageQueue( command );
            break;
        }
    
        case eventTrace:
        {
            this->commandTraceEvent( command );
            break;
        }
    
        case timeOffset:
        {
            this->commandSyncTime( command );
            break;
        }
    
        case objectAttributRequest:
        {
            commandObjectAttributRequest( command, commandSize );
            break;
        }
    
        case objectStateRequest:
        {
            commandObjectStateRequest( command );
            break;
        }
    
        case errorHandlerReached:
        {
            commandErrorHandlerReached( );
            break;
        }
    
        case stateSizeInformation:
        {
            commandStateSizeInformation( command );
            break;
        }
    
        case typeSizes:
        {
            commandTypeSizes( command );
            break;
        }
    
        case objectCreated:
        {
            commandObjectCreated( command );
            break;
        }
    
        case objectDestroyed:
        {
            commandObjectDestroyed( command );
            break;
        }
    
        case operationCalled:
        {
            commandOperationCalled( command );
            break;
        }
    
        case timeOutEventStart:
        {
            commandTimeOutEvent( command );
            break;
        }
    
        case traceTimeout:
        {
            this->commandTimeOutTrace( command );
            break;
        }
    
        case timeReset:
        {
            this->commandTimeReset( command );
            break;
        }
    
        case versionNumber:
        {
            itsMainWindow->removeTarget( *itsTargetInformation );
            itsTargetInformation->setIncommingTypeNr( 0 );
            for( auto aModelClass : itsTargetInformation->getModelClassList() )
            {
                aModelClass->resetInstanceCount();
                aModelClass->resetAttributeOffset();
            }
            commandNewVersion( command );
            break;
        }
    
        case bufferOverflow:
        {
            commandBufferOverflow( );
            break;
        }
        case intValue:
        {
            commandIntVal( command );
            break;
        }
        case targetConsoleMessage:
        {
            commandTargetMessage( command, commandSize );
            break;
        }
    }
    //#]
}

bool SingleParser::checkCommandStart(unsigned char size, char command)
{
    //#[ operation checkCommandStart(unsigned char,char)
    for(int i=0 ;i < COMMAND_COUNT ;i++)
    {
        if( commands[i] == command &&
            ( commandsSize[i]==size || ( commandsSize[i]==255 && commandsMinimalSize[i] <= size ) )
          )
        {
            return true;
        }
    }
    return false;
    //#]
}

void SingleParser::commandBufferOverflow()
{
    //#[ operation commandBufferOverflow()
    itsReceivedCommandsLogger->bufferOverflow( itsTargetInformation );
    //#]
}

void SingleParser::commandErrorHandlerReached()
{
    //#[ operation commandErrorHandlerReached()
    itsReceivedCommandsLogger->errorHandlerReached( itsTargetInformation );
    //#]
}

void SingleParser::commandEventEndDispatch(unsigned char* command)
{
    //#[ operation commandEventEndDispatch(unsigned char*)
    #if DEMO == 1
        anzEvents++;
        if((anzEvents-1)==DEMO_MAX_EVENTS){
            QString eval = "You have reached the limit of the demo version with " + QString::number(DEMO_MAX_EVENTS,10) + " events.";
            eval += "\nPlease close and restart the Embedded UML Target Debugger for further usage.";
            eval += "\nYou can contact Willert Software Tools.";
    
            //QMessageBox::information ( NULL, "Evaluation Version", eval, QMessageBox::Ok , 0, 0 );
            //target->mw->sendToConsole(eval);
            emit newErrorMsg(eval);
            target->mw->getUI()->menuRecent_opend_files->setEnabled(false);
            target->mw->getUI()->actionOpen_XML_file->setEnabled(false);
            target->mw->getUI()->actionSelectComPlugin->setEnabled(false);
            break;
    
        }
        if(anzEvents>DEMO_MAX_EVENTS){
            break ;
        }
    #endif
    uint eventID = read2Byte (command, 1);
    
    CommandEventStartDispatch *prevStartEvent = (CommandEventStartDispatch*)findPreviousEvent( eventID, Command::eventStartDispatchCommand );
    
    
    if( prevStartEvent != NULL)
    {    
        CommandEventCreated* createEvent = prevStartEvent->getItsCommandEventCreated();
        ModelInstance* destinationInstance = createEvent->getDestinationInstance();
    
        QString currentStateNames = this->readStateNames(command + 3, destinationInstance);
    
        CommandEventEndDispatch *newEvent = new CommandEventEndDispatch( eventID, prevStartEvent, currentStateNames, itsTargetInformation );
        prevStartEvent->setItsCommandEventEndDispatch( newEvent );
        itsReceivedCommandsLogger->addCommandToActiveList( newEvent );
    
    }
    else
    {
        itsReceivedCommandsLogger->unrecognizedEvent( eventID, Command::eventEndDispatchCommand );
    }
    //#]
}

void SingleParser::commandEventPutToMessageQueue(unsigned char* command)
{
    //#[ operation commandEventPutToMessageQueue(unsigned char*)
    #if DEMO == 1
    anzEvents++;
    if((anzEvents-1)==DEMO_MAX_EVENTS){
        QString eval = "You have reached the limit of the demo version with " + QString::number(DEMO_MAX_EVENTS,10) + " events.";
        eval += "\nPlease close and restart the Embedded UML Target Debugger for further usage.";
        eval += "\nYou can contact Willert Software Tools.";
    
        //QMessageBox::information ( NULL, "Evaluation Version", eval, QMessageBox::Ok , 0, 0 );
        //target->mw->sendToConsole(eval);
        emit newErrorMsg(eval);
        target->mw->getUI()->menuRecent_opend_files->setEnabled(false);
        target->mw->getUI()->actionOpen_XML_file->setEnabled(false);
        target->mw->getUI()->actionSelectComPlugin->setEnabled(false);
        break;
    
    }
    if(anzEvents>DEMO_MAX_EVENTS){
        break ;
    }
    #endif
    uint64_t source = readAddress( command, 1 );
    uint64_t destination = readAddress( command, itsTargetInformation->getPointerSize() + 1 );
    uint eventID = read2Byte (command, itsTargetInformation->getPointerSize() * 2 + 1);
    uint id = read2Byte( command, itsTargetInformation->getPointerSize() * 2 + 3 );
    uint ticks = command[ itsTargetInformation->getPointerSize() * 2 + 5 ] + itsTargetInformation->getTimeOffset();
    
    
    ModelEventType *eventType = itsTargetInformation->getEventType( id );
    
    ModelInstance* sourceInstance = itsTargetInformation->getInstance( source );
    
    ModelInstance* destinationInstance = itsTargetInformation->getInstance( destination );
    
    CommandEventCreated *newEvent = new CommandEventCreated( eventID, ticks, sourceInstance, eventType, destinationInstance, itsTargetInformation );
    
    
    int memCounter=0;
    
    for( auto myEventArgument : eventType->getArguments() )
    {
        int parameterSize = myEventArgument->getType()->getSize();
        if( parameterSize == 0 )
        {
            newEvent->addItsReceivedEventParameter( &brokenReceivedEventParameter );
            break;
        }
        if((parameterSize > 0 && memCounter % parameterSize != 0) || ( memCounter % 4 ) != 0)
        {
            memCounter += parameterSize - (memCounter % parameterSize);
        }
        QString value = "0x";
        if(itsTargetInformation->getEndianess() != LITTLE_ENDIAN )
        {
            for(int i = 0; i < parameterSize; i++)
            {
                QString byteValue = QString::number( (unsigned int)(unsigned char)command[ ( itsTargetInformation->getPointerSize() * 2 ) + 6 + memCounter + i ],16);
                if(byteValue.length() == 2)
                {
                    value+=byteValue;
                }
                else
                {
                    value+="0"+byteValue;
                }
            }
        }
        else
        {
            for(int i = parameterSize-1; i >= 0; i--)
            {
               QString byteValue = QString::number( (unsigned int)(unsigned char)command[ ( itsTargetInformation->getPointerSize() * 2 ) + 6 + memCounter + i ],16);
               if(byteValue.length() == 2)
               {
                   value+=byteValue;
               }
               else
               {
                   value+="0"+byteValue;
               }
            }
        }
    
        newEvent->addItsReceivedEventParameter( new ReceivedEventParameter(myEventArgument, value) );
    
        memCounter += parameterSize;
    }
    temporaryEventList.push_back( (CommandEventTripletData*)newEvent);
    itsReceivedCommandsLogger->addCommandToActiveList( newEvent );
    
    //#]
}

void SingleParser::commandEventStartDispatch(unsigned char* command)
{
    //#[ operation commandEventStartDispatch(unsigned char*)
    #if DEMO == 1
        anzEvents++;
        if((anzEvents-1)==DEMO_MAX_EVENTS){
            QString eval = "You have reached the limit of the demo version with " + QString::number(DEMO_MAX_EVENTS,10) + " events.";
            eval += "\nPlease close and restart the Embedded UML Target Debugger for further usage.";
            eval += "\nYou can contact Willert Software Tools.";
    
            //QMessageBox::information ( NULL, "Evaluation Version", eval, QMessageBox::Ok , 0, 0 );
            //target->mw->sendToConsole(eval);
            emit newErrorMsg(eval);
            target->mw->getUI()->menuRecent_opend_files->setEnabled(false);
            target->mw->getUI()->actionOpen_XML_file->setEnabled(false);
            target->mw->getUI()->actionSelectComPlugin->setEnabled(false);
            break;
    
        }
        if(anzEvents>DEMO_MAX_EVENTS){
            break ;
        }
    #endif
    uint eventID = read2Byte (command, 1);
    uint ticks = command[3] + itsTargetInformation->getTimeOffset();
    
    CommandEventCreated *prevCreateEvent = (CommandEventCreated*)findPreviousEvent( eventID, Command::eventPutToMessageQueueCommand );
    
    if( prevCreateEvent != NULL )
    {
        CommandEventStartDispatch *newEvent = new CommandEventStartDispatch( eventID , ticks, prevCreateEvent, itsTargetInformation );
        prevCreateEvent->setItsCommandEventStartDispatch( newEvent );
        temporaryEventList.push_back( (CommandEventTripletData*)newEvent);
        itsReceivedCommandsLogger->addCommandToActiveList( newEvent );
    }
    else
    {
        itsReceivedCommandsLogger->unrecognizedEvent( eventID, Command::eventStartDispatchCommand );
    }
    //#]
}

void SingleParser::commandIntVal(unsigned char* command)
{
    //#[ operation commandIntVal(unsigned char*)
    uint64_t instanceAddress = readAddress( command, 1 );
    uint intVal = read4Byte( command, 1 + itsTargetInformation->getPointerSize() );
    ModelInstance *myInstance = itsTargetInformation->getInstance( instanceAddress );
    CommandIntVal *myCommandIntVal = new CommandIntVal( itsTargetInformation, intVal, myInstance);
    itsReceivedCommandsLogger->addCommandToActiveList( myCommandIntVal );
    //#]
}

void SingleParser::commandObjectAttributRequest(unsigned char* command, unsigned int commandSize)
{
    //#[ operation commandObjectAttributRequest(unsigned char*,unsigned int)
    if( commandSize > 250 )
    {
        commandSize = 4;
    }
    QString value= "0x";
    if(itsTargetInformation->getEndianess() != LITTLE_ENDIAN )
    {
        for(unsigned int i = 0; i < commandSize; i++)
        {
            QString byteVal = QString::number( (unsigned int)command[i+1],16 );
            if( byteVal.length() == 1 )
            {
                byteVal = "0"+ byteVal;
            }
            value += byteVal;
        }
    }
    else
    {
        for(unsigned int i = 0; i < commandSize; i++)
        {
            QString byteVal = QString::number( (unsigned int)command[commandSize-i],16 );
            if( byteVal.length() == 1 )
            {
                byteVal = "0"+ byteVal;
            }
            value += byteVal;
        }
    }
    itsMainWindow->setCurrentAttributeWaitingForValueFromParser(value);
    itsRemoteControll->setAttributValueForAttributRequest( value );
    //#]
}

void SingleParser::commandObjectCreated(unsigned char* command)
{
    //#[ operation commandObjectCreated(unsigned char*)
    uint classId = command[1] + (command[2] << 8);
    uint64_t addressInstanceCreated = readAddress( command, 3 );
    ModelInstance *instance = NULL;
    uint64_t attributeStartAddress = readAddress( command, 3 + itsTargetInformation->getPointerSize() );
    instance = itsTargetInformation->searchTargetClassAndCreateObject( classId, addressInstanceCreated, attributeStartAddress );
    if( processConstructorCalls )
    {
        itsReceivedCommandsLogger->newObjectCreated( instance, itsTargetInformation );
    }
    
    //#]
}

void SingleParser::commandObjectDestroyed(unsigned char* command)
{
    //#[ operation commandObjectDestroyed(unsigned char*)
    uint64_t addressInstanceDestroyed = readAddress( command, 1 );
    ModelInstance *instance = itsTargetInformation->getInstance( addressInstanceDestroyed );
    if( processDestructorCalls )
    {
        itsReceivedCommandsLogger->objectDestoyed( instance, itsTargetInformation );
    }
    //#]
}

void SingleParser::commandObjectStateRequest(unsigned char* command)
{
    //#[ operation commandObjectStateRequest(unsigned char*)
    QStandardItem *myItem = itsMainWindow->getCurrentInstanceItemWaitingForState();
    if( myItem != NULL )
    {
        ModelInstance* instance = itsMainWindow->getCurrentModelInstanceWaitingForState();
        unsigned int parallelStates = instance->getItsModelClass()->getParrallelStateCount();
        if( parallelStates > parallelStateCount )
        {
            parallelStates = parallelStateCount;
        }
        for( unsigned int i = 0; i < parallelStates; i++)
        {
            uint stateId = readState(command, 1U + itsTargetInformation->getStateSize() * i );
            if( myItem->child(i) != NULL)
            {
                myItem->child(i)->setText( instance->getItsModelClass()->getState( stateId ) );
            }
        }
    
        itsMainWindow->setCurrentInstanceItemWaitingForState( NULL );
        itsMainWindow->setCurrentModelInstanceWaitingForState( NULL );
    }
    ModelInstance* instance = itsRemoteControll->getCurrentModelInstanceWaitingForState();
    if( instance != NULL )
    {
        unsigned int parallelStates = instance->getItsModelClass()->getParrallelStateCount();
        if( parallelStates > parallelStateCount )
        {
            parallelStates = parallelStateCount;
        }
        QString stateText = "";
        for( unsigned int i = 0; i < parallelStates; i++)
        {
            uint stateId = readState(command, 1U + itsTargetInformation->getStateSize() * i );
            if( i != 0 )
            {
                stateText += "|";
            }
            stateText += instance->getItsModelClass()->getState( stateId );
        }
        itsRemoteControll->setStateForStateRequest( stateText );
    }
    //#]
}

void SingleParser::commandOperationCalled(unsigned char* command)
{
    //#[ operation commandOperationCalled(unsigned char*)
    #if DEMO == 1
    anzEvents++;
    if((anzEvents-1)==DEMO_MAX_EVENTS){
        QString eval = "You have reached the limit of the demo version with " + QString::number(DEMO_MAX_EVENTS,10) + " events.";
        eval += "\nPlease close and restart the Embedded UML Target Debugger for further usage.";
        eval += "\nYou can contact Willert Software Tools.";
    
        //QMessageBox::information ( NULL, "Evaluation Version", eval, QMessageBox::Ok , 0, 0 );
        //target->mw->sendToConsole(eval);
        emit newErrorMsg(eval);
        target->mw->getUI()->menuRecent_opend_files->setEnabled(false);
        target->mw->getUI()->actionOpen_XML_file->setEnabled(false);
        target->mw->getUI()->actionSelectComPlugin->setEnabled(false);
        break;
    
    }
    if(anzEvents>DEMO_MAX_EVENTS){
        break ;
    }
    #endif
    uint64_t source = readAddress( command, 1 );
    uint64_t destination = readAddress( command, itsTargetInformation->getPointerSize() + 1 );
    uint id = read2Byte( command, itsTargetInformation->getPointerSize() * 2 + 1 );
    uint ticks = command[ itsTargetInformation->getPointerSize() * 2 + 3 ] + itsTargetInformation->getTimeOffset();
    
    
    ModelEventType *eventType = itsTargetInformation->getEventType( id );
    
    int memCounter=0;
    ModelInstance* destinationInstance = itsTargetInformation->getInstance( destination );
    ModelInstance* sourceInstance = itsTargetInformation->getInstance( source );
    
    CommandOperationCall *newOperation = new CommandOperationCall( ticks, sourceInstance, eventType, destinationInstance, itsTargetInformation );
    
    
    for( auto myEventArgument : eventType->getArguments() )
    {
        int parameterSize = myEventArgument->getType()->getSize();
        if( parameterSize == 0 )
        {
            newOperation->addItsReceivedEventParameter( &brokenReceivedEventParameter );
            break;
        }
        if((parameterSize > 0 && memCounter % parameterSize != 0) || ( memCounter % 4 ) != 0)
        {
            memCounter += parameterSize - (memCounter % parameterSize);
        }
        QString value = "0x";
        if(itsTargetInformation->getEndianess() == LITTLE_ENDIAN )
        {
            for(int i = 0; i < parameterSize; i++)
            {
               value+= QString::number( (unsigned int)(unsigned char)command[ ( itsTargetInformation->getPointerSize() * 2 ) + 4 + memCounter + i ],16);
            }
        }
        else
        {
            for(int i = parameterSize-1; i >= 0; i--)
            {
               value+= QString::number( (unsigned int)(unsigned char)command[ ( itsTargetInformation->getPointerSize() * 2 ) + 4 + memCounter + i ],16);
            }
        }
    
        newOperation->addItsReceivedEventParameter( new ReceivedEventParameter(myEventArgument, value) );
    
        memCounter += parameterSize;
    }
    
    itsReceivedCommandsLogger->addCommandToActiveList( newOperation );
    
    
    
    //#]
}

void SingleParser::commandStateSizeInformation(unsigned char* command)
{
    //#[ operation commandStateSizeInformation(unsigned char*)
    
    parallelStateCount = command[1];
    stateSize = command[2];
    
    if( parallelStateCount > 20 )
    {
        parallelStateCount = 4;
    }
    if( stateSize > 2 )
    {
        stateSize = 1;
    }
    itsTargetInformation->setParallelStateCount(parallelStateCount);
    itsTargetInformation->setStateSize(stateSize);
    
    updateCommands();
    //#]
}

void SingleParser::commandSyncTime(unsigned char* command)
{
    //#[ operation commandSyncTime(unsigned char*)
    uint offset = read4Byte( command, 1);
    itsTargetInformation->setTimeOffset( offset & 0xFFFFFF00 );
    //#]
}

void SingleParser::commandTargetMessage(unsigned char* command, unsigned int commandSize)
{
    //#[ operation commandTargetMessage(unsigned char*,unsigned int)
    QByteArray *dataBytes = new QByteArray((char*)&command[1], commandSize);
    QString data(*dataBytes);
    itsMainWindow->targetConsoleMsg( data );
    //#]
}

void SingleParser::commandTimeOutEvent(unsigned char* command)
{
    //#[ operation commandTimeOutEvent(unsigned char*)
    #if DEMO == 1
    anzEvents++;
    if((anzEvents-1)==DEMO_MAX_EVENTS){
        QString eval = "You have reached the limit of the demo version with " + QString::number(DEMO_MAX_EVENTS,10) + " events.";
        eval += "\nPlease close and restart the Embedded UML Target Debugger for further usage.";
        eval += "\nYou can contact Willert Software Tools.";
    
        //QMessageBox::information ( NULL, "Evaluation Version", eval, QMessageBox::Ok , 0, 0 );
        //target->mw->sendToConsole(eval);
        emit newErrorMsg(eval);
        target->mw->getUI()->menuRecent_opend_files->setEnabled(false);
        target->mw->getUI()->actionOpen_XML_file->setEnabled(false);
        target->mw->getUI()->actionSelectComPlugin->setEnabled(false);
        break;
    
    }
    if(anzEvents>DEMO_MAX_EVENTS){
        break ;
    }
    #endif
    
    uint64_t destination = readAddress( command, 1 );
    uint eventID = read2Byte (command, itsTargetInformation->getPointerSize() + 1);
    uint ticks =  command[ itsTargetInformation->getPointerSize() + 3 ] + itsTargetInformation->getTimeOffset();
    
    ModelInstance* destinationInstance = itsTargetInformation->getInstance(destination);
    
    CommandEventCreated *newEvent = new CommandEventCreated(eventID, ticks, destinationInstance, itsTargetInformation->getTimeOutEvent(),destinationInstance, itsTargetInformation );
    temporaryEventList.push_back( newEvent );
    itsReceivedCommandsLogger->addCommandToActiveList( newEvent );
    //#]
}

void SingleParser::commandTimeOutTrace(unsigned char* command)
{
    //#[ operation commandTimeOutTrace(unsigned char*)
    #if DEMO == 1
    anzEvents++;
    if((anzEvents-1)==DEMO_MAX_EVENTS){
        QString eval = "You have reached the limit of the demo version with " + QString::number(DEMO_MAX_EVENTS,10) + " events.";
        eval += "\nPlease close and restart the Embedded UML Target Debugger for further usage.";
        eval += "\nYou can contact Willert Software Tools.";
    
        //QMessageBox::information ( NULL, "Evaluation Version", eval, QMessageBox::Ok , 0, 0 );
        //target->mw->sendToConsole(eval);
        emit newErrorMsg(eval);
        target->mw->getUI()->menuRecent_opend_files->setEnabled(false);
        target->mw->getUI()->actionOpen_XML_file->setEnabled(false);
        target->mw->getUI()->actionSelectComPlugin->setEnabled(false);
        break;
    
    }
    if(anzEvents>DEMO_MAX_EVENTS){
        break ;
    }
    #endif
    
    uint64_t destination = readAddress( command, 1 );
    uint ticks =  command[ 1 + itsTargetInformation->getPointerSize() ] + itsTargetInformation->getTimeOffset();
    
    ModelInstance* destinationInstance = itsTargetInformation->getInstance(destination);
    QString currentStateNames = this->readStateNames(command + 1 + itsTargetInformation->getPointerSize() + 1, destinationInstance);
    
    CommandTraceEvent *newEvent = new CommandTraceEvent(ticks, destinationInstance, destinationInstance, itsTargetInformation->getTimeOutEvent(), currentStateNames, itsTargetInformation );
    itsReceivedCommandsLogger->addCommandToActiveList( newEvent );
    
    //#]
}

void SingleParser::commandTimeReset(unsigned char* command)
{
    //#[ operation commandTimeReset(unsigned char*)
    command = command;
    itsTargetInformation->setInReset( false );
    //#]
}

void SingleParser::commandTraceEvent(unsigned char* command)
{
    //#[ operation commandTraceEvent(unsigned char*)
    #if DEMO == 1
    anzEvents++;
    if((anzEvents-1)==DEMO_MAX_EVENTS){
        QString eval = "You have reached the limit of the demo version with " + QString::number(DEMO_MAX_EVENTS,10) + " events.";
        eval += "\nPlease close and restart the Embedded UML Target Debugger for further usage.";
        eval += "\nYou can contact Willert Software Tools.";
    
        //QMessageBox::information ( NULL, "Evaluation Version", eval, QMessageBox::Ok , 0, 0 );
        //target->mw->sendToConsole(eval);
        emit newErrorMsg(eval);
        target->mw->getUI()->menuRecent_opend_files->setEnabled(false);
        target->mw->getUI()->actionOpen_XML_file->setEnabled(false);
        target->mw->getUI()->actionSelectComPlugin->setEnabled(false);
        break;
    
    }
    if(anzEvents>DEMO_MAX_EVENTS){
        break ;
    }
    #endif
    
    uint64_t source = readAddress( command, 1 );
    uint64_t destination = readAddress( command, 1 + itsTargetInformation->getPointerSize() );
    uint id = read2Byte ( command, 1 + itsTargetInformation->getPointerSize()*2 );
    uint ticks =  command[ 1 + itsTargetInformation->getPointerSize()*2 + 2 ] + itsTargetInformation->getTimeOffset();
    
    ModelInstance* sourceInstance = itsTargetInformation->getInstance(source);
    ModelInstance* destinationInstance = itsTargetInformation->getInstance(destination);
    ModelEventType *eventType = itsTargetInformation->getEventType( id );
    QString currentStateNames = this->readStateNames(command + 1 + itsTargetInformation->getPointerSize()*2 + 2 + 1, destinationInstance);
    QList<ReceivedEventParameter*> receivedEventParameters = this->readReceivedEventParameters(command, 1 + itsTargetInformation->getPointerSize()*2 + 2 + 1 + (itsTargetInformation->getParallelStateCount()*itsTargetInformation->getStateSize()), *eventType);
    
    CommandTraceEvent *newEvent = new CommandTraceEvent(ticks, sourceInstance, destinationInstance, eventType, currentStateNames, itsTargetInformation );
    for(auto receivedEventParam : receivedEventParameters)
    {
        newEvent->addItsReceivedEventParameter(receivedEventParam);
    }
    
    itsReceivedCommandsLogger->addCommandToActiveList( newEvent );
    //#]
}

void SingleParser::commandTypeSizes(unsigned char* command)
{
    //#[ operation commandTypeSizes(unsigned char*)
    uint size = read2Byte(command,1);
    TargetInformation::ReceiveTypePosition position = itsTargetInformation->updateTypeSize( size );
    if( position == TargetInformation::First )
    {
        updateCommands();
    }
    if( position == TargetInformation::Last )
    {
        itsTargetInformation->updateClassAttributes();
    }
    //#]
}

CommandEventTripletData* SingleParser::findPreviousEvent(unsigned int eventID, Command::commandType eventType)
{
    //#[ operation findPreviousEvent(unsigned int,commandType)
    for( int i = 0; i < temporaryEventList.size(); i++ )
    {
        if( temporaryEventList.at(i)->getEventID() == eventID && temporaryEventList.at(i)->getCommandIdentifier() == eventType)
        {
            CommandEventTripletData* returnVal = temporaryEventList.at(i);
            temporaryEventList.removeAt(i);
            return returnVal;
        }
    }
    return NULL;
    //#]
}

unsigned int SingleParser::read2Byte(unsigned char* data, int startPointer)
{
    //#[ operation read2Byte(unsigned char*,int)
    int value = 0;
    
    if ( itsTargetInformation->getEndianess() == LITTLE_ENDIAN )
    {
        for ( int i = 0; i < 2; i++ )
        {
            value |= ( data[ i + startPointer ] << ( 8 * i ) );
        }
    }
    else
    {
        for ( int i = 0; i < 2; i++ )
        {
            value |= ( data[ i + startPointer ] << ( 8 * (2 - i - 1) ) );
        }
    }
    return value;
    //#]
}

unsigned int SingleParser::read4Byte(unsigned char* data, int startPointer)
{
    //#[ operation read4Byte(unsigned char*,int)
    int value = 0;
    
    if ( itsTargetInformation->getEndianess() == LITTLE_ENDIAN )
    {
        for ( int i = 0; i < 4; i++ )
        {
            value |= ( data[ i + startPointer ] << ( 8 * i ) );
        }
    }
    else
    {
        for ( int i = 0; i < 4; i++ )
        {
            value |= ( data[ i + startPointer ] << ( 8 * (4 - i - 1) ) );
        }
    }
    return value;
    //#]
}

uint64_t SingleParser::readAddress(unsigned char* data, int startPointer)
{
    //#[ operation readAddress(unsigned char*,int)
    uint64_t address;
    unsigned int ptrSize = itsTargetInformation->getPointerSize();
    if ( itsTargetInformation->getEndianess() == LITTLE_ENDIAN )
    {
        address = 0;
        for(unsigned int i = 0; i < ptrSize;i++)
        {
            address |= ((uint64_t)data[ startPointer + i ]) << (8 * i);
        }
    }
    else
    {
        address = 0;
        for( unsigned int i = 0; i < ptrSize; i++ )
        {
            address |= ((uint64_t)data[ startPointer + i ]) << (8 * ( ptrSize - i - 1 ) );
        }
    }
    return address;
    //#]
}

QList<ReceivedEventParameter*> SingleParser::readReceivedEventParameters(unsigned char* data, int startOffset, const ModelEventType& eventType, const TargetInformation& myTarget)
{
    //#[ operation readReceivedEventParameters(unsigned char,int,ModelEventType,TargetInformation)
    int memCounter=0;
    QList<ReceivedEventParameter*> receivedEventParameters;
    
    for( auto myEventArgument : eventType.getArguments() )
    {
        int parameterSize = myEventArgument->getType()->getSize();
        if( parameterSize == 0 )
        {
            receivedEventParameters.append( &brokenReceivedEventParameter );
            break;
        }
        if((parameterSize > 0 && memCounter % parameterSize != 0) || ( memCounter % 4 ) != 0)
        {
            memCounter += parameterSize - (memCounter % parameterSize);
        }
        QString value = "0x";
        if( myTarget.getEndianess() != LITTLE_ENDIAN )
        {
            for(int i = 0; i < parameterSize; i++)
            {
                QString byteValue = QString::number( (unsigned int)(unsigned char)data[ startOffset + memCounter + i ],16);
                if(byteValue.length() == 2)
                {
                    value+=byteValue;
                }
                else
                {
                    value+="0"+byteValue;
                }
            }
        }
        else
        {
            for(int i = parameterSize-1; i >= 0; i--)
            {
               QString byteValue = QString::number( (unsigned int)(unsigned char)data[ startOffset + memCounter + i ],16);
               if(byteValue.length() == 2)
               {
                   value+=byteValue;
               }
               else
               {
                   value+="0"+byteValue;
               }
            }
        }
    
        receivedEventParameters.append( new ReceivedEventParameter(myEventArgument, value) );
    
        memCounter += parameterSize;
    }
    
    return receivedEventParameters; // return copy of local list
    //#]
}

unsigned int SingleParser::readState(unsigned char* data, unsigned int position, const TargetInformation& target)
{
    //#[ operation readState(unsigned char*,unsigned int,TargetInformation)
    uint stateID = 0;
    if ( target.getEndianess() == LITTLE_ENDIAN )
    {
        for ( int i = 0; i < target.getStateSize(); i++ )
        {
            stateID |= ( data[ i + position ] << ( 8 * i ) );
        }
    }
    else
    {
        for ( int i = 0; i < target.getStateSize(); i++ )
        {
            stateID |= ( data[ i + position ] << ( 8 * ( target.getStateSize() - i - 1 ) ) );
        }
    }
    return stateID;
    //#]
}

void SingleParser::updateCommands()
{
    //#[ operation updateCommands()
    
    commands[0] = eventPutToMessageQueue;
    commandsSize[0] = 255;
    commandsMinimalSize[0] = 9;
    
    //Timeout Event
    commands[1] = timeOutEventStart;
    commandsSize[1] = itsTargetInformation->getPointerSize() +3U;
    
    commands[2] = eventStartDispatch;
    commandsSize[2] = 3U;
    
    commands[3] = eventEndDispatch;
    commandsSize[3] = 2 + ( parallelStateCount * stateSize ) ;
    
    //operation called
    commands[4] = operationCalled;
    commandsSize[4] = 255;
    commandsMinimalSize[4] = itsTargetInformation->getPointerSize() * 2 + 2;
    
    commands[5] = objectCreated;
    commandsSize[5] = itsTargetInformation->getPointerSize() * 2 + 2U;
    
    //destroy Object
    commands[6] = objectDestroyed;
    commandsSize[6] = itsTargetInformation->getPointerSize();
    
    //send Attribute
    commands[7] = objectAttributRequest;
    commandsSize[7] = 255;
    commandsMinimalSize[7] = 1;
    
    //send State
    commands[8] = objectStateRequest;
    commandsSize[8] = ( parallelStateCount * stateSize );
    
    //send Error
    commands[9] = errorHandlerReached;
    commandsSize[9] = 0;
    
    //receive version
    commands[10] = versionNumber;
    commandsSize[10] = 5;
    
    //buffer overflow
    commands[11] = bufferOverflow;
    commandsSize[11] = 0;
    
    //FSM Size
    commands[12] = stateSizeInformation;
    commandsSize[12] = 2;
    
    //typeSize Init
    commands[13] = typeSizes;
    commandsSize[13] = 255;
    commandsMinimalSize[13] = 0;
    
    //traceEvent Init
    commands[14] = eventTrace;
    commandsSize[14] = UCHAR_MAX;
    // 2x pointer (source, target), 2-byte (id), 1-byte (time), states
    commandsMinimalSize[14] = 2 * itsTargetInformation->getPointerSize() + 2 + 1 + ( parallelStateCount * stateSize );
    
    //time Offset Synchronisation
    commands[15] = timeOffset;
    commandsSize[15] = 4;  
    
    //integer Debug Value
    commands[16] = intValue;
    commandsSize[16] = itsTargetInformation->getPointerSize() + 4;        
    
    //TimeReset
    commands[17] = timeReset;
    commandsSize[17] = 0;
    
    //trace Timeout
    commands[18] = traceTimeout;
    // 1x pointer (destination), 1-byte (time), states
    commandsSize[18] = itsTargetInformation->getPointerSize() + 1 + ( parallelStateCount * stateSize );
    
    //targetConsole
    commands[19] = targetConsoleMessage;
    commandsSize[19] = 255;
    
    //#]
}

QString SingleParser::readStateNames(unsigned char* command, const ModelInstance* destinationInstance, const TargetInformation& myTarget)
{
    //#[ operation readStateNames(unsigned char,ModelInstance,TargetInformation)
    QString currentStateNames = "";
    uint fsmParallelStateCount;
        
    fsmParallelStateCount = destinationInstance->getItsModelClass()->getParrallelStateCount();
        
    if( fsmParallelStateCount > myTarget.getParallelStateCount() )
    {
        fsmParallelStateCount = myTarget.getParallelStateCount();
    }
        
    for( unsigned int i = 0; i < fsmParallelStateCount; i++){
        int stateNr = readState( command, ( i * myTarget.getStateSize() ), myTarget );
        currentStateNames += destinationInstance->getItsModelClass()->getState( stateNr );
        if( ( i + 1U ) < fsmParallelStateCount )
        {
        	currentStateNames+="|";
        }
    }
    
    return currentStateNames;
    //#]
}

void SingleParser::initRelations()
{
    brokenReceivedEventParameter.setItsModelEventArgumentType(&itsModelEventArgumentType);
}

void SingleParser::cleanUpRelations()
{
    if(itsRemoteControll != NULL)
        {
            itsRemoteControll = NULL;
        }
}

TargetInformation* SingleParser::itsTargetInformation = NULL;

/*********************************************************************
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\SingleParser.cpp
*********************************************************************/
