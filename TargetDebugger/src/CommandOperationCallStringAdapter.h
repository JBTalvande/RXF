/*********************************************************************
	Rhapsody	: 9.0.1 
	Login		: Y9DSYU706
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: CommandOperationCallStringAdapter
//!	Generated Date	: Thu, 4, Nov 2021  
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\CommandOperationCallStringAdapter.h
*********************************************************************/

#ifndef CommandOperationCallStringAdapter_H
#define CommandOperationCallStringAdapter_H

#include "StringAdapter.h"
#include "AbstractCommandStringAdapter.h"
class Command;

class CommandOperationCall;

class ModelEventType;

class ModelInstance;

class ReceivedEventParameter;

class TargetInformation;

//## package LogicLevel::Logging::Adapter::StringAdapter

//## class CommandOperationCallStringAdapter
class CommandOperationCallStringAdapter : public AbstractCommandStringAdapter {
    ////    Constructors and destructors    ////
    
public :

    //## operation CommandOperationCallStringAdapter()
    CommandOperationCallStringAdapter();
    
    virtual ~CommandOperationCallStringAdapter();
    
    ////    Operations    ////
    
    //## operation getCommandName()
    inline virtual QString getCommandName();
    
    //## operation getCommandProperties(Command)
    virtual QString getCommandProperties(const Command& p_command);

private :

    //## operation getReceivedEventParameters(CommandOperationCall)
    QString getReceivedEventParameters(const CommandOperationCall& p_command);
};

inline QString CommandOperationCallStringAdapter::getCommandName()
{
    //#[ operation getCommandName()
    return "OperationCallCommand";
    //#]
}

#endif
/*********************************************************************
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\CommandOperationCallStringAdapter.h
*********************************************************************/
