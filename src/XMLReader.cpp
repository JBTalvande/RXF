/********************************************************************
	Rhapsody	: 9.0.1 
	Login		: Y9DSYU706
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: XMLReader
//!	Generated Date	: Thu, 4, Nov 2021  
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\XMLReader.cpp
*********************************************************************/

#include "XMLReader.h"
#include "BreakPoints.h"
#include "DataViewFilterGeneration.h"
#include "EventInjection.h"
#include "MainWindow.h"
#include "ModelClass.h"
#include "ModelClassAttribute.h"
#include "ModelDataType.h"
#include "ModelEventType.h"
#include "ModelOperationType.h"
#include <QTextStream.h>
#include "SingleParser.h"
#include "TargetInformation.h"
#include "TargetList.h"
#include <QFile>
#include <QFileDialog>
//## package LogicLevel::Logging

//## class XMLReader
XMLReader::XMLReader() : lastUsedXMLPath("../../../Samples/Model/Blinky")
{
    itsBreakPoints = NULL;
    itsDataViewFilterGeneration = NULL;
    itsEventInjection = NULL;
    itsMainWindow = NULL;
    itsTargetInformation = NULL;
    //#[ operation XMLReader()
    //#]
}

XMLReader::~XMLReader()
{
    cleanUpRelations();
}

void XMLReader::openAndParseXMLFile(const QString& p_Path)
{
    //#[ operation openAndParseXMLFile(QString)
    // First check if file path is valid
    if ( p_Path.isEmpty() )
    {        
        itsMainWindow->errorMsg( "No valid file: " + p_Path );
        return;
    }
    
    //Check if file can be opend
    QFile file( p_Path );
    
    if ( !file.open( QFile::ReadOnly | QFile::Text ) )
    {
        itsMainWindow->errorMsg( "Can't open File : " + p_Path );
        return;
    }
    
    if( p_Path.endsWith(".xml"))
    {
        if ( !domDocument.setContent( file.readAll(), true ) )
        {
            itsMainWindow->errorMsg( "Can't parse XML File : " + p_Path );
            file.close();
            return;
        }
    }
    if( p_Path.endsWith(".lst"))
    {
        QTextStream in(&file);
        while (!in.atEnd())
        {
          QString line = in.readLine();
          openAndParseXMLFile( line );
        }
        file.close();
        return;
    }
    
    itsMainWindow->consoleMsg( "Import XML File:" + p_Path );
    
    file.close();
    
    //Parse XML File  
    documentElement = domDocument.documentElement();
    
    getTarget();
    getTargetLanguage();
    getEndianes();
    getMDDTool();
    getDefines(); 
    getTypes();
    getEvents();
    getOperations();
    getClasses();
    
    itsMainWindow->consoleMsg( "Import done:" + p_Path );  
    itsMainWindow->getUi()->actionLoadDataLOGFile->setEnabled( true );
    itsBreakPoints->updateTargets();
    itsEventInjection->updateTargets();
    
    return;
    //#]
}

void XMLReader::openFileDialog()
{
    //#[ operation openFileDialog()
    QString pathXMLfile = QFileDialog::getOpenFileName( this->itsMainWindow, "Open XML File", lastUsedXMLPath, "XML Files (*.xml);;XML FileList (*.lst)" );
       
    if ( !pathXMLfile.isEmpty() )
    {   
    	lastUsedXMLPath = pathXMLfile;
    	itsMainWindow->addRecentXMLPath( pathXMLfile );
    	openAndParseXMLFile( pathXMLfile );
    }
    //#]
}

void XMLReader::openRecentFile(QAction* myAction)
{
    //#[ operation openRecentFile(QAction)
    lastUsedXMLPath = myAction->text();
    itsMainWindow->addRecentXMLPath( lastUsedXMLPath );
    openAndParseXMLFile( lastUsedXMLPath );
    //#]
}

