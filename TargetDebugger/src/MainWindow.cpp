/********************************************************************
	Rhapsody	: 9.0.1 
	Login		: Y9DSYU706
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: MainWindow
//!	Generated Date	: Thu, 4, Nov 2021  
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\MainWindow.cpp
*********************************************************************/

#include "MainWindow.h"
#include "CommandList.h"
#include "DataView.h"
#include "DataViewFilterGeneration.h"
#include "ModelClass.h"
#include "ModelClassAttribute.h"
#include "ModelClassState.h"
#include "ModelDataType.h"
#include "ModelEventType.h"
#include <QFileDialog.h>
#include <QMessageBox.h>
#include "SequenceDiagram.h"
#include "TargetInformation.h"
#include "TimingDiagram.h"
#include <QDateTime>
#include "Revision.h"
//## package GUI

//## class MainWindow
MainWindow::MainWindow(QWidget * parent) : QMainWindow(parent)
 , ATTRIBUTE_VALUE_DATA(1), currentAttributeWaitingForValue(NULL), currentInstanceItemWaitingForState(NULL), currentModelInstanceWaitingForState(NULL), lastFilterDirectory(""), maxRecentFiles(10), qSettingsFile("Configuration.ini", QSettings::IniFormat), ui(new Ui::MainWindow), versionDebugger("4.0.0")
{
    itsAttributeChangeBaseItem = NULL;
    itsDataViewFilterGeneration = NULL;
    itsDebugIntListItem = NULL;
    itsSelectedCommandList = NULL;
    itsSequenceDiagram = NULL;
    itsTargetFilterListItem = NULL;
    itsTargetListItem = NULL;
    itsTimingDiagram = NULL;
    itsViewsFilterView = NULL;
    //#[ operation MainWindow(QWidget)
    ui->setupUi(this); 
    
    this->show();
    
    itsTargetFilterListItem = new QStandardItem(  QIcon( ":/icons/classTreeView/img/icons/classTreeView/ModelIcon_Target.png" ), "Targets" );
    itsTargetListItem = new QStandardItem( QIcon( ":/icons/classTreeView/img/icons/classTreeView/ModelIcon_Target.png" ), "Targets" );
    itsDebugIntListItem = new QStandardItem( QIcon( ":/icons/classTreeView/img/icons/classTreeView/ModelIcon_Target.png" ), "Targets" );
    itsDebugIntTreeItemModel.appendRow( itsDebugIntListItem );
    ui->printIntTreeView->setModel(&itsDebugIntTreeItemModel);
    
    itsModelTreeItemModel.appendRow( itsTargetListItem );
    ui->targetTreeView->setModel(&itsModelTreeItemModel);
    
    ui->viewsTreeView->setModel(&itsViewsTreeItemModel);
    
    createConsoleContextMenues();
    this->initFilterViewContextMenue();
    this->initTreeViewContextMenue();
    this->connectSignals();
    //#]
}

MainWindow::~MainWindow()
{
    //#[ operation ~MainWindow()
    qSettingsFile.beginGroup("Gui");
    qSettingsFile.setValue("windowWidth",QString::number( normalGeometry().width()) );
    qSettingsFile.setValue("windowHeight",QString::number( normalGeometry().height()) );
    qSettingsFile.setValue("windowXPos",QString::number( normalGeometry().left()) );
    qSettingsFile.setValue("windowYPos",QString::number( normalGeometry().top()) );
    if( isMaximized() )
    {
        qSettingsFile.setValue("windowFullScrean","true");
    }
    else
    {
        qSettingsFile.setValue("windowFullScrean","false");
    }
    qSettingsFile.endGroup();
    disconnectSignals();
    //#]
    cleanUpRelations();
}

void MainWindow::addFilterView()
{
    //#[ operation addFilterView()
    CommandList* myCommandList = (CommandList*)itsViewsTreeItemModel.itemFromIndex( ui->viewsTreeView->currentIndex() );
    itsDataViewFilterGeneration->showWindow( myCommandList );
    //#]
}

void MainWindow::addInstance(const ModelInstance& newInstance, const TargetInformation& target)
{
    //#[ operation addInstance(ModelInstance,TargetInformation)
    addNewInstanceToTargetTree( newInstance, target );
    addNewInstanceToInstanceList( newInstance );
    addNewInstanceToDebugIntTree( newInstance );
    addNewInstanceToTargetFilterTree( newInstance, target );
    //#]
}

void MainWindow::addRecentXMLPath(const QString& XMLPath)
{
    //#[ operation addRecentXMLPath(QString)
    for(int i = 0; i < ui->menuRecent_opend_files->actions().length(); i++ )
    {   
    	//If XML Path already one of the recent files move it to top of list
        if( ui->menuRecent_opend_files->actions().at(i)->text() == XMLPath )
        {
            QList<QAction*> myActionList = ui->menuRecent_opend_files->actions();
            myActionList.move(i,0);
            ui->menuRecent_opend_files->addActions(myActionList);
            saveRecentXMLFilesToConfigFile();
            return;
        }
    }  
    
    //New Entry in Recent File menue
    ui->menuRecent_opend_files->addAction(XMLPath);
    QList<QAction*> myActionList = ui->menuRecent_opend_files->actions();
    myActionList.move(ui->menuRecent_opend_files->actions().length()-1,0);
    ui->menuRecent_opend_files->addActions(myActionList);
    if( ui->menuRecent_opend_files->actions().length() > getMaxRecentFiles() )
    {
        ui->menuRecent_opend_files->removeAction( ui->menuRecent_opend_files->actions().at(ui->menuRecent_opend_files->actions().length()-1) );
    }
    saveRecentXMLFilesToConfigFile();
    //#]
}

void MainWindow::attributeValueToBin()
{
    //#[ operation attributeValueToBin()
    if( itsAttributeChangeBaseItem != NULL )
    {
        itsAttributeChangeBaseItem->setData((uint)Dual,Qt::UserRole + 2);
        attributeToBin( itsAttributeChangeBaseItem );
    }
    itsAttributeChangeBaseItem = NULL;
    //#]
}

