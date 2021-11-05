/********************************************************************
	Rhapsody	: 9.0.1 
	Login		: Y9DSYU706
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: MultiParser
//!	Generated Date	: Thu, 4, Nov 2021  
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\MultiParser.cpp
*********************************************************************/

#include "MultiParser.h"
#include "CommandConstructor.h"
#include "CommandDestructor.h"
#include "CommandEventCreated.h"
#include "CommandEventEndDispatch.h"
#include "CommandEventStartDispatch.h"
#include "CommandIntVal.h"
#include "CommandOperationCall.h"
#include "CommandTraceEvent.h"
#include "MainWindow.h"
#include "ModelEventArgumentType.h"
#include "ModelInstance.h"
#include "ReceivedCommandsLogger.h"
#include "TargetInformation.h"
#include "TargetList.h"
//## package LogicLevel::DataTransmission::DataParser

//## class MultiParser
MultiParser::MultiParser()
{
    //#[ operation MultiParser()
    //#]
}

MultiParser::~MultiParser()
{
}

bool MultiParser::checkCommandStart(unsigned char size, char command)
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

void MultiParser::commandBufferOverflow(unsigned char* command)
{
    //#[ operation commandBufferOverflow(unsigned char*)
    uint targetId = command[1];
    
    TargetInformation *myTarget = TargetList::getGlobalList()->getTarget( targetId );
    if( myTarget == NULL )
    {
        itsReceivedCommandsLogger->unknownTarget( "Buffer Overflow",targetId );
        return;
    }
    itsReceivedCommandsLogger->bufferOverflow( myTarget );
    //#]
}

void MultiParser::commandErrorHandlerReached(unsigned char* command)
{
    //#[ operation commandErrorHandlerReached(unsigned char*)
    uint targetId = command[1];
    
    TargetInformation *myTarget = TargetList::getGlobalList()->getTarget( targetId );
    if( myTarget == NULL )
    {
        itsReceivedCommandsLogger->unknownTarget( "Error Handler Reached",targetId );
        return;
    }
    itsReceivedCommandsLogger->errorHandlerReached( myTarget );
    //#]
}

void MultiParser::commandEventEndDispatch(unsigned char* command)
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
    
    uint targetId = command[1];
    
    TargetInformation *myTarget = TargetList::getGlobalList()->getTarget( targetId );
    if( myTarget == NULL )
    {
        itsReceivedCommandsLogger->unknownTarget( "Event End",targetId );
        return;
    }
    uint eventID = read2Byte (command, 2, myTarget ) + ( targetId << 16 );
    CommandEventStartDispatch *prevStartEvent = (CommandEventStartDispatch*)findPreviousEvent( eventID, Command::eventStartDispatchCommand );
    
    
    if( prevStartEvent != NULL )
    {    
        CommandEventCreated* createEvent = prevStartEvent->getItsCommandEventCreated();
        ModelInstance* destinationInstance = createEvent->getDestinationInstance();
    
        QString currentStateNames = this->readStateNames(( command + 2 + 2 ), destinationInstance, *myTarget);
    
        CommandEventEndDispatch *newEvent = new CommandEventEndDispatch( eventID, prevStartEvent, currentStateNames, myTarget );
        prevStartEvent->setItsCommandEventEndDispatch( newEvent );
        itsReceivedCommandsLogger->addCommandToActiveList( newEvent );
    
    }
    else
    {
        itsReceivedCommandsLogger->unrecognizedEvent( eventID, Command::eventEndDispatchCommand );
    }
    //#]
}

