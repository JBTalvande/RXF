/********************************************************************
	Rhapsody	: 9.0.1 
	Login		: Y9DSYU706
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: ConfigurationWindow
//!	Generated Date	: Thu, 4, Nov 2021  
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\ConfigurationWindow.cpp
*********************************************************************/

#include "ConfigurationWindow.h"
#include "PlugInLoader.h"
#include "PlugInLoaderTC.h"
#include "Receiver.h"
#include "SequenceDiagram.h"
#include "TestConductorParser.h"
#include "TimingDiagram.h"
#include "XMLReader.h"
#include <QStringList>
#include <QFileDialog>
//## package GUI

//## class ConfigurationWindow
ConfigurationWindow::ConfigurationWindow() : qSettingsFile("Configuration.ini", QSettings::IniFormat), ui(new Ui::ConfigurationWindow)
{
    itsPlugInLoader = NULL;
    itsPlugInLoaderTC = NULL;
    itsReceiver = NULL;
    itsTestConductorParser = NULL;
    itsXMLReader = NULL;
    //#[ operation ConfigurationWindow()
    ui->setupUi( this );
    connectSignals();
    //#]
}

ConfigurationWindow::~ConfigurationWindow()
{
    //#[ operation ~ConfigurationWindow()
    disconnectSignals();
    //#]
    cleanUpRelations();
}

void ConfigurationWindow::connectSignals()
{
    //#[ operation connectSignals()
    connect(ui->BTN_CloseWindow, SIGNAL(released()), this, SLOT(saveSettings()) );
    connect(this, SIGNAL(rejected()),this, SLOT(loadSettings()) );
    connect( ui->BTN_BrowseXMLFileForAutoStart, SIGNAL(released()), this, SLOT(setAutoStartXMLPath()) );
    connect( ui->BTN_ConfigurePluginForAutoStart, SIGNAL(released()), this, SLOT(openAutoStartConfigurationDialog()) );
    connect( ui->BTN_TCConfigurePluginForAutoStart, SIGNAL(released()), this, SLOT(openTCAutoStartConfigurationDialog()) );
    connect( ui->BTN_ReceiveDataBrowseRawDataFile, SIGNAL(released()), this, SLOT(openFilePathForSaveRawData()) );
    connect( ui->RAD_BigEndian, SIGNAL(clicked(bool)), this, SLOT(setBigEndian() ) );
    connect( ui->RAD_LittleEndian, SIGNAL(clicked(bool)), this, SLOT(setLittleEndian() ) );
    //#]
}

int ConfigurationWindow::getRemoteControlPort()
{
    //#[ operation getRemoteControlPort()
    return ui->SB_RCPort->value();
    //#]
}

int ConfigurationWindow::getTestConductorPort()
{
    //#[ operation getTestConductorPort()
    return ui->SB_TCPort->value();
    //#]
}

