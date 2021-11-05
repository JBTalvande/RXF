/*********************************************************************
	Rhapsody	: 9.0.1 
	Login		: Y9DSYU706
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: MainWindow
//!	Generated Date	: Thu, 4, Nov 2021  
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\MainWindow.h
*********************************************************************/

#ifndef MainWindow_H
#define MainWindow_H

#include "ModelInstance.h"
#include <QMainWindow>
#include "ui_mainwindow.h"
#include <QSettings>
#include <QStandardItemModel>
#include <QStandardItem>
class CommandList;

class DataView;

class DataViewFilterGeneration;

class ModelClass;

class ModelClassAttribute;

class ModelClassState;

class ModelDataType;

class ModelEventType;

class QFileDialog;

class QMessageBox;

class SequenceDiagram;

class TargetInformation;

class TimingDiagram;

//## package GUI

//## class MainWindow

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT
public :

    enum AttributeDisplayTypes {
        SignedInt,
        UnsignedInt,
        HexaDecimal,
        Dual
    };
    
    ////    Constructors and destructors    ////
    
    //## operation MainWindow(QWidget)
    explicit MainWindow(QWidget * parent = 0);
    
    //## operation ~MainWindow()
    ~MainWindow();
    
    ////    Operations    ////
    
    //## operation addFilterView()
    Q_SLOT void addFilterView();
    
    //## operation addInstance(ModelInstance,TargetInformation)
    void addInstance(const ModelInstance& newInstance, const TargetInformation& target);
    
    //## operation addRecentXMLPath(QString)
    void addRecentXMLPath(const QString& XMLPath);
    
    //## operation attributeValueToBin()
    Q_SLOT void attributeValueToBin();
    
    //## operation attributeValueToDec()
    Q_SLOT void attributeValueToDec();
    
    //## operation attributeValueToHex()
    Q_SLOT void attributeValueToHex();
    
    //## operation attributeValueToUnsignedDec()
    Q_SLOT void attributeValueToUnsignedDec();
    
    //## operation clearConsole()
    Q_SLOT void clearConsole();
    
    //## operation clearErrorConsole()
    Q_SLOT void clearErrorConsole();
    
    //## operation clearTargetConsole()
    Q_SLOT void clearTargetConsole();
    
    //## operation connectSignals()
    void connectSignals();
    
    //## operation consoleMsg(QString)
    void consoleMsg(const QString& msg);
    
    //## operation createConsoleContextMenues()
    void createConsoleContextMenues();
    
    //## operation deleteFilterView()
    Q_SLOT void deleteFilterView();
    
    //## operation disconnectSignals()
    void disconnectSignals();
    
    //## operation editFilterView()
    Q_SLOT void editFilterView();
    
    //## operation errorMsg(QString)
    void errorMsg(const QString& msg);
    
    //## operation exportSD()
    Q_SLOT void exportSD();
    
    //## operation exportSDtoRPY(CommandList)
    Q_SIGNAL void exportSDtoRPY(const CommandList& commandList);
    
    //## operation loadCommandList(QStandardItem)
    void loadCommandList(QStandardItem* newItem);
    
    //## operation loadConfiguration()
    void loadConfiguration();
    
    //## operation loadFilterView()
    Q_SLOT void loadFilterView();
    
    //## operation loadView()
    Q_SLOT void loadView();
    
    //## operation loadView(QString)
    Q_SIGNAL void loadView(const QString& filePath);
    
    //## operation newCommandList(QStandardItem)
    void newCommandList(QStandardItem* newItem);
    
    //## operation openAboutDialog()
    Q_SLOT void openAboutDialog();
    
    //## operation openNewViewWindow()
    Q_SLOT void openNewViewWindow();
    
    //## operation removeTarget(TargetInformation)
    void removeTarget(TargetInformation& target);
    
    //## operation saveActiveCommandList(QString)
    Q_SIGNAL void saveActiveCommandList(const QString& filePath);
    
    //## operation saveAllCommandsToFile()
    Q_SLOT void saveAllCommandsToFile();
    
    //## operation saveCommandList(CommandList)
    void saveCommandList(const CommandList& commandList);
    
    //## operation saveCommandList(QString,CommandList)
    Q_SIGNAL void saveCommandList(const QString& filePath, const CommandList& commandList);
    
    //## operation saveFilterView()
    Q_SLOT void saveFilterView();
    
    //## operation saveRecentXMLFilesToConfigFile()
    void saveRecentXMLFilesToConfigFile();
    
    //## operation saveSelectedCommandList()
    Q_SLOT void saveSelectedCommandList();
    
    //## operation saveView()
    Q_SLOT void saveView();
    
    //## operation saveView(QString,CommandList)
    Q_SIGNAL void saveView(const QString& filePath, CommandList* commandList);
    
    //## operation setCurrentAttributeWaitingForValueFromParser(QString)
    void setCurrentAttributeWaitingForValueFromParser(const QString& value);
    
    //## operation showConsoleContextMenue(QPoint)
    Q_SLOT void showConsoleContextMenue(QPoint point);
    
    //## operation showErrorConsoleContextMenue(QPoint)
    Q_SLOT void showErrorConsoleContextMenue(QPoint point);
    
    //## operation showTargetConsoleContextMenue(QPoint)
    Q_SLOT void showTargetConsoleContextMenue(QPoint point);
    
    //## operation showTreeContextMenue(QPoint)
    Q_SLOT void showTreeContextMenue(QPoint point);
    
    //## operation showViewsContextMenue(QPoint)
    Q_SLOT void showViewsContextMenue(QPoint point);
    
    //## operation targetConsoleMsg(QString)
    void targetConsoleMsg(const QString& msg);
    
    //## operation viewsTreeItemCountChanged()
    Q_SLOT void viewsTreeItemCountChanged();

