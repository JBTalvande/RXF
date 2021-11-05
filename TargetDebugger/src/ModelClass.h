/*********************************************************************
	Rhapsody	: 9.0.1 
	Login		: Y9DSYU706
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: ModelClass
//!	Generated Date	: Thu, 4, Nov 2021  
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\ModelClass.h
*********************************************************************/

#ifndef ModelClass_H
#define ModelClass_H

#include <QVector>
#include <QHash>
#include "ModelClassAttribute.h"
#include "ModelClassState.h"
#include "ModelInstance.h"
#include <QString>
#include <QStandardItem>
//## package RpyModelData

//## class ModelClass
// This class contain information of modelled classes in Rhapsody which are read in by the XML File.
class ModelClass {
    ////    Constructors and destructors    ////
    
public :

    ModelClass();
    
    ~ModelClass();
    
    ////    Operations    ////
    
    //## operation addAttribute(ModelClassAttribute)
    void addAttribute(ModelClassAttribute* p_ClassAttribute);
    
    //## operation addInstance(ModelInstance)
    void addInstance(ModelInstance* newInstance);
    
    //## operation addParent(ModelClass)
    void addParent(ModelClass* parentClass);
    
    //## operation addState(ModelClassState)
    void addState(ModelClassState* p_state);
    
    //## operation getClassAttributeList() const
    inline const QVector<ModelClassAttribute*>& getClassAttributeList() const;
    
    //## operation getFullPathName() const
    const QString& getFullPathName() const;
    
    //## operation getInstanceList() const
    inline const QHash<QString, ModelInstance*>& getInstanceList() const;
    
    //## operation getItsModelClassStateList()
    inline QVector<ModelClassState*>* getItsModelClassStateList();
    
    //## operation getName() const
    const QString& getName() const;
    
    //## operation getParents()
    inline QVector<ModelClass*>* getParents();
    
    //## operation getState(unsigned int)
    const QString& getState(unsigned int stateID);
    
    //## operation getState(QString)
    int getState(const QString& stateName);
    
    //## operation incrementInstanceCount()
    int incrementInstanceCount();
    
    //## operation resetAttributeOffset()
    void resetAttributeOffset();
    
    //## operation resetInstanceCount()
    void resetInstanceCount();
    
    //## operation setFullPathName(QString)
    void setFullPathName(const QString& p_fullPathName);
    
    //## operation setName(QString)
    void setName(const QString& p_name);
    
    ////    Additional operations    ////
    
    inline unsigned int getId() const
    {
        return id;
    }
    
    inline void setId(unsigned int p_id)
    {
        id = p_id;
    }
    
    inline bool getIsActive() const
    {
        return isActive;
    }
    
    inline void setIsActive(bool p_isActive)
    {
        isActive = p_isActive;
    }
    
    inline bool getIsReactive() const
    {
        return isReactive;
    }
    
    inline void setIsReactive(bool p_isReactive)
    {
        isReactive = p_isReactive;
    }
    
    inline unsigned int getParrallelStateCount() const
    {
        return parrallelStateCount;
    }
    
    inline void setParrallelStateCount(unsigned int p_parrallelStateCount)
    {
        parrallelStateCount = p_parrallelStateCount;
    }
    
    inline void clearItsClassAttributeList()
    {
        itsClassAttributeList.clear();
    }
    
    inline QVector<ModelClassState*>::const_iterator getItsModelClassStateList() const
    {
        QVector<ModelClassState*>::const_iterator iter = itsModelClassStateList.begin();
        return iter;
    }
    
    inline void clearItsModelClassStateList()
    {
        itsModelClassStateList.clear();
    }
    
    inline void clearItsModelGeneralisationList()
    {
        itsModelGeneralisationList.clear();
    }
    
    inline void clearItsModelInstanceList()
    {
        itsModelInstanceList.clear();
    }
    
    inline ModelInstance* getItsModelInstanceList(QString key) const
    {
        return itsModelInstanceList.value(key);
    }
    
    inline void removeItsModelInstanceList(QString key)
    {
        itsModelInstanceList.remove(key);
    }
    
    inline QStandardItem* getItsTreeViewItemDebugInt() const
    {
        return itsTreeViewItemDebugInt;
    }
    
    inline void setItsTreeViewItemDebugInt(QStandardItem* p_QStandardItem)
    {
        itsTreeViewItemDebugInt = p_QStandardItem;
    }
    
    inline QStandardItem* getItsTreeViewItemTarget() const
    {
        return itsTreeViewItemTarget;
    }
    
    inline void setItsTreeViewItemTarget(QStandardItem* p_QStandardItem)
    {
        itsTreeViewItemTarget = p_QStandardItem;
    }
    
    inline QStandardItem* getItsTreeViewItemTargetFilter() const
    {
        return itsTreeViewItemTargetFilter;
    }
    
    inline void setItsTreeViewItemTargetFilter(QStandardItem* p_QStandardItem)
    {
        itsTreeViewItemTargetFilter = p_QStandardItem;
    }
    
    inline ModelInstance* getLastInsertedInstance() const
    {
        return lastInsertedInstance;
    }
    
    inline void setLastInsertedInstance(ModelInstance* p_ModelInstance)
    {
        lastInsertedInstance = p_ModelInstance;
    }

protected :

    void cleanUpRelations();
    
    ////    Attributes    ////

private :

    QString fullPathName;		//## attribute fullPathName
    
    // Class ID generated by the Simplifier
    unsigned int id;		//## attribute id
    
    int instanceCount;		//## attribute instanceCount
    
    // Bool representing if class is active or not
    bool isActive;		//## attribute isActive
    
    // Bool representing if class uses a statemachine
    bool isReactive;		//## attribute isReactive
    
    QString name;		//## attribute name
    
    unsigned int parrallelStateCount;		//## attribute parrallelStateCount
    
    ////    Relations and components    ////

protected :

    QVector<ModelClassAttribute*> itsClassAttributeList;
    
    QVector<ModelClassState*> itsModelClassStateList;
    
    QVector<ModelClass*> itsModelGeneralisationList;
    
    QHash<QString, ModelInstance*> itsModelInstanceList;
    
    QStandardItem* itsTreeViewItemDebugInt;
    
    QStandardItem* itsTreeViewItemTarget;
    
    QStandardItem* itsTreeViewItemTargetFilter;
    
    ModelInstance* lastInsertedInstance;
};

inline const QVector<ModelClassAttribute*>& ModelClass::getClassAttributeList() const
{
    //#[ operation getClassAttributeList() const
    return this->itsClassAttributeList;
    //#]
}

inline const QHash<QString, ModelInstance*>& ModelClass::getInstanceList() const
{
    //#[ operation getInstanceList() const
    return this->itsModelInstanceList;
    //#]
}

inline QVector<ModelClassState*>* ModelClass::getItsModelClassStateList()
{
    //#[ operation getItsModelClassStateList()
    return &itsModelClassStateList;
    //#]
}

inline QVector<ModelClass*>* ModelClass::getParents()
{
    //#[ operation getParents()
    return &itsModelGeneralisationList;
    //#]
}

#endif
/*********************************************************************
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\ModelClass.h
*********************************************************************/
