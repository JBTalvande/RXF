/*********************************************************************
	Rhapsody	: 9.0.1 
	Login		: Y9DSYU706
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: CommandListFilter
//!	Generated Date	: Thu, 4, Nov 2021  
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\CommandListFilter.h
*********************************************************************/

#ifndef CommandListFilter_H
#define CommandListFilter_H

#include "Filter.h"
#include <QList>
#include "FilterPart.h"
class Command;

class CommandConstructor;

class CommandDestructor;

class CommandEventCreated;

class CommandEventEndDispatch;

class CommandEventStartDispatch;

class CommandIntVal;

class CommandOperationCall;

class CommandTraceEvent;

class ModelEventType;

class ModelInstance;

//## package LogicLevel::Logging::DataContainer::Filter

//## class CommandListFilter
class CommandListFilter {
    ////    Constructors and destructors    ////
    
public :

    //## operation CommandListFilter()
    CommandListFilter();
    
    //## operation ~CommandListFilter()
    ~CommandListFilter();
    
    ////    Operations    ////
    
    //## operation addFilterPart(FilterPart)
    void addFilterPart(FilterPart* newFilterPart);
    
    //## operation addTargetFilter(QPair<TargetInformation*, bool>*)
    void addTargetFilter(QPair<TargetInformation*, bool>* TargetFilterInfo);
    
    //## operation getFilterPartList() const
    inline const QList<FilterPart*>& getFilterPartList() const;
    
    //## operation getItsTargetFilterList()
    inline QList<QPair<TargetInformation*,bool>*>& getItsTargetFilterList();
    
    //## operation isFiltered(Command)
    bool isFiltered(const Command& command);
    
    //## operation removeFilterPart(int)
    inline void removeFilterPart(int index);

private :

    //## operation isDestinationFiltered(ModelInstance,FilterPart)
    bool isDestinationFiltered(ModelInstance* instance, FilterPart* filterPart);
    
    //## operation isEventFiltered(ModelEventType,FilterPart)
    bool isEventFiltered(ModelEventType* eventType, FilterPart* filterPart);
    
    //## operation isSourceFiltered(ModelInstance,FilterPart)
    bool isSourceFiltered(ModelInstance* instance, FilterPart* filterPart);
    
    ////    Additional operations    ////

public :

    inline bool getBufferOverflowFilterd() const
    {
        return bufferOverflowFilterd;
    }
    
    inline void setBufferOverflowFilterd(bool p_bufferOverflowFilterd)
    {
        bufferOverflowFilterd = p_bufferOverflowFilterd;
    }
    
    inline bool getConstructorFilterd() const
    {
        return constructorFilterd;
    }
    
    inline void setConstructorFilterd(bool p_constructorFilterd)
    {
        constructorFilterd = p_constructorFilterd;
    }
    
    inline bool getDebugIntFiltered() const
    {
        return debugIntFiltered;
    }
    
    inline void setDebugIntFiltered(bool p_debugIntFiltered)
    {
        debugIntFiltered = p_debugIntFiltered;
    }
    
    inline bool getDestructorFilterd() const
    {
        return destructorFilterd;
    }
    
    inline void setDestructorFilterd(bool p_destructorFilterd)
    {
        destructorFilterd = p_destructorFilterd;
    }
    
    inline bool getErrorHandlerFilterd() const
    {
        return errorHandlerFilterd;
    }
    
    inline void setErrorHandlerFilterd(bool p_errorHandlerFilterd)
    {
        errorHandlerFilterd = p_errorHandlerFilterd;
    }
    
    inline bool getTargetFilterd() const
    {
        return targetFilterd;
    }
    
    inline void setTargetFilterd(bool p_targetFilterd)
    {
        targetFilterd = p_targetFilterd;
    }
    
    inline int getTickMax() const
    {
        return tickMax;
    }
    
    inline void setTickMax(int p_tickMax)
    {
        tickMax = p_tickMax;
    }
    
    inline int getTickMin() const
    {
        return tickMin;
    }
    
    inline void setTickMin(int p_tickMin)
    {
        tickMin = p_tickMin;
    }
    
    inline bool getTicksFilterd() const
    {
        return ticksFilterd;
    }
    
    inline void setTicksFilterd(bool p_ticksFilterd)
    {
        ticksFilterd = p_ticksFilterd;
    }

protected :

    void cleanUpRelations();
    
    ////    Attributes    ////

private :

    bool bufferOverflowFilterd;		//## attribute bufferOverflowFilterd
    
    bool constructorFilterd;		//## attribute constructorFilterd
    
    bool debugIntFiltered;		//## attribute debugIntFiltered
    
    bool destructorFilterd;		//## attribute destructorFilterd
    
    bool errorHandlerFilterd;		//## attribute errorHandlerFilterd
    
    bool targetFilterd;		//## attribute targetFilterd
    
    int tickMax;		//## attribute tickMax
    
    int tickMin;		//## attribute tickMin
    
    bool ticksFilterd;		//## attribute ticksFilterd
    
    ////    Relations and components    ////

protected :

    QList<FilterPart*> itsFilterParts;
    
    QList<QPair<TargetInformation*,bool>*> itsTargetFilterList;
};

inline const QList<FilterPart*>& CommandListFilter::getFilterPartList() const
{
    //#[ operation getFilterPartList() const
    return this->itsFilterParts;
    //#]
}

inline QList<QPair<TargetInformation*,bool>*>& CommandListFilter::getItsTargetFilterList()
{
    //#[ operation getItsTargetFilterList()
    return itsTargetFilterList;
    //#]
}

inline void CommandListFilter::removeFilterPart(int index)
{
    //#[ operation removeFilterPart(int)
    if(0 <= index && index < this->itsFilterParts.size())
    {
    	this->itsFilterParts.removeAt(index);
    }
    //#]
}

#endif
/*********************************************************************
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\CommandListFilter.h
*********************************************************************/