void ConfigurationWindow::loadSettings()
{
    //#[ operation loadSettings()
    ui->SEL_PluginForStartUp->clear();
    ui->SEL_PluginForStartUp->addItems(itsPlugInLoader->getPluginStringList());
    
    ui->SEL_TCPluginForStartUp->clear();
    ui->SEL_TCPluginForStartUp->addItems(itsPlugInLoaderTC->getPluginStringList());
    
    qSettingsFile.beginGroup("GlobalConfiguration");
    
     qSettingsFile.beginGroup("DiagramView");
      ui->CBX_SD_StateDelta->setChecked( qSettingsFile.value("SD_StateDelta").toBool() );
      ui->CBX_TD_StateDelta->setChecked( qSettingsFile.value("TD_StateDelta").toBool() );
      ui->CBX_SD_HideOmNoneState->setChecked( qSettingsFile.value("SD_HideOmNoneState").toBool() );
      ui->CBX_TD_HideOmNoneState->setChecked( qSettingsFile.value("TD_HideOmNoneState").toBool() );
     qSettingsFile.endGroup();
    
     qSettingsFile.beginGroup("StartUp");
    
      qSettingsFile.beginGroup("XML_File");
       ui->CBX_LoadXMLForStartUp->setChecked( qSettingsFile.value("loadXMLFileOnStartUp").toBool() );
       ui->TXT_XMLPathForStartUp->setText( qSettingsFile.value("xmlFileOnStartUp").toString() );
      qSettingsFile.endGroup();
    
      qSettingsFile.beginGroup("Plugin");
       ui->CBX_PluginForStartUp->setChecked( qSettingsFile.value("loadPluginOnStartUp").toBool() );
       ui->SEL_PluginForStartUp->setCurrentText( qSettingsFile.value("pluginOnStartUp").toString() );
      qSettingsFile.endGroup();
    
      qSettingsFile.beginGroup("TestConductor"); 
       if( qSettingsFile.value("TC_Endianess").isValid() )
       {
           if( qSettingsFile.value("TC_Endianess").toBool() )
           {
               ui->RAD_LittleEndian->setChecked( true );
           }
           else
           {
               ui->RAD_BigEndian->setChecked( true );
           }
       }
       else
       {
           ui->RAD_LittleEndian->setChecked( true );
       }
    
    
       qSettingsFile.beginGroup("PluginTC");
        ui->CBX_TCPluginForStartUp->setChecked( qSettingsFile.value("loadPluginOnStartUp").toBool() );
        ui->SEL_TCPluginForStartUp->setCurrentText( qSettingsFile.value("pluginOnStartUp").toString() );
        bool ok;
        int port = qSettingsFile.value("port").toInt(&ok);
        if( ok )
        {
            ui->SB_TCPort->setValue( port );
        }
        else
        {
            ui->SB_TCPort->setValue( 5050 );
        }
       qSettingsFile.endGroup();
      qSettingsFile.endGroup();
    
      qSettingsFile.beginGroup("RemoteControl");
        port = qSettingsFile.value("port").toInt(&ok);
        if( ok )
        {
            ui->SB_RCPort->setValue( port );
        }
        else
        {
            ui->SB_RCPort->setValue( 27015 );
        }
      qSettingsFile.endGroup();
    
      qSettingsFile.beginGroup("Receiver");
       ui->TXT_ReceiveDataSaveRawDataFile->setText( qSettingsFile.value("ReceiveDataSaveRawDataFile").toString() );
       if( qSettingsFile.value("ReceiveDataAnalyzeData").isValid() )
       {
           ui->CBX_ReceiveDataAnalyzeData->setChecked( qSettingsFile.value("ReceiveDataAnalyzeData").toBool() );
       }
       else
       {
           ui->CBX_ReceiveDataAnalyzeData->setChecked( true );
       }
       ui->CBX_ReceiveDataSaveRawData->setChecked( qSettingsFile.value("ReceiveDataSaveRawData").toBool() );
       if( qSettingsFile.value("processConstructorCalls").isValid() )
       {
           ui->CBX_processConstructorCalls->setChecked( qSettingsFile.value("processConstructorCalls").toBool() );
       }
       else
       {
           ui->CBX_processConstructorCalls->setChecked( true );
       }
       if( qSettingsFile.value("processDestructorCalls").isValid() )
       {
           ui->CBX_processDestructorCalls->setChecked( qSettingsFile.value("processDestructorCalls").toBool() );
       }
       else
       {
           ui->CBX_processDestructorCalls->setChecked( true );
       }
      qSettingsFile.endGroup();
    
     qSettingsFile.endGroup();
    
    qSettingsFile.endGroup();
    //#]
}

void ConfigurationWindow::openAutoStartConfigurationDialog()
{
    //#[ operation openAutoStartConfigurationDialog()
    itsPlugInLoader->openAutoStartConfigurationDialog( ui->SEL_PluginForStartUp->currentText() );
    //#]
}

void ConfigurationWindow::openFilePathForSaveRawData()
{
    //#[ operation openFilePathForSaveRawData()
    QString filePath = QFileDialog::getSaveFileName(this, "Save complete active command list to file");
    if( filePath != "" )
    {
        ui->TXT_ReceiveDataSaveRawDataFile->setText( filePath );
    }
    //#]
}

void ConfigurationWindow::openTCAutoStartConfigurationDialog()
{
    //#[ operation openTCAutoStartConfigurationDialog()
    itsPlugInLoaderTC->openAutoStartConfigurationDialog( ui->SEL_TCPluginForStartUp->currentText() );
    //#]
}

