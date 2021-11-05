/*********************************************************************
	Rhapsody	: 9.0.1 
	Login		: Y9DSYU706
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: CommandConstructor
//!	Generated Date	: Thu, 4, Nov 2021  
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\CommandConstructor.h
*********************************************************************/

#ifndef CommandConstructor_H
#define CommandConstructor_H

#include "ReceivedCommands.h"
#include "Command.h"
class ModelInstance;

class TargetInformation;

//## package LogicLevel::Logging::DataContainer::ReceivedCommands

//## class CommandConstructor
class CommandConstructor : public Command {
    ////    Constructors and destructors    ////
    
public :

    //## operation CommandConstructor(ModelInstance,TargetInformation)
    CommandConstructor(ModelInstance* instance, TargetInformation* target);
    
    ~CommandConstructor();
    
    ////    Additional operations    ////
    
    inline ModelInstance* getItsModelInstance() const
    {
        return itsModelInstance;
    }
    
    inline void setItsModelInstance(ModelInstance* p_ModelInstance)
    {
        itsModelInstance = p_ModelInstance;
    }

protected :

    void cleanUpRelations();
    
    ////    Relations and components    ////
    
    ModelInstance* itsModelInstance;
};

#endif
/*********************************************************************
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\CommandConstructor.h
*********************************************************************/
