/*********************************************************************
	Rhapsody	: 9.0.1 
	Login		: Y9DSYU706
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: CommandIntVal
//!	Generated Date	: Thu, 4, Nov 2021  
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\CommandIntVal.h
*********************************************************************/

#ifndef CommandIntVal_H
#define CommandIntVal_H

#include "ReceivedCommands.h"
#include "Command.h"
#include "ModelInstance.h"
class TargetInformation;

//## package LogicLevel::Logging::DataContainer::ReceivedCommands

//## class CommandIntVal
class CommandIntVal : public Command {
    ////    Constructors and destructors    ////
    
public :

    //## operation CommandIntVal(TargetInformation,unsigned int,ModelInstance)
    CommandIntVal(TargetInformation* target, unsigned int value, ModelInstance* instance);
    
    ~CommandIntVal();
    
    ////    Additional operations    ////
    
    inline ModelInstance* getInstance() const
    {
        return instance;
    }
    
    inline void setInstance(ModelInstance* p_instance)
    {
        instance = p_instance;
    }
    
    inline unsigned int getIntValue() const
    {
        return intValue;
    }
    
    inline void setIntValue(unsigned int p_intValue)
    {
        intValue = p_intValue;
    }
    
    ////    Attributes    ////

private :

    ModelInstance* instance;		//## attribute instance
    
    unsigned int intValue;		//## attribute intValue
};

#endif
/*********************************************************************
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\CommandIntVal.h
*********************************************************************/
