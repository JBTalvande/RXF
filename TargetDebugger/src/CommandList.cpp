/********************************************************************
	Rhapsody	: 9.0.1 
	Login		: Y9DSYU706
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: CommandList
//!	Generated Date	: Thu, 4, Nov 2021  
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\CommandList.cpp
*********************************************************************/

#include "CommandList.h"
#include "CommandEventCreated.h"
#include "CommandEventEndDispatch.h"
#include "CommandEventStartDispatch.h"
#include "CommandListFilter.h"
#include "ModelEventType.h"
#include "TargetInformation.h"
#include "TargetList.h"
//## package LogicLevel::Logging::DataContainer

//## class CommandList
CommandList::CommandList(const TargetList& targetList) : lastTick(0), startTickInTimingDiagram(0), tickRangeInTimingDiagram(100), itsTargetList( (TargetList*)&targetList)
{
    itsCommandListFilter = NULL;
    //#[ operation CommandList(TargetList)
    //#]
}

CommandList::~CommandList()
{
    cleanUpRelations();
}

void CommandList::addChildList(CommandList* newCommandList)
{
    //#[ operation addChildList(CommandList)
    this->childList.prepend(newCommandList);
    //#]
}

bool CommandList::addCommand(Command* const command, bool isRootList)
{
    //#[ operation addCommand(Command,bool)
    bool isAddedToList = false;
    if( itsCommandListFilter == NULL || itsCommandListFilter->isFiltered( *command ) )
    {
        if( isRootList )
        {
            if( command->getTicks() == -1 )
            {
                command->setTicks( lastTick );
            }
            else
            {
                lastTick = command->getTicks();
            }
        }
        // < 3 because id 0, 1 and 2 are Tripple Event Data
        if( command->getCommandIdentifier() < 3 )
        {
            if( isRootList )
            {
                commandDisplayNumberInSequenceDiagram[ commands.size() ] = commands.size();
                ((CommandEventTripletData*)command)->setDisplayNumber( commands.size() );
            }
            else
            {
                commandDisplayNumberInSequenceDiagram[ ((CommandEventTripletData*)command)->getDisplayNumber() ] = commands.size();
            }
        }
    
        commands.append( command );
    
        for( auto childCommandList : this->childList )
        {
            childCommandList->addCommand( command, false );
        }
        isAddedToList = true;
    }
    
    return isAddedToList;
    //#]
}

void CommandList::addSDInstanceXPosition(ModelInstance* instance, int xPos)
{
    //#[ operation addSDInstanceXPosition(ModelInstance,int)
    itsInstanceXPositionList.append( new QPair<ModelInstance*,int>(instance,xPos));
    //#]
}

void CommandList::clear()
{
    //#[ operation clear()
    commands.clear();
    lastTick = 0;   
    commandDisplayNumberInSequenceDiagram.clear();
    currentCommandInSequenceDiagram = 0;
    
    for( auto childCommandList : this->childList )
    {
        childCommandList->clear();
    }     
    //#]
}

unsigned int CommandList::getCommandCounter()
{
    //#[ operation getCommandCounter()
    return this->commands.size();
    //#]
}

int CommandList::getSDInstanceXPosition(ModelInstance* instance)
{
    //#[ operation getSDInstanceXPosition(ModelInstance)
    for(auto aInstance : itsInstanceXPositionList )
    {
        if( aInstance->first == instance )
        {
            return aInstance->second;
        }
    }
    return -1;
    //#]
}

