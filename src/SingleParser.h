/*********************************************************************
	Rhapsody	: 9.0.1 
	Login		: Y9DSYU706
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: SingleParser
//!	Generated Date	: Thu, 4, Nov 2021  
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\SingleParser.h
*********************************************************************/

#ifndef SingleParser_H
#define SingleParser_H

#include "DataParser.h"
#include <QList>
#include "Command.h"
#include "CommandEventTripletData.h"
#include "IParser.h"
#include "ModelEventArgumentType.h"
#include "ReceivedEventParameter.h"
#include <QStandardItem>
class CommandConstructor;

class CommandDestructor;

class CommandEventCreated;

class CommandEventEndDispatch;

class CommandEventStartDispatch;

class CommandIntVal;

class CommandOperationCall;

class CommandTraceEvent;

class MainWindow;

class ModelEventType;

class ModelInstance;

class ReceivedCommandsLogger;

class RemoteControll;

class TargetInformation;

//## package LogicLevel::DataTransmission::DataParser

//## class SingleParser
class SingleParser : public IParser {
protected :

    enum AnimationMessageType {
        versionNumber = 0,
        bufferOverflow = 1,
        errorHandlerReached = 2,
        stateSizeInformation = 3,
        typeSizes = 4,
        objectAttributRequest = 5,
        objectStateRequest = 6,
        objectCreated = 7,
        objectDestroyed = 8,
        eventPutToMessageQueue = 9,
        eventStartDispatch = 10,
        eventEndDispatch = 11,
        timeOutEventStart = 12,
        operationCalled = 13,
        eventTrace = 14,
        timeOffset = 15,
        intValue = 16,
        traceTimeout = 17,
        timeReset = 18,
        targetConsoleMessage = 19,
        COMMAND_COUNT = 20
    };
    
    ////    Constructors and destructors    ////

public :

    //## operation SingleParser()
    SingleParser();
    
    virtual ~SingleParser();
    
    ////    Operations    ////
    
    //## operation analyzeCommand(unsigned char*,unsigned int)
    virtual void analyzeCommand(unsigned char* command, unsigned int commandSize);
    
    //## operation checkCommandStart(unsigned char,char)
    virtual bool checkCommandStart(unsigned char size, char command);
    
    //## operation commandBufferOverflow()
    virtual void commandBufferOverflow();
    
    //## operation commandErrorHandlerReached()
    virtual void commandErrorHandlerReached();
    
    //## operation commandEventEndDispatch(unsigned char*)
    virtual void commandEventEndDispatch(unsigned char* command);
    
    //## operation commandEventPutToMessageQueue(unsigned char*)
    virtual void commandEventPutToMessageQueue(unsigned char* command);
    
    //## operation commandEventStartDispatch(unsigned char*)
    virtual void commandEventStartDispatch(unsigned char* command);
    
    //## operation commandIntVal(unsigned char*)
    virtual void commandIntVal(unsigned char* command);
    
    //## operation commandObjectAttributRequest(unsigned char*,unsigned int)
    virtual void commandObjectAttributRequest(unsigned char* command, unsigned int commandSize);
    
    //## operation commandObjectCreated(unsigned char*)
    virtual void commandObjectCreated(unsigned char* command);
    
    //## operation commandObjectDestroyed(unsigned char*)
    virtual void commandObjectDestroyed(unsigned char* command);
    
    //## operation commandObjectStateRequest(unsigned char*)
    virtual void commandObjectStateRequest(unsigned char* command);
    
    //## operation commandOperationCalled(unsigned char*)
    virtual void commandOperationCalled(unsigned char* command);
    
    //## operation commandStateSizeInformation(unsigned char*)
    virtual void commandStateSizeInformation(unsigned char* command);
    
    //## operation commandSyncTime(unsigned char*)
    virtual void commandSyncTime(unsigned char* command);
    
    //## operation commandTargetMessage(unsigned char*,unsigned int)
    virtual void commandTargetMessage(unsigned char* command, unsigned int commandSize);
    
    //## operation commandTimeOutEvent(unsigned char*)
    virtual void commandTimeOutEvent(unsigned char* command);
    
    //## operation commandTimeOutTrace(unsigned char*)
    virtual void commandTimeOutTrace(unsigned char* command);
    
