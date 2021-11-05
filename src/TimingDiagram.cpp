/********************************************************************
	Rhapsody	: 9.0.1 
	Login		: Y9DSYU706
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: TimingDiagram
//!	Generated Date	: Thu, 4, Nov 2021  
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\TimingDiagram.cpp
*********************************************************************/

#include "TimingDiagram.h"
#include "Command.h"
#include "CommandConstructor.h"
#include "CommandDestructor.h"
#include "CommandEventCreated.h"
#include "CommandEventEndDispatch.h"
#include "CommandEventStartDispatch.h"
#include "CommandList.h"
#include "CommandOperationCall.h"
#include "CommandTraceEvent.h"
#include "ModelEventType.h"
#include "ModelInstance.h"
#include <QGraphicsSceneEvent.h>
#include <QGraphicsView.h>
#include <QScrollBar.h>
#include "TargetInformation.h"
#include <QApplication.h>
//## package GUI

//## class TimingDiagram
const int TimingDiagram::TICKSPACE_TD(25);

bool TimingDiagram::hideNonState;

bool TimingDiagram::showStateDelta;

TimingDiagram::TimingDiagram() : drag(DragNone), instanceLableHeight(40), instanceLableWidth(130), oldInstanceLableWidth(130)
{
    itsCheckBoxAutoRefresh = NULL;
    itsCheckBoxShowArguments = NULL;
    itsCommandList = NULL;
    itsStartTickSpinBox = NULL;
    itsTickRangeSpinBox = NULL;
    itsVerticalScrollBar = NULL;
    itsView = NULL;
    //#[ operation TimingDiagram()
    refreshTimer.singleShot(1000,this,SLOT(reDraw()) );
    addLine(0,-200000,0,0);
    //#]
}

TimingDiagram::~TimingDiagram()
{
    //#[ operation ~TimingDiagram()
    refreshTimer.stop();
    //#]
    cleanUpRelations();
}

void TimingDiagram::changeCommandList(QModelIndex index)
{
    //#[ operation changeCommandList(QModelIndex)
    QStandardItemModel *myModel = (QStandardItemModel*)index.model();
    CommandList *tmpList = (CommandList*)myModel->itemFromIndex(index);
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
    itsCommandList = tmpList;
    //#]
}

void TimingDiagram::changeYValue()
{
    //#[ operation changeYValue()
    resizeScene();
    //#]
}

void TimingDiagram::init()
{
    //#[ operation init()
    itsView = this->views().first();
    resizeScene();
    connect( itsVerticalScrollBar, SIGNAL(valueChanged(int)), this, SLOT(changeYValue()));
    //#]
}

void TimingDiagram::reDraw()
{
    //#[ operation reDraw()
    itsView = this->views().first();
    if(!itsView->isVisible())
    {
        refreshTimer.singleShot(400,this,SLOT(reDraw()));
        return;
    }
    if( itsCommandList != NULL && itsCheckBoxAutoRefresh->isChecked() )
    {
        int newStartTick = itsCommandList->getCommands().last()->getTicks() - ( itsTickRangeSpinBox->value() / 1.5 );
        itsStartTickSpinBox->setValue( newStartTick );
    }
    tickRange = itsTickRangeSpinBox->value();
    startTick = itsStartTickSpinBox->value();
    endTick = startTick + itsTickRangeSpinBox->value();
    drawingWidth = itsView->width() - instanceLableWidth - 40;
    faktor = (float) drawingWidth / (float)tickRange;
    
    //Disable Update to avoid flicker
    itsView->setUpdatesEnabled( false );
    
    cleanDynamicGraphicItems();
    
    for( auto currentInstance : this->itsInstanceItemTimingDiagram )
    {
        currentInstance->setLastState( NULL );
    }
    
    int commandCount = drawCommands();
    if( oldViewWidth != itsView->width() || oldViewHeight != itsView->height() )
    {
        resizeScene();
        oldViewWidth = itsView->width();
    }
    itsView->setUpdatesEnabled( true );
    itsView->repaint();
    int reprintTime;
    if( commandCount > 500 )
    {
        reprintTime = 1000;
    }
    else if(commandCount > 300)
    {
        reprintTime = 600;
    }
    else if(commandCount > 100)
    {
        reprintTime = 400;
    }
    else
    {
       reprintTime = 300;
    }
    refreshTimer.singleShot(reprintTime,this,SLOT(reDraw()));
    //#]
}

void TimingDiagram::setItsCommandList(CommandList* commandList)
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

