/********************************************************************
	Rhapsody	: 9.0.1 
	Login		: Y9DSYU706
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: CommandListExporter
//!	Generated Date	: Thu, 4, Nov 2021  
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\CommandListExporter.cpp
*********************************************************************/

#include "CommandListExporter.h"
#include "CommandList.h"
#include "CommandXmlWriter.h"
#include "ModelClass.h"
#include "ModelDataType.h"
#include "ModelEventArgumentType.h"
#include "ModelEventType.h"
#include "ModelInstance.h"
#include <QFile.h>
#include "TargetInformation.h"
//## package LogicLevel::Exporter

//## class CommandListExporter
CommandListExporter::CommandListExporter()
{
    commandList = NULL;
}

CommandListExporter::~CommandListExporter()
{
    cleanUpRelations();
}

void CommandListExporter::setCommandList(const CommandList& p_CommandList)
{
    //#[ operation setCommandList(CommandList)
    // TODO: urgently avoid this by copying CommandList or at least its content
    commandList = const_cast<CommandList*>(&p_CommandList);
    //#]
}

void CommandListExporter::writeCommands(QXmlStreamWriter& xmlWriter)
{
    //#[ operation writeCommands(QXmlStreamWriter)
    xmlWriter.writeStartElement("Commands");
    
    // use CommandXmlWriter to write commands regarding their specific type
    CommandXmlWriter commandXmlWriter(xmlWriter);
    for(auto command : this->commandList->getCommands())
    {
        commandXmlWriter.writeCommand(*command);
    }
    xmlWriter.writeEndElement();
    //#]
}

void CommandListExporter::writeContent(QFile& outFile)
{
    //#[ operation writeContent(QFile)
    QXmlStreamWriter xmlWriter(&outFile);     
    
    xmlWriter.setAutoFormatting(true);
    xmlWriter.writeStartDocument();
    xmlWriter.writeDefaultNamespace("http://willert.de/TargetDebugger/1.0");
    
    xmlWriter.writeStartElement("ViewData");
    xmlWriter.writeAttribute("saveDate", QDateTime::currentDateTime().toString());
    
    xmlWriter.writeStartElement("TargetInformations");
    this->writeTargetInformation(xmlWriter);
    xmlWriter.writeEndElement();
    
    // write command list data
    xmlWriter.writeStartElement("CommandList");
    this->writeCommands(xmlWriter);
    xmlWriter.writeEndElement(); // CommandList
    
    xmlWriter.writeEndElement(); // ViewData
    //#]
}

void CommandListExporter::writeTargetInformation(QXmlStreamWriter& xmlWriter)
{
    //#[ operation writeTargetInformation(QXmlStreamWriter)
    QSet<TargetInformation*> targetInformations;
    // compute all targetInformations for contained commands
    for(auto command : this->commandList->getCommands())
    {
        targetInformations.insert(command->getItsTargetInformation());
    }
    
    for(auto targetInformation : targetInformations)
    {
        xmlWriter.writeStartElement("TargetInformation");
    
        xmlWriter.writeAttribute("id", QString::number(targetInformation->getId()));
        xmlWriter.writeAttribute("name", targetInformation->getName());
        xmlWriter.writeAttribute("isSingleTarget", QString::number(targetInformation->getSingleTarget()));
    
        // write ModelClasses
        xmlWriter.writeStartElement("ModelClasses");
    
        for(auto modelClass : targetInformation->getModelClassList())
        {
            xmlWriter.writeStartElement("Class");
            {
                xmlWriter.writeAttribute("id", QString::number(modelClass->getId()));
                xmlWriter.writeAttribute("name", modelClass->getName());
                if( modelClass->getIsReactive() )
                {
                    xmlWriter.writeAttribute("reactive", QString::number(1) );
                }
                else
                {
                    xmlWriter.writeAttribute("reactive", QString::number(0) );
                }
    
                // add instances to class
                xmlWriter.writeStartElement("Instances");
                {
                    for(auto instance : modelClass->getInstanceList())
                    {
                        xmlWriter.writeStartElement("Instance");
                        xmlWriter.writeAttribute("address", QString::number(instance->getAddress(), 16));
                        xmlWriter.writeAttribute("name", instance->getName());
                        xmlWriter.writeAttribute("isBaseInstance", QString::number(instance->getIsBaseClass()) );
                        xmlWriter.writeEndElement(); // Instance
                    }
                }
                xmlWriter.writeEndElement(); // Instances
            }
            xmlWriter.writeEndElement(); // Class
        }
        xmlWriter.writeEndElement(); // ModelClasses
    
        // write ModelEventTypes
        xmlWriter.writeStartElement("ModelEventTypes");
    
        for(auto modelEventType : targetInformation->getModelEventTypeList())
        {
            xmlWriter.writeStartElement("ModelEventType");
            {
                xmlWriter.writeAttribute("id", QString::number(modelEventType->getId()));
                xmlWriter.writeAttribute("name", modelEventType->getName());
            }
            xmlWriter.writeEndElement(); // ModelEventType
        }
    
        xmlWriter.writeEndElement(); // ModelEventTypes
    
        xmlWriter.writeEndElement(); // TargetInformation
    }
    
    //#]
}

void CommandListExporter::cleanUpRelations()
{
    if(commandList != NULL)
        {
            commandList = NULL;
        }
}

/*********************************************************************
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\CommandListExporter.cpp
*********************************************************************/