void MultiParser::commandEventPutToMessageQueue(unsigned char* command)
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
    
    uint targetId = command[ 1 ];
    TargetInformation *myTarget = TargetList::getGlobalList()->getTarget( targetId );
    if( myTarget == NULL )
    {
        itsReceivedCommandsLogger->unknownTarget( "Event Created", targetId );
        return;
    }
    
    uint64_t source = readAddress( command, 2, myTarget );
    uint64_t destination = readAddress( command, myTarget->getPointerSize() + 2, myTarget );
    uint eventID = read2Byte (command, myTarget->getPointerSize() * 2 + 2, myTarget);
    uint id = read2Byte( command, myTarget->getPointerSize() * 2 + 4, myTarget );
    uint ticks = command[ myTarget->getPointerSize() * 2 + 6 ] + myTarget->getTimeOffset();
    
    
    ModelEventType *eventType = myTarget->getEventType( id );
    
    ModelInstance* sourceInstance = myTarget->getInstance( source );
    
    ModelInstance* destinationInstance = myTarget->getInstance( destination );
    
    CommandEventCreated *newEvent = new CommandEventCreated( eventID + ( targetId << 16 ), ticks, sourceInstance, eventType, destinationInstance, myTarget );
    
    
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
        if( myTarget->getEndianess() != LITTLE_ENDIAN )
        {
            for(int i = 0; i < parameterSize; i++)
            {
                QString byteValue = QString::number( (unsigned int)(unsigned char)command[ ( myTarget->getPointerSize() * 2 ) + 7 + memCounter + i ],16);
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
               QString byteValue = QString::number( (unsigned int)(unsigned char)command[ ( myTarget->getPointerSize() * 2 ) + 7 + memCounter + i ],16);
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

void MultiParser::commandEventStartDispatch(unsigned char* command)
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
    
    uint targetId = command[ 1 ];
    TargetInformation *myTarget = TargetList::getGlobalList()->getTarget( targetId );
    if( myTarget == NULL )
    {
        itsReceivedCommandsLogger->unknownTarget( "Event Start", targetId );
        return;
    }
    
    uint eventID = read2Byte (command, 2, myTarget) + ( targetId << 16 );
    uint ticks = command[ 4 ] + myTarget->getTimeOffset();
    
    CommandEventCreated *prevCreateEvent = (CommandEventCreated*)findPreviousEvent( eventID, Command::eventPutToMessageQueueCommand );
    
    if( prevCreateEvent != NULL )
    {
        CommandEventStartDispatch *newEvent = new CommandEventStartDispatch( eventID , ticks, prevCreateEvent, myTarget );
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

void MultiParser::commandIntVal(unsigned char* command)
{
    //#[ operation commandIntVal(unsigned char*)
    uint targetId = command[ 1 ];
    TargetInformation *myTarget = TargetList::getGlobalList()->getTarget( targetId );
    if( myTarget == NULL )
    {
        itsReceivedCommandsLogger->unknownTarget( "IntValue", targetId );
        return;
    }
    uint64_t instanceAddress = readAddress( command, 2,myTarget );
    uint intVal = read4Byte( command, 2 + myTarget->getPointerSize(), myTarget );
    ModelInstance *myInstance = myTarget->getInstance( instanceAddress );
    CommandIntVal *myCommandIntVal = new CommandIntVal( myTarget, intVal, myInstance);
    itsReceivedCommandsLogger->addCommandToActiveList( myCommandIntVal );
    //#]
}

void MultiParser::commandNewVersion(unsigned char* command)
{
    //#[ operation commandNewVersion(unsigned char*)
    uint targetId = command[ 5 ];
    TargetInformation *myTarget = TargetList::getGlobalList()->getTarget( targetId );
    if( myTarget == NULL )
    {
        itsReceivedCommandsLogger->unknownTarget( "Send Version", targetId );
        return;
    }
    myTarget->setIncommingTypeNr( 0 );
    itsMainWindow->removeTarget( *myTarget );
    for( auto aModelClass : myTarget->getModelClassList() )
    {
        aModelClass->resetInstanceCount();
        aModelClass->resetAttributeOffset();
    }
    itsReceivedCommandsLogger->newDataSet( false );
    //#]
}

void MultiParser::commandObjectAttributRequest(unsigned char* command, unsigned int commandSize)
{
    //#[ operation commandObjectAttributRequest(unsigned char*,unsigned int)
    
    uint targetId = command[ 1 ];
    TargetInformation *myTarget = TargetList::getGlobalList()->getTarget( targetId );
    if( myTarget == NULL )
    {
        itsReceivedCommandsLogger->unknownTarget( "Request Attribut", targetId );
        return;
    }
    
    if( commandSize > 60 )
    {
        commandSize = 4;
    }
    QString value= "0x";
    if(myTarget->getEndianess() != LITTLE_ENDIAN )
    {
        for(unsigned int i = 0; i < commandSize; i++)
        {
            QString byteVal = QString::number( (unsigned int)command[i+2],16 );
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
            QString byteVal = QString::number( (unsigned int)command[commandSize-( i - 1)],16 );
            if( byteVal.length() == 1 )
            {
                byteVal = "0"+ byteVal;
            }
            value += byteVal;
        }
    }
    itsMainWindow->setCurrentAttributeWaitingForValueFromParser( value );
    //#]
}

void MultiParser::commandObjectCreated(unsigned char* command)
{
    //#[ operation commandObjectCreated(unsigned char*)
    uint targetId = command[ 1 ];
    TargetInformation *myTarget = TargetList::getGlobalList()->getTarget( targetId );
    if( myTarget == NULL )
    {
        itsReceivedCommandsLogger->unknownTarget( "Object Created", targetId );
        return;
    }
    uint classId = command[2] + (command[3] << 8);
    uint64_t addressInstanceCreated = readAddress( command, 4, myTarget );
    ModelInstance *instance = NULL;
    uint64_t attributeStartAddress = readAddress( command, 4 + myTarget->getPointerSize(), myTarget );
    instance = myTarget->searchTargetClassAndCreateObject( classId, addressInstanceCreated, attributeStartAddress );
    if( processConstructorCalls )
    {
        itsReceivedCommandsLogger->newObjectCreated( instance, myTarget );
    }
    
    //#]
}

void MultiParser::commandObjectDestroyed(unsigned char* command)
{
    //#[ operation commandObjectDestroyed(unsigned char*)
    uint targetId = command[ 1 ];
    TargetInformation *myTarget = TargetList::getGlobalList()->getTarget( targetId );
    if( myTarget == NULL )
    {
        itsReceivedCommandsLogger->unknownTarget( "Object Destroyed", targetId );
        return;
    }
    uint64_t addressInstanceDestroyed = readAddress( command, 2, myTarget );
    ModelInstance *instance = myTarget->getInstance( addressInstanceDestroyed );
    if( processDestructorCalls )
    {
        itsReceivedCommandsLogger->objectDestoyed( instance, myTarget );
    }
    //#]
}

void MultiParser::commandObjectStateRequest(unsigned char* command)
{
    //#[ operation commandObjectStateRequest(unsigned char*)
    uint targetId = command[ 1 ];
    TargetInformation *myTarget = TargetList::getGlobalList()->getTarget( targetId );
    if( myTarget == NULL )
    {
        itsReceivedCommandsLogger->unknownTarget( "Object Destroyed", targetId );
        return;
    }
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
            uint stateId = readState(command, 2U + myTarget->getStateSize() * i, *myTarget );
    
            if( myItem->child(i) != NULL)
            {
                myItem->child(i)->setText( instance->getItsModelClass()->getState( stateId ) );
    
            }
        }
        itsMainWindow->setCurrentInstanceItemWaitingForState( NULL );
        itsMainWindow->setCurrentModelInstanceWaitingForState( NULL );
    }
    //#]
}

void MultiParser::commandOperationCalled(unsigned char* command)
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
    
    uint targetId = command[ 1 ];
    TargetInformation *myTarget = TargetList::getGlobalList()->getTarget( targetId );
    if( myTarget == NULL )
    {
        itsReceivedCommandsLogger->unknownTarget( "Operation Called", targetId );
        return;
    }
    
    uint64_t source = readAddress( command, 2, myTarget );
    uint64_t destination = readAddress( command, myTarget->getPointerSize() + 2, myTarget );
    uint id = read2Byte( command, myTarget->getPointerSize() * 2 + 2, myTarget );
    uint ticks = command[ myTarget->getPointerSize() * 2 + 4 ] + myTarget->getTimeOffset();
    
    
    ModelEventType *eventType = myTarget->getEventType( id );
    
    int memCounter=0;
    ModelInstance* destinationInstance = myTarget->getInstance( destination );
    ModelInstance* sourceInstance = myTarget->getInstance( source );
    
    CommandOperationCall *newOperation = new CommandOperationCall( ticks, sourceInstance, eventType, destinationInstance, myTarget );
    
    
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
        if( myTarget->getEndianess() == LITTLE_ENDIAN )
        {
            for(int i = 0; i < parameterSize; i++)
            {
               value+= QString::number( (unsigned int)(unsigned char)command[ ( myTarget->getPointerSize() * 2 ) + 5 + memCounter + i ],16);
            }
        }
        else
        {
            for(int i = parameterSize-1; i >= 0; i--)
            {
               value+= QString::number( (unsigned int)(unsigned char)command[ ( myTarget->getPointerSize() * 2 ) + 5 + memCounter + i ],16);
            }
        }
    
        newOperation->addItsReceivedEventParameter( new ReceivedEventParameter(myEventArgument, value) );
    
        memCounter += parameterSize;
    }
    
    itsReceivedCommandsLogger->addCommandToActiveList( newOperation );
    
    //#]
}

