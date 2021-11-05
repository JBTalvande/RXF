/********************************************************************
	Rhapsody	: 9.0.1 
	Login		: Y9DSYU706
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: TestConductorAPI
//!	Generated Date	: Thu, 4, Nov 2021  
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\TestConductorAPI.cpp
*********************************************************************/

#include "TestConductorAPI.h"
#include "ConfigurationWindow.h"
#include "IParser.h"
#include "MainWindow.h"
#include "PlugInLoader.h"
#include "PlugInLoaderTC.h"
#include "Sender.h"
#include <QDataStream>
#include <QTcpServer>
#include <QTcpSocket>
//## package API

//## class TestConductorAPI
TestConductorAPI::TestConductorAPI()
{
    itsConfigurationWindow = NULL;
    itsMainWindow = NULL;
    itsPlugInLoader = NULL;
    itsPlugInLoaderTC = NULL;
    itsQTcpServer = NULL;
    newClient = NULL;
    //#[ operation TestConductorAPI()
    itsQTcpServer = new QTcpServer();
    //#]
}

TestConductorAPI::~TestConductorAPI()
{
    //#[ operation ~TestConductorAPI()
    itsMainWindow->consoleMsg("Server port " + QString::number(itsQTcpServer->serverPort()) + " closed");
    if( newClient != NULL )
    {
            disconnect(newClient, SIGNAL(readyRead()), this, SLOT(readData()) );
    }
    itsQTcpServer->close();
    //#]
    cleanUpRelations();
}

void TestConductorAPI::TCPIPnewConnection()
{
    //#[ operation TCPIPnewConnection()
    if( newClient != NULL )
    {
        newClient->close();
        disconnect(newClient, SIGNAL(readyRead()), this, SLOT(readData()) );
    }
    newClient = itsQTcpServer->nextPendingConnection();
    connect(newClient, SIGNAL(readyRead()), this, SLOT(readData()), Qt::DirectConnection);
    //#]
}

void TestConductorAPI::init()
{
    //#[ operation init()
    TcpServerPortNumber = itsConfigurationWindow->getTestConductorPort();
    if( TcpServerPortNumber > 0 )
    {
        if (!itsQTcpServer->listen(QHostAddress::LocalHost, TcpServerPortNumber))
        {
            itsMainWindow->errorMsg("Test Server Already Running"+ itsQTcpServer->errorString()+ "\n"); //Problems in starting server
        }
        else
        {
            itsMainWindow->consoleMsg( "TCP/IP Test Server start on port " + QString::number(itsQTcpServer->serverPort()) + ".");
            connect (itsQTcpServer, SIGNAL(newConnection()), this, SLOT(TCPIPnewConnection()));
        }
    }
    //#]
}

