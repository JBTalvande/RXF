/*********************************************************************
	Rhapsody	: 9.0.1 
	Login		: Y9DSYU706
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: AbstractCommandStringAdapter
//!	Generated Date	: Thu, 4, Nov 2021  
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\AbstractCommandStringAdapter.h
*********************************************************************/

#ifndef AbstractCommandStringAdapter_H
#define AbstractCommandStringAdapter_H

#include "StringAdapter.h"
#include "Command.h"
#include "CommandAdapter.h"
class TargetInformation;

//## package LogicLevel::Logging::Adapter::StringAdapter

//## class AbstractCommandStringAdapter
class AbstractCommandStringAdapter : public CommandAdapter<QString> {
    ////    Constructors and destructors    ////
    
public :

    //## operation AbstractCommandStringAdapter(commandType)
    AbstractCommandStringAdapter(const Command::commandType& p_commandType);
    
    AbstractCommandStringAdapter();
    
    virtual ~AbstractCommandStringAdapter();
    
    ////    Operations    ////
    
    // Adapts a command to a string representative.
    // Uses the format "<CommandName>: <CommandProperties>" where <CommandName> is taken from getCommandName() and <CommandProperties> is taken from getCommandProperties(p_command: Command).
    // Both operations are intended to be overridden by subclasses of this AbstractCommandStringAdapter.
    //## operation adapt(Command)
    virtual QString adapt(const Command& command);
    
    //## operation getCommandName()
    inline virtual QString getCommandName();
    
    //## operation getCommandProperties(Command)
    inline virtual QString getCommandProperties(const Command& p_command);
};

inline QString AbstractCommandStringAdapter::getCommandName()
{
    //#[ operation getCommandName()
    return "Command";
    //#]
}

inline QString AbstractCommandStringAdapter::getCommandProperties(const Command& p_command)
{
    //#[ operation getCommandProperties(Command)
    (void)p_command; // avoid warning about unused parameter in this default operation
    return "";
    //#]
}

#endif
/*********************************************************************
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\AbstractCommandStringAdapter.h
*********************************************************************/
