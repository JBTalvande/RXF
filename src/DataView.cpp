/********************************************************************
	Rhapsody	: 9.0.1 
	Login		: Y9DSYU706
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: DataView
//!	Generated Date	: Thu, 4, Nov 2021  
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\DataView.cpp
*********************************************************************/

#include "DataView.h"
#include "CommandList.h"
#include "ui_DataView.h"
//## package GUI

//## class DataView
DataView::DataView(CommandList* commandList) : ui(new Ui::DataView)
{
    //#[ operation DataView(CommandList)
    ui->setupUi(this);
    itsSequenceDiagram.setItsRefreshCheckBox( ui->CBX_Refresh );
    itsSequenceDiagram.setItsVerticalScrollBar( ui->SDScrollBar );
    itsSequenceDiagram.setItsCommandList( commandList );
    ui->SDgraphicsView->setScene( &itsSequenceDiagram );
    itsSequenceDiagram.init();
    connectSignals();
    this->show();
    //#]
}

DataView::~DataView()
{
    //#[ operation ~DataView()
    disconnectSignals();
    //#]
}

void DataView::connectSignals()
{
    //#[ operation connectSignals()
    QObject::connect( ui->SDScrollBar, SIGNAL(valueChanged(int)), &this->itsSequenceDiagram, SLOT(setVerticalScrollBarValue()) );
    //#]
}

void DataView::disconnectSignals()
{
    //#[ operation disconnectSignals()
    QObject::disconnect( ui->SDScrollBar, SIGNAL(valueChanged(int)), &this->itsSequenceDiagram, SLOT(setVerticalScrollBarValue()) );
    //#]
}

/*********************************************************************
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\DataView.cpp
*********************************************************************/
