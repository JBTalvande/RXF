/********************************************************************
	Rhapsody	: 9.0.1 
	Login		: Y9DSYU706
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: SequenceDiagram
//!	Generated Date	: Thu, 4, Nov 2021  
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\SequenceDiagram.cpp
*********************************************************************/

#include "SequenceDiagram.h"
#include "CommandConstructor.h"
#include "CommandDestructor.h"
#include "CommandEventCreated.h"
#include "CommandEventEndDispatch.h"
#include "CommandEventStartDispatch.h"
#include "CommandIntVal.h"
#include "CommandList.h"
#include "CommandOperationCall.h"
#include "CommandTraceEvent.h"
#include "ModelEventArgumentType.h"
#include "ModelEventType.h"
#include "ModelInstance.h"
#include "ReceivedEventParameter.h"
#include <QGraphicsView>
#include <QGraphicsItem>
//## package GUI

//## class SequenceDiagram
bool SequenceDiagram::hideNonState;

unsigned int SequenceDiagram::printSessionNumber;

bool SequenceDiagram::showStateDelta;

SequenceDiagram::SequenceDiagram() : offset(0), scenePositionDragStart(-1), startCommand(0), verticalCommandSpace(20)
{
    itsCommandList = NULL;
    itsInstanceDragItem = NULL;
    itsRefreshCheckBox = NULL;
    itsVerticalScrollBar = NULL;
    itsView = NULL;
    //#[ operation SequenceDiagram()
    refreshTimer.singleShot(100,this, SLOT( reDraw()));
    //#]
}

SequenceDiagram::~SequenceDiagram()
{
    //#[ operation ~SequenceDiagram()
    refreshTimer.stop();
    //#]
    cleanUpRelations();
}

void SequenceDiagram::changeCommandList(QModelIndex modelIndex)
{
    //#[ operation changeCommandList(QModelIndex)
    QStandardItemModel *myModel = (QStandardItemModel*)modelIndex.model();
    CommandList *tmpList = (CommandList*)myModel->itemFromIndex(modelIndex);
    if( itsCommandList == tmpList || tmpList == NULL )
    {
        return;
    }
    if( itsCommandList != NULL )
    {
        itsCommandList->setCurrentCommandInSequenceDiagram( itsVerticalScrollBar->value() );
        setInactive(itsCommandList);
    }
    
    itsCommandList = NULL;
    setActive(tmpList);
    itsVerticalScrollBar->setValue( tmpList->getCurrentCommandInSequenceDiagram() );
    itsCommandList = tmpList;
    //#]
}

void SequenceDiagram::init()
{
    //#[ operation init()
    itsView = views().first();
    //#]
}

void SequenceDiagram::reDraw()
{
    //#[ operation reDraw()
    printSessionNumber++;
    if( itsCommandList == NULL || !itsView->isVisible() )
    {
        refreshTimer.singleShot(100,this, SLOT( reDraw()));
        return;
    }
    if( itsRefreshCheckBox->isChecked() )
    {
        int newValue = ( (int)itsCommandList->getCommandCounter() - ( this->views().first()->height() / 2 ) / verticalCommandSpace ) * verticalCommandSpace;
        if( newValue < 0)
        {
            newValue = 0;
        }
        itsVerticalScrollBar->setValue( newValue );
    }
    itsVerticalScrollBar->setMaximum( itsCommandList->getCommandCounter() * verticalCommandSpace );
    itsView->setUpdatesEnabled( false );
    
    for(int i=0;i<dynamicGraphicItems.size();i++){
        this->removeItem(dynamicGraphicItems.at(i));
        delete dynamicGraphicItems.at(i);
    }
    dynamicGraphicItems.clear();
    
    for( auto myInstanceItem : this->itsInstanceItemList )
    {
        myInstanceItem->setLastState( NULL );
    }
    drawCommands();
    
    int maxX = 0;
    for( auto myInstanceItem : this->itsInstanceItemList )
    {
        int xpos = myInstanceItem->getXPosition();
        myInstanceItem->setLastState( NULL );
        if( maxX < xpos )
        {
            maxX = xpos;
        }
    }
    
    
    itsView->setSceneRect(0,-40,maxX + 200,40);
    itsView->setUpdatesEnabled( true );
    itsView->repaint();
    
    refreshTimer.singleShot(50,this, SLOT( reDraw()));
    //#]
}

void SequenceDiagram::setItsCommandList(CommandList* commandList)
{
    //#[ operation setItsCommandList(CommandList)
    if( itsCommandList != NULL )
    {
        setInactive( itsCommandList );
    }
    itsCommandList = commandList;
    setActive( itsCommandList );
    //#]
}

void SequenceDiagram::setVerticalScrollBarValue()
{
    //#[ operation setVerticalScrollBarValue()
    startCommand = itsVerticalScrollBar->value() / verticalCommandSpace;
    offset = itsVerticalScrollBar->value() % verticalCommandSpace;
    //#]
}

void SequenceDiagram::updateInstanceLine(ModelInstance* instance, int pos)
{
    //#[ operation updateInstanceLine(ModelInstance,int)
    for( auto myInstanceItem : itsInstanceItemList )
    {
        if( myInstanceItem->getItsModelInstance() == instance )
        {
            myInstanceItem->setXPosition( pos );
            break;
        }
    }
    //#]
}