void XMLReader::getClassActive(const QDomElement& element, ModelClass* modelClass)
{
    //#[ operation getClassActive(QDomElement,ModelClass)
    int isActive = 0;
    QDomNodeList nl = element.elementsByTagName( "ActiveClass" );
    
    if ( !nl.isEmpty() )
    {
        QDomElement el = nl.item( 0 ).toElement();
        isActive = el.firstChild().nodeValue().toInt();
    }
    modelClass->setIsActive( isActive );
    //#]
}

void XMLReader::getClassAttributes(const QDomElement& element, ModelClass* modelClass)
{
    //#[ operation getClassAttributes(QDomElement,ModelClass)
    QDomNodeList domAttributeNodes = element.elementsByTagName( "Attribute" );
    
    if ( !domAttributeNodes.isEmpty() )
    {
        for ( int i = 0; i < domAttributeNodes.length(); i++ )
        {
            ModelClassAttribute *myNewClassAttribute = new ModelClassAttribute();
    
            //get attribut Name
            QStringList arrayParts;
            QString name = domAttributeNodes.at(i).firstChildElement( "Name" ).firstChild().nodeValue().trimmed();
            arrayParts = name.split("[");
            myNewClassAttribute->setName( arrayParts[0].trimmed() );
    
    
            //get attribut Type
            QString type = domAttributeNodes.at(i).firstChildElement( "Type" ).firstChild().nodeValue().trimmed();
            myNewClassAttribute->setItsModelDataType( itsTargetInformation->getTypePtr( type ) );
    
            //is attribut visible for user?
    
            QString visible = domAttributeNodes.at(i).firstChildElement( "Visible" ).firstChild().nodeValue().trimmed().toLower();
            if( visible == "0" || visible == "false" )
            {
                myNewClassAttribute->setVisible( false );
            }
            else
            {
                myNewClassAttribute->setVisible( true );
            }
    
            // is my class attribute an array?
    
            //split my array dimensions into parts -> arrayName[ part1 ][ part2 ][ part3 ]...
            for(int k = 0; k < arrayParts.size() - 1; k++){
                QString anArrayPartString = arrayParts[k+1].split("]").at(0).trimmed();
                unsigned int anArrayPartInt = 0;
    
                anArrayPartString = anArrayPartString.replace(" ","");
    
                //if array includes a + operator sumerise the block
                QStringList anArrayPartStringPlusList = anArrayPartString.split("+");
                for(int j = 0; j < anArrayPartStringPlusList.size();j++){
                    bool isNumber;
                    anArrayPartInt += anArrayPartStringPlusList.at(j).toInt(&isNumber);
    
    
                    if(!isNumber)
                    {
                        int partValueByDefine = getDefineSize( anArrayPartStringPlusList.at(j) );
                        if( partValueByDefine == -1 )
                        {
                            itsMainWindow->consoleMsg( "Array size value define \"" + anArrayPartStringPlusList.at(j) + "\" of class attribute " + modelClass->getName() + "." + arrayParts[0] + " is unknown. Size will be 1. The Offset of following attributes will be incorrect!" );
                            anArrayPartInt += anArrayPartStringPlusList.at(j).toInt(&isNumber);
                        }
                        else
                        {
                            anArrayPartInt += partValueByDefine;
                        }
                    }
                    myNewClassAttribute->setArrayDimension( k, anArrayPartInt );
                }
            }
            modelClass->addAttribute( myNewClassAttribute );
        }
    }
    //#]
}

void XMLReader::getClassFullPathName(const QDomElement& element, ModelClass* modelClass)
{
    //#[ operation getClassFullPathName(QDomElement,ModelClass)
    QString textVal = "UnkonwoClass";
    QDomNodeList nl = element.elementsByTagName( "FullPathName" );
    
    if ( !nl.isEmpty() )
    {
        QDomElement el = nl.item( 0 ).toElement();
        textVal = el.firstChild().nodeValue();
    }
    modelClass->setFullPathName(textVal);
    //#]
}

void XMLReader::getClassID(const QDomElement& element, ModelClass* modelClass)
{
    //#[ operation getClassID(QDomElement,ModelClass)
    unsigned int classID = 10000000;
    QDomNodeList nl = element.elementsByTagName( "ID" );
    
    if ( !nl.isEmpty() )
    {
        QDomElement el = nl.item( 0 ).toElement();
        classID = el.firstChild().nodeValue().toUInt();
    }
    modelClass->setId( classID );
    //#]
}