void CommandList::loadFilterSettings(QSettings& mySettingFile, bool isRoot)
{
    //#[ operation loadFilterSettings(QSettings,bool)
    mySettingFile.beginGroup("commandList");
    int instancePosSize = mySettingFile.beginReadArray("instancePositions");
    for( int i = 0; i < instancePosSize; i++)
    {
        mySettingFile.setArrayIndex( i );
    
        int targetId = mySettingFile.value("targetNr").toInt();
        TargetInformation *myTarget = itsTargetList->getTarget( targetId );
        if( myTarget != NULL )
        {
            QString instanceName = mySettingFile.value("name").toString();
            ModelInstance *myInstance = myTarget->getInstance(instanceName);
            if( myInstance != NULL )
            {
                int myNewPos = mySettingFile.value("position").toInt();
                int pos = this->getSDInstanceXPosition( myInstance );
                if( pos == -1 )
                {
                    addSDInstanceXPosition(myInstance, myNewPos);
                }
                else
                {
                    updateSDInstanceXPosition(myInstance, myNewPos);
                }
            }
        }
    
    
    }
    mySettingFile.endArray();
    if( mySettingFile.value("hasFilter").toBool() )
    {
        itsCommandListFilter = new CommandListFilter();
        itsCommandListFilter->setConstructorFilterd( mySettingFile.value("constructor").toBool() );
        itsCommandListFilter->setDestructorFilterd( mySettingFile.value("destructor").toBool() );
        itsCommandListFilter->setErrorHandlerFilterd( mySettingFile.value("error").toBool() );
        itsCommandListFilter->setBufferOverflowFilterd( mySettingFile.value("buffer").toBool() );
        itsCommandListFilter->setDebugIntFiltered( mySettingFile.value("debugInt").toBool() );
        itsCommandListFilter->setTicksFilterd( mySettingFile.value("tickFilter").toBool() );
        itsCommandListFilter->setTickMax( mySettingFile.value("ticksMax").toInt() );
        itsCommandListFilter->setTickMin( mySettingFile.value("ticksMin").toInt() );
        if( mySettingFile.value("targetFilter").toBool() )
        {
            itsCommandListFilter->setTargetFilterd( true );
            int targetCount = mySettingFile.beginReadArray("targets");
            for( int i = 0; i <targetCount; i++ )
            {
                mySettingFile.setArrayIndex( i );
                TargetInformation *myTarget = itsTargetList->getTarget( mySettingFile.value("target").toString() );
                if( myTarget != NULL )
                {
                    itsCommandListFilter->addTargetFilter( new QPair<TargetInformation*,bool>(myTarget, mySettingFile.value("active").toBool()) );
                }
            }
            mySettingFile.endArray();
        }
        else
        {
            itsCommandListFilter->setTargetFilterd( false );
        }
        if( mySettingFile.value("hasFilterParts" ).toBool() )
        {
            int targetCount = mySettingFile.beginReadArray("filterParts");
            for( int i = 0; i < targetCount; i++ )
            {
                mySettingFile.setArrayIndex( i );
                FilterPart *myFilterPart = new FilterPart();
                if( mySettingFile.value("destFilter").toBool() )
                {
                    if( !mySettingFile.value("destWhiteList").isValid() || mySettingFile.value("destWhiteList").toBool() )
                    {
                        myFilterPart->setDestinationFilterActive( FilterPart::WhiteList );
                    }
                    else
                    {
                        myFilterPart->setDestinationFilterActive( FilterPart::BlackList );
                    }
    
                    int destInstanceCount = mySettingFile.beginReadArray("destInstances");
                    for( int j = 0; j < destInstanceCount; j++)
                    {
                        mySettingFile.setArrayIndex( j );
                        QStringList myList = mySettingFile.value("instance").toString().split(".");
                        TargetInformation * myTarget = itsTargetList->getTarget( myList[0]);
                        if( myTarget != NULL )
                        {
                            ModelInstance *myInstance = myTarget->getInstance( myList[1] );
                            if( myInstance != NULL )
                            {
                                myFilterPart->addItsDestinationFilterList( myInstance );
                            }
                        }
                    }
                    mySettingFile.endArray();
                }
                else
                {
                    myFilterPart->setDestinationFilterActive( FilterPart::NoFilter );
                }
    
                if( mySettingFile.value("sourceFilter").toBool() )
                {
                    if( !mySettingFile.value("sourceWhiteList").isValid() || mySettingFile.value("sourceWhiteList").toBool() )
                    {
                        myFilterPart->setSourceFilterActive( FilterPart::WhiteList );
                    }
                    else
                    {
                        myFilterPart->setSourceFilterActive( FilterPart::BlackList );
                    }
    
                    int sourceInstanceCount = mySettingFile.beginReadArray("sourceInstances");
                    for( int j = 0; j < sourceInstanceCount; j++)
                    {
                        mySettingFile.setArrayIndex( j );
                        QStringList myList = mySettingFile.value("instance").toString().split(".");
                        TargetInformation * myTarget = itsTargetList->getTarget( myList[0]);
                        if( myTarget != NULL )
                        {
                            ModelInstance *myInstance = myTarget->getInstance( myList[1] );
                            if( myInstance != NULL )
                            {
                                myFilterPart->addItsSourceFilterList( myInstance );
                            }
                        }
                    }
                    mySettingFile.endArray();
                }
                else
                {
                    myFilterPart->setSourceFilterActive( FilterPart::NoFilter );
                }
    
                if( mySettingFile.value("eventFilter").toBool() )
                {
                    if( !mySettingFile.value("eventWhiteList").isValid() || mySettingFile.value("eventWhiteList").toBool() )
                    {
                        myFilterPart->setEventFilterActive( FilterPart::WhiteList );
                    }
                    else
                    {
                        myFilterPart->setEventFilterActive( FilterPart::BlackList );
                    }
                    int eventCount = mySettingFile.beginReadArray("events");
                    for( int j = 0; j < eventCount; j++)
                    {
                        mySettingFile.setArrayIndex( j );
                        QStringList myList = mySettingFile.value("event").toString().split(".");
                        TargetInformation * myTarget = itsTargetList->getTarget( myList[0]);
                        if( myTarget != NULL )
                        {
                            ModelEventType *myEvent = (ModelEventType *)myTarget->getEventType( myList[1] );
                            if( myEvent != NULL )
                            {
                                myFilterPart->addItsEventFilterList( myEvent );
                            }
                        }
                    }
                    mySettingFile.endArray();
                }
                else
                {
                    myFilterPart->setEventFilterActive( FilterPart::NoFilter );
                }
    
                itsCommandListFilter->addFilterPart( myFilterPart );
            }
            mySettingFile.endArray();
        }
    }
    int childListCount = mySettingFile.beginReadArray("ChildCommandLists");
    for( int i = 0; i <childListCount; i++ )
    {
        mySettingFile.setArrayIndex( i );
        CommandList *myChildList = new CommandList( *itsTargetList );
        myChildList->setText( mySettingFile.value("child").toString() );
        appendRow(myChildList);
        addChildList( myChildList );
        myChildList->loadFilterSettings(mySettingFile, false);
        if( isRoot )
        {
            for(int i = 0; i < commands.size(); i++ )
            {
               myChildList->addCommand( commands.at( i ), false );
            }
        }
    }
    mySettingFile.endArray();
    mySettingFile.endGroup();
    //#]
}

