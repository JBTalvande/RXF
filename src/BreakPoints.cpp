/********************************************************************
	Rhapsody	: 9.0.1 
	Login		: Y9DSYU706
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: BreakPoints
//!	Generated Date	: Thu, 4, Nov 2021  
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\BreakPoints.cpp
*********************************************************************/

#include "BreakPoints.h"
#include "ModelInstance.h"
#include "Sender.h"
#include "TargetInformation.h"
#include "TargetList.h"
#include "ui_BreakPoints.h"
//## package GUI

//## class BreakPoints
//## class BreakPoints::BreakPoint
BreakPoints::BreakPoint::BreakPoint(ModelInstance* instance, ModelEventType* event, ModelClassState* state)
{
    //#[ operation BreakPoint(ModelInstance,ModelEventType,ModelClassState)
    this->instance = instance;
    this->event = event;
    this->state = state;
    //#]
}

BreakPoints::BreakPoints() : ui(new Ui::BreakPoints), itsEventFreeBreakpoint("", 0, NULL), itsStateFreeBreakpoint(0, "")
{
    itsModelBreakpoints = NULL;
    itsSender = NULL;
    itsTargetInformation = NULL;
    //#[ operation BreakPoints()
    ui->setupUi(this);
    itsModelBreakpoints = new QStandardItemModel();
    ui->listBreakpoints->setModel(itsModelBreakpoints);
    connectSignals();
    //#]
}

BreakPoints::~BreakPoints()
{
    //#[ operation ~BreakPoints()
    disconnectSignals();
    //#]
    cleanUpRelations();
}

void BreakPoints::checkInsertPossible()
{
    //#[ operation checkInsertPossible()
    ui->insertBp->setEnabled(true);
    if(ui->instanceBox->count() == 0)
    {
        if(ui->eventBox->currentText() == "---" )
        {
            ui->insertBp->setEnabled(false);
        }
    }
    if(ui->stateBox->currentText() == "---" && ui->eventBox->currentText() == "---")
    {
        ui->insertBp->setEnabled(false);
    }
    //#]
}

void BreakPoints::classChanged()
{
    //#[ operation classChanged()
    ModelClass *myClass = *((ModelClass **)ui->classBox->currentData(Qt::UserRole).data());
    ui->instanceBox->clear();
    ui->stateBox->clear();
    if(myClass != NULL)
    {
        for( auto myInstance : myClass->getInstanceList() )
        {
            const QVariant myData((uint)myInstance);
            ui->instanceBox->addItem( myInstance->getName(), myData );
        }
    
        ui->stateBox->addItem("---");
        for( int i = 0; i <  myClass->getItsModelClassStateList()->size(); i++ )
        {
            const QVariant myData((uint)myClass->getItsModelClassStateList()->at(i));
            ui->stateBox->addItem( myClass->getItsModelClassStateList()->at(i)->getName(),myData );
        }
        ui->stateBox->model()->sort(0); // "A","B","C"
    }
    checkInsertPossible();
    //#]
}

void BreakPoints::insertBreakPoint()
{
    //#[ operation insertBreakPoint()
    addBreakpoint( *((ModelInstance**)ui->instanceBox->currentData(Qt::UserRole).data()), *((ModelEventType**)ui->eventBox->currentData(Qt::UserRole).data()), *((ModelClassState**)ui->stateBox->currentData(Qt::UserRole).data()) );
    //#]
}

void BreakPoints::removeAllBreakpoints()
{
    //#[ operation removeAllBreakpoints()
    while( itsModelBreakpoints->rowCount() > 0)
    {
        BreakPoint *breakpointToDelete = *((BreakPoint **)itsModelBreakpoints->item( 0 )->data( Qt::UserRole ).data());
        removeBreakpoint( breakpointToDelete );
        delete breakpointToDelete;
        itsModelBreakpoints->removeRow( 0 );
    }    
    //#]
}

void BreakPoints::removeSelectedBreakpoint()
{
    //#[ operation removeSelectedBreakpoint()
    if( itsModelBreakpoints->rowCount() == 0 )
    {
        return;
    }
    int zeile = ui->listBreakpoints->currentIndex().row();
    if( zeile == -1 )
    {
        return;
    }
    
    BreakPoint *breakpointToDelete = *((BreakPoint **)itsModelBreakpoints->item( zeile )->data( Qt::UserRole ).data());
    removeBreakpoint( breakpointToDelete );
    delete breakpointToDelete;
    itsModelBreakpoints->removeRow( zeile );
    //#]
}

void BreakPoints::showWindow()
{
    //#[ operation showWindow()
    classChanged();
    this->show();
    //#]
}

void BreakPoints::targetChanged()
{
    //#[ operation targetChanged()
    itsTargetInformation = *((TargetInformation**)ui->targetBox->currentData(Qt::UserRole).data());
    updateClasses();
    updateEvents();
    //#]
}

void BreakPoints::updateClasses()
{
    //#[ operation updateClasses()
    ui->classBox->clear();
    ui->classBox->addItem("---");
    
    foreach( auto myClass, this->itsTargetInformation->getModelClassList() )
    {
        if( myClass->getIsReactive() )
        {
            const QVariant myData( (uint)myClass );
            ui->classBox->addItem( myClass->getName(), myData );
        }
    }
    
    // sort
    ui->classBox->model()->sort(0); // "A","B","C"
    //#]
}