void XMLReader::getClassName(const QDomElement& element, ModelClass* modelClass)
{
    //#[ operation getClassName(QDomElement,ModelClass)
    QString textVal = "UnkonwoClass";
    QDomNodeList nl = element.elementsByTagName( "Name" );
    
    if ( !nl.isEmpty() )
    {
        QDomElement el = nl.item( 0 ).toElement();
        textVal = el.firstChild().nodeValue();
    }
    modelClass->setName(textVal);
    //#]
}

void XMLReader::getClassParrallelStateCount(const QDomElement& element, ModelClass* modelClass)
{
    //#[ operation getClassParrallelStateCount(QDomElement,ModelClass)
    unsigned int parrallelStateCount = 1;
    QDomNodeList nl = element.elementsByTagName( "parallelStateCount" );
    
    if ( !nl.isEmpty() )
    {
        QDomElement el = nl.item( 0 ).toElement();
        parrallelStateCount = el.firstChild().nodeValue().toUInt();
    }
    modelClass->setParrallelStateCount( parrallelStateCount );
    //#]
}

void XMLReader::getClassReactive(const QDomElement& element, ModelClass* modelClass)
{
    //#[ operation getClassReactive(QDomElement,ModelClass)
    unsigned int parrallelStateCount = 1;
    QDomNodeList nl = element.elementsByTagName( "parallelStateCount" );
    
    if ( !nl.isEmpty() )
    {
        QDomElement el = nl.item( 0 ).toElement();
        parrallelStateCount = el.firstChild().nodeValue().toUInt();
        if( parrallelStateCount > 0 )
        {
            modelClass->setIsReactive( true );
        }
        else
        {
            modelClass->setIsReactive( false );
        }
    }
    else
    {
        modelClass->setIsReactive( false );
    }
    //#]
}

void XMLReader::getClassRealisations(const QDomElement& classElement, ModelClass* modelClass)
{
    //#[ operation getClassRealisations(QDomElement,ModelClass)
    QDomNodeList domParentList = classElement.elementsByTagName( "BaseClasses" );
    
    if( domParentList.size() > 0 )
    {
        QDomNodeList baseList = domParentList.item( 0 ).childNodes();
        for( int i = 0; i < baseList.size(); i++ )
        {
            QDomNode aNode = baseList.item( i ).firstChild();
            if( !aNode.isNull() )
            {
    
                ModelClass *parentClass = itsTargetInformation->getClassByFullPath( aNode.nodeValue() );
                if( parentClass != NULL )
                {
                    modelClass->setParrallelStateCount( modelClass->getParrallelStateCount() + parentClass->getParrallelStateCount() );
                    modelClass->addParent( parentClass );
                    for( int i = 0; i < parentClass->getItsModelClassStateList()->size(); i++ )
                    {
                        modelClass->addState( parentClass->getItsModelClassStateList()->at(i) );
                    }
                }
            }
        }
    }
    //#]
}

void XMLReader::getClassStates(const QDomElement& element, ModelClass* modelClass)
{
    //#[ operation getClassStates(QDomElement,ModelClass)
    QDomNodeList nl = element.elementsByTagName( "State" );
    
    if ( !nl.isEmpty() )
    {
    
        for ( int i = 0; i < nl.length(); i++ )
        {
            ModelClassState *state = new ModelClassState( nl.item( i ).toElement().attribute( nl.item( i ).attributes().item( 0 ).nodeName() ).toInt(), nl.item( i ).toElement().firstChild().nodeValue());
            modelClass->addState( state );
        }
    }
    //#]
}

