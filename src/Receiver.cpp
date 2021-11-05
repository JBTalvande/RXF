/********************************************************************
	Rhapsody	: 9.0.1 
	Login		: Y9DSYU706
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: Receiver
//!	Generated Date	: Thu, 4, Nov 2021  
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\Receiver.cpp
*********************************************************************/

#include "Receiver.h"
#include "IParser.h"
#include "SingleParser.h"
#include <QTimer>
//## package LogicLevel::DataTransmission

//## class Receiver
bool Receiver::analyzeData(true);

bool Receiver::logData(false);

QFile Receiver::rawDataQFile;

Receiver::Receiver() : RefreshRateInMS(40), bytesPerStep(1000), rawDataFilePath("")
{
    //#[ operation Receiver()
    QTimer::singleShot(100,this, SLOT( analyzeStream()));
    //#]
}

Receiver::~Receiver()
{
}

void Receiver::analyzeStream()
{
    //#[ operation analyzeStream()
    itsActiveParser->analyzeStream( bytesPerStep );
    QTimer::singleShot(RefreshRateInMS,this, SLOT( analyzeStream()));
    //#]
}

void Receiver::processConstructors(bool value)
{
    //#[ operation processConstructors(bool)
    itsSingleParser->setProcessConstructorCalls( value );
    //#]
}

void Receiver::processDestructors(bool value)
{
    //#[ operation processDestructors(bool)
    itsSingleParser->setProcessDestructorCalls( value );
    //#]
}

void Receiver::receiveData(char* data, unsigned int length)
{
    //#[ operation receiveData(char*,unsigned int)
    // Read bytes per bytes
    for(unsigned int i = 0 ; i < length ; i++) //add all received bytes to the buffer
    {
        if( logData )
        {
            if( rawDataQFile.isOpen() )
            {
                rawDataQFile.write( (QString::number((int)(unsigned char)data[i])+"\n").toStdString().c_str() );
                rawDataQFile.flush();
            }
        }
        if( analyzeData )
        {
            itsActiveParser->addByte( data[i]);
        }
    
    }
    //#]
}

void Receiver::setParser(unsigned char monitorType)
{
    //#[ operation setParser(unsigned char)
    if( monitorType == SingleTarget )
    {
        Receiver::setItsActiveParser( Receiver::getItsSingleParser() );    
    }
    else if( monitorType == MultiTarget )
    {
        Receiver::setItsActiveParser( Receiver::getItsMultiParser() );
    }
    else if( monitorType == TestConductor )
    {
        Receiver::setItsActiveParser( Receiver::getItsTestConductorParser() );
    }
    //#]
}

void Receiver::updateAnalyzeData(bool value)
{
    //#[ operation updateAnalyzeData(bool)
    analyzeData = value;
    //#]
}

void Receiver::updateRawDataFilePath(const QString& path)
{
    //#[ operation updateRawDataFilePath(QString)
    rawDataFilePath = path;
    //#]
}

void Receiver::updateWriteLogData(bool value)
{
    //#[ operation updateWriteLogData(bool)
    logData = value;
    if( rawDataQFile.isOpen() )
    {
        rawDataQFile.flush();
        rawDataQFile.close();
    }
    if( logData )
    {
        rawDataQFile.setFileName( rawDataFilePath );
        rawDataQFile.open( QFile::WriteOnly | QFile::Truncate );
    }
    //#]
}

IParser* Receiver::itsActiveParser = NULL;

IParser* Receiver::itsMultiParser = NULL;

SingleParser* Receiver::itsSingleParser = NULL;

IParser* Receiver::itsTestConductorParser = NULL;

/*********************************************************************
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\Receiver.cpp
*********************************************************************/
