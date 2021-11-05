/*********************************************************************
	Rhapsody	: 9.0.1 
	Login		: Y9DSYU706
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: SequenceDiagramToRhapsodyExporter
//!	Generated Date	: Thu, 4, Nov 2021  
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\SequenceDiagramToRhapsodyExporter.h
*********************************************************************/

#ifndef SequenceDiagramToRhapsodyExporter_H
#define SequenceDiagramToRhapsodyExporter_H

#include "CommandList.h"
#include <QTcpSocket.h>
#include <QObject.h>
class CommandEventCreated;

class CommandEventEndDispatch;

class CommandEventStartDispatch;

class CommandOperationCall;

class CommandTraceEvent;

class ModelEventType;

class QProgressBar;

//## package API

//## class SequenceDiagramToRhapsodyExporter
class SequenceDiagramToRhapsodyExporter : public QObject {
Q_OBJECT
    ////    Constructors and destructors    ////
    
public :

    //## operation SequenceDiagramToRhapsodyExporter()
    SequenceDiagramToRhapsodyExporter();
    
    ~SequenceDiagramToRhapsodyExporter();
    
    ////    Operations    ////
    
    //## operation targetConnected()
    Q_SLOT void targetConnected();
    
    //## operation toRhapsody(CommandList)
    Q_SLOT void toRhapsody(const CommandList& commandList);
    
    ////    Additional operations    ////
    
    inline const CommandList* getCommandList() const
    {
        return commandList;
    }
    
    inline QTcpSocket* getItsQTcpSocket() const
    {
        return (QTcpSocket*) &itsQTcpSocket;
    }
    
    ////    Attributes    ////

private :

    const CommandList* commandList;		//## attribute commandList
    
    ////    Relations and components    ////

protected :

    QTcpSocket itsQTcpSocket;
};

#endif
/*********************************************************************
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\SequenceDiagramToRhapsodyExporter.h
*********************************************************************/
