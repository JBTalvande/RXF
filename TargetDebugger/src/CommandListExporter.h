/*********************************************************************
	Rhapsody	: 9.0.1 
	Login		: Y9DSYU706
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: CommandListExporter
//!	Generated Date	: Thu, 4, Nov 2021  
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\CommandListExporter.h
*********************************************************************/

#ifndef CommandListExporter_H
#define CommandListExporter_H

#include "Exporter.h"
#include "FileExporter.h"
#include <QXmlStreamWriter>
#include <QDateTime>
class CommandList;

class CommandXmlWriter;

class ModelClass;

class ModelDataType;

class ModelEventArgumentType;

class ModelEventType;

class ModelInstance;

class QFile;

class TargetInformation;

//## package LogicLevel::Exporter

//## class CommandListExporter
class CommandListExporter : public FileExporter {
    ////    Constructors and destructors    ////
    
public :

    CommandListExporter();
    
    virtual ~CommandListExporter();
    
    ////    Operations    ////
    
    //## operation setCommandList(CommandList)
    void setCommandList(const CommandList& p_CommandList);

protected :

    //## operation writeCommands(QXmlStreamWriter)
    void writeCommands(QXmlStreamWriter& xmlWriter);
    
    //## operation writeContent(QFile)
    virtual void writeContent(QFile& outFile);
    
    //## operation writeTargetInformation(QXmlStreamWriter)
    void writeTargetInformation(QXmlStreamWriter& xmlWriter);
    
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

protected :

    void cleanUpRelations();
    
    ////    Relations and components    ////
    
    CommandList* commandList;
};

#endif
/*********************************************************************
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\CommandListExporter.h
*********************************************************************/
