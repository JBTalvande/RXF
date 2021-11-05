/********************************************************************
	Rhapsody	: 9.0.1 
	Login		: Y9DSYU706
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: ModelOperationType
//!	Generated Date	: Thu, 4, Nov 2021  
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\ModelOperationType.cpp
*********************************************************************/

#include "ModelOperationType.h"
#include "TargetInformation.h"
//## package RpyModelData

//## class ModelOperationType
ModelOperationType::ModelOperationType(const QString& p_name, int id, TargetInformation* target) : ModelEventType( p_name, id, target )
{
    //#[ operation ModelOperationType(QString,int,TargetInformation)
    //#]
}

ModelOperationType::ModelOperationType()
{
}

ModelOperationType::~ModelOperationType()
{
}

bool ModelOperationType::isOperation()
{
    //#[ operation isOperation()
    return true;
    //#]
}

/*********************************************************************
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\ModelOperationType.cpp
*********************************************************************/
