//***************************************************************************
// File name:  TicTacToeView_SDL.h
// Author:     Chadd Williams
// Date:       3/22/2017
// Class:      CS485
// Assignment: Model View Presenter Example
// Purpose:    Demonstrate how the Model View Presenter is used
//***************************************************************************

#pragma once

#include "ITicTacToeView.h"
#include "ITicTacToePresenter.h"
#include "SDLApp.h"
#include "SDLTextWidget.h"
#include "SDLTextBoardView.h"
#include "SDLSprite.h"
#include <vector>
#include "SDLSpriteBoardView.h"


class TicTacToeView_SDL : public ITicTacToeView, public SDLApp
{
public:

  TicTacToeView_SDL ();

  virtual ~TicTacToeView_SDL ();

  // events from Presenter
  virtual void setPlayer1Name (std::string name);
  virtual void setPlayer2Name (std::string name);
  virtual void setWinner (std::string name);
  virtual void setMove (int x, int y, std::string symbol);
  virtual void resetUI ();


  // events from UI

  virtual void onSetPlayer1Name (std::string name);
  virtual void onSetPlayer2Name (std::string name);
  virtual void onSetPlayer1Symbol (std::string name);
  virtual void onSetPlayer2Symbol (std::string name);
  virtual void onMakeMove (std::string move);
  virtual void onQuit (std::string msg);

  // events from UI Widgets
  virtual void onSetPlayer1NameWidget (SDLTextWidget *pcWidget);
  virtual void onSetPlayer2NameWidget (SDLTextWidget *pcWidget);
  virtual void onSetPlayer1SymbolWidget (SDLTextWidget *pcWidget);
  virtual void onSetPlayer2SymbolWidget (SDLTextWidget *pcWidget);


  // From SDLApp
  // virtual void update (); // not used
  virtual void handleEvent (SDL_Event event);
  virtual void render ();
  virtual void initGame ();


  // TESTING
  //void spriteClick (SDLSprite *pSprite);

private:
  virtual void redrawUI () {};

  static const int BOARD_SIZE = 3;

  ITicTacToePresenter* mpcTTTPresenter;

  // UI control

  std::vector<ISDLWidget *> mcDrawableWidgets;

  // board
  SDLTextBoardView macBoard;
  SDLSpriteBoardView mcSpriteBoard;

  // player1
  SDLTextWidget mcPlayer1Name;
  SDLTextWidget mcPlayer1Symbol;

  // player2
  SDLTextWidget mcPlayer2Name;
  SDLTextWidget mcPlayer2Symbol;
  // winner
  SDLTextWidget mcWinnerName;

  //SDLSprite mcCard;

};