void SequenceDiagram::updateInstanceLines()
{
    //#[ operation updateInstanceLines()
    for( auto myInstanceItem : *itsCommandList->getItsInstanceXPositionList() )
    {
        updateInstanceLine( myInstanceItem->first, myInstanceItem->second );
    }
    //#]
}

void SequenceDiagram::mouseMoveEvent(QGraphicsSceneMouseEvent* mouseEvent)
{
    //#[ operation mouseMoveEvent(QGraphicsSceneMouseEvent)
    if( itsInstanceDragItem != NULL )
    {
        int newPos = instanceDragStart + ( mouseEvent->scenePos().x() - instanceDragStart );
        if( newPos < 0 )
        {
             newPos = 0;
        }
        itsInstanceDragItem->setXPosition( newPos );
        itsCommandList->updateSDInstanceXPosition( itsInstanceDragItem->getItsModelInstance(), newPos );
    }
    
    if( !dragItemList.isEmpty() )
    {
        int newPos;
        for( auto myInstanceItem : dragItemList )
        {
            newPos = myInstanceItem->second + ( mouseEvent->scenePos().x() - instanceDragStart );
            if( newPos < 0 )
            {
                 newPos = 0;
            }
            myInstanceItem->first->setXPosition( newPos );
            itsCommandList->updateSDInstanceXPosition( myInstanceItem->first->getItsModelInstance(), newPos );
        }
    }
    if( scenePositionDragStart != -1)
    {
        itsVerticalScrollBar->setValue( scenePositionDragStart - mouseEvent->scenePos().y() );
    }
    //#]
}

void SequenceDiagram::mousePressEvent(QGraphicsSceneMouseEvent* mouseEvent)
{
    //#[ operation mousePressEvent(QGraphicsSceneMouseEvent)
    if(mouseEvent->button() == Qt::LeftButton )
    {
        this->views().at(0)->setCursor( Qt::ClosedHandCursor );
        if( mouseEvent->scenePos().y() < 0 )
        {
            for( auto myInstanceItem : this->itsInstanceItemList )
            {
                if( myInstanceItem->getItsCommandList() == itsCommandList && myInstanceItem->isClicked( mouseEvent->scenePos().x() ) )
                {
                    itsInstanceDragItem = myInstanceItem;
                    instanceDragStart = myInstanceItem->getXPosition();
                    break;
                }
            }
        }
        else
        {
            itsRefreshCheckBox->setChecked( false );
            scenePositionDragStart = itsVerticalScrollBar->value() + mouseEvent->scenePos().y();
        }
    }
    else if(mouseEvent->button() == Qt::RightButton )
    {
        if( mouseEvent->scenePos().y() < 0 )
        {
            this->views().at(0)->setCursor( Qt::ClosedHandCursor );
            instanceDragStart = mouseEvent->scenePos().x();
            for( auto myInstanceItem : this->itsInstanceItemList )
            {
                if( myInstanceItem->getItsCommandList() == itsCommandList && ( myInstanceItem->isClicked( mouseEvent->scenePos().x() ) || myInstanceItem->getXPosition() > mouseEvent->scenePos().x() ) )
                {
                    dragItemList.append( new QPair<InstanceItemSeqenceDiagram*,int>( myInstanceItem,myInstanceItem->getXPosition())  );
                }
            }
        }
    }
    mouseEvent->accept();
    //#]
}

void SequenceDiagram::mouseReleaseEvent(QGraphicsSceneMouseEvent* mouseEvent)
{
    //#[ operation mouseReleaseEvent(QGraphicsSceneMouseEvent)
    itsInstanceDragItem = NULL;
    scenePositionDragStart = -1;
    this->views().at(0)->setCursor( Qt::OpenHandCursor );
    while( !dragItemList.empty() )
    {
        delete dragItemList.takeFirst();
    }
    mouseEvent->accept();
    //#]
}

void SequenceDiagram::wheelEvent(QGraphicsSceneWheelEvent* wheelEvent)
{
    //#[ operation wheelEvent(QGraphicsSceneWheelEvent)
    itsRefreshCheckBox->setChecked( false );
    if(wheelEvent->delta()>0)
    {
        itsVerticalScrollBar->setValue( itsVerticalScrollBar->value() - 10 );
    }
    else
    {
        itsVerticalScrollBar->setValue( itsVerticalScrollBar->value() + 10 );
    }
    //#]
}