    //## operation commandTimeReset(unsigned char*)
    virtual void commandTimeReset(unsigned char* command);
    
    //## operation commandTraceEvent(unsigned char*)
    virtual void commandTraceEvent(unsigned char* command);
    
    //## operation commandTypeSizes(unsigned char*)
    virtual void commandTypeSizes(unsigned char* command);
    
    //## operation findPreviousEvent(unsigned int,commandType)
    virtual CommandEventTripletData* findPreviousEvent(unsigned int eventID, Command::commandType eventType);
    
    //## operation read2Byte(unsigned char*,int)
    unsigned int read2Byte(unsigned char* data, int startPointer);
    
    //## operation read4Byte(unsigned char*,int)
    unsigned int read4Byte(unsigned char* data, int startPointer);
    
    //## operation readAddress(unsigned char*,int)
    uint64_t readAddress(unsigned char* data, int startPointer);
    
    //## operation readReceivedEventParameters(unsigned char,int,ModelEventType,TargetInformation)
    QList<ReceivedEventParameter*> readReceivedEventParameters(unsigned char* data, int startOffset, const ModelEventType& eventType, const TargetInformation& myTarget = *itsTargetInformation);
    
    //## operation readState(unsigned char*,unsigned int,TargetInformation)
    unsigned int readState(unsigned char* data, unsigned int position, const TargetInformation& target = *itsTargetInformation);
    
    //## operation updateCommands()
    virtual void updateCommands();

protected :

    // reads the state names for the given command regarding the state machine of the given instance
    //## operation readStateNames(unsigned char,ModelInstance,TargetInformation)
    QString readStateNames(unsigned char* command, const ModelInstance* destinationInstance, const TargetInformation& myTarget = *itsTargetInformation);
    
    ////    Additional operations    ////

public :

    inline static bool getProcessConstructorCalls()
    {
        return processConstructorCalls;
    }
    
    inline static void setProcessConstructorCalls(bool p_processConstructorCalls)
    {
        processConstructorCalls = p_processConstructorCalls;
    }
    
    inline static bool getProcessDestructorCalls()
    {
        return processDestructorCalls;
    }
    
    inline static void setProcessDestructorCalls(bool p_processDestructorCalls)
    {
        processDestructorCalls = p_processDestructorCalls;
    }
    
    inline ReceivedEventParameter* getBrokenReceivedEventParameter() const
    {
        return (ReceivedEventParameter*) &brokenReceivedEventParameter;
    }
    
    inline ModelEventArgumentType* getItsModelEventArgumentType() const
    {
        return (ModelEventArgumentType*) &itsModelEventArgumentType;
    }
    
    inline RemoteControll* getItsRemoteControll() const
    {
        return itsRemoteControll;
    }
    
    inline void setItsRemoteControll(RemoteControll* p_RemoteControll)
    {
        itsRemoteControll = p_RemoteControll;
    }
    
    inline static TargetInformation* getItsTargetInformation()
    {
        return itsTargetInformation;
    }
    
    inline static void setItsTargetInformation(TargetInformation* p_TargetInformation)
    {
        itsTargetInformation = p_TargetInformation;
    }

protected :

    void initRelations();
    
    void cleanUpRelations();
    
    ////    Attributes    ////
    
    char commands[COMMAND_COUNT];		//## attribute commands
    
    unsigned char commandsMinimalSize[COMMAND_COUNT];		//## attribute commandsMinimalSize
    
    unsigned char commandsSize[COMMAND_COUNT];		//## attribute commandsSize
    
    unsigned int parallelStateCount;		//## attribute parallelStateCount
    
    static bool processConstructorCalls;		//## attribute processConstructorCalls
    
    static bool processDestructorCalls;		//## attribute processDestructorCalls
    
    int stateSize;		//## attribute stateSize
    
    QList<CommandEventTripletData*> temporaryEventList;		//## attribute temporaryEventList
    
    ////    Relations and components    ////
    
    ReceivedEventParameter brokenReceivedEventParameter;
    
    ModelEventArgumentType itsModelEventArgumentType;
    
    RemoteControll* itsRemoteControll;

private :

    static TargetInformation* itsTargetInformation;
};

#endif
/*********************************************************************
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\SingleParser.h
*********************************************************************/
