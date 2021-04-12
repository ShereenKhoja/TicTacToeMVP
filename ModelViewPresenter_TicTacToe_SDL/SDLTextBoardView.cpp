//****************************************************************************
// File name:	SDLTextBoardView.cpp
// Author:		Chadd Williams
// Date:		  3/28/2017
// Class:		  CS 485
// Assignment:ModelViewPresenter TicTacToe SDL
// Purpose:		Demonstrate MVP
//****************************************************************************
#include "SDLTextBoardView.h"

//***************************************************************************
// Constructor: SDLTextBoardView
//
// Description: Build widgets for board and place on screen
//
// Parameters:  None
//
// Returned:    None
//***************************************************************************
SDLTextBoardView::SDLTextBoardView ()
{
  for (int i = 0; i < 3; i++)
  {
    for (int k = 0; k < 3; k++)
    {
      macBoard[i][k] = new SDLTextWidget ("", "#", 100 + i*20, 100 + k*20, 1,
      { 255,255,255,255 });
    }
  }
}

//***************************************************************************
// Destructor:  ~SDLTextBoardView
//
// Description: delete widgets
//
// Parameters:  None
//
// Returned:    None
//***************************************************************************
SDLTextBoardView::~SDLTextBoardView ()
{
  for (int i = 0; i < 3; i++)
  {
    for (int k = 0; k < 3; k++)
    {
      delete macBoard[i][k];
    }
  }
}

//***************************************************************************
// Function:    clear
//
// Description: clear the board
//
// Parameters:  None
//
// Returned:    None
//***************************************************************************
void SDLTextBoardView::clear ()
{
  for (int i = 0; i < 3; i++)
  {
    for (int k = 0; k < 3; k++)
    {
      macBoard[i][k]->setData ("");
    }
  }
}

//***************************************************************************
// Function:    setMove
//
// Description: set a move on the board
//
// Parameters:  x - x coordinate
//              y - y coordinate
//              symbol - symbol to use
//
// Returned:    None
//***************************************************************************
void SDLTextBoardView::setMove (int x, int y, const std::string &rcSymbol)
{
  macBoard[x][y]->setData (rcSymbol);
}

//***************************************************************************
// Function:    clicked
//
// Description: Determine if and where the board was clicked
//
// Parameters:  x - x coordinate
//              y - y coordinate
//              rcRow - row clicked
//              rcCol - column clicked
//
// Returned:    None
//***************************************************************************
bool SDLTextBoardView::clicked (int x, int y, int &rcRow, int &rcCol) const
{
  bool bRetVal = false;
  for (int i = 0; i < 3; i++) 
  {
    for (int k = 0; k < 3; k++) 
    {
      if (macBoard[i][k]->clicked (x, y))
      {
        rcRow = k;
        rcCol = i;
        bRetVal = true;
      }
    }
  }

  return bRetVal;
}

//***************************************************************************
// Function:    draw
//
// Description: draw board to the screen
//
// Parameters:  rcApp - the SDLApp to use
//
// Returned:    None
//***************************************************************************
void SDLTextBoardView::draw (SDLApp & rcApp) const
{
  for (int i = 0; i < 3; i++)
  {
    for (int k = 0; k < 3; k++)
    {
      macBoard[i][k]->draw(rcApp);
    }
  }
}
