/*********************************************************************
	Rhapsody	: 9.0.1 
	Login		: Y9DSYU706
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: TargetInformation
//!	Generated Date	: Thu, 4, Nov 2021  
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\TargetInformation.h
*********************************************************************/

#ifndef TargetInformation_H
#define TargetInformation_H

#include "Logging.h"
#include <QHash>
#include "LogicLevel.h"
#include "ModelClass.h"
#include "ModelClassState.h"
#include "ModelDataType.h"
#include "ModelEventType.h"
#include "ModelInstance.h"
#include <QString>
#include <QList>
class MainWindow;

class ModelClassAttribute;

//## package LogicLevel::Logging

//## class TargetInformation
class TargetInformation {
public :

    enum ReceiveTypePosition {
        First,
        Inbetween,
        Last
    };
    
    ////    Constructors and destructors    ////
    
    //## operation TargetInformation(QString,bool,int)
    TargetInformation(const QString& name, bool isSingleTarget, int id);
    
    ~TargetInformation();
    
    ////    Operations    ////
    
    //## operation addClass(ModelClass)
    void addClass(ModelClass* newClass);
    
    //## operation addEventType(ModelEventType)
    void addEventType(ModelEventType* eventType);
    
    //## operation addType(QString,int,int)
    void addType(const QString& name, int size, int index);
    
    //## operation clearEventTypeList()
    void clearEventTypeList();
    
    //## operation getClass(unsigned int)
    ModelClass* getClass(unsigned int classID);
    
    //## operation getClassByFullPath(QString)
    ModelClass* getClassByFullPath(const QString& name);
    
    //## operation getEventId(QString)
    int getEventId(const QString& eventName);
    
    //## operation getEventType(unsigned int)
    ModelEventType* getEventType(unsigned int eventID);
    
    //## operation getEventType(QString) const
    const ModelEventType* getEventType(const QString& p_name) const;
    
    //## operation getInstance(uint64_t)
    ModelInstance* getInstance(uint64_t address);
    
    //## operation getInstance(QString)
    ModelInstance* getInstance(const QString& instanceName);
    
    //## operation getModelClassList() const
    inline const QHash<unsigned int, ModelClass*>& getModelClassList() const;
    
    //## operation getModelEventTypeList() const
    const QHash<QString, ModelEventType*> getModelEventTypeList() const;
    
    //## operation getName() const
    inline const QString& getName() const;
    
    //## operation getTypePtr(QString)
    ModelDataType* getTypePtr(const QString& typeName);
    
    //## operation getTypeSize(QString)
    int getTypeSize(const QString& typeName);
    
    //## operation searchTargetClassAndCreateObject(unsigned int,uint64_t,uint64_t)
    ModelInstance* searchTargetClassAndCreateObject(unsigned int classID, uint64_t objectAddress, uint64_t firstAttributeAddress);
    
    //## operation setName(QString)
    void setName(const QString& p_name);
    
    //## operation updateClassAttributes()
    void updateClassAttributes();
    
    //## operation updateTypeSize(unsigned int)
    ReceiveTypePosition updateTypeSize(unsigned int value);
    
    ////    Additional operations    ////
    
    inline endianness getEndianess() const
    {
        return endianess;
    }
    
    inline void setEndianess(endianness p_endianess)
    {
        endianess = p_endianess;
    }
    
    inline int getId() const
    {
        return id;
    }
    
    inline void setId(int p_id)
    {
        id = p_id;
    }
    
    inline bool getInReset() const
    {
        return inReset;
    }
    
    inline void setInReset(bool p_inReset)
    {
        inReset = p_inReset;
    }
    
    inline unsigned int getIncommingTypeNr() const
    {
        return incommingTypeNr;
    }
    
    inline void setIncommingTypeNr(unsigned int p_incommingTypeNr)
    {
        incommingTypeNr = p_incommingTypeNr;
    }
    
    inline bool getInitilized() const
    {
        return initilized;
    }
    
    inline void setInitilized(bool p_initilized)
    {
        initilized = p_initilized;
    }
    
    inline unsigned int getParallelStateCount() const
    {
        return parallelStateCount;
    }
    
    inline void setParallelStateCount(unsigned int p_parallelStateCount)
    {
        parallelStateCount = p_parallelStateCount;
    }
    
    inline unsigned int getPointerSize() const
    {
        return pointerSize;
    }
    
    inline void setPointerSize(unsigned int p_pointerSize)
    {
        pointerSize = p_pointerSize;
    }
    
    inline bool getSingleTarget() const
    {
        return singleTarget;
    }
    
    inline void setSingleTarget(bool p_singleTarget)
    {
        singleTarget = p_singleTarget;
    }
    
    inline int getStateSize() const
    {
        return stateSize;
    }
    
