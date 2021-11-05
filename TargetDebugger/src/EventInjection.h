/*********************************************************************
	Rhapsody	: 9.0.1 
	Login		: Y9DSYU706
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: EventInjection
//!	Generated Date	: Thu, 4, Nov 2021  
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\EventInjection.h
*********************************************************************/

#ifndef EventInjection_H
#define EventInjection_H

#include <QStandardItemModel.h>
#include <QWidget>
#include <QStringListModel>
#include <QFileDialog>
#include <QFile>
#include <QShortcut>
class MainWindow;

class ModelEventArgumentType;

class ModelEventType;

class ModelInstance;

class QThread;

class Sender;

class TargetList;

//## package GUI

//## class EventInjection

namespace Ui {
class EventInjection;
}

class EventInjection : public QWidget {
Q_OBJECT
    ////    Constructors and destructors    ////
    
public :

    //## operation EventInjection()
    EventInjection();
    
    //## operation ~EventInjection()
    ~EventInjection();
    
    ////    Operations    ////
    
    //## operation addTimeDelayToSequence()
    Q_SLOT void addTimeDelayToSequence();
    
    //## operation addToSequence()
    Q_SLOT void addToSequence();
    
    //## operation clearEventHistory()
    Q_SLOT void clearEventHistory();
    
    //## operation eventInjection()
    Q_SLOT void eventInjection();
    
    //## operation injectSequence()
    Q_SLOT void injectSequence();
    
    //## operation loadSequence()
    Q_SLOT void loadSequence();
    
    //## operation moveDown()
    Q_SLOT void moveDown();
    
    //## operation moveUp()
    Q_SLOT void moveUp();
    
    //## operation newInstanceCreated(ModelInstance)
    Q_SLOT void newInstanceCreated(ModelInstance* instance);
    
    //## operation removeSelectedFromSequence()
    Q_SLOT void removeSelectedFromSequence();
    
    //## operation saveSequence()
    Q_SLOT void saveSequence();
    
    //## operation showWindow()
    Q_SLOT void showWindow();
    
    //## operation updateElements()
    Q_SLOT void updateElements();
    
    //## operation updateTargets()
    void updateTargets();

private :

    //## operation clear()
    void clear();
    
    //## operation connectSignals()
    void connectSignals();
    
    //## operation disconnectSignals()
    void disconnectSignals();
    
    ////    Additional operations    ////

public :

    inline QString getLastLoadFile() const
    {
        return lastLoadFile;
    }
    
    inline void setLastLoadFile(QString p_lastLoadFile)
    {
        lastLoadFile = p_lastLoadFile;
    }
    
    inline QString getLastSaveFile() const
    {
        return lastSaveFile;
    }
    
    inline void setLastSaveFile(QString p_lastSaveFile)
    {
        lastSaveFile = p_lastSaveFile;
    }
    
    inline QString getLastSelectedDestination() const
    {
        return lastSelectedDestination;
    }
    
    inline void setLastSelectedDestination(QString p_lastSelectedDestination)
    {
        lastSelectedDestination = p_lastSelectedDestination;
    }
    
    inline QString getLastSelectedEvent() const
    {
        return lastSelectedEvent;
    }
    
    inline void setLastSelectedEvent(QString p_lastSelectedEvent)
    {
        lastSelectedEvent = p_lastSelectedEvent;
    }
    
    inline QString getLastSelectedTarget() const
    {
        return lastSelectedTarget;
    }
    
    inline void setLastSelectedTarget(QString p_lastSelectedTarget)
    {
        lastSelectedTarget = p_lastSelectedTarget;
    }
    
    inline QShortcut* getShortcut() const
    {
        return shortcut;
    }
    
    inline void setShortcut(QShortcut* p_shortcut)
    {
        shortcut = p_shortcut;
    }
    
    inline Ui::EventInjection * getUi() const
    {
        return ui;
    }
    
    inline void setUi(Ui::EventInjection * p_ui)
    {
        ui = p_ui;
    }
    
    inline QStandardItemModel* getItsCurrentSequenceModel() const
    {
        return itsCurrentSequenceModel;
    }
    
    inline void setItsCurrentSequenceModel(QStandardItemModel* p_QStandardItemModel)
    {
        itsCurrentSequenceModel = p_QStandardItemModel;
    }
    
    inline QStringListModel* getItsEventHistodyModel() const
    {
        return itsEventHistodyModel;
    }
    
    inline void setItsEventHistodyModel(QStringListModel* p_QStringListModel)
    {
        itsEventHistodyModel = p_QStringListModel;
    }
    
    inline MainWindow* getItsMainWindow() const
    {
        return itsMainWindow;
    }
    
    inline void setItsMainWindow(MainWindow* p_MainWindow)
    {
        itsMainWindow = p_MainWindow;
    }
    
    inline Sender* getItsSender() const
    {
        return itsSender;
    }
    
    inline void setItsSender(Sender* p_Sender)
    {
        itsSender = p_Sender;
    }

protected :

    void cleanUpRelations();
    
    ////    Attributes    ////

private :

    QString lastLoadFile;		//## attribute lastLoadFile
    
    QString lastSaveFile;		//## attribute lastSaveFile
    
    QString lastSelectedDestination;		//## attribute lastSelectedDestination
    
    QString lastSelectedEvent;		//## attribute lastSelectedEvent
    
    QString lastSelectedTarget;		//## attribute lastSelectedTarget
    
    QShortcut* shortcut;		//## attribute shortcut
    
    Ui::EventInjection * ui;		//## attribute ui
    
    ////    Relations and components    ////

protected :

    QStandardItemModel* itsCurrentSequenceModel;
    
    QStringListModel* itsEventHistodyModel;
    
    MainWindow* itsMainWindow;
    
    Sender* itsSender;
};

#endif
/*********************************************************************
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\EventInjection.h
*********************************************************************/
