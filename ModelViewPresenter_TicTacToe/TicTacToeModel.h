//***************************************************************************
// File name:  TicTacToeModel.h
// Author:     Chadd Williams
// Date:       3/22/2017
// Class:      CS485
// Assignment: Model View Presenter Example
// Purpose:    Demonstrate how the Model View Presenter is used
//***************************************************************************
#pragma once
#include "TicTacToeBoard.h"
#include "TicTacToePlayer.h"

class TicTacToeModel
{
public:
  TicTacToeModel ();
  ~TicTacToeModel () = default;

  void setPlayer1Name (const std::string &rcStr);
  void setPlayer1Symbol (const std::string &rcStr);

  void setPlayer2Symbol (const std::string &rcStr);
  void setPlayer2Name (const std::string &rcStr);

  bool isBoardFull () const;
  bool isWinner () const;
  bool makeMove (int x, int y, std::string &rcSymbol, bool &rbWin);
  std::string getCurrentPlayerName () const;
  void resetGame ();
  void flipStartingPlayer ();


private:
  TicTacToeBoard mBoard;
  TicTacToePlayer mPlayer1, mPlayer2;
  TicTacToePlayer* mpcCurrTurn;

  bool isWinner (const TicTacToePlayer &rcPlayer) const;

};