    inline void setStateSize(int p_stateSize)
    {
        stateSize = p_stateSize;
    }
    
    inline unsigned int getTimeOffset() const
    {
        return timeOffset;
    }
    
    inline void setTimeOffset(unsigned int p_timeOffset)
    {
        timeOffset = p_timeOffset;
    }
    
    inline ModelInstance* getEnvironment() const
    {
        return (ModelInstance*) &environment;
    }
    
    inline static MainWindow* getItsMainWindow()
    {
        return itsMainWindow;
    }
    
    inline static void setItsMainWindow(MainWindow* p_MainWindow)
    {
        itsMainWindow = p_MainWindow;
    }
    
    inline void clearItsModelClassList()
    {
        itsModelClassList.clear();
    }
    
    inline ModelClass* getItsModelClassList(unsigned int key) const
    {
        return itsModelClassList.value(key);
    }
    
    inline void removeItsModelClassList(unsigned int key)
    {
        itsModelClassList.remove(key);
    }
    
    inline void clearItsModelDataTypeList()
    {
        itsModelDataTypeList.clear();
    }
    
    inline ModelDataType* getItsModelDataTypeList(QString key) const
    {
        return itsModelDataTypeList.value(key);
    }
    
    inline void removeItsModelDataTypeList(QString key)
    {
        itsModelDataTypeList.remove(key);
    }
    
    inline void clearItsModelEventTypeList()
    {
        itsModelEventTypeList.clear();
    }
    
    inline ModelEventType* getItsModelEventTypeList(QString key) const
    {
        return itsModelEventTypeList.value(key);
    }
    
    inline void removeItsModelEventTypeList(QString key)
    {
        itsModelEventTypeList.remove(key);
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
    
    inline ModelInstance* getLastModelInstance() const
    {
        return lastModelInstance;
    }
    
    inline void setLastModelInstance(ModelInstance* p_ModelInstance)
    {
        lastModelInstance = p_ModelInstance;
    }
    
    inline ModelEventType* getNullEvent() const
    {
        return (ModelEventType*) &nullEvent;
    }
    
    inline ModelEventType* getStartBehaviourEvent() const
    {
        return (ModelEventType*) &startBehaviourEvent;
    }
    
    inline ModelEventType* getTimeOutEvent() const
    {
        return (ModelEventType*) &timeOutEvent;
    }
    
    inline ModelClass* getUnknownClass() const
    {
        return (ModelClass*) &unknownClass;
    }
    
    inline ModelClassState* getUnknownClassState() const
    {
        return (ModelClassState*) &unknownClassState;
    }
    
    inline ModelDataType* getUnknownDataType() const
    {
        return (ModelDataType*) &unknownDataType;
    }

protected :

    void cleanUpRelations();
    
    ////    Attributes    ////

private :

    endianness endianess;		//## attribute endianess
    
    int id;		//## attribute id
    
    bool inReset;		//## attribute inReset
    
    unsigned int incommingTypeNr;		//## attribute incommingTypeNr
    
    bool initilized;		//## attribute initilized
    
    QString name;		//## attribute name
    
    unsigned int parallelStateCount;		//## attribute parallelStateCount
    
    unsigned int pointerSize;		//## attribute pointerSize
    
    bool singleTarget;		//## attribute singleTarget
    
    int stateSize;		//## attribute stateSize
    
    unsigned int timeOffset;		//## attribute timeOffset
    
    ////    Relations and components    ////

protected :

    ModelInstance environment;
    
    static MainWindow* itsMainWindow;
    
    // The content of this list must not be deleted when the list is cleared, because it might be used in the GUI even the list clears its content.
    QHash<unsigned int, ModelClass*> itsModelClassList;
    
    // The content of this list must not be deleted when the list is cleared, because it might be used in the GUI even the list clears its content.
    QHash<QString, ModelDataType*> itsModelDataTypeList;
    
    QHash<QString, ModelEventType*> itsModelEventTypeList;
    
    QStandardItem* itsTreeViewItemDebugInt;
    
    QStandardItem* itsTreeViewItemTarget;
    
    QStandardItem* itsTreeViewItemTargetFilter;
    
    ModelInstance* lastModelInstance;
    
    ModelEventType nullEvent;
    
    ModelEventType startBehaviourEvent;
    
    ModelEventType timeOutEvent;
    
    ModelClass unknownClass;
    
    ModelClassState unknownClassState;
    
    ModelDataType unknownDataType;
};

inline const QHash<unsigned int, ModelClass*>& TargetInformation::getModelClassList() const
{
    //#[ operation getModelClassList() const
    return this->itsModelClassList;
    //#]
}

inline const QString& TargetInformation::getName() const
{
    //#[ operation getName() const
    return name;
    //#]
}

#endif
/*********************************************************************
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\TargetInformation.h
*********************************************************************/
