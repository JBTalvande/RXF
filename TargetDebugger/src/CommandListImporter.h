/*********************************************************************
	Rhapsody	: 9.0.1 
	Login		: Y9DSYU706
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: CommandListImporter
//!	Generated Date	: Thu, 4, Nov 2021  
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\CommandListImporter.h
*********************************************************************/

#ifndef CommandListImporter_H
#define CommandListImporter_H

#include "Importer.h"
#include "FileImporter.h"
#include <QXmlStreamReader>
class CommandList;

class CommandXmlReader;

class ModelClass;

class ModelDataType;

class ModelEventArgumentType;

class ModelEventType;

class ModelInstance;

class QFile;

class QFileInfo;

class TargetInformation;

class TargetList;

//## package LogicLevel::Importer

//## class CommandListImporter
class CommandListImporter : public FileImporter {
    ////    Constructors and destructors    ////
    
public :

    CommandListImporter();
    
    virtual ~CommandListImporter();
    
    ////    Operations    ////

protected :

    //## operation readCommands(QXmlStreamReader)
    void readCommands(QXmlStreamReader& xmlReader);
    
    //## operation readContent(QFile)
    virtual void readContent(QFile& inFile);
    
    //## operation readModelClasses(QXmlStreamReader,TargetInformation)
    void readModelClasses(QXmlStreamReader& xmlReader, TargetInformation& targetInformation);
    
    //## operation readModelEventTypes(QXmlStreamReader,TargetInformation)
    void readModelEventTypes(QXmlStreamReader& xmlReader, TargetInformation& targetInformation);
    
    //## operation readModelInstances(QXmlStreamReader,ModelClass,TargetInformation)
    void readModelInstances(QXmlStreamReader& xmlReader, ModelClass& modelClass, TargetInformation& targetInformation);
    
    //## operation readTargetInformation(QXmlStreamReader)
    void readTargetInformation(QXmlStreamReader& xmlReader);
    
    ////    Additional operations    ////

public :

    inline CommandList* getCommandList() const
    {
        return commandList;
    }
    
    inline void setCommandList(CommandList* p_CommandList)
    {
        commandList = p_CommandList;
    }
    
    inline TargetList* getItsTargetList() const
    {
        return itsTargetList;
    }
    
    inline void setItsTargetList(TargetList* p_TargetList)
    {
        itsTargetList = p_TargetList;
    }

protected :

    void cleanUpRelations();
    
    ////    Relations and components    ////
    
    CommandList* commandList;
    
    TargetList* itsTargetList;
};

#endif
/*********************************************************************
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\CommandListImporter.h
*********************************************************************/
