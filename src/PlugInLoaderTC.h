/*********************************************************************
	Rhapsody	: 9.0.1 
	Login		: Y9DSYU706
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: PlugInLoaderTC
//!	Generated Date	: Thu, 4, Nov 2021  
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\PlugInLoaderTC.h
*********************************************************************/

#ifndef PlugInLoaderTC_H
#define PlugInLoaderTC_H

#include <QList>
#include "IdeCommunication.h"
#include <QObject>
class MainWindow;

class QSettings;

//## package Plugins::TestConductorPlugin

//## class PlugInLoaderTC
class PlugInLoaderTC : public QObject {
Q_OBJECT
    ////    Constructors and destructors    ////
    
public :

    //## operation PlugInLoaderTC()
    PlugInLoaderTC();
    
    ~PlugInLoaderTC();
    
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
    
    ////    Additional operations    ////
    
    inline IdeCommunication* getActivePlugin() const
    {
        return activePlugin;
    }
    
    inline void setActivePlugin(IdeCommunication* p_activePlugin)
    {
        activePlugin = p_activePlugin;
    }
    
    inline MainWindow* getItsMainWindow() const
    {
        return itsMainWindow;
    }
    
    inline void setItsMainWindow(MainWindow* p_MainWindow)
    {
        itsMainWindow = p_MainWindow;
    }

protected :

    void cleanUpRelations();
    
    ////    Attributes    ////

private :

    IdeCommunication* activePlugin;		//## attribute activePlugin
    
    QList<IdeCommunication*> myCommunications;		//## attribute myCommunications
    
    ////    Relations and components    ////

protected :

    MainWindow* itsMainWindow;
};

#endif
/*********************************************************************
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\PlugInLoaderTC.h
*********************************************************************/