void SequenceDiagram::drawCommands()
{
    //#[ operation drawCommands()
    unsigned int endPoint = ( startCommand + this->views().first()->height() / verticalCommandSpace ) ;
    QVector<Command*> commands = itsCommandList->getCommands();
    unsigned int positionCounter = 0;
    if( endPoint > itsCommandList->getCommandCounter() )
    {
        endPoint = itsCommandList->getCommandCounter();
    }
    selfMessageOpen = 0;
    for( unsigned int i = startCommand; i < endPoint; i++ )
    {
        Command* currentCommand = commands.at(i);
        switch( currentCommand->getCommandIdentifier() )
        {
            case Command::eventPutToMessageQueueCommand:
            {                
                printTrippleEvent( (CommandEventCreated*)currentCommand );
                break;
            }
            case Command::eventStartDispatchCommand:
            {
                CommandEventStartDispatch* myCommand = (CommandEventStartDispatch*)currentCommand;
                if( itsCommandList->getCommandDisplayNumberInSequenceDiagram( myCommand->getItsCommandEventCreated()->getDisplayNumber() ) < startCommand )
                {
                    printTrippleEvent( myCommand->getItsCommandEventCreated() );
                }
                break;
            }
            case Command::eventEndDispatchCommand:
            {
                CommandEventEndDispatch* myCommand = (CommandEventEndDispatch*)currentCommand;
                if( itsCommandList->getCommandDisplayNumberInSequenceDiagram( myCommand->getItsCommandEventStartDispatch()->getDisplayNumber() ) < startCommand )
                {
                    printTrippleEvent( myCommand->getItsCommandEventStartDispatch()->getItsCommandEventCreated() );
                }
                break;
            }
            case Command::constructorCommand:
            {
                printConstructor( (CommandConstructor*)currentCommand, i );
                break;
            }
            case Command::traceEventCommand:
            {
                printTraceEvent( (CommandTraceEvent*)currentCommand, i );
                break;
            }
            case Command::operationCalled:
            {
                printOperationCalled( (CommandOperationCall*)currentCommand, i );
                break;
            }
            case Command::errorHandlerReachedCommand:
            {
                printErrorHandlerReached( positionCounter );
                break;
            }
            case Command::bufferOverflowCommand:
            {
                printOperationBufferOverflow( positionCounter );
                break;
            }
            case Command::destructorCommand:
            {
                printDestructor( (CommandDestructor*)currentCommand, i );
                break;
            }
            case Command::debugIntValue:
            {
                printIntValue( (CommandIntVal*)currentCommand, i );
                break;
            }
        }
    
        positionCounter++;
    }
    selfMessageOpen = 0;
    //Finish event triplets which are not in View but go Through the view
    unsigned int endPointBehind = endPoint + 50 ;
    if( endPointBehind > itsCommandList->getCommandCounter() )
    {
        endPointBehind = itsCommandList->getCommandCounter();
    }
    for( unsigned int i = endPoint; i < endPointBehind; i++ )
    {
        Command* currentCommand = commands.at(i);
        switch( currentCommand->getCommandIdentifier() )
        {
            case Command::eventStartDispatchCommand:
            {
                CommandEventStartDispatch* myCommand = (CommandEventStartDispatch*)currentCommand;
                if( itsCommandList->getCommandDisplayNumberInSequenceDiagram( myCommand->getItsCommandEventCreated()->getDisplayNumber() ) < startCommand )
                {
                    printTrippleEvent( myCommand->getItsCommandEventCreated() );
                }
                break;
            }
            case Command::eventEndDispatchCommand:
            {
                CommandEventEndDispatch* myCommand = (CommandEventEndDispatch*)currentCommand;
                if( itsCommandList->getCommandDisplayNumberInSequenceDiagram( myCommand->getItsCommandEventStartDispatch()->getDisplayNumber() ) < startCommand )
                {
                    printTrippleEvent( myCommand->getItsCommandEventStartDispatch()->getItsCommandEventCreated() );
                }
                break;
            }
            default:
            {
                break;
            }
        }
        positionCounter++;
    }
    //#]
}

InstanceItemSeqenceDiagram* SequenceDiagram::getInstanceItem(ModelInstance* instance, QGraphicsScene* graphicScene)
{
    //#[ operation getInstanceItem(ModelInstance,QGraphicsScene)
    int maxX = 0;
    // try to find an existing InstanceItem with this modelInstance
    InstanceItemSeqenceDiagram *myInstance = NULL;
    InstanceItemSeqenceDiagram *instanceMostX = NULL;
    for( auto currentInstance : this->itsInstanceItemList )
    {
        if( currentInstance->getItsCommandList() == itsCommandList )
        {
            if( currentInstance->getItsModelInstance() == instance )
            {
                myInstance = currentInstance;
            }
            if( currentInstance->getXPosition() > maxX )
            {
                maxX = currentInstance->getXPosition();
                instanceMostX = currentInstance;
            }
        }
    }
    // if no InstanceItem was found for the given instance, create one
    if(myInstance == NULL)
    {
        int xPos = itsCommandList->getSDInstanceXPosition(instance);
        myInstance = new InstanceItemSeqenceDiagram( instance, graphicScene, itsCommandList, instanceMostX, xPos );
        if( xPos == -1 )
        {
            itsCommandList->addSDInstanceXPosition( instance, myInstance->getXPosition());
        }
        itsInstanceItemList.prepend(myInstance);
    }
    
    return myInstance;
    //#]
}

unsigned int SequenceDiagram::getInstancePosition(ModelInstance* instance, QGraphicsScene* graphicScene)
{
    //#[ operation getInstancePosition(ModelInstance,QGraphicsScene)
    int maxX = 0;
    // try to find an existing InstanceItem with this modelInstance
    InstanceItemSeqenceDiagram *myInstance = NULL;
    InstanceItemSeqenceDiagram *instanceMostX = NULL;
    for( auto currentInstance : this->itsInstanceItemList )
    {
        if( currentInstance->getItsCommandList() == itsCommandList )
        {
            if( currentInstance->getItsModelInstance() == instance )
            {
                myInstance = currentInstance;
            }
            if( currentInstance->getXPosition() > maxX )
            {
                maxX = currentInstance->getXPosition();
                instanceMostX = currentInstance;
            }
        }
    }
    // if no InstanceItem was found for the given instance, create one
    if(myInstance == NULL)
    {
        int xPos = itsCommandList->getSDInstanceXPosition(instance);
        myInstance = new InstanceItemSeqenceDiagram( instance, graphicScene, itsCommandList, instanceMostX, xPos );
        if( xPos == -1 )
        {
            itsCommandList->addSDInstanceXPosition( instance, myInstance->getXPosition());
        }
        itsInstanceItemList.prepend(myInstance);
    }
    
    return myInstance->getXPosition();
    //#]
}