void MultiParser::commandStateSizeInformation(unsigned char* command)
{
    //#[ operation commandStateSizeInformation(unsigned char*)
    
    uint targetId = command[ 1 ];
    TargetInformation *myTarget = TargetList::getGlobalList()->getTarget( targetId );
    if( myTarget == NULL )
    {
        itsReceivedCommandsLogger->unknownTarget( "State Size Information", targetId );
        return;
    }
    
    if( command[2] > 20 )
    {
        myTarget->setParallelStateCount( 4 );
    }
    else
    {
        myTarget->setParallelStateCount( command[2] );
    }
    if( command[3] > 2 )
    {
        myTarget->setStateSize( 1 );
    }
    else
    {
        myTarget->setStateSize( command[3] );
    }
    
    updateCommands( myTarget );
    //#]
}

void MultiParser::commandSyncTime(unsigned char* command)
{
    //#[ operation commandSyncTime(unsigned char*)
    uint targetId = command[ 1 ];
    TargetInformation *myTarget = TargetList::getGlobalList()->getTarget( targetId );
    if( myTarget == NULL )
    {
        itsReceivedCommandsLogger->unknownTarget( "Time Offset", targetId );
        return;
    }
    uint offset = read4Byte( command, 2, myTarget);
    myTarget->setTimeOffset( offset & 0xFFFFFF00 );
    //#]
}