void TimingDiagram::mouseMoveEvent(QGraphicsSceneMouseEvent* mouseEvent)
{
    //#[ operation mouseMoveEvent(QGraphicsSceneMouseEvent)
    if( drag == DragNone )
    {
       if( mouseEvent->scenePos().x() < -1 )
       {
            this->views().first()->viewport()->setCursor( Qt::ArrowCursor );
       }
       else if( mouseEvent->scenePos().x() > 1 )
       {
            this->views().first()->viewport()->setCursor( Qt::OpenHandCursor );
       }
       else
       {
            this->views().first()->viewport()->setCursor( Qt::SplitHCursor );
       }
    }
    else if( drag == DragInstanceWidth )
    {
        instanceLableWidth = oldInstanceLableWidth + mouseEvent->screenPos().x();
        resizeScene();
    }
    else if( drag == DragDiagram )
    {
        itsStartTickSpinBox->setValue( oldStartTick + ( ( oldStartTickXPos - mouseEvent->scenePos().x() ) /faktor ) );
    }
    else if( drag == DragInstance)
    {
        int newYVal = mouseEvent->scenePos().y();
        if( newYVal > -5 )
        {
            newYVal = -5;
        }
        if( instanceDragMouseButton == 0 )
        {
            dragInstance->setNewYPosition( newYVal );
        }
        else
        {
            for( auto currentInstance : this->itsInstanceItemTimingDiagram )
            {
                if( oldInstanceYPos + 15 > currentInstance->getOldInstanceYPos() &&
                    currentInstance->getItsCommandList() == itsCommandList )
                {
                    int offset = currentInstance->getOldInstanceYPos() - oldInstanceYPos;
                    currentInstance->setNewYPosition( newYVal + offset );
                }
            }
        }
    }    
    //#]
}

void TimingDiagram::mousePressEvent(QGraphicsSceneMouseEvent* mouseEvent)
{
    //#[ operation mousePressEvent(QGraphicsSceneMouseEvent)
    if( mouseEvent->scenePos().x() < -1 )
    {
        for( auto currentInstance : this->itsInstanceItemTimingDiagram )
        {
            int yPos = currentInstance->isPressed( mouseEvent->scenePos().y() );
            if( yPos < 1 )
            {
                if( mouseEvent->button() == Qt::LeftButton )
                {
                    instanceDragMouseButton = 0;
                    currentInstance->setOldInstanceYPos( currentInstance->getYPosition() );
                    dragInstance = currentInstance;
                    drag = DragInstance;
                }
                else if( mouseEvent->button() == Qt::RightButton )
                {
                    instanceDragMouseButton = 1;
                    oldInstanceYPos = currentInstance->getYPosition();
                    for( auto currentInstanceAbove : this->itsInstanceItemTimingDiagram )
                    {
                        if( mouseEvent->scenePos().y() > currentInstanceAbove->getYPosition() )
                        {
                            currentInstanceAbove->setOldInstanceYPos( currentInstanceAbove->getYPosition() );
                        }
                        else
                        {
                            currentInstanceAbove->setOldInstanceYPos( 100000 );
                        }
                    }
                    currentInstance->setOldInstanceYPos( oldInstanceYPos );
                    dragInstance = currentInstance;
                    drag = DragInstance;
                }
                break;
            }
        }
    
    }
    else if( mouseEvent->scenePos().x() > 1 )
    {
        drag = DragDiagram;
        this->views().first()->viewport()->setCursor( Qt::ClosedHandCursor );
        oldStartTick = itsStartTickSpinBox->value();
        oldStartTickXPos = mouseEvent->scenePos().x();
    }
    else
    {
        oldInstanceLableWidth = instanceLableWidth - mouseEvent->screenPos().x();
        this->views().first()->viewport()->setCursor( Qt::SplitHCursor );
        drag = DragInstanceWidth;
    }
    
    //#]
}

void TimingDiagram::mouseReleaseEvent(QGraphicsSceneMouseEvent* mouseEvent)
{
    //#[ operation mouseReleaseEvent(QGraphicsSceneMouseEvent)
    mouseEvent = mouseEvent;
    drag = DragNone;
    //#]
}

void TimingDiagram::wheelEvent(QGraphicsSceneWheelEvent* wheelEvent)
{
    //#[ operation wheelEvent(QGraphicsSceneWheelEvent)
    int posX = (int)wheelEvent->scenePos().x();
    float width = (float)this->views().first()->width() - instanceLableWidth;
    if(wheelEvent->delta()>0)
    {
        float faktor = width/(float)tickRange;
        int mouseIsOverTick = posX / faktor + startTick;
        tickRange=(int)(tickRange*0.75);
        if(tickRange<5)
        {
            tickRange=5;
        }
    
        faktor = width/(float)tickRange;
    
        startTick =  mouseIsOverTick - posX / faktor + 1;
    
        if( startTick < 0 )
        {
            startTick = 0;
        }
    }
    else
    {
        float faktor = width/(float)tickRange;
        int mouseIsOverTick = posX / faktor + startTick;
        tickRange=(int)(tickRange*1.25);
        if(tickRange<5)
        {
            tickRange=5;
        }
    
        faktor = width/(float)tickRange;
    
        startTick =  mouseIsOverTick - posX / faktor + 1;
    
        if( startTick < 0 )
        {
            startTick = 0;
        }
    }
    itsStartTickSpinBox->setValue(startTick);
    itsTickRangeSpinBox->setValue(tickRange);
    //#]
}

void TimingDiagram::cleanDynamicGraphicItems()
{
    //#[ operation cleanDynamicGraphicItems()
    for(int i=0;i<dynamicGraphicItems.size();i++){
        this->removeItem(dynamicGraphicItems.at(i));
        delete dynamicGraphicItems.at(i);
    }
    dynamicGraphicItems.clear();
    //#]
}

