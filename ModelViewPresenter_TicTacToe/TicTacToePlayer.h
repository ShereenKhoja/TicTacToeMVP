//***************************************************************************
// File name:  TicTacToePlayer.h
// Author:     Chadd Williams
// Date:       3/22/2017
// Class:      CS485
// Assignment: Model View Presenter Example
// Purpose:    Demonstrate how the Model View Presenter is used
//             This project was based on some ideas presented here:
//             https://github.com/ericmaxwell2003/ticTacToe
//***************************************************************************
#pragma once
#include <string>
#include "TicTacToeBoard.h"

class TicTacToePlayer
{
public:
  TicTacToePlayer (TicTacToeBoard::Player ePlayerID);
  ~TicTacToePlayer () = default;
  void setName (std::string name);
  void setSymbol (std::string symbol);
  std::string getName () const;
  std::string getSymbol () const;
  TicTacToeBoard::Player getID () const;
private:
  std::string mName;
  std::string mSymbol;
  TicTacToeBoard::Player mePlayerID;
};