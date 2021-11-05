/*********************************************************************
	Rhapsody	: 9.0.1 
	Login		: Y9DSYU706
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: CommandAdapter
//!	Generated Date	: Thu, 4, Nov 2021  
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\CommandAdapter.h
*********************************************************************/

#ifndef CommandAdapter_H
#define CommandAdapter_H

#include "Adapter.h"
#include "Command.h"
//## package LogicLevel::Logging::Adapter

//## class CommandAdapter
template <typename ADAPTSTO> class CommandAdapter {
    ////    Constructors and destructors    ////
    
public :

    //## operation CommandAdapter(commandType)
    CommandAdapter(const Command::commandType& p_commandType);
    
    CommandAdapter();
    
    virtual ~CommandAdapter();
    
    ////    Operations    ////
    
    //## operation adapt(Command)
    virtual ADAPTSTO adapt(const Command& command) = 0;
    
    ////    Additional operations    ////
    
    inline Command::commandType getAdaptsCommandType() const
    {
        return adaptsCommandType;
    }
    
    inline void setAdaptsCommandType(Command::commandType p_adaptsCommandType)
    {
        adaptsCommandType = p_adaptsCommandType;
    }
    
    ////    Attributes    ////
    
    Command::commandType adaptsCommandType;		//## attribute adaptsCommandType
};

//## package LogicLevel::Logging::Adapter

//## class CommandAdapter
template <typename ADAPTSTO> CommandAdapter<ADAPTSTO>::CommandAdapter(const Command::commandType& p_commandType) : adaptsCommandType(p_commandType)
{
    //#[ operation CommandAdapter(commandType)
    //#]
}

template <typename ADAPTSTO> CommandAdapter<ADAPTSTO>::CommandAdapter()
{
}

template <typename ADAPTSTO> CommandAdapter<ADAPTSTO>::~CommandAdapter()
{
}

#endif
/*********************************************************************
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\CommandAdapter.h
*********************************************************************/
