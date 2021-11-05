/*********************************************************************
	Rhapsody	: 9.0.1 
	Login		: Y9DSYU706
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: LogicLevel
//!	Generated Date	: Thu, 4, Nov 2021  
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\LogicLevel.h
*********************************************************************/

#ifndef LogicLevel_H
#define LogicLevel_H

#include <QString>
//## package LogicLevel


//#[ ignore
// This Package contains classes which handle the functionality of the UML Target Debugger.
//#]

enum languageTypes {
    C_LANGUAGE = 0,
    CPP_LANGUAGE = 1
};

enum modellingTools {
    MDD_RHAPSODY = 0,
    MDD_ENTERPRISE_ARCHITEKT = 1
};

enum endianness {
    LITTLE_ENDIAN = 0,
    BIG_ENDIAN = 1
};

//## attribute VersionNr
extern QString VersionNr;

// Global variable which indicates if the target runs with an CPP or C RXF.
// This information will be parsed from the XML File.
//## attribute languageKind
extern languageTypes languageKind;

//## attribute modellingTool
extern modellingTools modellingTool;

#endif
/*********************************************************************
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\LogicLevel.h
*********************************************************************/