void TimingDiagram::cleanTimelineGraphicItems()
{
    //#[ operation cleanTimelineGraphicItems()
    for(int i=0;i<timeLineGraphicItems.size();i++){
        this->removeItem(timeLineGraphicItems.at(i));
        delete timeLineGraphicItems.at(i);
    }
    timeLineGraphicItems.clear();
    //#]
}

int TimingDiagram::drawCommands()
{
    //#[ operation drawCommands()
    if( itsCommandList == NULL || itsCommandList->getCommandCounter() == 0 )
    {
        return 0;
    }
    float divisor = (float)itsCommandList->getCommandCounter() / 2.0;
    float startCommand_f = divisor;
    float endCommand_f = divisor;
    int endCommand;
    int startCommand;
    QVector<Command*> commands = itsCommandList->getCommands();
    //find start and end point by binary search
    while( divisor > 0.1 )
    {
        divisor = divisor / 2.0;
        if( commands.at( (int)(startCommand_f+0.5) )->getTicks() >= startTick )
        {
            startCommand_f = startCommand_f - divisor;
        }
        else
        {
            startCommand_f = startCommand_f + divisor;
        }
    
        if( commands.at( (int)(endCommand_f+0.5) )->getTicks() > endTick )
        {
            endCommand_f = endCommand_f - divisor;
        }
        else
        {
            endCommand_f = (float)endCommand_f + (float)divisor;
        }
        if( startCommand_f < 0 )
        {
            startCommand_f = 0;
        }
        if( (endCommand_f+0.5) >= itsCommandList->getCommandCounter()  )
        {
            endCommand_f = endCommand_f - 0.5;
        }
        if( (startCommand_f+0.5) >= itsCommandList->getCommandCounter()  )
        {
            startCommand_f = startCommand_f - 0.5;
        }
    }
    startCommand = startCommand_f + 0.6;
    endCommand = endCommand_f + 0.6;
    
    if( startCommand >= (int)itsCommandList->getCommandCounter())
    {
        startCommand = itsCommandList->getCommandCounter() - 1;
    }
    
    if( endCommand >= (int)itsCommandList->getCommandCounter())
    {
        endCommand = itsCommandList->getCommandCounter() - 1;
    }
    
    //clear instancePosition information from previous run
    for( auto currentInstance : this->itsInstanceItemTimingDiagram )
    {
        currentInstance->setCurrentTickForEvent( -1 );
        currentInstance->setCurrentTickForState( -1 );
    }
    
    //draw each command
    int commandCounter = 0;
    for( int i = startCommand; i <= endCommand; i++)
    {
        if((commandCounter % 100) == 0)
        {
           QApplication::processEvents();
        }
        Command* currentCommand = commands.at(i);
        switch( currentCommand->getCommandIdentifier() )
        {
            case Command::eventPutToMessageQueueCommand:
            {
                printCreateEvent( (CommandEventCreated*)currentCommand );
                break;
            }
            case Command::eventStartDispatchCommand:
            {
                break;
            }
            case Command::eventEndDispatchCommand:
            {
                printEndEvent( (CommandEventEndDispatch*)currentCommand );
                break;
            }
            case Command::constructorCommand:
            {
                printConstructor( (CommandConstructor*)currentCommand );
                break;
            }
            case Command::traceEventCommand:
            {
                printTraceEvent( (CommandTraceEvent*)currentCommand );
                break;
            }
            case Command::operationCalled:
            {
                printOperationCalled( (CommandOperationCall*)currentCommand );
                break;
            }
            case Command::errorHandlerReachedCommand:
            {
                printErrorHandlerReached( currentCommand );
                break;
            }
            case Command::bufferOverflowCommand:
            {
                printOperationBufferOverflow( currentCommand );
                break;
            }
            case Command::destructorCommand:
            {
                printDestructor( (CommandDestructor*)currentCommand );
                break;
            }
            case Command::debugIntValue:
            {
                break;
            }
        }
    }
    return endCommand - startCommand;
    //#]
}

void TimingDiagram::drawTimeLine()
{
    //#[ operation drawTimeLine()
    tickRange = itsTickRangeSpinBox->value();
    startTick = itsStartTickSpinBox->value();
    drawingWidth = itsView->width() - instanceLableWidth - 40;
    faktor = (float) drawingWidth / (float)tickRange;
    int count = drawingWidth / TICKSPACE_TD ;
    
    float space=0.0;
    if( count > tickRange )
    {
        count = tickRange;
        space = (float)drawingWidth / (float)count;
    }
    else
    {
        space = TICKSPACE_TD;
    }
    int xPos, tmpTick, tick;
    QString tickNumber= "";
    QGraphicsItem *tmp;
    cleanTimelineGraphicItems();
    for(int i=0; i <= count ; i++)
    {
        xPos = int(i * space);
    
        if( count == tickRange )
        {
            tmpTick = i + startTick;
        }
        else
        {
            tmpTick = int(xPos / faktor) + startTick;
        }
        tick = tmpTick;
        timeLineGraphicItems << this->addLine(xPos , 0 , xPos , 5 , itsTimeLinePen);
        tickNumber=tickNumber.setNum(tick);
        tmp = this->addSimpleText(tickNumber,QFont( "Arial", 14, QFont::Normal ));
        tmp->setRotation(90);
        tmp->setPos(xPos + 14, 8);
        timeLineGraphicItems<<tmp;
    }
    //#]
}

