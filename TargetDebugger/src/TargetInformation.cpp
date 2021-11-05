/********************************************************************
	Rhapsody	: 9.0.1 
	Login		: Y9DSYU706
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: TargetInformation
//!	Generated Date	: Thu, 4, Nov 2021  
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\TargetInformation.cpp
*********************************************************************/

#include "TargetInformation.h"
#include "MainWindow.h"
#include "ModelClassAttribute.h"
//## package LogicLevel::Logging

//## class TargetInformation
TargetInformation::TargetInformation(const QString& name, bool isSingleTarget, int id) : endianess(LITTLE_ENDIAN), inReset(false), incommingTypeNr(0), initilized(false), parallelStateCount(4), pointerSize(4), singleTarget(true), stateSize(1), timeOffset(0U), environment(&unknownClass, 0, 0, "Environment", this), itsModelClassList(), itsModelDataTypeList(), itsModelEventTypeList(), nullEvent("NullEvent", 65535, this), startBehaviourEvent("StartBehaviourEvent", 65534, this), timeOutEvent("TimeOutEvent", 65533, this), unknownDataType("UnknownType", 0)
{
    lastModelInstance = NULL;
    itsTreeViewItemTargetFilter = NULL;
    itsTreeViewItemTarget = NULL;
    itsTreeViewItemDebugInt = NULL;
    //#[ operation TargetInformation(QString,bool,int)
    this->name = name;
    this->singleTarget = isSingleTarget;
    this->id = id;
    this->itsModelEventTypeList.insert(nullEvent.getName(), &nullEvent);
    this->itsModelEventTypeList.insert(timeOutEvent.getName(), &timeOutEvent);
    this->itsModelEventTypeList.insert(startBehaviourEvent.getName(), &startBehaviourEvent);
    this->initilized = true;
    //#]
}

TargetInformation::~TargetInformation()
{
    cleanUpRelations();
}

void TargetInformation::addClass(ModelClass* newClass)
{
    //#[ operation addClass(ModelClass)
    this->itsModelClassList.insert(newClass->getId(), newClass);
    //#]
}

void TargetInformation::addEventType(ModelEventType* eventType)
{
    //#[ operation addEventType(ModelEventType)
    this->itsModelEventTypeList.insert(eventType->getName(), eventType);
    //#]
}

void TargetInformation::addType(const QString& name, int size, int index)
{
    //#[ operation addType(QString,int,int)
    this->itsModelDataTypeList.insert( name, new ModelDataType(name, index, size) );
    //#]
}

void TargetInformation::clearEventTypeList()
{
    //#[ operation clearEventTypeList()
    this->itsModelEventTypeList.clear();
    //#]
}

ModelClass* TargetInformation::getClass(unsigned int classID)
{
    //#[ operation getClass(unsigned int)
    return this->itsModelClassList.value(classID, NULL);
    //#]
}

ModelClass* TargetInformation::getClassByFullPath(const QString& name)
{
    //#[ operation getClassByFullPath(QString)
    for(auto myClass : this->itsModelClassList)
    {
        if( myClass->getFullPathName() == name )
        {
            return myClass;
        }
    }
    return NULL;
    //#]
}

int TargetInformation::getEventId(const QString& eventName)
{
    //#[ operation getEventId(QString)
    auto myEventType = this->itsModelEventTypeList.value(eventName, NULL);
    if(myEventType == NULL)
    {
        return myEventType->getId();
    }
    else
    {
        return -1;
    }
    //#]
}

ModelEventType* TargetInformation::getEventType(unsigned int eventID)
{
    //#[ operation getEventType(unsigned int)
    ModelEventType *myEventType = NULL;
    foreach ( auto currentEvent, this->itsModelEventTypeList ) {
        if(currentEvent->getId() == eventID)
        {
            return currentEvent;
        }
    }
    if( eventID == 65531 )
    {
        return &startBehaviourEvent;
    }
    // if no current event could be found
    myEventType = new ModelEventType("Unknown Event ID( " + QString::number( eventID ) + ")", eventID, this);
    this->addEventType(myEventType);
    
    return myEventType;
    //#]
}

const ModelEventType* TargetInformation::getEventType(const QString& p_name) const
{
    //#[ operation getEventType(QString) const
    return this->itsModelEventTypeList.value(p_name, NULL);
    //#]
}

