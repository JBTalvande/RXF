/*********************************************************************
	Rhapsody	: 9.0.1 
	Login		: Y9DSYU706
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: CommandEventEndDispatch
//!	Generated Date	: Thu, 4, Nov 2021  
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\CommandEventEndDispatch.h
*********************************************************************/

#ifndef CommandEventEndDispatch_H
#define CommandEventEndDispatch_H

#include "ReceivedCommands.h"
#include "CommandEventTripletData.h"
class CommandEventStartDispatch;

class TargetInformation;

//## package LogicLevel::Logging::DataContainer::ReceivedCommands

//## class CommandEventEndDispatch
class CommandEventEndDispatch : public CommandEventTripletData {
    ////    Constructors and destructors    ////
    
public :

    //## operation CommandEventEndDispatch(unsigned int,CommandEventStartDispatch,QString,TargetInformation)
    CommandEventEndDispatch(unsigned int eventID, CommandEventStartDispatch* startEvent, const QString& currentStatesString, TargetInformation* target);
    
    ~CommandEventEndDispatch();
    
    ////    Operations    ////
    
    //## operation getStateAfterEventConsumption() const
    inline const QString& getStateAfterEventConsumption() const;
    
    ////    Additional operations    ////
    
    inline CommandEventStartDispatch* getItsCommandEventStartDispatch() const
    {
        return itsCommandEventStartDispatch;
    }
    
    inline void setItsCommandEventStartDispatch(CommandEventStartDispatch* p_CommandEventStartDispatch)
    {
        itsCommandEventStartDispatch = p_CommandEventStartDispatch;
    }

protected :

    void cleanUpRelations();
    
    ////    Attributes    ////

private :

    QString stateAfterEventConsumption;		//## attribute stateAfterEventConsumption
    
    ////    Relations and components    ////

protected :

    CommandEventStartDispatch* itsCommandEventStartDispatch;
};

inline const QString& CommandEventEndDispatch::getStateAfterEventConsumption() const
{
    //#[ operation getStateAfterEventConsumption() const
    return stateAfterEventConsumption;
    //#]
}

#endif
/*********************************************************************
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\CommandEventEndDispatch.h
*********************************************************************/