QString SequenceDiagram::higliteStateDifference(const QString* lastState, const QString* newState)
{
    //#[ operation higliteStateDifference(QString,QString)
    QString myNewState = "";
    QStringList myLastStateList = lastState->split("|");
    QStringList myNewStateList = newState->split("|");
    for( int i = 0; i < myLastStateList.size() && i < myNewStateList.size(); i++ )
    {
        if( myLastStateList.at( i ).compare( myNewStateList.at( i ) ) == 0 )
        {
            myNewState += myNewStateList.at( i );
        }
        else
        {
            myNewState += "<b><font color=\"#FF00FF\">" + myNewStateList.at( i ) + "</font></b>";
        }
        if( ( i + 1 ) < myLastStateList.size() && ( i + 1 ) < myNewStateList.size())
        {
            myNewState += "|";
        }
    }
    return myNewState;
    //#]
}

void SequenceDiagram::printConstructor(CommandConstructor* constructorCall, int printPosition)
{
    //#[ operation printConstructor(CommandConstructor,int)
    int xPosition = getInstancePosition( constructorCall->getItsModelInstance(), this );
    int yPosition = verticalCommandSpace * ( printPosition - startCommand ) - offset;
    QGraphicsTextItem *myInitialisationText = addText("Initialisation", initialisationFont );
    myInitialisationText->setZValue( 50 );
    myInitialisationText->setPos( xPosition -myInitialisationText->boundingRect().width()/2, yPosition );
    dynamicGraphicItems.append( myInitialisationText );
    
    QRectF myRec = myInitialisationText->boundingRect();
    myRec.setHeight( myRec.height() - 5);
    myRec.setY( myRec.y() + 5);
    QGraphicsRectItem *myRectItem = addRect(myRec,transparentPen,constructorBrush);
    myRectItem->setPos(xPosition-myInitialisationText->boundingRect().width()/2,yPosition );
    myRectItem->setZValue( 49 );
    dynamicGraphicItems.append( myRectItem );
    //#]
}

void SequenceDiagram::printDestructor(CommandDestructor* destructorCall, int printPosition)
{
    //#[ operation printDestructor(CommandDestructor,int)
    int xPosition = getInstancePosition( destructorCall->getItsModelInstance(), this );
    int yPosition = verticalCommandSpace * ( printPosition - startCommand ) - offset;
    QGraphicsTextItem *myDestructionText = addText("Destroyed", destructionFont );
    myDestructionText->setZValue( 50 );
    myDestructionText->setPos( xPosition -myDestructionText->boundingRect().width()/2, yPosition );
    dynamicGraphicItems.append( myDestructionText );
    
    QRectF myRec = myDestructionText->boundingRect();
    myRec.setHeight( myRec.height() - 5);
    myRec.setY( myRec.y() + 5);
    QGraphicsRectItem *myRectItem = addRect( myRec, transparentPen, destructionBrush );
    myRectItem->setPos(xPosition-myDestructionText->boundingRect().width()/2,yPosition );
    myRectItem->setZValue( 49 );
    dynamicGraphicItems.append( myRectItem );
    //#]
}

void SequenceDiagram::printErrorHandlerReached(unsigned int position)
{
    //#[ operation printErrorHandlerReached(unsigned int)
    for( auto myInstanceItem : this->itsInstanceItemList )
    {
        if( myInstanceItem->getItsCommandList() == itsCommandList )
        {
            int xPosition = myInstanceItem->getXPosition();
            int yPosition = position * verticalCommandSpace - offset;
            dynamicGraphicItems << addLine(xPosition - 10,yPosition, xPosition + 10,yPosition + 4, errorHandlerPan);
            dynamicGraphicItems << addLine(xPosition + 10,yPosition + 4, xPosition - 10,yPosition + 8, errorHandlerPan);
            dynamicGraphicItems << addLine(xPosition - 10,yPosition + 8, xPosition + 10,yPosition + 12, errorHandlerPan);
            dynamicGraphicItems << addLine(xPosition + 10,yPosition + 12, xPosition + 7,yPosition + 9, errorHandlerPan);
            dynamicGraphicItems << addLine(xPosition + 10,yPosition + 12, xPosition + 7,yPosition + 15, errorHandlerPan);
            dynamicGraphicItems << addText("Error Handler Reached",QFont( "Arial", 8, QFont::Normal ));
            dynamicGraphicItems.last()->setPos( xPosition + 14, yPosition - 10 );
        }
    }
    //#]
}

void SequenceDiagram::printIntValue(CommandIntVal* intValCommand, int printPosition)
{
    //#[ operation printIntValue(CommandIntVal,int)
    int xPosition = getInstancePosition( intValCommand->getInstance(), this );
    int yPosition = verticalCommandSpace * ( printPosition - startCommand ) - offset;
    QGraphicsTextItem *myInitialisationText = addText(QString::number(intValCommand->getIntValue() ), initialisationFont );
    myInitialisationText->setZValue( 50 );
    myInitialisationText->setPos( xPosition -myInitialisationText->boundingRect().width()/2, yPosition );
    dynamicGraphicItems.append( myInitialisationText );
    
    QRectF myRec =myInitialisationText->boundingRect();
    myRec.setHeight( myRec.height() - 5);
    myRec.setY( myRec.y() + 5);
    QGraphicsRectItem *myRectItem = addRect(myRec,transparentPen,intValBrush);
    
    myRectItem->setPos(xPosition-myInitialisationText->boundingRect().width()/2,yPosition );
    myRectItem->setZValue( 49 );
    dynamicGraphicItems.append( myRectItem );
    //#]
}

