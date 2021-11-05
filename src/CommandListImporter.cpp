/********************************************************************
	Rhapsody	: 9.0.1 
	Login		: Y9DSYU706
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: CommandListImporter
//!	Generated Date	: Thu, 4, Nov 2021  
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\CommandListImporter.cpp
*********************************************************************/

#include "CommandListImporter.h"
#include "CommandList.h"
#include "CommandXmlReader.h"
#include "ModelClass.h"
#include "ModelDataType.h"
#include "ModelEventArgumentType.h"
#include "ModelEventType.h"
#include "ModelInstance.h"
#include <QFile.h>
#include <QFileInfo.h>
#include "TargetInformation.h"
#include "TargetList.h"
//## package LogicLevel::Importer

//## class CommandListImporter
CommandListImporter::CommandListImporter()
{
    commandList = NULL;
    itsTargetList = NULL;
}

CommandListImporter::~CommandListImporter()
{
    cleanUpRelations();
}

void CommandListImporter::readCommands(QXmlStreamReader& xmlReader)
{
    //#[ operation readCommands(QXmlStreamReader)
    /*
     * use the CommandXmlReader to read the commands
     *  notice that the xmlReader is passed and stored by reference
     *  so it is at the same position as in this scope
     */
    CommandXmlReader cmdXmlReader(xmlReader);
    cmdXmlReader.setItsTargetList( itsTargetList );
    
    while(xmlReader.readNextStartElement())
    {
        if(xmlReader.name() == "Commands")
        {
            while(xmlReader.readNextStartElement())
            {
                Command* newCommand = cmdXmlReader.readCommand();
    
                if(newCommand != NULL)
                {
                    this->commandList->addCommand(newCommand, true);
                }
                else
                {
                    this->logInfo("Could not read Command properly: " + xmlReader.name());
                }
            }
        }
    }
    //#]
}

void CommandListImporter::readContent(QFile& inFile)
{
    //#[ operation readContent(QFile)
    
    // prepare some variables
    itsTargetList = new TargetList();
    this->commandList = new CommandList( *itsTargetList );
    bool success = false;
    
    QXmlStreamReader xmlReader;
    
    // start reading xml
    try {
    
    
        xmlReader.setDevice(&inFile);
        xmlReader.readNext();
    
        while(xmlReader.atEnd() == false)
        {
            if(xmlReader.isStartElement())
            {
                if(xmlReader.name() == "ViewData")
                {
                    // read view data
                    QString saveDate = "";
                    for( QXmlStreamAttribute viewDataAttribute : xmlReader.attributes() )
                    {
                        if(viewDataAttribute.name() == "saveDate")
                        {
                            saveDate = viewDataAttribute.value().toString();
                        }
                    }
                    QFileInfo fileInfo(inFile.fileName());
                    this->commandList->setText(fileInfo.fileName() + ": " + saveDate);
    
                    // continue reading content of ViewData
                    xmlReader.readNext();
                    while(xmlReader.isEndElement() == false)
                    {
                        if(xmlReader.name() == "TargetInformations")
                        {
                            this->readTargetInformation(xmlReader);
                        }
                        else if(xmlReader.name() == "CommandList")
                        {
                            this->readCommands(xmlReader);
                        }
                        else
                        {
                            xmlReader.readNext();
                        }
                    }
                    // TODO: get results from reading data to refine this value
                    success = true;
                }
            }
            else
            {
                xmlReader.readNext();
            }
        }
    } catch (...) {
        // TODO: extend the catch with more specific exceptions which also might include some further information to the error
        success = false;
    }
    
    if(success == false)
    {
        // delete the memory of the command list because it will not be usable if something went wrong
        delete this->commandList;
        this->commandList = NULL;
        this->logInfo("Import Data failed: " + xmlReader.errorString());
    }
    //#]
}

