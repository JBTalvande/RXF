/*********************************************************************
	Rhapsody	: 9.0.1 
	Login		: Y9DSYU706
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: ModelEventType
//!	Generated Date	: Thu, 4, Nov 2021  
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\ModelEventType.h
*********************************************************************/

#ifndef ModelEventType_H
#define ModelEventType_H

#include <QVector>
#include "ModelEventArgumentType.h"
#include <QString>
class ModelDataType;

class TargetInformation;

//## package RpyModelData

//## class ModelEventType
class ModelEventType {
    ////    Constructors and destructors    ////
    
public :

    //## operation ModelEventType(QString,int,TargetInformation)
    ModelEventType(const QString& p_name, int id, TargetInformation* target);
    
    ModelEventType();
    
    virtual ~ModelEventType();
    
    ////    Operations    ////
    
    //## operation addArgument(QString,ModelDataType)
    void addArgument(const QString& argumentName, ModelDataType* argumentType);
    
    //## operation getArguments() const
    const QVector<ModelEventArgumentType*>& getArguments() const;
    
    //## operation getName() const
    const QString& getName() const;
    
    //## operation isOperation()
    virtual bool isOperation();
    
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
    
    inline void clearItsArguments()
    {
        itsArguments.clear();
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

    unsigned int id;		//## attribute id
    
    QString name;		//## attribute name
    
    ////    Relations and components    ////

protected :

    QVector<ModelEventArgumentType*> itsArguments;
    
    TargetInformation* itsTargetInformation;
};

#endif
/*********************************************************************
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\ModelEventType.h
*********************************************************************/
