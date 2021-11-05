/*********************************************************************
	Rhapsody	: 9.0.1 
	Login		: Y9DSYU706
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: Builder
//!	Generated Date	: Thu, 4, Nov 2021  
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\Builder.h
*********************************************************************/

#ifndef Builder_H
#define Builder_H

#include "RunTime.h"
#include "BreakPoints.h"
#include "CommandConstructorKeyValueAdapter.h"
#include "CommandConstructorStringAdapter.h"
#include "CommandEventCreatedStringAdapter.h"
#include "CommandEventEndDispatchStringAdapter.h"
#include "CommandEventStartDispatchStringAdapter.h"
#include "CommandKeyValueAdapterRegistry.h"
#include "CommandOperationCallStringAdapter.h"
#include "CommandStringAdapterRegistry.h"
#include "CommandTraceEventKeyValueAdapter.h"
#include "CommandTraceEventStringAdapter.h"
#include "ConfigurationWindow.h"
#include "DataViewFilterGeneration.h"
#include "DefaultParser.h"
#include "EventInjection.h"
#include "MainWindow.h"
#include "MainWindowMessageLogger.h"
#include "MultiParser.h"
#include "PlugInLoader.h"
#include "PlugInLoaderTC.h"
#include "ReceivedCommandsLogger.h"
#include "Receiver.h"
#include "RemoteControll.h"
#include "Sender.h"
#include "SequenceDiagram.h"
#include "SequenceDiagramToRhapsodyExporter.h"
#include "SingleParser.h"
#include "TargetInformation.h"
#include "TargetList.h"
#include "TestConductorAPI.h"
#include "TestConductorParser.h"
#include "TimingDiagram.h"
#include "XMLReader.h"
//## package RunTime

//## class Builder
class Builder {
    ////    Constructors and destructors    ////
    
public :

    //## operation Builder()
    Builder();
    
    //## operation ~Builder()
    ~Builder();
    
    ////    Operations    ////
    
    //## operation connectSignalsFromMainWindow()
    void connectSignalsFromMainWindow();
    
    //## operation disconnectSignalsFromMainWindow()
    void disconnectSignalsFromMainWindow();

private :

    // This must be called and maintained manually, because the code generator currently does not handle links of qualified associations.
    //## operation initAdapterRelations()
    void initAdapterRelations();
    
    ////    Additional operations    ////

public :

    inline BreakPoints* getItsBreakPoints() const
    {
        return (BreakPoints*) &itsBreakPoints;
    }
    
    inline CommandConstructorKeyValueAdapter* getItsCommandConstructorKeyValueAdapter() const
    {
        return (CommandConstructorKeyValueAdapter*) &itsCommandConstructorKeyValueAdapter;
    }
    
    inline CommandConstructorStringAdapter* getItsCommandConstructorStringAdapter() const
    {
        return (CommandConstructorStringAdapter*) &itsCommandConstructorStringAdapter;
    }
    
    inline CommandEventCreatedStringAdapter* getItsCommandEventCreatedStringAdapter() const
    {
        return (CommandEventCreatedStringAdapter*) &itsCommandEventCreatedStringAdapter;
    }
    
    inline CommandEventEndDispatchStringAdapter* getItsCommandEventEndDispatchStringAdapter() const
    {
        return (CommandEventEndDispatchStringAdapter*) &itsCommandEventEndDispatchStringAdapter;
    }
    
    inline CommandEventStartDispatchStringAdapter* getItsCommandEventStartDispatchStringAdapter() const
    {
        return (CommandEventStartDispatchStringAdapter*) &itsCommandEventStartDispatchStringAdapter;
    }
    
    inline CommandKeyValueAdapterRegistry* getItsCommandKeyValueAdapterRegistry() const
    {
        return (CommandKeyValueAdapterRegistry*) &itsCommandKeyValueAdapterRegistry;
    }
    
    inline CommandOperationCallStringAdapter* getItsCommandOperationCallStringAdapter() const
    {
        return (CommandOperationCallStringAdapter*) &itsCommandOperationCallStringAdapter;
    }
    
    inline CommandStringAdapterRegistry* getItsCommandStringAdapterRegistry() const
    {
        return (CommandStringAdapterRegistry*) &itsCommandStringAdapterRegistry;
    }
    
    inline CommandTraceEventKeyValueAdapter* getItsCommandTraceEventKeyValueAdapter() const
    {
        return (CommandTraceEventKeyValueAdapter*) &itsCommandTraceEventKeyValueAdapter;
    }
    
    inline CommandTraceEventStringAdapter* getItsCommandTraceEventStringAdapter() const
    {
        return (CommandTraceEventStringAdapter*) &itsCommandTraceEventStringAdapter;
    }
    
    inline ConfigurationWindow* getItsConfigurationWindow() const
    {
        return (ConfigurationWindow*) &itsConfigurationWindow;
    }
    
    inline DataViewFilterGeneration* getItsDataViewFilterGeneration() const
    {
        return (DataViewFilterGeneration*) &itsDataViewFilterGeneration;
    }
    
