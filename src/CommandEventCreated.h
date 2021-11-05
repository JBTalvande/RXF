/*********************************************************************
	Rhapsody	: 9.0.1 
	Login		: Y9DSYU706
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: CommandEventCreated
//!	Generated Date	: Thu, 4, Nov 2021  
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\CommandEventCreated.h
*********************************************************************/

#ifndef CommandEventCreated_H
#define CommandEventCreated_H

#include "ReceivedCommands.h"
#include <QVector>
#include "CommandEventTripletData.h"
#include "ReceivedEventParameter.h"
class CommandEventStartDispatch;

class ModelEventType;

class ModelInstance;

class TargetInformation;

//## package LogicLevel::Logging::DataContainer::ReceivedCommands

//## class CommandEventCreated
class CommandEventCreated : public CommandEventTripletData {
    ////    Constructors and destructors    ////
    
public :

    //## operation CommandEventCreated(unsigned int,unsigned int,ModelInstance,ModelEventType,ModelInstance,TargetInformation)
    CommandEventCreated(unsigned int eventID, unsigned int ticks, ModelInstance* p_sourceInstance, ModelEventType* eventType, ModelInstance* p_destinationInstance, TargetInformation* target);
    
    ~CommandEventCreated();
    
    ////    Operations    ////
    
    //## operation getReceivedEventParameters() const
    inline const QVector<ReceivedEventParameter*>& getReceivedEventParameters() const;
    
    ////    Additional operations    ////
    
    inline ModelInstance* getDestinationInstance() const
    {
        return destinationInstance;
    }
    
    inline void setDestinationInstance(ModelInstance* p_ModelInstance)
    {
        destinationInstance = p_ModelInstance;
    }
    
    inline CommandEventStartDispatch* getItsCommandEventStartDispatch() const
    {
        return itsCommandEventStartDispatch;
    }
    
    inline void setItsCommandEventStartDispatch(CommandEventStartDispatch* p_CommandEventStartDispatch)
    {
        itsCommandEventStartDispatch = p_CommandEventStartDispatch;
    }
    
    inline ModelEventType* getItsModelEventType() const
    {
        return itsModelEventType;
    }
    
    inline void setItsModelEventType(ModelEventType* p_ModelEventType)
    {
        itsModelEventType = p_ModelEventType;
    }
    
    inline void addItsReceivedEventParameter(ReceivedEventParameter* p_ReceivedEventParameter)
    {
        itsReceivedEventParameter.append(p_ReceivedEventParameter);
    }
    
    inline void clearItsReceivedEventParameter()
    {
        itsReceivedEventParameter.clear();
    }
    
    inline ModelInstance* getSourceInstance() const
    {
        return sourceInstance;
    }
    
    inline void setSourceInstance(ModelInstance* p_ModelInstance)
    {
        sourceInstance = p_ModelInstance;
    }

protected :

    void cleanUpRelations();
    
    ////    Relations and components    ////
    
    ModelInstance* destinationInstance;
    
    CommandEventStartDispatch* itsCommandEventStartDispatch;
    
    ModelEventType* itsModelEventType;
    
    QVector<ReceivedEventParameter*> itsReceivedEventParameter;
    
    ModelInstance* sourceInstance;
};

inline const QVector<ReceivedEventParameter*>& CommandEventCreated::getReceivedEventParameters() const
{
    //#[ operation getReceivedEventParameters() const
    return this->itsReceivedEventParameter;
    //#]
}

#endif
/*********************************************************************
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\CommandEventCreated.h
*********************************************************************/
