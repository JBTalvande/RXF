/********************************************************************
	Rhapsody	: 9.0.1 
	Login		: Y9DSYU706
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: Sender
//!	Generated Date	: Thu, 4, Nov 2021  
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\Sender.cpp
*********************************************************************/

#include "Sender.h"
#include "MainWindow.h"
#include "ModelClassAttribute.h"
#include "ModelInstance.h"
#include "TargetCommunication.h"
#include "TargetInformation.h"
//## package LogicLevel::DataTransmission

//## class Sender
Sender::Sender()
{
    itsMainWindow = NULL;
    itsTargetCommunication = NULL;
}

Sender::~Sender()
{
    cleanUpRelations();
}

void Sender::addBreakpoint(uint64_t instanceAddress, int stateId, int eventId, TargetInformation& targetInformation)
{
    //#[ operation addBreakpoint(uint64_t,int,int,TargetInformation)
    if( itsTargetCommunication == NULL )
    {
        return;
    }
    char commandToTarget[10];
    int next;
    commandToTarget[0] = targetInformation.getPointerSize() + 4;
    commandToTarget[1] = command_addBreakpoint;
    next = 2 + addAddressToStream(instanceAddress,&commandToTarget[2],targetInformation);
    
    if(targetInformation.getEndianess() == LITTLE_ENDIAN )
    {
        commandToTarget[next] = (char)stateId;
        commandToTarget[next + 1] = (char)( stateId >> 8 );
        commandToTarget[next + 2] = (char)( eventId );
        commandToTarget[next + 3] = (char)( eventId >> 8 );
    }
    else
    {
        commandToTarget[next + 1] = (char)stateId;
        commandToTarget[next] = (char)( stateId >> 8 );
        commandToTarget[next + 3] = (char)( eventId );
        commandToTarget[next + 2] = (char)( eventId >> 8 );
    }
    itsTargetCommunication->write( commandToTarget, commandToTarget[0] + 2, targetInformation.getId() );
    //#]
}

void Sender::executeTest(const QString& testCase)
{
    //#[ operation executeTest(QString)
    if( itsTargetCommunication == NULL )
    {
        return;
    }
    char command[250];
    strcpy(&command[2],testCase.toStdString().c_str());
    command[0] = testCase.length();
    command[1] = 26;
    
    itsTargetCommunication->write(command, testCase.length() + 2U, -1);
    //#]
}

void Sender::handleDebugIntFilter(QStandardItem* modelIndex)
{
    //#[ operation handleDebugIntFilter(QStandardItem)
    //Target Instance Filter
    if( itsTargetCommunication == NULL )
    {
        return;
    }
    if(modelIndex->text().startsWith("its"))
    {
        ModelInstance *myInstance = *((ModelInstance **)modelIndex->data(Qt::UserRole).data());
        char commandToTarget[10];
        commandToTarget[ 0 ] = 1 + myInstance->getItsTargetInformation()->getPointerSize();
        commandToTarget[ 1 ] = command_debugIntFilter;
        unsigned int next = 2 + addAddressToStream( myInstance->getAddress(), &commandToTarget[2], *myInstance->getItsTargetInformation() );
        if( modelIndex->checkState() == Qt::Checked )
        {
            commandToTarget[next] = 1U;
        }
        else
        {
            commandToTarget[next] = 0U;
        }
        itsTargetCommunication->write( commandToTarget, commandToTarget[0] + 2, myInstance->getItsTargetInformation()->getId() );
    }
    //#]
}

void Sender::handleInstanceFilter(QStandardItem* modelIndex)
{
    //#[ operation handleInstanceFilter(QStandardItem)
    //Target Instance Filter
    for( int i = 0; i < modelIndex->rowCount(); i++ )
    {
        modelIndex->child( i )->setCheckState( modelIndex->checkState() );
    }
    if( itsTargetCommunication == NULL )
    {
        return;
    }
    if(modelIndex->text().startsWith("its"))
    {
        ModelInstance *myInstance = *((ModelInstance **)modelIndex->data(Qt::UserRole).data());
        char commandToTarget[10];
        commandToTarget[ 0 ] = 1 + myInstance->getItsTargetInformation()->getPointerSize();
        commandToTarget[ 1 ] = command_instanceFilter;
        unsigned int next = 2 + addAddressToStream( myInstance->getAddress(), &commandToTarget[2], *myInstance->getItsTargetInformation() );
        if( modelIndex->checkState() == Qt::Checked )
        {
            commandToTarget[next] = 1U;
        }
        else
        {
            commandToTarget[next] = 0U;
        }
        itsTargetCommunication->write( commandToTarget, commandToTarget[0] + 2, myInstance->getItsTargetInformation()->getId() );
    }
    //#]
}

