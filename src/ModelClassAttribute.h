/*********************************************************************
	Rhapsody	: 9.0.1 
	Login		: Y9DSYU706
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: ModelClassAttribute
//!	Generated Date	: Thu, 4, Nov 2021  
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\ModelClassAttribute.h
*********************************************************************/

#ifndef ModelClassAttribute_H
#define ModelClassAttribute_H

#include <QString>
class ModelDataType;

//## package RpyModelData

//## class ModelClassAttribute
// Represents an Attribute of a Class in Rhapsody
class ModelClassAttribute {
    ////    Constructors and destructors    ////
    
public :

    //## operation ModelClassAttribute()
    ModelClassAttribute();
    
    ~ModelClassAttribute();
    
    ////    Operations    ////
    
    //## operation getCompleteArraySize()
    unsigned int getCompleteArraySize();
    
    //## operation getName() const
    const QString& getName() const;
    
    //## operation setName(QString)
    void setName(const QString& p_name);
    
    ////    Additional operations    ////
    
    inline uint32_t getArrayDimension(int i1) const
    {
        return arrayDimension[i1];
    }
    
    inline void setArrayDimension(int i1, uint32_t p_arrayDimension)
    {
        arrayDimension[i1] = p_arrayDimension;
    }
    
    inline int32_t getOffset() const
    {
        return offset;
    }
    
    inline void setOffset(int32_t p_offset)
    {
        offset = p_offset;
    }
    
    inline bool getVisible() const
    {
        return visible;
    }
    
    inline void setVisible(bool p_visible)
    {
        visible = p_visible;
    }
    
    inline ModelDataType* getItsModelDataType() const
    {
        return itsModelDataType;
    }
    
    inline void setItsModelDataType(ModelDataType* p_ModelDataType)
    {
        itsModelDataType = p_ModelDataType;
    }

protected :

    void cleanUpRelations();
    
    ////    Attributes    ////

private :

    uint32_t arrayDimension[3];		//## attribute arrayDimension
    
    QString name;		//## attribute name
    
    // offset from the instance address
    int32_t offset;		//## attribute offset
    
    bool visible;		//## attribute visible
    
    ////    Relations and components    ////

protected :

    ModelDataType* itsModelDataType;
};

#endif
/*********************************************************************
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\ModelClassAttribute.h
*********************************************************************/
