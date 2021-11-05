/*********************************************************************
	Rhapsody	: 9.0.1 
	Login		: Y9DSYU706
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: SequenceDiagram
//!	Generated Date	: Thu, 4, Nov 2021  
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\SequenceDiagram.h
*********************************************************************/

#ifndef SequenceDiagram_H
#define SequenceDiagram_H

#include <QVector>
#include <QList>
#include "InstanceItemSeqenceDiagram.h"
#include <QGraphicsScene>
#include <QTimer>
#include <QGraphicsSceneMouseEvent>
#include <QScrollBar>
#include <QModelIndex>
#include <QCheckBox>
class CommandConstructor;

class CommandDestructor;

class CommandEventCreated;

class CommandEventEndDispatch;

class CommandEventStartDispatch;

class CommandIntVal;

class CommandList;

class CommandOperationCall;

class CommandTraceEvent;

class ModelEventArgumentType;

class ModelEventType;

class ModelInstance;

class ReceivedEventParameter;

//## package GUI

//## class SequenceDiagram
class SequenceDiagram : public QGraphicsScene {
Q_OBJECT
    ////    Constructors and destructors    ////
    
public :

    //## operation SequenceDiagram()
    SequenceDiagram();
    
    //## operation ~SequenceDiagram()
    ~SequenceDiagram();
    
    ////    Operations    ////
    
    //## operation changeCommandList(QModelIndex)
    Q_SLOT void changeCommandList(QModelIndex modelIndex);
    
    //## operation init()
    void init();
    
    //## operation reDraw()
    Q_SLOT void reDraw();
    
    //## operation setItsCommandList(CommandList)
    void setItsCommandList(CommandList* commandList);
    
    //## operation setVerticalScrollBarValue()
    Q_SLOT void setVerticalScrollBarValue();
    
    //## operation updateInstanceLine(ModelInstance,int)
    void updateInstanceLine(ModelInstance* instance, int pos);
    
    //## operation updateInstanceLines()
    void updateInstanceLines();

protected :

    //## operation mouseMoveEvent(QGraphicsSceneMouseEvent)
    void mouseMoveEvent(QGraphicsSceneMouseEvent* mouseEvent);
    
    //## operation mousePressEvent(QGraphicsSceneMouseEvent)
    void mousePressEvent(QGraphicsSceneMouseEvent* mouseEvent);
    
    //## operation mouseReleaseEvent(QGraphicsSceneMouseEvent)
    void mouseReleaseEvent(QGraphicsSceneMouseEvent* mouseEvent);
    
    //## operation wheelEvent(QGraphicsSceneWheelEvent)
    void wheelEvent(QGraphicsSceneWheelEvent* wheelEvent);

private :

    //## operation drawCommands()
    void drawCommands();
    
    //## operation getInstanceItem(ModelInstance,QGraphicsScene)
    InstanceItemSeqenceDiagram* getInstanceItem(ModelInstance* instance, QGraphicsScene* graphicScene);
    
    //## operation getInstancePosition(ModelInstance,QGraphicsScene)
    unsigned int getInstancePosition(ModelInstance* instance, QGraphicsScene* graphicScene);
    
    //## operation higliteStateDifference(QString,QString)
    QString higliteStateDifference(const QString* lastState, const QString* newState);
    
    //## operation printConstructor(CommandConstructor,int)
    void printConstructor(CommandConstructor* constructorCall, int printPosition);
    
    //## operation printDestructor(CommandDestructor,int)
    void printDestructor(CommandDestructor* destructorCall, int printPosition);
    
    //## operation printErrorHandlerReached(unsigned int)
    void printErrorHandlerReached(unsigned int position);
    
    //## operation printIntValue(CommandIntVal,int)
    void printIntValue(CommandIntVal* intValCommand, int printPosition);
    
    //## operation printOperationBufferOverflow(unsigned int)
    void printOperationBufferOverflow(unsigned int position);
    
    //## operation printOperationCalled(CommandOperationCall,int)
    void printOperationCalled(CommandOperationCall* operationCall, int printPosition);
    
    //## operation printTraceEvent(CommandTraceEvent,int)
    void printTraceEvent(CommandTraceEvent* traceEvent, int printPosition);
    
    //## operation printTrippleEvent(CommandEventCreated)
    void printTrippleEvent(CommandEventCreated* createEvent);
    
    //## operation setActive(CommandList)
    void setActive(CommandList* commandList);
    
    //## operation setInactive(CommandList)
    void setInactive(CommandList* commandList);
    
    ////    Additional operations    ////

public :

    inline static bool getHideNonState()
    {
        return hideNonState;
    }
    
    inline static void setHideNonState(bool p_hideNonState)
    {
        hideNonState = p_hideNonState;
    }
    
    inline int getInstanceDragStart() const
    {
        return instanceDragStart;
    }
    
    inline void setInstanceDragStart(int p_instanceDragStart)
    {
        instanceDragStart = p_instanceDragStart;
    }
    
    inline unsigned int getOffset() const
    {
        return offset;
    }
    
    inline void setOffset(unsigned int p_offset)
    {
        offset = p_offset;
    }
    
    inline static unsigned int getPrintSessionNumber()
    {
        return printSessionNumber;
    }
    
    inline static void setPrintSessionNumber(unsigned int p_printSessionNumber)
    {
        printSessionNumber = p_printSessionNumber;
    }
    
    inline QTimer* getRefreshTimer() const
    {
        return (QTimer*) &refreshTimer;
    }
    
    inline int getScenePositionDragStart() const
    {
        return scenePositionDragStart;
    }
    
    inline void setScenePositionDragStart(int p_scenePositionDragStart)
    {
        scenePositionDragStart = p_scenePositionDragStart;
    }
    
