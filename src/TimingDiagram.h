/*********************************************************************
	Rhapsody	: 9.0.1 
	Login		: Y9DSYU706
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: TimingDiagram
//!	Generated Date	: Thu, 4, Nov 2021  
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\TimingDiagram.h
*********************************************************************/

#ifndef TimingDiagram_H
#define TimingDiagram_H

#include <QVector>
#include <QList>
#include "InstanceItemTimingDiagram.h"
#include <QCheckBox.h>
#include <QGraphicsItem.h>
#include <QGraphicsScene.h>
#include <QSpinBox.h>
#include <QTimer.h>
#include <QModelIndex>
class Command;

class CommandConstructor;

class CommandDestructor;

class CommandEventCreated;

class CommandEventEndDispatch;

class CommandEventStartDispatch;

class CommandList;

class CommandOperationCall;

class CommandTraceEvent;

class ModelEventType;

class ModelInstance;

class QGraphicsSceneEvent;

class QGraphicsView;

class QScrollBar;

class TargetInformation;

//## package GUI

//## class TimingDiagram
class TimingDiagram : public QGraphicsScene {
Q_OBJECT
private :

    enum dragModes {
        DragInstance,
        DragDiagram,
        DragNone,
        DragInstanceWidth
    };
    
    ////    Constructors and destructors    ////

public :

    //## operation TimingDiagram()
    TimingDiagram();
    
    //## operation ~TimingDiagram()
    ~TimingDiagram();
    
    ////    Operations    ////
    
    //## operation changeCommandList(QModelIndex)
    Q_SLOT void changeCommandList(QModelIndex index);
    
    //## operation changeYValue()
    Q_SLOT void changeYValue();
    
    //## operation init()
    void init();
    
    //## operation reDraw()
    Q_SLOT void reDraw();
    
    //## operation setItsCommandList(CommandList)
    void setItsCommandList(CommandList* commandList);

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

    //## operation cleanDynamicGraphicItems()
    void cleanDynamicGraphicItems();
    
    //## operation cleanTimelineGraphicItems()
    void cleanTimelineGraphicItems();
    
    //## operation drawCommands()
    int drawCommands();
    
    //## operation drawTimeLine()
    void drawTimeLine();
    
    //## operation getInstancePositionInformation(ModelInstance)
    InstanceItemTimingDiagram* getInstancePositionInformation(ModelInstance* instance);
    
    //## operation higliteStateDifference(QString,QString)
    QString higliteStateDifference(const QString* lastState, const QString* newState);
    
    //## operation printConstructor(CommandConstructor)
    void printConstructor(CommandConstructor* command);
    
    //## operation printCreateEvent(CommandEventCreated)
    void printCreateEvent(CommandEventCreated* command);
    
    //## operation printDestructor(CommandDestructor)
    void printDestructor(CommandDestructor* command);
    
    //## operation printEndEvent(CommandEventEndDispatch)
    void printEndEvent(CommandEventEndDispatch* command);
    
    //## operation printErrorHandlerReached(Command)
    void printErrorHandlerReached(Command* command);
    
    //## operation printOperationBufferOverflow(Command)
    void printOperationBufferOverflow(Command* command);
    
    //## operation printOperationCalled(CommandOperationCall)
    void printOperationCalled(CommandOperationCall* command);
    
    //## operation printTraceEvent(CommandTraceEvent)
    void printTraceEvent(CommandTraceEvent* command);
    
    //## operation resizeScene()
    void resizeScene();
    
    //## operation setActive(CommandList)
    void setActive(CommandList* commandList);
    
    //## operation setInactive(CommandList)
    void setInactive(CommandList* commandList);
    
    ////    Additional operations    ////

public :

    inline dragModes getDrag() const
    {
        return drag;
    }
    
    inline void setDrag(dragModes p_drag)
    {
        drag = p_drag;
    }
    
    inline InstanceItemTimingDiagram* getDragInstance() const
    {
        return dragInstance;
    }
    
    inline void setDragInstance(InstanceItemTimingDiagram* p_dragInstance)
    {
        dragInstance = p_dragInstance;
    }
    
    inline int getDrawingWidth() const
    {
        return drawingWidth;
    }
    
