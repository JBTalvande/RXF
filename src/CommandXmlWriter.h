/*********************************************************************
	Rhapsody	: 9.0.1 
	Login		: Y9DSYU706
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: CommandXmlWriter
//!	Generated Date	: Thu, 4, Nov 2021  
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\CommandXmlWriter.h
*********************************************************************/

#ifndef CommandXmlWriter_H
#define CommandXmlWriter_H

#include "Exporter.h"
#include "ReceivedEventParameter.h"
#include <QXmlStreamWriter>
class Command;

class CommandConstructor;

class CommandEventCreated;

class CommandEventEndDispatch;

class CommandEventStartDispatch;

class CommandIntVal;

class CommandOperationCall;

class CommandTraceEvent;

class ModelInstance;

class TargetInformation;

//## package LogicLevel::Exporter

//## class CommandXmlWriter
// This class writes commands to the given QXmlStreamWriter.
// 
// To use this writer, create an instance and give the QXmlStreamWriter as argument during construction.
// The CommandXmlWriter will then write the commands using the writeCommand() method at the position of the xmlWriter.
// Ensure, that the xmlWriter will not move to a location where you do not want to write the XmlElements for commands.
class CommandXmlWriter {
    ////    Constructors and destructors    ////
    
public :

    // Argument QXmlStreamWriter& p_xmlWriter :
    // The QXmlStreamWriter which is used by this CommandXmlWriter when writing the commands to xml
    //## operation CommandXmlWriter(QXmlStreamWriter)
    CommandXmlWriter(QXmlStreamWriter& p_xmlWriter);
    
    ~CommandXmlWriter();
    
    ////    Operations    ////
    
    //## operation writeCommand(Command)
    void writeCommand(const Command& command);

protected :

    //## operation writeConstructorCommand(CommandConstructor)
    void writeConstructorCommand(const CommandConstructor& constructorCommand);
    
    //## operation writeEventCreatedCommand(CommandEventCreated)
    void writeEventCreatedCommand(const CommandEventCreated& eventCreatedCommand);
    
    //## operation writeEventEndDispatchCommand(CommandEventEndDispatch)
    void writeEventEndDispatchCommand(const CommandEventEndDispatch& eventEndDispatchCommand);
    
    //## operation writeEventStartDispatchCommand(CommandEventStartDispatch)
    void writeEventStartDispatchCommand(const CommandEventStartDispatch& eventStartDispatchCommand);
    
    //## operation writeIntValCommand(CommandIntVal)
    void writeIntValCommand(const CommandIntVal& intValCommand);
    
    //## operation writeOperationCalledCommand(CommandOperationCall)
    void writeOperationCalledCommand(const CommandOperationCall& operationCalledCommand);
    
    //## operation writeReceivedEventParameters(const QVector<ReceivedEventParameter*>&)
    void writeReceivedEventParameters(const QVector<ReceivedEventParameter*>& receivedEventParameters);
    
    //## operation writeTraceEventCommand(CommandTraceEvent)
    void writeTraceEventCommand(const CommandTraceEvent& traceEventCommand);
    
    ////    Attributes    ////
    
    QXmlStreamWriter& xmlWriter;		//## attribute xmlWriter
};

#endif
/*********************************************************************
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\CommandXmlWriter.h
*********************************************************************/
