/********************************************************************
	Rhapsody	: 9.0.1 
	Login		: Y9DSYU706
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: FileImporter
//!	Generated Date	: Thu, 4, Nov 2021  
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\FileImporter.cpp
*********************************************************************/

#include "FileImporter.h"
#include "MessageLogger.h"
#include <QFile.h>
//## package LogicLevel::Importer

//## class FileImporter
FileImporter::FileImporter()
{
    itsMessageLogger = NULL;
}

FileImporter::~FileImporter()
{
    cleanUpRelations();
}

void FileImporter::doImport()
{
    //#[ operation doImport()
    this->itsMessageLogger->logInfo("Importing Data from " + this->targetFileName + "...");
    QFile inFile(this->targetFileName);
    if(!inFile.open(QIODevice::ReadOnly))
    {
        this->itsMessageLogger->logError("Cannot open file for reading: " + inFile.errorString());
    }
    else {
        this->readContent(inFile);
    
        inFile.close();
        this->itsMessageLogger->logInfo("Import Data from " + this->targetFileName + " finished!");
    }
    //#]
}

void FileImporter::logInfo(const QString& infoMessage)
{
    //#[ operation logInfo(QString)
    if(this->itsMessageLogger != NULL)
    {
    	this->itsMessageLogger->logInfo(infoMessage);
    }	
    //#]
}

void FileImporter::cleanUpRelations()
{
    if(itsMessageLogger != NULL)
        {
            itsMessageLogger = NULL;
        }
}

/*********************************************************************
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\FileImporter.cpp
*********************************************************************/
