/*********************************************************************
	Rhapsody	: 9.0.1 
	Login		: Y9DSYU706
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: CommandDestructor
//!	Generated Date	: Thu, 4, Nov 2021  
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\CommandDestructor.h
*********************************************************************/

#ifndef CommandDestructor_H
#define CommandDestructor_H

#include "ReceivedCommands.h"
#include "Command.h"
class ModelInstance;

class TargetInformation;

//## package LogicLevel::Logging::DataContainer::ReceivedCommands

//## class CommandDestructor
class CommandDestructor : public Command {
    ////    Constructors and destructors    ////
    
public :

    //## operation CommandDestructor(ModelInstance,TargetInformation)
    CommandDestructor(ModelInstance* instance, TargetInformation* target);
    
    ~CommandDestructor();
    
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
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\CommandDestructor.h
*********************************************************************/