ModelInstance* TargetInformation::getInstance(uint64_t address)
{
    //#[ operation getInstance(uint64_t)
    if( address == 0U )
    {
        return &environment;
    }
    ModelInstance* retValue = NULL;
    for( auto myClass : this->itsModelClassList )
    {
        for( auto myInstance : myClass->getInstanceList() ) /* run to end of the list */
        {
            if( myInstance->getAddress() == address )
            {
                if( myInstance->getIsBaseClass() )
                {
                    retValue = myInstance;
                }
                else
                {
                    return myInstance;
                }
            }
        }
    }
    if( retValue != NULL )
    {
        return retValue;
    }
    
    // if no instance was found in current classes, try to find the instance in the default unknownClass
    for( auto myInstance : unknownClass.getInstanceList() ) /* run to end of the list */
    {
        if( myInstance->getAddress() == address )
        {
            return myInstance;
        }
    }
    
    // if even no instance could found in the unknown class, create a new instance there with the given address
    ModelInstance* myInstance = new ModelInstance( &unknownClass, address, address, "0x" + QString::number(address,16), this );
    unknownClass.addInstance( myInstance );
    
    return myInstance;
    //#]
}

ModelInstance* TargetInformation::getInstance(const QString& instanceName)
{
    //#[ operation getInstance(QString)
    for( auto myClass : this->itsModelClassList )
    {
        ModelInstance* myInstance = myClass->getInstanceList().value(instanceName, NULL);
        if(myInstance != NULL)
        {
            return myInstance;
        }
    }
    return NULL;
    //#]
}

const QHash<QString, ModelEventType*> TargetInformation::getModelEventTypeList() const
{
    //#[ operation getModelEventTypeList() const
    return this->itsModelEventTypeList;
    //#]
}

ModelDataType* TargetInformation::getTypePtr(const QString& typeName)
{
    //#[ operation getTypePtr(QString)
    if( this->itsModelDataTypeList.empty() )
    {
        return NULL;
    }
    // TODO: Check if this is correct and any first element of the list can be returned
    if ( typeName.contains( "*" ) )
    {
        return itsModelDataTypeList.value("*", &this->unknownDataType);
    }
    
    return itsModelDataTypeList.value(typeName, &this->unknownDataType);
    //#]
}

int TargetInformation::getTypeSize(const QString& typeName)
{
    //#[ operation getTypeSize(QString)
    if( itsModelDataTypeList.empty() )
    {
        return 0;
    }
    if ( typeName.startsWith( "static" ) == true )
    {
        return 0;
    }
    
    if ( typeName.contains( "*" ) )
    {
        return pointerSize;
    }
    ModelDataType *myDataType = this->getTypePtr(typeName);
    
    if(myDataType == NULL) {
        return 0;
    } else {
        return myDataType->getSize();
    }
    //#]
}

ModelInstance* TargetInformation::searchTargetClassAndCreateObject(unsigned int classID, uint64_t objectAddress, uint64_t firstAttributeAddress)
{
    //#[ operation searchTargetClassAndCreateObject(unsigned int,uint64_t,uint64_t)
    //1. find out if instance already exist in list
    //    for( auto myClass : this->itsModelClassList )
    //    { //ClassID check
    //        for( auto anInstance : myClass->getInstanceList() )
    //        {
    //            if( anInstance->getAddress() == objectAddress && anInstance->getItsModelClass()->getId() == classID )
    //            {
    //                //Add Instance to MainWindow
    //                itsMainWindow->addInstance( *anInstance, *this );
    //                return anInstance;
    //            }
    //        }
    //    }
    
    QString instanceName;
    //2. Get Class of new Instance
    ModelClass *myBaseClass = getClass(classID);
    if( myBaseClass == NULL ) //If class does not exist use unknown class Object
    {
        instanceName = "0x" + QString::number(objectAddress,16);
        myBaseClass = &unknownClass;
    }
    else
    {
        QString prefix = "its";
        QStringList classNameParts = myBaseClass->getName().split("::");
        if( classNameParts.size() == 1 )
        {
            instanceName = prefix + myBaseClass->getName() + QString::number( myBaseClass->incrementInstanceCount() ) ;
        }
        else
        {
            instanceName ="";
            for(int i = 0; i < ( classNameParts.size() - 1 ); i++ )
            {
                instanceName += classNameParts[i] + "::";
            }
            instanceName += prefix + classNameParts[ classNameParts.size() - 1 ] + QString::number( myBaseClass->incrementInstanceCount() ) ;
        }
    
        //inform all inherited instances that they are not valid for destination of an event
        for( int i= 0; i < myBaseClass->getParents()->size(); i++ )
        {
            ModelInstance *lastInsertedInstance = myBaseClass->getParents()->at(i)->getLastInsertedInstance();
            if( lastInsertedInstance != NULL )
            {
                lastInsertedInstance->setIsBaseClass( true );
            }
        }
    }
    
    //3. create new Instance
    ModelInstance* myNewInstance = new ModelInstance( myBaseClass, objectAddress, firstAttributeAddress, instanceName, this);
    
    //4. Add Instance to Instance List
    myBaseClass->addInstance( myNewInstance );
    
    if( myBaseClass == &unknownClass )
    {
        //Steps 5 and 6 don't need to be performed by unknown class
        return myNewInstance;
    }
    
    
    //5. Add Instance to MainWindow
    itsMainWindow->addInstance( *myNewInstance, *this );
    
    
    return myNewInstance;
    //#]
}

