/*********************************************************************
	Rhapsody	: 9.0.1 
	Login		: Y9DSYU706
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: MessageLogger
//!	Generated Date	: Thu, 4, Nov 2021  
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\MessageLogger.h
*********************************************************************/

#ifndef MessageLogger_H
#define MessageLogger_H

#include "Logging.h"
//## package LogicLevel::Logging

//## class MessageLogger
class MessageLogger {
    ////    Constructors and destructors    ////
    
public :

    MessageLogger();
    
    virtual ~MessageLogger();
    
    ////    Operations    ////
    
    //## operation logError(QString)
    inline virtual void logError(const QString& errorMessage);
    
    //## operation logInfo(QString)
    virtual void logInfo(const QString& infoMessage) = 0;
};

inline void MessageLogger::logError(const QString& errorMessage)
{
    //#[ operation logError(QString)
    this->logInfo("ERROR: " + errorMessage);
    //#]
}

#endif
/*********************************************************************
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\MessageLogger.h
*********************************************************************/
