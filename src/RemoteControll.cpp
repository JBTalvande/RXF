/********************************************************************
	Rhapsody	: 9.0.1 
	Login		: Y9DSYU706
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: RemoteControll
//!	Generated Date	: Thu, 4, Nov 2021  
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\RemoteControll.cpp
*********************************************************************/

#include "RemoteControll.h"
#include "Command.h"
#include "CommandConstructor.h"
#include "CommandDestructor.h"
#include "CommandEventCreated.h"
#include "CommandEventEndDispatch.h"
#include "CommandEventStartDispatch.h"
#include "CommandIntVal.h"
#include "CommandList.h"
#include "CommandOperationCall.h"
#include "CommandTraceEvent.h"
#include "ConfigurationWindow.h"
#include "MainWindow.h"
#include "ModelEventType.h"
#include "Sender.h"
#include "SingleParser.h"
#include "TargetInformation.h"
//## package API

//## class RemoteControll
RemoteControll::RemoteControll() : attributValue(""), commandCounter(0), currentModelInstanceWaitingForAttribute(""), currentModelInstanceWaitingForState(NULL), running(true), stateValue(""), waitingSocket(NULL)
{
    activeCommandList = NULL;
    itsConfigurationWindow = NULL;
    itsMainWindow = NULL;
    itsQTcpServer = NULL;
    itsSender = NULL;
    //#[ operation RemoteControll()
    //#]
}

RemoteControll::~RemoteControll()
{
    //#[ operation ~RemoteControll()
    running = false;
    wait();
    //#]
    cleanUpRelations();
}

void RemoteControll::TCPIPConnectionClosed()
{
    //#[ operation TCPIPConnectionClosed()
    for( QTcpSocket *aSocket : myClient )
    {
        if( aSocket->state() != QTcpSocket::ConnectedState )
        {
            QObject::disconnect(aSocket, SIGNAL(readyRead()), this, SLOT(readData()));
            QObject::disconnect(aSocket, SIGNAL(disconnected()), this, SLOT(TCPIPConnectionClosed()) );
            myClient.removeOne( aSocket );
        }
    }
    //#]
}

void RemoteControll::TCPIPnewConnection()
{
    //#[ operation TCPIPnewConnection()
    QTcpSocket *newSocket = itsQTcpServer->nextPendingConnection();
    newSocket->moveToThread( this );
    if( myClient.size() == 0 )
    {
        if( activeCommandList != NULL )
        {
            commandCounter = activeCommandList->getCommands().size();
        }
    }
    myClient.append( newSocket );
    QObject::connect(newSocket, SIGNAL(readyRead()), this, SLOT(readData()) );
    QObject::connect( newSocket, SIGNAL(disconnected()), this, SLOT(TCPIPConnectionClosed()) );
    //#]
}

ModelInstance* RemoteControll::getCurrentModelInstanceWaitingForState()
{
    //#[ operation getCurrentModelInstanceWaitingForState()
    return currentModelInstanceWaitingForState;
    //#]
}

void RemoteControll::init()
{
    //#[ operation init()
    int TcpServerPortNumber = itsConfigurationWindow->getRemoteControlPort();
    itsMainWindow->consoleMsg( "TCP/IP Remote Control Server start on port " + QString::number( TcpServerPortNumber ) + ".");
    this->start();
    //#]
}

