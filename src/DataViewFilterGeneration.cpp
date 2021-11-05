/********************************************************************
	Rhapsody	: 9.0.1 
	Login		: Y9DSYU706
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: DataViewFilterGeneration
//!	Generated Date	: Thu, 4, Nov 2021  
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\DataViewFilterGeneration.cpp
*********************************************************************/

#include "DataViewFilterGeneration.h"
#include "CommandList.h"
#include "CommandListFilter.h"
#include "TargetInformation.h"
#include "TargetList.h"
#include "ui_DataViewFilterGeneration.h"
#include <QMessageBox>
//## package GUI

//## class DataViewFilterGeneration
DataViewFilterGeneration::DataViewFilterGeneration() : ui(new Ui::DataViewFilterGeneration)
{
    itsEditCommandList = NULL;
    itsParentCommandList = NULL;
    itsTargetInformationSingleTarget = NULL;
    //#[ operation DataViewFilterGeneration()
    ui->setupUi(this);
    eventFilterModel = new QStandardItemModel();
    ui->lstEventFilter->setModel(eventFilterModel);
    connectSignals();
    myWindowFlags = windowFlags();
    targetFilterModel = new QStandardItemModel();
    //#]
}

DataViewFilterGeneration::~DataViewFilterGeneration()
{
    //#[ operation ~DataViewFilterGeneration()
    disconnectSignals();
    //#]
    cleanUpRelations();
}

void DataViewFilterGeneration::activateDestinationFilter(bool active)
{
    //#[ operation activateDestinationFilter(bool)
    QModelIndex myIndex = ui->lstEventFilter->currentIndex();
    if( myIndex.isValid() )
    {
        int rowNr = myIndex.row();
        destFilterActiveList[ rowNr ] = active;
        ui->btnDestAdd->setEnabled( active );
        ui->btnDestAddAll->setEnabled( active );
        ui->btnDestDel->setEnabled( active );
        ui->btnDestDelAll->setEnabled( active );
        ui->lstDestHide->setEnabled( active );
        ui->lstDestShow->setEnabled( active );
    }
    //#]
}

void DataViewFilterGeneration::activateEventFilter(bool active)
{
    //#[ operation activateEventFilter(bool)
    QModelIndex myIndex = ui->lstEventFilter->currentIndex();
    if( myIndex.isValid() )
    {
        int rowNr = myIndex.row();
        eventFilterActiveList[ rowNr ] = active;
        ui->btnEventAdd->setEnabled( active );
        ui->btnEventAddAll->setEnabled( active );
        ui->btnEventDel->setEnabled( active );
        ui->btnEventDelAll->setEnabled( active );
        ui->lstEventHide->setEnabled( active );
        ui->lstEventShow->setEnabled( active );
    }
    //#]
}

void DataViewFilterGeneration::activateSourceFilter(bool active)
{
    //#[ operation activateSourceFilter(bool)
    QModelIndex myIndex = ui->lstEventFilter->currentIndex();
    if( myIndex.isValid() )
    {
        int rowNr = myIndex.row();
        sourceFilterActiveList[ rowNr ] = active;
        ui->btnSourceAdd->setEnabled( active );
        ui->btnSourceAddAll->setEnabled( active );
        ui->btnSourceDel->setEnabled( active );
        ui->btnSourceDelAll->setEnabled( active );
        ui->lstSourceHide->setEnabled( active );
        ui->lstSourceShow->setEnabled( active );
    }
    //#]
}

void DataViewFilterGeneration::addFilter()
{
    //#[ operation addFilter()
    this->hide();
    CommandListFilter * myNewCommandListFilter = new CommandListFilter();
    
    myNewCommandListFilter->setBufferOverflowFilterd( ui->CBX_BufferOverflow->isChecked() );
    myNewCommandListFilter->setConstructorFilterd( ui->CBX_ConstructorCalls->isChecked() );
    myNewCommandListFilter->setDestructorFilterd( ui->CBX_DestructorCalls->isChecked() );
    myNewCommandListFilter->setErrorHandlerFilterd( ui->CBX_ErrorHanlder->isChecked() );
    myNewCommandListFilter->setTargetFilterd( ui->CBX_TargetFilter->isChecked() );
    myNewCommandListFilter->setDebugIntFiltered( ui->CBX_DebugInt->isChecked() );
    myNewCommandListFilter->setTicksFilterd( ui->CBX_TickRange->isChecked() );
    myNewCommandListFilter->setTickMin( ui->SB_tickMin->value() );
    myNewCommandListFilter->setTickMax( ui->SB_tickMax->value() );
    
    
    addUiTargesToFilter( myNewCommandListFilter );
    addUiPartsToFilter( myNewCommandListFilter );
    
    
    if( mode == newFilterMode )
    {
        CommandList *myCommandList = new CommandList(*itsParentCommandList->getItsTargetList());
        myCommandList->setItsCommandListFilter( myNewCommandListFilter );
        myCommandList->setText( ui->txtFilterName->text() );
    
        // add all commands from parent to the new child list
        // this should be optimized
        for( auto myCommand : itsParentCommandList->getCommands() )
        {
            myCommandList->addCommand( myCommand, false );
        }
    
        // add the new command list to the child of its parent command list
        itsParentCommandList->addChildList( myCommandList );
        itsParentCommandList->appendRow( myCommandList );
    }
    else
    {
        itsEditCommandList->clear();
        itsEditCommandList->setItsCommandListFilter( myNewCommandListFilter );
        itsEditCommandList->setText( ui->txtFilterName->text() );
        // add all commands from parent to the new child list
        // this should be optimized
        for( auto myCommand : itsParentCommandList->getCommands() )
        {
            itsEditCommandList->addCommand( myCommand, false );
        }
    }
    
    //#]
}