    inline DefaultParser* getItsDefaultParser() const
    {
        return (DefaultParser*) &itsDefaultParser;
    }
    
    inline EventInjection* getItsEventInjection() const
    {
        return (EventInjection*) &itsEventInjection;
    }
    
    inline MainWindow* getItsMainWindow() const
    {
        return (MainWindow*) &itsMainWindow;
    }
    
    inline MainWindowMessageLogger* getItsMainWindowMessageLogger() const
    {
        return (MainWindowMessageLogger*) &itsMainWindowMessageLogger;
    }
    
    inline MultiParser* getItsMultiParser() const
    {
        return (MultiParser*) &itsMultiParser;
    }
    
    inline PlugInLoader* getItsPlugInLoader() const
    {
        return (PlugInLoader*) &itsPlugInLoader;
    }
    
    inline PlugInLoaderTC* getItsPlugInLoaderTC() const
    {
        return (PlugInLoaderTC*) &itsPlugInLoaderTC;
    }
    
    inline ReceivedCommandsLogger* getItsReceivedCommandsLogger() const
    {
        return (ReceivedCommandsLogger*) &itsReceivedCommandsLogger;
    }
    
    inline Receiver* getItsReceiver() const
    {
        return (Receiver*) &itsReceiver;
    }
    
    inline RemoteControll* getItsRemoteControll() const
    {
        return (RemoteControll*) &itsRemoteControll;
    }
    
    inline Sender* getItsSender() const
    {
        return (Sender*) &itsSender;
    }
    
    inline SequenceDiagram* getItsSequenceDiagram() const
    {
        return (SequenceDiagram*) &itsSequenceDiagram;
    }
    
    inline SequenceDiagramToRhapsodyExporter* getItsSequenceDiagramToRhapsodyExporter() const
    {
        return (SequenceDiagramToRhapsodyExporter*) &itsSequenceDiagramToRhapsodyExporter;
    }
    
    inline SingleParser* getItsSingleParser() const
    {
        return (SingleParser*) &itsSingleParser;
    }
    
    inline TargetInformation* getItsTargetInformation() const
    {
        return (TargetInformation*) &itsTargetInformation;
    }
    
    inline TargetList* getItsTargetList() const
    {
        return (TargetList*) &itsTargetList;
    }
    
    inline TestConductorAPI* getItsTestConductorAPI() const
    {
        return (TestConductorAPI*) &itsTestConductorAPI;
    }
    
    inline TestConductorParser* getItsTestConductorParser() const
    {
        return (TestConductorParser*) &itsTestConductorParser;
    }
    
    inline TimingDiagram* getItsTimingDiagram() const
    {
        return (TimingDiagram*) &itsTimingDiagram;
    }
    
    inline XMLReader* getItsXMLReader() const
    {
        return (XMLReader*) &itsXMLReader;
    }

protected :

    void initRelations();
    
    ////    Relations and components    ////
    
    BreakPoints itsBreakPoints;
    
    CommandConstructorKeyValueAdapter itsCommandConstructorKeyValueAdapter;
    
    CommandConstructorStringAdapter itsCommandConstructorStringAdapter;
    
    CommandEventCreatedStringAdapter itsCommandEventCreatedStringAdapter;
    
    CommandEventEndDispatchStringAdapter itsCommandEventEndDispatchStringAdapter;
    
    CommandEventStartDispatchStringAdapter itsCommandEventStartDispatchStringAdapter;
    
    CommandKeyValueAdapterRegistry itsCommandKeyValueAdapterRegistry;
    
    CommandOperationCallStringAdapter itsCommandOperationCallStringAdapter;
    
    CommandStringAdapterRegistry itsCommandStringAdapterRegistry;
    
    CommandTraceEventKeyValueAdapter itsCommandTraceEventKeyValueAdapter;
    
    CommandTraceEventStringAdapter itsCommandTraceEventStringAdapter;
    
    ConfigurationWindow itsConfigurationWindow;
    
    DataViewFilterGeneration itsDataViewFilterGeneration;
    
    DefaultParser itsDefaultParser;
    
    EventInjection itsEventInjection;
    
    MainWindow itsMainWindow;
    
    MainWindowMessageLogger itsMainWindowMessageLogger;
    
    MultiParser itsMultiParser;
    
    PlugInLoader itsPlugInLoader;
    
    PlugInLoaderTC itsPlugInLoaderTC;
    
    ReceivedCommandsLogger itsReceivedCommandsLogger;
    
    Receiver itsReceiver;
    
    RemoteControll itsRemoteControll;
    
    Sender itsSender;
    
    SequenceDiagram itsSequenceDiagram;
    
    SequenceDiagramToRhapsodyExporter itsSequenceDiagramToRhapsodyExporter;
    
    SingleParser itsSingleParser;
    
    TargetInformation itsTargetInformation;
    
    TargetList itsTargetList;
    
    TestConductorAPI itsTestConductorAPI;
    
    TestConductorParser itsTestConductorParser;
    
    TimingDiagram itsTimingDiagram;
    
    XMLReader itsXMLReader;
};

#endif
/*********************************************************************
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\Builder.h
*********************************************************************/