void MainWindow::attributeValueToDec()
{
    //#[ operation attributeValueToDec()
    if( itsAttributeChangeBaseItem != NULL )
    {
        itsAttributeChangeBaseItem->setData((uint)SignedInt,Qt::UserRole + 2);
        attributeToSInt( itsAttributeChangeBaseItem );
    }
    itsAttributeChangeBaseItem = NULL;
    //#]
}

void MainWindow::attributeValueToHex()
{
    //#[ operation attributeValueToHex()
    if( itsAttributeChangeBaseItem != NULL )
    {
        itsAttributeChangeBaseItem->setData((uint)HexaDecimal,Qt::UserRole + 2);
        attributeToHex( itsAttributeChangeBaseItem );
    }
    itsAttributeChangeBaseItem = NULL;
    //#]
}

void MainWindow::attributeValueToUnsignedDec()
{
    //#[ operation attributeValueToUnsignedDec()
    if( itsAttributeChangeBaseItem != NULL )
    {
    
        itsAttributeChangeBaseItem->setData((uint)UnsignedInt,Qt::UserRole + 2);
        attributeToUInt( itsAttributeChangeBaseItem );
    }
    itsAttributeChangeBaseItem = NULL;
    //#]
}

void MainWindow::clearConsole()
{
    //#[ operation clearConsole()
    ui->consoleTextArea->setText("");
    //#]
}

void MainWindow::clearErrorConsole()
{
    //#[ operation clearErrorConsole()
    ui->errorTextArea->setText("");
    //#]
}

void MainWindow::clearTargetConsole()
{
    //#[ operation clearTargetConsole()
    ui->TXT_TargetConsole->setText("");
    //#]
}

void MainWindow::connectSignals()
{
    //#[ operation connectSignals()
    // Menu Button Save Commands to File
    QObject::connect( this->ui->actionSaveCommandsFile, SIGNAL(triggered(bool)), this, SLOT( saveAllCommandsToFile () ) );
    
    // Save / Load log data
    QObject::connect( this->ui->actionSaveDataLOGFile, SIGNAL(triggered(bool)), this, SLOT( saveView() ));
    QObject::connect( this->ui->actionLoadDataLOGFile, SIGNAL(triggered(bool)), this, SLOT( loadView() ));
    
    // register signals for inserted and removed rows on viewsTreeItemModel to update ui according existing content
    QObject::connect( &this->itsViewsTreeItemModel, SIGNAL(rowsInserted(const QModelIndex &, int, int)), this, SLOT(viewsTreeItemCountChanged()) );
    QObject::connect( &this->itsViewsTreeItemModel, SIGNAL(rowsRemoved(QModelIndex,int,int)), this, SLOT(viewsTreeItemCountChanged()) );
    
    QObject::connect( ui->actionToRhapsody, SIGNAL(triggered(bool)), this, SLOT(exportSD()) );
    
    // context menues for consoles
    QObject::connect( ui->consoleTextArea, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT( showConsoleContextMenue(QPoint) ) );
    QObject::connect( ui->errorTextArea, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT( showErrorConsoleContextMenue(QPoint) ) );
    QObject::connect( ui->TXT_TargetConsole, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT( showTargetConsoleContextMenue(QPoint) ) );
    
    //context menu for help -> About
    QObject::connect( ui->actionAbout, SIGNAL( triggered() ), this, SLOT( openAboutDialog() ) );
    //#]
}

void MainWindow::consoleMsg(const QString& msg)
{
    //#[ operation consoleMsg(QString)
    ui->consoleTextArea->append(msg);
    //#]
}

void MainWindow::createConsoleContextMenues()
{
    //#[ operation createConsoleContextMenues()
    //TargetConsole
    ui->TXT_TargetConsole->setContextMenuPolicy(Qt::CustomContextMenu);
    targetConsoleContextMenue = new QMenu(ui->TXT_TargetConsole);
    QAction *clearAction = new QAction("clear");
    connect(clearAction,SIGNAL(triggered(bool)),this,SLOT(clearTargetConsole()) );
    targetConsoleContextMenue->addAction( clearAction );
    
    //Console
    ui->consoleTextArea->setContextMenuPolicy(Qt::CustomContextMenu);
    consoleContextMenue = new QMenu(ui->consoleTextArea);
    clearAction = new QAction("clear");
    connect(clearAction,SIGNAL(triggered(bool)),this,SLOT(clearConsole()) );
    consoleContextMenue->addAction( clearAction );
    
    //ErrorConsole
    ui->errorTextArea->setContextMenuPolicy(Qt::CustomContextMenu);
    errorConsoleContextMenue = new QMenu(ui->errorTextArea);
    clearAction = new QAction("clear");
    connect(clearAction,SIGNAL(triggered(bool)),this,SLOT(clearErrorConsole()) );
    errorConsoleContextMenue->addAction( clearAction );
    //#]
}

void MainWindow::deleteFilterView()
{
    //#[ operation deleteFilterView()
    //#]
}

void MainWindow::disconnectSignals()
{
    //#[ operation disconnectSignals()
    // Menu Button Save Commands to File
    QObject::disconnect( this->ui->actionSaveCommandsFile, SIGNAL(triggered(bool)), this, SLOT( saveAllCommandsToFile () ) );
    
    // Save / Load log data
    QObject::disconnect( this->ui->actionSaveDataLOGFile, SIGNAL(triggered(bool)), this, SLOT( saveView() ));
    QObject::disconnect( this->ui->actionLoadDataLOGFile, SIGNAL(triggered(bool)), this, SLOT( loadView() ));
    
    // register signals for inserted and removed rows on viewsTreeItemModel to update ui according existing content
    QObject::disconnect( &this->itsViewsTreeItemModel, SIGNAL(rowsInserted(const QModelIndex &, int, int)), this, SLOT(viewsTreeItemCountChanged()) );
    QObject::disconnect( &this->itsViewsTreeItemModel, SIGNAL(rowsRemoved(QModelIndex,int,int)), this, SLOT(viewsTreeItemCountChanged()) );
    
    QObject::disconnect( ui->actionToRhapsody, SIGNAL(triggered(bool)), this, SLOT(exportSD()) );
    
    //#]
}

