/*********************************************************************
	Rhapsody	: 9.0.1 
	Login		: Y9DSYU706
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: CommandTraceEventStringAdapter
//!	Generated Date	: Thu, 4, Nov 2021  
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\CommandTraceEventStringAdapter.h
*********************************************************************/

#ifndef CommandTraceEventStringAdapter_H
#define CommandTraceEventStringAdapter_H

#include "StringAdapter.h"
#include "AbstractCommandStringAdapter.h"
#include "ModelInstance.h"
class Command;

class CommandTraceEvent;

class ModelEventType;

class TargetInformation;

//## package LogicLevel::Logging::Adapter::StringAdapter

//## class CommandTraceEventStringAdapter
class CommandTraceEventStringAdapter : public AbstractCommandStringAdapter {
    ////    Constructors and destructors    ////
    
public :

    //## operation CommandTraceEventStringAdapter()
    CommandTraceEventStringAdapter();
    
    virtual ~CommandTraceEventStringAdapter();
    
    ////    Operations    ////
    
    //## operation getCommandName()
    inline virtual QString getCommandName();
    
    //## operation getCommandProperties(Command)
    virtual QString getCommandProperties(const Command& p_command);

private :

    //## operation getReceivedEventParameters(CommandTraceEvent)
    QString getReceivedEventParameters(const CommandTraceEvent& p_command);
};

inline QString CommandTraceEventStringAdapter::getCommandName()
{
    //#[ operation getCommandName()
    return "TraceEventCommand";
    //#]
}

#endif
/*********************************************************************
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\CommandTraceEventStringAdapter.h
*********************************************************************/
