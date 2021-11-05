/*********************************************************************
	Rhapsody	: 9.0.1 
	Login		: Y9DSYU706
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: MultiParser
//!	Generated Date	: Thu, 4, Nov 2021  
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\MultiParser.h
*********************************************************************/

#ifndef MultiParser_H
#define MultiParser_H

#include "DataParser.h"
#include "SingleParser.h"
class CommandConstructor;

class CommandDestructor;

class CommandEventCreated;

class CommandEventEndDispatch;

class CommandEventStartDispatch;

class CommandIntVal;

class CommandOperationCall;

class CommandTraceEvent;

class MainWindow;

class ModelEventArgumentType;

class ModelInstance;

class ReceivedCommandsLogger;

class TargetInformation;

class TargetList;

//## package LogicLevel::DataTransmission::DataParser

//## class MultiParser
class MultiParser : public SingleParser {
    ////    Constructors and destructors    ////
    
public :

    //## operation MultiParser()
    MultiParser();
    
    virtual ~MultiParser();
    
    ////    Operations    ////
    
    //## operation checkCommandStart(unsigned char,char)
    virtual bool checkCommandStart(unsigned char size, char command);
    
    //## operation commandBufferOverflow(unsigned char*)
    virtual void commandBufferOverflow(unsigned char* command);
    
    //## operation commandErrorHandlerReached(unsigned char*)
    virtual void commandErrorHandlerReached(unsigned char* command);
    
    //## operation commandEventEndDispatch(unsigned char*)
    void commandEventEndDispatch(unsigned char* command);
    
    //## operation commandEventPutToMessageQueue(unsigned char*)
    void commandEventPutToMessageQueue(unsigned char* command);
    
    //## operation commandEventStartDispatch(unsigned char*)
    void commandEventStartDispatch(unsigned char* command);
    
    //## operation commandIntVal(unsigned char*)
    void commandIntVal(unsigned char* command);
    
    //## operation commandNewVersion(unsigned char*)
    void commandNewVersion(unsigned char* command);
    
    //## operation commandObjectAttributRequest(unsigned char*,unsigned int)
    void commandObjectAttributRequest(unsigned char* command, unsigned int commandSize);
    
    //## operation commandObjectCreated(unsigned char*)
    virtual void commandObjectCreated(unsigned char* command);
    
    //## operation commandObjectDestroyed(unsigned char*)
    virtual void commandObjectDestroyed(unsigned char* command);
    
    //## operation commandObjectStateRequest(unsigned char*)
    void commandObjectStateRequest(unsigned char* command);
    
    //## operation commandOperationCalled(unsigned char*)
    void commandOperationCalled(unsigned char* command);
    
    //## operation commandStateSizeInformation(unsigned char*)
    void commandStateSizeInformation(unsigned char* command);
    
    //## operation commandSyncTime(unsigned char*)
    virtual void commandSyncTime(unsigned char* command);
    
    //## operation commandTimeOutEvent(unsigned char*)
    void commandTimeOutEvent(unsigned char* command);
    
    //## operation commandTimeOutTrace(unsigned char*)
    void commandTimeOutTrace(unsigned char* command);
    
    //## operation commandTimeReset(unsigned char*)
    virtual void commandTimeReset(unsigned char* command);
    
    //## operation commandTraceEvent(unsigned char*)
    void commandTraceEvent(unsigned char* command);
    
    //## operation commandTypeSizes(unsigned char*)
    void commandTypeSizes(unsigned char* command);
    
    //## operation read2Byte(unsigned char*,int,TargetInformation)
    unsigned int read2Byte(unsigned char* data, int startPointer, TargetInformation* target);
    
    //## operation read4Byte(unsigned char*,int,TargetInformation)
    unsigned int read4Byte(unsigned char* data, int startPointer, TargetInformation* target);
    
    //## operation readAddress(unsigned char*,int,TargetInformation)
    uint64_t readAddress(unsigned char* data, int startPointer, TargetInformation* target);
    
    //## operation updateCommands(TargetInformation)
    virtual void updateCommands(TargetInformation* target);
};

#endif
/*********************************************************************
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\MultiParser.h
*********************************************************************/