void MainWindow::editFilterView()
{
    //#[ operation editFilterView()
    CommandList* myCommandList = (CommandList*)itsViewsTreeItemModel.itemFromIndex( ui->viewsTreeView->currentIndex() );
    if( myCommandList->parent() != NULL )
    {
        itsDataViewFilterGeneration->editFilter( myCommandList );
    }
    else
    {
        consoleMsg("Root list don't have Filter");
    }
    //#]
}

void MainWindow::errorMsg(const QString& msg)
{
    //#[ operation errorMsg(QString)
    ui->errorTextArea->append( msg );
    //#]
}

void MainWindow::exportSD()
{
    //#[ operation exportSD()
    QModelIndex myIndex = ui->viewsTreeView->currentIndex();
    if( myIndex.isValid() )
    {
        CommandList *myList = (CommandList*)itsViewsTreeItemModel.itemFromIndex( myIndex );
        emit exportSDtoRPY(*myList);
    }
    //#]
}

void MainWindow::loadCommandList(QStandardItem* newItem)
{
    //#[ operation loadCommandList(QStandardItem)
    this->itsViewsTreeItemModel.appendRow( newItem );
    //#]
}

void MainWindow::loadConfiguration()
{
    //#[ operation loadConfiguration()
    qSettingsFile.beginGroup("Gui");    
    
    loadWindowPosition();
    loadRecentXMLFiles();
    
    qSettingsFile.endGroup();
    
    show();
    //#]
}

void MainWindow::loadFilterView()
{
    //#[ operation loadFilterView()
    CommandList* myCommandList = (CommandList*)itsViewsTreeItemModel.itemFromIndex( ui->viewsTreeView->currentIndex() );
    QString pathLoadFile = QFileDialog::getOpenFileName(NULL,tr("Load Filter"), lastFilterDirectory, tr("Filter File (*.fif)" ) );
    if( pathLoadFile != NULL )
    {
        QSettings testSetting(pathLoadFile, QSettings::IniFormat);
        myCommandList->loadFilterSettings( testSetting, true );
        itsSequenceDiagram->updateInstanceLines();
    }
    
    
    //#]
}

void MainWindow::loadView()
{
    //#[ operation loadView()
    QString filePath = QFileDialog::getOpenFileName(this, "Load View", QString(), "Target Debugger files (*.tdx)");
    if( filePath != NULL )
    {
        emit this->loadView(filePath);
    }
    //#]
}

void MainWindow::newCommandList(QStandardItem* newItem)
{
    //#[ operation newCommandList(QStandardItem)
    newItem->setText(QDateTime::currentDateTime().toString());
    this->itsViewsTreeItemModel.appendRow( newItem );
    //#]
}

void MainWindow::openAboutDialog()
{
    //#[ operation openAboutDialog()
    QString info = "<b>Embedded UML Target Debugger"
               "</b> <br /> <br />"
           "Build "REVISION"<br />"
           "Copyright 2021 - Willert Software Tools GmbH. <br />All rights reserved.<br /><br />"
           "Contact: support@sodiuswillert.com";
    QMessageBox::about(this, tr("About Embedded UML Target Debugger"), info);
    //#]
}

void MainWindow::openNewViewWindow()
{
    //#[ operation openNewViewWindow()
    new DataView( (CommandList*)itsViewsTreeItemModel.itemFromIndex( ui->viewsTreeView->currentIndex() ) );
    //#]
}

void MainWindow::removeTarget(TargetInformation& target)
{
    //#[ operation removeTarget(TargetInformation)
    target.setItsTreeViewItemTarget( NULL );
    target.setItsTreeViewItemDebugInt( NULL );
    target.setItsTreeViewItemTargetFilter( NULL );
    for( auto aModelClass : target.getModelClassList() )
    {
        aModelClass->setItsTreeViewItemDebugInt( NULL );
        aModelClass->setItsTreeViewItemTarget( NULL );
        aModelClass->setItsTreeViewItemTargetFilter( NULL );
    }
    for( int i = 0; i < itsTargetListItem->rowCount(); )
    {
        if( itsTargetListItem->child( i )->data(Qt::UserRole).toInt() == target.getId() )
        {
            itsTargetListItem->removeRow( i );
        }
        else
        {
            i++;
        }
    }   
    
    for( int i = 0; i < itsDebugIntListItem->rowCount(); )
    {
        if( itsDebugIntListItem->child( i )->data(Qt::UserRole).toInt() == target.getId() )
        {
            itsDebugIntListItem->removeRow( i );
        }
        else
        {
            i++;
        }
    }
    
    for( int i = 0; i < itsTargetFilterListItem->rowCount(); )
    {
        if( itsTargetFilterListItem->child( i )->data(Qt::UserRole).toInt() == target.getId() )
        {
            itsTargetFilterListItem->removeRow( i );
        }
        else
        {
            i++;
        }
    }
    for( int i = 0; i < ui->instanceList->rowCount(); )
    {
        if( ui->instanceList->item(i,0)->data(Qt::UserRole).toInt() == target.getId() )
        {
            ui->instanceList->removeRow(i);
        }
        else
        {
            i++;
        }
    }
    //#]
}

void MainWindow::saveAllCommandsToFile()
{
    //#[ operation saveAllCommandsToFile()
    QString filePath = QFileDialog::getSaveFileName(this, "Save complete active command list to file");
    emit saveActiveCommandList(filePath);
    //#]
}

void MainWindow::saveCommandList(const CommandList& commandList)
{
    //#[ operation saveCommandList(CommandList)
    QString filePath = QFileDialog::getSaveFileName(this, "Save selected commands to file");
    emit saveCommandList(filePath, commandList);
    //#]
}

