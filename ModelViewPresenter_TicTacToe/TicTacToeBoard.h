//***************************************************************************
// File name:  TicTacToeBoard.h
// Author:     Chadd Williams
// Date:       3/22/2017
// Class:      CS485
// Assignment: Model View Presenter Example
// Purpose:    Demonstrate how the Model View Presenter is used
//***************************************************************************
#pragma once

class TicTacToeBoard
{
public:
  enum class Player { ONE, TWO, EMPTY };

  TicTacToeBoard ();

  bool makeMove (int x, int y, Player ePlayer);
  bool isBoardFull () const;
  bool isWinner (Player ePlayer) const;
  void reset ();

private:

  static const int BOARD_SIZE = 3;
  Player maeBoard[BOARD_SIZE][BOARD_SIZE];

  bool checkRowWinner (int row, Player ePlayer) const;
  bool checkColumnWinner (int col, Player ePlayer) const;
};
