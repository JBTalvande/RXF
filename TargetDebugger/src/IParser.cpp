/********************************************************************
	Rhapsody	: 9.0.1 
	Login		: Y9DSYU706
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: IParser
//!	Generated Date	: Thu, 4, Nov 2021  
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\IParser.cpp
*********************************************************************/

#include "IParser.h"
#include "CommandConstructor.h"
#include "CommandDestructor.h"
#include "MainWindow.h"
#include "ModelInstance.h"
#include "ReceivedCommandsLogger.h"
//## package LogicLevel::DataTransmission::ParserInterface

//## class IParser
unsigned int IParser::readPointer(0);

char IParser::receiveBuffer[RECEIVE_BUFFER_SIZE];

unsigned int IParser::writePointer(0);

void IParser::analyzeStream(unsigned int bytesPerStep)
{
    //#[ operation analyzeStream(unsigned int)
    unsigned int commandSize;
    unsigned int counter = 0;
    unsigned int oldReadPointer = -1;
    while( readPointer != writePointer && oldReadPointer != readPointer && counter < bytesPerStep)
    {
        oldReadPointer = readPointer;
        if( shiftToCommand())
        {
            if( ( readPointer + (unsigned char)receiveBuffer[readPointer] + 2 ) < RECEIVE_BUFFER_SIZE )
            {
                commandSize = (unsigned char)receiveBuffer[readPointer];
                analyzeCommand((unsigned char*)&receiveBuffer[readPointer + 1], commandSize);
            }
            else
            {
                char *miniBuffer = new char[ (unsigned char)receiveBuffer[readPointer] + 2 ];
                for(int i = 0; i < (unsigned char)receiveBuffer[readPointer] + 2; i++){
                    miniBuffer[i] = receiveBuffer[ ( readPointer + i + 1 ) % RECEIVE_BUFFER_SIZE];
                }
                commandSize = (unsigned char)receiveBuffer[readPointer];
                analyzeCommand((unsigned char*)miniBuffer, commandSize);
            }
            if( receiveBuffer[readPointer + 1] == 0 )
            {
                counter = bytesPerStep;
            }
            readPointer = ( readPointer + (unsigned char)receiveBuffer[readPointer] + 2 ) % RECEIVE_BUFFER_SIZE;
        }
    
        counter++;
    }
    //#]
}

void IParser::commandNewVersion(unsigned char* command)
{
    //#[ operation commandNewVersion(unsigned char*)
    Receiver::setParser( command[4] );
    
    itsReceivedCommandsLogger->newDataSet( true );
    
    //#]
}

void IParser::resetParserPointer()
{
    //#[ operation resetParserPointer()
    readPointer = 0; 
    writePointer =0;
    //#]
}

bool IParser::shiftToCommand()
{
    //#[ operation shiftToCommand()
    volatile static int old = 0;
    //Command to small
    if( ( ( writePointer + RECEIVE_BUFFER_SIZE - readPointer) % RECEIVE_BUFFER_SIZE ) < 2){
        return false;
    }
    //check if the start of the buffer is a valid command start ... otherwise return false
    while(!checkCommandStart(receiveBuffer[readPointer],receiveBuffer[(readPointer + 1) % RECEIVE_BUFFER_SIZE])){
        if( ( ( writePointer + RECEIVE_BUFFER_SIZE - readPointer) % RECEIVE_BUFFER_SIZE ) < 2){
            return false;
        }
        readPointer = (readPointer + 1) % RECEIVE_BUFFER_SIZE;
    }
    
    
    //if valid start seqence was found but the command isn't received complete also retrurn false
    if( ( ( writePointer - readPointer + RECEIVE_BUFFER_SIZE) % RECEIVE_BUFFER_SIZE ) < ((unsigned char)receiveBuffer[readPointer] + 2U) ){
        return false;
    }
    old = readPointer;
    return true;
    //#]
}

MainWindow* IParser::itsMainWindow = NULL;

ReceivedCommandsLogger* IParser::itsReceivedCommandsLogger = NULL;

/*********************************************************************
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\IParser.cpp
*********************************************************************/
