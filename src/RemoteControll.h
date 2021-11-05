/*********************************************************************
	Rhapsody	: 9.0.1 
	Login		: Y9DSYU706
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: RemoteControll
//!	Generated Date	: Thu, 4, Nov 2021  
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\RemoteControll.h
*********************************************************************/

#ifndef RemoteControll_H
#define RemoteControll_H

#include <QList>
#include "ModelInstance.h"
#include <QTcpServer.h>
#include <QTcpSocket.h>
#include <QThread.h>
class Command;

class CommandConstructor;

class CommandDestructor;

class CommandEventCreated;

class CommandEventEndDispatch;

class CommandEventStartDispatch;

class CommandIntVal;

class CommandList;

class CommandOperationCall;

class CommandTraceEvent;

class ConfigurationWindow;

class MainWindow;

class ModelEventType;

class Sender;

class SingleParser;

class TargetInformation;

//## package API

//## class RemoteControll
class RemoteControll : public QThread {
Q_OBJECT
private :

    enum RESPONSE_TYPE {
        SUCCESSFUL = 0,
        REQUEST_STATE_FAILED = 1,
        REQUEST_ATTRIBUT_INSTANCE_UNKNOWN = 2,
        REQUEST_ATTRIBUT_ATTRIBUT_UNKNOWN = 3,
        INJECT_EVENT_DESTINATION_UNKNOWN = 4,
        INJECT_EVENT_EVENT_UNKNOWN = 5,
        INJECT_EVENT_WRONG_NUMBER_PARAMETER = 6,
        INJECT_EVENT_PARAMETER_WRONG_FORMAT = 7
    };
    
    ////    Constructors and destructors    ////

public :

    //## operation RemoteControll()
    RemoteControll();
    
    //## operation ~RemoteControll()
    ~RemoteControll();
    
    ////    Operations    ////
    
    //## operation TCPIPConnectionClosed()
    Q_SLOT void TCPIPConnectionClosed();
    
    //## operation TCPIPnewConnection()
    Q_SLOT void TCPIPnewConnection();
    
    //## operation getCurrentModelInstanceWaitingForState()
    ModelInstance* getCurrentModelInstanceWaitingForState();
    
    //## operation init()
    void init();
    
    //## operation readData()
    Q_SLOT void readData();
    
    //## operation setAttributValueForAttributRequest(QString)
    void setAttributValueForAttributRequest(const QString& value);
    
    //## operation setStateForStateRequest(QString)
    void setStateForStateRequest(const QString& state);
    
    //## operation updateCommandList(CommandList)
    void updateCommandList(const CommandList& commandList);

protected :

    //## operation run()
    virtual void run();

private :

    //## operation commandToString(Command)
    QString* commandToString(const Command& aCommand);
    
    ////    Additional operations    ////

public :

    inline ConfigurationWindow* getItsConfigurationWindow() const
    {
        return itsConfigurationWindow;
    }
    
    inline void setItsConfigurationWindow(ConfigurationWindow* p_ConfigurationWindow)
    {
        itsConfigurationWindow = p_ConfigurationWindow;
    }
    
    inline MainWindow* getItsMainWindow() const
    {
        return itsMainWindow;
    }
    
    inline void setItsMainWindow(MainWindow* p_MainWindow)
    {
        itsMainWindow = p_MainWindow;
    }
    
    inline Sender* getItsSender() const
    {
        return itsSender;
    }
    
    inline void setItsSender(Sender* p_Sender)
    {
        itsSender = p_Sender;
    }

protected :

    void cleanUpRelations();
    
    ////    Attributes    ////

private :

    QString attributValue;		//## attribute attributValue
    
    uint32_t commandCounter;		//## attribute commandCounter
    
    QString currentModelInstanceWaitingForAttribute;		//## attribute currentModelInstanceWaitingForAttribute
    
    ModelInstance* currentModelInstanceWaitingForState;		//## attribute currentModelInstanceWaitingForState
    
    bool running;		//## attribute running
    
    QString stateValue;		//## attribute stateValue
    
    QTcpSocket* waitingSocket;		//## attribute waitingSocket
    
    ////    Relations and components    ////

protected :

    ConfigurationWindow* itsConfigurationWindow;
    
    MainWindow* itsMainWindow;
    
    QTcpServer* itsQTcpServer;
    
    Sender* itsSender;
    
    QList<QTcpSocket*> myClient;

private :

    const CommandList* activeCommandList;
};

#endif
/*********************************************************************
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\RemoteControll.h
*********************************************************************/
