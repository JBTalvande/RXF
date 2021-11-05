/*********************************************************************
	Rhapsody	: 9.0.1 
	Login		: Y9DSYU706
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: BreakPoints
//!	Generated Date	: Thu, 4, Nov 2021  
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\BreakPoints.h
*********************************************************************/

#ifndef BreakPoints_H
#define BreakPoints_H

#include "ModelClassState.h"
#include "ModelEventType.h"
#include <QWidget>
#include <QStringListModel>
#include "ModelInstance.h"
class ModelInstance;

class Sender;

class TargetInformation;

class TargetList;

//## package GUI

//## class BreakPoints

namespace Ui {
class BreakPoints;
}

class BreakPoints : public QWidget {
Q_OBJECT
public :

    //## class BreakPoints::BreakPoint
    class BreakPoint {
        ////    Constructors and destructors    ////
        
    public :
    
        //## operation BreakPoint(ModelInstance,ModelEventType,ModelClassState)
        BreakPoint(ModelInstance* instance, ModelEventType* event, ModelClassState* state);
        
        ////    Additional operations    ////
        
        inline ModelEventType* getEvent() const
        {
            return event;
        }
        
        inline void setEvent(ModelEventType* p_event)
        {
            event = p_event;
        }
        
        inline ModelInstance* getInstance() const
        {
            return instance;
        }
        
        inline void setInstance(ModelInstance* p_instance)
        {
            instance = p_instance;
        }
        
        inline ModelClassState* getState() const
        {
            return state;
        }
        
        inline void setState(ModelClassState* p_state)
        {
            state = p_state;
        }
        
        ////    Attributes    ////
        
        ModelEventType* event;		//## attribute event
        
        ModelInstance* instance;		//## attribute instance
        
        ModelClassState* state;		//## attribute state
    };
    
    ////    Constructors and destructors    ////
    
    //## operation BreakPoints()
    BreakPoints();
    
    //## operation ~BreakPoints()
    ~BreakPoints();
    
    ////    Operations    ////
    
    //## operation checkInsertPossible()
    Q_SLOT void checkInsertPossible();
    
    //## operation classChanged()
    Q_SLOT void classChanged();
    
    //## operation insertBreakPoint()
    Q_SLOT void insertBreakPoint();
    
    //## operation removeAllBreakpoints()
    Q_SLOT void removeAllBreakpoints();
    
    //## operation removeSelectedBreakpoint()
    Q_SLOT void removeSelectedBreakpoint();
    
    //## operation showWindow()
    Q_SLOT void showWindow();
    
    //## operation targetChanged()
    Q_SLOT void targetChanged();
    
    //## operation updateClasses()
    void updateClasses();
    
    //## operation updateEvents()
    void updateEvents();
    
    //## operation updateTargets()
    void updateTargets();

private :

    //## operation addBreakpoint(ModelInstance,ModelEventType,ModelClassState)
    void addBreakpoint(ModelInstance* instance, ModelEventType* event, ModelClassState* state);
    
    //## operation connectSignals()
    void connectSignals();
    
    //## operation disconnectSignals()
    void disconnectSignals();
    
    //## operation removeBreakpoint(BreakPoint)
    void removeBreakpoint(BreakPoint* breakPoint);
    
    ////    Additional operations    ////

public :

    inline Ui::BreakPoints* getUi() const
    {
        return ui;
    }
    
    inline void setUi(Ui::BreakPoints* p_ui)
    {
        ui = p_ui;
    }
    
    inline ModelEventType* getItsEventFreeBreakpoint() const
    {
        return (ModelEventType*) &itsEventFreeBreakpoint;
    }
    
    inline QStandardItemModel* getItsModelBreakpoints() const
    {
        return itsModelBreakpoints;
    }
    
    inline void setItsModelBreakpoints(QStandardItemModel* p_QStandardItemModel)
    {
        itsModelBreakpoints = p_QStandardItemModel;
    }
    
    inline Sender* getItsSender() const
    {
        return itsSender;
    }
    
    inline void setItsSender(Sender* p_Sender)
    {
        itsSender = p_Sender;
    }
    
    inline ModelClassState* getItsStateFreeBreakpoint() const
    {
        return (ModelClassState*) &itsStateFreeBreakpoint;
    }
    
    inline TargetInformation* getItsTargetInformation() const
    {
        return itsTargetInformation;
    }
    
    inline void setItsTargetInformation(TargetInformation* p_TargetInformation)
    {
        itsTargetInformation = p_TargetInformation;
    }

protected :

    void cleanUpRelations();
    
    ////    Attributes    ////

public :

    Ui::BreakPoints* ui;		//## attribute ui
    
    ////    Relations and components    ////

protected :

    ModelEventType itsEventFreeBreakpoint;
    
    QStandardItemModel* itsModelBreakpoints;
    
    Sender* itsSender;
    
    ModelClassState itsStateFreeBreakpoint;
    
    TargetInformation* itsTargetInformation;
};

#endif
/*********************************************************************
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\BreakPoints.h
*********************************************************************/
