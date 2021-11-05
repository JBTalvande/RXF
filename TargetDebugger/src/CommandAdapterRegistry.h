/*********************************************************************
	Rhapsody	: 9.0.1 
	Login		: Y9DSYU706
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: CommandAdapterRegistry
//!	Generated Date	: Thu, 4, Nov 2021  
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\CommandAdapterRegistry.h
*********************************************************************/

#ifndef CommandAdapterRegistry_H
#define CommandAdapterRegistry_H

#include "Adapter.h"
#include <QHash>
#include "Command.h"
#include "CommandAdapter.h"
//## package LogicLevel::Logging::Adapter

//## class CommandAdapterRegistry
template <typename ADAPTSTO> class CommandAdapterRegistry {
    ////    Constructors and destructors    ////
    
public :

    CommandAdapterRegistry();
    
    ~CommandAdapterRegistry();
    
    ////    Operations    ////
    
    //## operation addCommandAdapters(CommandAdapter)
    void addCommandAdapters(CommandAdapter<ADAPTSTO>* p_CommandAdapter);
    
    ////    Additional operations    ////
    
    inline void clearCommandAdapters()
    {
        commandAdapters.clear();
    }
    
    inline CommandAdapter<ADAPTSTO>* getCommandAdapters(Command::commandType key) const
    {
        return commandAdapters.value(key);
    }
    
    inline void addCommandAdapters(Command::commandType key, CommandAdapter<ADAPTSTO>* p_CommandAdapter)
    {
        commandAdapters.insert(key,p_CommandAdapter);
    }
    
    inline void removeCommandAdapters(Command::commandType key)
    {
        commandAdapters.remove(key);
    }

protected :

    void cleanUpRelations();
    
    ////    Relations and components    ////
    
    QHash<Command::commandType, CommandAdapter<ADAPTSTO>*> commandAdapters;
};

//## package LogicLevel::Logging::Adapter

//## class CommandAdapterRegistry
template <typename ADAPTSTO> void CommandAdapterRegistry<ADAPTSTO>::addCommandAdapters(CommandAdapter<ADAPTSTO>* p_CommandAdapter)
{
    //#[ operation addCommandAdapters(CommandAdapter)
    this->commandAdapters.insert(p_CommandAdapter->getAdaptsCommandType(), p_CommandAdapter);
    //#]
}

template <typename ADAPTSTO> void CommandAdapterRegistry<ADAPTSTO>::cleanUpRelations()
{
    {
        commandAdapters.clear();
    }
}

template <typename ADAPTSTO> CommandAdapterRegistry<ADAPTSTO>::CommandAdapterRegistry() : commandAdapters()
{
}

template <typename ADAPTSTO> CommandAdapterRegistry<ADAPTSTO>::~CommandAdapterRegistry()
{
    cleanUpRelations();
}

#endif
/*********************************************************************
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\CommandAdapterRegistry.h
*********************************************************************/
