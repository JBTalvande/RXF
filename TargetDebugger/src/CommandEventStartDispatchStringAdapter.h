/*********************************************************************
	Rhapsody	: 9.0.1 
	Login		: Y9DSYU706
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: CommandEventStartDispatchStringAdapter
//!	Generated Date	: Thu, 4, Nov 2021  
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\CommandEventStartDispatchStringAdapter.h
*********************************************************************/

#ifndef CommandEventStartDispatchStringAdapter_H
#define CommandEventStartDispatchStringAdapter_H

#include "StringAdapter.h"
#include "AbstractCommandStringAdapter.h"
class Command;

class CommandEventCreated;

class CommandEventStartDispatch;

class ModelEventType;

class TargetInformation;

//## package LogicLevel::Logging::Adapter::StringAdapter

//## class CommandEventStartDispatchStringAdapter
class CommandEventStartDispatchStringAdapter : public AbstractCommandStringAdapter {
    ////    Constructors and destructors    ////
    
public :

    //## operation CommandEventStartDispatchStringAdapter()
    CommandEventStartDispatchStringAdapter();
    
    virtual ~CommandEventStartDispatchStringAdapter();
    
    ////    Operations    ////
    
    //## operation getCommandName()
    inline virtual QString getCommandName();
    
    //## operation getCommandProperties(Command)
    virtual QString getCommandProperties(const Command& p_command);
};

inline QString CommandEventStartDispatchStringAdapter::getCommandName()
{
    //#[ operation getCommandName()
    return "EventStartDispatchCommand";
    //#]
}

#endif
/*********************************************************************
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\CommandEventStartDispatchStringAdapter.h
*********************************************************************/
