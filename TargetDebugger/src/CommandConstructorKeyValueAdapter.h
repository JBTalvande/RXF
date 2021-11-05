/*********************************************************************
	Rhapsody	: 9.0.1 
	Login		: Y9DSYU706
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: CommandConstructorKeyValueAdapter
//!	Generated Date	: Thu, 4, Nov 2021  
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\CommandConstructorKeyValueAdapter.h
*********************************************************************/

#ifndef CommandConstructorKeyValueAdapter_H
#define CommandConstructorKeyValueAdapter_H

#include "KeyValueAdapter.h"
#include "AbstractCommandKeyValueAdapter.h"
class Command;

class CommandConstructor;

class ModelClass;

class ModelInstance;

template <typename T> class QList;

class TargetInformation;

//## package LogicLevel::Logging::Adapter::KeyValueAdapter

//## class CommandConstructorKeyValueAdapter
class CommandConstructorKeyValueAdapter : public AbstractCommandKeyValueAdapter {
    ////    Constructors and destructors    ////
    
public :

    //## operation CommandConstructorKeyValueAdapter()
    CommandConstructorKeyValueAdapter();
    
    virtual ~CommandConstructorKeyValueAdapter();
    
    ////    Operations    ////

protected :

    //## operation addProperties(QHash<QString,QString>&,Command)
    virtual void addProperties(QHash<QString,QString>& keyValues, const Command& command);
};

#endif
/*********************************************************************
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\CommandConstructorKeyValueAdapter.h
*********************************************************************/
