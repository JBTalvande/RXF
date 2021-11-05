/********************************************************************
	Rhapsody	: 9.0.1 
	Login		: Y9DSYU706
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: PlugInLoaderTC
//!	Generated Date	: Thu, 4, Nov 2021  
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\PlugInLoaderTC.cpp
*********************************************************************/

#include "PlugInLoaderTC.h"
#include "MainWindow.h"
#include <QSettings.h>
#include <QPlugInLoader>
#include <QString>
#include <QDir>
#include <QInputDialog>
//## package Plugins::TestConductorPlugin

//## class PlugInLoaderTC
PlugInLoaderTC::PlugInLoaderTC() : activePlugin(NULL)
{
    itsMainWindow = NULL;
    //#[ operation PlugInLoaderTC()
    //#]
}

PlugInLoaderTC::~PlugInLoaderTC()
{
    cleanUpRelations();
}

void PlugInLoaderTC::forwardConsoleMsg(const QString& msg)
{
    //#[ operation forwardConsoleMsg(QString)
    itsMainWindow->consoleMsg( msg );
    //#]
}

void PlugInLoaderTC::forwardErrorMsg(const QString& msg)
{
    //#[ operation forwardErrorMsg(QString)
    itsMainWindow->errorMsg( msg );
    //#]
}

QStringList PlugInLoaderTC::getPluginStringList()
{
    //#[ operation getPluginStringList()
    QStringList myPluginList;
    for( int i = 0; i < myCommunications.size(); i++)
    {
        myPluginList.append( myCommunications.at(i)->getName() );
    }
    return myPluginList;
    //#]
}

void PlugInLoaderTC::loadPluginOnAutoStart(const QString& pluginName)
{
    //#[ operation loadPluginOnAutoStart(QString)
    for( int i = 0; i < myCommunications.size(); i++)
    {
        if( pluginName == myCommunications.at(i)->getName() )
        {
            myCommunications.at(i)->initialisation( true );
            activePlugin = myCommunications.at(i);
            return;
        }
    }
    itsMainWindow->errorMsg("Plugin " + pluginName + " Not available. Please reconfigure your Settings.");
    //#]
}

bool PlugInLoaderTC::loadPlugins()
{
    //#[ operation loadPlugins()
    bool foundDll = false;
    QDir pluginsDir(QDir::currentPath());
    pluginsDir.cd( "../pluginsTC" );
    
    foreach( QString fileName, pluginsDir.entryList( QDir::Files ) )
    {
        if( fileName.endsWith(".dll") )
        {
    	    QPluginLoader pluginLoader( pluginsDir.absoluteFilePath( fileName ) );
    	    QObject *plugin = pluginLoader.instance();
    	    if ( plugin )
    	    {
    
    	        IdeCommunication * ideCommunication = qobject_cast<IdeCommunication *>( plugin );
    	
    	        if ( ideCommunication )
    	        {                                               
    
                    myCommunications.append( ideCommunication );              
                    QObject::connect( ideCommunication, SIGNAL( consoleMsg(QString) ), this, SLOT( forwardConsoleMsg(QString) ) );
                    QObject::connect( ideCommunication, SIGNAL( errorMsg(QString) ), this, SLOT( forwardErrorMsg(QString) ) );
                    foundDll = true;
    	        }
                else
                {
                    itsMainWindow->errorMsg( fileName + " can not be loaded!" );
    	        }
    	    }
    	    else
            {
                itsMainWindow->errorMsg( fileName + " can not be loaded!" );
            }
        }
    }
    return foundDll;
    //#]
}

void PlugInLoaderTC::openAutoStartConfigurationDialog(const QString& pluginName)
{
    //#[ operation openAutoStartConfigurationDialog(QString)
    for( int i = 0; i < myCommunications.size(); i++)
    {
        if( pluginName == myCommunications.at(i)->getName() )
        {
            myCommunications.at(i)->showAutoStartConfigurationDialog();
            return;
        }
    }
    itsMainWindow->errorMsg("Plugin " + pluginName + " Not available. Please reconfigure your Settings.");
    //#]
}

void PlugInLoaderTC::openCommunicationList()
{
    //#[ operation openCommunicationList()
    QSettings mySetting("Configuration.ini", QSettings::IniFormat);
    int index = 0;
    mySetting.beginGroup("GlobalConfiguration");
     mySetting.beginGroup("StartUp");
      mySetting.beginGroup("TestConductor");
       if( mySetting.value("lastChoosenItem").isValid() )
       {
           index = mySetting.value("lastChoosenItem").toInt();
       }
        QString selectedConnection;
        bool ok = false;
        QStringList myPluginList = getPluginStringList();
    
        selectedConnection = QInputDialog::getItem( itsMainWindow, "Configure TestConductor Plugin", "Select a Plugin", myPluginList, index, false, &ok, Qt::WindowCloseButtonHint );
    
    
        if ( ok && !selectedConnection.isEmpty() )
        {
            index = myPluginList.indexOf(selectedConnection);
            mySetting.setValue("lastChoosenItem", QString::number( index ));
            activePlugin = myCommunications.at( index );
            activePlugin->showCommunicationConfigurationDialog();
        }
      mySetting.endGroup();
     mySetting.endGroup();
    mySetting.endGroup();
    //#]
}

void PlugInLoaderTC::cleanUpRelations()
{
    if(itsMainWindow != NULL)
        {
            itsMainWindow = NULL;
        }
}

/*********************************************************************
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\PlugInLoaderTC.cpp
*********************************************************************/
