/*********************************************************************
	Rhapsody	: 9.0.1 
	Login		: Y9DSYU706
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: CommandEventStartDispatch
//!	Generated Date	: Thu, 4, Nov 2021  
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\CommandEventStartDispatch.h
*********************************************************************/

#ifndef CommandEventStartDispatch_H
#define CommandEventStartDispatch_H

#include "ReceivedCommands.h"
#include "CommandEventTripletData.h"
class CommandEventCreated;

class CommandEventEndDispatch;

class TargetInformation;

//## package LogicLevel::Logging::DataContainer::ReceivedCommands

//## class CommandEventStartDispatch
class CommandEventStartDispatch : public CommandEventTripletData {
    ////    Constructors and destructors    ////
    
public :

    //## operation CommandEventStartDispatch(unsigned int,unsigned int,CommandEventCreated,TargetInformation)
    CommandEventStartDispatch(unsigned int eventID, unsigned int ticks, CommandEventCreated* prevCreateEvent, TargetInformation* target);
    
    ~CommandEventStartDispatch();
    
    ////    Additional operations    ////
    
    inline CommandEventCreated* getItsCommandEventCreated() const
    {
        return itsCommandEventCreated;
    }
    
    inline void setItsCommandEventCreated(CommandEventCreated* p_CommandEventCreated)
    {
        itsCommandEventCreated = p_CommandEventCreated;
    }
    
    inline CommandEventEndDispatch* getItsCommandEventEndDispatch() const
    {
        return itsCommandEventEndDispatch;
    }
    
    inline void setItsCommandEventEndDispatch(CommandEventEndDispatch* p_CommandEventEndDispatch)
    {
        itsCommandEventEndDispatch = p_CommandEventEndDispatch;
    }

protected :

    void cleanUpRelations();
    
    ////    Relations and components    ////
    
    CommandEventCreated* itsCommandEventCreated;
    
    CommandEventEndDispatch* itsCommandEventEndDispatch;
};

#endif
/*********************************************************************
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\CommandEventStartDispatch.h
*********************************************************************/
