//***************************************************************************
// File name:  TicTacToePresenter.cpp
// Author:     Chadd Williams
// Date:       3/22/2017
// Class:      CS485
// Assignment: Model View Presenter Example
// Purpose:    Demonstrate how the Model View Presenter is used
//***************************************************************************
#include "TicTacToePresenter.h"
#include <algorithm>

//***************************************************************************
// Constructor: TicTacToePresenter
//
// Description: Initialize the view correctly
//
// Parameters:  pcView - pointer to the view
//
// Returned:    None
//***************************************************************************

TicTacToePresenter::TicTacToePresenter (ITicTacToeView *pcView)
  : mpcTTTView (pcView)
{
  
 // initBoard ();
}

//***************************************************************************
// Function:    setMove
//
// Description: Set the move in the model
//
// Parameters:  x - the x coordinate
//              y - the y coordinace
//
// Returned:    None
//***************************************************************************
void TicTacToePresenter::setMove (int x, int y)
{
  std::string symbol;
  bool bRetVal;
  bool bWin=false;

  bRetVal =  mcTTTModel.makeMove (x, y, symbol, bWin);
  
  if (bRetVal)
  {
    mpcTTTView->setMove (x, y, symbol);
  }

  if (bWin)
  {
    mpcTTTView->setWinner (mcTTTModel.getCurrentPlayerName ());
  }
}

//***************************************************************************
// Function:    removeSpaces
//
// Description: Remove spaces from the string
//
// Parameters:  rcStr - the string to remove spaces from
//
// Returned:    None
//***************************************************************************
void removeSpaces (std::string &rcStr)
{
  rcStr.erase (std::remove (rcStr.begin (),
    rcStr.end (), ' '), rcStr.end ());
}

//***************************************************************************
// Function:    setName1
//
// Description: SetName1 in both the model and view
//
// Parameters:  name - the string to pass to the Model and View
//
// Returned:    None
//***************************************************************************
void TicTacToePresenter::setName1 (std::string name)
{
  removeSpaces (name);
  mcTTTModel.setPlayer1Name (name);
  mpcTTTView->setPlayer1Name (name);
}

//***************************************************************************
// Function:    setName2
//
// Description: SetName2 in both the model and view
//
// Parameters:  name - the string to pass to the Model and View
//
// Returned:    None
//***************************************************************************
void TicTacToePresenter::setName2 (std::string name)
{
  removeSpaces (name);
  mcTTTModel.setPlayer2Name (name);
  mpcTTTView->setPlayer2Name (name);
}

//***************************************************************************
// Function:    setSymbol1
//
// Description: setSymbol1 in both the model and view
//
// Parameters:  name - the string to pass to the Model and View
//
// Returned:    None
//***************************************************************************
void TicTacToePresenter::setSymbol1 (std::string sym)
{
  removeSpaces (sym);
  mcTTTModel.setPlayer1Symbol (sym);
}

//***************************************************************************
// Function:    setSymbol2
//
// Description: setSymbol2 in both the model and view
//
// Parameters:  name - the string to pass to the Model and View
//
// Returned:    None
//***************************************************************************
void TicTacToePresenter::setSymbol2 (std::string sym)
{
  removeSpaces (sym);
  mcTTTModel.setPlayer2Symbol (sym);
}

//***************************************************************************
// Function:    resetGame
//
// Description: reset the game in the Model and reset the UI in the View
//
// Parameters:  None
//
// Returned:    None
//***************************************************************************
void TicTacToePresenter::resetGame ()
{
  mcTTTModel.resetGame ();
  mpcTTTView->resetUI ();
}


