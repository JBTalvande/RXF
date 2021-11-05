/*********************************************************************
	Rhapsody	: 9.0.1 
	Login		: Y9DSYU706
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: CommandEventTripletData
//!	Generated Date	: Thu, 4, Nov 2021  
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\CommandEventTripletData.h
*********************************************************************/

#ifndef CommandEventTripletData_H
#define CommandEventTripletData_H

#include "ReceivedCommands.h"
#include "Command.h"
class TargetInformation;

//## package LogicLevel::Logging::DataContainer::ReceivedCommands

//## class CommandEventTripletData
class CommandEventTripletData : public Command {
    ////    Constructors and destructors    ////
    
public :

    //## operation CommandEventTripletData(TargetInformation)
    CommandEventTripletData(TargetInformation* target);
    
    ~CommandEventTripletData();
    
    ////    Additional operations    ////
    
    inline unsigned int getDisplayNumber() const
    {
        return displayNumber;
    }
    
    inline void setDisplayNumber(unsigned int p_displayNumber)
    {
        displayNumber = p_displayNumber;
    }
    
    inline unsigned int getEventID() const
    {
        return eventID;
    }
    
    inline void setEventID(unsigned int p_eventID)
    {
        eventID = p_eventID;
    }
    
    ////    Attributes    ////
    
    unsigned int displayNumber;		//## attribute displayNumber

protected :

    unsigned int eventID;		//## attribute eventID
};

#endif
/*********************************************************************
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\CommandEventTripletData.h
*********************************************************************/
