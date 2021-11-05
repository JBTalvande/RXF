/*********************************************************************
	Rhapsody	: 9.0.1 
	Login		: Y9DSYU706
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: TestConductorParser
//!	Generated Date	: Thu, 4, Nov 2021  
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\TestConductorParser.h
*********************************************************************/

#ifndef TestConductorParser_H
#define TestConductorParser_H

#include "DataParser.h"
#include "IParser.h"
class CommandConstructor;

class CommandDestructor;

class MainWindow;

class ModelInstance;

class TestConductorAPI;

//## package LogicLevel::DataTransmission::DataParser

//## class TestConductorParser
class TestConductorParser : public IParser {
private :

    enum TestConductorMessageType {
        versionNumber = 0,
        bufferOverflow = 1,
        errorHandlerReached = 2,
        RTCInfo = 3,
        RTCExit = 4,
        RTCCoverage = 5,
        RTCModelCoverage = 6,
        COMMAND_COUNT = 7
    };
    
    ////    Constructors and destructors    ////

public :

    TestConductorParser();
    
    virtual ~TestConductorParser();
    
    ////    Operations    ////
    
    //## operation analyzeCommand(unsigned char*,unsigned int)
    virtual void analyzeCommand(unsigned char* command, unsigned int commandSize);
    
    //## operation checkCommandStart(unsigned char,char)
    bool checkCommandStart(unsigned char size, char command);
    
    //## operation commandBufferOverflow()
    virtual void commandBufferOverflow();
    
    //## operation commandErrorHandlerReached()
    virtual void commandErrorHandlerReached();
    
    //## operation read4Byte(unsigned char*,int)
    unsigned int read4Byte(unsigned char* data, int startPointer);
    
    //## operation rtcCoverage(unsigned char)
    void rtcCoverage(unsigned char* data);
    
    //## operation rtcExit()
    void rtcExit();
    
    //## operation rtcInfo(unsigned char)
    void rtcInfo(unsigned char* data);
    
    //## operation rtcModelCoverage(unsigned char)
    void rtcModelCoverage(unsigned char* data);
    
    //## operation updateCommands()
    void updateCommands();
    
    ////    Additional operations    ////
    
    inline bool getIsLittleEndian() const
    {
        return isLittleEndian;
    }
    
    inline void setIsLittleEndian(bool p_isLittleEndian)
    {
        isLittleEndian = p_isLittleEndian;
    }
    
    inline TestConductorAPI* getItsTestConductorAPI() const
    {
        return itsTestConductorAPI;
    }
    
    inline void setItsTestConductorAPI(TestConductorAPI* p_TestConductorAPI)
    {
        itsTestConductorAPI = p_TestConductorAPI;
    }

protected :

    void cleanUpRelations();
    
    ////    Attributes    ////

private :

    char commands[COMMAND_COUNT];		//## attribute commands
    
    unsigned char commandsMinimalSize[COMMAND_COUNT];		//## attribute commandsMinimalSize
    
    unsigned char commandsSize[COMMAND_COUNT];		//## attribute commandsSize
    
    bool isLittleEndian;		//## attribute isLittleEndian
    
    ////    Relations and components    ////

protected :

    TestConductorAPI* itsTestConductorAPI;
};

#endif
/*********************************************************************
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\TestConductorParser.h
*********************************************************************/