void SequenceDiagram::printOperationBufferOverflow(unsigned int position)
{
    //#[ operation printOperationBufferOverflow(unsigned int)
    for( auto myInstanceItem : this->itsInstanceItemList )
    {
        if( myInstanceItem->getItsCommandList() == itsCommandList )
        {
            int xPosition = myInstanceItem->getXPosition();
            int yPosition = position * verticalCommandSpace - offset;
            dynamicGraphicItems << addLine(xPosition - 10,yPosition, xPosition + 10,yPosition + 4, errorHandlerPan);
            dynamicGraphicItems << addLine(xPosition + 10,yPosition + 4, xPosition - 10,yPosition + 8, errorHandlerPan);
            dynamicGraphicItems << addLine(xPosition - 10,yPosition + 8, xPosition + 10,yPosition + 12, errorHandlerPan);
            dynamicGraphicItems << addLine(xPosition + 10,yPosition + 12, xPosition + 7,yPosition + 9, errorHandlerPan);
            dynamicGraphicItems << addLine(xPosition + 10,yPosition + 12, xPosition + 7,yPosition + 15, errorHandlerPan);
            dynamicGraphicItems << addText("Buffer Overflow\nEventData Lost");
            dynamicGraphicItems.last()->setPos( xPosition + 14, yPosition - 10 );
        }
    }
    //#]
}

void SequenceDiagram::printOperationCalled(CommandOperationCall* operationCall, int printPosition)
{
    //#[ operation printOperationCalled(CommandOperationCall,int)
    int eventPosSourceX = getInstancePosition( operationCall->getSourceInstance(), this );
    int eventPosSourceY = ( printPosition - startCommand ) * verticalCommandSpace - offset;
    
    int eventPosDestinationX = getInstancePosition( operationCall->getDestinationInstance(), this );
    int eventPosDestinationY = eventPosSourceY;
    QString parameterText ="";
    for( auto myEventParameter : operationCall->getReceivedEventParameters() )
    {
        parameterText+=myEventParameter->getItsModelEventArgumentType()->getName()+"="+myEventParameter->getValue()+" ";
    }
    QGraphicsTextItem *myEventNameItem = addText( operationCall->getItsModelEventType()->getName()+" Ticks: "+QString::number(operationCall->getTicks()) );
    QGraphicsTextItem *myEventParameterItem = addText( parameterText );
    dynamicGraphicItems << myEventNameItem;
    dynamicGraphicItems << myEventParameterItem;
    
    if(eventPosSourceX<eventPosDestinationX)
    {
        myEventNameItem->setPos( eventPosSourceX - myEventNameItem->boundingRect().width() - 4, eventPosSourceY -7 );
        myEventParameterItem->setPos( eventPosSourceX + 4, eventPosSourceY -7 );
        dynamicGraphicItems << addLine(   eventPosSourceX , eventPosSourceY + 5 , eventPosDestinationX , eventPosDestinationY + 5 , eventLineEndPen );
        dynamicGraphicItems << addLine(   eventPosDestinationX , eventPosDestinationY + 5 , eventPosDestinationX - 8 , eventPosDestinationY - 3  , eventLineEndPen );
        dynamicGraphicItems << addLine(   eventPosDestinationX , eventPosDestinationY + 5 , eventPosDestinationX - 8 , eventPosDestinationY + 13 , eventLineEndPen );
    }
    else if(eventPosSourceX>eventPosDestinationX)
    {
        myEventNameItem->setPos( eventPosSourceX + 4, eventPosSourceY -7 );
        myEventParameterItem->setPos( eventPosSourceX - myEventParameterItem->boundingRect().width() - 4, eventPosSourceY -7 );
        dynamicGraphicItems << addLine(   eventPosSourceX , eventPosSourceY +5 , eventPosDestinationX , eventPosDestinationY +5 , eventLineEndPen );
        dynamicGraphicItems << addLine(   eventPosDestinationX , eventPosDestinationY + 5 , eventPosDestinationX + 8 , eventPosDestinationY - 3  , eventLineEndPen );
        dynamicGraphicItems << addLine(   eventPosDestinationX , eventPosDestinationY + 5 , eventPosDestinationX + 8 , eventPosDestinationY + 13 , eventLineEndPen );
    }
    else{
        myEventNameItem->setPos( eventPosSourceX - myEventNameItem->boundingRect().width() - 4, eventPosSourceY -7 );
        myEventParameterItem->setPos( eventPosSourceX + 4, eventPosSourceY -7 );
        dynamicGraphicItems << addLine(   eventPosSourceX , eventPosSourceY , eventPosSourceX + 10 , eventPosSourceY , eventLineEndPen );
        dynamicGraphicItems << addLine(   eventPosSourceX + 10 , eventPosSourceY , eventPosSourceX + 10 , eventPosDestinationY + 5 , eventLineEndPen );
        dynamicGraphicItems << addLine(   eventPosSourceX + 10 , eventPosDestinationY + 5 , eventPosSourceX , eventPosDestinationY + 5 , eventLineEndPen );
        dynamicGraphicItems << addLine(   eventPosSourceX , eventPosDestinationY + 5 , eventPosSourceX + 8 , eventPosDestinationY - 3 , eventLineEndPen );
        dynamicGraphicItems << addLine(   eventPosSourceX , eventPosDestinationY + 5 , eventPosSourceX + 8 , eventPosDestinationY + 12 , eventLineEndPen );
    }
    //#]
}

