/*********************************************************************
	Rhapsody	: 9.0.1 
	Login		: Y9DSYU706
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: InstanceItemSeqenceDiagram
//!	Generated Date	: Thu, 4, Nov 2021  
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\InstanceItemSeqenceDiagram.h
*********************************************************************/

#ifndef InstanceItemSeqenceDiagram_H
#define InstanceItemSeqenceDiagram_H

#include "DataContainer.h"
#include <QGraphicsItemGroup>
class CommandList;

class ModelInstance;

class TargetInformation;

//## package LogicLevel::Logging::DataContainer

//## class InstanceItemSeqenceDiagram
class InstanceItemSeqenceDiagram {
    ////    Constructors and destructors    ////
    
public :

    //## operation InstanceItemSeqenceDiagram(ModelInstance,QGraphicsScene,CommandList,InstanceItemSeqenceDiagram,int)
    InstanceItemSeqenceDiagram(ModelInstance* instance, QGraphicsScene* graphicScene, CommandList* commandList, InstanceItemSeqenceDiagram* neigbourInstanceItem, int prePos);
    
    ~InstanceItemSeqenceDiagram();
    
    ////    Operations    ////
    
    //## operation getXPosition()
    int getXPosition();
    
    //## operation isClicked(int)
    bool isClicked(int xPosition);
    
    //## operation setXPosition(int)
    inline void setXPosition(int xPosition);
    
    ////    Additional operations    ////
    
    inline QString* getLastState() const
    {
        return lastState;
    }
    
    inline void setLastState(QString* p_lastState)
    {
        lastState = p_lastState;
    }
    
    inline static QBrush* getSDinstanceBodyColorBrush()
    {
        return (QBrush*) &SDinstanceBodyColorBrush;
    }
    
    inline static QPen* getSDinstanceBoxPen()
    {
        return (QPen*) &SDinstanceBoxPen;
    }
    
    inline static QPen* getSDinstanceLifeLine()
    {
        return (QPen*) &SDinstanceLifeLine;
    }
    
    inline CommandList* getItsCommandList() const
    {
        return itsCommandList;
    }
    
    inline void setItsCommandList(CommandList* p_CommandList)
    {
        itsCommandList = p_CommandList;
    }
    
    inline QGraphicsItemGroup* getItsInstanceGraphicsItem() const
    {
        return itsInstanceGraphicsItem;
    }
    
    inline void setItsInstanceGraphicsItem(QGraphicsItemGroup* p_QGraphicsItemGroup)
    {
        itsInstanceGraphicsItem = p_QGraphicsItemGroup;
    }
    
    inline QGraphicsLineItem* getItsLifeLine() const
    {
        return itsLifeLine;
    }
    
    inline void setItsLifeLine(QGraphicsLineItem* p_QGraphicsLineItem)
    {
        itsLifeLine = p_QGraphicsLineItem;
    }
    
    inline ModelInstance* getItsModelInstance() const
    {
        return itsModelInstance;
    }
    
    inline void setItsModelInstance(ModelInstance* p_ModelInstance)
    {
        itsModelInstance = p_ModelInstance;
    }
    
    inline QGraphicsRectItem* getItsQGraphicsRectItem() const
    {
        return itsQGraphicsRectItem;
    }
    
    inline void setItsQGraphicsRectItem(QGraphicsRectItem* p_QGraphicsRectItem)
    {
        itsQGraphicsRectItem = p_QGraphicsRectItem;
    }

protected :

    void cleanUpRelations();
    
    ////    Attributes    ////

private :

    QString* lastState;		//## attribute lastState
    
    ////    Relations and components    ////

protected :

    static QBrush SDinstanceBodyColorBrush;
    
    static QPen SDinstanceBoxPen;
    
    static QPen SDinstanceLifeLine;
    
    CommandList* itsCommandList;
    
    QGraphicsItemGroup* itsInstanceGraphicsItem;
    
    QGraphicsLineItem* itsLifeLine;
    
    ModelInstance* itsModelInstance;
    
    QGraphicsRectItem* itsQGraphicsRectItem;
};

inline void InstanceItemSeqenceDiagram::setXPosition(int xPosition)
{
    //#[ operation setXPosition(int)
    itsInstanceGraphicsItem->setX( xPosition );
    itsLifeLine->setX( xPosition );
    //#]
}

#endif
/*********************************************************************
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\InstanceItemSeqenceDiagram.h
*********************************************************************/
