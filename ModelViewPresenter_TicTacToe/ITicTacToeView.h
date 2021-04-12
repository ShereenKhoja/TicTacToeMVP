//***************************************************************************
// File name:  ITicTacToeView.h
// Author:     Chadd Williams
// Date:       3/22/2017
// Class:      CS485
// Assignment: Model View Presenter Example
// Purpose:    Demonstrate how the Model View Presenter is used
//***************************************************************************
#pragma once
#include <string>

class ITicTacToeView
{
public:

  // events from Presenter
  virtual void setPlayer1Name (std::string name) = 0;
  virtual void setPlayer2Name (std::string name) = 0;
  virtual void setWinner (std::string name) = 0;
  virtual void setMove (int x, int y, std::string symbol) = 0;

  virtual void resetUI () = 0;
  virtual void redrawUI () = 0;

  // events from UI
  virtual void onSetPlayer1Name (std::string name) = 0;
  virtual void onSetPlayer2Name (std::string name) = 0;
  virtual void onSetPlayer1Symbol (std::string name) = 0;
  virtual void onSetPlayer2Symbol (std::string name) = 0;
  virtual void onMakeMove (std::string move) = 0;
  virtual void onQuit (std::string msg) = 0;
};