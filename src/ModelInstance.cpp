/********************************************************************
	Rhapsody	: 9.0.1 
	Login		: Y9DSYU706
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: ModelInstance
//!	Generated Date	: Thu, 4, Nov 2021  
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\ModelInstance.cpp
*********************************************************************/

#include "ModelInstance.h"
#include "ModelClass.h"
#include "TargetInformation.h"
//## package RpyModelData

//## class ModelInstance
ModelInstance::ModelInstance(ModelClass* baseClass, uint64_t objectAddress, uint64_t firstAttributeAddress, const QString& instanceName, TargetInformation* target) : isBaseClass(false)
{
    itsTargetInformation = NULL;
    itsModelClass = NULL;
    //#[ operation ModelInstance(ModelClass,uint64_t,uint64_t,QString,TargetInformation)
    this->itsModelClass = baseClass;
    this->address = objectAddress;
    this->firstAttributeAddress = firstAttributeAddress;
    this->name = instanceName;
    this->itsTargetInformation = target;
    //#]
}

ModelInstance::ModelInstance() : isBaseClass(false)
{
    itsModelClass = NULL;
    itsTargetInformation = NULL;
}

ModelInstance::~ModelInstance()
{
    cleanUpRelations();
}

const QString& ModelInstance::getName() const
{
    //#[ operation getName() const
    return name;
    //#]
}

void ModelInstance::cleanUpRelations()
{
    if(itsModelClass != NULL)
        {
            itsModelClass = NULL;
        }
    if(itsTargetInformation != NULL)
        {
            itsTargetInformation = NULL;
        }
}

/*********************************************************************
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\ModelInstance.cpp
*********************************************************************/
