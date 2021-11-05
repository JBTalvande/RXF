/*********************************************************************
	Rhapsody	: 9.0.1 
	Login		: Y9DSYU706
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: TestConductorAPI
//!	Generated Date	: Thu, 4, Nov 2021  
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\TestConductorAPI.h
*********************************************************************/

#ifndef TestConductorAPI_H
#define TestConductorAPI_H

#include <QObject>
class ConfigurationWindow;

class IParser;

class MainWindow;

class PlugInLoader;

class PlugInLoaderTC;

class QTcpServer;

class QTcpSocket;

class Sender;

//## package API

//## class TestConductorAPI
class TestConductorAPI : public QObject {
Q_OBJECT
    ////    Constructors and destructors    ////
    
public :

    //## operation TestConductorAPI()
    TestConductorAPI();
    
    //## operation ~TestConductorAPI()
    ~TestConductorAPI();
    
    ////    Operations    ////
    
    //## operation TCPIPnewConnection()
    Q_SLOT void TCPIPnewConnection();
    
    //## operation init()
    void init();
    
    //## operation readData()
    Q_SLOT void readData();
    
    //## operation rtcCoverage(QString)
    void rtcCoverage(const QString& msg);
    
    //## operation rtcExit()
    void rtcExit();
    
    //## operation rtcInfo(unsigned int,unsigned int,unsigned int)
    void rtcInfo(unsigned int e, unsigned int ln, unsigned int nr);
    
    //## operation rtcModCoverage(QString)
    void rtcModCoverage(const QString& msg);
    
    ////    Additional operations    ////
    
    inline QString getTCCovPath() const
    {
        return TCCovPath;
    }
    
    inline void setTCCovPath(QString p_TCCovPath)
    {
        TCCovPath = p_TCCovPath;
    }
    
    inline QString getTCModCovPath() const
    {
        return TCModCovPath;
    }
    
    inline void setTCModCovPath(QString p_TCModCovPath)
    {
        TCModCovPath = p_TCModCovPath;
    }
    
    inline QString getTCPath() const
    {
        return TCPath;
    }
    
    inline void setTCPath(QString p_TCPath)
    {
        TCPath = p_TCPath;
    }
    
    inline int getTcpServerPortNumber() const
    {
        return TcpServerPortNumber;
    }
    
    inline void setTcpServerPortNumber(int p_TcpServerPortNumber)
    {
        TcpServerPortNumber = p_TcpServerPortNumber;
    }
    
    inline ConfigurationWindow* getItsConfigurationWindow() const
    {
        return itsConfigurationWindow;
    }
    
    inline void setItsConfigurationWindow(ConfigurationWindow* p_ConfigurationWindow)
    {
        itsConfigurationWindow = p_ConfigurationWindow;
    }
    
    inline MainWindow* getItsMainWindow() const
    {
        return itsMainWindow;
    }
    
    inline void setItsMainWindow(MainWindow* p_MainWindow)
    {
        itsMainWindow = p_MainWindow;
    }
    
    inline PlugInLoader* getItsPlugInLoader() const
    {
        return itsPlugInLoader;
    }
    
    inline void setItsPlugInLoader(PlugInLoader* p_PlugInLoader)
    {
        itsPlugInLoader = p_PlugInLoader;
    }
    
    inline PlugInLoaderTC* getItsPlugInLoaderTC() const
    {
        return itsPlugInLoaderTC;
    }
    
    inline void setItsPlugInLoaderTC(PlugInLoaderTC* p_PlugInLoaderTC)
    {
        itsPlugInLoaderTC = p_PlugInLoaderTC;
    }
    
    inline QTcpServer* getItsQTcpServer() const
    {
        return itsQTcpServer;
    }
    
    inline void setItsQTcpServer(QTcpServer* p_QTcpServer)
    {
        itsQTcpServer = p_QTcpServer;
    }
    
    inline QTcpSocket* getNewClient() const
    {
        return newClient;
    }
    
    inline void setNewClient(QTcpSocket* p_QTcpSocket)
    {
        newClient = p_QTcpSocket;
    }

protected :

    void cleanUpRelations();
    
    ////    Attributes    ////

private :

    QString TCCovPath;		//## attribute TCCovPath
    
    QString TCModCovPath;		//## attribute TCModCovPath
    
    QString TCPath;		//## attribute TCPath
    
    int TcpServerPortNumber;		//## attribute TcpServerPortNumber
    
    ////    Relations and components    ////

protected :

    ConfigurationWindow* itsConfigurationWindow;
    
    MainWindow* itsMainWindow;
    
    PlugInLoader* itsPlugInLoader;
    
    PlugInLoaderTC* itsPlugInLoaderTC;
    
    QTcpServer* itsQTcpServer;
    
    QTcpSocket* newClient;
};

#endif
/*********************************************************************
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\TestConductorAPI.h
*********************************************************************/
