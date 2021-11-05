/*********************************************************************
	Rhapsody	: 9.0.1 
	Login		: Y9DSYU706
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: CommandEventCreatedStringAdapter
//!	Generated Date	: Thu, 4, Nov 2021  
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\CommandEventCreatedStringAdapter.h
*********************************************************************/

#ifndef CommandEventCreatedStringAdapter_H
#define CommandEventCreatedStringAdapter_H

#include "StringAdapter.h"
#include "AbstractCommandStringAdapter.h"
#include "CommandEventCreated.h"
class Command;

class ModelEventType;

class ModelInstance;

class ReceivedEventParameter;

class TargetInformation;

//## package LogicLevel::Logging::Adapter::StringAdapter

//## class CommandEventCreatedStringAdapter
class CommandEventCreatedStringAdapter : public AbstractCommandStringAdapter {
    ////    Constructors and destructors    ////
    
public :

    //## operation CommandEventCreatedStringAdapter()
    CommandEventCreatedStringAdapter();
    
    virtual ~CommandEventCreatedStringAdapter();
    
    ////    Operations    ////
    
    //## operation getCommandName()
    inline virtual QString getCommandName();
    
    //## operation getCommandProperties(Command)
    virtual QString getCommandProperties(const Command& p_command);

private :

    //## operation getReceivedEventParameters(CommandEventCreated)
    QString getReceivedEventParameters(const CommandEventCreated& p_command);
};

inline QString CommandEventCreatedStringAdapter::getCommandName()
{
    //#[ operation getCommandName()
    return "EventCreatedCommand";
    //#]
}

#endif
/*********************************************************************
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\CommandEventCreatedStringAdapter.h
*********************************************************************/
