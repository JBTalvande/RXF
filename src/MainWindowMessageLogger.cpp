/********************************************************************
	Rhapsody	: 9.0.1 
	Login		: Y9DSYU706
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: MainWindowMessageLogger
//!	Generated Date	: Thu, 4, Nov 2021  
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\MainWindowMessageLogger.cpp
*********************************************************************/

#include "MainWindowMessageLogger.h"
#include "MainWindow.h"
//## package LogicLevel::Logging

//## class MainWindowMessageLogger
MainWindowMessageLogger::MainWindowMessageLogger()
{
    itsMainWindow = NULL;
}

MainWindowMessageLogger::~MainWindowMessageLogger()
{
    cleanUpRelations();
}

void MainWindowMessageLogger::logError(const QString& errorMessage)
{
    //#[ operation logError(QString)
    this->itsMainWindow->errorMsg(errorMessage);
    //#]
}

void MainWindowMessageLogger::logInfo(const QString& infoMessage)
{
    //#[ operation logInfo(QString)
    this->itsMainWindow->consoleMsg(infoMessage);
    //#]
}

void MainWindowMessageLogger::cleanUpRelations()
{
    if(itsMainWindow != NULL)
        {
            itsMainWindow = NULL;
        }
}

/*********************************************************************
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\MainWindowMessageLogger.cpp
*********************************************************************/
