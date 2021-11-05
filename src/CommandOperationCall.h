/*********************************************************************
	Rhapsody	: 9.0.1 
	Login		: Y9DSYU706
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: CommandOperationCall
//!	Generated Date	: Thu, 4, Nov 2021  
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\CommandOperationCall.h
*********************************************************************/

#ifndef CommandOperationCall_H
#define CommandOperationCall_H

#include "ReceivedCommands.h"
#include <QVector>
#include "Command.h"
#include "ReceivedEventParameter.h"
class ModelEventType;

class ModelInstance;

class TargetInformation;

//## package LogicLevel::Logging::DataContainer::ReceivedCommands

//## class CommandOperationCall
class CommandOperationCall : public Command {
    ////    Constructors and destructors    ////
    
public :

    //## operation CommandOperationCall(unsigned int,ModelInstance,ModelEventType,ModelInstance,TargetInformation)
    CommandOperationCall(unsigned int ticks, ModelInstance* p_sourceInstance, ModelEventType* eventType, ModelInstance* p_destinationInstance, TargetInformation* target);
    
    ~CommandOperationCall();
    
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
    
    ModelEventType* itsModelEventType;
    
    QVector<ReceivedEventParameter*> itsReceivedEventParameter;
    
    ModelInstance* sourceInstance;
};

inline const QVector<ReceivedEventParameter*>& CommandOperationCall::getReceivedEventParameters() const
{
    //#[ operation getReceivedEventParameters() const
    return this->itsReceivedEventParameter;
    //#]
}

#endif
/*********************************************************************
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\CommandOperationCall.h
*********************************************************************/
