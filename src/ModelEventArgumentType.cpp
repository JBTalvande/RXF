/********************************************************************
	Rhapsody	: 9.0.1 
	Login		: Y9DSYU706
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: ModelEventArgumentType
//!	Generated Date	: Thu, 4, Nov 2021  
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\ModelEventArgumentType.cpp
*********************************************************************/

#include "ModelEventArgumentType.h"
//## package RpyModelData

//## class ModelEventArgumentType
ModelEventArgumentType::ModelEventArgumentType(const QString& p_name, ModelDataType* p_type)
{
    //#[ operation ModelEventArgumentType(QString,ModelDataType)
    name = p_name; 
    type = p_type;
    //#]
}

ModelEventArgumentType::ModelEventArgumentType()
{
}

ModelEventArgumentType::~ModelEventArgumentType()
{
}

const QString& ModelEventArgumentType::getName() const
{
    //#[ operation getName() const
    return name;
    //#]
}

void ModelEventArgumentType::setName(const QString& p_name)
{
    //#[ operation setName(QString)
    name = p_name;
    //#]
}

/*********************************************************************
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\ModelEventArgumentType.cpp
*********************************************************************/
