//****************************************************************************
// File name:	TicTacToeView_SDL.cpp
// Author:		Chadd Williams
// Date:		  3/28/2017
// Class:		  CS 485
// Assignment:ModelViewPresenter TicTacToe SDL
// Purpose:		Demonstrate MVP
//****************************************************************************
#include "TicTacToeView_SDL.h"
#include "TicTacToePresenter.h"
#include <sstream>
#include <functional>


//***************************************************************************
// Constructor: TicTacToeView_SDL
//
// Description: Initialize the on-screen widgets, hookup event handlders,
//              load fonts, register widgets with SDLApp
//
// Parameters:  None
//
// Returned:    None
//***************************************************************************
TicTacToeView_SDL::TicTacToeView_SDL () 
  : mcPlayer1Name ("Player1", "Chadd", 10, 10, 1, { 255,255,255,255 }), 
  mcPlayer2Name ("Player2", "Computer", 200, 10, 1, { 255,255,255,255 }), 
  mcWinnerName ("", "", 200, 50, 1, { 255,0,0,255 }),
  mcPlayer1Symbol("", "X", 10, 30, 1, { 255,255,255,255 }),
  mcPlayer2Symbol ("", "O", 200, 30, 1, { 255,255,255,255 })
{
  mpcTTTPresenter = new TicTacToePresenter (this);
  loadFont ("c:/Windows/Fonts/Cour.ttf", 20);
  mpcTTTPresenter->setName1 ("Chadd");
  mpcTTTPresenter->setName2 ("Computer");

  mcPlayer1Name.registerStateChangeEventHandler
    (std::bind 
      (&TicTacToeView_SDL::onSetPlayer1NameWidget, this, &mcPlayer1Name));
  mcPlayer1Symbol.registerStateChangeEventHandler
  (std::bind
  (&TicTacToeView_SDL::onSetPlayer1SymbolWidget, this, &mcPlayer1Symbol));


  mcPlayer2Name.registerStateChangeEventHandler 
    (std::bind 
      (&TicTacToeView_SDL::onSetPlayer2NameWidget, this, &mcPlayer2Name));
  mcPlayer2Symbol.registerStateChangeEventHandler
  (std::bind
  (&TicTacToeView_SDL::onSetPlayer2SymbolWidget, this, &mcPlayer2Symbol));

  enableTextInput ();

  registerTextWidget (&mcPlayer1Name);
  registerTextWidget (&mcPlayer2Name);

  registerTextWidget (&mcPlayer1Symbol);
  registerTextWidget (&mcPlayer2Symbol);

  mcDrawableWidgets.push_back (&mcPlayer1Name);
  mcDrawableWidgets.push_back (&mcPlayer2Name);
  mcDrawableWidgets.push_back (&mcPlayer1Symbol);
  mcDrawableWidgets.push_back (&mcPlayer2Symbol);
  mcDrawableWidgets.push_back (&mcWinnerName);
//  mcDrawableWidgets.push_back (&mcCard);

//  registerClickableWidget (&mcCard);
}