void SequenceDiagram::printTraceEvent(CommandTraceEvent* traceEvent, int printPosition)
{
    //#[ operation printTraceEvent(CommandTraceEvent,int)
    // TODO: refactor to reuse code from printTrippleEvent() and printTraceEvent() !!!
    
    int eventPosSourceX = getInstancePosition( traceEvent->getSourceInstance(), this );
    int eventPosSourceY = ( printPosition - startCommand ) * ( verticalCommandSpace + 20 ) - offset;
    
    InstanceItemSeqenceDiagram* myDestinationInstance = getInstanceItem( traceEvent->getDestinationInstance(), this );
    int eventPosDestinationX = myDestinationInstance->getXPosition();
    int eventPosDestinationY = eventPosSourceY;
    
    QString parameterText ="";
    for( auto myEventParameter : traceEvent->getReceivedEventParameters() )
    {
        parameterText+=myEventParameter->getItsModelEventArgumentType()->getName()+"="+myEventParameter->getValue()+" ";
    }
    QGraphicsTextItem *myEventNameItem = addText( traceEvent->getItsModelEventType()->getName()+" Ticks: "+QString::number(traceEvent->getTicks()) );
    QGraphicsTextItem *myEventParameterItem = addText( parameterText );
    dynamicGraphicItems << myEventNameItem;
    dynamicGraphicItems << myEventParameterItem;
    
    //print State
    QGraphicsTextItem *stateText = addText( "" );
    
    QString myString;
    if( showStateDelta && myDestinationInstance->getLastState() != NULL )
    {
        myString = QString( higliteStateDifference( myDestinationInstance->getLastState(), &traceEvent->getStateAfterEventConsumption() ) );
    }
    else
    {
        myString = QString(traceEvent->getStateAfterEventConsumption());
    }
    if( hideNonState )
    {
        myString = myString.replace("OMNonState","");
    }
    if( showStateDelta )
    {
        myDestinationInstance->setLastState( (QString*)&traceEvent->getStateAfterEventConsumption() );
    }
    
    stateText->setHtml(myString.replace("|","<b><font color=\"red\">|</font></b>" ) );
    
    // set position before destination arrow to show, that this is the state before(!)
    stateText->setPos(eventPosDestinationX - stateText->boundingRect().width()/2, eventPosDestinationY - stateText->boundingRect().height() );
    stateText->setZValue( 50 );
    dynamicGraphicItems << stateText;
    
    QGraphicsRectItem *myRectItem = addRect( dynamicGraphicItems.last()->pos().rx() + 3,dynamicGraphicItems.last()->pos().ry() + 3,dynamicGraphicItems.last()->boundingRect().width() -6,dynamicGraphicItems.last()->boundingRect().height()-6,transparentPen,stateBrush);
    myRectItem->setZValue( 49 );
    dynamicGraphicItems.append( myRectItem );
    
    if(eventPosSourceX<eventPosDestinationX)
    {
        myEventNameItem->setPos( eventPosSourceX - myEventNameItem->boundingRect().width() - 4, eventPosSourceY -7 );
        myEventParameterItem->setPos( eventPosSourceX + 4, eventPosSourceY -7 );
        dynamicGraphicItems << addLine(   eventPosSourceX , eventPosSourceY , eventPosDestinationX , eventPosDestinationY+5 , eventLineEndPen );
        dynamicGraphicItems << addLine(   eventPosDestinationX , eventPosDestinationY + 5 , eventPosDestinationX - 8 , eventPosDestinationY - 3  , eventLineEndPen );
        dynamicGraphicItems << addLine(   eventPosDestinationX , eventPosDestinationY + 5 , eventPosDestinationX - 8 , eventPosDestinationY + 13 , eventLineEndPen );
    }
    else if(eventPosSourceX>eventPosDestinationX)
    {
        myEventNameItem->setPos( eventPosSourceX + 4, eventPosSourceY -7 );
        myEventParameterItem->setPos( eventPosSourceX - myEventParameterItem->boundingRect().width() - 4, eventPosSourceY -7 );
        dynamicGraphicItems << addLine(   eventPosSourceX , eventPosSourceY , eventPosDestinationX , eventPosDestinationY+5 , eventLineEndPen );
        dynamicGraphicItems << addLine(   eventPosDestinationX , eventPosDestinationY + 5 , eventPosDestinationX + 8 , eventPosDestinationY - 3  , eventLineEndPen );
        dynamicGraphicItems << addLine(   eventPosDestinationX , eventPosDestinationY + 5 , eventPosDestinationX + 8 , eventPosDestinationY + 13 , eventLineEndPen );
    }
    else{
        myEventNameItem->setPos( eventPosSourceX - myEventNameItem->boundingRect().width() - 4, eventPosSourceY -7 );
        myEventParameterItem->setPos( eventPosSourceX + 4, eventPosSourceY -7 );
        dynamicGraphicItems << addLine(   eventPosSourceX , eventPosSourceY , eventPosSourceX + 10 , eventPosSourceY , eventLineEndPen );
        dynamicGraphicItems << addLine(   eventPosSourceX + 10 , eventPosSourceY , eventPosSourceX + 10 , eventPosDestinationY + 5 , eventLineEndPen );
        dynamicGraphicItems << addLine(   eventPosSourceX + 10 , eventPosDestinationY + 5 , eventPosSourceX , eventPosDestinationY + 5 , eventLineEndPen );
        dynamicGraphicItems << addLine(   eventPosSourceX , eventPosDestinationY + 5 , eventPosSourceX + 8 , eventPosDestinationY - 3 , eventLineEndPen );
        dynamicGraphicItems << addLine(   eventPosSourceX , eventPosDestinationY + 5 , eventPosSourceX + 8 , eventPosDestinationY + 12 , eventLineEndPen );
    }
    //#]
}

