/*********************************************************************
	Rhapsody	: 9.0.1 
	Login		: Y9DSYU706
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: DefaultParser
//!	Generated Date	: Thu, 4, Nov 2021  
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\DefaultParser.h
*********************************************************************/

#ifndef DefaultParser_H
#define DefaultParser_H

#include "DataParser.h"
#include "IParser.h"
class CommandConstructor;

class CommandDestructor;

class ModelInstance;

//## package LogicLevel::DataTransmission::DataParser

//## class DefaultParser
class DefaultParser : public IParser {
    ////    Constructors and destructors    ////
    
public :

    DefaultParser();
    
    virtual ~DefaultParser();
    
    ////    Operations    ////
    
    //## operation analyzeCommand(unsigned char*,unsigned int)
    virtual void analyzeCommand(unsigned char* data, unsigned int commandSize);
    
    //## operation checkCommandStart(unsigned char,char)
    virtual bool checkCommandStart(unsigned char size, char command);
    
    //## operation updateCommands()
    virtual void updateCommands();
};

#endif
/*********************************************************************
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\DefaultParser.h
*********************************************************************/