void XMLReader::getClasses()
{
    //#[ operation getClasses()
    QDomNodeList domNodeClassList = documentElement.elementsByTagName( "Class" );    
    if ( !domNodeClassList.isEmpty() )
    {
        QList<ModelClass *> myTemporaryModelClassList;
        for ( int i = 0; i < domNodeClassList.length(); i++ )
        {
            //get the Object element
            QDomElement classElement = domNodeClassList.item( i ).toElement();
            ModelClass *myModelClass = new ModelClass();
            myTemporaryModelClassList.append( myModelClass );
    
            //get the each parameters in an object
            getClassName( classElement, myModelClass );
            getClassFullPathName( classElement, myModelClass );
            getClassID( classElement, myModelClass );
            getClassActive( classElement, myModelClass );
            getClassReactive( classElement, myModelClass );
            getClassStates( classElement, myModelClass );
            getClassParrallelStateCount( classElement, myModelClass );
            getClassAttributes( classElement, myModelClass );
    
            //add it to DataModel
            itsTargetInformation->addClass( myModelClass );
        }
    
        // if we use CPP also get parants from inherince
        if( languageKind == CPP_LANGUAGE )
        {
            for ( int i = 0; i < domNodeClassList.length(); i++ )
            {
                getClassRealisations( domNodeClassList.item( i ).toElement(), myTemporaryModelClassList.at(i) );
            }
        }
    }
    
    //#]
}

int XMLReader::getDefineSize(const QString& defineName)
{
    //#[ operation getDefineSize(QString)
    for(int i = 0; i < defines.size();i++){
        if(defines.at(i)->getDefineName() == defineName ){
            return defines.at(i)->getDefineSize();
        }
    }
    return -1;
    //#]
}

void XMLReader::getDefines()
{
    //#[ operation getDefines()
    QDomNodeList nl = documentElement.elementsByTagName( "Define" );
    
    if ( !nl.isEmpty() )
    {
    
        bool isNumber;
        for ( int i = 0; i < nl.length(); i++ )
        {
            ModelDefine *tmpDef = new ModelDefine;
            QDomElement element = nl.item( i ).toElement();
            tmpDef->setDefineName( element.attribute( "name" ) );    
            int defineSize = element.firstChild().nodeValue().toInt(&isNumber);
            if(isNumber){
            	tmpDef->setDefineSize( defineSize ); 
            }
            else
            {
                tmpDef->setDefineSize( 1 ); 
            }
            defines.append(tmpDef);        
        }
    }
    //#]
}

void XMLReader::getEndianes()
{
    //#[ operation getEndianes()
    QDomNodeList targetElements = documentElement.elementsByTagName( "Target" );
    
    if ( !targetElements.isEmpty() )
    {
        QDomNodeList DomNodeListEndianess = targetElements.at(0).toElement().elementsByTagName( "Endianness" );
    
        QString endianess;
        if(!DomNodeListEndianess.isEmpty())
        {
            endianess = DomNodeListEndianess.item( 0 ).toElement().firstChild().nodeValue();
        }
        if(endianess.toLower() == "little")
        {
            itsTargetInformation->setEndianess( LITTLE_ENDIAN );
        }
        if(endianess.toLower() == "big")
        {
            itsTargetInformation->setEndianess( BIG_ENDIAN );
        } 
    }
    //#]
}

void XMLReader::getEvents()
{
    //#[ operation getEvents()
    QDomNodeList domNodeEventList = documentElement.elementsByTagName( "EventList" );
    if ( !domNodeEventList.isEmpty() )
    {
        QDomNodeList domNodeEvents = domNodeEventList.item( 0 ).toElement().elementsByTagName( "Event" );
    
        if ( !domNodeEvents.isEmpty() )
        {
            for ( int i = 0; i < domNodeEvents.length(); i++ )
            {
                //get the Object element
    
                QDomElement element = domNodeEvents.item( i ).toElement();
                ModelEventType *myNewEventType = new ModelEventType( element.attribute( "name" ), element.attribute( "id" ).toInt(), itsTargetInformation );
                for(int j=0;j<element.childNodes().at(0).childNodes().size();j++){
                    QString parameterType = element.childNodes().at(0).childNodes().at(j).childNodes().at(1).firstChild().nodeValue();
                    QString parameterName = element.childNodes().at(0).childNodes().at(j).childNodes().at(0).firstChild().nodeValue();
                    ModelDataType *myEventArgumentDataType = itsTargetInformation->getTypePtr( parameterType );
                    myNewEventType->addArgument(parameterName,myEventArgumentDataType);
                }
    
                itsTargetInformation->addEventType( myNewEventType );
            }
        }
    }
    //#]
}