void MainWindow::saveFilterView()
{
    //#[ operation saveFilterView()
    QString pathSaveFile = QFileDialog::getSaveFileName(NULL,tr("Save Filter"), lastFilterDirectory, tr("Filter File (*.fif)" ) );
    if( pathSaveFile != NULL )
    {
        lastFilterDirectory = pathSaveFile;
        QSettings testSetting(pathSaveFile, QSettings::IniFormat);
        testSetting.clear();
        CommandList* myCommandList = (CommandList*)itsViewsTreeItemModel.itemFromIndex( ui->viewsTreeView->currentIndex() );
        myCommandList->saveFilterSettings( testSetting );
    }
    //#]
}

void MainWindow::saveRecentXMLFilesToConfigFile()
{
    //#[ operation saveRecentXMLFilesToConfigFile()
    qSettingsFile.beginGroup("Gui");
    qSettingsFile.remove("RecentFiles");
    QList<QAction*> myActionList = ui->menuRecent_opend_files->actions();
    qSettingsFile.beginWriteArray("RecentFiles",myActionList.size());
    for( int i = 0; i < myActionList.size(); i++ )
    {
        qSettingsFile.setArrayIndex(i);
        qSettingsFile.setValue("RecentFiles",myActionList.at( i )->text());
    }
    qSettingsFile.endArray();
    
    
    qSettingsFile.endGroup();
    //#]
}

void MainWindow::saveSelectedCommandList()
{
    //#[ operation saveSelectedCommandList()
    CommandList& currentCommandList = *(CommandList*)itsViewsTreeItemModel.itemFromIndex( ui->viewsTreeView->currentIndex() );
    this->saveCommandList(currentCommandList);
    //#]
}

void MainWindow::saveView()
{
    //#[ operation saveView()
    QString filePath = QFileDialog::getSaveFileName(this, "Save View", QString(), "Target Debugger files (*.tdx)");
    CommandList* currentCommandList = NULL;
    
    QModelIndex myIndex = ui->viewsTreeView->currentIndex();
    if( myIndex.isValid() )
    {
        currentCommandList = (CommandList*)itsViewsTreeItemModel.itemFromIndex( myIndex );
    
    }
    emit this->saveView(filePath, currentCommandList);
    //#]
}

void MainWindow::setCurrentAttributeWaitingForValueFromParser(const QString& value)
{
    //#[ operation setCurrentAttributeWaitingForValueFromParser(QString)
    if( currentAttributeWaitingForValue != NULL )
    {
        currentAttributeWaitingForValue->setText( value );
        AttributeDisplayTypes displayType = (AttributeDisplayTypes)currentAttributeWaitingForValue->data( Qt::UserRole + 2).toInt();
        if( displayType == UnsignedInt )
        {
            attributeToUInt( currentAttributeWaitingForValue );
        }
        else if( displayType == SignedInt )
        {
            attributeToSInt( currentAttributeWaitingForValue );
        }
        else if( displayType == Dual )
        {
            attributeToBin( currentAttributeWaitingForValue );
        }
        else if( displayType == HexaDecimal )
        {
            attributeToHex( currentAttributeWaitingForValue );
        }
    }
    //#]
}

void MainWindow::showConsoleContextMenue(QPoint point)
{
    //#[ operation showConsoleContextMenue(QPoint)
    consoleContextMenue->exec( ui->consoleTextArea->mapToGlobal(point) );
    //#]
}

void MainWindow::showErrorConsoleContextMenue(QPoint point)
{
    //#[ operation showErrorConsoleContextMenue(QPoint)
    errorConsoleContextMenue->exec( ui->errorTextArea->mapToGlobal(point) );
    //#]
}

void MainWindow::showTargetConsoleContextMenue(QPoint point)
{
    //#[ operation showTargetConsoleContextMenue(QPoint)
    targetConsoleContextMenue->exec( ui->TXT_TargetConsole->mapToGlobal(point) );
    //#]
}

void MainWindow::showTreeContextMenue(QPoint point)
{
    //#[ operation showTreeContextMenue(QPoint)
    QModelIndex index = ui->targetTreeView->indexAt(point);
    if( index.isValid() )
    {
    
        QStandardItemModel *myModel = (QStandardItemModel*)index.model();   
        QStandardItem *aItem = myModel->itemFromIndex(index);
        if( !aItem->data(Qt::UserRole).isNull() && aItem->data(Qt::UserRole).toInt() == ATTRIBUTE_VALUE_DATA )
        {
            itsAttributeChangeBaseItem = aItem;
            targetTreeContextMenue->exec( ui->targetTreeView->mapToGlobal(point) );
        }
        else
        {
            itsAttributeChangeBaseItem = NULL;
        }
    }       
    
    //#]
}

void MainWindow::showViewsContextMenue(QPoint point)
{
    //#[ operation showViewsContextMenue(QPoint)
    QModelIndex index = ui->viewsTreeView->indexAt(point);
    if( index.isValid() )
    {
        viewsContextMenue->exec(ui->viewsTreeView->mapToGlobal(point));
        QStandardItemModel *myModel = (QStandardItemModel*)index.model();
        itsSelectedCommandList = (CommandList*)myModel->itemFromIndex(index);
    }
    //#]
}

void MainWindow::targetConsoleMsg(const QString& msg)
{
    //#[ operation targetConsoleMsg(QString)
    ui->TXT_TargetConsole->append(msg);
    //#]
}

void MainWindow::viewsTreeItemCountChanged()
{
    //#[ operation viewsTreeItemCountChanged()
    const bool viewsTreeItemModelNotEmpty = this->itsViewsTreeItemModel.rowCount() > 0;
    this->ui->actionSaveCommandsFile->setEnabled(viewsTreeItemModelNotEmpty);
    this->ui->actionSaveDataLOGFile->setEnabled(viewsTreeItemModelNotEmpty);
    //#]
}

