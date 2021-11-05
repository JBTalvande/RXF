/********************************************************************
	Rhapsody	: 9.0.1 
	Login		: Y9DSYU706
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: CommandListFilter
//!	Generated Date	: Thu, 4, Nov 2021  
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\CommandListFilter.cpp
*********************************************************************/

#include "CommandListFilter.h"
#include "Command.h"
#include "CommandConstructor.h"
#include "CommandDestructor.h"
#include "CommandEventCreated.h"
#include "CommandEventEndDispatch.h"
#include "CommandEventStartDispatch.h"
#include "CommandIntVal.h"
#include "CommandOperationCall.h"
#include "CommandTraceEvent.h"
#include "ModelEventType.h"
#include "ModelInstance.h"
//## package LogicLevel::Logging::DataContainer::Filter

//## class CommandListFilter
CommandListFilter::CommandListFilter() : tickMin(-1)
{
    //#[ operation CommandListFilter()
    //#]
}

CommandListFilter::~CommandListFilter()
{
    //#[ operation ~CommandListFilter()
    qDeleteAll(this->itsFilterParts);
    //#]
    cleanUpRelations();
}

void CommandListFilter::addFilterPart(FilterPart* newFilterPart)
{
    //#[ operation addFilterPart(FilterPart)
    this->itsFilterParts.append(newFilterPart);
    //#]
}

void CommandListFilter::addTargetFilter(QPair<TargetInformation*, bool>* TargetFilterInfo)
{
    //#[ operation addTargetFilter(QPair<TargetInformation*, bool>*)
    itsTargetFilterList.append( TargetFilterInfo );
    //#]
}