void ConfigurationWindow::performAutoStartSettings()
{
    //#[ operation performAutoStartSettings()
    
    SequenceDiagram::setShowStateDelta( ui->CBX_SD_StateDelta->isChecked() );
    TimingDiagram::setShowStateDelta( ui->CBX_TD_StateDelta->isChecked() );
    SequenceDiagram::setHideNonState( ui->CBX_SD_HideOmNoneState->isChecked() );
    TimingDiagram::setHideNonState( ui->CBX_TD_HideOmNoneState->isChecked() );
    if( ui->CBX_LoadXMLForStartUp->isChecked() )
    {
        itsXMLReader->openAndParseXMLFile(ui->TXT_XMLPathForStartUp->text());
    }
    
    
    if( ui->CBX_TCPluginForStartUp->isChecked() )
    {
        itsPlugInLoaderTC->loadPluginOnAutoStart( ui->SEL_TCPluginForStartUp->currentText() );
    }
    
    if( ui->CBX_PluginForStartUp->isChecked() )
    {
        itsPlugInLoader->loadPluginOnAutoStart( ui->SEL_PluginForStartUp->currentText() );
    }
    
    itsTestConductorParser->setIsLittleEndian( ui->RAD_LittleEndian->isChecked() );
    
    itsReceiver->setAnalyzeData( ui->CBX_ReceiveDataAnalyzeData->isChecked() );
    itsReceiver->updateRawDataFilePath( ui->TXT_ReceiveDataSaveRawDataFile->text() );
    itsReceiver->updateWriteLogData( ui->CBX_ReceiveDataSaveRawData->isChecked() );
    itsReceiver->processConstructors( ui->CBX_processConstructorCalls->isChecked() );
    itsReceiver->processDestructors( ui->CBX_processDestructorCalls->isChecked() );
    //#]
}

void ConfigurationWindow::saveSettings()
{
    //#[ operation saveSettings()
    this->hide();
    
    qSettingsFile.beginGroup("GlobalConfiguration");
    
     qSettingsFile.beginGroup("DiagramView");
      qSettingsFile.setValue("SD_StateDelta", ui->CBX_SD_StateDelta->isChecked() );
      qSettingsFile.setValue("TD_StateDelta", ui->CBX_TD_StateDelta->isChecked() );
      SequenceDiagram::setShowStateDelta( ui->CBX_SD_StateDelta->isChecked() );
      TimingDiagram::setShowStateDelta( ui->CBX_TD_StateDelta->isChecked() );
    
      qSettingsFile.setValue("SD_HideOmNoneState", ui->CBX_SD_HideOmNoneState->isChecked() );
      qSettingsFile.setValue("TD_HideOmNoneState", ui->CBX_TD_HideOmNoneState->isChecked() );
      SequenceDiagram::setHideNonState( ui->CBX_SD_HideOmNoneState->isChecked() );
      TimingDiagram::setHideNonState( ui->CBX_TD_HideOmNoneState->isChecked() );
     qSettingsFile.endGroup();
    
     qSettingsFile.beginGroup("StartUp");
    
      qSettingsFile.beginGroup("XML_File");
       qSettingsFile.setValue("loadXMLFileOnStartUp", ui->CBX_LoadXMLForStartUp->isChecked() );
       qSettingsFile.setValue("xmlFileOnStartUp", ui->TXT_XMLPathForStartUp->text() );
      qSettingsFile.endGroup();
    
      qSettingsFile.beginGroup("Plugin");
       qSettingsFile.setValue("loadPluginOnStartUp", ui->CBX_PluginForStartUp->isChecked() );
       qSettingsFile.setValue("pluginOnStartUp", ui->SEL_PluginForStartUp->currentText() );
      qSettingsFile.endGroup();
    
      qSettingsFile.beginGroup("TestConductor");
       qSettingsFile.setValue("TC_Endianess" , ui->RAD_LittleEndian->isChecked() );
       itsTestConductorParser->setIsLittleEndian( ui->RAD_LittleEndian->isChecked() );
       qSettingsFile.beginGroup("PluginTC");
        qSettingsFile.setValue("loadPluginOnStartUp", ui->CBX_TCPluginForStartUp->isChecked() );
        qSettingsFile.setValue("pluginOnStartUp", ui->SEL_TCPluginForStartUp->currentText() );
        qSettingsFile.setValue("port", QString::number(ui->SB_TCPort->value()) );
       qSettingsFile.endGroup();
      qSettingsFile.endGroup();
    
      qSettingsFile.beginGroup("RemoteControl");
       qSettingsFile.setValue("port", QString::number(ui->SB_RCPort->value()) );
      qSettingsFile.endGroup();
    
      qSettingsFile.beginGroup("Receiver");
       qSettingsFile.setValue("ReceiveDataAnalyzeData", ui->CBX_ReceiveDataAnalyzeData->isChecked() );
       itsReceiver->setAnalyzeData( ui->CBX_ReceiveDataAnalyzeData->isChecked() );
       qSettingsFile.setValue("ReceiveDataSaveRawData", ui->CBX_ReceiveDataSaveRawData->isChecked() );
       itsReceiver->updateWriteLogData( ui->CBX_ReceiveDataSaveRawData->isChecked() );
       qSettingsFile.setValue("ReceiveDataSaveRawDataFile", ui->TXT_ReceiveDataSaveRawDataFile->text() );
       itsReceiver->updateRawDataFilePath( ui->TXT_ReceiveDataSaveRawDataFile->text() );
       qSettingsFile.setValue("processConstructorCalls", ui->CBX_processConstructorCalls->isChecked() );
       itsReceiver->processConstructors( ui->CBX_processConstructorCalls->isChecked() );
       qSettingsFile.setValue("processDestructorCalls", ui->CBX_processDestructorCalls->isChecked() );
       itsReceiver->processDestructors( ui->CBX_processDestructorCalls->isChecked() );
      qSettingsFile.endGroup();
    
     qSettingsFile.endGroup();
    
    qSettingsFile.endGroup();
    //#]
}