void MainWindow::addNewInstanceToDebugIntTree(const ModelInstance& newInstance)
{
    //#[ operation addNewInstanceToDebugIntTree(ModelInstance)
    if( newInstance.getItsTargetInformation()->getItsTreeViewItemDebugInt() == NULL )
    {
        QStandardItem* myItem = new QStandardItem( QIcon( ":/icons/classTreeView/img/icons/classTreeView/ModelIcon_ClassGroup.png" ), newInstance.getItsTargetInformation()->getName() );
        myItem->setData(QVariant(newInstance.getItsTargetInformation()->getId()), Qt::UserRole + 1);
        itsDebugIntListItem->appendRow( myItem );
        newInstance.getItsTargetInformation()->setItsTreeViewItemDebugInt( myItem );
    }
    QStandardItem *classFilterItem = newInstance.getItsModelClass()->getItsTreeViewItemDebugInt();
    if( classFilterItem == NULL )
    {
        classFilterItem = new QStandardItem( QIcon( ":/icons/classTreeView/img/icons/classTreeView/ModelIcon_Class.png" ), newInstance.getItsModelClass()->getName() );
        classFilterItem->setCheckable( true );
        newInstance.getItsTargetInformation()->getItsTreeViewItemDebugInt()->appendRow( classFilterItem );
        newInstance.getItsTargetInformation()->getItsTreeViewItemDebugInt()->sortChildren(0);
        newInstance.getItsModelClass()->setItsTreeViewItemDebugInt( classFilterItem );
    }
    QStandardItem * filterInstanceTreeViewItem = new QStandardItem( QIcon( ":/icons/classTreeView/img/icons/classTreeView/ModelIcon_Instance.png" ), newInstance.getName() );
    filterInstanceTreeViewItem->setCheckable( true );
    filterInstanceTreeViewItem->setCheckState( Qt::Unchecked );
    filterInstanceTreeViewItem->setData(QVariant((uint)&newInstance),Qt::UserRole);
    classFilterItem->appendRow( filterInstanceTreeViewItem );
    newInstance.getItsTargetInformation()->getItsTreeViewItemDebugInt()->sortChildren(0);
    //#]
}

void MainWindow::addNewInstanceToInstanceList(const ModelInstance& newInstance)
{
    //#[ operation addNewInstanceToInstanceList(ModelInstance)
    //add instance to instance list
    int newRow = ui->instanceList->rowCount();
    QTableWidgetItem *instanceNameItem = new QTableWidgetItem( newInstance.getName() );
    instanceNameItem->setData(Qt::UserRole, QVariant(newInstance.getItsTargetInformation()->getId()));
    QTableWidgetItem *classNameItem = new QTableWidgetItem(newInstance.getItsModelClass()->getName());
    QTableWidgetItem *addressItem = new QTableWidgetItem("0x" + QString::number(newInstance.getAddress(),16));
    ui->instanceList->setRowCount(newRow + 1);
    
    ui->instanceList->setItem(newRow,0,instanceNameItem);
    ui->instanceList->setItem(newRow,1,classNameItem);
    ui->instanceList->setItem(newRow,2,addressItem);
    //#]
}

void MainWindow::addNewInstanceToTargetFilterTree(const ModelInstance& newInstance, const TargetInformation& target)
{
    //#[ operation addNewInstanceToTargetFilterTree(ModelInstance,TargetInformation)
    //create model item and appand to filter list in tree view
    if( newInstance.getItsModelClass()->getIsReactive() )
    {
        if( target.getItsTreeViewItemTargetFilter() == NULL )
        {
            QStandardItem* myItem = new QStandardItem( QIcon( ":/icons/classTreeView/img/icons/classTreeView/ModelIcon_ClassGroup.png" ), target.getName() );
            myItem->setData(QVariant(target.getId()), Qt::UserRole + 1);
            itsTargetFilterListItem->appendRow( myItem );
            newInstance.getItsTargetInformation()->setItsTreeViewItemTargetFilter( myItem );
        }
        QStandardItem *classFilterItem = newInstance.getItsModelClass()->getItsTreeViewItemTargetFilter();
        if( classFilterItem == NULL )
        {
            classFilterItem = new QStandardItem( QIcon( ":/icons/classTreeView/img/icons/classTreeView/ModelIcon_Class.png" ), newInstance.getItsModelClass()->getName() );
            classFilterItem->setCheckable( true );
            target.getItsTreeViewItemTargetFilter()->appendRow( classFilterItem );
            target.getItsTreeViewItemTargetFilter()->sortChildren(0);
            newInstance.getItsModelClass()->setItsTreeViewItemTargetFilter( classFilterItem );
        }
        QStandardItem * filterInstanceTreeViewItem = new QStandardItem( QIcon( ":/icons/classTreeView/img/icons/classTreeView/ModelIcon_Instance.png" ), newInstance.getName() );
        filterInstanceTreeViewItem->setCheckable( true );
        filterInstanceTreeViewItem->setCheckState( Qt::Checked );
        filterInstanceTreeViewItem->setData(QVariant((uint)&newInstance), Qt::UserRole);
        classFilterItem->appendRow( filterInstanceTreeViewItem );
        classFilterItem->sortChildren(0);
    }
    //#]
}

