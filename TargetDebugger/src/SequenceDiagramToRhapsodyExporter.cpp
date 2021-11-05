/********************************************************************
	Rhapsody	: 9.0.1 
	Login		: Y9DSYU706
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: SequenceDiagramToRhapsodyExporter
//!	Generated Date	: Thu, 4, Nov 2021  
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\SequenceDiagramToRhapsodyExporter.cpp
*********************************************************************/

#include "SequenceDiagramToRhapsodyExporter.h"
#include "CommandEventCreated.h"
#include "CommandEventEndDispatch.h"
#include "CommandEventStartDispatch.h"
#include "CommandOperationCall.h"
#include "CommandTraceEvent.h"
#include "ModelEventType.h"
#include <QProgressBar.h>
#include <QHostAddress.h>
#include <QApplication>
//## package API

//## class SequenceDiagramToRhapsodyExporter
SequenceDiagramToRhapsodyExporter::SequenceDiagramToRhapsodyExporter()
{
    //#[ operation SequenceDiagramToRhapsodyExporter()
    connect( &itsQTcpSocket, SIGNAL(connected()), this, SLOT(targetConnected()));
    //#]
}

SequenceDiagramToRhapsodyExporter::~SequenceDiagramToRhapsodyExporter()
{
}

void SequenceDiagramToRhapsodyExporter::targetConnected()
{
    //#[ operation targetConnected()
    QProgressBar bar;
    bar.setTextVisible(true);
    bar.setWindowTitle("Sending to Rhapsody");
    int count = commandList->getCommands().size();
    bar.setMaximum( count );
    bar.show();
    
    char sendData = 4;
    itsQTcpSocket.write(&sendData,1);
    
    for( int i = 0; i < count; i++)
    {
        Command *myCommand = commandList->getCommands().at( i );
        if( myCommand->getCommandIdentifier() == Command::eventPutToMessageQueueCommand  )
        {
            CommandEventCreated *myEventCreated = (CommandEventCreated*)myCommand;
            if( myEventCreated->getItsCommandEventStartDispatch() != NULL && myEventCreated->getItsCommandEventStartDispatch()->getItsCommandEventEndDispatch() != NULL )
            {
                char sendData = 2;
                itsQTcpSocket.write(&sendData,1);
                itsQTcpSocket.write(myEventCreated->getSourceInstance()->getName().toStdString().c_str(),myEventCreated->getSourceInstance()->getName().length() + 1);
                itsQTcpSocket.write(myEventCreated->getDestinationInstance()->getName().toStdString().c_str(),myEventCreated->getDestinationInstance()->getName().length() + 1);
                itsQTcpSocket.write(myEventCreated->getItsModelEventType()->getName().toStdString().c_str(),myEventCreated->getItsModelEventType()->getName().length() + 1);
                CommandEventEndDispatch *myEventEnd = (CommandEventEndDispatch*)myEventCreated->getItsCommandEventStartDispatch()->getItsCommandEventEndDispatch();
                itsQTcpSocket.write(myEventEnd->getStateAfterEventConsumption().toStdString().c_str(), myEventEnd->getStateAfterEventConsumption().length() + 1);
            }
        }
        if( myCommand->getCommandIdentifier() == Command::operationCalled )
        {
            CommandOperationCall *myOpCall = (CommandOperationCall*)myCommand;
            char sendData = 3;
            itsQTcpSocket.write(&sendData,1);
            itsQTcpSocket.write(myOpCall->getSourceInstance()->getName().toStdString().c_str(),myOpCall->getSourceInstance()->getName().length() + 1);
            itsQTcpSocket.write(myOpCall->getDestinationInstance()->getName().toStdString().c_str(),myOpCall->getDestinationInstance()->getName().length() + 1);
            itsQTcpSocket.write(myOpCall->getItsModelEventType()->getName().toStdString().c_str(),myOpCall->getItsModelEventType()->getName().length() + 1);
        }
    
        if( myCommand->getCommandIdentifier() == Command::traceEventCommand  )
        {
            CommandTraceEvent *myTraceEvent = (CommandTraceEvent*)myCommand;
                char sendData = 2;
                itsQTcpSocket.write(&sendData,1);
                itsQTcpSocket.write(myTraceEvent->getSourceInstance()->getName().toStdString().c_str(),myTraceEvent->getSourceInstance()->getName().length() + 1);
                itsQTcpSocket.write(myTraceEvent->getDestinationInstance()->getName().toStdString().c_str(),myTraceEvent->getDestinationInstance()->getName().length() + 1);
                itsQTcpSocket.write(myTraceEvent->getItsModelEventType()->getName().toStdString().c_str(),myTraceEvent->getItsModelEventType()->getName().length() + 1);
                itsQTcpSocket.write(myTraceEvent->getStateAfterEventConsumption().toStdString().c_str(), myTraceEvent->getStateAfterEventConsumption().length() + 1);
        }
        QApplication::processEvents();
        bar.setValue(i);
    }
    sendData = 5;
    itsQTcpSocket.write(&sendData,1);
    itsQTcpSocket.flush();
    itsQTcpSocket.close();
    bar.hide();
    //#]
}

void SequenceDiagramToRhapsodyExporter::toRhapsody(const CommandList& commandList)
{
    //#[ operation toRhapsody(CommandList)
    QHostAddress addr("127.0.0.1");
    itsQTcpSocket.connectToHost(addr,27015, QTcpSocket::WriteOnly);
    this->commandList = &commandList;
    //#]
}

/*********************************************************************
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\SequenceDiagramToRhapsodyExporter.cpp
*********************************************************************/