void RemoteControll::readData()
{
    //#[ operation readData()
    char data[1024];
    for( QTcpSocket *aSocket : myClient )
    {
        int dataReceived = aSocket->readLine(data, 1024);
        if( dataReceived > 0 )
        {
            QString myCommand(data);
            if( myCommand.startsWith( "REQUEST_STATE:" ) )
            {
                QStringList myList = myCommand.split("REQUEST_STATE:",QString::SkipEmptyParts);
                if( myList.size() == 1 )
                {
                    if( itsSender->requestState( myList.at(0).trimmed(), *SingleParser::getItsTargetInformation() ) )
                    {
                        currentModelInstanceWaitingForState = SingleParser::getItsTargetInformation()->getInstance(myList.at(0).trimmed());
                        waitingSocket = aSocket;
                        aSocket->write("SUCCESS\r\n");
                    }
                    else
                    {
                        aSocket->write("ERROR:1\r\n");
                    }
                }
                else
                {
                    aSocket->write("ERROR:1\r\n");
                }
            }
            else if( myCommand.startsWith( "REQUEST_ATTRIBUT:" ) )
            {
                QStringList myList = myCommand.split("REQUEST_ATTRIBUT:",QString::SkipEmptyParts);
                if( myList.size() == 1 )
                {
                    myList = myList.at(0).trimmed().split(";",QString::SkipEmptyParts);
                    if( myList.size() == 2)
                    {
                        if( itsSender->requestAttribut(myList.at(0).trimmed(), myList.at(1).trimmed(), *SingleParser::getItsTargetInformation()) )
                        {
                            currentModelInstanceWaitingForAttribute = myList.at(0).trimmed()+ ";" + myList.at(1).trimmed();
                            waitingSocket = aSocket;
                            aSocket->write("SUCCESS\r\n");
                        }
                        else
                        {
                            aSocket->write("ERROR:2\r\n");
                        }
                    }
                    else
                    {
                        aSocket->write("ERROR:2\r\n");
                    }
                }
            }
            else if( myCommand.startsWith( "INJECT_EVENT:" ) )
            {
                QStringList myList = myCommand.split("INJECT_EVENT:",QString::SkipEmptyParts);
                if( myList.size() == 1 )
                {
                    myList = myList.at(0).trimmed().split(";");
                    if( myList.size() == 2 )
                    {
                        ModelInstance *myInstance = SingleParser::getItsTargetInformation()->getInstance(myList.at(0).trimmed());
                        if( myInstance == NULL )
                        {
                            aSocket->write("ERROR:3\r\n");
                        }
                        else
                        {
                            const ModelEventType *myEvent = SingleParser::getItsTargetInformation()->getEventType(myList.at(1).trimmed());
                            if( myEvent == NULL )
                            {
                                aSocket->write("ERROR:4\r\n");
                                return;
                            }
                            else
                            {
                                if( myEvent->getArguments().size() > 0 )
                                {
                                    aSocket->write("ERROR:5\r\n");
                                }
                                else
                                {
                                    itsSender->injectEvent(myInstance->getAddress(),myEvent->getId(),NULL,0, *SingleParser::getItsTargetInformation() );
                                    aSocket->write("SUCCESS\r\n");
                                }
                            }
                        }
                    }
                    else
                    {
                        ModelInstance *myInstance = SingleParser::getItsTargetInformation()->getInstance(myList.at(0).trimmed());
                        if( myInstance == NULL )
                        {
                            aSocket->write("ERROR:3\r\n");
                        }
                        else
                        {
                            const ModelEventType *myEvent = SingleParser::getItsTargetInformation()->getEventType(myList.at(1).trimmed());
                            if( myEvent == NULL )
                            {
                                aSocket->write("ERROR:4\r\n");
                                return;
                            }
                            else
                            {
                                myList = myList.at(2).trimmed().split(",");
                                const QVector<ModelEventArgumentType*>& eventParameter = myEvent->getArguments();
                                if( eventParameter.size() != myList.size() )
                                {
                                    aSocket->write("ERROR:5\r\n");
                                }
                                else
                                {
                                    char eventParameterData[256];
                                    int eventParameterDataSize = 0;
                                    bool parameter;
                                    for( int i = 0; i < eventParameter.size(); i++ )
                                    {
                                        int iVal = myList.at(i).toInt(&parameter,16);
                                        if( !parameter )
                                        {
                                            break;
                                        }
                                        int argumentSize = eventParameter.at(i)->getType()->getSize();
                                        if( argumentSize > 4)
                                        {
                                            if( argumentSize % 4 != 0)
                                            {
                                                eventParameterDataSize += 4 - ( argumentSize % 4 );
                                            }
                                        }
                                        else
                                        {
                                            if( eventParameterDataSize % argumentSize != 0 )
                                            {
                                                eventParameterDataSize += argumentSize - ( eventParameterDataSize % argumentSize );
                                            }
                                        }
                                        if( SingleParser::getItsTargetInformation()->getEndianess() == LITTLE_ENDIAN )
                                        {
                                            for( int j = 0; j < eventParameter.at(i)->getType()->getSize(); j++ )
                                            {
                                                eventParameterData[ eventParameterDataSize ] = (char)iVal >>( j * 8 );
                                                eventParameterDataSize++;
                                            }
                                        }
                                        else
                                        {
                                            for( int j = eventParameter.at(i)->getType()->getSize() -1; j >=0 ; j-- )
                                            {
                                                eventParameterData[ eventParameterDataSize ] = (char)iVal >>( j * 8 );
                                                eventParameterDataSize++;
                                            }
                                        }
                                    }
                                    if( parameter )
                                    {
                                        itsSender->injectEvent(myInstance->getAddress(),myEvent->getId(),eventParameterData,eventParameterDataSize, *SingleParser::getItsTargetInformation() );
                                        aSocket->write("SUCCESS\r\n");
                                    }
                                    else
                                    {
                                        aSocket->write("ERROR:6\r\n");
                                    }
                                }
                            }
                        }
                    }
                }
            }
            else if( myCommand.startsWith( "STOP_TARGET" ) )
            {
                itsSender->suspendRXF();
                aSocket->write("SUCCESS\r\n");
            }
            else if( myCommand.startsWith( "CONSUME_TARGET" ) )
            {
                itsSender->resumeRXF();
                aSocket->write("SUCCESS\r\n");
            }
            else
            {
                aSocket->write("ERROR:0\r\n");
            }
            aSocket->flush();
        }
    }
    //#]
}