void MainWindow::addNewInstanceToTargetTree(const ModelInstance& newInstance, const TargetInformation& target)
{
    //#[ operation addNewInstanceToTargetTree(ModelInstance,TargetInformation)
    //Add Instance to Class
    
    if( target.getItsTreeViewItemTarget() == NULL )
    {
        QStandardItem *myItem = new QStandardItem( QIcon( ":/icons/classTreeView/img/icons/classTreeView/ModelIcon_ClassGroup.png" ), target.getName() );
        myItem->setData(QVariant(target.getId()), Qt::UserRole + 1);
        newInstance.getItsTargetInformation()->setItsTreeViewItemTarget( myItem );
        itsTargetListItem->appendRow( myItem );
    }
    QStandardItem * targetClassInstanceItem = newInstance.getItsModelClass()->getItsTreeViewItemTarget();
    if( targetClassInstanceItem == NULL )
    {
        QStandardItem* targetClassItem = new QStandardItem( QIcon( ":/icons/classTreeView/img/icons/classTreeView/ModelIcon_Class.png" ), newInstance.getItsModelClass()->getName() );
        targetClassInstanceItem = new QStandardItem( QIcon( ":/icons/classTreeView/img/icons/classTreeView/ModelIcon_InstanceGroup.png" ) , "Instances" );
        targetClassItem->appendRow( targetClassInstanceItem );
    
        newInstance.getItsModelClass()->setItsTreeViewItemTarget( targetClassInstanceItem );
    
        target.getItsTreeViewItemTarget()->appendRow( targetClassItem );
        target.getItsTreeViewItemTarget()->sortChildren(0);
    }
    
    //Instance part
    //create model item and appand to class list in tree view
    QStandardItem * instanceItem = new QStandardItem( QIcon( ":/icons/classTreeView/img/icons/classTreeView/ModelIcon_Instance.png" ), newInstance.getName() );
    targetClassInstanceItem->appendRow( instanceItem );
    
    
    //Attribute part
    QStandardItem * myClassAttributeGroupItem = new QStandardItem( QIcon( ":/icons/classTreeView/img/icons/classTreeView/ModelIcon_AttributeGroup.png" ), "Attributes" );
    instanceItem->appendRow( myClassAttributeGroupItem );
    for( auto myClassAttribut : newInstance.getItsModelClass()->getClassAttributeList() )
    {
        if( myClassAttribut->getVisible() )
        {
            QStandardItem* myClassAttributeItem = new QStandardItem( QIcon( ":/icons/classTreeView/img/icons/classTreeView/ModelIcon_Attribute.png" ) , myClassAttribut->getName() );
            myClassAttributeItem->setData(QVariant((uint)&target), Qt::UserRole);
            if( myClassAttribut->getCompleteArraySize() > 1)
            {
                for( unsigned int i = 0; i < myClassAttribut->getArrayDimension(0); i++){
                    QStandardItem * arrayItem = new QStandardItem( QIcon( ":/icons/classTreeView/img/icons/classTreeView/ModelIcon_Highwater.png"), "["+QString::number(i)+"]" );
                    arrayItem->setData(QVariant((uint)&target), Qt::UserRole);
                    if( myClassAttribut->getArrayDimension(1) == 1 ){ // 1 Dimensional
                        arrayItem->appendRow( new QStandardItem( QIcon( ":/icons/classTreeView/img/icons/classTreeView/ModelIcon_VariableType.png"), myClassAttribut->getItsModelDataType()->getName() ) );
                        QStandardItem *aItem = new QStandardItem( 0 );
                        aItem->setData(ATTRIBUTE_VALUE_DATA, Qt::UserRole );
                        aItem->setData((uint)(myClassAttribut->getItsModelDataType()), Qt::UserRole + 1 );
                        aItem->setData((uint)HexaDecimal, Qt::UserRole + 2 );
                        arrayItem->appendRow( aItem );
                    }
                    else{ // 2 Dimensional
                        for( unsigned int j = 0; j < myClassAttribut->getArrayDimension(1); j++){
                            QStandardItem * arrayItem2D = new QStandardItem( QIcon(":/icons/classTreeView/img/icons/classTreeView/ModelIcon_Highwater.png" ), "["+QString::number(j)+"]" );
                            arrayItem2D->setData(QVariant((uint)&target), Qt::UserRole);
                            if( myClassAttribut->getArrayDimension(2) == 1 ){ // 2 Dimensional
                                arrayItem2D->appendRow( new QStandardItem( QIcon(":/icons/classTreeView/img/icons/classTreeView/ModelIcon_VariableType.png"), myClassAttribut->getItsModelDataType()->getName() ) );
                                QStandardItem *aItem = new QStandardItem( 0 );
                                aItem->setData(ATTRIBUTE_VALUE_DATA, Qt::UserRole );
                                aItem->setData((uint)(myClassAttribut->getItsModelDataType()), Qt::UserRole + 1 );
                                aItem->setData((uint)HexaDecimal, Qt::UserRole + 2 );
                                arrayItem2D->appendRow( aItem );
                            }
                            else{ // 3 Dimensional
                                for( unsigned int k = 0; k < myClassAttribut->getArrayDimension(2); k++){
                                    QStandardItem * arrayItem3D = new QStandardItem( QIcon( ":/icons/classTreeView/img/icons/classTreeView/ModelIcon_Highwater.png" ), "["+QString::number(k)+"]" );
                                    arrayItem3D->setData(QVariant((uint)&target), Qt::UserRole);
                                    arrayItem3D->appendRow( new QStandardItem( QIcon( ":/icons/classTreeView/img/icons/classTreeView/ModelIcon_VariableType.png" ), myClassAttribut->getItsModelDataType()->getName() ) );
                                    QStandardItem *aItem = new QStandardItem( 0 );
                                    aItem->setData(ATTRIBUTE_VALUE_DATA, Qt::UserRole );
                                    aItem->setData((uint)(myClassAttribut->getItsModelDataType()), Qt::UserRole + 1 );
                                    aItem->setData((uint)HexaDecimal, Qt::UserRole + 2 );
                                    arrayItem3D->appendRow( aItem );
                                    arrayItem2D->appendRow(arrayItem3D);
                                }
                            }
                            arrayItem->appendRow(arrayItem2D);
                        }
                    }    
                    myClassAttributeItem->appendRow( arrayItem );
                }                
            }
            else
            {
                QStandardItem* myClassAttributeTypeItem = new QStandardItem( QIcon( ":/icons/classTreeView/img/icons/classTreeView/ModelIcon_VariableType.png" ) , myClassAttribut->getItsModelDataType()->getName() );
                QStandardItem *myClassAttributeTypeValue = new QStandardItem( 0 );
                myClassAttributeTypeValue->setData(ATTRIBUTE_VALUE_DATA, Qt::UserRole );
                myClassAttributeTypeValue->setData((uint)(myClassAttribut->getItsModelDataType()), Qt::UserRole + 1 );
                myClassAttributeTypeValue->setData((uint)HexaDecimal, Qt::UserRole + 2 );
                myClassAttributeItem->appendRow(myClassAttributeTypeItem);
                myClassAttributeItem->appendRow(myClassAttributeTypeValue);
            }
            myClassAttributeGroupItem->appendRow( myClassAttributeItem );
        }
    }
    
    //State part
    if( newInstance.getItsModelClass()->getIsReactive() )
    {
        QStandardItem * myClassStateGroupItem = new QStandardItem( QIcon( ":/icons/classTreeView/img/icons/classTreeView/ModelIcon_State.png" ), "State" );
        myClassStateGroupItem->setData(QVariant((uint)&target), Qt::UserRole);
        instanceItem->appendRow( myClassStateGroupItem );
        for(unsigned int i = 0; i < newInstance.getItsModelClass()->getParrallelStateCount(); i++)
        {
            QStandardItem* myClassStateItem = new QStandardItem( "" );
            myClassStateGroupItem->appendRow( myClassStateItem );
        }
    }
    //#]
}