bool CommandListFilter::isFiltered(const Command& command)
{
    //#[ operation isFiltered(Command)
    if( targetFilterd )
    {
        for( int i = 0; i < itsTargetFilterList.size(); i++ )
        {
            if( itsTargetFilterList.at(i)->first == command.getItsTargetInformation() )
            {
                if( itsTargetFilterList.at(i)->second )
                {
                    break;
                }
                else
                {
                    return false;
                }
            }
        }
    }
    if( ticksFilterd )
    {
        if( command.getTicks() < tickMin || command.getTicks() > tickMax )
        {
            return false;
        }
    }
    switch( command.getCommandIdentifier() )
    {
        case Command::eventEndDispatchCommand:
        {
            if( this->itsFilterParts.empty() )
            {
                return true;
            }
            for( auto myFilterPart : this->itsFilterParts )
            {
                CommandEventCreated *myCreateEvent = ((CommandEventEndDispatch&)command).getItsCommandEventStartDispatch()->getItsCommandEventCreated();
                bool returnValue = true;
                if( myFilterPart->getDestinationFilterActive() != FilterPart::NoFilter )
                {
                    if( !isDestinationFiltered( myCreateEvent->getDestinationInstance(), myFilterPart ) )
                    {
                        returnValue = false;
                    }
                }
                if( returnValue && myFilterPart->getSourceFilterActive() != FilterPart::NoFilter )
                {
                    if( !isSourceFiltered( myCreateEvent->getSourceInstance(), myFilterPart ) )
                    {
                        returnValue = false;
                    }
                }
                if( returnValue && myFilterPart->getEventFilterActive() != FilterPart::NoFilter )
                {
                    if( !isEventFiltered( myCreateEvent->getItsModelEventType(), myFilterPart ))
                    {
                        returnValue = false;
                    }
                }
                if( returnValue )
                {
                    return true;
                }
            }
            return false;
            break;
        }
        case Command::eventStartDispatchCommand:
        {
            if( this->itsFilterParts.empty() )
            {
                return true;
            }
    
            for( auto myFilterPart : this->itsFilterParts )
            {
                CommandEventCreated *myCreateEvent = ((CommandEventStartDispatch&)command).getItsCommandEventCreated();
                bool returnValue = true;
                if( myFilterPart->getDestinationFilterActive() != FilterPart::NoFilter )
                {
                    if( !isDestinationFiltered( myCreateEvent->getDestinationInstance(), myFilterPart ) )
                    {
                        returnValue = false;
                    }
                }
                if( returnValue && myFilterPart->getSourceFilterActive() != FilterPart::NoFilter )
                {
                    if( !isSourceFiltered( myCreateEvent->getSourceInstance(), myFilterPart ) )
                    {
                        returnValue = false;
                    }
                }
                if( returnValue && myFilterPart->getEventFilterActive() != FilterPart::NoFilter )
                {
                    if( !isEventFiltered( myCreateEvent->getItsModelEventType(), myFilterPart ))
                    {
                        returnValue = false;
                    }
                }
                if( returnValue )
                {
                    return true;
                }
            }
            return false;
            break;
        }
        case Command::eventPutToMessageQueueCommand:
        {
            if( this->itsFilterParts.empty() )
            {
                return true;
            }
    
            for( auto myFilterPart : this->itsFilterParts )
            {
                const CommandEventCreated& myCreateEvent = (const CommandEventCreated&)command;
                bool returnValue = true;
                if( myFilterPart->getDestinationFilterActive() != FilterPart::NoFilter )
                {
                    if( !isDestinationFiltered( myCreateEvent.getDestinationInstance(), myFilterPart ) )
                    {
                        returnValue = false;
                    }
                }
                if( returnValue && myFilterPart->getSourceFilterActive() != FilterPart::NoFilter )
                {
                    if( !isSourceFiltered( myCreateEvent.getSourceInstance(), myFilterPart ) )
                    {
                        returnValue = false;
                    }
                }
                if( returnValue && myFilterPart->getEventFilterActive() != FilterPart::NoFilter )
                {
                    if( !isEventFiltered( myCreateEvent.getItsModelEventType(), myFilterPart ))
                    {
                        returnValue = false;
                    }
                }
                if( returnValue )
                {
                    return true;
                }
            }
            return false;
            break;
        }
        case Command::traceEventCommand:
        {
            if( this->itsFilterParts.empty() )
            {
                return true;
            }
            for( auto myFilterPart : this->itsFilterParts )
            {
                const CommandTraceEvent& myTraceEvent = (const CommandTraceEvent&)command;
                bool returnValue = true;
                if( myFilterPart->getDestinationFilterActive() != FilterPart::NoFilter )
                {
                    if( !isDestinationFiltered( myTraceEvent.getDestinationInstance(), myFilterPart ) )
                    {
                        returnValue = false;
                    }
                }
                if( returnValue && myFilterPart->getSourceFilterActive() != FilterPart::NoFilter )
                {
                    if( !isSourceFiltered( myTraceEvent.getSourceInstance(), myFilterPart ) )
                    {
                        returnValue = false;
                    }
                }
                if( returnValue && myFilterPart->getEventFilterActive() != FilterPart::NoFilter )
                {
                    if( !isEventFiltered( myTraceEvent.getItsModelEventType(), myFilterPart ))
                    {
                        returnValue = false;
                    }
                }
                if( returnValue )
                {
                    return true;
                }
            }
            return false;
            break;
        }
        case Command::operationCalled:
        {
            if( this->itsFilterParts.empty() )
            {
                return true;
            }
    
            for( auto myFilterPart : this->itsFilterParts )
            {
                const CommandOperationCall& myCreateEvent = (const CommandOperationCall&)command;
                bool returnValue = true;
                if( myFilterPart->getDestinationFilterActive() != FilterPart::NoFilter )
                {
                    if( !isDestinationFiltered( myCreateEvent.getDestinationInstance(), myFilterPart ) )
                    {
                        returnValue = false;
                    }
                }
                if( returnValue && myFilterPart->getSourceFilterActive() != FilterPart::NoFilter )
                {
                    if( !isSourceFiltered( myCreateEvent.getSourceInstance(), myFilterPart ) )
                    {
                        returnValue = false;
                    }
                }
                if( returnValue && myFilterPart->getEventFilterActive() != FilterPart::NoFilter )
                {
                    if( !isEventFiltered( myCreateEvent.getItsModelEventType(), myFilterPart ))
                    {
                        returnValue = false;
                    }
                }
                if( returnValue )
                {
                    return true;
                }
            }
            return false;
            break;
        }
        case Command::bufferOverflowCommand:
        {
            if( bufferOverflowFilterd )
            {
                return true;
            }
            else
            {
                return false;
            }
            break;
        }
        case Command::constructorCommand:
        {
            if( constructorFilterd )
            {
                bool returnVal = true;
                const CommandConstructor &constructorCommand = (const CommandConstructor&)command;
                for( auto myFilterPart : this->itsFilterParts )
                {
                    returnVal = false;
                    if( myFilterPart->getDestinationFilterActive() != FilterPart::NoFilter )
                    {
                        if( isDestinationFiltered( constructorCommand.getItsModelInstance(), myFilterPart ) )
                        {
                            return true;
                        }
                    }
                    if( myFilterPart->getSourceFilterActive() != FilterPart::NoFilter )
                    {
                        if( isSourceFiltered( constructorCommand.getItsModelInstance(), myFilterPart ) )
                        {
                            return true;
                        }
                    }
                }
                return returnVal;
            }
            else
            {
                return false;
            }
            break;
        }
        case Command::destructorCommand:
        {
            if( destructorFilterd )
            {
                bool returnVal = true;
                const CommandConstructor &destructorCommand = (const CommandConstructor&)command;
                for( auto myFilterPart : this->itsFilterParts )
                {
                    returnVal = false;
                    if( myFilterPart->getDestinationFilterActive() != FilterPart::NoFilter )
                    {
                        if( isDestinationFiltered( destructorCommand.getItsModelInstance(), myFilterPart ) )
                        {
                            return true;
                        }
                    }
                    if( myFilterPart->getSourceFilterActive() != FilterPart::NoFilter )
                    {
                        if( isSourceFiltered( destructorCommand.getItsModelInstance(), myFilterPart ) )
                        {
                            return true;
                        }
                    }
                }
                return returnVal;
            }
            else
            {
                return false;
            }
            break;
        }
        case Command::errorHandlerReachedCommand:
        {
            if( errorHandlerFilterd )
            {
                return true;
            }
            else
            {
                return false;
            }
            break;
        }
    case Command::debugIntValue:
    {
        if( debugIntFiltered )
        {
            bool returnVal = true;
            const CommandIntVal &intVallCommand = (const CommandIntVal&)command;
            for( auto myFilterPart : this->itsFilterParts )
            {
                returnVal = false;
                if( myFilterPart->getDestinationFilterActive() != FilterPart::NoFilter )
                {
                    if( isDestinationFiltered( intVallCommand.getInstance(), myFilterPart ) )
                    {
                        return true;
                    }
                }
                if( myFilterPart->getSourceFilterActive() != FilterPart::NoFilter )
                {
                    if( isSourceFiltered( intVallCommand.getInstance(), myFilterPart ) )
                    {
                        return true;
                    }
                }
            }
            return returnVal;
        }
        else
        {
            return false;
        }
        break;
    }
    }
    return true;
    //#]
}

