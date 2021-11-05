/*********************************************************************
	Rhapsody	: 9.0.1 
	Login		: Y9DSYU706
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: CommandXmlReader
//!	Generated Date	: Thu, 4, Nov 2021  
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\CommandXmlReader.h
*********************************************************************/

#ifndef CommandXmlReader_H
#define CommandXmlReader_H

#include "Importer.h"
// used by the cache for triplet data
#include "CommandEventTripletData.h"
#include "ReceivedEventParameter.h"
#include <QXmlStreamReader>
#include <QHash>
class Command;

class CommandConstructor;

class CommandDestructor;

class CommandEventCreated;

class CommandEventEndDispatch;

class CommandEventStartDispatch;

class CommandIntVal;

class CommandOperationCall;

class CommandTraceEvent;

class TargetList;

//## package LogicLevel::Importer

//## class CommandXmlReader
class CommandXmlReader {
    ////    Constructors and destructors    ////
    
public :

    //## operation CommandXmlReader(QXmlStreamReader)
    CommandXmlReader(QXmlStreamReader& p_xmlReader);
    
    ~CommandXmlReader();
    
    ////    Operations    ////
    
    //## operation readCommand()
    Command* readCommand();

protected :

    //## operation readConstructorCommand()
    CommandConstructor* readConstructorCommand();
    
    //## operation readDestructorCommand()
    CommandDestructor* readDestructorCommand();
    
    //## operation readEventCreatedCommand()
    CommandEventCreated* readEventCreatedCommand();
    
    //## operation readEventEndDispatchCommand()
    CommandEventEndDispatch* readEventEndDispatchCommand();
    
    //## operation readEventStartDispatchCommand()
    CommandEventStartDispatch* readEventStartDispatchCommand();
    
    //## operation readIntValCommand()
    CommandIntVal* readIntValCommand();
    
    //## operation readOperationCalledCommand()
    CommandOperationCall* readOperationCalledCommand();
    
    //## operation readReceivedEventParameters()
    QVector<ReceivedEventParameter*> readReceivedEventParameters();
    
    //## operation readTraceEventCommand()
    CommandTraceEvent* readTraceEventCommand();
    
    ////    Additional operations    ////

public :

    inline QHash<unsigned int, CommandEventTripletData*> getTripletDataCache() const
    {
        return tripletDataCache;
    }
    
    inline void setTripletDataCache(QHash<unsigned int, CommandEventTripletData*> p_tripletDataCache)
    {
        tripletDataCache = p_tripletDataCache;
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
    
    ////    Attributes    ////
    
    QHash<unsigned int, CommandEventTripletData*> tripletDataCache;		//## attribute tripletDataCache
    
    QXmlStreamReader& xmlReader;		//## attribute xmlReader
    
    ////    Relations and components    ////
    
    TargetList* itsTargetList;
};

#endif
/*********************************************************************
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\CommandXmlReader.h
*********************************************************************/
