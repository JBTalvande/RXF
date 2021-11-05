/********************************************************************
	Rhapsody	: 9.0.1 
	Login		: Y9DSYU706
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: ReceivedCommandsLogger
//!	Generated Date	: Thu, 4, Nov 2021  
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\ReceivedCommandsLogger.cpp
*********************************************************************/

#include "ReceivedCommandsLogger.h"
#include "CommandConstructor.h"
#include "CommandDestructor.h"
#include "CommandEventCreated.h"
#include "CommandEventEndDispatch.h"
#include "CommandEventStartDispatch.h"
#include "CommandKeyValueAdapterRegistry.h"
#include "CommandList.h"
#include "CommandListExporter.h"
#include "CommandListImporter.h"
#include "CommandOperationCall.h"
#include "CommandsExporter.h"
#include "CommandStringAdapterRegistry.h"
#include "CommandTraceEvent.h"
#include "MainWindow.h"
#include "MessageLogger.h"
#include "ModelInstance.h"
#include "RemoteControll.h"
#include "SequenceDiagram.h"
#include "TargetInformation.h"
#include "TargetList.h"
#include "TimingDiagram.h"
//## package LogicLevel::Logging

//## class ReceivedCommandsLogger
ReceivedCommandsLogger::ReceivedCommandsLogger()
{
    itsActiveRootCommandList = NULL;
    itsCommandKeyValueAdapterRegistry = NULL;
    itsCommandStringAdapterRegistry = NULL;
    itsMainWindow = NULL;
    itsMessageLogger = NULL;
    itsOldRootCommandList = NULL;
    itsRemoteControll = NULL;
}

ReceivedCommandsLogger::~ReceivedCommandsLogger()
{
    cleanUpRelations();
}

void ReceivedCommandsLogger::addCommandToActiveList(Command* command)
{
    //#[ operation addCommandToActiveList(Command)
    if( command->getItsTargetInformation()->getInReset() )
    {
        if( itsOldRootCommandList != NULL )
        {
            itsOldRootCommandList->addCommand( command, true );
        }
        else
        {
            delete command;
        }
    }
    else
    {
        if( itsActiveRootCommandList != NULL )
        {
            itsActiveRootCommandList->addCommand( command, true );
        }
        else
        {
            delete command;
        }
    }
    //#]
}

void ReceivedCommandsLogger::bufferOverflow(TargetInformation* target)
{
    //#[ operation bufferOverflow(TargetInformation)
    Command* myBufferOverflowCommand = new Command( target );
    myBufferOverflowCommand->setCommandIdentifier( Command::bufferOverflowCommand );
    addCommandToActiveList( myBufferOverflowCommand );
    //#]
}

void ReceivedCommandsLogger::createNewCommandListByReset()
{
    //#[ operation createNewCommandListByReset()
    newDataSet( true );
    //#]
}

void ReceivedCommandsLogger::errorHandlerReached(TargetInformation* target)
{
    //#[ operation errorHandlerReached(TargetInformation)
    Command* myErrorHandlerReachedCommand = new Command( target );
    myErrorHandlerReachedCommand->setCommandIdentifier( Command::errorHandlerReachedCommand );
    addCommandToActiveList( myErrorHandlerReachedCommand );
    //#]
}

void ReceivedCommandsLogger::loadViewData(const QString& filePath)
{
    //#[ operation loadViewData(QString)
    CommandListImporter cmdListImporter;
    cmdListImporter.setTargetFileName(filePath);
    cmdListImporter.setItsMessageLogger(this->itsMessageLogger);
    cmdListImporter.doImport();
    
    CommandList* loadedCommandList = cmdListImporter.getCommandList();
    if(loadedCommandList != NULL)
    {
        itsMainWindow->loadCommandList(loadedCommandList);
    }
    //#]
}

void ReceivedCommandsLogger::newDataSet(bool newRootCommandList)
{
    //#[ operation newDataSet(bool)
    if( newRootCommandList || itsActiveRootCommandList == NULL )
    {
        itsOldRootCommandList = itsActiveRootCommandList;
        itsActiveRootCommandList = new CommandList(*TargetList::getGlobalList());
    
        itsMainWindow->getItsSequenceDiagram()->setItsCommandList( itsActiveRootCommandList );
        itsMainWindow->getItsTimingDiagram()->setItsCommandList( itsActiveRootCommandList );
    
        itsMainWindow->newCommandList( itsActiveRootCommandList );
        itsRemoteControll->updateCommandList(*itsActiveRootCommandList);
    }
    //#]
}