    inline void setDrawingWidth(int p_drawingWidth)
    {
        drawingWidth = p_drawingWidth;
    }
    
    inline int getEndTick() const
    {
        return endTick;
    }
    
    inline void setEndTick(int p_endTick)
    {
        endTick = p_endTick;
    }
    
    inline float getFaktor() const
    {
        return faktor;
    }
    
    inline void setFaktor(float p_faktor)
    {
        faktor = p_faktor;
    }
    
    inline static bool getHideNonState()
    {
        return hideNonState;
    }
    
    inline static void setHideNonState(bool p_hideNonState)
    {
        hideNonState = p_hideNonState;
    }
    
    inline int getInstanceDragMouseButton() const
    {
        return instanceDragMouseButton;
    }
    
    inline void setInstanceDragMouseButton(int p_instanceDragMouseButton)
    {
        instanceDragMouseButton = p_instanceDragMouseButton;
    }
    
    inline int getInstanceLableHeight() const
    {
        return instanceLableHeight;
    }
    
    inline void setInstanceLableHeight(int p_instanceLableHeight)
    {
        instanceLableHeight = p_instanceLableHeight;
    }
    
    inline int getInstanceLableWidth() const
    {
        return instanceLableWidth;
    }
    
    inline void setInstanceLableWidth(int p_instanceLableWidth)
    {
        instanceLableWidth = p_instanceLableWidth;
    }
    
    inline int getOldInstanceLableWidth() const
    {
        return oldInstanceLableWidth;
    }
    
    inline void setOldInstanceLableWidth(int p_oldInstanceLableWidth)
    {
        oldInstanceLableWidth = p_oldInstanceLableWidth;
    }
    
    inline int getOldInstanceYPos() const
    {
        return oldInstanceYPos;
    }
    
    inline void setOldInstanceYPos(int p_oldInstanceYPos)
    {
        oldInstanceYPos = p_oldInstanceYPos;
    }
    
    inline int getOldStartTick() const
    {
        return oldStartTick;
    }
    
    inline void setOldStartTick(int p_oldStartTick)
    {
        oldStartTick = p_oldStartTick;
    }
    
    inline int getOldStartTickXPos() const
    {
        return oldStartTickXPos;
    }
    
    inline void setOldStartTickXPos(int p_oldStartTickXPos)
    {
        oldStartTickXPos = p_oldStartTickXPos;
    }
    
    inline int getOldViewHeight() const
    {
        return oldViewHeight;
    }
    
    inline void setOldViewHeight(int p_oldViewHeight)
    {
        oldViewHeight = p_oldViewHeight;
    }
    
    inline int getOldViewWidth() const
    {
        return oldViewWidth;
    }
    
    inline void setOldViewWidth(int p_oldViewWidth)
    {
        oldViewWidth = p_oldViewWidth;
    }
    
    inline QTimer* getRefreshTimer() const
    {
        return (QTimer*) &refreshTimer;
    }
    
    inline static bool getShowStateDelta()
    {
        return showStateDelta;
    }
    
    inline static void setShowStateDelta(bool p_showStateDelta)
    {
        showStateDelta = p_showStateDelta;
    }
    
    inline int getStartTick() const
    {
        return startTick;
    }
    
    inline void setStartTick(int p_startTick)
    {
        startTick = p_startTick;
    }
    
    inline int getTickRange() const
    {
        return tickRange;
    }
    
    inline void setTickRange(int p_tickRange)
    {
        tickRange = p_tickRange;
    }
    
    inline QCheckBox* getItsCheckBoxAutoRefresh() const
    {
        return itsCheckBoxAutoRefresh;
    }
    
    inline void setItsCheckBoxAutoRefresh(QCheckBox* p_QCheckBox)
    {
        itsCheckBoxAutoRefresh = p_QCheckBox;
    }
    
    inline QCheckBox* getItsCheckBoxShowArguments() const
    {
        return itsCheckBoxShowArguments;
    }
    
    inline void setItsCheckBoxShowArguments(QCheckBox* p_QCheckBox)
    {
        itsCheckBoxShowArguments = p_QCheckBox;
    }
    
