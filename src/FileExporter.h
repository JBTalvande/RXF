/*********************************************************************
	Rhapsody	: 9.0.1 
	Login		: Y9DSYU706
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: FileExporter
//!	Generated Date	: Thu, 4, Nov 2021  
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\FileExporter.h
*********************************************************************/

#ifndef FileExporter_H
#define FileExporter_H

#include "Exporter.h"
#include "AbstractExporter.h"
class MessageLogger;

class QFile;

//## package LogicLevel::Exporter

//## class FileExporter
// This class represents an exporter for a file as target. This class is intended to be overridden. Specialized class of this should only override writeContent() to provide the content of the file.
class FileExporter : public AbstractExporter {
    ////    Constructors and destructors    ////
    
public :

    FileExporter();
    
    virtual ~FileExporter();
    
    ////    Operations    ////
    
    //## operation doExport()
    virtual void doExport();
    
    //## operation logInfo(QString)
    void logInfo(const QString& infoMessage);

protected :

    //## operation writeContent(QFile)
    virtual void writeContent(QFile& outFile) = 0;
    
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
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\FileExporter.h
*********************************************************************/
