/*********************************************************************
	Rhapsody	: 9.0.1 
	Login		: Y9DSYU706
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: PlugInLoader
//!	Generated Date	: Thu, 4, Nov 2021  
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\PlugInLoader.h
*********************************************************************/

#ifndef PlugInLoader_H
#define PlugInLoader_H

#include <QList>
#include "Receiver.h"
#include "TargetCommunication.h"
#include <QObject>
class MainWindow;

class QSettings;

class Sender;

//## package Plugins::CommunicationPlugin

//## class PlugInLoader
class PlugInLoader : public QObject {
Q_OBJECT
    ////    Constructors and destructors    ////
    
public :

    //## operation PlugInLoader()
    PlugInLoader();
    
    //## operation ~PlugInLoader()
    ~PlugInLoader();
    
    ////    Operations    ////
    
    //## operation forwardConsoleMsg(QString)
    Q_SLOT void forwardConsoleMsg(const QString& msg);
    
    //## operation forwardErrorMsg(QString)
    Q_SLOT void forwardErrorMsg(const QString& msg);
    
    //## operation getPluginStringList()
    QStringList getPluginStringList();
    
    //## operation loadPluginOnAutoStart(QString)
    void loadPluginOnAutoStart(const QString& pluginName);
    
    //## operation loadPlugins()
    bool loadPlugins();
    
    //## operation openAutoStartConfigurationDialog(QString)
    void openAutoStartConfigurationDialog(const QString& pluginName);
    
    //## operation openCommunicationList()
    Q_SLOT void openCommunicationList();
    
    //## operation targetCommunicationEstablished()
    Q_SLOT void targetCommunicationEstablished();
    
    ////    Additional operations    ////
    
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

    QList<TargetCommunication*> myCommunications;		//## attribute myCommunications
    
    ////    Relations and components    ////

protected :

    MainWindow* itsMainWindow;
    
    Sender* itsSender;
};

#endif
/*********************************************************************
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\PlugInLoader.h
*********************************************************************/
