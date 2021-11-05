/********************************************************************
	Rhapsody	: 9.0.1 
	Login		: Y9DSYU706
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: Builder
//!	Generated Date	: Thu, 4, Nov 2021  
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\Builder.cpp
*********************************************************************/

#include "Builder.h"
//## package RunTime

//## class Builder
Builder::Builder() : itsMainWindow(0), itsTargetInformation("DefaultTarget", true, 0)
{
    initRelations();
    //#[ operation Builder()
    
    TargetInformation::setItsMainWindow(&itsMainWindow);
    // call custom init relations
    initAdapterRelations();
    
    //Connect all QT Signals with Slots
    connectSignalsFromMainWindow();
    
    //load mainWindowConfiguration
    itsMainWindow.loadConfiguration();
    
    //load communication Plugins
    itsPlugInLoader.loadPlugins();
    itsPlugInLoaderTC.loadPlugins();
    
    //load global configuration
    itsConfigurationWindow.loadSettings();
    itsConfigurationWindow.saveSettings();
    
    //load global configuration
    itsConfigurationWindow.performAutoStartSettings();
    
    //initilize Commands for all parser
    itsSingleParser.updateCommands();
    itsTestConductorParser.updateCommands();
    itsMultiParser.updateCommands(&itsTargetInformation);
    
    //Set GraphicsScene of SequenceDiagram
    itsMainWindow.getUi()->graphicsViewSD->setScene( &itsSequenceDiagram );
    itsSequenceDiagram.setItsVerticalScrollBar( itsMainWindow.getUi()->SDScrollBar );
    itsSequenceDiagram.setItsRefreshCheckBox( itsMainWindow.getUi()->checkBoxRefreshSD );
    itsSequenceDiagram.init();
    
    //Set GraphicsScene of TimingDiagram
    itsMainWindow.getUi()->graphicsViewTD->setScene( &itsTimingDiagram );
    itsTimingDiagram.setItsStartTickSpinBox( itsMainWindow.getUi()->TDtickStart );
    itsTimingDiagram.setItsTickRangeSpinBox( itsMainWindow.getUi()->TDtickRange );
    itsTimingDiagram.setItsVerticalScrollBar( itsMainWindow.getUi()->SB_TimingDiagram );
    itsTimingDiagram.setItsCheckBoxShowArguments( itsMainWindow.getUi()->cbxShowArgumentsTimingDiagram );
    itsTimingDiagram.setItsCheckBoxAutoRefresh( itsMainWindow.getUi()->checkBoxRefreshTD );
    itsTimingDiagram.init();
    
    //init TestConductor API
    itsTestConductorAPI.init();      
    
    itsRemoteControll.init();
    //#]
}

Builder::~Builder()
{
    //#[ operation ~Builder()
    disconnectSignalsFromMainWindow();
    //#]
}

