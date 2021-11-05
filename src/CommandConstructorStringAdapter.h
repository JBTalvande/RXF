/*********************************************************************
	Rhapsody	: 9.0.1 
	Login		: Y9DSYU706
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: CommandConstructorStringAdapter
//!	Generated Date	: Thu, 4, Nov 2021  
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\CommandConstructorStringAdapter.h
*********************************************************************/

#ifndef CommandConstructorStringAdapter_H
#define CommandConstructorStringAdapter_H

#include "StringAdapter.h"
#include "AbstractCommandStringAdapter.h"
#include "CommandConstructor.h"
class Command;

class ModelClass;

class ModelInstance;

class TargetInformation;

//## package LogicLevel::Logging::Adapter::StringAdapter

//## class CommandConstructorStringAdapter
class CommandConstructorStringAdapter : public AbstractCommandStringAdapter {
    ////    Constructors and destructors    ////
    
public :

    //## operation CommandConstructorStringAdapter()
    CommandConstructorStringAdapter();
    
    virtual ~CommandConstructorStringAdapter();
    
    ////    Operations    ////
    
    //## operation getCommandName()
    inline virtual QString getCommandName();
    
    //## operation getCommandProperties(Command)
    virtual QString getCommandProperties(const Command& p_command);
};

inline QString CommandConstructorStringAdapter::getCommandName()
{
    //#[ operation getCommandName()
    return "ConstructorCommand";
    //#]
}

#endif
/*********************************************************************
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\CommandConstructorStringAdapter.h
*********************************************************************/
