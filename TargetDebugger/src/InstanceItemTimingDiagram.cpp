/********************************************************************
	Rhapsody	: 9.0.1 
	Login		: Y9DSYU706
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: InstanceItemTimingDiagram
//!	Generated Date	: Thu, 4, Nov 2021  
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\InstanceItemTimingDiagram.cpp
*********************************************************************/

#include "InstanceItemTimingDiagram.h"
#include "CommandList.h"
#include "ModelInstance.h"
#include <QGraphicsScene>
//## package LogicLevel::Logging::DataContainer

//## class InstanceItemTimingDiagram
InstanceItemTimingDiagram::InstanceItemTimingDiagram(ModelInstance* instance, QGraphicsItemGroup* graphicElement, CommandList* commandList) : botCounter(0), currentTickForEvent(-1), currentTickForState(-1), lastState(NULL), topCounter(0)
{
    itsStateTextItem = NULL;
    itsQGraphicsItemGroup = NULL;
    itsModelInstance = NULL;
    itsCommandList = NULL;
    //#[ operation InstanceItemTimingDiagram(ModelInstance,QGraphicsItemGroup,CommandList)
    itsModelInstance = instance;
    itsQGraphicsItemGroup = graphicElement;
    itsCommandList = commandList;
    //#]
}

InstanceItemTimingDiagram::~InstanceItemTimingDiagram()
{
    cleanUpRelations();
}

void InstanceItemTimingDiagram::appendAllStatesForTick(const QString& p_allStatesForTick)
{
    //#[ operation appendAllStatesForTick(QString)
    allStatesForTick = allStatesForTick + " -> " + p_allStatesForTick;
    //#]
}

int InstanceItemTimingDiagram::getBotPosition(int tick)
{
    //#[ operation getBotPosition(int)
    if( tick == currentTickForEvent )
    {
        botCounter++;
    }
    else
    {
        currentTickForEvent = tick;
        botCounter = 1;
    }
    return botCounter;
    //#]
}

int InstanceItemTimingDiagram::getEventTickCounter(int tick)
{
    //#[ operation getEventTickCounter(int)
    if( tick != currentTickForEvent )
    {
        botCounter = 0;
        topCounter = 0;
    }
    return botCounter + topCounter;
    //#]
}

QGraphicsTextItem* InstanceItemTimingDiagram::getStatTextFromTick(int tick)
{
    //#[ operation getStatTextFromTick(int)
    if( tick == currentTickForState )
    {
        return itsStateTextItem;
    }
    else
    {
        currentTickForState = tick;
        return NULL;
    }
    //#]
}

int InstanceItemTimingDiagram::getTopPosition(int tick)
{
    //#[ operation getTopPosition(int)
    if( tick == currentTickForEvent )
    {
        topCounter++;
    }
    else
    {
        currentTickForEvent = tick;
        topCounter = 1;
    }
    return topCounter;
    //#]
}

int InstanceItemTimingDiagram::isPressed(int yPos)
{
    //#[ operation isPressed(int)
    if( ( itsQGraphicsItemGroup->pos().y() + itsQGraphicsItemGroup->boundingRect().height() / 2 ) > yPos && yPos > ( itsQGraphicsItemGroup->pos().y() - itsQGraphicsItemGroup->boundingRect().height() / 2 ) )
    {
        return itsQGraphicsItemGroup->pos().y();
    }
    else
    {
        return 1;
    }
    //#]
}

void InstanceItemTimingDiagram::setNewYPosition(int yPos)
{
    //#[ operation setNewYPosition(int)
    itsQGraphicsItemGroup->setY( yPos );
    //#]
}

void InstanceItemTimingDiagram::cleanUpRelations()
{
    if(itsCommandList != NULL)
        {
            itsCommandList = NULL;
        }
    if(itsModelInstance != NULL)
        {
            itsModelInstance = NULL;
        }
    if(itsQGraphicsItemGroup != NULL)
        {
            itsQGraphicsItemGroup = NULL;
        }
    if(itsStateTextItem != NULL)
        {
            itsStateTextItem = NULL;
        }
}

/*********************************************************************
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\InstanceItemTimingDiagram.cpp
*********************************************************************/