void Builder::connectSignalsFromMainWindow()
{
    //#[ operation connectSignalsFromMainWindow()
    // Open XML File via selection Dialog
    QObject::connect( this->itsMainWindow.getUi()->actionOpen_XML_file,SIGNAL(triggered(bool)), &this->itsXMLReader, SLOT(openFileDialog()) );
    
    //Select communication Plugin
    QObject::connect( this->itsMainWindow.getUi()->actionSelectComPlugin, SIGNAL(triggered(bool)), &this->itsPlugInLoader, SLOT(openCommunicationList()) );
    
    //Select TC Plugin
    QObject::connect( this->itsMainWindow.getUi()->actionSelectTCPlugin, SIGNAL(triggered(bool)), &this->itsPlugInLoaderTC, SLOT(openCommunicationList()) );
    
    
    //Open XML FIle from recent Files
    QObject::connect( this->itsMainWindow.getUi()->menuRecent_opend_files, SIGNAL(triggered(QAction*)), &this->itsXMLReader, SLOT(openRecentFile(QAction*) ) );
    
    //Open Settings Window
    QObject::connect( this->itsMainWindow.getUi()->actionShowSettingsDialog, SIGNAL(triggered(bool)), &this->itsConfigurationWindow, SLOT(show()) );
    
    //Update start position for Sequencediagram in Main window
    QObject::connect( this->itsMainWindow.getUi()->SDScrollBar, SIGNAL(valueChanged(int)), &this->itsSequenceDiagram, SLOT(setVerticalScrollBarValue()) );
    
    //Trigger targetInstanceFilter
    QObject::connect( this->itsMainWindow.getItsFilterTreeItemModel(), SIGNAL(itemChanged(QStandardItem*)), &this->itsSender, SLOT(handleInstanceFilter(QStandardItem*)) );
    
    //Trigger debugIntFilter
    QObject::connect( this->itsMainWindow.getItsDebugIntTreeItemModel(), SIGNAL(itemChanged(QStandardItem*)), &this->itsSender, SLOT(handleDebugIntFilter(QStandardItem*)) );
    
    //Trigger attribute request / state request on expands on targetTreeView
    QObject::connect( this->itsMainWindow.getUi()->targetTreeView, SIGNAL(expanded(QModelIndex)), &this->itsSender, SLOT(handleTargetTreeCollaps(QModelIndex)) );
    
    //Suspend / Resume RXF
    QObject::connect( this->itsMainWindow.getUi()->actionResume_RXF, SIGNAL(triggered(bool)), &this->itsSender, SLOT(resumeRXF()) );
    QObject::connect( this->itsMainWindow.getUi()->actionSuspend_RXF, SIGNAL(triggered(bool)), &this->itsSender, SLOT(suspendRXF()) );
    
    //Breakpoint Butten with breakpoint Window
    QObject::connect( this->itsMainWindow.getUi()->actionBreakpoinMenue, SIGNAL(triggered(bool)), &this->itsBreakPoints, SLOT(showWindow()) );
    
    //InjectEvent Butten with eventInjection Window
    QObject::connect( this->itsMainWindow.getUi()->actionInjectEvent, SIGNAL(triggered(bool)), &this->itsEventInjection, SLOT(showWindow()) );
    
    //Change view
    QObject::connect( this->itsMainWindow.getUi()->viewsTreeView, SIGNAL(clicked(QModelIndex)), &this->itsSequenceDiagram, SLOT( changeCommandList(QModelIndex) ) );
    QObject::connect( this->itsMainWindow.getUi()->viewsTreeView, SIGNAL(clicked(QModelIndex)), &this->itsTimingDiagram, SLOT( changeCommandList(QModelIndex) ) );
    
    //Show ContextMenue for Views
    QObject::connect( this->itsMainWindow.getUi()->viewsTreeView, SIGNAL(customContextMenuRequested(QPoint)), &this->itsMainWindow, SLOT( showViewsContextMenue(QPoint) ) );
    QObject::connect( this->itsMainWindow.getUi()->targetTreeView, SIGNAL(customContextMenuRequested(QPoint)), &this->itsMainWindow, SLOT( showTreeContextMenue(QPoint) ) );
    
    
    // connect save command list signals to commands logger slots
    QObject::connect( &this->itsMainWindow, SIGNAL(saveCommandList(QString,CommandList)), &this->itsReceivedCommandsLogger, SLOT(saveCommandList(QString, CommandList)) );
    QObject::connect( &this->itsMainWindow, SIGNAL(saveActiveCommandList(QString)), &this->itsReceivedCommandsLogger, SLOT(saveActiveRootCommandList(QString)) );
    
    // connect load/save view signal to commands logger slot
    QObject::connect( &this->itsMainWindow, SIGNAL(saveView(QString, CommandList*)), &this->itsReceivedCommandsLogger, SLOT(saveViewData(QString, CommandList*)) );
    QObject::connect( &this->itsMainWindow, SIGNAL(loadView(QString)), &this->itsReceivedCommandsLogger, SLOT(loadViewData(QString)) );
    
    // Connect Multi Target Sync with Sender
    QObject::connect( this->itsMainWindow.getUi()->actionTimeSync, SIGNAL(triggered(bool)), &this->itsReceivedCommandsLogger, SLOT( createNewCommandListByReset() ) );
    QObject::connect( this->itsMainWindow.getUi()->actionTimeSync, SIGNAL(triggered(bool)), &this->itsTargetList, SLOT( setAllTargetsWaitingForSynchronisation()) );
    QObject::connect( this->itsMainWindow.getUi()->actionTimeSync, SIGNAL(triggered(bool)), &this->itsSender, SLOT( synchronizeTargets()) );
    
    //connect sd export
    QObject::connect( &this->itsMainWindow, SIGNAL(exportSDtoRPY(CommandList)), &this->itsSequenceDiagramToRhapsodyExporter, SLOT( toRhapsody(CommandList)) );
    
    //#]
}

