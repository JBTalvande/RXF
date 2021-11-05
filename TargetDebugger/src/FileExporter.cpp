/********************************************************************
	Rhapsody	: 9.0.1 
	Login		: Y9DSYU706
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: FileExporter
//!	Generated Date	: Thu, 4, Nov 2021  
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\FileExporter.cpp
*********************************************************************/

#include "FileExporter.h"
#include "MessageLogger.h"
#include <QFile.h>
//## package LogicLevel::Exporter

//## class FileExporter
FileExporter::FileExporter()
{
    itsMessageLogger = NULL;
}

FileExporter::~FileExporter()
{
    cleanUpRelations();
}

void FileExporter::doExport()
{
    //#[ operation doExport()
    this->itsMessageLogger->logInfo("Exporting Commands to " + this->targetFileName + "...");
    QFile outFile(this->targetFileName);
    if(!outFile.open(QIODevice::WriteOnly))
    {
        this->itsMessageLogger->logError("Cannot open file for writing: " + outFile.errorString());
    }
    else {
        this->writeContent(outFile);
    
        outFile.close();
        this->itsMessageLogger->logInfo("Export Commands to " + this->targetFileName + " finished successfully!");
    }
    //#]
}

void FileExporter::logInfo(const QString& infoMessage)
{
    //#[ operation logInfo(QString)
    if(this->itsMessageLogger != NULL)
    {
    	this->itsMessageLogger->logInfo(infoMessage);
    }	
    //#]
}

void FileExporter::cleanUpRelations()
{
    if(itsMessageLogger != NULL)
        {
            itsMessageLogger = NULL;
        }
}

/*********************************************************************
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\FileExporter.cpp
*********************************************************************/