void Sender::handleTargetTreeCollaps(QModelIndex modelIndex)
{
    //#[ operation handleTargetTreeCollaps(QModelIndex)
    if( itsTargetCommunication == NULL )
    {
        return;
    }
    QStandardItem * item = itsMainWindow->getItsTargetListItem()->model()->itemFromIndex( modelIndex );
    
    if( item != NULL && item->parent() == NULL ){
        return;
    }
    
    if ( item->parent() ->text() == "Attributes" && item->child(0)->text() != "[0]"  )
    {
        TargetInformation * myTarget = *((TargetInformation **)item->data(Qt::UserRole).data());
        if( requestAttribut( item->parent()->parent()->text(), item->text() , *myTarget) )
        {
            itsMainWindow->setCurrentAttributeWaitingForValue( itsMainWindow->getItsTargetListItem()->model()->itemFromIndex( modelIndex.child( 1, 0 ) ) );
        }
    }
    else if ( item->text().startsWith("[") &&  item->text().endsWith("]") && item->child(0) != NULL && item->child(0)->child(0) == NULL )
    {
        TargetInformation * myTarget = *((TargetInformation **)item->data(Qt::UserRole).data());
        QString number = item->text();
        number.replace("[","");
        number.replace("]","");
        if( item->parent()->text().startsWith("[") &&  item->parent()->text().endsWith("]") ){
            QString number2 = item->parent()->text();
            number2.replace("[","");
            number2.replace("]","");
            if( item->parent()->parent()->text().startsWith("[") &&  item->parent()->parent()->text().endsWith("]") ){ // 3. Dimension
                QString number3 = item->parent()->parent()->text();
                number3.replace("[","");
                number3.replace("]","");
    
                unsigned int position = ( number3.toUInt() * item->parent()->parent()->rowCount() ) * item->parent()->rowCount() +
                                 number2.toUInt() * item->parent()->rowCount() +
                                 number.toUInt();
                if( requestArrayAttribut( item->parent() ->parent() ->parent() ->parent() ->parent() ->text(),item->parent()->parent() ->parent() ->text(), position, *myTarget ))
                {
                    itsMainWindow->setCurrentAttributeWaitingForValue( itsMainWindow->getItsTargetListItem()->model()->itemFromIndex( modelIndex.child( 1, 0 ) ) );
                }
            }
            else
            { // 2. Dimension
    
    
                unsigned int position = ( number2.toUInt() ) * item->parent()->rowCount() + number.toUInt();
    
                if( requestArrayAttribut( item->parent() ->parent() ->parent() ->parent() ->text(),item->parent()->parent() ->text(), position,*myTarget ) )
                {
                    itsMainWindow->setCurrentAttributeWaitingForValue( itsMainWindow->getItsTargetListItem()->model()->itemFromIndex( modelIndex.child( 1, 0 ) ) );
                }
            }
        }
        else
        { // 1. Dimension
            if( requestArrayAttribut( item->parent() ->parent() ->parent() ->text(),item->parent() ->text(), number.toUInt(), *myTarget ) )
            {
                itsMainWindow->setCurrentAttributeWaitingForValue( itsMainWindow->getItsTargetListItem()->model()->itemFromIndex( modelIndex.child( 1, 0 ) ) );
            }
        }
    }
    else if ( ( item->text() == "State" ) )
    {
        TargetInformation * myTarget = *((TargetInformation **)item->data(Qt::UserRole).data());
        if( requestState( item->parent()->text(), *myTarget ) )
        {
            itsMainWindow->setCurrentInstanceItemWaitingForState( itsMainWindow->getItsTargetListItem()->model()->itemFromIndex( modelIndex ) );
        }
    }
    //#]
}