void DataViewFilterGeneration::destAdd()
{
    //#[ operation destAdd()
    QModelIndexList mySelection = ui->lstDestHide->selectionModel()->selectedRows();
    int pos = 0;
    QStandardItemModel* destHideModel = (QStandardItemModel*)ui->lstDestHide->model();
    QStandardItemModel* destShowModel = (QStandardItemModel*)ui->lstDestShow->model();
    while( !mySelection.empty() )
    {
        pos = mySelection.first().row();
        QStandardItem * myItem = destHideModel->takeItem( pos );
        destHideModel->removeRow( pos );
        destShowModel->appendRow( myItem );
        mySelection = ui->lstDestHide->selectionModel()->selectedRows();
    }
    destShowModel->sort(0);
    //#]
}

void DataViewFilterGeneration::destAddAll()
{
    //#[ operation destAddAll()
    QStandardItemModel* destHideModel = (QStandardItemModel*)ui->lstDestHide->model();
    QStandardItemModel* destShowModel = (QStandardItemModel*)ui->lstDestShow->model();
    while( destHideModel->rowCount() > 0 )
    {
        QStandardItem * myItem = destHideModel->takeItem( 0 );
        destHideModel->removeRow( 0 );
        destShowModel->appendRow( myItem );
    }
    destShowModel->sort(0);
    //#]
}

void DataViewFilterGeneration::destDel()
{
    //#[ operation destDel()
    QModelIndexList mySelection = ui->lstDestShow->selectionModel()->selectedRows();
    int pos = 0;
    QStandardItemModel* destHideModel = (QStandardItemModel*)ui->lstDestHide->model();
    QStandardItemModel* destShowModel = (QStandardItemModel*)ui->lstDestShow->model();
    while( !mySelection.empty() )
    {
        pos = mySelection.first().row();
        QStandardItem * myItem = destShowModel->takeItem( pos );
        destShowModel->removeRow( pos );
        destHideModel->appendRow( myItem );
        mySelection = ui->lstDestShow->selectionModel()->selectedRows();
    }
    destHideModel->sort(0);
    //#]
}

void DataViewFilterGeneration::destDelAll()
{
    //#[ operation destDelAll()
    QStandardItemModel* destHideModel = (QStandardItemModel*)ui->lstDestHide->model();
    QStandardItemModel* destShowModel = (QStandardItemModel*)ui->lstDestShow->model();
    while( destShowModel->rowCount() > 0 )
    {
        QStandardItem * myItem = destShowModel->takeItem( 0 );
        destShowModel->removeRow( 0 );
        destHideModel->appendRow( myItem );
    }
    destHideModel->sort(0);
    //#]
}

void DataViewFilterGeneration::editFilter(CommandList* list)
{
    //#[ operation editFilter(CommandList)
    setWindowFlags(Qt::WindowTitleHint);
    mode = editFilterMode;
    itsEditCommandList = list;
    CommandListFilter *myCommandListFilter = list->getItsCommandListFilter();
    
    ui->CBX_DestinationFilter->setChecked( false );
    ui->CBX_SourceFilter->setChecked( false );
    ui->CBX_EventFilter->setChecked( false );
    ui->CBX_BufferOverflow->setChecked( myCommandListFilter->getBufferOverflowFilterd() );
    ui->CBX_ConstructorCalls->setChecked( myCommandListFilter->getConstructorFilterd() );
    ui->CBX_ErrorHanlder->setChecked( myCommandListFilter->getErrorHandlerFilterd() );
    ui->CBX_DestructorCalls->setChecked( myCommandListFilter->getDestructorFilterd() );
    ui->CBX_TickRange->setChecked( myCommandListFilter->getTicksFilterd() );
    
    ui->SB_tickMax->setValue( myCommandListFilter->getTickMax() );
    ui->SB_tickMin->setValue( myCommandListFilter->getTickMin() );
    
    ui->txtFilterName->setText( list->text() );
    
    //Clear userInterface
    ui->lstDestHide->setModel( NULL );
    ui->lstDestShow->setModel( NULL );
    
    ui->lstSourceHide->setModel( NULL );
    ui->lstSourceShow->setModel( NULL );
    
    ui->lstEventHide->setModel( NULL );
    ui->lstEventShow->setModel( NULL );
    
    ui->lstDestHide->setEnabled( false );
    ui->lstDestShow->setEnabled( false );
    
    ui->lstSourceHide->setEnabled( false );
    ui->lstSourceShow->setEnabled( false );
    
    ui->lstEventHide->setEnabled( false );
    ui->lstEventShow->setEnabled( false );
    
    ui->CBX_TargetFilter->setChecked( myCommandListFilter->getTargetFilterd() );
    
    eventFilterActiveList.clear();
    destFilterActiveList.clear();
    sourceFilterActiveList.clear();
    
    addFilterPartsToUiList( myCommandListFilter, list->getItsTargetList() );
    
    
    ui->lstTargetFilter->setModel(targetFilterModel);
    
    
    
    show();
    //#]
}

