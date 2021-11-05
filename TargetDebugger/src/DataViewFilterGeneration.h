/*********************************************************************
	Rhapsody	: 9.0.1 
	Login		: Y9DSYU706
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: DataViewFilterGeneration
//!	Generated Date	: Thu, 4, Nov 2021  
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\DataViewFilterGeneration.h
*********************************************************************/

#ifndef DataViewFilterGeneration_H
#define DataViewFilterGeneration_H

#include <QVector>
#include <QDialog>
#include <QStandardItemModel>
class CommandList;

class CommandListFilter;

class TargetInformation;

class TargetList;

//## package GUI

//## class DataViewFilterGeneration

namespace Ui {
class DataViewFilterGeneration;
}

class DataViewFilterGeneration : public QDialog {
Q_OBJECT
private :

    enum operationMode {
        editFilterMode,
        newFilterMode
    };
    
    ////    Constructors and destructors    ////

public :

    //## operation DataViewFilterGeneration()
    DataViewFilterGeneration();
    
    //## operation ~DataViewFilterGeneration()
    ~DataViewFilterGeneration();
    
    ////    Operations    ////
    
    //## operation activateDestinationFilter(bool)
    Q_SLOT void activateDestinationFilter(bool active);
    
    //## operation activateEventFilter(bool)
    Q_SLOT void activateEventFilter(bool active);
    
    //## operation activateSourceFilter(bool)
    Q_SLOT void activateSourceFilter(bool active);
    
    //## operation addFilter()
    Q_SLOT void addFilter();
    
    //## operation destAdd()
    Q_SLOT void destAdd();
    
    //## operation destAddAll()
    Q_SLOT void destAddAll();
    
    //## operation destDel()
    Q_SLOT void destDel();
    
    //## operation destDelAll()
    Q_SLOT void destDelAll();
    
    //## operation editFilter(CommandList)
    void editFilter(CommandList* list);
    
    //## operation eventAdd()
    Q_SLOT void eventAdd();
    
    //## operation eventAddAll()
    Q_SLOT void eventAddAll();
    
    //## operation eventDel()
    Q_SLOT void eventDel();
    
    //## operation eventDelAll()
    Q_SLOT void eventDelAll();
    
    //## operation filterChanged()
    Q_SLOT void filterChanged();
    
    //## operation newFilter()
    Q_SLOT void newFilter();
    
    //## operation reject()
    Q_SLOT void reject();
    
    //## operation removeFilter()
    Q_SLOT void removeFilter();
    
    //## operation showWindow(CommandList)
    void showWindow(CommandList* parentList);
    
    //## operation sourceAdd()
    Q_SLOT void sourceAdd();
    
    //## operation sourceAddAll()
    Q_SLOT void sourceAddAll();
    
    //## operation sourceDel()
    Q_SLOT void sourceDel();
    
    //## operation sourceDelAll()
    Q_SLOT void sourceDelAll();

private :

    //## operation addFilterPartsToUiList(CommandListFilter,TargetList)
    void addFilterPartsToUiList(CommandListFilter* filter, TargetList* targetList);
    
    //## operation addUiPartsToFilter(CommandListFilter)
    void addUiPartsToFilter(CommandListFilter* filter);
    
    //## operation addUiTargesToFilter(CommandListFilter)
    void addUiTargesToFilter(CommandListFilter* filter);
    
    //## operation connectSignals()
    void connectSignals();
    
    //## operation disconnectSignals()
    void disconnectSignals();
    
    ////    Additional operations    ////

public :

    inline operationMode getMode() const
    {
        return mode;
    }
    
    inline void setMode(operationMode p_mode)
    {
        mode = p_mode;
    }
    
    inline Qt::WindowFlags getMyWindowFlags() const
    {
        return myWindowFlags;
    }
    
    inline void setMyWindowFlags(Qt::WindowFlags p_myWindowFlags)
    {
        myWindowFlags = p_myWindowFlags;
    }
    
    inline Ui::DataViewFilterGeneration * getUi() const
    {
        return ui;
    }
    
    inline void setUi(Ui::DataViewFilterGeneration * p_ui)
    {
        ui = p_ui;
    }
    
    inline CommandList* getItsEditCommandList() const
    {
        return itsEditCommandList;
    }
    
    inline void setItsEditCommandList(CommandList* p_CommandList)
    {
        itsEditCommandList = p_CommandList;
    }
    
    inline CommandList* getItsParentCommandList() const
    {
        return itsParentCommandList;
    }
    
    inline void setItsParentCommandList(CommandList* p_CommandList)
    {
        itsParentCommandList = p_CommandList;
    }
    
    inline TargetInformation* getItsTargetInformationSingleTarget() const
    {
        return itsTargetInformationSingleTarget;
    }
    
    inline void setItsTargetInformationSingleTarget(TargetInformation* p_TargetInformation)
    {
        itsTargetInformationSingleTarget = p_TargetInformation;
    }

protected :

    void cleanUpRelations();
    
    ////    Attributes    ////

private :

    QVector<bool> destFilterActiveList;		//## attribute destFilterActiveList
    
    QVector<QStandardItemModel*> destHideModelList;		//## attribute destHideModelList
    
    QVector<QStandardItemModel*> destShowModelList;		//## attribute destShowModelList
    
    QVector<bool> eventFilterActiveList;		//## attribute eventFilterActiveList
    
    QStandardItemModel* eventFilterModel;		//## attribute eventFilterModel
    
    QVector<QStandardItemModel*> eventHideModelList;		//## attribute eventHideModelList
    
    QVector<QStandardItemModel*> eventShowModelList;		//## attribute eventShowModelList
    
    operationMode mode;		//## attribute mode
    
    Qt::WindowFlags myWindowFlags;		//## attribute myWindowFlags
    
    QVector<bool> sourceFilterActiveList;		//## attribute sourceFilterActiveList
    
    QVector<QStandardItemModel*> sourceHideModelList;		//## attribute sourceHideModelList
    
    QVector<QStandardItemModel*> sourceShowModelList;		//## attribute sourceShowModelList
    
    QStandardItemModel* targetFilterModel;		//## attribute targetFilterModel
    
    Ui::DataViewFilterGeneration * ui;		//## attribute ui
    
    ////    Relations and components    ////

protected :

    CommandList* itsEditCommandList;
    
    CommandList* itsParentCommandList;
    
    TargetInformation* itsTargetInformationSingleTarget;
};

#endif
/*********************************************************************
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\DataViewFilterGeneration.h
*********************************************************************/