//***************************************************************************
// Destructor:  ~TicTacToeView_SDL
//
// Description: Delete the presenter
//
// Parameters:  None
//
// Returned:    None
//***************************************************************************
TicTacToeView_SDL::~TicTacToeView_SDL ()
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
void TicTacToeView_SDL::setPlayer1Name (std::string name)
{
  mcPlayer1Name.setData (name);
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
void TicTacToeView_SDL::setPlayer2Name (std::string name)
{
  mcPlayer2Name.setData (name);
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
void TicTacToeView_SDL::setWinner (std::string name)
{
  mcWinnerName.setLabel ("WINNER! ");
  mcWinnerName.setData (name);
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
void TicTacToeView_SDL::setMove (int x, int y, std::string symbol)
{
  macBoard.setMove (x, y, symbol);
  if (mcPlayer1Symbol.getData () == symbol)
  {
    mcSpriteBoard.setMove (x, y, "X");
  }
  else
  {
    mcSpriteBoard.setMove (x, y, "O");
  }
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
void TicTacToeView_SDL::resetUI ()
{
  mcPlayer1Name.setData ("");
  mcPlayer2Name.setData ("");
  mcWinnerName.setData ("");
  macBoard.clear ();
  redrawUI ();
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
void TicTacToeView_SDL::onSetPlayer1Name (std::string name)
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
void TicTacToeView_SDL::onSetPlayer2Name (std::string name)
{
  mpcTTTPresenter->setName2 (name);
}

//***************************************************************************
// Function:    onSetPlayer1NameWidget
//
// Description: UI Event handler: call presenter
//
// Parameters:  string - the data from the UI Widget
//
// Returned:    None
//***************************************************************************
void TicTacToeView_SDL::onSetPlayer1NameWidget (SDLTextWidget *pcWidget)
{
  onSetPlayer1Name (pcWidget->getData ());
}

//***************************************************************************
// Function:    onSetPlayer2NameWidget
//
// Description: UI Event handler: call presenter
//
// Parameters:  string - the data from the UI Widget
//
// Returned:    None
//***************************************************************************
void TicTacToeView_SDL::onSetPlayer2NameWidget (SDLTextWidget *pcWidget)
{
  onSetPlayer2Name (pcWidget->getData ());
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
void TicTacToeView_SDL::onMakeMove (std::string move)
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
void TicTacToeView_SDL::onQuit (std::string msg)
{
}

//***************************************************************************
// Function:    onSetPlayer1SymbolWidget
//
// Description: UI Event handler: call presenter
//
// Parameters:  string - the data from the UI Widget
//
// Returned:    None
//***************************************************************************
void TicTacToeView_SDL::onSetPlayer1SymbolWidget (SDLTextWidget *pcWidget)
{
  onSetPlayer1Symbol (pcWidget->getData ());
}

//***************************************************************************
// Function:    onSetPlayer2SymbolWidget
//
// Description: UI Event handler: call presenter
//
// Parameters:  string - the data from the UI Widget
//
// Returned:    None
//***************************************************************************
void TicTacToeView_SDL::onSetPlayer2SymbolWidget (SDLTextWidget *pcWidget)
{
  onSetPlayer2Symbol (pcWidget->getData ());
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
void TicTacToeView_SDL::onSetPlayer1Symbol (std::string name)
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
void TicTacToeView_SDL::onSetPlayer2Symbol (std::string name)
{
  mpcTTTPresenter->setSymbol2 (name);
}

//***************************************************************************
// Function:    initGame
//
// Description: Load icons in to sprite
//
// Parameters:  None
//
// Returned:    None
//***************************************************************************
void TicTacToeView_SDL::initGame ()
{
  
  //mcCard.loadSprite (this, "Sprites\\Card.png", 400, 400);
  
  //mcCard.registerClickEventHandler (
  //  (std::bind
  //  (&TicTacToeView_SDL::spriteClick, this, &mcCard)));
  mcSpriteBoard.setIcons ("Sprites\\Empty.png", "Sprites\\X.png", 
    "Sprites\\O.png");
  mcSpriteBoard.load (this, 200, 200);
}

//***************************************************************************
// Function:    handleEvent
//
// Description: Handle a mouse event. Check if either board was clicked
//
// Parameters:  event - SDL_Event
//
// Returned:    None
//***************************************************************************
void TicTacToeView_SDL::handleEvent (SDL_Event event)
{
  int x, y;
  int row, col;
  std::string tmpString;

  if (event.type == SDL_MOUSEBUTTONDOWN &&
    event.button.button == SDL_BUTTON_LEFT)
  {
    // where is the button click?
    x = event.button.x;
    y = event.button.y;
    if (macBoard.clicked (x, y, row, col))
    {
      mpcTTTPresenter->setMove (col, row);
    }
    else if (mcSpriteBoard.clicked (x, y, row, col))
    {
      mpcTTTPresenter->setMove (col, row);
    }
    /*else if (mcCard.clicked (x, y))
    {
      // just testing
    }*/

  }
}

//***************************************************************************
// Function:    render
//
// Description: draw all the widgets to the screen
//
// Parameters:  None
//
// Returned:    None
//***************************************************************************
void TicTacToeView_SDL::render ()
{
  macBoard.draw (*this);
  mcSpriteBoard.draw (*this);
  //mcCard.draw (*this);
  for (auto value : mcDrawableWidgets)
  {
    if (value->isVisible ())
    {
      value->draw (*this);
    }
  }
}