bool CommandListFilter::isDestinationFiltered(ModelInstance* instance, FilterPart* filterPart)
{
    //#[ operation isDestinationFiltered(ModelInstance,FilterPart)
    bool whiteList = true;
    if( filterPart->getDestinationFilterActive() == FilterPart::BlackList )
    {
        whiteList = false;
    }
    for( int i = 0; i < filterPart->getItsDestinationFilterList().size(); i++ )
    {
        if( filterPart->getItsDestinationFilterList().at( i ) == instance )
        {
            return whiteList;
        }
    }
    return !whiteList;
    //#]
}

bool CommandListFilter::isEventFiltered(ModelEventType* eventType, FilterPart* filterPart)
{
    //#[ operation isEventFiltered(ModelEventType,FilterPart)
    bool whiteList = true;
    if( filterPart->getEventFilterActive() == FilterPart::BlackList )
    {
        whiteList = false;
    }
    for( int i = 0; i < filterPart->getItsEventFilterList().size(); i++ )
    {
        if( filterPart->getItsEventFilterList().at( i ) == eventType )
        {
            return whiteList;
        }
    }
    return !whiteList;
    //#]
}

bool CommandListFilter::isSourceFiltered(ModelInstance* instance, FilterPart* filterPart)
{
    //#[ operation isSourceFiltered(ModelInstance,FilterPart)
    bool whiteList = true;
    if( filterPart->getSourceFilterActive() == FilterPart::BlackList )
    {
        whiteList = false;
    }
    for( int i = 0; i < filterPart->getItsSourceFilterList().size(); i++ )
    {
        if( filterPart->getItsSourceFilterList().at( i ) == instance )
        {
            return whiteList;
        }
    }
    return !whiteList;
    //#]
}

void CommandListFilter::cleanUpRelations()
{
    {
        itsTargetFilterList.clear();
    }
}

/*********************************************************************
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\CommandListFilter.cpp
*********************************************************************/
