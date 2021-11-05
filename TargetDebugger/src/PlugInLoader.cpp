/********************************************************************
	Rhapsody	: 9.0.1 
	Login		: Y9DSYU706
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: PlugInLoader
//!	Generated Date	: Thu, 4, Nov 2021  
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\PlugInLoader.cpp
*********************************************************************/

#include "PlugInLoader.h"
#include "MainWindow.h"
#include <QSettings.h>
#include "Sender.h"
#include <QPlugInLoader>
#include <QString>
#include <QDir>
#include <QInputDialog>
//## package Plugins::CommunicationPlugin

//## class PlugInLoader
PlugInLoader::PlugInLoader()
{
    itsMainWindow = NULL;
    itsSender = NULL;
    //#[ operation PlugInLoader()
    //#]
}

PlugInLoader::~PlugInLoader()
{
    //#[ operation ~PlugInLoader()
    foreach (auto com, myCommunications) {
        QObject::disconnect( com, SIGNAL( consoleMsg(QString) ), this, SLOT( forwardConsoleMsg(QString) ) );
        QObject::disconnect( com, SIGNAL( errorMsg(QString) ), this, SLOT( forwardErrorMsg(QString) ) );
        QObject::disconnect( com, SIGNAL( targetCommunicationEstablished() ), this, SLOT(targetCommunicationEstablished()) );
    }
    //#]
    cleanUpRelations();
}

void PlugInLoader::forwardConsoleMsg(const QString& msg)
{
    //#[ operation forwardConsoleMsg(QString)
    itsMainWindow->consoleMsg( msg );
    //#]
}

void PlugInLoader::forwardErrorMsg(const QString& msg)
{
    //#[ operation forwardErrorMsg(QString)
    itsMainWindow->errorMsg( msg );
    //#]
}

QStringList PlugInLoader::getPluginStringList()
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

void PlugInLoader::loadPluginOnAutoStart(const QString& pluginName)
{
    //#[ operation loadPluginOnAutoStart(QString)
    for( int i = 0; i < myCommunications.size(); i++)
    {
        if( pluginName == myCommunications.at(i)->getName() )
        {
            itsSender->setItsTargetCommunication( myCommunications.at(i) );
            myCommunications.at(i)->initialisation( true );
            return;
        }
    }
    itsMainWindow->errorMsg("Plugin " + pluginName + " Not available. Please reconfigure your Settings.");
    //#]
}

bool PlugInLoader::loadPlugins()
{
    //#[ operation loadPlugins()
    bool foundDll = false;
    QDir pluginsDir(QDir::currentPath());
    pluginsDir.cd( "../plugins" );
    
    foreach( QString fileName, pluginsDir.entryList( QDir::Files ) )
    {
        if( fileName.endsWith(".dll") )
        {
    	    QPluginLoader pluginLoader( pluginsDir.absoluteFilePath( fileName ) );
    	    QObject *plugin = pluginLoader.instance();
    	    if ( plugin )
    	    {
    
    	        TargetCommunication * targetCommunication = qobject_cast<TargetCommunication *>( plugin );
    	
    	        if ( targetCommunication )
    	        {                                               
                    targetCommunication->setReceiveOperationCallBackPointer( &Receiver::receiveData );
                    myCommunications.append( targetCommunication );              
                    QObject::connect( targetCommunication, SIGNAL( consoleMsg(QString) ), this, SLOT( forwardConsoleMsg(QString) ) );
                    QObject::connect( targetCommunication, SIGNAL( errorMsg(QString) ), this, SLOT( forwardErrorMsg(QString) ) );
                    QObject::connect( targetCommunication, SIGNAL( targetCommunicationEstablished() ), this, SLOT(targetCommunicationEstablished()) );
                    foundDll = true;
    	        }
                else
                {
                    itsMainWindow->errorMsg( fileName + " can not be loaded!" );
    	        }
    	    }
        }
    }
    return foundDll;
    //#]
}

void PlugInLoader::openAutoStartConfigurationDialog(const QString& pluginName)
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

void PlugInLoader::openCommunicationList()
{
    //#[ operation openCommunicationList()
    QSettings mySetting("Configuration.ini", QSettings::IniFormat);
    int index = 0;
    mySetting.beginGroup("GlobalConfiguration");
     mySetting.beginGroup("StartUp");
      mySetting.beginGroup("Plugin");
       if( mySetting.value("lastChoosenItem").isValid() )
       {
           index = mySetting.value("lastChoosenItem").toInt();
       }
    QString selectedConnection;
    bool ok = false;
    QStringList myPluginList = getPluginStringList();
    selectedConnection = QInputDialog::getItem( itsMainWindow, "Configure connection", "Select a connection", myPluginList, index, false, &ok, Qt::WindowCloseButtonHint  );
    
    if ( ok && !selectedConnection.isEmpty() )
    {
        index = myPluginList.indexOf(selectedConnection);
        mySetting.setValue("lastChoosenItem", QString::number( index ));
        TargetCommunication *myNewTargetCommunication = myCommunications.at( index );
        myNewTargetCommunication->showCommunicationConfigurationDialog();
        itsSender->setItsTargetCommunication( myNewTargetCommunication );
    }
    mySetting.endGroup();
    mySetting.endGroup();
    mySetting.endGroup();
    //#]
}

void PlugInLoader::targetCommunicationEstablished()
{
    //#[ operation targetCommunicationEstablished()
    itsMainWindow->getUi()->actionBreakpoinMenue->setEnabled( true );
    itsMainWindow->getUi()->actionInjectEvent->setEnabled( true );
    itsMainWindow->getUi()->actionResume_RXF->setEnabled( true );
    itsMainWindow->getUi()->actionSuspend_RXF->setEnabled( true );
    //#]
}

void PlugInLoader::cleanUpRelations()
{
    if(itsMainWindow != NULL)
        {
            itsMainWindow = NULL;
        }
    if(itsSender != NULL)
        {
            itsSender = NULL;
        }
}

/*********************************************************************
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\PlugInLoader.cpp
*********************************************************************/