void BreakPoints::updateEvents()
{
    //#[ operation updateEvents()
    ui->eventBox->clear();
    ui->eventBox->addItem("---");
    ui->eventBox->addItem("TimeOutEvent");
    ui->eventBox->addItem("NullEvent");
    for( auto myEvent : this->itsTargetInformation->getModelEventTypeList() )
    {
        const QVariant myData( (uint)myEvent );
        ui->eventBox->addItem( myEvent->getName(), myData);
    }
    
    // sort
    ui->eventBox->model()->sort(0); // "A","B","C"
    //#]
}

void BreakPoints::updateTargets()
{
    //#[ operation updateTargets()
    QObject::disconnect( ui->targetBox, SIGNAL( currentIndexChanged(int) ), this, SLOT( targetChanged() ) );
    ui->targetBox->clear();
    foreach( TargetInformation* myTargetInformation, TargetList::getGlobalList()->getTargetList())
    {
        const QVariant itsTarget((uint)myTargetInformation);
        ui->targetBox->addItem(myTargetInformation->getName(),itsTarget);
    }
    // sort
    ui->targetBox->model()->sort(0); // "A","B","C"
    itsTargetInformation = *((TargetInformation**)ui->targetBox->currentData(Qt::UserRole).data());
    QObject::connect( ui->targetBox, SIGNAL( currentIndexChanged(int) ), this, SLOT( targetChanged() ) );
    updateClasses();
    updateEvents();
    //#]
}

void BreakPoints::addBreakpoint(ModelInstance* instance, ModelEventType* event, ModelClassState* state)
{
    //#[ operation addBreakpoint(ModelInstance,ModelEventType,ModelClassState)
    if( instance != NULL )
    {
        if( event == NULL )
        {
            event = &itsEventFreeBreakpoint;
        }
        if( state == NULL )
        {
            state = &itsStateFreeBreakpoint;
        }
        QStandardItem * myItem = new QStandardItem( instance->getName() + "." + state->getName() + "."+event->getName() );
        itsModelBreakpoints->insertRow(0,myItem);
    
        BreakPoint *myBreakpoint = new BreakPoint(instance,event,state);
        myItem->setData((uint)myBreakpoint, Qt::UserRole);
    
        itsSender->addBreakpoint( instance->getAddress(),state->getId(), event->getId(), *itsTargetInformation );
    }
    //#]
}

void BreakPoints::connectSignals()
{
    //#[ operation connectSignals()
    QObject::connect(ui->btnRemoveSelected,SIGNAL(clicked()),this, SLOT(removeSelectedBreakpoint()));
    QObject::connect(ui->btnRemoveAll,SIGNAL(clicked()),this, SLOT(removeAllBreakpoints()));
    
    QObject::connect( ui->classBox, SIGNAL( currentIndexChanged(int) ), this, SLOT( classChanged() ) );
    
    QObject::connect( ui->eventBox, SIGNAL( currentIndexChanged(int) ), this, SLOT( checkInsertPossible() ) );
    
    QObject::connect( ui->stateBox, SIGNAL( currentIndexChanged(int) ), this, SLOT( checkInsertPossible() ) );
    
    QObject::connect( ui->targetBox, SIGNAL( currentIndexChanged(int) ), this, SLOT( targetChanged() ) );
    
    QObject::connect( ui->insertBp, SIGNAL( clicked() ), this, SLOT( insertBreakPoint() ) );
    //#]
}

void BreakPoints::disconnectSignals()
{
    //#[ operation disconnectSignals()
    QObject::disconnect(ui->btnRemoveSelected,SIGNAL(clicked()),this, SLOT(removeSelectedBreakpoint()));
    QObject::disconnect(ui->btnRemoveAll,SIGNAL(clicked()),this, SLOT(removeAllBreakpoints()));
    
    QObject::disconnect( ui->classBox, SIGNAL( currentIndexChanged(int) ), this, SLOT( classChanged() ) );
    
    QObject::disconnect( ui->eventBox, SIGNAL( currentIndexChanged(int) ), this, SLOT( checkInsertPossible() ) );
    
    QObject::disconnect( ui->stateBox, SIGNAL( currentIndexChanged(int) ), this, SLOT( checkInsertPossible() ) );
    
    QObject::disconnect( ui->targetBox, SIGNAL( currentIndexChanged(int) ), this, SLOT( targetChanged() ) );
    
    QObject::disconnect( ui->insertBp, SIGNAL( clicked() ), this, SLOT( insertBreakPoint() ) );
    //#]
}

void BreakPoints::removeBreakpoint(BreakPoints::BreakPoint* breakPoint)
{
    //#[ operation removeBreakpoint(BreakPoint)
    itsSender->removeBreakpoint(breakPoint->getInstance()->getAddress(), breakPoint->getState()->getId(), breakPoint->getEvent()->getId(), *itsTargetInformation);
    //#]
}

void BreakPoints::cleanUpRelations()
{
    if(itsModelBreakpoints != NULL)
        {
            itsModelBreakpoints = NULL;
        }
    if(itsSender != NULL)
        {
            itsSender = NULL;
        }
    if(itsTargetInformation != NULL)
        {
            itsTargetInformation = NULL;
        }
}

/*********************************************************************
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\BreakPoints.cpp
*********************************************************************/
