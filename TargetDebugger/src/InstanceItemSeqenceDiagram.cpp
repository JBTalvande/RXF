/********************************************************************
	Rhapsody	: 9.0.1 
	Login		: Y9DSYU706
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: InstanceItemSeqenceDiagram
//!	Generated Date	: Thu, 4, Nov 2021  
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\InstanceItemSeqenceDiagram.cpp
*********************************************************************/

#include "InstanceItemSeqenceDiagram.h"
#include "CommandList.h"
#include "ModelInstance.h"
#include "TargetInformation.h"
#include <QGraphicsScene>
//## package LogicLevel::Logging::DataContainer

//## class InstanceItemSeqenceDiagram
InstanceItemSeqenceDiagram::InstanceItemSeqenceDiagram(ModelInstance* instance, QGraphicsScene* graphicScene, CommandList* commandList, InstanceItemSeqenceDiagram* neigbourInstanceItem, int prePos) : lastState(NULL)
{
    itsQGraphicsRectItem = NULL;
    itsModelInstance = instance;
    itsLifeLine = NULL;
    itsInstanceGraphicsItem = NULL;
    itsCommandList = commandList;
    //#[ operation InstanceItemSeqenceDiagram(ModelInstance,QGraphicsScene,CommandList,InstanceItemSeqenceDiagram,int)
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
    QGraphicsTextItem *myInstanceNameTextItem = graphicScene->addText(instanceName,QFont("Arial",10));
    myInstanceNameTextItem->setPos(-myInstanceNameTextItem->boundingRect().width() / 2, -myInstanceNameTextItem->boundingRect().height());
    myInstanceNameTextItem->setZValue( 1 );
    myInstanceItemList.append( myInstanceNameTextItem );
    
    QGraphicsRectItem *myRectItem = graphicScene->addRect( myInstanceNameTextItem->boundingRect(),SDinstanceBoxPen,SDinstanceBodyColorBrush);
    myRectItem->setPos(-myRectItem->boundingRect().width() / 2, -myRectItem->boundingRect().height());
    myRectItem->setZValue( 0 );
    itsQGraphicsRectItem = myRectItem;
    myInstanceItemList.append( myRectItem );
    
    itsInstanceGraphicsItem = graphicScene->createItemGroup( myInstanceItemList );
    itsInstanceGraphicsItem->setZValue(100);
    
    int xPosition;
    if( neigbourInstanceItem != NULL )
    {
        xPosition = neigbourInstanceItem->getXPosition() +
                    neigbourInstanceItem->getItsInstanceGraphicsItem()->boundingRect().width() / 2 +
                    itsInstanceGraphicsItem->boundingRect().width() / 2 +
                    20;
    }
    else
    {
        xPosition = itsInstanceGraphicsItem->boundingRect().width() / 2 +
                    20;
    }
    itsLifeLine = graphicScene->addLine( 0,0,0,1000,SDinstanceLifeLine);
    itsLifeLine->setX( xPosition );
    
    itsInstanceGraphicsItem->setX( xPosition );
    if( prePos != -1 )
    { 
        setXPosition( prePos );
    }
    
    //#]
}

InstanceItemSeqenceDiagram::~InstanceItemSeqenceDiagram()
{
    cleanUpRelations();
}

int InstanceItemSeqenceDiagram::getXPosition()
{
    //#[ operation getXPosition()
    if( itsLifeLine->isVisible() )
    {
        return itsInstanceGraphicsItem->pos().x();
    }
    else
    {
        return 0;
    }
    //#]
}

bool InstanceItemSeqenceDiagram::isClicked(int xPosition)
{
    //#[ operation isClicked(int)
    if( ( getXPosition() + (int)itsInstanceGraphicsItem->boundingRect().left() ) < xPosition && ( getXPosition() + itsInstanceGraphicsItem->boundingRect().right() ) > xPosition )
    {
        return true;
    }
    return false;
    //#]
}

void InstanceItemSeqenceDiagram::cleanUpRelations()
{
    if(itsCommandList != NULL)
        {
            itsCommandList = NULL;
        }
    if(itsInstanceGraphicsItem != NULL)
        {
            itsInstanceGraphicsItem = NULL;
        }
    if(itsLifeLine != NULL)
        {
            itsLifeLine = NULL;
        }
    if(itsModelInstance != NULL)
        {
            itsModelInstance = NULL;
        }
    if(itsQGraphicsRectItem != NULL)
        {
            itsQGraphicsRectItem = NULL;
        }
}

QBrush InstanceItemSeqenceDiagram::SDinstanceBodyColorBrush(Qt::lightGray);

QPen InstanceItemSeqenceDiagram::SDinstanceBoxPen(Qt::black, 2, Qt::SolidLine);

QPen InstanceItemSeqenceDiagram::SDinstanceLifeLine(Qt::gray, 1, Qt::DashLine, Qt::FlatCap, Qt::BevelJoin);

/*********************************************************************
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\InstanceItemSeqenceDiagram.cpp
*********************************************************************/
