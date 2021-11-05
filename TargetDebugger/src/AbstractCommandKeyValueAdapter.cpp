/********************************************************************
	Rhapsody	: 9.0.1 
	Login		: Y9DSYU706
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: AbstractCommandKeyValueAdapter
//!	Generated Date	: Thu, 4, Nov 2021  
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\AbstractCommandKeyValueAdapter.cpp
*********************************************************************/

#include "AbstractCommandKeyValueAdapter.h"
#include <QList.h>
#include "ReceivedEventParameter.h"
#include "TargetInformation.h"
//## package LogicLevel::Logging::Adapter::KeyValueAdapter

//## class AbstractCommandKeyValueAdapter
AbstractCommandKeyValueAdapter::AbstractCommandKeyValueAdapter(const Command::commandType& p_commandType) : CommandAdapter(p_commandType)
{
    //#[ operation AbstractCommandKeyValueAdapter(commandType)
    //#]
}

AbstractCommandKeyValueAdapter::AbstractCommandKeyValueAdapter()
{
}

AbstractCommandKeyValueAdapter::~AbstractCommandKeyValueAdapter()
{
}

QHash<QString, QString> AbstractCommandKeyValueAdapter::adapt(const Command& command)
{
    //#[ operation adapt(Command)
    QHash<QString, QString> keyValueList;
    
    // add commandType as default value
    keyValueList.insert("commandType", QString::number(command.getCommandIdentifier()));
    
    // add additional properties by specialized KeyValueAdapters
    this->addProperties(keyValueList, command);
    
    return keyValueList;
    //#]
}

QString AbstractCommandKeyValueAdapter::computeReceivedEventParametersString(const QVector<ReceivedEventParameter*>& receivedEventParameters)
{
    //#[ operation computeReceivedEventParametersString(ReceivedEventParameter)
    QString receivedEventParametersString = "";
    
    if(receivedEventParameters.empty() == false)
    {
    	for(auto eventParameter : receivedEventParameters)
    	{
    	    // name=value
    	    receivedEventParametersString.append(QString(", %1=%2").arg(
    	                                       eventParameter->getItsModelEventArgumentType()->getName(),
    	                                       eventParameter->getValue()));
    	}
    	// replace first colon with [
    	receivedEventParametersString.replace(0, 1, '[');
    	receivedEventParametersString.append(" ]");
    }
    
    return receivedEventParametersString;
    //#]
}

/*********************************************************************
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\AbstractCommandKeyValueAdapter.cpp
*********************************************************************/