void DataViewFilterGeneration::eventAdd()
{
    //#[ operation eventAdd()
    QModelIndexList mySelection = ui->lstEventHide->selectionModel()->selectedRows();
    int pos = 0;
    QStandardItemModel* eventHideModel = (QStandardItemModel*)ui->lstEventHide->model();
    QStandardItemModel* eventShowModel = (QStandardItemModel*)ui->lstEventShow->model();
    while( !mySelection.empty() )
    {
        pos = mySelection.first().row();
        QStandardItem * myItem = eventHideModel->takeItem( pos );
        eventHideModel->removeRow( pos );
        eventShowModel->appendRow( myItem );
        mySelection = ui->lstEventHide->selectionModel()->selectedRows();
    }
    eventShowModel->sort(0);
    //#]
}

void DataViewFilterGeneration::eventAddAll()
{
    //#[ operation eventAddAll()
    QStandardItemModel* eventHideModel = (QStandardItemModel*)ui->lstEventHide->model();
    QStandardItemModel* eventShowModel = (QStandardItemModel*)ui->lstEventShow->model();
    while( eventHideModel->rowCount() > 0 )
    {
        QStandardItem * myItem = eventHideModel->takeItem( 0 );
        eventHideModel->removeRow( 0 );
        eventShowModel->appendRow( myItem );
    }
    eventShowModel->sort(0);
    //#]
}

void DataViewFilterGeneration::eventDel()
{
    //#[ operation eventDel()
    QModelIndexList mySelection = ui->lstEventShow->selectionModel()->selectedRows();
    int pos = 0;
    QStandardItemModel* eventHideModel = (QStandardItemModel*)ui->lstEventHide->model();
    QStandardItemModel* eventShowModel = (QStandardItemModel*)ui->lstEventShow->model();
    while( !mySelection.empty() )
    {
        pos = mySelection.first().row();
        QStandardItem * myItem = eventShowModel->takeItem( pos );
        eventShowModel->removeRow( pos );
        eventHideModel->appendRow( myItem );
        mySelection = ui->lstEventShow->selectionModel()->selectedRows();
    }
    eventHideModel->sort(0);
    //#]
}

void DataViewFilterGeneration::eventDelAll()
{
    //#[ operation eventDelAll()
    QStandardItemModel* eventHideModel = (QStandardItemModel*)ui->lstEventHide->model();
    QStandardItemModel* eventShowModel = (QStandardItemModel*)ui->lstEventShow->model();
    while( eventShowModel->rowCount() > 0 )
    {
        QStandardItem * myItem = eventShowModel->takeItem( 0 );
        eventShowModel->removeRow( 0 );
        eventHideModel->appendRow( myItem );
    }
    eventHideModel->sort(0);
    //#]
}

void DataViewFilterGeneration::filterChanged()
{
    //#[ operation filterChanged()
    QModelIndex myIndex = ui->lstEventFilter->currentIndex();
    if( myIndex.isValid() )
    {    
        int rowNr = myIndex.row();
        ui->lstDestHide->setModel(destHideModelList.at(rowNr));
        ui->lstDestShow->setModel(destShowModelList.at(rowNr));
        ui->lstEventHide->setModel(eventHideModelList.at(rowNr));
        ui->lstEventShow->setModel(eventShowModelList.at(rowNr));
        ui->lstSourceHide->setModel(sourceHideModelList.at(rowNr));
        ui->lstSourceShow->setModel(sourceShowModelList.at(rowNr));
    
        ui->CBX_EventFilter->setChecked( eventFilterActiveList.at(rowNr) );
        ui->CBX_DestinationFilter->setChecked( destFilterActiveList.at(rowNr) );
        ui->CBX_SourceFilter->setChecked(  sourceFilterActiveList.at(rowNr) );
    }
    //#]
}