void TestConductorAPI::readData()
{
    //#[ operation readData()
    char data[1000];
    while( newClient->readLine(data, 1000) > 0 )
    {
    	QString msg(data);
    	itsMainWindow->consoleMsg("from TC = " + msg +" End");
    	if(msg.startsWith("OPEN_IDE_PROJECT"))
    	{
    	    if( itsPlugInLoaderTC->getActivePlugin() != NULL )
    	    {
    	        QStringList tmpMsgList = msg.split("OPEN_IDE_PROJECT");
    	        QString tmpMsg = "";
    	        if(tmpMsgList.size() > 0){
    	            tmpMsg = tmpMsgList.last();
    	            tmpMsg = tmpMsg.replace("|","");
    	        }
    	
    	        int error = itsPlugInLoaderTC->getActivePlugin()->openIDEProject( tmpMsg );
    	        if( error == 0 )
    	        {
    	            newClient->write("OK\0",3);
    	        }
    	        else if( error == 1 )
    	        {
    	            itsMainWindow->consoleMsg("Please open the IDE project manualy.");
    	            newClient->write("NOT_SUPPORTED\0",14);
    	        }
    	        else
    	        {
    	            itsMainWindow->consoleMsg("Open the IDE project failed.");
    	            newClient->write("ERROR\0",6);
    	        }
    	    }
    	    else
    	    {
    	        itsMainWindow->consoleMsg("Please, first select a communication plugin.");
    	        newClient->write("NOT_SUPPORTED\0",14);
    	    }
    	}
    	
    	
    	if(msg.startsWith("COMPILE_TARGET"))
    	{
    	    if(itsPlugInLoaderTC->getActivePlugin() != NULL ){
    	        int error = itsPlugInLoaderTC->getActivePlugin()->compileTarget();
    	        if( error == 0 )
    	        {
    	            itsMainWindow->consoleMsg("Compilation done.");
    	            newClient->write("OK\0",3);
    	        }
    	        else if( error == 1 )
    	        {
    	            itsMainWindow->consoleMsg("Please compile the target manual.");
    	            newClient->write("NOT_SUPPORTED\0",14);
    	        }
    	        else
    	        {
    	            itsMainWindow->consoleMsg("The compilation failed.");
    	            newClient->write("ERROR\0",6);
    	        }
    	    }
    	    else
    	    {
    	        itsMainWindow->consoleMsg("Please, first select a communication plugin.");
    	        newClient->write("NOT_SUPPORTED\0",14);
    	    }
    	}
    	
    	if(msg.startsWith("FLASH_TARGET"))
    	{
    	    if(itsPlugInLoaderTC->getActivePlugin() != NULL ){
    	        int error = itsPlugInLoaderTC->getActivePlugin()->flashTarget();
    	        if( error == 0 )
    	        {
    	            itsMainWindow->consoleMsg("Flash done.");
    	            newClient->write("OK\0",3);
    	        }
    	        else if( error == 1 )
    	        {
    	            itsMainWindow->consoleMsg("Please flash the target manual.");
    	            newClient->write("NOT_SUPPORTED\0",14);
    	        }
    	        else
    	        {
    	            itsMainWindow->consoleMsg("Flashing the target failed.");
    	            newClient->write("ERROR\0",6);
    	        }
    	    }
    	    else
    	    {
    	        itsMainWindow->consoleMsg("Please, first select a communication plugin.");
    	        newClient->write("NOT_SUPPORTED\0",14);
    	    }
    	}
    	
    	if(msg.startsWith("RUN_TARGET"))
    	{
    	    itsMainWindow->consoleMsg("from TC = " + msg);
    	    if(itsPlugInLoaderTC->getActivePlugin() != NULL ){
    	        int error = itsPlugInLoaderTC->getActivePlugin()->runTarget();
    	        if( error == 0 )
    	        {
    	            itsMainWindow->consoleMsg("Target running.");
    	            newClient->write("OK\0",3);
    	        }
    	        else if( error == 1 )
    	        {
    	            itsMainWindow->consoleMsg("Please start the target manual.");
    	            newClient->write("NOT_SUPPORTED\0",14);
    	        }
    	        else
    	        {
    	            itsMainWindow->consoleMsg("Starting the target failed.");
    	            newClient->write("ERROR\0",6);
    	        }
    	    }
    	    else
    	    {
    	        itsMainWindow->consoleMsg("Please, first select a communication plugin.");
    	        newClient->write("NOT_SUPPORTED\0",14);
    	    }
    	}
    	
    	if(msg.startsWith("EXECUTE_TEST|"))
    	{
    	    if( itsPlugInLoader->getItsSender() != NULL){
    	        TCPath = "";
    	        TCCovPath = "";
    	        TCModCovPath = "";
    	        if( msg.contains("||") )
    	        {
    	            msg = msg.replace("EXECUTE_TEST||", "");
    	            QStringList ETmsg = msg.split("||");
    	            QString tcName = "";
    	            for( QString part : ETmsg)
    	            {
    	                if( part.startsWith("TCASE|") )
    	                {
    	                    tcName = part.split("TCASE|").at(1);
    	                }
    	                else if( part.startsWith("RESFILE|") )
    	                {
    	                    TCPath = part.split("RESFILE|").at(1);
    	                }
    	                else if( part.startsWith("CCOVFILE|") )
    	                {
    	                    TCCovPath = part.split("CCOVFILE|").at(1);
    	                }
    	                else if( part.startsWith("MCOVFILE|") )
    	                {
    	                    TCModCovPath = part.split("MCOVFILE|").at(1);
    	                }
    	            }
    	            if( tcName != "" )
    	            {
    	                IParser::resetParserPointer();
    	                itsPlugInLoader->getItsSender()->executeTest( tcName );
    	            }
    	            else
    	            {
    	                itsMainWindow->consoleMsg("Test Case Format not correct");
    	            }
    	
    	        }
    	        else
    	        {
    	            QStringList ETmsg = msg.split("|");
    	            if( ETmsg.size() == 2 )
    	            {
    	                itsPlugInLoader->getItsSender()->executeTest( ETmsg[1] );
    	            }
    	            else if(ETmsg.size() == 3)
    	            {
    	                TCPath = ETmsg[2];
    	                itsPlugInLoader->getItsSender()->executeTest( ETmsg[1] );
    	            }
    	            else if(ETmsg.size() == 4)
    	            {
    	                TCPath = ETmsg[2];
    	                TCCovPath = ETmsg[3];
    	                itsPlugInLoader->getItsSender()->executeTest( ETmsg[1] );
    	            }
    	            else
    	            {
    	                itsMainWindow->consoleMsg("Test Case Format not correct");
    	            }
    	        }
    	    }
    	    else
    	    {
    	        itsMainWindow->consoleMsg("Please, first select a communication plugin.");
    	    }
    	}
    	newClient->flush();
    }
    //#]
}