void ReceivedCommandsLogger::newObjectCreated(ModelInstance* instance, TargetInformation* target)
{
    //#[ operation newObjectCreated(ModelInstance,TargetInformation)
    if( itsActiveRootCommandList != NULL )
    {
        CommandConstructor *constructorCommand = new CommandConstructor( instance, target );
        addCommandToActiveList( constructorCommand );
    }
    //#]
}

void ReceivedCommandsLogger::objectDestoyed(ModelInstance* instance, TargetInformation* target)
{
    //#[ operation objectDestoyed(ModelInstance,TargetInformation)
    if( itsActiveRootCommandList != NULL )
    {
        CommandDestructor *destructorCommand = new CommandDestructor( instance, target );
        addCommandToActiveList( destructorCommand );
    }
    //#]
}

void ReceivedCommandsLogger::saveActiveRootCommandList(const QString& filePath) const
{
    //#[ operation saveActiveRootCommandList(QString) const
    this->saveCommandList(filePath, *this->itsActiveRootCommandList);
    //#]
}

void ReceivedCommandsLogger::saveCommandList(const QString& filePath, const CommandList& commandList) const
{
    //#[ operation saveCommandList(QString,CommandList) const
    CommandsExporter exporter;
    exporter.setCommands(commandList.getCommands().toList());
    exporter.setItsCommandStringAdapterRegistry(this->itsCommandStringAdapterRegistry);
    exporter.setTargetFileName(filePath);
    exporter.setItsMessageLogger(this->itsMessageLogger);
    exporter.doExport();
    //#]
}

void ReceivedCommandsLogger::saveViewData(const QString& filePath, CommandList* commandList)
{
    //#[ operation saveViewData(QString,CommandList)
    CommandListExporter cmdListExporter;
    cmdListExporter.setTargetFileName(filePath);
    cmdListExporter.setItsMessageLogger(this->itsMessageLogger);
    if(commandList == NULL)
    {
        commandList = this->itsActiveRootCommandList;
    }
    cmdListExporter.setCommandList(commandList);
    cmdListExporter.doExport();
    //#]
}

void ReceivedCommandsLogger::unknownTarget(const QString& command, unsigned int targetId)
{
    //#[ operation unknownTarget(QString,unsigned int)
    itsMainWindow->errorMsg("Command \""+ command + "\" received for unknown target id ." + QString::number(targetId));
    //#]
}

void ReceivedCommandsLogger::unrecognizedEvent(unsigned int eventID, Command::commandType eventType)
{
    //#[ operation unrecognizedEvent(unsigned int,commandType)
    if( eventType == Command::eventEndDispatchCommand )
    {
        itsMainWindow->errorMsg("Event end dispatch receivend with no previous event start dispatch received with ID: " + QString::number(eventID));
    }
    if( eventType == Command::eventStartDispatchCommand )
    {
        itsMainWindow->errorMsg("Event start dispatch receivend with no previous create event received with ID: " + QString::number(eventID));
    }
    //#]
}

void ReceivedCommandsLogger::cleanUpRelations()
{
    if(itsActiveRootCommandList != NULL)
        {
            itsActiveRootCommandList = NULL;
        }
    if(itsCommandKeyValueAdapterRegistry != NULL)
        {
            itsCommandKeyValueAdapterRegistry = NULL;
        }
    if(itsCommandStringAdapterRegistry != NULL)
        {
            itsCommandStringAdapterRegistry = NULL;
        }
    if(itsMainWindow != NULL)
        {
            itsMainWindow = NULL;
        }
    if(itsMessageLogger != NULL)
        {
            itsMessageLogger = NULL;
        }
    if(itsOldRootCommandList != NULL)
        {
            itsOldRootCommandList = NULL;
        }
    if(itsRemoteControll != NULL)
        {
            itsRemoteControll = NULL;
        }
}

/*********************************************************************
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\ReceivedCommandsLogger.cpp
*********************************************************************/