void DataViewFilterGeneration::newFilter()
{
    //#[ operation newFilter()
    QStandardItem *myNewFilterItem = new QStandardItem( "Filter " + QString::number(eventFilterModel->rowCount()) );
    
    QStandardItemModel *destHideModel = new QStandardItemModel();
    QStandardItemModel *destShowModel = new QStandardItemModel();
    QStandardItemModel *eventHideModel = new QStandardItemModel();
    QStandardItemModel *eventShowModel = new QStandardItemModel();
    QStandardItemModel *sourceHideModel = new QStandardItemModel();
    QStandardItemModel *sourceShowModel = new QStandardItemModel();
    
    destHideModelList.append( destHideModel );
    destShowModelList.append( destShowModel );
    eventHideModelList.append( eventHideModel );
    eventShowModelList.append( eventShowModel );
    sourceHideModelList.append( sourceHideModel );
    sourceShowModelList.append( sourceShowModel );
    
    destFilterActiveList.append(false);
    sourceFilterActiveList.append(false);
    eventFilterActiveList.append(false);
    
    ui->lstDestHide->setModel( destHideModel );
    ui->lstDestShow->setModel( destShowModel );
    ui->lstEventHide->setModel( eventHideModel );
    ui->lstEventShow->setModel( eventShowModel );
    ui->lstSourceHide->setModel( sourceHideModel );
    ui->lstSourceShow->setModel( sourceShowModel );
    
    foreach(TargetInformation *myTarget, itsParentCommandList->getItsTargetList()->getTargetList() )
    {
        for( auto myClass : myTarget->getModelClassList() )
        {
            for( auto myInstance : myClass->getInstanceList() )
            {
                if(myClass->getIsReactive() )
                {
                    QStandardItem *myNewDestItem = new QStandardItem( myTarget->getName() + "." + myInstance->getName() );
                    myNewDestItem->setData((uint)myInstance, Qt::UserRole );
                    destShowModel->appendRow(myNewDestItem);
                }
                QStandardItem *myNewSourceItem = new QStandardItem( myTarget->getName() + "." + myInstance->getName() );
                myNewSourceItem->setData((uint)myInstance, Qt::UserRole );
                sourceShowModel->appendRow(myNewSourceItem);
            }
        }
        for( auto myEvent : myTarget->getModelEventTypeList() )
        {
            QStandardItem *myNeweventItem = new QStandardItem( myTarget->getName() + "." + myEvent->getName() );
            myNeweventItem->setData((uint)myEvent, Qt::UserRole );
            eventShowModel->appendRow(myNeweventItem);
        }
    }
    
    eventFilterModel->appendRow( myNewFilterItem );
    ui->lstEventFilter->setCurrentIndex(myNewFilterItem->index());
    
    ui->CBX_DestinationFilter->setCheckState(Qt::Unchecked);
    ui->CBX_SourceFilter->setCheckState(Qt::Unchecked);
    ui->CBX_EventFilter->setCheckState(Qt::Unchecked);
    //#]
}

void DataViewFilterGeneration::reject()
{
    //#[ operation reject()
    this->hide();
    //#]
}

void DataViewFilterGeneration::removeFilter()
{
    //#[ operation removeFilter()
    if( !ui->lstEventFilter->currentIndex().isValid() )
    {
        return;
    }
    int rowNr = ui->lstEventFilter->currentIndex().row();
    eventFilterModel->removeRow( rowNr );
    destFilterActiveList.removeAt( rowNr );
    sourceFilterActiveList.removeAt( rowNr );
    eventFilterActiveList.removeAt( rowNr );
    
    delete sourceHideModelList.takeAt( rowNr );
    delete sourceShowModelList.takeAt( rowNr );
    delete destHideModelList.takeAt( rowNr );
    delete destShowModelList.takeAt( rowNr );
    delete eventHideModelList.takeAt( rowNr );
    delete eventShowModelList.takeAt( rowNr );
    //#]
}

void DataViewFilterGeneration::showWindow(CommandList* parentList)
{
    //#[ operation showWindow(CommandList)
    mode = newFilterMode;
    itsParentCommandList = parentList;
    
    //Reset all Checkboxes
    ui->CBX_DestinationFilter->setChecked( false );
    ui->CBX_SourceFilter->setChecked( false );
    ui->CBX_EventFilter->setChecked( false );
    ui->CBX_BufferOverflow->setChecked( true );
    ui->CBX_ConstructorCalls->setChecked( true );
    ui->CBX_ErrorHanlder->setChecked( true );
    ui->CBX_DestructorCalls->setChecked( true );
    ui->CBX_TickRange->setChecked( false );
    ui->CBX_TargetFilter->setChecked( false );
    
    //Reset Tick Range
    ui->SB_tickMax->setValue(1000);
    ui->SB_tickMin->setValue(0);
    
    //Reset Filtername
    ui->txtFilterName->setText("newFilter");
    
    //Clear userInterface
    ui->lstDestHide->setModel( NULL );
    ui->lstDestShow->setModel( NULL );
    
    ui->lstSourceHide->setModel( NULL );
    ui->lstSourceShow->setModel( NULL );
    
    ui->lstEventHide->setModel( NULL );
    ui->lstEventShow->setModel( NULL );
    
    ui->lstDestHide->setEnabled( false );
    ui->lstDestShow->setEnabled( false );
    
    ui->lstSourceHide->setEnabled( false );
    ui->lstSourceShow->setEnabled( false );
    
    ui->lstEventHide->setEnabled( false );
    ui->lstEventShow->setEnabled( false );
    
    //Clear temporary Container
    eventFilterModel->clear();
    ui->lstEventFilter->setModel( eventFilterModel );
    destFilterActiveList.clear();
    sourceFilterActiveList.clear();
    eventFilterActiveList.clear();
    
    sourceHideModelList.clear();
    sourceShowModelList.clear();
    destHideModelList.clear();
    destShowModelList.clear();
    eventHideModelList.clear();
    eventShowModelList.clear();
    
    targetFilterModel->clear();
    
    //Add all available Targets to Target Filter
    foreach( TargetInformation *aTarget , itsParentCommandList->getItsTargetList()->getTargetList() )
    {
        QStandardItem *aItem = new QStandardItem( aTarget->getName() );
        aItem->setCheckable( true );
        aItem->setCheckState( Qt::Checked );
        aItem->setData( QVariant((uint) aTarget), Qt::UserRole );
        targetFilterModel->appendRow(aItem);
    }
    ui->lstTargetFilter->setModel(targetFilterModel);
    
    show();
    //#]
}

