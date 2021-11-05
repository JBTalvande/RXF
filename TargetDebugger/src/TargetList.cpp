/********************************************************************
	Rhapsody	: 9.0.1 
	Login		: Y9DSYU706
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: TargetList
//!	Generated Date	: Thu, 4, Nov 2021  
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\TargetList.cpp
*********************************************************************/

#include "TargetList.h"
//## package LogicLevel::Logging

//## class TargetList
TargetList TargetList::globalList;

TargetList::TargetList() : itsTargetList()
{
}

TargetList::~TargetList()
{
    cleanUpRelations();
}

TargetInformation* TargetList::createTarget(int targetId, const QString& name, bool isSingleton)
{
    //#[ operation createTarget(int,QString,bool)
    TargetInformation * newTarget = new TargetInformation(name, isSingleton, targetId);
    itsTargetList[ targetId ] = newTarget;
    return newTarget;
    //#]
}

QHash<int, TargetInformation*>& TargetList::getTargetList()
{
    //#[ operation getTargetList()
    return itsTargetList;
    //#]
}

void TargetList::setAllTargetsWaitingForSynchronisation()
{
    //#[ operation setAllTargetsWaitingForSynchronisation()
    foreach ( TargetInformation* aTarget, TargetList::getTargetList()) {
        aTarget->setInReset( true );
    }
    //#]
}

void TargetList::cleanUpRelations()
{
    {
        itsTargetList.clear();
    }
}

/*********************************************************************
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\TargetList.cpp
*********************************************************************/