InstanceItemTimingDiagram* TimingDiagram::getInstancePositionInformation(ModelInstance* instance)
{
    //#[ operation getInstancePositionInformation(ModelInstance)
    int maxY = 0;
    for( auto currentInstance : this->itsInstanceItemTimingDiagram )
    {
        if( currentInstance->getItsCommandList() == itsCommandList )
        {
            if( currentInstance->getItsModelInstance() == instance )
            {
                return currentInstance;
            }
            if( currentInstance->getYPosition() < maxY )
            {
                maxY = currentInstance->getYPosition();
            }
        }
    }
    maxY -= instanceLableHeight;
    QList<QGraphicsItem*> myInstanceItemList;
    
    QString instanceName;
    if(instance->getItsTargetInformation()->getSingleTarget() )
    {
        instanceName = instance->getName();
    }
    else
    {
        instanceName = instance->getItsTargetInformation()->getName() + "." + instance->getName();
    }
    
    QGraphicsTextItem *myInstanceNameTextItem = addText( instanceName,QFont("Arial",10));
    myInstanceNameTextItem->setPos(- ( myInstanceNameTextItem->boundingRect().width() + 4 ) , -10 );
    myInstanceItemList.append( myInstanceNameTextItem );
    
    myInstanceItemList.append( addLine( 0 ,  7, 10000,  7 ) );
    myInstanceItemList.append( addLine( 0 , -7, 10000, -7 ) );
    
    QGraphicsItemGroup *myGrup = createItemGroup( myInstanceItemList );
    myGrup->setZValue(1);
    myGrup->setY( maxY );
    itsInstanceItemTimingDiagram.append( new InstanceItemTimingDiagram(instance ,myGrup, itsCommandList ) );
    return itsInstanceItemTimingDiagram.last();
    //#]
}

QString TimingDiagram::higliteStateDifference(const QString* lastState, const QString* newState)
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

void TimingDiagram::printConstructor(CommandConstructor* command)
{
    //#[ operation printConstructor(CommandConstructor)
    int eventPosX = (int)((command->getTicks() - startTick)*faktor);
    InstanceItemTimingDiagram* instancePositionInformation = getInstancePositionInformation( command->getItsModelInstance() );
    int eventPosDestinationY = instancePositionInformation->getYPosition();
    dynamicGraphicItems << addLine( eventPosX , eventPosDestinationY - 17 , eventPosX , eventPosDestinationY - 8, itsConstructorPan );
    dynamicGraphicItems.last()->setZValue(10);
    dynamicGraphicItems << addEllipse( eventPosX - 3 , eventPosDestinationY - 25 , 6, 6, itsConstructorPan, itsConstructorBrush );
    dynamicGraphicItems.last()->setZValue(10);
    dynamicGraphicItems << addLine( eventPosX - 5 , eventPosDestinationY - 13 , eventPosX , eventPosDestinationY - 8, itsConstructorPan );
    dynamicGraphicItems.last()->setZValue(10);
    dynamicGraphicItems << addLine( eventPosX + 5 , eventPosDestinationY - 13 , eventPosX , eventPosDestinationY - 8, itsConstructorPan );
    dynamicGraphicItems.last()->setZValue(10);
    //#]
}

