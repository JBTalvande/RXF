/********************************************************************
	Rhapsody	: 9.0.1 
	Login		: Y9DSYU706
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: EventInjection
//!	Generated Date	: Thu, 4, Nov 2021  
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\EventInjection.cpp
*********************************************************************/

#include "EventInjection.h"
#include "MainWindow.h"
#include "ModelEventArgumentType.h"
#include "ModelEventType.h"
#include "ModelInstance.h"
#include <QThread.h>
#include "Sender.h"
#include "TargetList.h"
#include "ui_EventInjection.h"
#include <QInputDialog>
#include <QTextStream>
//## package GUI

//## class EventInjection
EventInjection::EventInjection() : lastSelectedDestination(""), lastSelectedEvent(""), lastSelectedTarget(""), ui(new Ui::EventInjection)
{
    itsCurrentSequenceModel = NULL;
    itsEventHistodyModel = NULL;
    itsMainWindow = NULL;
    itsSender = NULL;
    //#[ operation EventInjection()
    ui->setupUi(this);
    lastSaveFile = "../../";
    lastLoadFile = "../../";
    itsCurrentSequenceModel = new QStandardItemModel();
    ui->currentSequenceList->setModel(itsCurrentSequenceModel);
    
    itsEventHistodyModel = new QStringListModel();
    ui->lstEventHistory->setModel(itsEventHistodyModel);
    
    ui->lstEventHistory->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->currentSequenceList->setEditTriggers(QAbstractItemView::NoEditTriggers);
    shortcut = new QShortcut(QKeySequence(Qt::Key_Delete), ui->currentSequenceList);
    connectSignals();
    //#]
}

EventInjection::~EventInjection()
{
    //#[ operation ~EventInjection()
    disconnectSignals();
    delete shortcut;
    //#]
    cleanUpRelations();
}

void EventInjection::addTimeDelayToSequence()
{
    //#[ operation addTimeDelayToSequence()
    QStandardItem *item = new QStandardItem("tm(" + ui->sbTimeDelay->text() +")");
    itsCurrentSequenceModel->appendRow(item);
    //#]
}

void EventInjection::addToSequence()
{
    //#[ operation addToSequence()
    
    // find eventType by name
    ModelEventType* eventType = *((ModelEventType**)ui->eventBox->currentData().data());
    TargetInformation* target = *((TargetInformation**)ui->targetBox->currentData().data());
    ModelInstance* instance = *((ModelInstance**)ui->instanceBox->currentData().data());
    
    QString parameter = "";
    if( eventType != NULL)
    {
        for( auto myEventArgument : eventType->getArguments() )
        {
            QString header = "Insert Parameter Value - " + eventType->getName();
            QString discription = "Please insert value for event parameter: " + myEventArgument->getName();
            QString val = QInputDialog::getText(NULL, tr(header.toStdString().c_str()),tr(discription.toStdString().c_str()));
    
            if(parameter.size()>0){
                parameter += "," + val;
            }
            else{
                parameter = val;
            }
        }
    }
    
    QStandardItem *myItem = new QStandardItem( ui->targetBox->currentText()+"."+ui->instanceBox->currentText()+"."+ui->eventBox->currentText()+"(" + parameter + ")");
    myItem->setData((uint)eventType, Qt::UserRole );
    myItem->setData((uint)target, Qt::UserRole + 1 );
    myItem->setData((uint)instance, Qt::UserRole + 2 );
    myItem->setData(parameter, Qt::UserRole + 3 );
    itsCurrentSequenceModel->appendRow( myItem );
    //#]
}

void EventInjection::clearEventHistory()
{
    //#[ operation clearEventHistory()
    itsEventHistodyModel->removeRows(0,itsEventHistodyModel->rowCount() );
    //#]
}