void MultiParser::commandTimeOutEvent(unsigned char* command)
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
    
    uint targetId = command[ 1 ];
    TargetInformation *myTarget = TargetList::getGlobalList()->getTarget( targetId );
    if( myTarget == NULL )
    {
        itsReceivedCommandsLogger->unknownTarget( "Timeout Occurred", targetId );
        return;
    }
    
    uint64_t destination = readAddress( command, 2, myTarget );
    uint eventID = read2Byte (command, myTarget->getPointerSize() + 2, myTarget) + ( targetId << 16 );
    uint ticks =  command[ myTarget->getPointerSize() + 4 ] + myTarget->getTimeOffset();
    
    
    ModelInstance* destinationInstance = myTarget->getInstance(destination);
    
    CommandEventCreated *newEvent = new CommandEventCreated(eventID, ticks, destinationInstance, myTarget->getTimeOutEvent(),destinationInstance, myTarget );
    temporaryEventList.push_back( newEvent );
    itsReceivedCommandsLogger->addCommandToActiveList( newEvent );
    //#]
}

void MultiParser::commandTimeOutTrace(unsigned char* command)
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
    
    uint targetId = command[ 1 ];
    TargetInformation *myTarget = TargetList::getGlobalList()->getTarget( targetId );
    if( myTarget == NULL )
    {
        itsReceivedCommandsLogger->unknownTarget( "Timeout Occurred", targetId );
        return;
    }
    
    uint64_t destination = readAddress( command, 1 + 1, myTarget );
    uint ticks =  command[ 1 + 1 + myTarget->getPointerSize() ] + myTarget->getTimeOffset();
    
    ModelInstance* destinationInstance = myTarget->getInstance(destination);
    QString currentStateNames = this->readStateNames(command + 1 + 1 + myTarget->getPointerSize() + 1, destinationInstance, *myTarget);
    
    CommandTraceEvent *newEvent = new CommandTraceEvent(ticks, destinationInstance, destinationInstance, myTarget->getTimeOutEvent(), currentStateNames, myTarget );
    itsReceivedCommandsLogger->addCommandToActiveList( newEvent );
    //#]
}

