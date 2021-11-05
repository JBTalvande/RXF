/*********************************************************************
	Rhapsody	: 9.0.1 
	Login		: Y9DSYU706
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: TargetCommunication
//!	Generated Date	: Thu, 4, Nov 2021  
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\TargetCommunication.h
*********************************************************************/

#ifndef TargetCommunication_H
#define TargetCommunication_H

#include <QObject>
//## package Plugins::CommunicationPlugin

//## class TargetCommunication
class TargetCommunication : public QObject {
Q_OBJECT
    ////    Operations    ////
    
public :

    //## operation consoleMsg(QString)
    Q_SIGNAL void consoleMsg(const QString& msg);
    
    //## operation errorMsg(QString)
    Q_SIGNAL void errorMsg(const QString& msg);
    
    //## operation getName()
    virtual QString getName() = 0;
    
    //## operation initialisation(bool)
    virtual void initialisation(bool directConfig) = 0;
    
    //## operation setReceiveOperationCallBackPointer(void (*)( char*, unsigned int ))
    inline void setReceiveOperationCallBackPointer(void (*p_receiveOperationCallBackPointer)( char*, unsigned int ));
    
    //## operation showAutoStartConfigurationDialog()
    virtual void showAutoStartConfigurationDialog() = 0;
    
    //## operation showCommunicationConfigurationDialog()
    virtual void showCommunicationConfigurationDialog() = 0;
    
    //## operation targetCommunicationEstablished()
    Q_SIGNAL void targetCommunicationEstablished();
    
    //## operation write(char*,unsigned int,int)
    virtual void write(char* data, unsigned int size, int targetNr) = 0;
    
    ////    Attributes    ////

protected :

    void (*receiveOperationCallBackPointer)( char*, unsigned int );		//## attribute receiveOperationCallBackPointer
};

QT_BEGIN_NAMESPACE
    Q_DECLARE_INTERFACE(TargetCommunication,"PlugInCommunication")
QT_END_NAMESPACE

inline void TargetCommunication::setReceiveOperationCallBackPointer(void (*p_receiveOperationCallBackPointer)( char*, unsigned int ))
{
    //#[ operation setReceiveOperationCallBackPointer(void (*)( char*, unsigned int ))
    receiveOperationCallBackPointer = p_receiveOperationCallBackPointer;
    //#]
}

#endif
/*********************************************************************
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\TargetCommunication.h
*********************************************************************/
