/*********************************************************************
	Rhapsody	: 9.0.1 
	Login		: Y9DSYU706
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: ModelDefine
//!	Generated Date	: Thu, 4, Nov 2021  
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\ModelDefine.h
*********************************************************************/

#ifndef ModelDefine_H
#define ModelDefine_H

#include <QString>
//## package RpyModelData

//## class ModelDefine
class ModelDefine {
    ////    Constructors and destructors    ////
    
public :

    ModelDefine();
    
    ~ModelDefine();
    
    ////    Additional operations    ////
    
    inline QString getDefineName() const
    {
        return defineName;
    }
    
    inline void setDefineName(QString p_defineName)
    {
        defineName = p_defineName;
    }
    
    inline int getDefineSize() const
    {
        return defineSize;
    }
    
    inline void setDefineSize(int p_defineSize)
    {
        defineSize = p_defineSize;
    }
    
    ////    Attributes    ////

private :

    QString defineName;		//## attribute defineName
    
    int defineSize;		//## attribute defineSize
};

#endif
/*********************************************************************
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\ModelDefine.h
*********************************************************************/
