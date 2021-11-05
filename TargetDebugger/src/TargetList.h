/*********************************************************************
	Rhapsody	: 9.0.1 
	Login		: Y9DSYU706
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: TargetList
//!	Generated Date	: Thu, 4, Nov 2021  
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\TargetList.h
*********************************************************************/

#ifndef TargetList_H
#define TargetList_H

#include "Logging.h"
#include <QHash>
#include "TargetInformation.h"
#include <QObject>
//## package LogicLevel::Logging

//## class TargetList
class TargetList : public QObject {
Q_OBJECT
    ////    Constructors and destructors    ////
    
public :

    TargetList();
    
    ~TargetList();
    
    ////    Operations    ////
    
    //## operation createTarget(int,QString,bool)
    TargetInformation* createTarget(int targetId, const QString& name, bool isSingleton);
    
    //## operation getTarget(unsigned int)
    inline TargetInformation* getTarget(unsigned int id);
    
    //## operation getTarget(QString)
    inline TargetInformation* getTarget(const QString& name);
    
    //## operation getTargetList()
    QHash<int, TargetInformation*>& getTargetList();
    
    //## operation setAllTargetsWaitingForSynchronisation()
    Q_SLOT void setAllTargetsWaitingForSynchronisation();
    
    ////    Additional operations    ////
    
    inline static TargetList* getGlobalList()
    {
        return (TargetList*) &globalList;
    }
    
    inline void clearItsTargetList()
    {
        itsTargetList.clear();
    }
    
    inline TargetInformation* getItsTargetList(int key) const
    {
        return itsTargetList.value(key);
    }
    
    inline void removeItsTargetList(int key)
    {
        itsTargetList.remove(key);
    }

protected :

    void cleanUpRelations();
    
    ////    Attributes    ////

public :

    static TargetList globalList;		//## attribute globalList
    
    ////    Relations and components    ////

protected :

    QHash<int, TargetInformation*> itsTargetList;
};

inline TargetInformation* TargetList::getTarget(unsigned int id)
{
    //#[ operation getTarget(unsigned int)
    return itsTargetList.value(id, NULL);
    //#]
}

inline TargetInformation* TargetList::getTarget(const QString& name)
{
    //#[ operation getTarget(QString)
    foreach (TargetInformation *aTarget, itsTargetList) {
        if( aTarget->getName() == name )
        {
            return aTarget;
        }
    }
    return NULL;
    //#]
}

#endif
/*********************************************************************
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\TargetList.h
*********************************************************************/
