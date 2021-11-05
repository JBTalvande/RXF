/*********************************************************************
	Rhapsody	: 9.0.1 
	Login		: Y9DSYU706
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: ModelDataType
//!	Generated Date	: Thu, 4, Nov 2021  
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\ModelDataType.h
*********************************************************************/

#ifndef ModelDataType_H
#define ModelDataType_H

#include <QString>
//## package RpyModelData

//## class ModelDataType
class ModelDataType {
    ////    Constructors and destructors    ////
    
public :

    //## operation ModelDataType(QString,int,int)
    ModelDataType(const QString& p_name, int p_index, int p_size = 0);
    
    ~ModelDataType();
    
    ////    Operations    ////
    
    //## operation getIndex() const
    inline unsigned int getIndex() const;
    
    //## operation getName() const
    inline const QString& getName() const;
    
    //## operation setName(QString)
    inline void setName(const QString& p_name);
    
    ////    Additional operations    ////
    
    inline int getSize() const
    {
        return size;
    }
    
    inline void setSize(int p_size)
    {
        size = p_size;
    }
    
    ////    Attributes    ////

private :

    const unsigned int index;		//## attribute index
    
    QString name;		//## attribute name
    
    int size;		//## attribute size
};

inline unsigned int ModelDataType::getIndex() const
{
    //#[ operation getIndex() const
    return this->index;
    //#]
}

inline const QString& ModelDataType::getName() const
{
    //#[ operation getName() const
    return this->name;
    //#]
}

inline void ModelDataType::setName(const QString& p_name)
{
    //#[ operation setName(QString)
    name = p_name;
    //#]
}

#endif
/*********************************************************************
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\ModelDataType.h
*********************************************************************/