void EventInjection::eventInjection()
{
    //#[ operation eventInjection()
    static QList<ModelEventArgumentType*> pl;
    pl.clear();
    
    if( ui->targetBox->count() == 0)
    {
        return;
    }
    ModelEventType *eventType = *((ModelEventType**)ui->eventBox->currentData().data());
    TargetInformation* myTargetInfo = *((TargetInformation**)ui->targetBox->currentData().data());
    ModelInstance *instance = myTargetInfo->getInstance( ui->instanceBox->currentText() );
    
    bool inputOk = true;
    if( eventType != NULL && instance != NULL)
    {
        QString parameterVal = "";
        char eventParameterData[250];
        unsigned int eventParameterDataSize = 0;
    
        for( auto myEventArgument : eventType->getArguments() )
        {
            QString header = "Insert Parameter Value - " + eventType->getName();
            QString discription = "Please insert value for event parameter: " + eventType->getName();
    
            QString val = QInputDialog::getText(this, tr(header.toStdString().c_str()),tr(discription.toStdString().c_str()), QLineEdit::Normal, "", &inputOk);
            if(!inputOk) {
                break;
            }
    
            int iVal = 0;
            if(val.toLower().startsWith("0x"))
            {
                iVal = val.toInt(NULL,16);
            }
            else
            {
                iVal = val.toInt(NULL,10);
            }
            int argumentSize = myEventArgument->getType()->getSize();
            if( argumentSize > 4)
            {
                if( argumentSize % 4 != 0)
                {
                    eventParameterDataSize += 4 - ( argumentSize % 4 );
                }
            }
            else
            {
                if( eventParameterDataSize % argumentSize != 0 )
                {
                    eventParameterDataSize += argumentSize - ( eventParameterDataSize % argumentSize );
                }
            }
            if( ( eventParameterDataSize + argumentSize ) > 250 )
            {
                itsMainWindow->errorMsg("Can not inject Event. Problem with event argument size( " + QString::number(argumentSize) + " ).");
                return;
            }
            if( myTargetInfo->getEndianess() == LITTLE_ENDIAN )
            {
                for( int i = 0; i < myEventArgument->getType()->getSize(); i++ )
                {
                    eventParameterData[ eventParameterDataSize ] = (char)(iVal >>( i * 8 ));
                    eventParameterDataSize++;
                }
            }
            else
            {
                for( int i = myEventArgument->getType()->getSize() -1; i >=0 ; i-- )
                {
                    eventParameterData[ eventParameterDataSize ] = (char)(iVal >>( i * 8 ));
                    eventParameterDataSize++;
                }
            }
        }
        if(inputOk)
        {
            TargetInformation *myTarget = instance->getItsTargetInformation();
            itsSender->injectEvent( instance->getAddress(),eventType->getId(),eventParameterData,eventParameterDataSize, *myTarget);
            QStringList list;
            list = itsEventHistodyModel->stringList();
            list.append(myTarget->getName()+"."+instance->getName()+"."+eventType->getName()+"("+parameterVal+")");
            itsEventHistodyModel->setStringList(list);
        }
    }
    //#]
}

void EventInjection::injectSequence()
{
    //#[ operation injectSequence()
    // iterate through n entries of the sequence
    
    for( int i = 0; i < itsCurrentSequenceModel->rowCount(); i++)
    {
        if(itsCurrentSequenceModel->item( i )->text().startsWith("tm("))
        {
            QString time = itsCurrentSequenceModel->item( i )->text().replace("tm(","").replace(")","");
            QThread::msleep( time.toInt() );
        }
        // get model data from parsed information
        ModelEventType *eventType = *((ModelEventType **)itsCurrentSequenceModel->item( i )->data(Qt::UserRole).data());
        TargetInformation *target = *((TargetInformation **)itsCurrentSequenceModel->item( i )->data(Qt::UserRole + 1).data());
        ModelInstance *instance = *((ModelInstance **)itsCurrentSequenceModel->item( i )->data(Qt::UserRole + 2).data());
        QString parameter = itsCurrentSequenceModel->item( i )->data(Qt::UserRole + 3).toString();
        QStringList parameterList;
        if( parameter != "" )
        {
            parameterList = parameter.split(",");
        }
    
        // if eventType and instance exist
        if( target != NULL && eventType != NULL && instance != NULL )
        {
            const QVector<ModelEventArgumentType*> eventArguments = eventType->getArguments();
    
            // check, if argument size equals parameter list size
            if(eventArguments.size() == parameterList.size())
            {
                QString parameterVal = "";
                char eventParameterData[250];
                unsigned int eventParameterDataSize = 0;
    
                // iterate through eventArguments and get the parameter for each argument
                for( int parameterNumber = 0; parameterNumber < eventArguments.size(); ++parameterNumber )
                {
                    QString parameterValue = parameterList.at(parameterNumber);
                    const ModelEventArgumentType* myEventArgument = eventArguments.at(parameterNumber);
    
                    // get parameter value
                    int iVal = 0;
                    if( parameterValue.toLower().startsWith("0x") )
                    {
                        iVal = parameterValue.toInt(NULL,16);
                    }
                    else
                    {
                        iVal = parameterValue.toInt(NULL,10);
                    }
    
                    // get argument size and add it to the eventParameterDataSize
                    int argumentSize = myEventArgument->getType()->getSize();
                    if( argumentSize > 4)
                    {
                        if( argumentSize % 4 != 0)
                        {
                            eventParameterDataSize += 4 - ( argumentSize % 4 );
                        }
                    }
                    else
                    {
                        if( eventParameterDataSize % argumentSize != 0 )
                        {
                            eventParameterDataSize += argumentSize - ( eventParameterDataSize % argumentSize );
                        }
                    }
                    if( ( eventParameterDataSize + argumentSize ) > 250 )
                    {
                        itsMainWindow->errorMsg("Can not inject Event. Problem with event argument size( " + QString::number(argumentSize) + " ).");
                        return;
                    }
                    // pass arguments to eventParameterData due to the endian
                    if( target->getEndianess() == LITTLE_ENDIAN )
                    {
                        for( int i = 0; i < myEventArgument->getType()->getSize(); i++ )
                        {
                            eventParameterData[ eventParameterDataSize ] = (char)(iVal >>( i * 8 ));
                            eventParameterDataSize++;
                        }
                    }
                    else
                    {
                        for( int i = myEventArgument->getType()->getSize() -1; i >=0 ; i-- )
                        {
                            eventParameterData[ eventParameterDataSize ] = (char)(iVal >>( i * 8 ));
                            eventParameterDataSize++;
                        }
                    }
                }
                itsSender->injectEvent( instance->getAddress(),eventType->getId(),eventParameterData,eventParameterDataSize, *target);
                QStringList list;
                list = itsEventHistodyModel->stringList();
                list.append(target->getName()+"."+instance->getName()+"."+eventType->getName()+"("+parameterVal+")");
                itsEventHistodyModel->setStringList(list);
            }
            else
            {
                itsMainWindow->errorMsg("Event \"" + eventType->getName() + "\" uses incorrect count of arguments.");
            }
        }
    }
    //#]
}