void Sender::injectEvent(uint64_t instanceAddress, int eventId, char* eventParameter, int eventParameterCount, TargetInformation& targetInformation)
{
    //#[ operation injectEvent(uint64_t,int,char*,int,TargetInformation)
    if( itsTargetCommunication == NULL)
    {
        return;
    }
    char commandToTarget[500];
    int next;
    commandToTarget[0] = targetInformation.getPointerSize() + 2 + eventParameterCount;
    commandToTarget[1] = command_injectEvent;
    next = 2 + addAddressToStream(instanceAddress,&commandToTarget[2],targetInformation);
    if(targetInformation.getEndianess() == LITTLE_ENDIAN )
    {
        commandToTarget[next] = (char)eventId;
        commandToTarget[next + 1] = (char)( eventId >> 8 );
    }
    else
    {
        commandToTarget[next + 1] = (char)eventId;
        commandToTarget[next] = (char)( eventId >> 8 );
    }
    memcpy(&commandToTarget[next + 2],eventParameter,eventParameterCount);
    itsTargetCommunication->write( commandToTarget, commandToTarget[0] + 2, targetInformation.getId() );
    //#]
}

void Sender::removeBreakpoint(uint64_t instanceAddress, int stateId, int eventId, TargetInformation& targetInformation)
{
    //#[ operation removeBreakpoint(uint64_t,int,int,TargetInformation)
    if( itsTargetCommunication == NULL )
    {
        return;
    }
    char commandToTarget[10];
    int next;
    commandToTarget[0] = targetInformation.getPointerSize() + 4;
    commandToTarget[1] = command_removeBreakpoint;
    next = 2 + addAddressToStream(instanceAddress,&commandToTarget[2],targetInformation);
    
    if(targetInformation.getEndianess() == LITTLE_ENDIAN )
    {
        commandToTarget[next] = (char)stateId;
        commandToTarget[next + 1] = (char)( stateId >> 8 );
        commandToTarget[next + 2] = (char)( eventId );
        commandToTarget[next + 3] = (char)( eventId >> 8 );
    }
    else
    {
        commandToTarget[next + 1] = (char)stateId;
        commandToTarget[next] = (char)( stateId >> 8 );
        commandToTarget[next + 3] = (char)( eventId );
        commandToTarget[next + 2] = (char)( eventId >> 8 );
    }
    itsTargetCommunication->write( commandToTarget, commandToTarget[0] + 2, targetInformation.getId() );
    //#]
}

bool Sender::requestAttribut(const QString& instanceName, const QString& argumentName, TargetInformation& targetInformation)
{
    //#[ operation requestAttribut(QString,QString,TargetInformation)
    ModelInstance *myInstance = targetInformation.getInstance( instanceName );
    if( myInstance != NULL )
    {
        for( auto myAttribute : myInstance->getItsModelClass()->getClassAttributeList() )
        {
            if( myAttribute->getName() == argumentName && myAttribute->getItsModelDataType()->getSize() > 0 )
            {
                if( myAttribute->getOffset() == -1 )
                {
                    itsMainWindow->errorMsg("Request attribute value from attribute \"" + argumentName + "\" of instance \"" + instanceName + "\" Has no correct Offset. Please perform a ReGenerate Code and a ReBuild of you target application."  );
                    return -1;
                }
                uint64_t attributeAddress = myInstance->getFirstAttributeAddress() + myAttribute->getOffset();
                itsMainWindow->consoleMsg("Request attribute value from attribute \"" + argumentName + "\" of instance \"" + instanceName + "\" att address: 0x" + QString::number(attributeAddress,16) );
                char commandToTarget[7];
                int targetId = myInstance->getItsTargetInformation()->getId();
                commandToTarget[0] = targetInformation.getPointerSize() + 1;
                commandToTarget[1] = command_requestAttributeValue;
                unsigned int next = 2 + addAddressToStream( attributeAddress, &commandToTarget[2], targetInformation );
                commandToTarget[next] = myAttribute->getItsModelDataType()->getSize();
                itsTargetCommunication->write( commandToTarget, commandToTarget[0] + 2, targetId);
                return true;
            }
        }
    }
    return false;
    //#]
}

