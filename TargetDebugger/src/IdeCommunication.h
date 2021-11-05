/*********************************************************************
	Rhapsody	: 9.0.1 
	Login		: Y9DSYU706
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: IdeCommunication
//!	Generated Date	: Thu, 4, Nov 2021  
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\IdeCommunication.h
*********************************************************************/

#ifndef IdeCommunication_H
#define IdeCommunication_H

#include <QObject>
//## package Plugins::TestConductorPlugin

//## class IdeCommunication
class IdeCommunication : public QObject {
Q_OBJECT
    ////    Operations    ////
    
public :

    //## operation compileTarget()
    virtual int compileTarget() = 0;
    
    //## operation consoleMsg(QString)
    Q_SIGNAL void consoleMsg(const QString& msg);
    
    //## operation errorMsg(QString)
    Q_SIGNAL void errorMsg(const QString& msg);
    
    //## operation flashTarget()
    virtual int flashTarget() = 0;
    
    //## operation getName()
    virtual QString getName() = 0;
    
    //## operation initialisation(bool)
    virtual void initialisation(bool directConfig) = 0;
    
    //## operation openIDEProject(QString)
    virtual int openIDEProject(const QString& projectPath) = 0;
    
    //## operation runTarget()
    virtual int runTarget() = 0;
    
    //## operation showAutoStartConfigurationDialog()
    virtual void showAutoStartConfigurationDialog() = 0;
    
    //## operation showCommunicationConfigurationDialog()
    virtual void showCommunicationConfigurationDialog() = 0;
};

QT_BEGIN_NAMESPACE
    Q_DECLARE_INTERFACE(IdeCommunication,"PlugInCommunication")
QT_END_NAMESPACE

#endif
/*********************************************************************
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\IdeCommunication.h
*********************************************************************/