void EventInjection::loadSequence()
{
    //#[ operation loadSequence()
    QString pathLoadFile=NULL;
    itsCurrentSequenceModel->clear();
    pathLoadFile = QFileDialog::getOpenFileName(NULL,tr("Open event sequence"), lastLoadFile, tr("Event Sequence File (*.esf)" ) );
    if(pathLoadFile!=NULL){
        lastLoadFile = pathLoadFile;
        QFile *file = new QFile(pathLoadFile);
        if(file->open(QIODevice::ReadOnly)){
            QTextStream fileStream (file);
            QString line;
            while(!fileStream.atEnd())
            {
                line = fileStream.readLine();
                if(line!="")
                {
                    QStringList data = line.split(".");
                    if( data.size() == 3)
                    {
                        TargetInformation *target = NULL;
                        QHash<int, TargetInformation*> &allTargets = TargetList::getGlobalList()->getTargetList();
                        foreach(TargetInformation * t, allTargets)
                        {
                            if( t->getName() == data[ 0 ] )
                            {
                                target = t;
                                itsMainWindow->errorMsg( "Couldnt find Target: " + data[ 0 ]);
                                break;
                            }
                        }
                        if( target == NULL )
                        {
                            continue;
                        }
                        ModelInstance *instance = target->getInstance( data[ 1 ] );
                        if( instance == NULL )
                        {
                            itsMainWindow->errorMsg( "Couldnt find instance: " + data[ 1 ] + "from Target: " + data[ 0 ]);
                            continue;
                        }
                        QStringList eventData = data[ 2 ].split("(");
                        const ModelEventType *event = NULL;
                        QString parameter = "";
                        if( eventData.size() == 2 )
                        {
                            event = target->getEventType( eventData[ 0 ] );
                            if( event == NULL )
                            {
                                itsMainWindow->errorMsg( "Couldnt find event: " + eventData[ 0 ] + "from Target: " + data[ 0 ]);
                                continue;
                            }
                            parameter = eventData[ 1 ].replace(")", "").trimmed();
                        }
                        else
                        {
                            itsMainWindow->errorMsg( "Event Data corrupt: " + data[ 2 ] + "from Target: " + data[ 0 ]);
                            continue;
                        }
    
                        QStandardItem *myItem = new QStandardItem( target->getName()+"."+instance->getName()+"."+event->getName()+"(" + parameter + ")");
                        myItem->setData((uint)event, Qt::UserRole );
                        myItem->setData((uint)target, Qt::UserRole + 1 );
                        myItem->setData((uint)instance, Qt::UserRole + 2 );
                        myItem->setData(parameter, Qt::UserRole + 3 );
                        itsCurrentSequenceModel->appendRow( myItem );
                    }
                }
            }
            file->close();
        }
    }
    //#]
}