void DataViewFilterGeneration::sourceAdd()
{
    //#[ operation sourceAdd()
    QStandardItemModel* sourceHideModel = (QStandardItemModel*)ui->lstSourceHide->model();
    QStandardItemModel* sourceShowModel = (QStandardItemModel*)ui->lstSourceShow->model();
    QModelIndexList mySelection = ui->lstSourceHide->selectionModel()->selectedRows();
    int pos = 0;
    while( !mySelection.empty() )
    {
        pos = mySelection.first().row();
        QStandardItem * myItem = sourceHideModel->takeItem( pos );
        sourceHideModel->removeRow( pos );
        sourceShowModel->appendRow( myItem );
        mySelection = ui->lstSourceHide->selectionModel()->selectedRows();
    }
    sourceShowModel->sort(0);
    //#]
}

void DataViewFilterGeneration::sourceAddAll()
{
    //#[ operation sourceAddAll()
    QStandardItemModel* sourceHideModel = (QStandardItemModel*)ui->lstSourceHide->model();
    QStandardItemModel* sourceShowModel = (QStandardItemModel*)ui->lstSourceShow->model();
    while( sourceHideModel->rowCount() > 0 )
    {
        QStandardItem * myItem = sourceHideModel->takeItem( 0 );
        sourceHideModel->removeRow( 0 );
        sourceShowModel->appendRow( myItem );
    }
    sourceShowModel->sort(0);
    //#]
}

void DataViewFilterGeneration::sourceDel()
{
    //#[ operation sourceDel()
    QStandardItemModel* sourceHideModel = (QStandardItemModel*)ui->lstSourceHide->model();
    QStandardItemModel* sourceShowModel = (QStandardItemModel*)ui->lstSourceShow->model();
    QModelIndexList mySelection = ui->lstSourceShow->selectionModel()->selectedRows();
    int pos = 0;
    while( !mySelection.empty() )
    {
        pos = mySelection.first().row();
        QStandardItem * myItem = sourceShowModel->takeItem( pos );
        sourceShowModel->removeRow( pos );
        sourceHideModel->appendRow( myItem );
        mySelection = ui->lstSourceShow->selectionModel()->selectedRows();
    }
    sourceHideModel->sort(0);
    //#]
}

void DataViewFilterGeneration::sourceDelAll()
{
    //#[ operation sourceDelAll()
    QStandardItemModel* sourceHideModel = (QStandardItemModel*)ui->lstSourceHide->model();
    QStandardItemModel* sourceShowModel = (QStandardItemModel*)ui->lstSourceShow->model();
    while( sourceShowModel->rowCount() > 0 )
    {
        QStandardItem * myItem = sourceShowModel->takeItem( 0 );
        sourceShowModel->removeRow( 0 );
        sourceHideModel->appendRow( myItem );
    }
    sourceHideModel->sort(0);
    //#]
}