void TimingDiagram::printCreateEvent(CommandEventCreated* command)
{
    //#[ operation printCreateEvent(CommandEventCreated)
    int eventPosX = (int)((command->getTicks() - startTick)*faktor);
    InstanceItemTimingDiagram* instancePositionInformation = getInstancePositionInformation( command->getDestinationInstance() );
    int eventPosDestinationY = instancePositionInformation->getYPosition();
    int eventPosSourceY;
    if( command->getDestinationInstance() == command->getSourceInstance() )
    {
         eventPosSourceY = eventPosDestinationY;
    }
    else
    {
        eventPosSourceY = getInstancePositionInformation( command->getSourceInstance() )->getYPosition();
    }
    
    
    //Draw event Name
    QString parameterText ="";
    if( itsCheckBoxShowArguments->isChecked() )
    {
        for( auto myEventParameter : command->getReceivedEventParameters() )
        {
            parameterText+=myEventParameter->getItsModelEventArgumentType()->getName()+"="+myEventParameter->getValue()+" ";
        }
    }
    int eventNr = instancePositionInformation->getEventTickCounter(command->getTicks()) + 1;
    QGraphicsTextItem *eventText = addText( QString::number(eventNr) + "." + command->getItsModelEventType()->getName() + " " + parameterText );
    dynamicGraphicItems << eventText;
    
    //Draw Event Line
    QPen *pen = &itsEventCreatePen;
    if( command->getItsCommandEventStartDispatch() != NULL )
    {
        if( command->getItsCommandEventStartDispatch()->getItsCommandEventEndDispatch() != NULL )
        {
            pen = &itsEventEndPen;
        }
        else
        {
            pen = &itsEventStartPen;
        }
    }
    if(eventPosSourceY<eventPosDestinationY)
    {
        dynamicGraphicItems << addLine( eventPosX , eventPosSourceY + 8 , eventPosX , eventPosDestinationY - 8 , *pen );
        dynamicGraphicItems.last()->setZValue(10);
        dynamicGraphicItems << addLine( eventPosX - 5 , eventPosDestinationY - 13 , eventPosX , eventPosDestinationY - 8 , *pen );
        dynamicGraphicItems.last()->setZValue(10);
        dynamicGraphicItems << addLine( eventPosX + 5 , eventPosDestinationY - 13 , eventPosX , eventPosDestinationY - 8 , *pen );
        dynamicGraphicItems.last()->setZValue(10);
        int ypos = eventPosDestinationY - ( eventText->boundingRect().height() - 10 ) * instancePositionInformation->getTopPosition( command->getTicks() ) - 14;
        eventText->setPos( eventPosX + 2,  ypos);
    }
    else if(eventPosSourceY>eventPosDestinationY)
    {
        dynamicGraphicItems << addLine( eventPosX , eventPosSourceY - 8 , eventPosX , eventPosDestinationY + 8 , *pen );
        dynamicGraphicItems.last()->setZValue(10);
        dynamicGraphicItems << addLine( eventPosX - 5 , eventPosDestinationY + 13 , eventPosX , eventPosDestinationY + 8 , *pen );
        dynamicGraphicItems.last()->setZValue(10);
        dynamicGraphicItems << addLine( eventPosX + 5 , eventPosDestinationY + 13 , eventPosX , eventPosDestinationY + 8 , *pen );
        dynamicGraphicItems.last()->setZValue(10);
        int ypos = eventPosDestinationY + 8 + ( eventText->boundingRect().height() - 10 ) * instancePositionInformation->getBotPosition( command->getTicks() ) - 14;
    
        eventText->setPos( eventPosX + 2, ypos);
    }
    else
    {
        dynamicGraphicItems << addLine( eventPosX , eventPosDestinationY - 17 , eventPosX , eventPosDestinationY - 8, *pen );
        dynamicGraphicItems.last()->setZValue(10);
        dynamicGraphicItems << addLine( eventPosX - 2 , eventPosDestinationY - 17 , eventPosX + 2 , eventPosDestinationY - 17, *pen );
        dynamicGraphicItems.last()->setZValue(10);
        dynamicGraphicItems << addLine( eventPosX - 5 , eventPosDestinationY - 13 , eventPosX , eventPosDestinationY - 8, *pen );
        dynamicGraphicItems.last()->setZValue(10);
        dynamicGraphicItems << addLine( eventPosX + 5 , eventPosDestinationY - 13 , eventPosX , eventPosDestinationY - 8, *pen );
        dynamicGraphicItems.last()->setZValue(10);
    
        int ypos = eventPosDestinationY - ( eventText->boundingRect().height() - 10 ) * instancePositionInformation->getTopPosition( command->getTicks() ) - 14;
        eventText->setPos( eventPosX + 2, ypos );
    }
    //#]
}

void TimingDiagram::printDestructor(CommandDestructor* command)
{
    //#[ operation printDestructor(CommandDestructor)
    int eventPosX = (int)((command->getTicks() - startTick)*faktor);
    InstanceItemTimingDiagram* instancePositionInformation = getInstancePositionInformation( command->getItsModelInstance() );
    int eventPosDestinationY = instancePositionInformation->getYPosition();
    dynamicGraphicItems << addLine( eventPosX , eventPosDestinationY - 17 , eventPosX , eventPosDestinationY - 8, itsDestuctorPen );
    dynamicGraphicItems.last()->setZValue(10);
    dynamicGraphicItems << addEllipse( eventPosX - 3 , eventPosDestinationY - 25 , 6, 6, itsDestuctorPen, itsConstructorBrush );
    dynamicGraphicItems.last()->setZValue(10);
    dynamicGraphicItems << addLine( eventPosX - 5 , eventPosDestinationY - 13 , eventPosX , eventPosDestinationY - 8, itsDestuctorPen );
    dynamicGraphicItems.last()->setZValue(10);
    dynamicGraphicItems << addLine( eventPosX + 5 , eventPosDestinationY - 13 , eventPosX , eventPosDestinationY - 8, itsDestuctorPen );
    dynamicGraphicItems.last()->setZValue(10);
    //#]
}

