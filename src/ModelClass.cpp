/********************************************************************
	Rhapsody	: 9.0.1 
	Login		: Y9DSYU706
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: ModelClass
//!	Generated Date	: Thu, 4, Nov 2021  
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\ModelClass.cpp
*********************************************************************/

#include "ModelClass.h"
//## package RpyModelData

//## class ModelClass
ModelClass::ModelClass() : instanceCount(0), isActive(false), isReactive(false), parrallelStateCount(1), itsModelInstanceList()
{
    itsTreeViewItemDebugInt = NULL;
    itsTreeViewItemTarget = NULL;
    itsTreeViewItemTargetFilter = NULL;
    lastInsertedInstance = NULL;
}

ModelClass::~ModelClass()
{
    cleanUpRelations();
}

void ModelClass::addAttribute(ModelClassAttribute* p_ClassAttribute)
{
    //#[ operation addAttribute(ModelClassAttribute)
    this->itsClassAttributeList.append(p_ClassAttribute);
    //#]
}

void ModelClass::addInstance(ModelInstance* newInstance)
{
    //#[ operation addInstance(ModelInstance)
    lastInsertedInstance = newInstance;
    this->itsModelInstanceList.insert(newInstance->getName(), newInstance);
    //#]
}

void ModelClass::addParent(ModelClass* parentClass)
{
    //#[ operation addParent(ModelClass)
    this->itsModelGeneralisationList.append(parentClass);
    //#]
}

void ModelClass::addState(ModelClassState* p_state)
{
    //#[ operation addState(ModelClassState)
    itsModelClassStateList.append( p_state );
    //#]
}

const QString& ModelClass::getFullPathName() const
{
    //#[ operation getFullPathName() const
    return fullPathName;
    //#]
}

const QString& ModelClass::getName() const
{
    //#[ operation getName() const
    return name;
    //#]
}

const QString& ModelClass::getState(unsigned int stateID)
{
    //#[ operation getState(unsigned int)
    for(int i = 0; i < itsModelClassStateList.size(); i++){
        if( itsModelClassStateList[i]->getId() == stateID )
        {
            return itsModelClassStateList[i]->getName();
        }
    }
    static QString unknownStateName;
    unknownStateName = "StateID " + QString::number(stateID) +" is Unknown";
    return unknownStateName;
    
    //#]
}

int ModelClass::getState(const QString& stateName)
{
    //#[ operation getState(QString)
    for(int i = 0; i < itsModelClassStateList.size(); i++){
        if( itsModelClassStateList[i]->getName() == stateName )
        {
            return itsModelClassStateList[i]->getId();
        }
    }
    return -1;
    
    //#]
}

int ModelClass::incrementInstanceCount()
{
    //#[ operation incrementInstanceCount()
    instanceCount++;
    return instanceCount;
    //#]
}

void ModelClass::resetAttributeOffset()
{
    //#[ operation resetAttributeOffset()
    for( ModelClassAttribute* aClassAttribute : itsClassAttributeList )
    {
        aClassAttribute->setOffset( -1 );
    }
    //#]
}

void ModelClass::resetInstanceCount()
{
    //#[ operation resetInstanceCount()
    instanceCount = 0;
    //#]
}

void ModelClass::setFullPathName(const QString& p_fullPathName)
{
    //#[ operation setFullPathName(QString)
    fullPathName = p_fullPathName;
    //#]
}

void ModelClass::setName(const QString& p_name)
{
    //#[ operation setName(QString)
    name = p_name;
    //#]
}

void ModelClass::cleanUpRelations()
{
    {
        itsClassAttributeList.clear();
    }
    {
        itsModelClassStateList.clear();
    }
    {
        itsModelGeneralisationList.clear();
    }
    {
        itsModelInstanceList.clear();
    }
    if(itsTreeViewItemDebugInt != NULL)
        {
            itsTreeViewItemDebugInt = NULL;
        }
    if(itsTreeViewItemTarget != NULL)
        {
            itsTreeViewItemTarget = NULL;
        }
    if(itsTreeViewItemTargetFilter != NULL)
        {
            itsTreeViewItemTargetFilter = NULL;
        }
    if(lastInsertedInstance != NULL)
        {
            lastInsertedInstance = NULL;
        }
}

/*********************************************************************
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\ModelClass.cpp
*********************************************************************/