void RemoteControll::setAttributValueForAttributRequest(const QString& value)
{
    //#[ operation setAttributValueForAttributRequest(QString)
    if( currentModelInstanceWaitingForAttribute != "" )
    {
        attributValue = value;
    }
    //#]
}

void RemoteControll::setStateForStateRequest(const QString& state)
{
    //#[ operation setStateForStateRequest(QString)
    stateValue = state;
    //#]
}

void RemoteControll::updateCommandList(const CommandList& commandList)
{
    //#[ operation updateCommandList(CommandList)
    this->activeCommandList = &commandList;
    //#]
}

void RemoteControll::run()
{
    //#[ operation run()
    itsQTcpServer = new QTcpServer();
    QObject::connect (itsQTcpServer, SIGNAL(newConnection()), this, SLOT(TCPIPnewConnection()));
    int TcpServerPortNumber = itsConfigurationWindow->getRemoteControlPort();
    if( TcpServerPortNumber > 0 )
    {
        if (!itsQTcpServer->listen(QHostAddress::LocalHost, TcpServerPortNumber))
        {
            return;
        }
    }
    while( running )
    {
        if( myClient.size() > 0 && this->activeCommandList != NULL )
        {
            uint currentSize = this->activeCommandList->getCommands().size();
            while( currentSize > commandCounter )
            {
                QString *dataToClient = commandToString( *activeCommandList->getCommands().at( commandCounter ) );
                if( dataToClient != NULL )
                {
                    for( QTcpSocket *aSocket : myClient )
                    {
                        aSocket->write( dataToClient->toStdString().c_str() );
                        aSocket->flush();
                    }
                    delete dataToClient;
                }
                commandCounter++;
            }
            if( currentModelInstanceWaitingForState != NULL )
            {
                if(stateValue != "" && waitingSocket != NULL )
                {
                    QString data = "STATE_VALUE:" + currentModelInstanceWaitingForState->getName() + ";" + stateValue + "\r\n";
                    waitingSocket->write(data.toStdString().c_str());
                    waitingSocket->flush();
                    waitingSocket = NULL;
                    stateValue = "";
                }
            }
            if( currentModelInstanceWaitingForAttribute != "" )
            {
                if(attributValue != "" && waitingSocket != NULL )
                {
                    QString data = "ATTRIBUT_VALUE:" + currentModelInstanceWaitingForAttribute + ";" + attributValue + "\r\n";
                    waitingSocket->write(data.toStdString().c_str());
                    waitingSocket->flush();
                    waitingSocket = NULL;
                    attributValue = "";
                }
            }
        }
        QApplication::processEvents();
        QThread::msleep(150);
    }
    for( QTcpSocket *aSocket : myClient )
    {
        aSocket->close();
    }
    QObject::disconnect (itsQTcpServer, SIGNAL(newConnection()), this, SLOT(TCPIPnewConnection()));
    itsQTcpServer->close();
    //#]
}

