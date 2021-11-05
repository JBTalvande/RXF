/*********************************************************************
	Rhapsody	: 9.0.1 
	Login		: Y9DSYU706
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: MainWindowMessageLogger
//!	Generated Date	: Thu, 4, Nov 2021  
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\MainWindowMessageLogger.h
*********************************************************************/

#ifndef MainWindowMessageLogger_H
#define MainWindowMessageLogger_H

#include "Logging.h"
#include "MessageLogger.h"
class MainWindow;

//## package LogicLevel::Logging

//## class MainWindowMessageLogger
class MainWindowMessageLogger : public MessageLogger {
    ////    Constructors and destructors    ////
    
public :

    MainWindowMessageLogger();
    
    virtual ~MainWindowMessageLogger();
    
    ////    Operations    ////
    
    //## operation logError(QString)
    virtual void logError(const QString& errorMessage);
    
    //## operation logInfo(QString)
    virtual void logInfo(const QString& infoMessage);
    
    ////    Additional operations    ////
    
    inline MainWindow* getItsMainWindow() const
    {
        return itsMainWindow;
    }
    
    inline void setItsMainWindow(MainWindow* p_MainWindow)
    {
        itsMainWindow = p_MainWindow;
    }

protected :

    void cleanUpRelations();
    
    ////    Relations and components    ////
    
    MainWindow* itsMainWindow;
};

#endif
/*********************************************************************
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\MainWindowMessageLogger.h
*********************************************************************/
