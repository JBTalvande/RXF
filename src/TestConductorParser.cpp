/********************************************************************
	Rhapsody	: 9.0.1 
	Login		: Y9DSYU706
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: TestConductorParser
//!	Generated Date	: Thu, 4, Nov 2021  
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\TestConductorParser.cpp
*********************************************************************/

#include "TestConductorParser.h"
#include "CommandConstructor.h"
#include "CommandDestructor.h"
#include "MainWindow.h"
#include "ModelInstance.h"
#include "TestConductorAPI.h"
//## package LogicLevel::DataTransmission::DataParser

//## class TestConductorParser
TestConductorParser::TestConductorParser() : isLittleEndian(true)
{
    itsTestConductorAPI = NULL;
}

TestConductorParser::~TestConductorParser()
{
    cleanUpRelations();
}

void TestConductorParser::analyzeCommand(unsigned char* command, unsigned int commandSize)
{
    //#[ operation analyzeCommand(unsigned char*,unsigned int)
    (void)commandSize;
    switch ( command[ 0 ] )
    {
    
        case RTCInfo:
        {
            rtcInfo( command );
            break;
        }
    
        case RTCCoverage:
        {
            rtcCoverage( command );
            break;
        }
    
        case RTCModelCoverage:
        {
            rtcModelCoverage( command );
            break;
        }
    
        case RTCExit:
        {
            rtcExit( );
            break;
        }
    
        case errorHandlerReached:
        {
            commandErrorHandlerReached( );
            break;
        }
    
        case versionNumber:
        {
            commandNewVersion( command );
            break;
        }
    
        case bufferOverflow:
        {
            commandBufferOverflow( );
            break;
        }
    }
    //#]
}

bool TestConductorParser::checkCommandStart(unsigned char size, char command)
{
    //#[ operation checkCommandStart(unsigned char,char)
    for(int i=0 ;i < COMMAND_COUNT ;i++)
    {
        if( commands[i] == command &&
            ( commandsSize[i]==size || ( commandsSize[i]==255 && commandsMinimalSize[i] <= size ) )
          )
        {
            return true;
        }
    }
    return false;
    //#]
}

void TestConductorParser::commandBufferOverflow()
{
    //#[ operation commandBufferOverflow()
    itsMainWindow->consoleMsg("Send Buffer overflow. Test Data incomplete.");
    //#]
}

void TestConductorParser::commandErrorHandlerReached()
{
    //#[ operation commandErrorHandlerReached()
    itsMainWindow->consoleMsg("Error Handler Reached on Target");
    //#]
}

unsigned int TestConductorParser::read4Byte(unsigned char* data, int startPointer)
{
    //#[ operation read4Byte(unsigned char*,int)
    int value = 0;
    
    if ( isLittleEndian )
    {
        for ( int i = 0; i < 4; i++ )
        {
            value |= ( data[ i + startPointer ] << ( 8 * i ) );
        }
    }
    else
    {
        for ( int i = 0; i < 4; i++ )
        {
            value |= ( data[ i + startPointer ] << ( 8 * (4 - i - 1) ) );
        }
    }
    return value;
    //#]
}

void TestConductorParser::rtcCoverage(unsigned char* data)
{
    //#[ operation rtcCoverage(unsigned char)
    uint i =  read4Byte(data,1);
    uint j =  read4Byte(data,5);
    unsigned char* c =  &data[9];
    for(uint k = 4; k < 10; k++)
    {
        if (c[ k ] == 0)
        {
            QString msg = QString((char*)c) + " " + QString::number(i) + " " + QString::number(j) + "\n";
            itsTestConductorAPI->rtcCoverage( msg );
            break;
        }
    }
    //#]
}

void TestConductorParser::rtcExit()
{
    //#[ operation rtcExit()
    itsTestConductorAPI->rtcExit( );
    //#]
}

void TestConductorParser::rtcInfo(unsigned char* data)
{
    //#[ operation rtcInfo(unsigned char)
    uint e =  read4Byte(data,1);
    uint ln =  read4Byte(data,5);
    uint nr =  read4Byte(data,9);
    itsTestConductorAPI->rtcInfo(e, ln, nr);
    //#]
}

void TestConductorParser::rtcModelCoverage(unsigned char* data)
{
    //#[ operation rtcModelCoverage(unsigned char)
    uint i =  read4Byte(data,1);
    itsTestConductorAPI->rtcModCoverage( QString::number(i) + "\n" );
    //#]
}

void TestConductorParser::updateCommands()
{
    //#[ operation updateCommands()
    
    //RTC Info
    commands[0] = RTCInfo;
    commandsSize[0] = 12;
    
    //RTC Exit
    commands[1] = RTCExit;
    commandsSize[1] = 0;
    
    //RTC Cov
    commands[2] = RTCCoverage;
    commandsSize[2] = 255;
    commandsMinimalSize[2] = 8;
    
    //send Error
    commands[3] = errorHandlerReached;
    commandsSize[3] = 0;
    
    //receive version
    commands[4] = versionNumber;
    commandsSize[4] = 5;
    
    
    //buffer overflow
    commands[5] = bufferOverflow;
    commandsSize[5] = 0;
    
    
    //RTC ModCov
    commands[6] = RTCModelCoverage;
    commandsSize[6] = 4;
    //#]
}

void TestConductorParser::cleanUpRelations()
{
    if(itsTestConductorAPI != NULL)
        {
            itsTestConductorAPI = NULL;
        }
}

/*********************************************************************
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\TestConductorParser.cpp
*********************************************************************/