QString* RemoteControll::commandToString(const Command& aCommand)
{
    //#[ operation commandToString(Command)
    QString *retVal = NULL;
    switch( aCommand.getCommandIdentifier() )
    {
        case Command::constructorCommand :
        {
            CommandConstructor *myCommand = (CommandConstructor *)&aCommand;
            retVal = new QString("INSTANCE_CREATED:" + myCommand->getItsModelInstance()->getName() + "\r\n");
            break;
        }
        case Command::destructorCommand :
        {
            CommandDestructor *myCommand = (CommandDestructor *)&aCommand;
            retVal = new QString("INSTANCE_DESTROYED:" + myCommand->getItsModelInstance()->getName() + "\r\n");
            break;
        }
        case Command::debugIntValue :
        {
            CommandIntVal *myCommand = (CommandIntVal *)&aCommand;
            retVal = new QString("INT_VALUE:" + myCommand->getInstance()->getName() + ";" + QString::number((int)myCommand->getIntValue()) + "\r\n");
            break;
        }
        case Command::errorHandlerReachedCommand :
        {
            retVal = new QString("ERROR_HANDLER\r\n");
            break;
        }
        case Command::eventEndDispatchCommand :
        {
            CommandEventEndDispatch *myCommand = (CommandEventEndDispatch *)&aCommand;
            retVal = new QString("EVENT_END:" + QString::number(myCommand->getEventID()) + ";" + myCommand->getStateAfterEventConsumption() + "\r\n");
            break;
        }
        case Command::eventPutToMessageQueueCommand :
        {
            CommandEventCreated *myCommand = (CommandEventCreated *)&aCommand;
            const QVector<ReceivedEventParameter*>& myArguments = myCommand->getReceivedEventParameters();
            QString eventArguments = "";
            bool first = true;
            for( ReceivedEventParameter* aArgument : myArguments )
            {
                if( first == true )
                {
                    first = false;
                    eventArguments += aArgument->getValue();
                }
                else
                {
                    eventArguments += "," + aArgument->getValue();
                }
            }
            retVal = new QString("EVENT_TO_MSG:" + myCommand->getSourceInstance()->getName() + ";" +
                                 myCommand->getDestinationInstance()->getName() + ";" +
                                 myCommand->getItsModelEventType()->getName() + ";" +
                                 QString::number( myCommand->getTicks() ) + ";" +
                                 QString::number( myCommand->getEventID() ) + ";" +
                                 eventArguments + "\r\n");
            break;
        }
        case Command::eventStartDispatchCommand :
        {
            CommandEventStartDispatch *myCommand = (CommandEventStartDispatch *)&aCommand;
            retVal = new QString("EVENT_START:" + QString::number(myCommand->getEventID()) + "\r\n");
            break;
        }
        case Command::operationCalled :
        {
            CommandOperationCall *myCommand = (CommandOperationCall *)&aCommand;
            const QVector<ReceivedEventParameter*>& myArguments = myCommand->getReceivedEventParameters();
            QString eventArguments = "";
            bool first = true;
            for( ReceivedEventParameter* aArgument : myArguments )
            {
                if( first == true )
                {
                    first = false;
                    eventArguments += aArgument->getValue();
                }
                else
                {
                    eventArguments += ";" + aArgument->getValue();
                }
            }
            retVal = new QString("OP_CALL:" + myCommand->getSourceInstance()->getName() + ";" +
                                 myCommand->getDestinationInstance()->getName() + ";" +
                                 myCommand->getItsModelEventType()->getName() + ";" +
                                 QString::number( myCommand->getTicks() ) + ";" +
                                 eventArguments + "\r\n");
            break;
        }
        case Command::traceEventCommand :
        {
            CommandTraceEvent *myCommand = (CommandTraceEvent *)&aCommand;
            const QVector<ReceivedEventParameter*>& myArguments = myCommand->getReceivedEventParameters();
            QString eventArguments = "";
            bool first = true;
            for( ReceivedEventParameter* aArgument : myArguments )
            {
                if( first == true )
                {
                    first = false;
                    eventArguments += aArgument->getValue();
                }
                else
                {
                    eventArguments += ";" + aArgument->getValue();
                }
            }
            retVal = new QString("EVENT:" + myCommand->getSourceInstance()->getName() + ";" +
                                 myCommand->getDestinationInstance()->getName() + ";" +
                                 myCommand->getItsModelEventType()->getName() + ";" +
                                 QString::number( myCommand->getTicks() ) + ";" +
                                 eventArguments + ";" +
                                 myCommand->getStateAfterEventConsumption() + "\r\n");
            break;
        }
        case Command::bufferOverflowCommand :
        {
            retVal = new QString("BUFFER_OVERFLOW\r\n");
            break;
        }
    }
    return retVal;
    //#]
}

void RemoteControll::cleanUpRelations()
{
    if(activeCommandList != NULL)
        {
            activeCommandList = NULL;
        }
    if(itsConfigurationWindow != NULL)
        {
            itsConfigurationWindow = NULL;
        }
    if(itsMainWindow != NULL)
        {
            itsMainWindow = NULL;
        }
    if(itsQTcpServer != NULL)
        {
            itsQTcpServer = NULL;
        }
    if(itsSender != NULL)
        {
            itsSender = NULL;
        }
    {
        myClient.clear();
    }
}

/*********************************************************************
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\RemoteControll.cpp
*********************************************************************/