void MultiParser::commandTimeReset(unsigned char* command)
{
    //#[ operation commandTimeReset(unsigned char*)
    uint targetId = command[ 1 ];
    TargetInformation *myTarget = TargetList::getGlobalList()->getTarget( targetId );
    if( myTarget == NULL )
    {
        itsReceivedCommandsLogger->unknownTarget( "TimeReset", targetId );
        return;
    }
    myTarget->setInReset( false );
    //#]
}

void MultiParser::commandTraceEvent(unsigned char* command)
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
    
    uint targetId = command[ 1 ];
    TargetInformation *myTarget = TargetList::getGlobalList()->getTarget( targetId );
    if( myTarget == NULL )
    {
        itsReceivedCommandsLogger->unknownTarget( "Timeout Occurred", targetId );
        return;
    }
    
    uint64_t source = readAddress( command, 1 + 1, myTarget );
    uint64_t destination = readAddress( command, 1 + 1 + myTarget->getPointerSize(), myTarget );
    uint id = read2Byte (command, 1 + 1 + myTarget->getPointerSize()*2, myTarget);
    uint ticks =  command[ 1 + 1 + myTarget->getPointerSize()*2 + 2 ] + myTarget->getTimeOffset();
    
    ModelInstance* sourceInstance = myTarget->getInstance(source);
    ModelInstance* destinationInstance = myTarget->getInstance(destination);
    ModelEventType *eventType = myTarget->getEventType( id );
    QString currentStateNames = this->readStateNames(command + 1 + 1 + myTarget->getPointerSize()*2 + 2 + 1, destinationInstance, *myTarget);
    QList<ReceivedEventParameter*> receivedEventParameters = this->readReceivedEventParameters(command,  1 + 1 + myTarget->getPointerSize()*2 + 2 + 1 + (myTarget->getParallelStateCount()*myTarget->getStateSize()), *eventType, *myTarget);
    
    CommandTraceEvent *newEvent = new CommandTraceEvent(ticks, sourceInstance, destinationInstance, eventType, currentStateNames, myTarget );
    for(auto receivedEventParam : receivedEventParameters)
    {
        newEvent->addItsReceivedEventParameter(receivedEventParam);
    }
    
    itsReceivedCommandsLogger->addCommandToActiveList( newEvent );
    //#]
}

void MultiParser::commandTypeSizes(unsigned char* command)
{
    //#[ operation commandTypeSizes(unsigned char*)
    uint size;
    
    uint targetId = command[ 1 ];
    TargetInformation *myTarget = TargetList::getGlobalList()->getTarget( targetId );
    if( myTarget == NULL )
    {
        itsReceivedCommandsLogger->unknownTarget( "TypeSizeInformation", targetId );
        return;
    }
    size = read2Byte(command,3 , myTarget);
    TargetInformation::ReceiveTypePosition position = myTarget->updateTypeSize( size );
    if( position == TargetInformation::First )
    {
        updateCommands( myTarget );
    }
    if( position == TargetInformation::Last )
    {
        myTarget->updateClassAttributes();
    }
    //#]
}

