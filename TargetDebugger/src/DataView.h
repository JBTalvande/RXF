/*********************************************************************
	Rhapsody	: 9.0.1 
	Login		: Y9DSYU706
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: DataView
//!	Generated Date	: Thu, 4, Nov 2021  
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\DataView.h
*********************************************************************/

#ifndef DataView_H
#define DataView_H

#include "SequenceDiagram.h"
class CommandList;

//## package GUI

//## class DataView

namespace Ui {
class DataView;
}

class DataView : public QWidget {
    ////    Constructors and destructors    ////
    
public :

    //## operation DataView(CommandList)
    DataView(CommandList* commandList);
    
    //## operation ~DataView()
    ~DataView();
    
    ////    Operations    ////

private :

    //## operation connectSignals()
    void connectSignals();
    
    //## operation disconnectSignals()
    void disconnectSignals();
    
    ////    Additional operations    ////

public :

    inline Ui::DataView * getUi() const
    {
        return ui;
    }
    
    inline void setUi(Ui::DataView * p_ui)
    {
        ui = p_ui;
    }
    
    inline SequenceDiagram* getItsSequenceDiagram() const
    {
        return (SequenceDiagram*) &itsSequenceDiagram;
    }
    
    ////    Attributes    ////

private :

    Ui::DataView * ui;		//## attribute ui
    
    ////    Relations and components    ////

protected :

    SequenceDiagram itsSequenceDiagram;
};

#endif
/*********************************************************************
	File Path	: C:\V7\DevTools\TargetDebugger\Code\TargetDebugger\GeneratedModel\DataView.h
*********************************************************************/
