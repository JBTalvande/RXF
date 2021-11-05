/*********************************************************************
	Rhapsody	: 9.0.1 
	Login		: Y9DSYU706
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: FileImporter
//!	Generated Date	: Thu, 4, Nov 2021  
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\FileImporter.h
*********************************************************************/

#ifndef FileImporter_H
#define FileImporter_H

#include "Importer.h"
#include "AbstractImporter.h"
class MessageLogger;

class QFile;

//## package LogicLevel::Importer

//## class FileImporter
// This class represents an exporter for a file as target. This class is intended to be overridden. Specialized class of this should only override writeContent() to provide the content of the file.
class FileImporter : public AbstractImporter {
    ////    Constructors and destructors    ////
    
public :

    FileImporter();
    
    virtual ~FileImporter();
    
    ////    Operations    ////
    
    //## operation doImport()
    virtual void doImport();
    
    //## operation logInfo(QString)
    void logInfo(const QString& infoMessage);

protected :

    //## operation readContent(QFile)
    virtual void readContent(QFile& inFile) = 0;
    
    ////    Additional operations    ////

public :

    inline QString getTargetFileName() const
    {
        return targetFileName;
    }
    
    inline void setTargetFileName(QString p_targetFileName)
    {
        targetFileName = p_targetFileName;
    }
    
    inline MessageLogger* getItsMessageLogger() const
    {
        return itsMessageLogger;
    }
    
    inline void setItsMessageLogger(MessageLogger* p_MessageLogger)
    {
        itsMessageLogger = p_MessageLogger;
    }

protected :

    void cleanUpRelations();
    
    ////    Attributes    ////

public :

    QString targetFileName;		//## attribute targetFileName
    
    ////    Relations and components    ////

protected :

    MessageLogger* itsMessageLogger;
};

#endif
/*********************************************************************
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\FileImporter.h
*********************************************************************/