unsigned int MultiParser::read2Byte(unsigned char* data, int startPointer, TargetInformation* target)
{
    //#[ operation read2Byte(unsigned char*,int,TargetInformation)
    int value = 0;
    
    if ( target->getEndianess() == LITTLE_ENDIAN )
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

unsigned int MultiParser::read4Byte(unsigned char* data, int startPointer, TargetInformation* target)
{
    //#[ operation read4Byte(unsigned char*,int,TargetInformation)
    int value = 0;
    
    if ( target->getEndianess() == LITTLE_ENDIAN )
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

uint64_t MultiParser::readAddress(unsigned char* data, int startPointer, TargetInformation* target)
{
    //#[ operation readAddress(unsigned char*,int,TargetInformation)
    uint64_t address;
    unsigned int ptrSize = target->getPointerSize();
    if ( target->getEndianess() == LITTLE_ENDIAN )
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

void MultiParser::updateCommands(TargetInformation* target)
{
    //#[ operation updateCommands(TargetInformation)
    
    commands[0] = eventPutToMessageQueue;
    commandsSize[0] = 255;
    commandsMinimalSize[0] = target->getPointerSize() * 2 + 4;
    
    //Timeout Event
    commands[1] = timeOutEventStart;
    commandsSize[1] = target->getPointerSize() + 4;
    
    commands[2] = eventStartDispatch;
    commandsSize[2] = 4;
    
    commands[3] = eventEndDispatch;
    commandsSize[3] = 255 ;
    commandsMinimalSize[3] = 3;
    
    //operation called
    commands[4] = operationCalled;
    commandsSize[4] = 255;
    commandsMinimalSize[4] = target->getPointerSize() * 2 + 3;
    
    commands[5] = objectCreated;
    commandsSize[5] = target->getPointerSize() * 2 + 3U;
    
    //destroy Object
    commands[6] = objectDestroyed;
    commandsSize[6] = target->getPointerSize() + 1;
    
    //send Attribute
    commands[7] = objectAttributRequest;
    commandsSize[7] = 255;
    commandsMinimalSize[7] = 1;
    
    //send State
    commands[8] = objectStateRequest;
    commandsSize[8] = 255;
    commandsMinimalSize[8] = 1;
    
    //send Error
    commands[9] = errorHandlerReached;
    commandsSize[9] = 1;
    
    //receive version
    commands[10] = versionNumber;
    commandsSize[10] = 5;
    
    //buffer overflow
    commands[11] = bufferOverflow;
    commandsSize[11] = 1;
    
    //FSM Size
    commands[12] = stateSizeInformation;
    commandsSize[12] = 3;
    
    //typeSize Init
    commands[13] = typeSizes;
    commandsSize[13] = 255;
    commandsMinimalSize[13] = 3;
    
    //traceEvent Init
    commands[14] = eventTrace;
    commandsSize[14] = UCHAR_MAX;
    // 1x targetID, 2x pointer (source, destination), 2-byte (eventID), 1-byte (time), states
    commandsMinimalSize[14] = 1 + ( 2*target->getPointerSize() ) + 2 + 1 + ( parallelStateCount * stateSize );
    
    //time Offset Synchronisation
    commands[15] = timeOffset;
    commandsSize[15] = 5;   
    
    //Debug Integaer value
    commands[16] = intValue;
    commandsSize[16] = target->getPointerSize() + 5;
    
    //TimeReset
    commands[17] = timeReset;
    commandsSize[17] = 1;
    
    //trace Timeout
    commands[18] = traceTimeout;
    // 1x targetID, 1x pointer (destination), 1-byte (time), states
    commandsSize[18] = 1 + target->getPointerSize() + 1 + ( parallelStateCount * stateSize );
    
    //#]
}

/*********************************************************************
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\MultiParser.cpp
*********************************************************************/