void CommandListImporter::readModelClasses(QXmlStreamReader& xmlReader, TargetInformation& targetInformation)
{
    //#[ operation readModelClasses(QXmlStreamReader,TargetInformation)
    while(xmlReader.atEnd() == false)
    {
        if(xmlReader.isEndElement())
        {
            xmlReader.readNext();
            break;
        }
        else if(xmlReader.isStartElement() && xmlReader.name() == "Class")
        {
            // Read Class Element
            ModelClass* newModelClass = NULL;
    
            uint id = 0;
            bool isReactive = true;
            QString name = "";
    
            bool isValid = false;
    
            for(QXmlStreamAttribute classAttribute : xmlReader.attributes())
            {
                if(classAttribute.name() == "id")
                {
                    id = classAttribute.value().toUInt(&isValid);
                }
                else if(classAttribute.name() == "name")
                {
                    name = classAttribute.value().toString();
                }
                else if(classAttribute.name() == "reactive")
                {
                    bool isReactiveParseValid;
                    int id = classAttribute.value().toInt(&isReactiveParseValid);
                    if( id != 0 || !isReactiveParseValid )
                    {
                        isReactive = true;
                    }
                    else
                    {
                        isReactive = false;
                    }
                }
            }
    
            if(isValid)
            {
                newModelClass = new ModelClass();
                newModelClass->setId(id);
                newModelClass->setName(name);
                newModelClass->setIsReactive(isReactive);
            }
            else
            {
                // TODO: do execption handling for this case
            }
    
            xmlReader.readNext();
    
            // read content of model class
            while(xmlReader.atEnd() == false)
            {
                if(xmlReader.isEndElement())
                {
                    xmlReader.readNext();
                    break;
                }
                else if(xmlReader.isStartElement() && xmlReader.name() == "Instances")
                {
                    this->readModelInstances(xmlReader, *newModelClass, targetInformation);
                }
                else
                {
                    xmlReader.readNext();
                }
            }
    
    
            // finally add new class to targetInformation
            if(newModelClass != NULL)
            {
                targetInformation.addClass(newModelClass);
            }
        }
        else
        {
            xmlReader.readNext();
        }
    }
    //#]
}

void CommandListImporter::readModelEventTypes(QXmlStreamReader& xmlReader, TargetInformation& targetInformation)
{
    //#[ operation readModelEventTypes(QXmlStreamReader,TargetInformation)
    while(xmlReader.atEnd() == false)
    {
        if(xmlReader.isEndElement())
        {
            xmlReader.readNext();
            break;
        }
        else if(xmlReader.isStartElement() && (xmlReader.name() == "ModelEventType"))
        {
            // read ModelEventTypeElement
            ModelEventType* newModelEventType = NULL;
    
            int id = 0;
            QString name = "";
    
            bool isValid = false;
    
            // read ModelEventType attributes
            for(QXmlStreamAttribute eventTypeAttribute : xmlReader.attributes())
            {
                if(eventTypeAttribute.name() == "id")
                {
                    id = eventTypeAttribute.value().toInt(&isValid);
                }
                else if(eventTypeAttribute.name() == "name")
                {
                    name = eventTypeAttribute.value().toString();
                }
            }
    
            if(isValid)
            {
                newModelEventType = new ModelEventType(name, id, &targetInformation);
            }
            else
            {
                // TODO: handle exception for this case
            }
    
            // add new ModelEventType to targetInformation
            if(newModelEventType != NULL)
            {
                targetInformation.addEventType(newModelEventType);
            }
    
            xmlReader.readNext();
    
            // read until end of <ModelEventType>
            while(xmlReader.atEnd() == false)
            {
                if(xmlReader.isEndElement())
                {
                    xmlReader.readNext();
                    break;
                }
                else
                {
                    xmlReader.readNext();
                }
    
            }
        }
        else
        {
            xmlReader.readNext();
        }
    }
    //#]
}