void TimingDiagram::printEndEvent(CommandEventEndDispatch* command)
{
    //#[ operation printEndEvent(CommandEventEndDispatch)
    InstanceItemTimingDiagram* instancePositionInformation = getInstancePositionInformation( command->getItsCommandEventStartDispatch()->getItsCommandEventCreated()->getDestinationInstance() );
    int eventPosDestinationY = instancePositionInformation->getYPosition();
    int eventPosX = (int)((command->getTicks() - startTick)*faktor);
    dynamicGraphicItems << addLine( eventPosX, eventPosDestinationY - 5 , eventPosX  , eventPosDestinationY + 5, itsTimeLinePen );
    dynamicGraphicItems.last()->setZValue(10);
    QGraphicsTextItem *stateText = instancePositionInformation->getStatTextFromTick( command->getTicks() );
    
    QString myString;
    if( showStateDelta && instancePositionInformation->getLastState() != NULL )
    {
        myString = QString( higliteStateDifference( instancePositionInformation->getLastState(), &command->getStateAfterEventConsumption() ) );
    }
    else
    {
        myString = QString(command->getStateAfterEventConsumption());
    }
    if( hideNonState )
    {
        myString = myString.replace("OMNonState","");
    }
    if( showStateDelta )
    {
        instancePositionInformation->setLastState( (QString*)&command->getStateAfterEventConsumption() );
    }
    myString = myString.replace("|","<b><font color=\"red\">|</font></b>" );
    
    if( stateText == NULL )
    {
        stateText = addText("");
    
        instancePositionInformation->setAllStatesForTick( myString );
        stateText->setHtml( myString );
    
        stateText->setPos(eventPosX + 2, eventPosDestinationY - ( stateText->boundingRect().height() / 2 ) );
        stateText->setZValue(9);
        dynamicGraphicItems << stateText;
        instancePositionInformation->setItsStateTextItem( stateText );
    }
    else
    {
        instancePositionInformation->appendAllStatesForTick( myString );
        stateText->setHtml( instancePositionInformation->getAllStatesForTick( ) );
    }
    //#]
}

void TimingDiagram::printErrorHandlerReached(Command* command)
{
    //#[ operation printErrorHandlerReached(Command)
    command = command;
    //#]
}

void TimingDiagram::printOperationBufferOverflow(Command* command)
{
    //#[ operation printOperationBufferOverflow(Command)
    command = command;
    //#]
}

void TimingDiagram::printOperationCalled(CommandOperationCall* command)
{
    //#[ operation printOperationCalled(CommandOperationCall)
    int eventPosX = (int)((command->getTicks() - startTick)*faktor);
    InstanceItemTimingDiagram* instancePositionInformation = getInstancePositionInformation( command->getDestinationInstance() );
    int eventPosDestinationY = instancePositionInformation->getYPosition();
    int eventPosSourceY;
    if( command->getDestinationInstance() == command->getSourceInstance() )
    {
         eventPosSourceY = eventPosDestinationY;
    }
    else
    {
        eventPosSourceY = getInstancePositionInformation( command->getSourceInstance() )->getYPosition();
    }
    
    
    //Draw event Name
    QString parameterText ="";
    if( itsCheckBoxShowArguments->isChecked() )
    {
        for( auto myEventParameter : command->getReceivedEventParameters() )
        {
            parameterText+=myEventParameter->getItsModelEventArgumentType()->getName()+"="+myEventParameter->getValue()+" ";
        }
    }
    int eventNr = instancePositionInformation->getEventTickCounter(command->getTicks()) + 1;
    QGraphicsTextItem *eventText = addText( QString::number(eventNr) + "." + command->getItsModelEventType()->getName() + " " + parameterText );
    dynamicGraphicItems << eventText;
    
    //Draw Event Line
    if(eventPosSourceY<eventPosDestinationY)
    {
        dynamicGraphicItems << addLine( eventPosX , eventPosSourceY + 8 , eventPosX , eventPosDestinationY - 8 , itsOperationPen );
        dynamicGraphicItems.last()->setZValue(10);
        dynamicGraphicItems << addLine( eventPosX - 5 , eventPosDestinationY - 13 , eventPosX , eventPosDestinationY - 8 , itsOperationPen );
        dynamicGraphicItems.last()->setZValue(10);
        dynamicGraphicItems << addLine( eventPosX + 5 , eventPosDestinationY - 13 , eventPosX , eventPosDestinationY - 8 , itsOperationPen );
        dynamicGraphicItems.last()->setZValue(10);
        int ypos = eventPosDestinationY - ( eventText->boundingRect().height() - 10 ) * instancePositionInformation->getTopPosition( command->getTicks() ) - 14;
        eventText->setPos( eventPosX + 2,  ypos);
    }
    else if(eventPosSourceY>eventPosDestinationY)
    {
        dynamicGraphicItems << addLine( eventPosX , eventPosSourceY - 8 , eventPosX , eventPosDestinationY + 8 , itsOperationPen );
        dynamicGraphicItems.last()->setZValue(10);
        dynamicGraphicItems << addLine( eventPosX - 5 , eventPosDestinationY + 13 , eventPosX , eventPosDestinationY + 8 , itsOperationPen );
        dynamicGraphicItems.last()->setZValue(10);
        dynamicGraphicItems << addLine( eventPosX + 5 , eventPosDestinationY + 13 , eventPosX , eventPosDestinationY + 8 , itsOperationPen );
        dynamicGraphicItems.last()->setZValue(10);
        int ypos = eventPosDestinationY + 8 + ( eventText->boundingRect().height() - 10 ) * instancePositionInformation->getBotPosition( command->getTicks() ) - 14;
    
        eventText->setPos( eventPosX + 2, ypos);
    }
    else
    {
        dynamicGraphicItems << addLine( eventPosX , eventPosDestinationY - 17 , eventPosX , eventPosDestinationY - 8, itsOperationPen );
        dynamicGraphicItems.last()->setZValue(10);
        dynamicGraphicItems << addLine( eventPosX - 2 , eventPosDestinationY - 17 , eventPosX + 2 , eventPosDestinationY - 17, itsOperationPen );
        dynamicGraphicItems.last()->setZValue(10);
        dynamicGraphicItems << addLine( eventPosX - 5 , eventPosDestinationY - 13 , eventPosX , eventPosDestinationY - 8, itsOperationPen );
        dynamicGraphicItems.last()->setZValue(10);
        dynamicGraphicItems << addLine( eventPosX + 5 , eventPosDestinationY - 13 , eventPosX , eventPosDestinationY - 8, itsOperationPen );
        dynamicGraphicItems.last()->setZValue(10);
    
        int ypos = eventPosDestinationY - ( eventText->boundingRect().height() - 10 ) * instancePositionInformation->getTopPosition( command->getTicks() ) - 14;
        eventText->setPos( eventPosX + 2, ypos );
    }
    //#]
}

