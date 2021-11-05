/*********************************************************************
	Rhapsody	: 9.0.1 
	Login		: Y9DSYU706
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: CommandEventEndDispatchStringAdapter
//!	Generated Date	: Thu, 4, Nov 2021  
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\CommandEventEndDispatchStringAdapter.h
*********************************************************************/

#ifndef CommandEventEndDispatchStringAdapter_H
#define CommandEventEndDispatchStringAdapter_H

#include "StringAdapter.h"
#include "AbstractCommandStringAdapter.h"
class Command;

class CommandEventCreated;

class CommandEventEndDispatch;

class CommandEventStartDispatch;

class ModelEventType;

class TargetInformation;

//## package LogicLevel::Logging::Adapter::StringAdapter

//## class CommandEventEndDispatchStringAdapter
class CommandEventEndDispatchStringAdapter : public AbstractCommandStringAdapter {
    ////    Constructors and destructors    ////
    
public :

    //## operation CommandEventEndDispatchStringAdapter()
    CommandEventEndDispatchStringAdapter();
    
    virtual ~CommandEventEndDispatchStringAdapter();
    
    ////    Operations    ////
    
    //## operation getCommandName()
    inline virtual QString getCommandName();
    
    //## operation getCommandProperties(Command)
    virtual QString getCommandProperties(const Command& p_command);
};

inline QString CommandEventEndDispatchStringAdapter::getCommandName()
{
    //#[ operation getCommandName()
    return "EventEndDispatchCommand";
    //#]
}

#endif
/*********************************************************************
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\CommandEventEndDispatchStringAdapter.h
*********************************************************************/
