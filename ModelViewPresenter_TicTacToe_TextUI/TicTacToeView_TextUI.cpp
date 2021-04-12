//***************************************************************************
// File name:  TicTacToeView_TextUI.h
// Author:     Chadd Williams
// Date:       3/22/2017
// Class:      CS485
// Assignment: Model View Presenter Example
// Purpose:    Demonstrate how the Model View Presenter is used
//***************************************************************************
#include "TicTacToeView_TextUI.h"
#include "TicTacToePresenter.h"
#include <sstream>

//***************************************************************************
// Constructor: TicTacToeView_TextUI
//
// Description: Initialize the on-screen widgets, hookup event handlders,
//              load fonts, register widgets with TextUI
//
// Parameters:  None
//
// Returned:    None
//***************************************************************************

TicTacToeView_TextUI::TicTacToeView_TextUI (): TextUI(std::cout, std::cin)
{
  TextUITextWidget *pcWidget;
  //setView (this);
  mpcTTTPresenter = new TicTacToePresenter (this);

  mpPlayer1Name = new TextUITextWidget ("Player1", "");
  mpPlayer2Name = new TextUITextWidget ("Player2", "");
  mpWinnerName = new TextUITextWidget ("", "");

  addWidget (2, 3, mpPlayer1Name);
  addWidget (20, 3, mpPlayer2Name);
  addWidget (10, 4, mpWinnerName);

  for (int x = 0; x < 3; x++)
  {
    for (int y = 0; y < 3; y++)
    {
      pcWidget = new TextUITextWidget ("", "_");
      addWidget (x + 10, y + 10, pcWidget);
      macBoard.setWidget (x, y, pcWidget);
    }
  }
  registerEvent ("MOVE",
    std::bind
    (&TicTacToeView_TextUI::onMakeMove, this, std::placeholders::_1));
    //&ITicTacToeView::onMakeMove);

  registerEvent ("SETPLAYER1NAME", 
    std::bind
    (&TicTacToeView_TextUI::onSetPlayer1Name, this, std::placeholders::_1));
    //&ITicTacToeView::onSetPlayer1Name);

  registerEvent ("SETPLAYER2NAME", 
    std::bind
    (&TicTacToeView_TextUI::onSetPlayer2Name, this, std::placeholders::_1));
      //&ITicTacToeView::onSetPlayer2Name);


  registerEvent ("SETPLAYER1SYMBOL", 
    std::bind
    (&TicTacToeView_TextUI::onSetPlayer1Symbol, this, std::placeholders::_1));

    //&ITicTacToeView::onSetPlayer1Symbol);
  registerEvent ("SETPLAYER2SYMBOL",
    std::bind
    (&TicTacToeView_TextUI::onSetPlayer2Symbol, this, std::placeholders::_1));
  
  //&ITicTacToeView::onSetPlayer2Symbol);

  onSetPlayer1Name ("shereen");
  onSetPlayer2Name ("computer");

}

//***************************************************************************
// Destructor:  ~TicTacToeView_TextUI
//
// Description: Delete the presenter
//
// Parameters:  None
//
// Returned:    None
//***************************************************************************
TicTacToeView_TextUI::~TicTacToeView_TextUI ()
{
  delete mpcTTTPresenter;
}

//***************************************************************************
// Function:    setPlayer1Name
//
// Description:  From Presenter: Set player 1's name
//
// Parameters:  name - the name
//
// Returned:    None
//***************************************************************************
void TicTacToeView_TextUI::setPlayer1Name (std::string name)
{
  mpPlayer1Name->setData (name);
}

//***************************************************************************
// Function:    setPlayer2Name
//
// Description:  From Presenter: Set player 2's name
//
// Parameters:  name - the name
//
// Returned:    None
//***************************************************************************
void TicTacToeView_TextUI::setPlayer2Name (std::string name)
{
  mpPlayer2Name->setData (name);
}

//***************************************************************************
// Function:    setWinner
//
// Description:  From Presenter: Set the winner message
//
// Parameters:  name - the winner's name
//
// Returned:    None
//***************************************************************************
void TicTacToeView_TextUI::setWinner (std::string name)
{
  mpWinnerName->setLabel ("WINNER! ");
  mpWinnerName->setData (name);
}

//***************************************************************************
// Function:    setMove
//
// Description: From Presenter: set the mvoe on the visible boards
//
// Parameters:  x - x coordinate
//              y - y coordinate
//              symbol - the symbol to use
//
// Returned:    None
//***************************************************************************
void TicTacToeView_TextUI::setMove (int x, int y, std::string symbol)
{
  macBoard.setMove (x, y, symbol);
}

//***************************************************************************
// Function:    resetUI
//
// Description: Clear the data from the widgets
//
// Parameters:  None
//
// Returned:    None
//***************************************************************************
void TicTacToeView_TextUI::resetUI ()
{
  mpPlayer1Name->setData ("");
  mpPlayer2Name->setData ("");
  mpWinnerName->setData ("");
  macBoard.clear ();
  redrawUI ();
}

//***************************************************************************
// Function:    redrawUI
//
// Description: draw the screen
//
// Parameters:  None
//
// Returned:    None
//***************************************************************************
void TicTacToeView_TextUI::redrawUI ()
{
  drawScreen ();
}

//***************************************************************************
// Function:    onSetPlayer1Name
//
// Description: UI Event handler: call presenter
//
// Parameters:  string - the data from the UI Widget
//
// Returned:    None
//***************************************************************************
void TicTacToeView_TextUI::onSetPlayer1Name (std::string name)
{
  mpcTTTPresenter->setName1 (name);
}

//***************************************************************************
// Function:    onSetPlayer2Name
//
// Description: UI Event handler: call presenter
//
// Parameters:  string - the data from the UI Widget
//
// Returned:    None
//***************************************************************************
void TicTacToeView_TextUI::onSetPlayer2Name (std::string name)
{
  mpcTTTPresenter->setName2 (name);
}

//***************************************************************************
// Function:    onMakeMove
//
// Description: UI Event handler: call presenter
//              parse two ints from the string to pass to the presenter
//
// Parameters:  string - the data from the UI Widget
//
// Returned:    None
//***************************************************************************
void TicTacToeView_TextUI::onMakeMove (std::string move)
{
  int x, y;
  std::istringstream cStringStream (move);
  if (cStringStream >> x)
  {
    if (cStringStream >> y)
    {
      mpcTTTPresenter->setMove (x, y);
    }
  }
}

//***************************************************************************
// Function:    onQuit
//
// Description: UI Event handler: call presenter
//
// Parameters:  string - no real data, just necessary to match function sig
//
// Returned:    None
//***************************************************************************
void TicTacToeView_TextUI::onQuit (std::string msg)
{
}

//***************************************************************************
// Function:    onSetPlayer1Symbol
//
// Description: UI Event handler: call presenter
//
// Parameters:  string - the data from the UI Widget
//
// Returned:    None
//***************************************************************************
void TicTacToeView_TextUI::onSetPlayer1Symbol (std::string name)
{
  mpcTTTPresenter->setSymbol1 (name);
}

//***************************************************************************
// Function:    onSetPlayer2Symbol
//
// Description: UI Event handler: call presenter
//
// Parameters:  string - the data from the UI Widget
//
// Returned:    None
//***************************************************************************
void TicTacToeView_TextUI::onSetPlayer2Symbol (std::string name)
{
  mpcTTTPresenter->setSymbol2 (name);
}
