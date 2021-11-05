/*********************************************************************
	Rhapsody	: 9.0.1 
	Login		: Y9DSYU706
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: CommandTraceEventKeyValueAdapter
//!	Generated Date	: Thu, 4, Nov 2021  
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\CommandTraceEventKeyValueAdapter.h
*********************************************************************/

#ifndef CommandTraceEventKeyValueAdapter_H
#define CommandTraceEventKeyValueAdapter_H

#include "KeyValueAdapter.h"
#include "AbstractCommandKeyValueAdapter.h"
class Command;

class CommandTraceEvent;

template <typename T> class QList;

class ReceivedEventParameter;

class TargetInformation;

//## package LogicLevel::Logging::Adapter::KeyValueAdapter

//## class CommandTraceEventKeyValueAdapter
class CommandTraceEventKeyValueAdapter : public AbstractCommandKeyValueAdapter {
    ////    Constructors and destructors    ////
    
public :

    //## operation CommandTraceEventKeyValueAdapter()
    CommandTraceEventKeyValueAdapter();
    
    virtual ~CommandTraceEventKeyValueAdapter();
    
    ////    Operations    ////

protected :

    //## operation addProperties(QHash<QString,QString>&,Command)
    virtual void addProperties(QHash<QString,QString>& keyValues, const Command& command);
};

#endif
/*********************************************************************
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\CommandTraceEventKeyValueAdapter.h
*********************************************************************/
