/********************************************************************
	Rhapsody	: 9.0.1 
	Login		: Y9DSYU706
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: ReceivedEventParameter
//!	Generated Date	: Thu, 4, Nov 2021  
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\ReceivedEventParameter.cpp
*********************************************************************/

#include "ReceivedEventParameter.h"
#include "ModelEventArgumentType.h"
//## package LogicLevel::Logging::DataContainer

//## class ReceivedEventParameter
ReceivedEventParameter::ReceivedEventParameter(ModelEventArgumentType* parameterType, const QString& value)
{
    itsModelEventArgumentType = parameterType;
    //#[ operation ReceivedEventParameter(ModelEventArgumentType,QString)
    this->value = value;
    //#]
}

ReceivedEventParameter::~ReceivedEventParameter()
{
    cleanUpRelations();
}

void ReceivedEventParameter::cleanUpRelations()
{
    if(itsModelEventArgumentType != NULL)
        {
            itsModelEventArgumentType = NULL;
        }
}

/*********************************************************************
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\ReceivedEventParameter.cpp
*********************************************************************/
