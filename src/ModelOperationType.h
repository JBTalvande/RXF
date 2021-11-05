/*********************************************************************
	Rhapsody	: 9.0.1 
	Login		: Y9DSYU706
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: ModelOperationType
//!	Generated Date	: Thu, 4, Nov 2021  
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\ModelOperationType.h
*********************************************************************/

#ifndef ModelOperationType_H
#define ModelOperationType_H

#include "ModelEventType.h"
class TargetInformation;

//## package RpyModelData

//## class ModelOperationType
class ModelOperationType : public ModelEventType {
    ////    Constructors and destructors    ////
    
public :

    //## operation ModelOperationType(QString,int,TargetInformation)
    ModelOperationType(const QString& p_name, int id, TargetInformation* target);
    
    ModelOperationType();
    
    virtual ~ModelOperationType();
    
    ////    Operations    ////
    
    //## operation isOperation()
    virtual bool isOperation();
};

#endif
/*********************************************************************
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\ModelOperationType.h
*********************************************************************/