    inline int getSelfMessageOpen() const
    {
        return selfMessageOpen;
    }
    
    inline void setSelfMessageOpen(int p_selfMessageOpen)
    {
        selfMessageOpen = p_selfMessageOpen;
    }
    
    inline static bool getShowStateDelta()
    {
        return showStateDelta;
    }
    
    inline static void setShowStateDelta(bool p_showStateDelta)
    {
        showStateDelta = p_showStateDelta;
    }
    
    inline unsigned int getStartCommand() const
    {
        return startCommand;
    }
    
    inline void setStartCommand(unsigned int p_startCommand)
    {
        startCommand = p_startCommand;
    }
    
    inline int getVerticalCommandSpace() const
    {
        return verticalCommandSpace;
    }
    
    inline void setVerticalCommandSpace(int p_verticalCommandSpace)
    {
        verticalCommandSpace = p_verticalCommandSpace;
    }
    
    inline static QPen* getCompleteLifeLinePen()
    {
        return (QPen*) &completeLifeLinePen;
    }
    
    inline static QBrush* getConstructorBrush()
    {
        return (QBrush*) &constructorBrush;
    }
    
    inline static QBrush* getDestructionBrush()
    {
        return (QBrush*) &destructionBrush;
    }
    
    inline static QFont* getDestructionFont()
    {
        return (QFont*) &destructionFont;
    }
    
    inline static QPen* getErrorHandlerPan()
    {
        return (QPen*) &errorHandlerPan;
    }
    
    inline static QPen* getEventLineCreatedPen()
    {
        return (QPen*) &eventLineCreatedPen;
    }
    
    inline static QPen* getEventLineEndPen()
    {
        return (QPen*) &eventLineEndPen;
    }
    
    inline static QPen* getEventLineStartPen()
    {
        return (QPen*) &eventLineStartPen;
    }
    
    inline static QFont* getInitialisationFont()
    {
        return (QFont*) &initialisationFont;
    }
    
    inline static QBrush* getIntValBrush()
    {
        return (QBrush*) &intValBrush;
    }
    
    inline CommandList* getItsCommandList() const
    {
        return itsCommandList;
    }
    
    inline InstanceItemSeqenceDiagram* getItsInstanceDragItem() const
    {
        return itsInstanceDragItem;
    }
    
    inline void setItsInstanceDragItem(InstanceItemSeqenceDiagram* p_InstanceItemSeqenceDiagram)
    {
        itsInstanceDragItem = p_InstanceItemSeqenceDiagram;
    }
    
    inline QCheckBox* getItsRefreshCheckBox() const
    {
        return itsRefreshCheckBox;
    }
    
    inline void setItsRefreshCheckBox(QCheckBox* p_QCheckBox)
    {
        itsRefreshCheckBox = p_QCheckBox;
    }
    
    inline QScrollBar* getItsVerticalScrollBar() const
    {
        return itsVerticalScrollBar;
    }
    
    inline void setItsVerticalScrollBar(QScrollBar* p_QScrollBar)
    {
        itsVerticalScrollBar = p_QScrollBar;
    }
    
    inline QGraphicsView* getItsView() const
    {
        return itsView;
    }
    
    inline void setItsView(QGraphicsView* p_QGraphicsView)
    {
        itsView = p_QGraphicsView;
    }
    
    inline static QBrush* getStateBrush()
    {
        return (QBrush*) &stateBrush;
    }
    
    inline static QPen* getTransparentPen()
    {
        return (QPen*) &transparentPen;
    }
    
    inline static QPen* getUncompleteLifeLinePen()
    {
        return (QPen*) &uncompleteLifeLinePen;
    }

protected :

    void cleanUpRelations();
    
    ////    Attributes    ////

private :

    QVector<QGraphicsItem*> dynamicGraphicItems;		//## attribute dynamicGraphicItems
    
    static bool hideNonState;		//## attribute hideNonState
    
    int instanceDragStart;		//## attribute instanceDragStart
    
    unsigned int offset;		//## attribute offset
    
    static unsigned int printSessionNumber;		//## attribute printSessionNumber
    
    QTimer refreshTimer;		//## attribute refreshTimer
    
    int scenePositionDragStart;		//## attribute scenePositionDragStart
    
    int selfMessageOpen;		//## attribute selfMessageOpen
    
    static bool showStateDelta;		//## attribute showStateDelta
    
    unsigned int startCommand;		//## attribute startCommand
    
    int verticalCommandSpace;		//## attribute verticalCommandSpace
    
    ////    Relations and components    ////

protected :

    static QPen completeLifeLinePen;
    
    static QBrush constructorBrush;
    
    static QBrush destructionBrush;
    
    static QFont destructionFont;
    
    QList<QPair<InstanceItemSeqenceDiagram*,int>*> dragItemList;
    
    static QPen errorHandlerPan;
    
    static QPen eventLineCreatedPen;
    
    static QPen eventLineEndPen;
    
    static QPen eventLineStartPen;
    
    static QFont initialisationFont;
    
    static QBrush intValBrush;
    
    CommandList* itsCommandList;
    
    InstanceItemSeqenceDiagram* itsInstanceDragItem;
    
    QList<InstanceItemSeqenceDiagram*> itsInstanceItemList;
    
    QCheckBox* itsRefreshCheckBox;
    
    QScrollBar* itsVerticalScrollBar;
    
    QGraphicsView* itsView;
    
    static QBrush stateBrush;
    
    static QPen transparentPen;
    
    static QPen uncompleteLifeLinePen;
};

#endif
/*********************************************************************
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\SequenceDiagram.h
*********************************************************************/
