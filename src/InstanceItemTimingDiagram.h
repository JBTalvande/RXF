/*********************************************************************
	Rhapsody	: 9.0.1 
	Login		: Y9DSYU706
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: InstanceItemTimingDiagram
//!	Generated Date	: Thu, 4, Nov 2021  
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\InstanceItemTimingDiagram.h
*********************************************************************/

#ifndef InstanceItemTimingDiagram_H
#define InstanceItemTimingDiagram_H

#include "DataContainer.h"
#include <QGraphicsItemGroup>
class CommandList;

class ModelInstance;

//## package LogicLevel::Logging::DataContainer

//## class InstanceItemTimingDiagram
class InstanceItemTimingDiagram {
    ////    Constructors and destructors    ////
    
public :

    //## operation InstanceItemTimingDiagram(ModelInstance,QGraphicsItemGroup,CommandList)
    InstanceItemTimingDiagram(ModelInstance* instance, QGraphicsItemGroup* graphicElement, CommandList* commandList);
    
    ~InstanceItemTimingDiagram();
    
    ////    Operations    ////
    
    //## operation appendAllStatesForTick(QString)
    void appendAllStatesForTick(const QString& p_allStatesForTick);
    
    //## operation getBotPosition(int)
    int getBotPosition(int tick);
    
    //## operation getEventTickCounter(int)
    int getEventTickCounter(int tick);
    
    //## operation getStatTextFromTick(int)
    QGraphicsTextItem* getStatTextFromTick(int tick);
    
    //## operation getTopPosition(int)
    int getTopPosition(int tick);
    
    //## operation getYPosition()
    inline int getYPosition();
    
    //## operation isPressed(int)
    int isPressed(int yPos);
    
    //## operation setNewYPosition(int)
    void setNewYPosition(int yPos);
    
    ////    Additional operations    ////
    
    inline QString getAllStatesForTick() const
    {
        return allStatesForTick;
    }
    
    inline void setAllStatesForTick(QString p_allStatesForTick)
    {
        allStatesForTick = p_allStatesForTick;
    }
    
    inline int getBotCounter() const
    {
        return botCounter;
    }
    
    inline void setBotCounter(int p_botCounter)
    {
        botCounter = p_botCounter;
    }
    
    inline int getCurrentTickForEvent() const
    {
        return currentTickForEvent;
    }
    
    inline void setCurrentTickForEvent(int p_currentTickForEvent)
    {
        currentTickForEvent = p_currentTickForEvent;
    }
    
    inline int getCurrentTickForState() const
    {
        return currentTickForState;
    }
    
    inline void setCurrentTickForState(int p_currentTickForState)
    {
        currentTickForState = p_currentTickForState;
    }
    
    inline QString* getLastState() const
    {
        return lastState;
    }
    
    inline void setLastState(QString* p_lastState)
    {
        lastState = p_lastState;
    }
    
    inline int getOldInstanceYPos() const
    {
        return oldInstanceYPos;
    }
    
    inline void setOldInstanceYPos(int p_oldInstanceYPos)
    {
        oldInstanceYPos = p_oldInstanceYPos;
    }
    
    inline int getTopCounter() const
    {
        return topCounter;
    }
    
    inline void setTopCounter(int p_topCounter)
    {
        topCounter = p_topCounter;
    }
    
    inline CommandList* getItsCommandList() const
    {
        return itsCommandList;
    }
    
    inline void setItsCommandList(CommandList* p_CommandList)
    {
        itsCommandList = p_CommandList;
    }
    
    inline ModelInstance* getItsModelInstance() const
    {
        return itsModelInstance;
    }
    
    inline void setItsModelInstance(ModelInstance* p_ModelInstance)
    {
        itsModelInstance = p_ModelInstance;
    }
    
    inline QGraphicsItemGroup* getItsQGraphicsItemGroup() const
    {
        return itsQGraphicsItemGroup;
    }
    
    inline void setItsQGraphicsItemGroup(QGraphicsItemGroup* p_QGraphicsItemGroup)
    {
        itsQGraphicsItemGroup = p_QGraphicsItemGroup;
    }
    
    inline QGraphicsTextItem* getItsStateTextItem() const
    {
        return itsStateTextItem;
    }
    
    inline void setItsStateTextItem(QGraphicsTextItem* p_QGraphicsTextItem)
    {
        itsStateTextItem = p_QGraphicsTextItem;
    }

protected :

    void cleanUpRelations();
    
    ////    Attributes    ////

private :

    QString allStatesForTick;		//## attribute allStatesForTick
    
    int botCounter;		//## attribute botCounter
    
    int currentTickForEvent;		//## attribute currentTickForEvent
    
    int currentTickForState;		//## attribute currentTickForState
    
    QString* lastState;		//## attribute lastState
    
    int oldInstanceYPos;		//## attribute oldInstanceYPos
    
    int topCounter;		//## attribute topCounter
    
    ////    Relations and components    ////

protected :

    CommandList* itsCommandList;
    
    ModelInstance* itsModelInstance;
    
    QGraphicsItemGroup* itsQGraphicsItemGroup;
    
    QGraphicsTextItem* itsStateTextItem;
};

inline int InstanceItemTimingDiagram::getYPosition()
{
    //#[ operation getYPosition()
    if( itsQGraphicsItemGroup->isVisible() )
    {
        return itsQGraphicsItemGroup->y();
    }
    else
    {
        return 0;
    }
    //#]
}

#endif
/*********************************************************************
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\InstanceItemTimingDiagram.h
*********************************************************************/