void MainWindow::attributeToBin(QStandardItem* item)
{
    //#[ operation attributeToBin(QStandardItem)
    bool ok;
    QString val = item->text();
    uint64_t value = convertCurrentAttributeValuetoInt( val, ok );
    if( ok )
    {
        QString newNumber = QString::number(value,2);
        ModelDataType *modelType = (ModelDataType*)item->data(Qt::UserRole + 1).toUInt();
        int offset = newNumber.length() - ( modelType->getSize() * 8 );
        if( offset > 0 )
        {
            newNumber = newNumber.remove(0, offset );
        }
        else if( offset < 0 )
        {
            offset = offset * -1;
            QString additionalData = "";
            for( int i = 0; i < offset; i++ )
            {
                additionalData += "0";
            }
            newNumber = additionalData + newNumber;
        }
        item->setText( "0b" + newNumber);
    }
    //#]
}

void MainWindow::attributeToHex(QStandardItem* item)
{
    //#[ operation attributeToHex(QStandardItem)
    bool ok;
    QString val = item->text();
    uint64_t value = convertCurrentAttributeValuetoInt( val, ok );
    if( ok )
    {
        QString newNumber = QString::number(value,16);
        ModelDataType *modelType = (ModelDataType*)item->data(Qt::UserRole + 1).toUInt();
        int offset = newNumber.length() - ( modelType->getSize() * 2 );
        if( offset > 0 )
        {
            newNumber = newNumber.remove(0, offset );
        }
        else if( offset < 0 )
        {
            offset = offset * -1;
            QString additionalData = "";
            for( int i = 0; i < offset; i++ )
            {
                additionalData += "0";
            }
            newNumber = additionalData + newNumber;
        }
    
        item->setText( "0x" + newNumber);
    }
    //#]
}

void MainWindow::attributeToSInt(QStandardItem* item)
{
    //#[ operation attributeToSInt(QStandardItem)
    bool ok;
    QString val = item->text();
    int64_t value = convertCurrentAttributeValuetoInt( val, ok );
    ModelDataType *modelType = (ModelDataType*)item->data(Qt::UserRole + 1).toUInt();
    if( ok )
    {
        if( modelType->getSize() == 1 )
        {
            item->setText( QString::number((int8_t)value,10) );
        }
        else if( modelType->getSize() == 2 )
        {
            item->setText( QString::number((int16_t)value,10) );
        }
        else if( modelType->getSize() == 4 )
        {
            item->setText( QString::number((int32_t)value,10) );
        }
        else if( modelType->getSize() == 8 )
        {
            item->setText( QString::number(value,10) );
        }
    }
    //#]
}

void MainWindow::attributeToUInt(QStandardItem* item)
{
    //#[ operation attributeToUInt(QStandardItem)
    bool ok;
    QString val = item->text();
    uint64_t value = convertCurrentAttributeValuetoInt( val, ok );
    ModelDataType *modelType = (ModelDataType*)item->data(Qt::UserRole + 1).toUInt();
    if( ok )
    {
        if( modelType->getSize() == 1 )
        {
            item->setText( QString::number((uint8_t)value,10) );
        }
        else if( modelType->getSize() == 2 )
        {
            item->setText( QString::number((uint16_t)value,10) );
        }
        else if( modelType->getSize() == 4 )
        {
            item->setText( QString::number((uint32_t)value,10) );
        }
        else if( modelType->getSize() == 8 )
        {
            item->setText( QString::number(value,10) );
        }
    }
    //#]
}

uint64_t MainWindow::convertCurrentAttributeValuetoInt(const QString& text, bool& ok)
{
    //#[ operation convertCurrentAttributeValuetoInt(QString,bool)
    QString myText = text;
    if( myText.startsWith("0x") )
    {
        return myText.replace("0x","").toULongLong(&ok, 16);
    }
    else if( myText.startsWith("0b") )
    {
        return myText.replace("0b","").toULongLong(&ok, 2);
    }
    else
    {
        if( myText.startsWith("-") )
        {
            return (uint64_t)myText.toLongLong(&ok, 10);
        }
        else
        {
            return text.toULongLong(&ok, 10);
        }
    }
    //#]
}

