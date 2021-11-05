/*********************************************************************
	Rhapsody	: 9.0.1 
	Login		: Y9DSYU706
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: ReceivedCommandsLogger
//!	Generated Date	: Thu, 4, Nov 2021  
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\ReceivedCommandsLogger.h
*********************************************************************/

#ifndef ReceivedCommandsLogger_H
#define ReceivedCommandsLogger_H

#include "Logging.h"
#include "Command.h"
#include <QObject>
class CommandConstructor;

class CommandDestructor;

class CommandEventCreated;

class CommandEventEndDispatch;

class CommandEventStartDispatch;

class CommandKeyValueAdapterRegistry;

class CommandList;

class CommandListExporter;

class CommandListImporter;

class CommandOperationCall;

class CommandStringAdapterRegistry;

class CommandTraceEvent;

class CommandsExporter;

class MainWindow;

class MessageLogger;

class ModelInstance;

class RemoteControll;

class SequenceDiagram;

class TargetInformation;

class TargetList;

class TimingDiagram;

//## package LogicLevel::Logging

//## class ReceivedCommandsLogger
class ReceivedCommandsLogger : public QObject {
Q_OBJECT
    ////    Constructors and destructors    ////
    
public :

    ReceivedCommandsLogger();
    
    ~ReceivedCommandsLogger();
    
    ////    Operations    ////
    
    //## operation addCommandToActiveList(Command)
    void addCommandToActiveList(Command* command);
    
    //## operation bufferOverflow(TargetInformation)
    void bufferOverflow(TargetInformation* target);
    
    //## operation createNewCommandListByReset()
    Q_SLOT void createNewCommandListByReset();
    
    //## operation errorHandlerReached(TargetInformation)
    void errorHandlerReached(TargetInformation* target);
    
    //## operation loadViewData(QString)
    Q_SLOT void loadViewData(const QString& filePath);
    
    //## operation newDataSet(bool)
    void newDataSet(bool newRootCommandList);
    
    //## operation newObjectCreated(ModelInstance,TargetInformation)
    void newObjectCreated(ModelInstance* instance, TargetInformation* target);
    
    //## operation objectDestoyed(ModelInstance,TargetInformation)
    void objectDestoyed(ModelInstance* instance, TargetInformation* target);
    
    //## operation saveActiveRootCommandList(QString) const
    Q_SLOT void saveActiveRootCommandList(const QString& filePath) const;
    
    //## operation saveCommandList(QString,CommandList) const
    Q_SLOT void saveCommandList(const QString& filePath, const CommandList& commandList) const;
    
    //## operation saveViewData(QString,CommandList)
    Q_SLOT void saveViewData(const QString& filePath, CommandList* commandList);
    
    //## operation unknownTarget(QString,unsigned int)
    void unknownTarget(const QString& command, unsigned int targetId);
    
    //## operation unrecognizedEvent(unsigned int,commandType)
    void unrecognizedEvent(unsigned int eventID, Command::commandType eventType);
    
    ////    Additional operations    ////
    
    inline CommandList* getItsActiveRootCommandList() const
    {
        return itsActiveRootCommandList;
    }
    
    inline void setItsActiveRootCommandList(CommandList* p_CommandList)
    {
        itsActiveRootCommandList = p_CommandList;
    }
    
    inline CommandKeyValueAdapterRegistry* getItsCommandKeyValueAdapterRegistry() const
    {
        return itsCommandKeyValueAdapterRegistry;
    }
    
    inline void setItsCommandKeyValueAdapterRegistry(CommandKeyValueAdapterRegistry* p_CommandKeyValueAdapterRegistry)
    {
        itsCommandKeyValueAdapterRegistry = p_CommandKeyValueAdapterRegistry;
    }
    
    inline CommandStringAdapterRegistry* getItsCommandStringAdapterRegistry() const
    {
        return itsCommandStringAdapterRegistry;
    }
    
    inline void setItsCommandStringAdapterRegistry(CommandStringAdapterRegistry* p_CommandStringAdapterRegistry)
    {
        itsCommandStringAdapterRegistry = p_CommandStringAdapterRegistry;
    }
    
    inline MainWindow* getItsMainWindow() const
    {
        return itsMainWindow;
    }
    
    inline void setItsMainWindow(MainWindow* p_MainWindow)
    {
        itsMainWindow = p_MainWindow;
    }
    
    inline MessageLogger* getItsMessageLogger() const
    {
        return itsMessageLogger;
    }
    
    inline void setItsMessageLogger(MessageLogger* p_MessageLogger)
    {
        itsMessageLogger = p_MessageLogger;
    }
    
    inline CommandList* getItsOldRootCommandList() const
    {
        return itsOldRootCommandList;
    }
    
    inline void setItsOldRootCommandList(CommandList* p_CommandList)
    {
        itsOldRootCommandList = p_CommandList;
    }
    
    inline RemoteControll* getItsRemoteControll() const
    {
        return itsRemoteControll;
    }
    
    inline void setItsRemoteControll(RemoteControll* p_RemoteControll)
    {
        itsRemoteControll = p_RemoteControll;
    }

protected :

    void cleanUpRelations();
    
    ////    Relations and components    ////
    
    CommandList* itsActiveRootCommandList;
    
    CommandKeyValueAdapterRegistry* itsCommandKeyValueAdapterRegistry;
    
    CommandStringAdapterRegistry* itsCommandStringAdapterRegistry;
    
    MainWindow* itsMainWindow;
    
    MessageLogger* itsMessageLogger;
    
    CommandList* itsOldRootCommandList;
    
    RemoteControll* itsRemoteControll;
};

#endif
/*********************************************************************
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\ReceivedCommandsLogger.h
*********************************************************************/
