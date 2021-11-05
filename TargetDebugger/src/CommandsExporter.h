/*********************************************************************
	Rhapsody	: 9.0.1 
	Login		: Y9DSYU706
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: CommandsExporter
//!	Generated Date	: Thu, 4, Nov 2021  
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\CommandsExporter.h
*********************************************************************/

#ifndef CommandsExporter_H
#define CommandsExporter_H

#include "Exporter.h"
#include <QList>
#include "Command.h"
#include "FileExporter.h"
#include <QTextStream.h>
class CommandStringAdapterRegistry;

class QFile;

//## package LogicLevel::Exporter

//## class CommandsExporter
class CommandsExporter : public FileExporter {
    ////    Constructors and destructors    ////
    
public :

    CommandsExporter();
    
    virtual ~CommandsExporter();
    
    ////    Operations    ////
    
    //## operation setCommands(Command)
    inline void setCommands(const QList<Command*>& p_commands);

protected :

    //## operation writeContent(QFile)
    virtual void writeContent(QFile& outFile);
    
    ////    Additional operations    ////

public :

    inline CommandStringAdapterRegistry* getItsCommandStringAdapterRegistry() const
    {
        return itsCommandStringAdapterRegistry;
    }
    
    inline void setItsCommandStringAdapterRegistry(CommandStringAdapterRegistry* p_CommandStringAdapterRegistry)
    {
        itsCommandStringAdapterRegistry = p_CommandStringAdapterRegistry;
    }

protected :

    void cleanUpRelations();
    
    ////    Relations and components    ////
    
    QList<Command*> commands;
    
    CommandStringAdapterRegistry* itsCommandStringAdapterRegistry;
};

inline void CommandsExporter::setCommands(const QList<Command*>& p_commands)
{
    //#[ operation setCommands(Command)
    this->commands = p_commands;
    //#]
}

#endif
/*********************************************************************
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\CommandsExporter.h
*********************************************************************/