void TimingDiagram::printTraceEvent(CommandTraceEvent* command)
{
    //#[ operation printTraceEvent(CommandTraceEvent)
    int eventPosX = (int)((command->getTicks() - startTick)*faktor);
    InstanceItemTimingDiagram* instancePositionInformation = getInstancePositionInformation( command->getDestinationInstance() );
    int eventPosDestinationY = instancePositionInformation->getYPosition();
    int eventPosSourceY;
    if( command->getDestinationInstance() == command->getSourceInstance() )
    {
         eventPosSourceY = eventPosDestinationY;
    }
    else
    {
        eventPosSourceY = getInstancePositionInformation( command->getSourceInstance() )->getYPosition();
    }
    
    
    //Draw event Name
    QString parameterText ="";
    if( itsCheckBoxShowArguments->isChecked() )
    {
        for( auto myEventParameter : command->getReceivedEventParameters() )
        {
            parameterText+=myEventParameter->getItsModelEventArgumentType()->getName()+"="+myEventParameter->getValue()+" ";
        }
    }
    int eventNr = instancePositionInformation->getEventTickCounter(command->getTicks()) + 1;
    QGraphicsTextItem *eventText = addText( QString::number(eventNr) + "." + command->getItsModelEventType()->getName() + " " + parameterText );
    dynamicGraphicItems << eventText;
    
    //Draw Event Line
    if(eventPosSourceY<eventPosDestinationY)
    {
        dynamicGraphicItems << addLine( eventPosX , eventPosSourceY + 8 , eventPosX , eventPosDestinationY - 8 , itsEventStartPen );
        dynamicGraphicItems.last()->setZValue(10);
        dynamicGraphicItems << addLine( eventPosX - 5 , eventPosDestinationY - 13 , eventPosX , eventPosDestinationY - 8 , itsEventStartPen );
        dynamicGraphicItems.last()->setZValue(10);
        dynamicGraphicItems << addLine( eventPosX + 5 , eventPosDestinationY - 13 , eventPosX , eventPosDestinationY - 8 , itsEventStartPen );
        dynamicGraphicItems.last()->setZValue(10);
        int ypos = eventPosDestinationY - ( eventText->boundingRect().height() - 10 ) * instancePositionInformation->getTopPosition( command->getTicks() ) - 14;
        eventText->setPos( eventPosX + 2,  ypos);
    }
    else if(eventPosSourceY>eventPosDestinationY)
    {
        dynamicGraphicItems << addLine( eventPosX , eventPosSourceY - 8 , eventPosX , eventPosDestinationY + 8 , itsEventStartPen );
        dynamicGraphicItems.last()->setZValue(10);
        dynamicGraphicItems << addLine( eventPosX - 5 , eventPosDestinationY + 13 , eventPosX , eventPosDestinationY + 8 , itsEventStartPen );
        dynamicGraphicItems.last()->setZValue(10);
        dynamicGraphicItems << addLine( eventPosX + 5 , eventPosDestinationY + 13 , eventPosX , eventPosDestinationY + 8 , itsEventStartPen );
        dynamicGraphicItems.last()->setZValue(10);
        int ypos = eventPosDestinationY + 8 + ( eventText->boundingRect().height() - 10 ) * instancePositionInformation->getBotPosition( command->getTicks() ) - 14;
    
        eventText->setPos( eventPosX + 2, ypos);
    }
    else
    {
        dynamicGraphicItems << addLine( eventPosX , eventPosDestinationY - 17 , eventPosX , eventPosDestinationY - 8, itsEventStartPen );
        dynamicGraphicItems.last()->setZValue(10);
        dynamicGraphicItems << addLine( eventPosX - 2 , eventPosDestinationY - 17 , eventPosX + 2 , eventPosDestinationY - 17, itsEventStartPen );
        dynamicGraphicItems.last()->setZValue(10);
        dynamicGraphicItems << addLine( eventPosX - 5 , eventPosDestinationY - 13 , eventPosX , eventPosDestinationY - 8, itsEventStartPen );
        dynamicGraphicItems.last()->setZValue(10);
        dynamicGraphicItems << addLine( eventPosX + 5 , eventPosDestinationY - 13 , eventPosX , eventPosDestinationY - 8, itsEventStartPen );
        dynamicGraphicItems.last()->setZValue(10);
    
        int ypos = eventPosDestinationY - ( eventText->boundingRect().height() - 10 ) * instancePositionInformation->getTopPosition( command->getTicks() ) - 14;
        eventText->setPos( eventPosX + 2, ypos );
    }
    
    // draw state text
    QGraphicsTextItem *stateText = instancePositionInformation->getStatTextFromTick( command->getTicks() );
    
    QString myString;
    if( showStateDelta && instancePositionInformation->getLastState() != NULL )
    {
        myString = QString( higliteStateDifference( instancePositionInformation->getLastState(), &command->getStateAfterEventConsumption() ) );
    }
    else
    {
        myString = QString(command->getStateAfterEventConsumption());
    }
    if( hideNonState )
    {
        myString = myString.replace("OMNonState","");
    }
    if( showStateDelta )
    {
        instancePositionInformation->setLastState( (QString*)&command->getStateAfterEventConsumption() );
    }
    myString = myString.replace("|","<b><font color=\"red\">|</font></b>" );
    
    if( stateText == NULL )
    {
        stateText = addText("");
    
        instancePositionInformation->setAllStatesForTick( myString );
        stateText->setHtml( myString );
    
        stateText->setPos(eventPosX + 2, eventPosDestinationY - ( stateText->boundingRect().height() / 2 ) );
        stateText->setZValue(9);
        dynamicGraphicItems << stateText;
        instancePositionInformation->setItsStateTextItem( stateText );
    }
    else
    {
        instancePositionInformation->appendAllStatesForTick( myString );
        stateText->setHtml( instancePositionInformation->getAllStatesForTick( ) );
    }
    //#]
}