void TargetInformation::setName(const QString& p_name)
{
    //#[ operation setName(QString)
    name = p_name;
    //#]
}

void TargetInformation::updateClassAttributes()
{
    //#[ operation updateClassAttributes()
    uint offset;
    uint attributeSize;
    for( auto modelClass : this->itsModelClassList )
    {
        offset = 0;
        for( auto myClassAttribute : modelClass->getClassAttributeList() )
        {
            attributeSize = myClassAttribute->getItsModelDataType()->getSize();
            if( attributeSize == 0)
            {
                attributeSize = 1;
            }
            if( attributeSize > getPointerSize())
            {
                if( offset % getPointerSize() != 0)
                {
                    offset += getPointerSize() - ( offset % getPointerSize() );
                }
            }
            else
            {
                if( offset % attributeSize != 0)
                {
                    offset += attributeSize - ( offset % attributeSize );
                }
            }
            myClassAttribute->setOffset( offset );
            offset += attributeSize * myClassAttribute->getCompleteArraySize();
        }
    }
    
    //#]
}

TargetInformation::ReceiveTypePosition TargetInformation::updateTypeSize(unsigned int value)
{
    //#[ operation updateTypeSize(unsigned int)
    ReceiveTypePosition retVal = Inbetween;
    if( incommingTypeNr == 0 )
    {
        int ptrSize;
        if( value >= 2 && value <=8 )
        {
            ptrSize = value;
        }
        else
        {
            ptrSize =  4;
        }
        pointerSize = ptrSize;
        for( auto myDataType : this->itsModelDataTypeList.values() )
        {
            if( myDataType->getIndex() == incommingTypeNr )
            {
                myDataType->setSize( ptrSize );
                break;
            }
        }
        retVal = First;
    }
    else
    {
        for( auto myDataType : this->itsModelDataTypeList.values() )
        {
            if( myDataType->getIndex() == incommingTypeNr )
            {
                myDataType->setSize( value );
                break;
            }
        }
    }  
    incommingTypeNr++;
    if( incommingTypeNr == (uint)itsModelDataTypeList.size() )
    {
       retVal = Last;
    }
    return retVal;
    //#]
}

void TargetInformation::cleanUpRelations()
{
    {
        itsModelClassList.clear();
    }
    {
        itsModelDataTypeList.clear();
    }
    {
        itsModelEventTypeList.clear();
    }
    if(itsTreeViewItemDebugInt != NULL)
        {
            itsTreeViewItemDebugInt = NULL;
        }
    if(itsTreeViewItemTarget != NULL)
        {
            itsTreeViewItemTarget = NULL;
        }
    if(itsTreeViewItemTargetFilter != NULL)
        {
            itsTreeViewItemTargetFilter = NULL;
        }
    if(lastModelInstance != NULL)
        {
            lastModelInstance = NULL;
        }
}

MainWindow* TargetInformation::itsMainWindow = NULL;

/*********************************************************************
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\TargetInformation.cpp
*********************************************************************/