private :

    //## operation addNewInstanceToDebugIntTree(ModelInstance)
    void addNewInstanceToDebugIntTree(const ModelInstance& newInstance);
    
    //## operation addNewInstanceToInstanceList(ModelInstance)
    void addNewInstanceToInstanceList(const ModelInstance& newInstance);
    
    //## operation addNewInstanceToTargetFilterTree(ModelInstance,TargetInformation)
    void addNewInstanceToTargetFilterTree(const ModelInstance& newInstance, const TargetInformation& target);
    
    //## operation addNewInstanceToTargetTree(ModelInstance,TargetInformation)
    void addNewInstanceToTargetTree(const ModelInstance& newInstance, const TargetInformation& target);
    
    //## operation attributeToBin(QStandardItem)
    void attributeToBin(QStandardItem* item);
    
    //## operation attributeToHex(QStandardItem)
    void attributeToHex(QStandardItem* item);
    
    //## operation attributeToSInt(QStandardItem)
    void attributeToSInt(QStandardItem* item);
    
    //## operation attributeToUInt(QStandardItem)
    void attributeToUInt(QStandardItem* item);
    
    //## operation convertCurrentAttributeValuetoInt(QString,bool)
    uint64_t convertCurrentAttributeValuetoInt(const QString& text, bool& ok);
    
    //## operation initFilterViewContextMenue()
    void initFilterViewContextMenue();
    
    //## operation initTreeViewContextMenue()
    void initTreeViewContextMenue();
    
    //## operation loadRecentXMLFiles()
    void loadRecentXMLFiles();
    
    //## operation loadWindowPosition()
    void loadWindowPosition();
    
    ////    Additional operations    ////

