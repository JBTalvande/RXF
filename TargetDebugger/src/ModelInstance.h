/*********************************************************************
	Rhapsody	: 9.0.1 
	Login		: Y9DSYU706
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: ModelInstance
//!	Generated Date	: Thu, 4, Nov 2021  
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\ModelInstance.h
*********************************************************************/

#ifndef ModelInstance_H
#define ModelInstance_H

#include <QString>
#include <QStandardItem>
class ModelClass;

class TargetInformation;

//## package RpyModelData

//## class ModelInstance
class ModelInstance {
    ////    Constructors and destructors    ////
    
public :

    //## operation ModelInstance(ModelClass,uint64_t,uint64_t,QString,TargetInformation)
    ModelInstance(ModelClass* baseClass, uint64_t objectAddress, uint64_t firstAttributeAddress, const QString& instanceName, TargetInformation* target);
    
    ModelInstance();
    
    ~ModelInstance();
    
    ////    Operations    ////
    
    //## operation getName() const
    const QString& getName() const;
    
    ////    Additional operations    ////
    
    inline uint64_t getAddress() const
    {
        return address;
    }
    
    inline void setAddress(uint64_t p_address)
    {
        address = p_address;
    }
    
    inline uint64_t getFirstAttributeAddress() const
    {
        return firstAttributeAddress;
    }
    
    inline void setFirstAttributeAddress(uint64_t p_firstAttributeAddress)
    {
        firstAttributeAddress = p_firstAttributeAddress;
    }
    
    inline bool getIsBaseClass() const
    {
        return isBaseClass;
    }
    
    inline void setIsBaseClass(bool p_isBaseClass)
    {
        isBaseClass = p_isBaseClass;
    }
    
    inline QStandardItem* getStateItemInModelTree() const
    {
        return stateItemInModelTree;
    }
    
    inline void setStateItemInModelTree(QStandardItem* p_stateItemInModelTree)
    {
        stateItemInModelTree = p_stateItemInModelTree;
    }
    
    inline ModelClass* getItsModelClass() const
    {
        return itsModelClass;
    }
    
    inline void setItsModelClass(ModelClass* p_ModelClass)
    {
        itsModelClass = p_ModelClass;
    }
    
    inline TargetInformation* getItsTargetInformation() const
    {
        return itsTargetInformation;
    }
    
    inline void setItsTargetInformation(TargetInformation* p_TargetInformation)
    {
        itsTargetInformation = p_TargetInformation;
    }

protected :

    void cleanUpRelations();
    
    ////    Attributes    ////

private :

    uint64_t address;		//## attribute address
    
    uint64_t firstAttributeAddress;		//## attribute firstAttributeAddress
    
    bool isBaseClass;		//## attribute isBaseClass
    
    QString name;		//## attribute name
    
    QStandardItem* stateItemInModelTree;		//## attribute stateItemInModelTree
    
    ////    Relations and components    ////

protected :

    ModelClass* itsModelClass;
    
    TargetInformation* itsTargetInformation;
};

#endif
/*********************************************************************
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\ModelInstance.h
*********************************************************************/
