/*********************************************************************
	Rhapsody	: 9.0.1 
	Login		: Y9DSYU706
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: IParser
//!	Generated Date	: Thu, 4, Nov 2021  
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\IParser.h
*********************************************************************/

#ifndef IParser_H
#define IParser_H

#include "ParserInterface.h"
#include "Receiver.h"
class CommandConstructor;

class CommandDestructor;

class MainWindow;

class ModelInstance;

class ReceivedCommandsLogger;

//## package LogicLevel::DataTransmission::ParserInterface

//## class IParser
class IParser {
public :

    #define RECEIVE_BUFFER_SIZE 0x400000
    ////    Operations    ////
    
    //## operation addByte(char)
    inline void addByte(char aByte);
    
    //## operation analyzeCommand(unsigned char*,unsigned int)
    virtual void analyzeCommand(unsigned char* data, unsigned int commandSize) = 0;
    
    //## operation analyzeStream(unsigned int)
    void analyzeStream(unsigned int bytesPerStep);
    
    //## operation checkCommandStart(unsigned char,char)
    virtual bool checkCommandStart(unsigned char size, char command) = 0;
    
    //## operation commandNewVersion(unsigned char*)
    virtual void commandNewVersion(unsigned char* command);
    
    //## operation resetParserPointer()
    static void resetParserPointer();
    
    //## operation shiftToCommand()
    bool shiftToCommand();
    
    //## operation updateCommands()
    virtual void updateCommands() = 0;
    
    ////    Additional operations    ////
    
    inline static MainWindow* getItsMainWindow()
    {
        return itsMainWindow;
    }
    
    inline static void setItsMainWindow(MainWindow* p_MainWindow)
    {
        itsMainWindow = p_MainWindow;
    }
    
    inline static ReceivedCommandsLogger* getItsReceivedCommandsLogger()
    {
        return itsReceivedCommandsLogger;
    }
    
    inline static void setItsReceivedCommandsLogger(ReceivedCommandsLogger* p_ReceivedCommandsLogger)
    {
        itsReceivedCommandsLogger = p_ReceivedCommandsLogger;
    }
    
    ////    Attributes    ////

protected :

    static unsigned int readPointer;		//## attribute readPointer
    
    static char receiveBuffer[RECEIVE_BUFFER_SIZE];		//## attribute receiveBuffer
    
    static unsigned int writePointer;		//## attribute writePointer
    
    ////    Relations and components    ////
    
    static MainWindow* itsMainWindow;
    
    static ReceivedCommandsLogger* itsReceivedCommandsLogger;
};

inline void IParser::addByte(char aByte)
{
    //#[ operation addByte(char)
    receiveBuffer[ writePointer ] = aByte;
    writePointer = (writePointer + 1) % RECEIVE_BUFFER_SIZE;
    //#]
}

#endif
/*********************************************************************
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\IParser.h
*********************************************************************/
