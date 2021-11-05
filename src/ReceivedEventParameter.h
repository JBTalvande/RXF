/*********************************************************************
	Rhapsody	: 9.0.1 
	Login		: Y9DSYU706
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: ReceivedEventParameter
//!	Generated Date	: Thu, 4, Nov 2021  
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\ReceivedEventParameter.h
*********************************************************************/

#ifndef ReceivedEventParameter_H
#define ReceivedEventParameter_H

#include "DataContainer.h"
class ModelEventArgumentType;

//## package LogicLevel::Logging::DataContainer

//## class ReceivedEventParameter
class ReceivedEventParameter {
    ////    Constructors and destructors    ////
    
public :

    //## operation ReceivedEventParameter(ModelEventArgumentType,QString)
    ReceivedEventParameter(ModelEventArgumentType* parameterType, const QString& value);
    
    ~ReceivedEventParameter();
    
    ////    Additional operations    ////
    
    inline QString getValue() const
    {
        return value;
    }
    
    inline ModelEventArgumentType* getItsModelEventArgumentType() const
    {
        return itsModelEventArgumentType;
    }
    
    inline void setItsModelEventArgumentType(ModelEventArgumentType* p_ModelEventArgumentType)
    {
        itsModelEventArgumentType = p_ModelEventArgumentType;
    }

protected :

    void cleanUpRelations();
    
    ////    Attributes    ////

private :

    QString value;		//## attribute value
    
    ////    Relations and components    ////

protected :

    ModelEventArgumentType* itsModelEventArgumentType;
};

#endif
/*********************************************************************
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\ReceivedEventParameter.h
*********************************************************************/
