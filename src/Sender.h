/*********************************************************************
	Rhapsody	: 9.0.1 
	Login		: Y9DSYU706
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: Sender
//!	Generated Date	: Thu, 4, Nov 2021  
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\Sender.h
*********************************************************************/

#ifndef Sender_H
#define Sender_H

#include "DataTransmission.h"
#include <QObject>
#include <QModelIndex>
#include <QStandardItem>
class MainWindow;

class ModelClassAttribute;

class ModelInstance;

class TargetCommunication;

class TargetInformation;

//## package LogicLevel::DataTransmission

//## class Sender
class Sender : public QObject {
Q_OBJECT
private :

    enum sendCommandIds {
        command_suspendRXF = 0,
        command_resumeRXF = 1,
        command_requestAttributeValue = 2,
        command_requestState = 3,
        command_injectEvent = 4,
        command_addBreakpoint = 5,
        command_removeBreakpoint = 6,
        command_instanceFilter = 7,
        command_syncTargets = 8,
        command_debugIntFilter = 9
    };
    
    ////    Constructors and destructors    ////

public :

    Sender();
    
    ~Sender();
    
    ////    Operations    ////
    
    //## operation addBreakpoint(uint64_t,int,int,TargetInformation)
    void addBreakpoint(uint64_t instanceAddress, int stateId, int eventId, TargetInformation& targetInformation);
    
    //## operation executeTest(QString)
    void executeTest(const QString& testCase);
    
    //## operation handleDebugIntFilter(QStandardItem)
    Q_SLOT void handleDebugIntFilter(QStandardItem* modelIndex);
    
    //## operation handleInstanceFilter(QStandardItem)
    Q_SLOT void handleInstanceFilter(QStandardItem* modelIndex);
    
    //## operation handleTargetTreeCollaps(QModelIndex)
    Q_SLOT void handleTargetTreeCollaps(QModelIndex modelIndex);
    
    //## operation injectEvent(uint64_t,int,char*,int,TargetInformation)
    void injectEvent(uint64_t instanceAddress, int eventId, char* eventParameter, int eventParameterCount, TargetInformation& targetInformation);
    
    //## operation removeBreakpoint(uint64_t,int,int,TargetInformation)
    void removeBreakpoint(uint64_t instanceAddress, int stateId, int eventId, TargetInformation& targetInformation);
    
    //## operation requestAttribut(QString,QString,TargetInformation)
    bool requestAttribut(const QString& instanceName, const QString& argumentName, TargetInformation& targetInformation);
    
    //## operation requestState(QString,TargetInformation)
    bool requestState(const QString& instanceName, TargetInformation& targetInformation);
    
    //## operation resumeRXF()
    Q_SLOT void resumeRXF();
    
    //## operation suspendRXF()
    Q_SLOT void suspendRXF();
    
    //## operation synchronizeTargets()
    Q_SLOT void synchronizeTargets();

private :

    //## operation addAddressToStream(uint64_t,char*,TargetInformation)
    unsigned int addAddressToStream(uint64_t address, char* data, TargetInformation& targetInformation);
    
    //## operation requestArrayAttribut(QString,QString,unsigned int,TargetInformation)
    bool requestArrayAttribut(const QString& instanceName, const QString& argumentName, unsigned int position, TargetInformation& targetInformation);
    
    ////    Additional operations    ////

public :

    inline MainWindow* getItsMainWindow() const
    {
        return itsMainWindow;
    }
    
    inline void setItsMainWindow(MainWindow* p_MainWindow)
    {
        itsMainWindow = p_MainWindow;
    }
    
    inline TargetCommunication* getItsTargetCommunication() const
    {
        return itsTargetCommunication;
    }
    
    inline void setItsTargetCommunication(TargetCommunication* p_TargetCommunication)
    {
        itsTargetCommunication = p_TargetCommunication;
    }

protected :

    void cleanUpRelations();
    
    ////    Relations and components    ////
    
    MainWindow* itsMainWindow;
    
    TargetCommunication* itsTargetCommunication;
};

#endif
/*********************************************************************
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\Sender.h
*********************************************************************/