void EventInjection::moveDown()
{
    //#[ operation moveDown()
    QModelIndex tmp = ui->currentSequenceList->currentIndex();
    if( tmp.isValid() && tmp.row() < (itsCurrentSequenceModel->rowCount() -1 ))
    {
        int myRow = tmp.row();
        QList<QStandardItem *> aItemList = itsCurrentSequenceModel->takeRow( myRow );
        itsCurrentSequenceModel->insertRow( myRow + 1, aItemList);
        ui->currentSequenceList->setCurrentIndex( aItemList.at(0)->index() );
    }
    //#]
}

void EventInjection::moveUp()
{
    //#[ operation moveUp()
    QModelIndex tmp = ui->currentSequenceList->currentIndex();
    if( tmp.isValid() && tmp.row() > 0 )
    {
        int myRow = tmp.row();
        QList<QStandardItem *> aItemList = itsCurrentSequenceModel->takeRow( myRow );
        itsCurrentSequenceModel->insertRow( myRow - 1, aItemList);
        ui->currentSequenceList->setCurrentIndex( aItemList.at(0)->index() );
    }
    //#]
}

void EventInjection::newInstanceCreated(ModelInstance* instance)
{
    //#[ operation newInstanceCreated(ModelInstance)
    ui->instanceBox->addItem(instance->getName());
    ui->instanceBox->model()->sort(0); // "A","B","C"
    //#]
}

void EventInjection::removeSelectedFromSequence()
{
    //#[ operation removeSelectedFromSequence()
    itsCurrentSequenceModel->removeRow(ui->currentSequenceList->currentIndex().row());
    //#]
}

void EventInjection::saveSequence()
{
    //#[ operation saveSequence()
    QString pathSaveFile=NULL;
    pathSaveFile = QFileDialog::getSaveFileName(NULL,tr("Save event sequence to..."), lastSaveFile, tr("Event Sequence File (*.esf)" ) );
    if(pathSaveFile!=NULL){
        lastSaveFile = pathSaveFile;
        QFile *file = new QFile(pathSaveFile);
        if(file->open(QIODevice::WriteOnly))
        {
            for(int i = 0; i < itsCurrentSequenceModel->rowCount(); i++ ){
                file->write( (itsCurrentSequenceModel->item( i )->text()+"\n").toStdString().c_str());
            }
            file->close();
        }
    }
    //#]
}

void EventInjection::showWindow()
{
    //#[ operation showWindow()
    updateElements();
    this->show();
    this->raise();
    //#]
}

void EventInjection::updateElements()
{
    //#[ operation updateElements()
    if(ui->eventBox->count() != 0 )
    {
        lastSelectedEvent = ui->eventBox->currentText();
    }
    if(ui->instanceBox->count() != 0 )
    {
        lastSelectedDestination = ui->instanceBox->currentText();
    }
    if( ui->targetBox->count() == 0 )
    {
    	ui->eventBox->clear();
    	ui->instanceBox->clear();
        return;
    }
    TargetInformation* myTargetInfo = *((TargetInformation**)ui->targetBox->currentData().data());
    ui->eventBox->clear();
    foreach( ModelEventType* myEventType, myTargetInfo->getModelEventTypeList() )
    {
        if( !( myEventType->isOperation() || myEventType->getName().compare("StartBehaviourEvent") == 0 || myEventType->getName().compare("TimeOutEvent") == 0 ) )
        {
            const QVariant itsEvent((uint)myEventType);
            ui->eventBox->addItem( myEventType->getName(),itsEvent );
        }
    }
    // sort
    ui->eventBox->model()->sort(0); // "A","B","C"
    ui->eventBox->setCurrentText(lastSelectedEvent);
    
    ui->instanceBox->clear();
    foreach( ModelClass* myClass, myTargetInfo->getModelClassList() )
    {
        if( myClass->getIsReactive() )
        {
            foreach( ModelInstance* myInstance, myClass->getInstanceList() )
            {
                const QVariant itsInstance((uint)myInstance);
                ui->instanceBox->addItem( myInstance->getName(),itsInstance );
            }
        }
    }
    // sort
    ui->instanceBox->model()->sort(0); // "A","B","C"
    ui->instanceBox->setCurrentText(lastSelectedDestination);
    //#]
}

