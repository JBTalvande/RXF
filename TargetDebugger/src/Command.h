/*********************************************************************
	Rhapsody	: 9.0.1 
	Login		: Y9DSYU706
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: Command
//!	Generated Date	: Thu, 4, Nov 2021  
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\Command.h
*********************************************************************/

#ifndef Command_H
#define Command_H

#include "ReceivedCommands.h"
class TargetInformation;

//## package LogicLevel::Logging::DataContainer::ReceivedCommands

//## class Command
class Command {
public :

    enum commandType {
        eventPutToMessageQueueCommand = 0,
        eventStartDispatchCommand = 1,
        eventEndDispatchCommand = 2,
        constructorCommand = 3,
        destructorCommand = 4,
        traceEventCommand = 5,
        errorHandlerReachedCommand = 6,
        bufferOverflowCommand = 7,
        operationCalled = 8,
        debugIntValue = 9
    };
    
    ////    Constructors and destructors    ////
    
    //## operation Command(TargetInformation)
    Command(TargetInformation* target);
    
    ~Command();
    
    ////    Additional operations    ////
    
    inline commandType getCommandIdentifier() const
    {
        return commandIdentifier;
    }
    
    inline void setCommandIdentifier(commandType p_commandIdentifier)
    {
        commandIdentifier = p_commandIdentifier;
    }
    
    inline int getTicks() const
    {
        return ticks;
    }
    
    inline void setTicks(int p_ticks)
    {
        ticks = p_ticks;
    }
    
    inline TargetInformation* getItsTargetInformation() const
    {
        return itsTargetInformation;
    }
    
    inline void setItsTargetInformation(TargetInformation* p_TargetInformation)
    {
        itsTargetInformation = p_TargetInformation;
    }

protected :

    void cleanUpRelations();
    
    ////    Attributes    ////
    
    commandType commandIdentifier;		//## attribute commandIdentifier
    
    int ticks;		//## attribute ticks
    
    ////    Relations and components    ////
    
    TargetInformation* itsTargetInformation;
};

#endif
/*********************************************************************
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\Command.h
*********************************************************************/
