/********************************************************************
	Rhapsody	: 9.0.1 
	Login		: Y9DSYU706
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: CommandsExporter
//!	Generated Date	: Thu, 4, Nov 2021  
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\CommandsExporter.cpp
*********************************************************************/

#include "CommandsExporter.h"
#include "CommandStringAdapterRegistry.h"
#include <QFile.h>
//## package LogicLevel::Exporter

//## class CommandsExporter
CommandsExporter::CommandsExporter()
{
    itsCommandStringAdapterRegistry = NULL;
}

CommandsExporter::~CommandsExporter()
{
    cleanUpRelations();
}

void CommandsExporter::writeContent(QFile& outFile)
{
    //#[ operation writeContent(QFile)
    unsigned int count = 0;
    QTextStream outStream(&outFile);
    
    for(auto command : this->commands)
    {
        ++count;
        QString writeString = QString("%1: ").arg(QString::number(count));
        CommandAdapter<QString>* adapter = this->itsCommandStringAdapterRegistry->getCommandAdapters(command->getCommandIdentifier());
        if(adapter != NULL)
        {
            writeString = writeString + adapter->adapt(*command);
        }
        else
        {
            writeString = writeString + "Unknown Command or missing output adapter for Command";
        }
        outStream << writeString << endl;
    }
    //#]
}

void CommandsExporter::cleanUpRelations()
{
    {
        commands.clear();
    }
    if(itsCommandStringAdapterRegistry != NULL)
        {
            itsCommandStringAdapterRegistry = NULL;
        }
}

/*********************************************************************
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\CommandsExporter.cpp
*********************************************************************/