    inline CommandList* getItsCommandList() const
    {
        return itsCommandList;
    }
    
    inline static QBrush* getItsConstructorBrush()
    {
        return (QBrush*) &itsConstructorBrush;
    }
    
    inline static QPen* getItsConstructorPan()
    {
        return (QPen*) &itsConstructorPan;
    }
    
    inline static QPen* getItsDestuctorPen()
    {
        return (QPen*) &itsDestuctorPen;
    }
    
    inline static QPen* getItsEventCreatePen()
    {
        return (QPen*) &itsEventCreatePen;
    }
    
    inline static QPen* getItsEventEndPen()
    {
        return (QPen*) &itsEventEndPen;
    }
    
    inline static QPen* getItsEventStartPen()
    {
        return (QPen*) &itsEventStartPen;
    }
    
    inline static QPen* getItsOperationPen()
    {
        return (QPen*) &itsOperationPen;
    }
    
    inline QSpinBox* getItsStartTickSpinBox() const
    {
        return itsStartTickSpinBox;
    }
    
    inline void setItsStartTickSpinBox(QSpinBox* p_QSpinBox)
    {
        itsStartTickSpinBox = p_QSpinBox;
    }
    
    inline QSpinBox* getItsTickRangeSpinBox() const
    {
        return itsTickRangeSpinBox;
    }
    
    inline void setItsTickRangeSpinBox(QSpinBox* p_QSpinBox)
    {
        itsTickRangeSpinBox = p_QSpinBox;
    }
    
    inline static QPen* getItsTimeLinePen()
    {
        return (QPen*) &itsTimeLinePen;
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

protected :

    void cleanUpRelations();
    
    ////    Attributes    ////

private :

    static const int TICKSPACE_TD;		//## attribute TICKSPACE_TD
    
    dragModes drag;		//## attribute drag
    
    InstanceItemTimingDiagram* dragInstance;		//## attribute dragInstance
    
    int drawingWidth;		//## attribute drawingWidth
    
    QVector<QGraphicsItem*> dynamicGraphicItems;		//## attribute dynamicGraphicItems
    
    int endTick;		//## attribute endTick
    
    float faktor;		//## attribute faktor
    
    static bool hideNonState;		//## attribute hideNonState
    
    int instanceDragMouseButton;		//## attribute instanceDragMouseButton
    
    int instanceLableHeight;		//## attribute instanceLableHeight
    
    int instanceLableWidth;		//## attribute instanceLableWidth
    
    int oldInstanceLableWidth;		//## attribute oldInstanceLableWidth
    
    int oldInstanceYPos;		//## attribute oldInstanceYPos
    
    int oldStartTick;		//## attribute oldStartTick
    
    int oldStartTickXPos;		//## attribute oldStartTickXPos
    
    int oldViewHeight;		//## attribute oldViewHeight
    
    int oldViewWidth;		//## attribute oldViewWidth
    
    QTimer refreshTimer;		//## attribute refreshTimer
    
    static bool showStateDelta;		//## attribute showStateDelta
    
    int startTick;		//## attribute startTick
    
    int tickRange;		//## attribute tickRange
    
    QVector<QGraphicsItem*> timeLineGraphicItems;		//## attribute timeLineGraphicItems
    
    ////    Relations and components    ////

protected :

    QCheckBox* itsCheckBoxAutoRefresh;
    
    QCheckBox* itsCheckBoxShowArguments;
    
    CommandList* itsCommandList;
    
    static QBrush itsConstructorBrush;
    
    static QPen itsConstructorPan;
    
    static QPen itsDestuctorPen;
    
    static QPen itsEventCreatePen;
    
    static QPen itsEventEndPen;
    
    static QPen itsEventStartPen;
    
    QList<InstanceItemTimingDiagram*> itsInstanceItemTimingDiagram;
    
    static QPen itsOperationPen;
    
    QSpinBox* itsStartTickSpinBox;
    
    QSpinBox* itsTickRangeSpinBox;
    
    static QPen itsTimeLinePen;
    
    QScrollBar* itsVerticalScrollBar;
    
    QGraphicsView* itsView;
};

#endif
/*********************************************************************
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\TimingDiagram.h
*********************************************************************/