void CommandList::saveFilterSettings(QSettings& mySettingFile)
{
    //#[ operation saveFilterSettings(QSettings)
    mySettingFile.beginGroup("commandList");
    mySettingFile.beginWriteArray("instancePositions", itsInstanceXPositionList.size());
    for( int i = 0; i < itsInstanceXPositionList.size(); i++)
    {
        mySettingFile.setArrayIndex( i );
        mySettingFile.setValue("name",itsInstanceXPositionList.at(i)->first->getName());
        mySettingFile.setValue("position",itsInstanceXPositionList.at(i)->second);
        mySettingFile.setValue("targetNr",itsInstanceXPositionList.at(i)->first->getItsTargetInformation()->getId() );
    }
    mySettingFile.endArray();
    
    mySettingFile.setValue("name", text());
    if( itsCommandListFilter == NULL )
    {
        mySettingFile.setValue("hasFilter", false );
    }
    else
    {
        mySettingFile.setValue("hasFilter", true );
        mySettingFile.setValue("constructor", itsCommandListFilter->getConstructorFilterd() );
        mySettingFile.setValue("destructor", itsCommandListFilter->getDestructorFilterd() );
        mySettingFile.setValue("error", itsCommandListFilter->getErrorHandlerFilterd() );
        mySettingFile.setValue("buffer", itsCommandListFilter->getBufferOverflowFilterd() );
        mySettingFile.setValue("debugInt", itsCommandListFilter->getDebugIntFiltered() );
        mySettingFile.setValue("tickFilter", itsCommandListFilter->getTicksFilterd() );
        mySettingFile.setValue("ticksMax", itsCommandListFilter->getTickMax() );
        mySettingFile.setValue("ticksMin", itsCommandListFilter->getTickMin() );
    
        if( itsCommandListFilter->getTargetFilterd() )
        {
            mySettingFile.setValue("targetFilter", true);
            mySettingFile.beginWriteArray("targets", itsCommandListFilter->getItsTargetFilterList().size() );
            for( int i = 0; i < itsCommandListFilter->getItsTargetFilterList().size(); i++)
            {
                mySettingFile.setArrayIndex( i );
                mySettingFile.setValue("target", itsCommandListFilter->getItsTargetFilterList().at( i )->first->getName() );
                if( itsCommandListFilter->getItsTargetFilterList().at( i )->second )
                {
                    mySettingFile.setValue("active", true );
                }
                else
                {
                    mySettingFile.setValue("active", false );
                }
            }
            mySettingFile.endArray();
        }
        else
        {
            mySettingFile.setValue("targetFilter", false);
        }
    
        if( itsCommandListFilter->getFilterPartList().size() == 0 )
        {
            mySettingFile.setValue("hasFilterParts", false);
        }
        else
        {
            mySettingFile.setValue("hasFilterParts", true);
            mySettingFile.beginWriteArray("filterParts", itsCommandListFilter->getFilterPartList().size());
            for( int i = 0; i < itsCommandListFilter->getFilterPartList().size(); i++)
            {
                FilterPart *myFilterPart = itsCommandListFilter->getFilterPartList().at(i);
                mySettingFile.setArrayIndex( i );
                if( myFilterPart->getDestinationFilterActive() != FilterPart::NoFilter )
                {
                    mySettingFile.setValue("destFilter", true);
                    if( myFilterPart->getDestinationFilterActive() == FilterPart::WhiteList )
                    {
                        mySettingFile.setValue("destWhiteList", true);
                    }
                    else
                    {
                        mySettingFile.setValue("destWhiteList", false);
                    }
                    mySettingFile.beginWriteArray("destInstances", myFilterPart->getItsDestinationFilterList().size());
                    for( int j = 0; j < myFilterPart->getItsDestinationFilterList().size(); j++)
                    {
                        mySettingFile.setArrayIndex( j );
                        ModelInstance * aInstance = myFilterPart->getItsDestinationFilterList().at( j );
                        mySettingFile.setValue("instance", aInstance->getItsTargetInformation()->getName() + "." + aInstance->getName() );
                    }
                    mySettingFile.endArray();
                }
                else
                {
                    mySettingFile.setValue("destFilter", false);
                }
    
                if(myFilterPart->getSourceFilterActive() != FilterPart::NoFilter )
                {
                    mySettingFile.setValue("sourceFilter", true);
                    if( myFilterPart->getSourceFilterActive() == FilterPart::WhiteList )
                    {
                        mySettingFile.setValue("sourceWhiteList", true);
                    }
                    else
                    {
                        mySettingFile.setValue("sourceWhiteList", false);
                    }
                    mySettingFile.beginWriteArray("sourceInstances", myFilterPart->getItsSourceFilterList().size());
                    for( int j = 0; j < myFilterPart->getItsSourceFilterList().size(); j++)
                    {
                        mySettingFile.setArrayIndex( j );
                        ModelInstance * aInstance = myFilterPart->getItsSourceFilterList().at( j );
                        mySettingFile.setValue("instance", aInstance->getItsTargetInformation()->getName() + "." + aInstance->getName() );
                    }
                    mySettingFile.endArray();
                }
                else
                {
                    mySettingFile.setValue("sourceFilter", false);
                }
    
                if( myFilterPart->getEventFilterActive() != FilterPart::NoFilter )
                {
                    mySettingFile.setValue("eventFilter", true);
                    if( myFilterPart->getEventFilterActive() == FilterPart::WhiteList )
                    {
                        mySettingFile.setValue("eventWhiteList", true);
                    }
                    else
                    {
                        mySettingFile.setValue("eventWhiteList", false);
                    }
                    mySettingFile.beginWriteArray("events", myFilterPart->getItsEventFilterList().size());
                    for( int j = 0; j < myFilterPart->getItsEventFilterList().size(); j++)
                    {
                        mySettingFile.setArrayIndex( j );
                        ModelEventType * aEvent = myFilterPart->getItsEventFilterList().at( j );
                        mySettingFile.setValue("event", aEvent->getItsTargetInformation()->getName() + "." + aEvent->getName() );
                    }
                    mySettingFile.endArray();
                }
                else
                {
                    mySettingFile.setValue("eventFilter", false);
                }
            }
            mySettingFile.endArray();
        }
    }
    mySettingFile.beginWriteArray("ChildCommandLists", childList.size());
    for( int i = 0; i< childList.size(); i++ )
    {
        mySettingFile.setArrayIndex( i );
        mySettingFile.setValue("child", childList.at( i )->text());
        childList.at( i )->saveFilterSettings( mySettingFile );
    }
    mySettingFile.endArray();
    mySettingFile.endGroup();
    //#]
}

void CommandList::updateSDInstanceXPosition(ModelInstance* instance, int xPos)
{
    //#[ operation updateSDInstanceXPosition(ModelInstance,int)
    for(auto aInstance : itsInstanceXPositionList )
    {
        if( aInstance->first == instance )
        {
            aInstance->second = xPos;
            return;
        }
    }
    //#]
}

void CommandList::cleanUpRelations()
{
    {
        childList.clear();
    }
    {
        commands.clear();
    }
    if(itsCommandListFilter != NULL)
        {
            itsCommandListFilter = NULL;
        }
    {
        itsInstanceXPositionList.clear();
    }
    if(itsTargetList != NULL)
        {
            itsTargetList = NULL;
        }
}

/*********************************************************************
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\CommandList.cpp
*********************************************************************/
