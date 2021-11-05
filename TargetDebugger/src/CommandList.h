/*********************************************************************
	Rhapsody	: 9.0.1 
	Login		: Y9DSYU706
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: CommandList
//!	Generated Date	: Thu, 4, Nov 2021  
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\CommandList.h
*********************************************************************/

#ifndef CommandList_H
#define CommandList_H

#include "DataContainer.h"
#include <QList>
#include <QVector>
#include "Command.h"
#include "ModelInstance.h"
#include <QSettings.h>
#include <QStandardItem>
#include <QGraphicsScene>
class CommandEventCreated;

class CommandEventEndDispatch;

class CommandEventStartDispatch;

class CommandListFilter;

class ModelEventType;

class TargetInformation;

class TargetList;

//## package LogicLevel::Logging::DataContainer

//## class CommandList
class CommandList : public QStandardItem {
    ////    Constructors and destructors    ////
    
public :

    //## operation CommandList(TargetList)
    CommandList(const TargetList& targetList);
    
    ~CommandList();
    
    ////    Operations    ////
    
    // inserts a new CommandList at the beginning of its childList.
    //## operation addChildList(CommandList)
    void addChildList(CommandList* newCommandList);
    
    //## operation addCommand(Command,bool)
    bool addCommand(Command* const command, bool isRootList);
    
    //## operation addSDInstanceXPosition(ModelInstance,int)
    void addSDInstanceXPosition(ModelInstance* instance, int xPos);
    
    //## operation clear()
    void clear();
    
    //## operation getCommandCounter()
    unsigned int getCommandCounter();
    
    //## operation getCommandDisplayNumberInSequenceDiagram(unsigned int) const
    inline unsigned int getCommandDisplayNumberInSequenceDiagram(unsigned int rootNumber) const;
    
    //## operation getCommands() const
    inline const QVector<Command*>& getCommands() const
    {
        //#[ operation getCommands() const
        return this->commands;
        //#]
    }
    
    //## operation getItsInstanceXPositionList()
    inline QList<QPair<ModelInstance*,int>*>* getItsInstanceXPositionList();
    
    //## operation getSDInstanceXPosition(ModelInstance)
    int getSDInstanceXPosition(ModelInstance* instance);
    
    //## operation loadFilterSettings(QSettings,bool)
    void loadFilterSettings(QSettings& mySettingFile, bool isRoot);
    
    //## operation saveFilterSettings(QSettings)
    void saveFilterSettings(QSettings& mySettingFile);
    
    //## operation updateSDInstanceXPosition(ModelInstance,int)
    void updateSDInstanceXPosition(ModelInstance* instance, int xPos);
    
    ////    Additional operations    ////
    
    inline unsigned int getCurrentCommandInSequenceDiagram() const
    {
        return currentCommandInSequenceDiagram;
    }
    
    inline void setCurrentCommandInSequenceDiagram(unsigned int p_currentCommandInSequenceDiagram)
    {
        currentCommandInSequenceDiagram = p_currentCommandInSequenceDiagram;
    }
    
    inline int getLastTick() const
    {
        return lastTick;
    }
    
    inline void setLastTick(int p_lastTick)
    {
        lastTick = p_lastTick;
    }
    
    inline int getStartTickInTimingDiagram() const
    {
        return startTickInTimingDiagram;
    }
    
    inline void setStartTickInTimingDiagram(int p_startTickInTimingDiagram)
    {
        startTickInTimingDiagram = p_startTickInTimingDiagram;
    }
    
    inline int getTickRangeInTimingDiagram() const
    {
        return tickRangeInTimingDiagram;
    }
    
    inline void setTickRangeInTimingDiagram(int p_tickRangeInTimingDiagram)
    {
        tickRangeInTimingDiagram = p_tickRangeInTimingDiagram;
    }
    
    inline void clearCommands()
    {
        commands.clear();
    }
    
    inline CommandListFilter* getItsCommandListFilter() const
    {
        return itsCommandListFilter;
    }
    
    inline void setItsCommandListFilter(CommandListFilter* p_CommandListFilter)
    {
        itsCommandListFilter = p_CommandListFilter;
    }
    
    inline TargetList* getItsTargetList() const
    {
        return itsTargetList;
    }
    
    inline void setItsTargetList(TargetList* p_TargetList)
    {
        itsTargetList = p_TargetList;
    }

protected :

    void cleanUpRelations();
    
    ////    Attributes    ////

private :

    QMap<unsigned int, unsigned int> commandDisplayNumberInSequenceDiagram;		//## attribute commandDisplayNumberInSequenceDiagram
    
    unsigned int currentCommandInSequenceDiagram;		//## attribute currentCommandInSequenceDiagram
    
    int lastTick;		//## attribute lastTick
    
    int startTickInTimingDiagram;		//## attribute startTickInTimingDiagram
    
    int tickRangeInTimingDiagram;		//## attribute tickRangeInTimingDiagram
    
    ////    Relations and components    ////

protected :

    QList<CommandList*> childList;
    
    QVector<Command*> commands;
    
    CommandListFilter* itsCommandListFilter;
    
    QList<QPair<ModelInstance*,int>*> itsInstanceXPositionList;
    
    TargetList* itsTargetList;
};

inline unsigned int CommandList::getCommandDisplayNumberInSequenceDiagram(unsigned int rootNumber) const
{
    //#[ operation getCommandDisplayNumberInSequenceDiagram(unsigned int) const
    return this->commandDisplayNumberInSequenceDiagram[ rootNumber ];
    //#]
}

inline QList<QPair<ModelInstance*,int>*>* CommandList::getItsInstanceXPositionList()
{
    //#[ operation getItsInstanceXPositionList()
    return &itsInstanceXPositionList;
    //#]
}

#endif
/*********************************************************************
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\CommandList.h
*********************************************************************/
