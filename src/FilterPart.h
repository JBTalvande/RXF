/*********************************************************************
	Rhapsody	: 9.0.1 
	Login		: Y9DSYU706
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: FilterPart
//!	Generated Date	: Thu, 4, Nov 2021  
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\FilterPart.h
*********************************************************************/

#ifndef FilterPart_H
#define FilterPart_H

#include "Filter.h"
#include <QVector>
#include "ModelEventType.h"
#include "ModelInstance.h"
#include <QStandardItemModel>
//## package LogicLevel::Logging::DataContainer::Filter

//## class FilterPart
class FilterPart {
public :

    enum FilterMode {
        BlackList,
        WhiteList,
        NoFilter
    };
    
    ////    Constructors and destructors    ////
    
    FilterPart();
    
    ~FilterPart();
    
    ////    Operations    ////
    
    //## operation getItsDestinationFilterList()
    inline QVector<ModelInstance*>& getItsDestinationFilterList();
    
    //## operation getItsEventFilterList()
    inline QVector<ModelEventType*>& getItsEventFilterList();
    
    //## operation getItsSourceFilterList()
    inline QVector<ModelInstance*>& getItsSourceFilterList();
    
    ////    Additional operations    ////
    
    inline FilterMode getDestinationFilterActive() const
    {
        return destinationFilterActive;
    }
    
    inline void setDestinationFilterActive(FilterMode p_destinationFilterActive)
    {
        destinationFilterActive = p_destinationFilterActive;
    }
    
    inline FilterMode getEventFilterActive() const
    {
        return eventFilterActive;
    }
    
    inline void setEventFilterActive(FilterMode p_eventFilterActive)
    {
        eventFilterActive = p_eventFilterActive;
    }
    
    inline FilterMode getSourceFilterActive() const
    {
        return sourceFilterActive;
    }
    
    inline void setSourceFilterActive(FilterMode p_sourceFilterActive)
    {
        sourceFilterActive = p_sourceFilterActive;
    }
    
    inline void addItsDestinationFilterList(ModelInstance* p_ModelInstance)
    {
        itsDestinationFilterList.append(p_ModelInstance);
    }
    
    inline void clearItsDestinationFilterList()
    {
        itsDestinationFilterList.clear();
    }
    
    inline void addItsEventFilterList(ModelEventType* p_ModelEventType)
    {
        itsEventFilterList.append(p_ModelEventType);
    }
    
    inline void clearItsEventFilterList()
    {
        itsEventFilterList.clear();
    }
    
    inline void addItsSourceFilterList(ModelInstance* p_ModelInstance)
    {
        itsSourceFilterList.append(p_ModelInstance);
    }
    
    inline void clearItsSourceFilterList()
    {
        itsSourceFilterList.clear();
    }

protected :

    void cleanUpRelations();
    
    ////    Attributes    ////

private :

    FilterMode destinationFilterActive;		//## attribute destinationFilterActive
    
    FilterMode eventFilterActive;		//## attribute eventFilterActive
    
    FilterMode sourceFilterActive;		//## attribute sourceFilterActive
    
    ////    Relations and components    ////

protected :

    QVector<ModelInstance*> itsDestinationFilterList;
    
    QVector<ModelEventType*> itsEventFilterList;
    
    QVector<ModelInstance*> itsSourceFilterList;
};

inline QVector<ModelInstance*>& FilterPart::getItsDestinationFilterList()
{
    //#[ operation getItsDestinationFilterList()
    return itsDestinationFilterList;
    //#]
}

inline QVector<ModelEventType*>& FilterPart::getItsEventFilterList()
{
    //#[ operation getItsEventFilterList()
    return itsEventFilterList;
    //#]
}

inline QVector<ModelInstance*>& FilterPart::getItsSourceFilterList()
{
    //#[ operation getItsSourceFilterList()
    return itsSourceFilterList;
    //#]
}

#endif
/*********************************************************************
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\FilterPart.h
*********************************************************************/
