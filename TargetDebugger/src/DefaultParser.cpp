/********************************************************************
	Rhapsody	: 9.0.1 
	Login		: Y9DSYU706
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: DefaultParser
//!	Generated Date	: Thu, 4, Nov 2021  
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\DefaultParser.cpp
*********************************************************************/

#include "DefaultParser.h"
#include "CommandConstructor.h"
#include "CommandDestructor.h"
#include "ModelInstance.h"
//## package LogicLevel::DataTransmission::DataParser

//## class DefaultParser
DefaultParser::DefaultParser()
{
}

DefaultParser::~DefaultParser()
{
}

void DefaultParser::analyzeCommand(unsigned char* data, unsigned int commandSize)
{
    //#[ operation analyzeCommand(unsigned char*,unsigned int)
    commandSize = commandSize;
    commandNewVersion(data);
    //#]
}

bool DefaultParser::checkCommandStart(unsigned char size, char command)
{
    //#[ operation checkCommandStart(unsigned char,char)
    if( command == 0 && size == 5 )
    {
    	return true;
    }
    return false;
    //#]
}

void DefaultParser::updateCommands()
{
    //#[ operation updateCommands()
    //#]
}

/*********************************************************************
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\DefaultParser.cpp
*********************************************************************/