void XMLReader::getMDDTool()
{
    //#[ operation getMDDTool()
    QDomAttr myAttribute = documentElement.attributeNode("tool");
    
    
    if( myAttribute.value() == "EnterpriseArchitect")
    {   
        modellingTool = MDD_ENTERPRISE_ARCHITEKT;
    }
    else
    {    
        modellingTool = MDD_RHAPSODY;
    }
    
    
    //#]
}

void XMLReader::getOperations()
{
    //#[ operation getOperations()
    QDomNodeList domNodeOperationList = documentElement.elementsByTagName( "Operation" );
    if ( !domNodeOperationList.isEmpty() )
    {
    
        for ( int i = 0; i < domNodeOperationList.length(); i++ )
        {
            //get the Object element
    
            QDomElement element = domNodeOperationList.item( i ).toElement();
            ModelOperationType *myNewEventType = new ModelOperationType( element.attribute( "name" ), element.attribute( "id" ).toInt(), itsTargetInformation );
            for(int j=0;j<element.childNodes().at(0).childNodes().size();j++){
                QString parameterType = element.childNodes().at(0).childNodes().at(j).childNodes().at(1).firstChild().nodeValue();
                QString parameterName = element.childNodes().at(0).childNodes().at(j).childNodes().at(0).firstChild().nodeValue();
                ModelDataType *myEventArgumentDataType = itsTargetInformation->getTypePtr( parameterType );
                myNewEventType->addArgument(parameterName,myEventArgumentDataType);
            }
    
            itsTargetInformation->addEventType( myNewEventType );
        }
    }
    //#]
}

void XMLReader::getTarget()
{
    //#[ operation getTarget()
    QDomNodeList nodeLanguage = documentElement.elementsByTagName( "TargetIdentification" );
    
    if(nodeLanguage.count() > 0)
    {
        unsigned int id = nodeLanguage.at(0).toElement().attribute("id").toUInt();    
        itsTargetInformation = TargetList::getGlobalList()->createTarget( id, nodeLanguage.at(0).toElement().text(), false );
        itsMainWindow->removeTarget( *itsTargetInformation );
    }
    else
    {
        itsTargetInformation = TargetList::getGlobalList()->createTarget( 0, "SingleTarget", true );
        itsMainWindow->removeTarget( *itsTargetInformation );
        SingleParser::setItsTargetInformation( itsTargetInformation );
    }
    //#]
}

void XMLReader::getTargetLanguage()
{
    //#[ operation getTargetLanguage()
    QDomNodeList nodeLanguage = documentElement.elementsByTagName( "Language" );
    
    if(nodeLanguage.at(0).toElement().text().toUpper() == "CPP")
    {
        languageKind = CPP_LANGUAGE;
    }
    else
    {
    	languageKind = C_LANGUAGE;
    }
    //#]
}

void XMLReader::getTypes()
{
    //#[ operation getTypes()
    QDomNodeList domTypeList = documentElement.elementsByTagName( "TypeList" ).at(0).childNodes();
    
    if ( !domTypeList.isEmpty() )
    {
        for ( int i = 0; i < domTypeList.length(); i++ )
        {
            QDomElement element = domTypeList.item( i ).toElement();
            itsTargetInformation->addType( element.firstChild().nodeValue(), element.attribute( "size" ).toInt(), i );
        }
    }
    //#]
}

void XMLReader::cleanUpRelations()
{
    if(itsBreakPoints != NULL)
        {
            itsBreakPoints = NULL;
        }
    if(itsDataViewFilterGeneration != NULL)
        {
            itsDataViewFilterGeneration = NULL;
        }
    if(itsEventInjection != NULL)
        {
            itsEventInjection = NULL;
        }
    if(itsMainWindow != NULL)
        {
            itsMainWindow = NULL;
        }
    if(itsTargetInformation != NULL)
        {
            itsTargetInformation = NULL;
        }
}

/*********************************************************************
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\XMLReader.cpp
*********************************************************************/