void Builder::disconnectSignalsFromMainWindow()
{
    //#[ operation disconnectSignalsFromMainWindow()
    // Open XML File via selection Dialog
    QObject::disconnect( this->itsMainWindow.getUi()->actionOpen_XML_file,SIGNAL(triggered(bool)), &this->itsXMLReader, SLOT(openFileDialog()) );
    
    //Select communication Plugin
    QObject::disconnect( this->itsMainWindow.getUi()->actionSelectComPlugin, SIGNAL(triggered(bool)), &this->itsPlugInLoader, SLOT(openCommunicationList()) );
    
    //Select TC Plugin
    QObject::disconnect( this->itsMainWindow.getUi()->actionSelectTCPlugin, SIGNAL(triggered(bool)), &this->itsPlugInLoaderTC, SLOT(openCommunicationList()) );
    
    
    //Open XML FIle from recent Files
    QObject::disconnect( this->itsMainWindow.getUi()->menuRecent_opend_files, SIGNAL(triggered(QAction*)), &this->itsXMLReader, SLOT(openRecentFile(QAction*) ) );
    
    //Open Settings Window
    QObject::disconnect( this->itsMainWindow.getUi()->actionShowSettingsDialog, SIGNAL(triggered(bool)), &this->itsConfigurationWindow, SLOT(show()) );
    
    //Update start position for Sequencediagram in Main window
    QObject::disconnect( this->itsMainWindow.getUi()->SDScrollBar, SIGNAL(valueChanged(int)), &this->itsSequenceDiagram, SLOT(setVerticalScrollBarValue()) );
    
    //Trigger targetInstanceFilter
    QObject::disconnect( this->itsMainWindow.getItsFilterTreeItemModel(), SIGNAL(itemChanged(QStandardItem*)), &this->itsSender, SLOT(handleInstanceFilter(QStandardItem*)) );
    
    //Trigger debugIntFilter
    QObject::disconnect( this->itsMainWindow.getItsDebugIntTreeItemModel(), SIGNAL(itemChanged(QStandardItem*)), &this->itsSender, SLOT(handleDebugIntFilter(QStandardItem*)) );
    
    //Trigger attribute request / state request on expands on targetTreeView
    QObject::disconnect( this->itsMainWindow.getUi()->targetTreeView, SIGNAL(expanded(QModelIndex)), &this->itsSender, SLOT(handleTargetTreeCollaps(QModelIndex)) );
    
    //Suspend / Resume RXF
    QObject::disconnect( this->itsMainWindow.getUi()->actionResume_RXF, SIGNAL(triggered(bool)), &this->itsSender, SLOT(resumeRXF()) );
    QObject::disconnect( this->itsMainWindow.getUi()->actionSuspend_RXF, SIGNAL(triggered(bool)), &this->itsSender, SLOT(suspendRXF()) );
    
    //Breakpoint Butten with breakpoint Window
    QObject::disconnect( this->itsMainWindow.getUi()->actionBreakpoinMenue, SIGNAL(triggered(bool)), &this->itsBreakPoints, SLOT(showWindow()) );
    
    //InjectEvent Butten with eventInjection Window
    QObject::disconnect( this->itsMainWindow.getUi()->actionInjectEvent, SIGNAL(triggered(bool)), &this->itsEventInjection, SLOT(showWindow()) );
    
    //Change view
    QObject::disconnect( this->itsMainWindow.getUi()->viewsTreeView, SIGNAL(clicked(QModelIndex)), &this->itsSequenceDiagram, SLOT( changeCommandList(QModelIndex) ) );
    QObject::disconnect( this->itsMainWindow.getUi()->viewsTreeView, SIGNAL(clicked(QModelIndex)), &this->itsTimingDiagram, SLOT( changeCommandList(QModelIndex) ) );
    
    //Show ContextMenue for Views
    QObject::disconnect( this->itsMainWindow.getUi()->viewsTreeView, SIGNAL(customContextMenuRequested(QPoint)), &this->itsMainWindow, SLOT( showViewsContextMenue(QPoint) ) );
    
    // connect save command list signals to commands logger slots
    QObject::disconnect( &this->itsMainWindow, SIGNAL(saveCommandList(QString,CommandList)), &this->itsReceivedCommandsLogger, SLOT(saveCommandList(QString, CommandList)) );
    QObject::disconnect( &this->itsMainWindow, SIGNAL(saveActiveCommandList(QString)), &this->itsReceivedCommandsLogger, SLOT(saveActiveRootCommandList(QString)) );
    
    // connect load/save view signal to commands logger slot
    QObject::disconnect( &this->itsMainWindow, SIGNAL(saveView(QString, CommandList*)), &this->itsReceivedCommandsLogger, SLOT(saveViewData(QString, CommandList*)) );
    QObject::disconnect( &this->itsMainWindow, SIGNAL(loadView(QString)), &this->itsReceivedCommandsLogger, SLOT(loadViewData(QString)) );
    
    // Connect Multi Target Sync with Sender
    QObject::disconnect( this->itsMainWindow.getUi()->actionTimeSync, SIGNAL(triggered(bool)), &this->itsReceivedCommandsLogger, SLOT( createNewCommandListByReset() ) );
    QObject::disconnect( this->itsMainWindow.getUi()->actionTimeSync, SIGNAL(triggered(bool)), &this->itsTargetList, SLOT( setAllTargetsWaitingForSynchronisation()) );
    QObject::disconnect( this->itsMainWindow.getUi()->actionTimeSync, SIGNAL(triggered(bool)), &this->itsSender, SLOT( synchronizeTargets()) );
    
    //connect sd export
    QObject::disconnect( &this->itsMainWindow, SIGNAL(exportSDtoRPY(CommandList)), &this->itsSequenceDiagramToRhapsodyExporter, SLOT( toRhapsody(CommandList)) );    
    //#]
}

