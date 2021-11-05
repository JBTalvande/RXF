/*********************************************************************
	Rhapsody	: 9.0.1 
	Login		: Y9DSYU706
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: XMLReader
//!	Generated Date	: Thu, 4, Nov 2021  
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\XMLReader.h
*********************************************************************/

#ifndef XMLReader_H
#define XMLReader_H

#include "Logging.h"
#include <QList>
#include "ModelDefine.h"
#include <QString>
#include <QObject>
#include <QtXml\QDomDocument>
#include <QAction>
class BreakPoints;

class DataViewFilterGeneration;

class EventInjection;

class MainWindow;

class ModelClass;

class ModelClassAttribute;

class ModelDataType;

class ModelEventType;

class ModelOperationType;

class QTextStream;

class SingleParser;

class TargetInformation;

class TargetList;

//## package LogicLevel::Logging

//## class XMLReader
class XMLReader : public QObject {
Q_OBJECT
    ////    Constructors and destructors    ////
    
public :

    //## operation XMLReader()
    XMLReader();
    
    ~XMLReader();
    
    ////    Operations    ////
    
    // Operation to read Rhapsody model from XML file
    //## operation openAndParseXMLFile(QString)
    void openAndParseXMLFile(const QString& p_Path);
    
    //## operation openFileDialog()
    Q_SLOT void openFileDialog();
    
    //## operation openRecentFile(QAction)
    Q_SLOT void openRecentFile(QAction* myAction);

private :

    //## operation getClassActive(QDomElement,ModelClass)
    void getClassActive(const QDomElement& element, ModelClass* modelClass);
    
    //## operation getClassAttributes(QDomElement,ModelClass)
    void getClassAttributes(const QDomElement& element, ModelClass* modelClass);
    
    //## operation getClassFullPathName(QDomElement,ModelClass)
    void getClassFullPathName(const QDomElement& element, ModelClass* modelClass);
    
    //## operation getClassID(QDomElement,ModelClass)
    void getClassID(const QDomElement& element, ModelClass* modelClass);
    
    //## operation getClassName(QDomElement,ModelClass)
    void getClassName(const QDomElement& element, ModelClass* modelClass);
    
    //## operation getClassParrallelStateCount(QDomElement,ModelClass)
    void getClassParrallelStateCount(const QDomElement& element, ModelClass* modelClass);
    
    //## operation getClassReactive(QDomElement,ModelClass)
    void getClassReactive(const QDomElement& element, ModelClass* modelClass);
    
    //## operation getClassRealisations(QDomElement,ModelClass)
    void getClassRealisations(const QDomElement& classElement, ModelClass* modelClass);
    
    //## operation getClassStates(QDomElement,ModelClass)
    void getClassStates(const QDomElement& element, ModelClass* modelClass);
    
    // Parse Class Information from XML File and add them to ModelInformationList 
    //## operation getClasses()
    void getClasses();
    
    //## operation getDefineSize(QString)
    int getDefineSize(const QString& defineName);
    
    // Parse used types inside rhapsody model
    //## operation getDefines()
    void getDefines();
    
    //## operation getEndianes()
    void getEndianes();
    
    // Parse Event information from XML File
    //## operation getEvents()
    void getEvents();
    
    //## operation getMDDTool()
    void getMDDTool();
    
    // Parse Event information from XML File
    //## operation getOperations()
    void getOperations();
    
    //## operation getTarget()
    void getTarget();
    
    //## operation getTargetLanguage()
    void getTargetLanguage();
    
    // Parse used types inside rhapsody model
    //## operation getTypes()
    void getTypes();
    
    ////    Additional operations    ////

public :

    inline QString getLastUsedXMLPath() const
    {
        return lastUsedXMLPath;
    }
    
    inline void setLastUsedXMLPath(QString p_lastUsedXMLPath)
    {
        lastUsedXMLPath = p_lastUsedXMLPath;
    }
    
    inline BreakPoints* getItsBreakPoints() const
    {
        return itsBreakPoints;
    }
    
    inline void setItsBreakPoints(BreakPoints* p_BreakPoints)
    {
        itsBreakPoints = p_BreakPoints;
    }
    
    inline DataViewFilterGeneration* getItsDataViewFilterGeneration() const
    {
        return itsDataViewFilterGeneration;
    }
    
    inline void setItsDataViewFilterGeneration(DataViewFilterGeneration* p_DataViewFilterGeneration)
    {
        itsDataViewFilterGeneration = p_DataViewFilterGeneration;
    }
    
    inline EventInjection* getItsEventInjection() const
    {
        return itsEventInjection;
    }
    
    inline void setItsEventInjection(EventInjection* p_EventInjection)
    {
        itsEventInjection = p_EventInjection;
    }
    
    inline MainWindow* getItsMainWindow() const
    {
        return itsMainWindow;
    }
    
    inline void setItsMainWindow(MainWindow* p_MainWindow)
    {
        itsMainWindow = p_MainWindow;
    }
    
    inline TargetInformation* getItsTargetInformation() const
    {
        return itsTargetInformation;
    }
    
    inline void setItsTargetInformation(TargetInformation* p_TargetInformation)
    {
        itsTargetInformation = p_TargetInformation;
    }

protected :

    void cleanUpRelations();
    
    ////    Attributes    ////

private :

    QList<ModelDefine*> defines;		//## attribute defines
    
    QDomElement documentElement;		//## attribute documentElement
    
    QDomDocument domDocument;		//## attribute domDocument
    
    QString lastUsedXMLPath;		//## attribute lastUsedXMLPath
    
    ////    Relations and components    ////

protected :

    BreakPoints* itsBreakPoints;
    
    DataViewFilterGeneration* itsDataViewFilterGeneration;
    
    EventInjection* itsEventInjection;
    
    MainWindow* itsMainWindow;
    
    TargetInformation* itsTargetInformation;
};

#endif
/*********************************************************************
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\XMLReader.h
*********************************************************************/
