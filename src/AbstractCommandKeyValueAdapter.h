/*********************************************************************
	Rhapsody	: 9.0.1 
	Login		: Y9DSYU706
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: AbstractCommandKeyValueAdapter
//!	Generated Date	: Thu, 4, Nov 2021  
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\AbstractCommandKeyValueAdapter.h
*********************************************************************/

#ifndef AbstractCommandKeyValueAdapter_H
#define AbstractCommandKeyValueAdapter_H

#include "KeyValueAdapter.h"
#include "Command.h"
#include "CommandAdapter.h"
#include <QPair.h>
template <typename T> class QList;

class ReceivedEventParameter;

class TargetInformation;

//## package LogicLevel::Logging::Adapter::KeyValueAdapter

//## class AbstractCommandKeyValueAdapter
// Adapts a command to a key value pair list. The keys are usually the name of the properties while the values are the values to these properties.
// This class is intended to be overridden and override addProperties() to add the key values for their properties to the keyValueList.
class AbstractCommandKeyValueAdapter : public CommandAdapter<QHash<QString, QString>> {
    ////    Constructors and destructors    ////
    
public :

    // Argument const Command::commandType& p_commandType :
    // the commandType for this Adapter
    //## operation AbstractCommandKeyValueAdapter(commandType)
    AbstractCommandKeyValueAdapter(const Command::commandType& p_commandType);
    
    AbstractCommandKeyValueAdapter();
    
    virtual ~AbstractCommandKeyValueAdapter();
    
    ////    Operations    ////
    
    //## operation adapt(Command)
    virtual QHash<QString, QString> adapt(const Command& command);

protected :

    // Adds properties to the given QPair if applicable. This method is intended to be overridden by specialized KeyValueAdapter
    //## operation addProperties(QHash<QString,QString>&,Command)
    virtual void addProperties(QHash<QString,QString>& keyValueList, const Command& command) = 0;
    
    //## operation computeReceivedEventParametersString(ReceivedEventParameter)
    static QString computeReceivedEventParametersString(const QVector<ReceivedEventParameter*>& receivedEventParameters);
};

#endif
/*********************************************************************
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\AbstractCommandKeyValueAdapter.h
*********************************************************************/