void Builder::initAdapterRelations()
{
    //#[ operation initAdapterRelations()
    // add command adapters for StringAdapterRegistry
    itsCommandStringAdapterRegistry.addCommandAdapters(&itsCommandConstructorStringAdapter);
    itsCommandStringAdapterRegistry.addCommandAdapters(&itsCommandEventCreatedStringAdapter);
    itsCommandStringAdapterRegistry.addCommandAdapters(&itsCommandEventStartDispatchStringAdapter);
    itsCommandStringAdapterRegistry.addCommandAdapters(&itsCommandEventEndDispatchStringAdapter);
    itsCommandStringAdapterRegistry.addCommandAdapters(&itsCommandTraceEventStringAdapter);
    itsCommandStringAdapterRegistry.addCommandAdapters(&itsCommandOperationCallStringAdapter);
    
    // add command adapters for KeyValueAdapterRegistry
    itsCommandKeyValueAdapterRegistry.addCommandAdapters(&itsCommandConstructorKeyValueAdapter);
    itsCommandKeyValueAdapterRegistry.addCommandAdapters(&itsCommandTraceEventKeyValueAdapter);
    //#]
}

void Builder::initRelations()
{
    itsXMLReader.setItsMainWindow(&itsMainWindow);
    itsPlugInLoader.setItsMainWindow(&itsMainWindow);
    itsConfigurationWindow.setItsPlugInLoader(&itsPlugInLoader);
    itsConfigurationWindow.setItsXMLReader(&itsXMLReader);
    itsReceiver.setItsSingleParser(&itsSingleParser);
    itsReceiver.setItsTestConductorParser(&itsTestConductorParser);
    itsReceiver.setItsActiveParser(&itsDefaultParser);
    itsDefaultParser.setItsReceivedCommandsLogger(&itsReceivedCommandsLogger);
    itsReceivedCommandsLogger.setItsMainWindow(&itsMainWindow);
    itsMainWindow.setItsSequenceDiagram(&itsSequenceDiagram);
    itsSender.setItsMainWindow(&itsMainWindow);
    itsPlugInLoader.setItsSender(&itsSender);
    itsBreakPoints.setItsSender(&itsSender);
    itsXMLReader.setItsBreakPoints(&itsBreakPoints);
    itsEventInjection.setItsSender(&itsSender);
    itsEventInjection.setItsMainWindow(&itsMainWindow);
    itsMainWindow.setItsDataViewFilterGeneration(&itsDataViewFilterGeneration);
    itsXMLReader.setItsDataViewFilterGeneration(&itsDataViewFilterGeneration);
    itsReceiver.setItsMultiParser(&itsMultiParser);
    itsPlugInLoaderTC.setItsMainWindow(&itsMainWindow);
    itsTestConductorAPI.setItsMainWindow(&itsMainWindow);
    itsTestConductorAPI.setItsPlugInLoaderTC(&itsPlugInLoaderTC);
    itsTestConductorAPI.setItsPlugInLoader(&itsPlugInLoader);
    itsConfigurationWindow.setItsPlugInLoaderTC(&itsPlugInLoaderTC);
    itsTestConductorAPI.setItsConfigurationWindow(&itsConfigurationWindow);
    itsTestConductorParser.setItsTestConductorAPI(&itsTestConductorAPI);
    itsReceivedCommandsLogger.setItsCommandStringAdapterRegistry(&itsCommandStringAdapterRegistry);
    itsMainWindowMessageLogger.setItsMainWindow(&itsMainWindow);
    itsReceivedCommandsLogger.setItsMessageLogger(&itsMainWindowMessageLogger);
    itsMainWindow.setItsTimingDiagram(&itsTimingDiagram);
    itsXMLReader.setItsEventInjection(&itsEventInjection);
    itsSingleParser.setItsMainWindow(&itsMainWindow);
    itsSingleParser.setItsTargetInformation(&itsTargetInformation);
    itsReceivedCommandsLogger.setItsCommandKeyValueAdapterRegistry(&itsCommandKeyValueAdapterRegistry);
    itsConfigurationWindow.setItsTestConductorParser(&itsTestConductorParser);
    itsConfigurationWindow.setItsReceiver(&itsReceiver);
    itsReceivedCommandsLogger.setItsRemoteControll(&itsRemoteControll);
    itsRemoteControll.setItsConfigurationWindow(&itsConfigurationWindow);
    itsRemoteControll.setItsMainWindow(&itsMainWindow);
    itsRemoteControll.setItsSender(&itsSender);
    itsSingleParser.setItsRemoteControll(&itsRemoteControll);
}

/*********************************************************************
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\Builder.cpp
*********************************************************************/
