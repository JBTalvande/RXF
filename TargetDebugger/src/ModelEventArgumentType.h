/*********************************************************************
	Rhapsody	: 9.0.1 
	Login		: Y9DSYU706
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: ModelEventArgumentType
//!	Generated Date	: Thu, 4, Nov 2021  
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\ModelEventArgumentType.h
*********************************************************************/

#ifndef ModelEventArgumentType_H
#define ModelEventArgumentType_H

#include "ModelDataType.h"
//## package RpyModelData

//## class ModelEventArgumentType
class ModelEventArgumentType {
    ////    Constructors and destructors    ////
    
public :

    //## operation ModelEventArgumentType(QString,ModelDataType)
    ModelEventArgumentType(const QString& p_name, ModelDataType* p_type);
    
    ModelEventArgumentType();
    
    ~ModelEventArgumentType();
    
    ////    Operations    ////
    
    //## operation getName() const
    const QString& getName() const;
    
    //## operation setName(QString)
    void setName(const QString& p_name);
    
    ////    Additional operations    ////
    
    inline ModelDataType* getType() const
    {
        return type;
    }
    
    inline void setType(ModelDataType* p_type)
    {
        type = p_type;
    }
    
    ////    Attributes    ////

private :

    QString name;		//## attribute name
    
    ModelDataType* type;		//## attribute type
};

#endif
/*********************************************************************
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\ModelEventArgumentType.h
*********************************************************************/