void TimingDiagram::resizeScene()
{
    //#[ operation resizeScene()
    int minY = 0;
    for( auto currentInstance : itsInstanceItemTimingDiagram )
    {
        if( currentInstance->getYPosition() < minY )
        {
            minY = currentInstance->getYPosition();
        }
    }
    minY = minY + itsView->height() - 200;
    if( minY > 0 )
    {
        minY = 0;
    }
    itsVerticalScrollBar->setMinimum( minY );
    itsView->setSceneRect(-( instanceLableWidth + 2), - itsView->height() + 100 + itsVerticalScrollBar->value()  ,itsView->width() -2, itsView->height() -2 );
    drawTimeLine();
    //#]
}

void TimingDiagram::setActive(CommandList* commandList)
{
    //#[ operation setActive(CommandList)
    itsStartTickSpinBox->setValue( commandList->getStartTickInTimingDiagram() );
    itsTickRangeSpinBox->setValue( commandList->getTickRangeInTimingDiagram() );
    for( auto myInstanceItem : this->itsInstanceItemTimingDiagram )
    {
        if( myInstanceItem->getItsCommandList() == commandList )
        {
            myInstanceItem->getItsQGraphicsItemGroup()->show();
        }
    }
    //#]
}

void TimingDiagram::setInactive(CommandList* commandList)
{
    //#[ operation setInactive(CommandList)
    commandList->setStartTickInTimingDiagram( itsStartTickSpinBox->value() );
    commandList->setTickRangeInTimingDiagram( itsTickRangeSpinBox->value() );
    for( auto myInstanceItem : this->itsInstanceItemTimingDiagram )
    {
        if( myInstanceItem->getItsCommandList() == commandList )
        {
            myInstanceItem->getItsQGraphicsItemGroup()->hide();
        }
    }
    //#]
}

void TimingDiagram::cleanUpRelations()
{
    if(itsCheckBoxAutoRefresh != NULL)
        {
            itsCheckBoxAutoRefresh = NULL;
        }
    if(itsCheckBoxShowArguments != NULL)
        {
            itsCheckBoxShowArguments = NULL;
        }
    if(itsCommandList != NULL)
        {
            itsCommandList = NULL;
        }
    {
        itsInstanceItemTimingDiagram.clear();
    }
    if(itsStartTickSpinBox != NULL)
        {
            itsStartTickSpinBox = NULL;
        }
    if(itsTickRangeSpinBox != NULL)
        {
            itsTickRangeSpinBox = NULL;
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

QBrush TimingDiagram::itsConstructorBrush(Qt::black);

QPen TimingDiagram::itsConstructorPan(Qt::green, 1, Qt::SolidLine);

QPen TimingDiagram::itsDestuctorPen(Qt::red, 1, Qt::SolidLine);

QPen TimingDiagram::itsEventCreatePen(Qt::red, 1, Qt::DashLine);

QPen TimingDiagram::itsEventEndPen(Qt::green, 1, Qt::SolidLine);

QPen TimingDiagram::itsEventStartPen(Qt::blue, 1, Qt::SolidLine);

QPen TimingDiagram::itsOperationPen(Qt::red, 1, Qt::SolidLine);

QPen TimingDiagram::itsTimeLinePen(Qt::black, 1, Qt::SolidLine);

/*********************************************************************
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\TimingDiagram.cpp
*********************************************************************/