void DataViewFilterGeneration::addFilterPartsToUiList(CommandListFilter* filter, TargetList* targetList)
{
    //#[ operation addFilterPartsToUiList(CommandListFilter,TargetList)
    eventFilterModel->clear();
    destHideModelList.clear();
    destShowModelList.clear();
    sourceHideModelList.clear();
    sourceShowModelList.clear();
    eventHideModelList.clear();
    eventShowModelList.clear();
    targetFilterModel->clear();
    
    //TargetFilterList
    
    foreach(auto targetFilter ,filter->getItsTargetFilterList())
    {
        QStandardItem *myTargetItem = new QStandardItem( targetFilter->first->getName() );
        myTargetItem->setCheckable( true );
        if( targetFilter->second )
        {
            myTargetItem->setCheckState( Qt::Checked );
        }
        else
        {
            myTargetItem->setCheckState( Qt::Unchecked );
        }
        myTargetItem->setData((uint)targetFilter->first, Qt::UserRole );
        targetFilterModel->appendRow( myTargetItem );
    }
    foreach(TargetInformation *myTarget, targetList->getTargetList() )
    {
        bool found = false;
        foreach(auto targetFilter ,filter->getItsTargetFilterList())
        {
            if( targetFilter->first == myTarget )
            {
                found = true;
                break;
            }
        }
        if( !found )
        {
            QStandardItem *myTargetItem = new QStandardItem( myTarget->getName() );
            myTargetItem->setCheckable( true );
            myTargetItem->setCheckState( Qt::Checked );
            myTargetItem->setData((uint)myTarget, Qt::UserRole );
            targetFilterModel->appendRow( myTargetItem );
        }
    }
    
    //Filter Parts -> Source, Destination and Events
    int i = 0;
    for( auto myFilterPart : filter->getFilterPartList() )
    {
        if( myFilterPart->getEventFilterActive() == FilterPart::BlackList ||
            myFilterPart->getEventFilterActive() == FilterPart::WhiteList )
        {
            eventFilterActiveList.append(true);
        }
        else
        {
            eventFilterActiveList.append(false);
        }
    
        if( myFilterPart->getSourceFilterActive() == FilterPart::BlackList ||
            myFilterPart->getSourceFilterActive() == FilterPart::WhiteList )
        {
            sourceFilterActiveList.append(true);
        }
        else
        {
            sourceFilterActiveList.append(false);
        }
    
        if( myFilterPart->getDestinationFilterActive() == FilterPart::BlackList ||
            myFilterPart->getDestinationFilterActive() == FilterPart::WhiteList )
        {
            destFilterActiveList.append(true);
        }
        else
        {
            destFilterActiveList.append(false);
        }
    
        eventFilterModel->appendRow( new QStandardItem("Filter " + QString::number( i ) ));
        QStandardItemModel *myDestHideModel = new QStandardItemModel();
        QStandardItemModel *myDestShowModel = new QStandardItemModel();
    
        QStandardItemModel *mySourceHideModel = new QStandardItemModel();
        QStandardItemModel *mySourceShowModel = new QStandardItemModel();
    
        QStandardItemModel *myEventHideModel = new QStandardItemModel();
        QStandardItemModel *myEventShowModel = new QStandardItemModel();
    
        //Search all Instances
        foreach(TargetInformation *myTarget, targetList->getTargetList() )
        {
            //Add Events to List
            for( ModelEventType* myEvent : myTarget->getModelEventTypeList() )
            {
                QString eventName;
                if( myTarget->getSingleTarget() )
                {
                    eventName = myEvent->getName();
                }
                else
                {
                    eventName = myTarget->getName() + "." + myEvent->getName();
                }
                QStandardItem *myEventItem = new QStandardItem( eventName );
                myEventItem->setData((uint)myEvent, Qt::UserRole );
                //If Black List
                if( myFilterPart->getEventFilterActive() == FilterPart::BlackList )
                {
                    bool eventFound = false;
                    foreach( auto myFilterEvent ,myFilterPart->getItsEventFilterList() )
                    {
                        if( myEvent == myFilterEvent )
                        {
                            eventFound = true;
                            myEventHideModel->appendRow( myEventItem );
                            break;
                        }
                    }
                    if( !eventFound )
                    {
                        myEventShowModel->appendRow( myEventItem );
                    }
                }
                //If White List
                else if( myFilterPart->getEventFilterActive() == FilterPart::WhiteList )
                {
                    bool eventFound = false;
                    foreach( auto myFilterEvent , myFilterPart->getItsEventFilterList() )
                    {
                        if( myEvent == myFilterEvent )
                        {
                            eventFound = true;
                            myEventShowModel->appendRow( myEventItem );
                            break;
                        }
                    }
                    if( !eventFound )
                    {
                        myEventHideModel->appendRow( myEventItem );
                    }
                }
                //If not Filter put all to Hide
                else
                {
                    myEventShowModel->appendRow( myEventItem );
                }
            }
            for( ModelClass* myClass : myTarget->getModelClassList() )
            {
                for( ModelInstance* myInstance : myClass->getInstanceList() )
                {
                    QString instanceName;
                    if( myTarget->getSingleTarget() )
                    {
                        instanceName = myInstance->getName();
                    }
                    else
                    {
                        instanceName = myTarget->getName() + "." + myInstance->getName();
                    }
    
    
                    //Update Destination Filter
                    if( myClass->getIsReactive() )
                    {
                        QStandardItem *myInstanceItemDest = new QStandardItem( instanceName );
                        myInstanceItemDest->setData((uint)myInstance, Qt::UserRole );
                        //If Black List
                        if( myFilterPart->getDestinationFilterActive() == FilterPart::BlackList )
                        {
                            bool destFound = false;
                            foreach( auto myFilterInstance , myFilterPart->getItsDestinationFilterList() )
                            {
                                if( myInstance == myFilterInstance )
                                {
                                    destFound = true;
                                    myDestHideModel->appendRow( myInstanceItemDest );
                                    break;
                                }
                            }
                            if( !destFound )
                            {
                                myDestShowModel->appendRow( myInstanceItemDest );
                            }
                        }
                        //If White List
                        else if( myFilterPart->getDestinationFilterActive() == FilterPart::WhiteList )
                        {
                            bool destFound = false;
                            foreach( auto myFilterInstance , myFilterPart->getItsDestinationFilterList() )
                            {
                                if( myInstance == myFilterInstance )
                                {
                                    destFound = true;
                                    myDestShowModel->appendRow( myInstanceItemDest );
                                    break;
                                }
                            }
                            if( !destFound )
                            {
                                myDestHideModel->appendRow( myInstanceItemDest );
                            }
                        }
                        //If not Filter put all to Hide
                        else
                        {
                            myDestShowModel->appendRow( myInstanceItemDest );
                        }
                    }
    
                    // add Source Filter
                    QStandardItem *myInstanceItemSource = new QStandardItem( instanceName );
                    myInstanceItemSource->setData((uint)myInstance, Qt::UserRole );
                    //If Black List
                    if( myFilterPart->getSourceFilterActive() == FilterPart::BlackList )
                    {
                        bool sourceFound = false;
                        foreach( auto myFilterInstance , myFilterPart->getItsSourceFilterList() )
                        {
                            if( myInstance == myFilterInstance )
                            {
                                sourceFound = true;
                                mySourceHideModel->appendRow( myInstanceItemSource );
                                break;
                            }
                        }
                        if( !sourceFound )
                        {
                            mySourceShowModel->appendRow( myInstanceItemSource );
                        }
                    }
                    //If White List
                    else if( myFilterPart->getSourceFilterActive() == FilterPart::WhiteList )
                    {
                        bool sourceFound = false;
                        foreach( auto myFilterInstance , myFilterPart->getItsSourceFilterList() )
                        {
                            if( myInstance == myFilterInstance )
                            {
                                sourceFound = true;
                                mySourceShowModel->appendRow( myInstanceItemSource );
                                break;
                            }
                        }
                        if( !sourceFound )
                        {
                            mySourceHideModel->appendRow( myInstanceItemSource );
                        }
                    }
                    //If not Filter put all to Hide
                    else
                    {
                        mySourceHideModel->appendRow( myInstanceItemSource );
                    }
                }
            }
        }
        destHideModelList.append(myDestHideModel);
        destShowModelList.append(myDestShowModel);
    
        sourceHideModelList.append(mySourceHideModel);
        sourceShowModelList.append(mySourceShowModel);
    
        eventHideModelList.append(myEventHideModel);
        eventShowModelList.append(myEventShowModel);
        i++;
    }
    //#]
}

