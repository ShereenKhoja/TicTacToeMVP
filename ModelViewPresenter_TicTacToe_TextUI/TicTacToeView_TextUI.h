//***************************************************************************
// File name:  TicTacToeView_TextUI.h
// Author:     Chadd Williams
// Date:       3/22/2017
// Class:      CS485
// Assignment: Model View Presenter Example
// Purpose:    Demonstrate how the Model View Presenter is used
//***************************************************************************
#pragma once
#include "ITicTacToePresenter.h"
#include <string>
#include <map>
#include <functional>
#include "TextUI.h"
#include "TextUITextWidget.h"
#include "TextBoardView.h"

class TicTacToeView_TextUI : public ITicTacToeView, public TextUI
{
public:
  
  TicTacToeView_TextUI ();

  virtual ~TicTacToeView_TextUI ();

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

private:
  virtual void redrawUI ();

  static const int BOARD_SIZE = 3;
  
  ITicTacToePresenter* mpcTTTPresenter;

  TextBoardView macBoard;

  TextUITextWidget *mpPlayer1Name;
  TextUITextWidget *mpPlayer2Name;
  TextUITextWidget *mpWinnerName;

};