void CommandListImporter::readModelInstances(QXmlStreamReader& xmlReader, ModelClass& modelClass, TargetInformation& targetInformation)
{
    //#[ operation readModelInstances(QXmlStreamReader,ModelClass,TargetInformation)
    while(xmlReader.atEnd() == false)
    {
        if(xmlReader.isEndElement())
        {
            xmlReader.readNext();
            break;
        }
        else if(xmlReader.isStartElement() && (xmlReader.name() == "Instance"))
        {
            // read InstanceElement
            ModelInstance* newInstance = NULL;
            uint instanceAddress = 0;
            QString instanceName = "";
            bool isBaseInstance;
    
    
            bool isValid = false;
    
            // read attributes
            for(QXmlStreamAttribute instanceAttribute : xmlReader.attributes())
            {
                if(instanceAttribute.name() == "address")
                {
                    instanceAddress = instanceAttribute.value().toUInt(&isValid, 16);
                }
                else if(instanceAttribute.name() == "name")
                {
                    instanceName = instanceAttribute.value().toString();
                }
                else if(instanceAttribute.name() == "isBaseInstance")
                {
                    isBaseInstance = instanceAttribute.value().toInt();
                }
    
    
            }
    
            if(isValid)
            {
                newInstance = new ModelInstance(&modelClass, instanceAddress, 0, instanceName, &targetInformation);
                newInstance->setIsBaseClass(isBaseInstance);
            }
            else
            {
                // TODO: do exception handling for this case
            }
    
            // add newInstance to class
            if(newInstance != NULL)
            {
                modelClass.addInstance(newInstance);
            }
    
            xmlReader.readNext();
    
            // read until end of <Instance>
            while(xmlReader.atEnd() == false)
            {
                if(xmlReader.isEndElement())
                {
                    xmlReader.readNext();
                    break;
                }
                else
                {
                    xmlReader.readNext();
                }
            }
        }
        else
        {
            xmlReader.readNext();
        }
    }
    //#]
}

void CommandListImporter::readTargetInformation(QXmlStreamReader& xmlReader)
{
    //#[ operation readTargetInformation(QXmlStreamReader)
    while(xmlReader.atEnd() == false)
    {
        // return if the end element of this section is reached
        if(xmlReader.isEndElement())
        {
            xmlReader.readNext();
            break;
        }
        else if(xmlReader.isStartElement() && (xmlReader.name() == "TargetInformation"))
        {
            TargetInformation* newTargetInformation = NULL;
    
            int targetId = 0;
            QString targetName = "";
            bool isSingleTarget = false;
    
            bool isValid = false;
    
            // read attributes of TargetInformation
            for(QXmlStreamAttribute targetInfoAttribute : xmlReader.attributes())
            {
                if(targetInfoAttribute.name() == "id")
                {
                    targetId = targetInfoAttribute.value().toInt(&isValid);
                }
                else if(targetInfoAttribute.name() == "name")
                {
                    targetName = targetInfoAttribute.value().toString();
                }
                else if(targetInfoAttribute.name() == "isSingleTarget")
                {
                    isSingleTarget = targetInfoAttribute.value().toInt(&isValid);
                }
            }
    
            if(isValid)
            {
                newTargetInformation = itsTargetList->createTarget(targetId, targetName, isSingleTarget );
            }
            else
            {
                xmlReader.readNext();
                continue;
            }
    
            xmlReader.readNext();
    
            // read content of TargetInformationElement
            while(xmlReader.atEnd() == false)
            {
                // return if the end of this element is reached
                if(xmlReader.isEndElement())
                {
                    xmlReader.readNext();
                    break;
                }
                // in case of content element start
                else if(xmlReader.isStartElement())
                {
                    if(xmlReader.name() == "ModelClasses")
                    {
                        this->readModelClasses(xmlReader, *newTargetInformation);
                    }
                    else if(xmlReader.name() == "ModelEventTypes")
                    {
                        this->readModelEventTypes(xmlReader, *newTargetInformation);
                    }
                    xmlReader.readNext();
                }
                else
                {
                    xmlReader.readNext();
                }
            }
        }
        else
        {
            xmlReader.readNext();
        }
    }
    
    //#]
}

void CommandListImporter::cleanUpRelations()
{
    if(commandList != NULL)
        {
            commandList = NULL;
        }
    if(itsTargetList != NULL)
        {
            itsTargetList = NULL;
        }
}

/*********************************************************************
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\CommandListImporter.cpp
*********************************************************************/