void DataViewFilterGeneration::addUiPartsToFilter(CommandListFilter* filter)
{
    //#[ operation addUiPartsToFilter(CommandListFilter)
    for( int i = 0; i < eventFilterModel->rowCount(); i++ )
    {
        FilterPart *newFilterPart = new FilterPart();
        filter->addFilterPart( newFilterPart );
        //Check if Dest Filter is Active
        if( destFilterActiveList.at(i) )
        {
            if( destHideModelList.at( i )->rowCount() > destShowModelList.at( i )->rowCount() )
            {
                newFilterPart->setDestinationFilterActive( FilterPart::WhiteList );
                for(int j = 0; j < destShowModelList.at( i )->rowCount(); j++)
                {
                    newFilterPart->addItsDestinationFilterList( (ModelInstance*)destShowModelList.at( i )->item( j )->data(Qt::UserRole).toUInt() );
                }
            }
            else
            {
                newFilterPart->setDestinationFilterActive( FilterPart::BlackList );
                for(int j = 0; j < destHideModelList.at( i )->rowCount(); j++)
                {
                    newFilterPart->addItsDestinationFilterList( (ModelInstance*)destHideModelList.at( i )->item( j )->data(Qt::UserRole).toUInt() );
                }
            }
        }
        else
        {
            newFilterPart->setDestinationFilterActive( FilterPart::NoFilter );
        }
    
    
        //Check if Source Filter is Active
        if( sourceFilterActiveList.at(i) )
        {
            if( sourceHideModelList.at( i )->rowCount() > sourceShowModelList.at( i )->rowCount() )
            {
                newFilterPart->setSourceFilterActive( FilterPart::WhiteList );
                for(int j = 0; j < sourceShowModelList.at( i )->rowCount(); j++)
                {
                    newFilterPart->addItsSourceFilterList( (ModelInstance*)sourceShowModelList.at( i )->item( j )->data(Qt::UserRole).toUInt() );
                }
            }
            else
            {
                newFilterPart->setSourceFilterActive( FilterPart::BlackList );
                for(int j = 0; j < sourceHideModelList.at( i )->rowCount(); j++)
                {
                    newFilterPart->addItsSourceFilterList( (ModelInstance*)sourceHideModelList.at( i )->item( j )->data(Qt::UserRole).toUInt() );
                }
            }
        }
        else
        {
            newFilterPart->setSourceFilterActive( FilterPart::NoFilter );
        }
    
        //Check if Event Filter is Active
        if( eventFilterActiveList.at(i) )
        {
            if( eventHideModelList.at( i )->rowCount() > eventShowModelList.at( i )->rowCount() )
            {
                newFilterPart->setEventFilterActive( FilterPart::WhiteList );
                for(int j = 0; j < eventShowModelList.at( i )->rowCount(); j++)
                {
                    newFilterPart->addItsEventFilterList( (ModelEventType*)eventShowModelList.at( i )->item( j )->data(Qt::UserRole).toUInt() );
                }
            }
            else
            {
                newFilterPart->setEventFilterActive( FilterPart::BlackList );
                for(int j = 0; j < eventHideModelList.at( i )->rowCount(); j++)
                {
                    newFilterPart->addItsEventFilterList( (ModelEventType*)eventHideModelList.at( i )->item( j )->data(Qt::UserRole).toUInt() );
                }
            }
        }
        else
        {
            newFilterPart->setEventFilterActive( FilterPart::NoFilter );
        }
    }
    //#]
}

void DataViewFilterGeneration::addUiTargesToFilter(CommandListFilter* filter)
{
    //#[ operation addUiTargesToFilter(CommandListFilter)
    for( int i = 0; i < targetFilterModel->rowCount(); i++ )
    {
        TargetInformation *aTarget = (TargetInformation*)targetFilterModel->item( i )->data(Qt::UserRole).toInt();
        if( targetFilterModel->item( i )->checkState() == Qt::Checked )
        {
            filter->addTargetFilter( new QPair<TargetInformation*,bool>(aTarget, true) );
        }
        else
        {
            filter->addTargetFilter( new QPair<TargetInformation*,bool>(aTarget, false) );
        }
    }
    //#]
}

