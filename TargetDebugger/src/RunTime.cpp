/********************************************************************
	Rhapsody	: 9.0.1 
	Login		: Y9DSYU706
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: RunTime
//!	Generated Date	: Thu, 4, Nov 2021  
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\RunTime.cpp
*********************************************************************/

#include "RunTime.h"
#include "Builder.h"
//## package RunTime


//## operation main(int,char*)
int main(int argc, char* argv [])
{
    //#[ operation main(int,char*)
    QApplication a(argc, argv);
    Builder b;
    
    for(int i = 0 ; i < (argc -1); i++ )
    {
        QString myValue(argv[i]);
        if( myValue.compare("-x") == 0 || myValue.compare("-xml") == 0 )
        {
            QString xmlPath(argv[i+1]);
            QFile myXMLFile(xmlPath);
            if(myXMLFile.exists())
            {
                b.getItsXMLReader()->openAndParseXMLFile( xmlPath );
            }
            else
            {
                b.getItsMainWindow()->consoleMsg("XML file do NOT exist: " + xmlPath);
            }
        }
    
    }
    
    return a.exec();
    //#]
}

/*********************************************************************
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\RunTime.cpp
*********************************************************************/
