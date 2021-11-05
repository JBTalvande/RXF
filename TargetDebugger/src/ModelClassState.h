/*********************************************************************
	Rhapsody	: 9.0.1 
	Login		: Y9DSYU706
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: ModelClassState
//!	Generated Date	: Thu, 4, Nov 2021  
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\ModelClassState.h
*********************************************************************/

#ifndef ModelClassState_H
#define ModelClassState_H

#include <QString>
//## package RpyModelData

//## class ModelClassState
class ModelClassState {
    ////    Constructors and destructors    ////
    
public :

    //## operation ModelClassState(int,QString)
    ModelClassState(int p_id, const QString& p_name);
    
    ModelClassState();
    
    ~ModelClassState();
    
    ////    Operations    ////
    
    //## operation getName() const
    inline const QString& getName() const;
    
    ////    Additional operations    ////
    
    inline unsigned int getId() const
    {
        return id;
    }
    
    inline void setId(unsigned int p_id)
    {
        id = p_id;
    }
    
    ////    Attributes    ////

private :

    unsigned int id;		//## attribute id
    
    const QString name;		//## attribute name
};

inline const QString& ModelClassState::getName() const
{
    //#[ operation getName() const
    return name;
    //#]
}

#endif
/*********************************************************************
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\ModelClassState.h
*********************************************************************/