void TestConductorAPI::rtcCoverage(const QString& msg)
{
    //#[ operation rtcCoverage(QString)
    FILE *out =fopen(TCCovPath.toStdString().c_str(),"a+");
    itsMainWindow->consoleMsg("Code Coverage Information: " + msg);
    if(out != NULL)
    {
        fprintf(out,msg.toStdString().c_str());
        fflush( out );
        fclose( out );
    }
    //#]
}

void TestConductorAPI::rtcExit()
{
    //#[ operation rtcExit()
    if(newClient != NULL)
    {
        itsMainWindow->consoleMsg("Test Case execution finished.");
        newClient->write("OK\0",3);
    }
    //#]
}

void TestConductorAPI::rtcInfo(unsigned int e, unsigned int ln, unsigned int nr)
{
    //#[ operation rtcInfo(unsigned int,unsigned int,unsigned int)
    QString msg = "ASSERTION=" + QString::number(nr) + "," + QString::number(ln) + "," + QString::number(e) + "\n";
    itsMainWindow->consoleMsg(msg);
    if( TCPath != NULL )
    {
        FILE *out =fopen(TCPath.toStdString().c_str(),"a+");
        if(out != NULL)
        {
            fprintf(out,msg.toStdString().c_str());
            fflush( out );
            fclose( out );
        }
    }
    //#]
}

void TestConductorAPI::rtcModCoverage(const QString& msg)
{
    //#[ operation rtcModCoverage(QString)
    FILE *out =fopen(TCModCovPath.toStdString().c_str(),"a+");
    itsMainWindow->consoleMsg("Model Coverage Information: " + msg);
    if(out != NULL)
    {
        fprintf(out,msg.toStdString().c_str());
        fflush( out );
        fclose( out );
    }
    //#]
}

void TestConductorAPI::cleanUpRelations()
{
    if(itsConfigurationWindow != NULL)
        {
            itsConfigurationWindow = NULL;
        }
    if(itsMainWindow != NULL)
        {
            itsMainWindow = NULL;
        }
    if(itsPlugInLoader != NULL)
        {
            itsPlugInLoader = NULL;
        }
    if(itsPlugInLoaderTC != NULL)
        {
            itsPlugInLoaderTC = NULL;
        }
    if(itsQTcpServer != NULL)
        {
            itsQTcpServer = NULL;
        }
    if(newClient != NULL)
        {
            newClient = NULL;
        }
}

/*********************************************************************
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\TestConductorAPI.cpp
*********************************************************************/
