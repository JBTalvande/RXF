/*********************************************************************
	Rhapsody	: 9.0.1 
	Login		: Y9DSYU706
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: Receiver
//!	Generated Date	: Thu, 4, Nov 2021  
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\Receiver.h
*********************************************************************/

#ifndef Receiver_H
#define Receiver_H

#include "DataTransmission.h"
#include <QString>
#include <QFile>
class IParser;

class SingleParser;

//## package LogicLevel::DataTransmission

//## class Receiver
class Receiver : public QObject {
Q_OBJECT
private :

    enum MonitorTypes {
        SingleTarget = 0,
        MultiTarget = 1,
        TestConductor = 2
    };
    
    ////    Constructors and destructors    ////

public :

    //## operation Receiver()
    Receiver();
    
    ~Receiver();
    
    ////    Operations    ////
    
    //## operation analyzeStream()
    Q_SLOT void analyzeStream();
    
    //## operation processConstructors(bool)
    void processConstructors(bool value);
    
    //## operation processDestructors(bool)
    void processDestructors(bool value);
    
    //## operation receiveData(char*,unsigned int)
    static void receiveData(char* data, unsigned int length);
    
    //## operation setParser(unsigned char)
    static void setParser(unsigned char monitorType);
    
    //## operation updateAnalyzeData(bool)
    void updateAnalyzeData(bool value);
    
    //## operation updateRawDataFilePath(QString)
    void updateRawDataFilePath(const QString& path);
    
    //## operation updateWriteLogData(bool)
    void updateWriteLogData(bool value);
    
    ////    Additional operations    ////
    
    inline int getRefreshRateInMS() const
    {
        return RefreshRateInMS;
    }
    
    inline void setRefreshRateInMS(int p_RefreshRateInMS)
    {
        RefreshRateInMS = p_RefreshRateInMS;
    }
    
    inline static bool getAnalyzeData()
    {
        return analyzeData;
    }
    
    inline static void setAnalyzeData(bool p_analyzeData)
    {
        analyzeData = p_analyzeData;
    }
    
    inline int getBytesPerStep() const
    {
        return bytesPerStep;
    }
    
    inline void setBytesPerStep(int p_bytesPerStep)
    {
        bytesPerStep = p_bytesPerStep;
    }
    
    inline static bool getLogData()
    {
        return logData;
    }
    
    inline static void setLogData(bool p_logData)
    {
        logData = p_logData;
    }
    
    inline QString getRawDataFilePath() const
    {
        return rawDataFilePath;
    }
    
    inline void setRawDataFilePath(QString p_rawDataFilePath)
    {
        rawDataFilePath = p_rawDataFilePath;
    }
    
    inline static IParser* getItsActiveParser()
    {
        return itsActiveParser;
    }
    
    inline static void setItsActiveParser(IParser* p_IParser)
    {
        itsActiveParser = p_IParser;
    }
    
    inline static IParser* getItsMultiParser()
    {
        return itsMultiParser;
    }
    
    inline static void setItsMultiParser(IParser* p_IParser)
    {
        itsMultiParser = p_IParser;
    }
    
    inline static SingleParser* getItsSingleParser()
    {
        return itsSingleParser;
    }
    
    inline static void setItsSingleParser(SingleParser* p_SingleParser)
    {
        itsSingleParser = p_SingleParser;
    }
    
    inline static IParser* getItsTestConductorParser()
    {
        return itsTestConductorParser;
    }
    
    inline static void setItsTestConductorParser(IParser* p_IParser)
    {
        itsTestConductorParser = p_IParser;
    }
    
    ////    Attributes    ////

private :

    int RefreshRateInMS;		//## attribute RefreshRateInMS
    
    static bool analyzeData;		//## attribute analyzeData
    
    int bytesPerStep;		//## attribute bytesPerStep
    
    static bool logData;		//## attribute logData
    
    QString rawDataFilePath;		//## attribute rawDataFilePath
    
    static QFile rawDataQFile;		//## attribute rawDataQFile
    
    ////    Relations and components    ////

protected :

    static IParser* itsActiveParser;
    
    static IParser* itsMultiParser;
    
    static SingleParser* itsSingleParser;
    
    static IParser* itsTestConductorParser;
};

#endif
/*********************************************************************
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\Receiver.h
*********************************************************************/