void SequenceDiagram::printTrippleEvent(CommandEventCreated* createEvent)
{
    //#[ operation printTrippleEvent(CommandEventCreated)
    int eventPosSourceX = getInstancePosition( createEvent->getSourceInstance(), this );
    int eventPosSourceY = ( itsCommandList->getCommandDisplayNumberInSequenceDiagram( createEvent->getDisplayNumber() ) - startCommand ) * verticalCommandSpace - offset;
    
    InstanceItemSeqenceDiagram* myDestinationInstance = getInstanceItem( createEvent->getDestinationInstance(), this );
    int eventPosDestinationX = myDestinationInstance->getXPosition();
    int eventPosDestinationY = eventPosSourceY;
    
    if( createEvent->getDestinationInstance() == createEvent->getSourceInstance() )
    {
        selfMessageOpen +=3;
    }
    
    QPen* eventLine;
    QString parameterText ="";
    for( auto myEventParameter : createEvent->getReceivedEventParameters() )
    {
        parameterText+=myEventParameter->getItsModelEventArgumentType()->getName()+"="+myEventParameter->getValue()+" ";
    }
    QGraphicsTextItem *myEventNameItem = addText( createEvent->getItsModelEventType()->getName()+" Ticks: "+QString::number(createEvent->getTicks()) );
    QGraphicsTextItem *myEventParameterItem = addText( parameterText );
    dynamicGraphicItems << myEventNameItem;
    dynamicGraphicItems << myEventParameterItem;
    if( createEvent->getItsCommandEventStartDispatch() == NULL )
    {
        eventLine = &eventLineCreatedPen;
    }
    else
    {
        CommandEventEndDispatch *myEndEvent = createEvent->getItsCommandEventStartDispatch()->getItsCommandEventEndDispatch();
        eventPosDestinationY = ( itsCommandList->getCommandDisplayNumberInSequenceDiagram( createEvent->getItsCommandEventStartDispatch()->getDisplayNumber() ) - startCommand ) * verticalCommandSpace - offset;
        if( createEvent->getItsCommandEventStartDispatch()->getItsCommandEventEndDispatch() == NULL )
        {
            dynamicGraphicItems << addLine(eventPosDestinationX,eventPosDestinationY+5,eventPosDestinationX, (itsCommandList->getCommandCounter() -startCommand) * verticalCommandSpace - offset, uncompleteLifeLinePen);
            eventLine = &eventLineStartPen;
        }
        else
        {
            int eventEndPositionY = ( itsCommandList->getCommandDisplayNumberInSequenceDiagram( myEndEvent->getDisplayNumber() ) - startCommand ) * verticalCommandSpace - offset;
            dynamicGraphicItems << addLine(eventPosDestinationX,eventPosDestinationY+5,eventPosDestinationX, eventEndPositionY, completeLifeLinePen);
    
            //print State
            QGraphicsTextItem *stateText = addText("");
    
            QString myString;
            if( showStateDelta && myDestinationInstance->getLastState() != NULL )
            {
                myString = QString( higliteStateDifference( myDestinationInstance->getLastState(), &myEndEvent->getStateAfterEventConsumption() ) );
            }
            else
            {
                myString = QString(myEndEvent->getStateAfterEventConsumption());
            }
            if( hideNonState )
            {
                myString = myString.replace("OMNonState","");
            }
            if( showStateDelta )
            {
                myDestinationInstance->setLastState( (QString*)&myEndEvent->getStateAfterEventConsumption() );
            }
    
            stateText->setHtml(myString.replace("|","<b><font color=\"red\">|</font></b>" ) );
            stateText->setPos(eventPosDestinationX - stateText->boundingRect().width()/2, eventEndPositionY );
            stateText->setZValue( 50 );
            dynamicGraphicItems << stateText;
    
            QGraphicsRectItem *myRectItem = addRect( dynamicGraphicItems.last()->pos().rx() + 3,dynamicGraphicItems.last()->pos().ry() + 3,dynamicGraphicItems.last()->boundingRect().width() -6,dynamicGraphicItems.last()->boundingRect().height()-6,transparentPen,stateBrush);
            myRectItem->setZValue( 49 );
            dynamicGraphicItems.append( myRectItem );
            eventLine = &eventLineEndPen;
        }
    }
    
    if(eventPosSourceX<eventPosDestinationX)
    {
        myEventNameItem->setPos( eventPosSourceX - myEventNameItem->boundingRect().width() - 4, eventPosSourceY -7 );
        myEventParameterItem->setPos( eventPosSourceX + 4, eventPosSourceY -7 );
        dynamicGraphicItems << addLine(   eventPosSourceX , eventPosSourceY , eventPosDestinationX , eventPosDestinationY+5 , *eventLine );
        dynamicGraphicItems << addLine(   eventPosDestinationX , eventPosDestinationY + 5 , eventPosDestinationX - 8 , eventPosDestinationY - 3  , *eventLine );
        dynamicGraphicItems << addLine(   eventPosDestinationX , eventPosDestinationY + 5 , eventPosDestinationX - 8 , eventPosDestinationY + 13 , *eventLine );
    }
    else if(eventPosSourceX>eventPosDestinationX)
    {
        myEventNameItem->setPos( eventPosSourceX + 4, eventPosSourceY -7 );
        myEventParameterItem->setPos( eventPosSourceX - myEventParameterItem->boundingRect().width() - 4, eventPosSourceY -7 );
        dynamicGraphicItems << addLine(   eventPosSourceX , eventPosSourceY , eventPosDestinationX , eventPosDestinationY+5 , *eventLine );
        dynamicGraphicItems << addLine(   eventPosDestinationX , eventPosDestinationY + 5 , eventPosDestinationX + 8 , eventPosDestinationY - 3  , *eventLine );
        dynamicGraphicItems << addLine(   eventPosDestinationX , eventPosDestinationY + 5 , eventPosDestinationX + 8 , eventPosDestinationY + 13 , *eventLine );
    }
    else{
        myEventNameItem->setPos( eventPosSourceX - myEventNameItem->boundingRect().width() - 4, eventPosSourceY -7 );
        myEventParameterItem->setPos( eventPosSourceX + 4, eventPosSourceY -7 );
        dynamicGraphicItems << addLine(   eventPosSourceX , eventPosSourceY , eventPosSourceX + 10 + selfMessageOpen , eventPosSourceY , *eventLine );
        dynamicGraphicItems << addLine(   eventPosSourceX + 10 + selfMessageOpen , eventPosSourceY , eventPosSourceX + 10 + selfMessageOpen , eventPosDestinationY + 5 , *eventLine );
        dynamicGraphicItems << addLine(   eventPosSourceX + 10 + selfMessageOpen , eventPosDestinationY + 5 , eventPosSourceX , eventPosDestinationY + 5 , *eventLine );
        dynamicGraphicItems << addLine(   eventPosSourceX , eventPosDestinationY + 5 , eventPosSourceX + 8 , eventPosDestinationY - 3 , *eventLine );
        dynamicGraphicItems << addLine(   eventPosSourceX , eventPosDestinationY + 5 , eventPosSourceX + 8 , eventPosDestinationY + 12 , *eventLine );
    }
    //#]
}