bool Sender::requestState(const QString& instanceName, TargetInformation& targetInformation)
{
    //#[ operation requestState(QString,TargetInformation)
    ModelInstance *myInstance = targetInformation.getInstance( instanceName );
    if( myInstance != NULL )
    {
        uint64_t instanceAddress = myInstance->getAddress();
        int targetId = myInstance->getItsTargetInformation()->getId();
        itsMainWindow->consoleMsg("Request state from instance \"" + instanceName + "\"" );
        char commandToTarget[7];
        commandToTarget[0] = targetInformation.getPointerSize() + 1;
        commandToTarget[1] = command_requestState;
        unsigned int next = 2 + addAddressToStream( instanceAddress, &commandToTarget[2], targetInformation );
        commandToTarget[next] = myInstance->getItsModelClass()->getIsActive();
        itsTargetCommunication->write( commandToTarget, commandToTarget[0] + 2, targetId);
        itsMainWindow->setCurrentModelInstanceWaitingForState( myInstance );
        return true;
    }
    return false;
    //#]
}

void Sender::resumeRXF()
{
    //#[ operation resumeRXF()
    if( itsTargetCommunication == NULL )
    {
        return;
    }
    static char suspendCommand[2] = {0, command_resumeRXF};
    itsTargetCommunication->write(suspendCommand, 2, -1);
    //#]
}

void Sender::suspendRXF()
{
    //#[ operation suspendRXF()
    if( itsTargetCommunication == NULL )
    {
        return;
    }
    static char suspendCommand[2] = {0, command_suspendRXF};
    itsTargetCommunication->write(suspendCommand, 2, -1);
    //#]
}

void Sender::synchronizeTargets()
{
    //#[ operation synchronizeTargets()
    if( itsTargetCommunication == NULL )
    {
        return;
    }
    static char suspendCommand[2] = {0, command_syncTargets};
    itsTargetCommunication->write(suspendCommand, 2, -1);
    //#]
}

unsigned int Sender::addAddressToStream(uint64_t address, char* data, TargetInformation& targetInformation)
{
    //#[ operation addAddressToStream(uint64_t,char*,TargetInformation)
    if( targetInformation.getEndianess() == LITTLE_ENDIAN )
    {
        for(uint i = 0; i < targetInformation.getPointerSize(); i++)
        {
            data[ i ] = (char)(address >> (i * 8));
        }
    }
    else
    {
        for(uint i = 0; i < targetInformation.getPointerSize() ; i++)
        {
            data[ ( targetInformation.getPointerSize() - 1 ) - i ] = (char)(address >> (i * 8));
        }
    }
    return targetInformation.getPointerSize();
    //#]
}

bool Sender::requestArrayAttribut(const QString& instanceName, const QString& argumentName, unsigned int position, TargetInformation& targetInformation)
{
    //#[ operation requestArrayAttribut(QString,QString,unsigned int,TargetInformation)
    ModelInstance *myInstance = targetInformation.getInstance( instanceName );
    if( myInstance != NULL )
    {
        for( auto myAttribute : myInstance->getItsModelClass()->getClassAttributeList() )
        {
            if( myAttribute->getName() == argumentName && myAttribute->getItsModelDataType()->getSize() > 0 )
            {
                if( myAttribute->getOffset() == -1 )
                {
                    itsMainWindow->errorMsg("Request attribute value from attribute \"" + argumentName + "\" of instance \"" + instanceName + "\" Has no correct Offset. Please perform a ReGenerate Code and a ReBuild of you target application."  );
                    return false;
                }
                uint64_t attributeAddress = myInstance->getFirstAttributeAddress() + myAttribute->getOffset() + position * myAttribute->getItsModelDataType()->getSize();
                itsMainWindow->consoleMsg("Request attribute value from attribute \"" + argumentName + "\" of instance \"" + instanceName + "\" att address: 0x" + QString::number(attributeAddress,16) );
                int targetId = myInstance->getItsTargetInformation()->getId();
                char commandToTarget[7];
                commandToTarget[0] = targetInformation.getPointerSize() + 1;
                commandToTarget[1] = command_requestAttributeValue;
                unsigned int next = 2 + addAddressToStream( attributeAddress, &commandToTarget[2], targetInformation );
                commandToTarget[next] = myAttribute->getItsModelDataType()->getSize();
                itsTargetCommunication->write( commandToTarget, commandToTarget[0] + 2, targetId);
                return true;
            }
        }
    }
    return false;
    //#]
}

void Sender::cleanUpRelations()
{
    if(itsMainWindow != NULL)
        {
            itsMainWindow = NULL;
        }
    if(itsTargetCommunication != NULL)
        {
            itsTargetCommunication = NULL;
        }
}

/*********************************************************************
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\Sender.cpp
*********************************************************************/