public :

    inline QStandardItem* getCurrentAttributeWaitingForValue() const
    {
        return currentAttributeWaitingForValue;
    }
    
    inline void setCurrentAttributeWaitingForValue(QStandardItem* p_currentAttributeWaitingForValue)
    {
        currentAttributeWaitingForValue = p_currentAttributeWaitingForValue;
    }
    
    inline QStandardItem* getCurrentInstanceItemWaitingForState() const
    {
        return currentInstanceItemWaitingForState;
    }
    
    inline void setCurrentInstanceItemWaitingForState(QStandardItem* p_currentInstanceItemWaitingForState)
    {
        currentInstanceItemWaitingForState = p_currentInstanceItemWaitingForState;
    }
    
    inline ModelInstance* getCurrentModelInstanceWaitingForState() const
    {
        return currentModelInstanceWaitingForState;
    }
    
    inline void setCurrentModelInstanceWaitingForState(ModelInstance* p_currentModelInstanceWaitingForState)
    {
        currentModelInstanceWaitingForState = p_currentModelInstanceWaitingForState;
    }
    
    inline QString getLastFilterDirectory() const
    {
        return lastFilterDirectory;
    }
    
    inline void setLastFilterDirectory(QString p_lastFilterDirectory)
    {
        lastFilterDirectory = p_lastFilterDirectory;
    }
    
    inline int getMaxRecentFiles() const
    {
        return maxRecentFiles;
    }
    
    inline void setMaxRecentFiles(int p_maxRecentFiles)
    {
        maxRecentFiles = p_maxRecentFiles;
    }
    
    inline Ui::MainWindow* getUi() const
    {
        return ui;
    }
    
    inline void setUi(Ui::MainWindow* p_ui)
    {
        ui = p_ui;
    }
    
    inline QString getVersionDebugger() const
    {
        return versionDebugger;
    }
    
    inline void setVersionDebugger(QString p_versionDebugger)
    {
        versionDebugger = p_versionDebugger;
    }
    
    inline QStandardItem* getItsAttributeChangeBaseItem() const
    {
        return itsAttributeChangeBaseItem;
    }
    
    inline void setItsAttributeChangeBaseItem(QStandardItem* p_QStandardItem)
    {
        itsAttributeChangeBaseItem = p_QStandardItem;
    }
    
    inline DataViewFilterGeneration* getItsDataViewFilterGeneration() const
    {
        return itsDataViewFilterGeneration;
    }
    
    inline void setItsDataViewFilterGeneration(DataViewFilterGeneration* p_DataViewFilterGeneration)
    {
        itsDataViewFilterGeneration = p_DataViewFilterGeneration;
    }
    
    inline QStandardItem* getItsDebugIntListItem() const
    {
        return itsDebugIntListItem;
    }
    
    inline void setItsDebugIntListItem(QStandardItem* p_QStandardItem)
    {
        itsDebugIntListItem = p_QStandardItem;
    }
    
    inline QStandardItemModel* getItsDebugIntTreeItemModel() const
    {
        return (QStandardItemModel*) &itsDebugIntTreeItemModel;
    }
    
    inline QStandardItemModel* getItsFilterTreeItemModel() const
    {
        return (QStandardItemModel*) &itsFilterTreeItemModel;
    }
    
    inline QStandardItemModel* getItsModelTreeItemModel() const
    {
        return (QStandardItemModel*) &itsModelTreeItemModel;
    }
    
    inline CommandList* getItsSelectedCommandList() const
    {
        return itsSelectedCommandList;
    }
    
    inline void setItsSelectedCommandList(CommandList* p_CommandList)
    {
        itsSelectedCommandList = p_CommandList;
    }
    
    inline SequenceDiagram* getItsSequenceDiagram() const
    {
        return itsSequenceDiagram;
    }
    
    inline void setItsSequenceDiagram(SequenceDiagram* p_SequenceDiagram)
    {
        itsSequenceDiagram = p_SequenceDiagram;
    }
    
    inline QStandardItem* getItsTargetFilterListItem() const
    {
        return itsTargetFilterListItem;
    }
    
    inline void setItsTargetFilterListItem(QStandardItem* p_QStandardItem)
    {
        itsTargetFilterListItem = p_QStandardItem;
    }
    
    inline QStandardItem* getItsTargetListItem() const
    {
        return itsTargetListItem;
    }
    
    inline void setItsTargetListItem(QStandardItem* p_QStandardItem)
    {
        itsTargetListItem = p_QStandardItem;
    }
    
    inline TimingDiagram* getItsTimingDiagram() const
    {
        return itsTimingDiagram;
    }
    
    inline void setItsTimingDiagram(TimingDiagram* p_TimingDiagram)
    {
        itsTimingDiagram = p_TimingDiagram;
    }
    
    inline QStandardItem* getItsViewsFilterView() const
    {
        return itsViewsFilterView;
    }
    
    inline void setItsViewsFilterView(QStandardItem* p_QStandardItem)
    {
        itsViewsFilterView = p_QStandardItem;
    }
    
    inline QStandardItemModel* getItsViewsTreeItemModel() const
    {
        return (QStandardItemModel*) &itsViewsTreeItemModel;
    }

protected :

    void cleanUpRelations();
    
    ////    Attributes    ////

private :

    const int ATTRIBUTE_VALUE_DATA;		//## attribute ATTRIBUTE_VALUE_DATA
    
    QMenu* consoleContextMenue;		//## attribute consoleContextMenue
    
    QStandardItem* currentAttributeWaitingForValue;		//## attribute currentAttributeWaitingForValue
    
    QStandardItem* currentInstanceItemWaitingForState;		//## attribute currentInstanceItemWaitingForState
    
    ModelInstance* currentModelInstanceWaitingForState;		//## attribute currentModelInstanceWaitingForState
    
    QMenu* errorConsoleContextMenue;		//## attribute errorConsoleContextMenue
    
    QString lastFilterDirectory;		//## attribute lastFilterDirectory
    
    int maxRecentFiles;		//## attribute maxRecentFiles
    
    QSettings qSettingsFile;		//## attribute qSettingsFile
    
    QMenu* targetConsoleContextMenue;		//## attribute targetConsoleContextMenue
    
    QMenu* targetTreeContextMenue;		//## attribute targetTreeContextMenue
    
    Ui::MainWindow* ui;		//## attribute ui
    
    QString versionDebugger;		//## attribute versionDebugger
    
    QMenu* viewsContextMenue;		//## attribute viewsContextMenue
    
    ////    Relations and components    ////

protected :

    QStandardItem* itsAttributeChangeBaseItem;
    
    DataViewFilterGeneration* itsDataViewFilterGeneration;
    
    QStandardItem* itsDebugIntListItem;
    
    QStandardItemModel itsDebugIntTreeItemModel;
    
    QStandardItemModel itsFilterTreeItemModel;
    
    QStandardItemModel itsModelTreeItemModel;
    
    CommandList* itsSelectedCommandList;
    
    SequenceDiagram* itsSequenceDiagram;
    
    QStandardItem* itsTargetFilterListItem;
    
    QStandardItem* itsTargetListItem;
    
    TimingDiagram* itsTimingDiagram;
    
    QStandardItem* itsViewsFilterView;
    
    QStandardItemModel itsViewsTreeItemModel;
};

#endif
/*********************************************************************
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\MainWindow.h
*********************************************************************/