void SequenceDiagram::setActive(CommandList* commandList)
{
    //#[ operation setActive(CommandList)
    for( auto myInstanceItem : this->itsInstanceItemList )
    {
        if( myInstanceItem->getItsCommandList() == commandList )
        {
            myInstanceItem->getItsInstanceGraphicsItem()->show();
            myInstanceItem->getItsLifeLine()->show();
        }
    }
    //#]
}

void SequenceDiagram::setInactive(CommandList* commandList)
{
    //#[ operation setInactive(CommandList)
    for( auto myInstanceItem : this->itsInstanceItemList )
    {
        if( myInstanceItem->getItsCommandList() == commandList )
        {
            myInstanceItem->getItsInstanceGraphicsItem()->hide();
            myInstanceItem->getItsLifeLine()->hide();
        }
    }
    //#]
}

void SequenceDiagram::cleanUpRelations()
{
    {
        dragItemList.clear();
    }
    if(itsCommandList != NULL)
        {
            itsCommandList = NULL;
        }
    if(itsInstanceDragItem != NULL)
        {
            itsInstanceDragItem = NULL;
        }
    {
        itsInstanceItemList.clear();
    }
    if(itsRefreshCheckBox != NULL)
        {
            itsRefreshCheckBox = NULL;
        }
    if(itsVerticalScrollBar != NULL)
        {
            itsVerticalScrollBar = NULL;
        }
    if(itsView != NULL)
        {
            itsView = NULL;
        }
}

QPen SequenceDiagram::completeLifeLinePen(Qt::blue,5);

QBrush SequenceDiagram::constructorBrush(Qt::green);

QBrush SequenceDiagram::destructionBrush(Qt::red);

QFont SequenceDiagram::destructionFont("Arial", 8);

QPen SequenceDiagram::errorHandlerPan(Qt::yellow,2);

QPen SequenceDiagram::eventLineCreatedPen(Qt::red, 1, Qt::DashLine, Qt::FlatCap, Qt::BevelJoin);

QPen SequenceDiagram::eventLineEndPen(Qt::green, 1, Qt::SolidLine, Qt::FlatCap, Qt::BevelJoin);

QPen SequenceDiagram::eventLineStartPen(Qt::blue, 1, Qt::SolidLine, Qt::FlatCap, Qt::BevelJoin);

QFont SequenceDiagram::initialisationFont("Arial", 8);

QBrush SequenceDiagram::intValBrush(Qt::lightGray);

QBrush SequenceDiagram::stateBrush(Qt::cyan);

QPen SequenceDiagram::transparentPen(Qt::transparent);

QPen SequenceDiagram::uncompleteLifeLinePen(Qt::red,5);

/*********************************************************************
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\SequenceDiagram.cpp
*********************************************************************/