void DataViewFilterGeneration::connectSignals()
{
    //#[ operation connectSignals()
    connect(ui->CBX_DestinationFilter, SIGNAL(toggled(bool)), this, SLOT(activateDestinationFilter(bool)) );
    connect(ui->CBX_SourceFilter, SIGNAL(toggled(bool)), this, SLOT(activateSourceFilter(bool)) );
    connect(ui->CBX_EventFilter, SIGNAL(toggled(bool)), this, SLOT(activateEventFilter(bool)) );
    
    connect(ui->btnDestDelAll, SIGNAL( released() ), this, SLOT(destDelAll()) );
    connect(ui->btnDestDel, SIGNAL( released() ), this, SLOT(destDel()) );
    connect(ui->btnDestAddAll, SIGNAL( released() ), this, SLOT(destAddAll()) );
    connect(ui->btnDestAdd, SIGNAL( released() ), this, SLOT(destAdd()) );
    
    connect(ui->btnSourceDelAll, SIGNAL( released() ), this, SLOT(sourceDelAll()) );
    connect(ui->btnSourceDel, SIGNAL( released() ), this, SLOT(sourceDel()) );
    connect(ui->btnSourceAddAll, SIGNAL( released() ), this, SLOT(sourceAddAll()) );
    connect(ui->btnSourceAdd, SIGNAL( released() ), this, SLOT(sourceAdd()) );
    
    connect(ui->btnEventDelAll, SIGNAL( released() ), this, SLOT(eventDelAll()) );
    connect(ui->btnEventDel, SIGNAL( released() ), this, SLOT(eventDel()) );
    connect(ui->btnEventAddAll, SIGNAL( released() ), this, SLOT(eventAddAll()) );
    connect(ui->btnEventAdd, SIGNAL( released() ), this, SLOT(eventAdd()) );
    
    connect(ui->btnNewEventFilter, SIGNAL(released()), this, SLOT(newFilter()) );
    connect(ui->btnRemoveEventFilter, SIGNAL(released()), this, SLOT(removeFilter()) );
    
    connect(ui->btnFilterApply, SIGNAL(released()), this, SLOT( addFilter() ) );
    
    connect(this, SIGNAL(rejected()), this, SLOT( reject() ) );
    connect(ui->lstEventFilter->selectionModel(), SIGNAL(selectionChanged(QItemSelection,QItemSelection)), this, SLOT(filterChanged()) );
    //#]
}

void DataViewFilterGeneration::disconnectSignals()
{
    //#[ operation disconnectSignals()
    disconnect(ui->CBX_DestinationFilter, SIGNAL(toggled(bool)), this, SLOT(activateDestinationFilter(bool)) );
    disconnect(ui->CBX_SourceFilter, SIGNAL(toggled(bool)), this, SLOT(activateSourceFilter(bool)) );
    disconnect(ui->CBX_EventFilter, SIGNAL(toggled(bool)), this, SLOT(activateEventFilter(bool)) );
    
    disconnect(ui->btnDestDelAll, SIGNAL( released() ), this, SLOT(destDelAll()) );
    disconnect(ui->btnDestDel, SIGNAL( released() ), this, SLOT(destDel()) );
    disconnect(ui->btnDestAddAll, SIGNAL( released() ), this, SLOT(destAddAll()) );
    disconnect(ui->btnDestAdd, SIGNAL( released() ), this, SLOT(destAdd()) );
    
    disconnect(ui->btnSourceDelAll, SIGNAL( released() ), this, SLOT(sourceDelAll()) );
    disconnect(ui->btnSourceDel, SIGNAL( released() ), this, SLOT(sourceDel()) );
    disconnect(ui->btnSourceAddAll, SIGNAL( released() ), this, SLOT(sourceAddAll()) );
    disconnect(ui->btnSourceAdd, SIGNAL( released() ), this, SLOT(sourceAdd()) );
    
    disconnect(ui->btnEventDelAll, SIGNAL( released() ), this, SLOT(eventDelAll()) );
    disconnect(ui->btnEventDel, SIGNAL( released() ), this, SLOT(eventDel()) );
    disconnect(ui->btnEventAddAll, SIGNAL( released() ), this, SLOT(eventAddAll()) );
    disconnect(ui->btnEventAdd, SIGNAL( released() ), this, SLOT(eventAdd()) );
    
    disconnect(ui->btnNewEventFilter, SIGNAL(released()), this, SLOT(newFilter()) );
    disconnect(ui->btnRemoveEventFilter, SIGNAL(released()), this, SLOT(removeFilter()) );
    
    disconnect(ui->btnFilterApply, SIGNAL(released()), this, SLOT( addFilter() ) );
    
    disconnect(this, SIGNAL(rejected()), this, SLOT( reject() ) );
    disconnect(ui->lstEventFilter->selectionModel(), SIGNAL(selectionChanged(QItemSelection,QItemSelection)), this, SLOT(filterChanged()) );
    //#]
}

void DataViewFilterGeneration::cleanUpRelations()
{
    if(itsEditCommandList != NULL)
        {
            itsEditCommandList = NULL;
        }
    if(itsParentCommandList != NULL)
        {
            itsParentCommandList = NULL;
        }
    if(itsTargetInformationSingleTarget != NULL)
        {
            itsTargetInformationSingleTarget = NULL;
        }
}

/*********************************************************************
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\DataViewFilterGeneration.cpp
*********************************************************************/