void ConfigurationWindow::setAutoStartXMLPath()
{
    //#[ operation setAutoStartXMLPath()
    QString pathXMLfile = QFileDialog::getOpenFileName( this , "Open XML File", ui->TXT_XMLPathForStartUp->text(), "XML Files (*.xml);;XML FileList (*.lst)" );
    if(pathXMLfile!=NULL)
    {
        ui->TXT_XMLPathForStartUp->setText(pathXMLfile);
    }
    //#]
}

void ConfigurationWindow::setBigEndian()
{
    //#[ operation setBigEndian()
    //#]
}

void ConfigurationWindow::setLittleEndian()
{
    //#[ operation setLittleEndian()
    //#]
}

void ConfigurationWindow::disconnectSignals()
{
    //#[ operation disconnectSignals()
    disconnect(ui->BTN_CloseWindow, SIGNAL(released()), this, SLOT(saveSettings()) );
    disconnect(this, SIGNAL(rejected()),this, SLOT(loadSettings()) );
    disconnect( ui->BTN_BrowseXMLFileForAutoStart, SIGNAL(released()), this, SLOT(setAutoStartXMLPath()) );
    disconnect( ui->BTN_ConfigurePluginForAutoStart, SIGNAL(released()), this, SLOT(openAutoStartConfigurationDialog()) );
    disconnect( ui->BTN_TCConfigurePluginForAutoStart, SIGNAL(released()), this, SLOT(openTCAutoStartConfigurationDialog()) );
    disconnect( ui->BTN_ReceiveDataBrowseRawDataFile, SIGNAL(released()), this, SLOT(openFilePathForSaveRawData()) );
    //#]
}

void ConfigurationWindow::cleanUpRelations()
{
    if(itsPlugInLoader != NULL)
        {
            itsPlugInLoader = NULL;
        }
    if(itsPlugInLoaderTC != NULL)
        {
            itsPlugInLoaderTC = NULL;
        }
    if(itsReceiver != NULL)
        {
            itsReceiver = NULL;
        }
    if(itsTestConductorParser != NULL)
        {
            itsTestConductorParser = NULL;
        }
    if(itsXMLReader != NULL)
        {
            itsXMLReader = NULL;
        }
}

/*********************************************************************
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\ConfigurationWindow.cpp
*********************************************************************/
