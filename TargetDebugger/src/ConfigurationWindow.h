/*********************************************************************
	Rhapsody	: 9.0.1 
	Login		: Y9DSYU706
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: ConfigurationWindow
//!	Generated Date	: Thu, 4, Nov 2021  
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\ConfigurationWindow.h
*********************************************************************/

#ifndef ConfigurationWindow_H
#define ConfigurationWindow_H

#include <QDialog>
#include "ui_configurationwindow.h"
#include <QSettings>
class PlugInLoader;

class PlugInLoaderTC;

class Receiver;

class SequenceDiagram;

class TestConductorParser;

class TimingDiagram;

class XMLReader;

//## package GUI

//## class ConfigurationWindow

namespace Ui {
class ConfigurationWindow;
}

class ConfigurationWindow : public QDialog {
	Q_OBJECT
    ////    Constructors and destructors    ////
    
public :

    //## operation ConfigurationWindow()
    ConfigurationWindow();
    
    //## operation ~ConfigurationWindow()
    ~ConfigurationWindow();
    
    ////    Operations    ////
    
    //## operation connectSignals()
    void connectSignals();
    
    //## operation getRemoteControlPort()
    int getRemoteControlPort();
    
    //## operation getTestConductorPort()
    int getTestConductorPort();
    
    //## operation loadSettings()
    Q_SLOT void loadSettings();
    
    //## operation openAutoStartConfigurationDialog()
    Q_SLOT void openAutoStartConfigurationDialog();
    
    //## operation openFilePathForSaveRawData()
    Q_SLOT void openFilePathForSaveRawData();
    
    //## operation openTCAutoStartConfigurationDialog()
    Q_SLOT void openTCAutoStartConfigurationDialog();
    
    //## operation performAutoStartSettings()
    void performAutoStartSettings();
    
    //## operation saveSettings()
    Q_SLOT void saveSettings();
    
    //## operation setAutoStartXMLPath()
    Q_SLOT void setAutoStartXMLPath();
    
    //## operation setBigEndian()
    Q_SLOT void setBigEndian();
    
    //## operation setLittleEndian()
    Q_SLOT void setLittleEndian();

private :

    //## operation disconnectSignals()
    void disconnectSignals();
    
    ////    Additional operations    ////

public :

    inline Ui::ConfigurationWindow* getUi() const
    {
        return ui;
    }
    
    inline void setUi(Ui::ConfigurationWindow* p_ui)
    {
        ui = p_ui;
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
    
    inline Receiver* getItsReceiver() const
    {
        return itsReceiver;
    }
    
    inline void setItsReceiver(Receiver* p_Receiver)
    {
        itsReceiver = p_Receiver;
    }
    
    inline TestConductorParser* getItsTestConductorParser() const
    {
        return itsTestConductorParser;
    }
    
    inline void setItsTestConductorParser(TestConductorParser* p_TestConductorParser)
    {
        itsTestConductorParser = p_TestConductorParser;
    }
    
    inline XMLReader* getItsXMLReader() const
    {
        return itsXMLReader;
    }
    
    inline void setItsXMLReader(XMLReader* p_XMLReader)
    {
        itsXMLReader = p_XMLReader;
    }

protected :

    void cleanUpRelations();
    
    ////    Attributes    ////

private :

    QSettings qSettingsFile;		//## attribute qSettingsFile
    
    Ui::ConfigurationWindow* ui;		//## attribute ui
    
    ////    Relations and components    ////

protected :

    PlugInLoader* itsPlugInLoader;
    
    PlugInLoaderTC* itsPlugInLoaderTC;
    
    Receiver* itsReceiver;
    
    TestConductorParser* itsTestConductorParser;
    
    XMLReader* itsXMLReader;
};

#endif
/*********************************************************************
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\ConfigurationWindow.h
*********************************************************************/
