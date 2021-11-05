/********************************************************************
	Rhapsody	: 9.0.1 
	Login		: Y9DSYU706
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: ModelClassAttribute
//!	Generated Date	: Thu, 4, Nov 2021  
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\ModelClassAttribute.cpp
*********************************************************************/

#include "ModelClassAttribute.h"
#include "ModelDataType.h"
//## package RpyModelData

//## class ModelClassAttribute
ModelClassAttribute::ModelClassAttribute() : offset(-1)
{
    itsModelDataType = NULL;
    //#[ operation ModelClassAttribute()
    arrayDimension[0] = 1;
    arrayDimension[1] = 1;
    arrayDimension[2] = 1;
    //#]
}

ModelClassAttribute::~ModelClassAttribute()
{
    cleanUpRelations();
}

unsigned int ModelClassAttribute::getCompleteArraySize()
{
    //#[ operation getCompleteArraySize()
    return arrayDimension[0] * arrayDimension[1] * arrayDimension[2];
    //#]
}

const QString& ModelClassAttribute::getName() const
{
    //#[ operation getName() const
    return name;
    //#]
}

void ModelClassAttribute::setName(const QString& p_name)
{
    //#[ operation setName(QString)
    name = p_name;
    //#]
}

void ModelClassAttribute::cleanUpRelations()
{
    if(itsModelDataType != NULL)
        {
            itsModelDataType = NULL;
        }
}

/*********************************************************************
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\ModelClassAttribute.cpp
*********************************************************************/