void EventInjection::updateTargets()
{
    //#[ operation updateTargets()
    ui->targetBox->clear();
    foreach( TargetInformation* myTargetInformation, TargetList::getGlobalList()->getTargetList())
    {
        const QVariant itsTarget((uint)myTargetInformation);
        ui->targetBox->addItem( myTargetInformation->getName(),itsTarget);
    }
    // sort
    ui->targetBox->model()->sort(0); // "A","B","C"
    updateElements();
    //#]
}

void EventInjection::clear()
{
    //#[ operation clear()
    ui->instanceBox->clear();
    itsEventHistodyModel->removeRows(0,itsEventHistodyModel->rowCount() );
    //#]
}

void EventInjection::connectSignals()
{
    //#[ operation connectSignals()
    QObject::connect( ui->addToSequence, SIGNAL( clicked() ), this, SLOT( addToSequence() ) );
    QObject::connect( ui->btnDel, SIGNAL( clicked() ), this, SLOT( removeSelectedFromSequence() ) );
    QObject::connect( ui->btnUp, SIGNAL( clicked() ), this, SLOT( moveUp() ) );
    QObject::connect( ui->btnDown, SIGNAL( clicked() ), this, SLOT( moveDown() ) );
    QObject::connect( ui->btnSaveSequence, SIGNAL( clicked() ), this, SLOT( saveSequence() ) );
    QObject::connect( ui->btnLoadSequence, SIGNAL( clicked() ), this, SLOT( loadSequence() ) );
    QObject::connect( ui->btnEventInjection, SIGNAL( clicked() ), this, SLOT( eventInjection() ) );
    QObject::connect( ui->btnInjectSequence, SIGNAL( clicked() ), this, SLOT( injectSequence() ) );
    QObject::connect( ui->btnClearEventHistory, SIGNAL( clicked() ), this, SLOT( clearEventHistory() ) );
    QObject::connect( ui->targetBox, SIGNAL( currentIndexChanged(int) ), this, SLOT( updateElements() ) );
    QObject::connect( ui->btnAddTimeDelay, SIGNAL( clicked() ), this, SLOT( addTimeDelayToSequence() ) );
    QObject::connect(shortcut, SIGNAL(activated()), this, SLOT(removeSelectedFromSequence()));
    
    
    //#]
}

void EventInjection::disconnectSignals()
{
    //#[ operation disconnectSignals()
    QObject::disconnect( ui->addToSequence, SIGNAL( clicked() ), this, SLOT( addToSequence() ) );
    QObject::disconnect( ui->btnDel, SIGNAL( clicked() ), this, SLOT( removeSelectedFromSequence() ) );
    QObject::disconnect( ui->btnUp, SIGNAL( clicked() ), this, SLOT( moveUp() ) );
    QObject::disconnect( ui->btnDown, SIGNAL( clicked() ), this, SLOT( moveDown() ) );
    QObject::disconnect( ui->btnSaveSequence, SIGNAL( clicked() ), this, SLOT( saveSequence() ) );
    QObject::disconnect( ui->btnLoadSequence, SIGNAL( clicked() ), this, SLOT( loadSequence() ) );
    QObject::disconnect( ui->btnEventInjection, SIGNAL( clicked() ), this, SLOT( eventInjection() ) );
    QObject::disconnect( ui->btnInjectSequence, SIGNAL( clicked() ), this, SLOT( injectSequence() ) );
    QObject::disconnect( ui->targetBox, SIGNAL( currentIndexChanged(int) ), this, SLOT( updateElements() ) );
    QObject::disconnect( ui->btnAddTimeDelay, SIGNAL( clicked() ), this, SLOT( addTimeDelayToSequence() ) );
    QObject::disconnect( ui->btnClearEventHistory, SIGNAL( clicked() ), this, SLOT( clearEventHistory() ) );
    QObject::disconnect(shortcut, SIGNAL(activated()), this, SLOT(removeSelectedFromSequence()));
    //#]
}

void EventInjection::cleanUpRelations()
{
    if(itsCurrentSequenceModel != NULL)
        {
            itsCurrentSequenceModel = NULL;
        }
    if(itsEventHistodyModel != NULL)
        {
            itsEventHistodyModel = NULL;
        }
    if(itsMainWindow != NULL)
        {
            itsMainWindow = NULL;
        }
    if(itsSender != NULL)
        {
            itsSender = NULL;
        }
}

/*********************************************************************
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\EventInjection.cpp
*********************************************************************/