void MainWindow::initFilterViewContextMenue()
{
    //#[ operation initFilterViewContextMenue()
    itsFilterTreeItemModel.appendRow(itsTargetFilterListItem);
    ui->filtersTreeView->setModel(&itsFilterTreeItemModel);
    
    /*
     * Create context menue with actions
     */
    viewsContextMenue = new QMenu(ui->viewsTreeView);
    
    // create add action
    QAction *addFilter = new QAction("Add Filter");
    viewsContextMenue->addAction( addFilter );
    connect( addFilter, SIGNAL(triggered(bool)), this, SLOT( addFilterView() ) );
    
    // create edit action
    QAction *editFilter = new QAction("Edit Filter");
    viewsContextMenue->addAction( editFilter );
    connect( editFilter, SIGNAL(triggered(bool)), this, SLOT( editFilterView() ) );
    
    // create delete action
    //ToDo
    /*QAction *deleteFilter = new QAction("Delete Filter List");
    viewsContextMenue->addAction( deleteFilter );
    connect( deleteFilter, SIGNAL(triggered(bool)), this, SLOT( deleteFilterView() ) );*/
    
    viewsContextMenue->addSeparator();
    
    // create new view action
    QAction *newView = new QAction("Open View in New Window");
    viewsContextMenue->addAction( newView );
    connect( newView, SIGNAL(triggered(bool)), this, SLOT( openNewViewWindow() ) );
    
    // save view
    QAction *saveView = new QAction("Save View");
    viewsContextMenue->addAction( saveView );
    connect( saveView, SIGNAL(triggered(bool)), this, SLOT( saveView() ));
    
    // create export action
    QAction *exportCommands = new QAction("Save Commands to File");
    viewsContextMenue->addAction( exportCommands );
    connect( exportCommands, SIGNAL(triggered(bool)), this, SLOT( saveSelectedCommandList()) );
    
    viewsContextMenue->addSeparator();
    
    // create save filter view action
    QAction *saveFilter = new QAction("Save Filter View");
    viewsContextMenue->addAction( saveFilter );
    connect( saveFilter, SIGNAL(triggered(bool)), this, SLOT( saveFilterView()) );
    
    // create load filter view action
    QAction *loadFilter = new QAction("Load Filter View");
    viewsContextMenue->addAction( loadFilter );
    connect( loadFilter, SIGNAL(triggered(bool)), this, SLOT( loadFilterView()) );
    
    ui->viewsTreeView->setContextMenuPolicy(Qt::CustomContextMenu);
    //#]
}

void MainWindow::initTreeViewContextMenue()
{
    //#[ operation initTreeViewContextMenue()
    targetTreeContextMenue = new QMenu(ui->targetTreeView);
    
    // toHex
    QAction *toHex = new QAction("to Hexadecimal");
    connect(toHex,SIGNAL(triggered(bool)),this,SLOT(attributeValueToHex()) );
    targetTreeContextMenue->addAction( toHex );
    
    // toDec
    QAction *toDec = new QAction("to Decimal");
    connect(toDec,SIGNAL(triggered(bool)),this,SLOT(attributeValueToDec()) );
    targetTreeContextMenue->addAction( toDec );
    
    // toUDec
    QAction *toUDec = new QAction("to Unsigned Decimal");
    connect(toUDec,SIGNAL(triggered(bool)),this,SLOT(attributeValueToUnsignedDec()) );
    targetTreeContextMenue->addAction( toUDec );
    
    // toBin
    QAction *toBin = new QAction("to Binary");
    connect(toBin,SIGNAL(triggered(bool)),this,SLOT(attributeValueToBin()) );
    targetTreeContextMenue->addAction( toBin );  
    
    ui->targetTreeView->setContextMenuPolicy(Qt::CustomContextMenu);
    //#]
}

void MainWindow::loadRecentXMLFiles()
{
    //#[ operation loadRecentXMLFiles()
    bool ok;
    maxRecentFiles = qSettingsFile.value("maxRecentFiles").toInt( &ok );
    if(!ok)
    {
        maxRecentFiles = 10;
        qSettingsFile.setValue("maxRecentFiles",QString::number(10));
    }
    
    int storedXMLFiles = qSettingsFile.beginReadArray("RecentFiles");
    for( int i = 0; i < storedXMLFiles; i++ )
    {
        qSettingsFile.setArrayIndex(i);
        ui->menuRecent_opend_files->addAction( qSettingsFile.value( "RecentFiles" ).toString() );
    }
    qSettingsFile.endArray();
    //#]
}

void MainWindow::loadWindowPosition()
{
    //#[ operation loadWindowPosition()
    bool ok;
    int windowWidth = qSettingsFile.value("windowWidth").toInt( &ok );
    if(!ok)
    {
        windowWidth = 1000;
        qSettingsFile.setValue("windowWidth",QString::number(1000));
    }
    int windowHeight = qSettingsFile.value("windowHeight").toInt( &ok );
    if(!ok)
    {
        windowHeight = 700;
        qSettingsFile.setValue("windowHeight",QString::number(700));
    }
    int windowXPos = qSettingsFile.value("windowXPos").toInt( &ok );
    if(!ok)
    {
        windowXPos = 50;
        qSettingsFile.setValue("windowXPos",QString::number(50));
    }
    int windowYPos = qSettingsFile.value("windowYPos").toInt( &ok );
    if(!ok)
    {
        windowYPos = 50;
        qSettingsFile.setValue("windowYPos",QString::number(50));
    }
    bool windowFullScrean = qSettingsFile.value("windowFullScrean").toBool();
    setGeometry(windowXPos,windowYPos,windowWidth,windowHeight);
    
    if( windowFullScrean )
    {
        showMaximized();
        qSettingsFile.setValue("windowFullScrean","true");
    }
    else
    {
        qSettingsFile.setValue("windowFullScrean","false");
    }
    //#]
}

void MainWindow::cleanUpRelations()
{
    if(itsAttributeChangeBaseItem != NULL)
        {
            itsAttributeChangeBaseItem = NULL;
        }
    if(itsDataViewFilterGeneration != NULL)
        {
            itsDataViewFilterGeneration = NULL;
        }
    if(itsDebugIntListItem != NULL)
        {
            itsDebugIntListItem = NULL;
        }
    if(itsSelectedCommandList != NULL)
        {
            itsSelectedCommandList = NULL;
        }
    if(itsSequenceDiagram != NULL)
        {
            itsSequenceDiagram = NULL;
        }
    if(itsTargetFilterListItem != NULL)
        {
            itsTargetFilterListItem = NULL;
        }
    if(itsTargetListItem != NULL)
        {
            itsTargetListItem = NULL;
        }
    if(itsTimingDiagram != NULL)
        {
            itsTimingDiagram = NULL;
        }
    if(itsViewsFilterView != NULL)
        {
            itsViewsFilterView = NULL;
        }
}

/*********************************************************************
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\MainWindow.cpp
*********************************************************************/
