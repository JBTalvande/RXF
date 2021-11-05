/*********************************************************************
	Rhapsody	: 9.0.1 
	Login		: Y9DSYU706
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: CommandTraceEvent
//!	Generated Date	: Thu, 4, Nov 2021  
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\CommandTraceEvent.h
*********************************************************************/

#ifndef CommandTraceEvent_H
#define CommandTraceEvent_H

#include "ReceivedCommands.h"
#include <QVector>
#include "Command.h"
#include "ReceivedEventParameter.h"
class ModelEventType;

class ModelInstance;

class TargetInformation;

//## package LogicLevel::Logging::DataContainer::ReceivedCommands

//## class CommandTraceEvent
class CommandTraceEvent : public Command {
    ////    Constructors and destructors    ////
    
public :

    //## operation CommandTraceEvent(int,ModelInstance,ModelInstance,ModelEventType,QString,TargetInformation)
    CommandTraceEvent(int ticks, ModelInstance* sourceInstance, ModelInstance* destinationInstance, ModelEventType* modelEventType, const QString& currentStatesString, TargetInformation* targetInformation);
    
    ~CommandTraceEvent();
    
    ////    Operations    ////
    
    //## operation getReceivedEventParameters() const
    inline const QVector<ReceivedEventParameter*>& getReceivedEventParameters() const;
    
    //## operation getStateAfterEventConsumption() const
    inline const QString& getStateAfterEventConsumption() const;
    
    ////    Additional operations    ////
    
    inline ModelInstance* getDestinationInstance() const
    {
        return destinationInstance;
    }
    
    inline void setDestinationInstance(ModelInstance* p_ModelInstance)
    {
        destinationInstance = p_ModelInstance;
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
    
    ////    Attributes    ////

private :

    QString stateAfterEventConsumption;		//## attribute stateAfterEventConsumption
    
    ////    Relations and components    ////

protected :

    ModelInstance* destinationInstance;
    
    ModelEventType* itsModelEventType;
    
    QVector<ReceivedEventParameter*> itsReceivedEventParameter;
    
    ModelInstance* sourceInstance;
};

inline const QVector<ReceivedEventParameter*>& CommandTraceEvent::getReceivedEventParameters() const
{
    //#[ operation getReceivedEventParameters() const
    return this->itsReceivedEventParameter;
    //#]
}

inline const QString& CommandTraceEvent::getStateAfterEventConsumption() const
{
    //#[ operation getStateAfterEventConsumption() const
    return stateAfterEventConsumption;
    //#]
}

#endif
/*********************************************************************
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\CommandTraceEvent.h
*********************************************************************/
