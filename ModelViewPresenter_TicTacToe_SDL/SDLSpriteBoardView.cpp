//****************************************************************************
// File name:	SDLSpriteBoardView.cpp
// Author:		Chadd Williams
// Date:		  3/28/2017
// Class:		  CS 485
// Assignment:ModelViewPresenter TicTacToe SDL
// Purpose:		Demonstrate MVP
//****************************************************************************
#include "SDLSpriteBoardView.h"

//***************************************************************************
// Constructor: SDLSpriteBoardView
//
// Description: Initialize board to empty
//
// Parameters:  None
//
// Returned:    None
//***************************************************************************
SDLSpriteBoardView::SDLSpriteBoardView ()
{
  for (int i = 0; i < 3; i++)
  {
    for (int k = 0; k < 3; k++)
    {
      macBoard[i][k] = nullptr;
    }
  }
}

//***************************************************************************
// Function:    loadIcons
//
// Description: set the icons to be used for each player
//
// Parameters:  rcEmpty - the empty square icon
//              rcPlayer1 - player 1's icon
//              rcPlayer2 - player 2's icon
//
// Returned:    None
//***************************************************************************
void SDLSpriteBoardView::setIcons (const std::string &rcEmpty, 
  const std::string &rcPlayer1, const std::string &rcPlayer2)
{
  mEmpty = rcEmpty;
  mPlayer1 = rcPlayer1;
  mPlayer2 = rcPlayer2;
}

//***************************************************************************
// Constructor: SDLSpriteBoardView
//
// Description: Initialize board to empty icons and place the board on the 
//              screen
//
// Parameters:  rcApp - the SDLApp to use
//              x - x coordinate
//              y - y coordinate
//
// Returned:    None
//***************************************************************************
SDLSpriteBoardView::SDLSpriteBoardView (SDLApp &rcApp, int x, int y)
{
  load (&rcApp, x, y);
}

//***************************************************************************
// Destructor: ~SDLSpriteBoardView
//
// Description: Delete all the sprites
//
// Parameters:  None
//
// Returned:    None
//***************************************************************************
SDLSpriteBoardView::~SDLSpriteBoardView ()
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
// Function:    load
//
// Description: Initialize board to empty icons and place the board on the 
//              screen
//
// Parameters:  pcApp - the SDLApp to use
//              x - x coordinate
//              y - y coordinate
//
// Returned:    None
//***************************************************************************
void SDLSpriteBoardView::load (SDLApp * pcApp, int x, int y)
{
  mpApp = pcApp;
  for (int i = 0; i < 3; i++)
  {
    for (int k = 0; k < 3; k++)
    {
      macBoard[i][k] = new SDLSprite (pcApp, mEmpty, x + i * 50, y + k * 50);
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
void SDLSpriteBoardView::clear ()
{
  for (int i = 0; i < 3; i++)
  {
    for (int k = 0; k < 3; k++)
    {
      delete macBoard[i][k];
      macBoard[i][k] = new SDLSprite (mpApp, mEmpty, 200 + i * 50, 
        200 + k * 50);
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
void SDLSpriteBoardView::setMove (int x, int y, const std::string &rcSymbol)
{
  if ("X" == rcSymbol)
  {
    delete macBoard[x][y];
    macBoard[x][y] = new SDLSprite (mpApp, mPlayer1, 
      200 + x * 50, 200 + y * 50);
  }
  else
  {
    delete macBoard[x][y];
    macBoard[x][y] = new SDLSprite (mpApp, mPlayer2,
      200 + x * 50, 200 + y * 50);
  }
}

//***************************************************************************
// Function:    setSprite
//
// Description: set the sprite at the given location after deleting the
//              current sprite
//
// Parameters:  x - x coordinate
//              y - y coordinate
//              pcSprite - sprite to use
//
// Returned:    None
//***************************************************************************
void SDLSpriteBoardView::setSprite (int x, int y, SDLSprite * pcSprite)
{
  delete  macBoard[x][y];
  macBoard[x][y] = pcSprite;
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
bool SDLSpriteBoardView::clicked (int x, int y, int &rcRow, int &rcCol) const
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
void SDLSpriteBoardView::draw (SDLApp & rcApp) const
{
  for (int i = 0; i < 3; i++)
  {
    for (int k = 0; k < 3; k++)
    {
      macBoard[i][k]->draw (rcApp);
    }
  }
}
