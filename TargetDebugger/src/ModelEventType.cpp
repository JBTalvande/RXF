/********************************************************************
	Rhapsody	: 9.0.1 
	Login		: Y9DSYU706
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: ModelEventType
//!	Generated Date	: Thu, 4, Nov 2021  
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\ModelEventType.cpp
*********************************************************************/

#include "ModelEventType.h"
#include "ModelDataType.h"
#include "TargetInformation.h"
//## package RpyModelData

//## class ModelEventType
ModelEventType::ModelEventType(const QString& p_name, int id, TargetInformation* target)
{
    itsTargetInformation = NULL;
    //#[ operation ModelEventType(QString,int,TargetInformation)
    name = p_name;
    itsTargetInformation = target;
    this->id = id;
    //#]
}

ModelEventType::ModelEventType()
{
    itsTargetInformation = NULL;
}

ModelEventType::~ModelEventType()
{
    cleanUpRelations();
}

void ModelEventType::addArgument(const QString& argumentName, ModelDataType* argumentType)
{
    //#[ operation addArgument(QString,ModelDataType)
    
    ModelEventArgumentType *newArgument = new ModelEventArgumentType(argumentName, argumentType);
    this->itsArguments.append(newArgument);
    
    //#]
}

const QVector<ModelEventArgumentType*>& ModelEventType::getArguments() const
{
    //#[ operation getArguments() const
    return this->itsArguments;
    //#]
}

const QString& ModelEventType::getName() const
{
    //#[ operation getName() const
    return name;
    //#]
}

bool ModelEventType::isOperation()
{
    //#[ operation isOperation()
    return false;
    //#]
}

void ModelEventType::setName(const QString& p_name)
{
    //#[ operation setName(QString)
    name = p_name;
    //#]
}

void ModelEventType::cleanUpRelations()
{
    {
        itsArguments.clear();
    }
    if(itsTargetInformation != NULL)
        {
            itsTargetInformation = NULL;
        }
}

/*********************************************************************
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\ModelEventType.cpp
*********************************************************************/
