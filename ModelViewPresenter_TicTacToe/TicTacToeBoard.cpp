//***************************************************************************
// File name:  TicTacToeBoard.cpp
// Author:     Chadd Williams
// Date:       3/22/2017
// Class:      CS485
// Assignment: Model View Presenter Example
// Purpose:    Demonstrate how the Model View Presenter is used
//***************************************************************************

#include "TicTacToeBoard.h"

//***************************************************************************
// Constructor: TicTacToeBoard
//
// Description: Initializes the board to empty
//
// Parameters:  None
//
// Returned:    None
//***************************************************************************
TicTacToeBoard::TicTacToeBoard ()
{
  reset ();
}

//***************************************************************************
// Function:    reset
//
// Description: reset the board to empty
//
// Parameters:  None
//
// Returned:    None
//***************************************************************************
void TicTacToeBoard::reset ()
{
  for (int x = 0; x < BOARD_SIZE; x++)
  {
    for (int y = 0; y < BOARD_SIZE; y++)
    {
      maeBoard[x][y] = Player::EMPTY;
    }
  }
}

//***************************************************************************
// Function:    makeMove
//
// Description: update the board with a move if the move is legal
//
// Parameters:  x - x coordinate
//              y - y coordinate
//              ePlayer - the player making the move
//
// Returned:    true if the move was legal and made, false otherwise
//***************************************************************************
bool TicTacToeBoard::makeMove (int x, int y, Player ePlayer)
{
  bool bSuccessfulMove = false;

  if (Player::EMPTY == maeBoard[x][y])
  {
    bSuccessfulMove = true;
    maeBoard[x][y] = ePlayer;
  }
  return bSuccessfulMove;
}

//***************************************************************************
// Function:    isBoardFull
//
// Description: return true if the board is full, false otherwise
//
// Parameters:  None
//
// Returned:    return true if the board is full, false otherwise
//***************************************************************************
bool TicTacToeBoard::isBoardFull () const
{
  bool bFull = true;
  for (int x = 0; bFull && x < BOARD_SIZE; x++)
  {
    for (int y = 0; bFull && y < BOARD_SIZE; y++)
    {
      if (Player::EMPTY == maeBoard[x][y])
      {
        bFull = false;
      }
    }
  }
  return bFull;
}

//***************************************************************************
// Function:    isWinner
//
// Description: Determine if the given player is a winner
//
// Parameters:  ePlayer - the player to check
//
// Returned:    return true if the player has won, false otherwise
//***************************************************************************
bool TicTacToeBoard::isWinner (Player ePlayer) const
{
  bool bWinner = false;

  for (int x = 0; !bWinner &&  x < BOARD_SIZE; x++)
  {
    bWinner = checkRowWinner (x, ePlayer) ||
      checkColumnWinner(x, ePlayer);
  }

  // diagonals
  if (!bWinner)
  {
    if (ePlayer == maeBoard[0][0])
    {
      bWinner = (ePlayer == maeBoard[1][1]) && (ePlayer == maeBoard[2][2]);
    }
    if (!bWinner && ePlayer == maeBoard[0][2])
    {
      bWinner = (ePlayer == maeBoard[1][1]) && (ePlayer == maeBoard[2][0]);
    }
  }

  return bWinner;
}

//***************************************************************************
// Function:    checkRowWinner
//
// Description: Determine if the given player is a winner in a given row
//
// Parameters:   row - the row to check
//               ePlayer - the player to check
//
// Returned:    return true if the player has won, false otherwise
//***************************************************************************
bool TicTacToeBoard::checkRowWinner (int row, Player ePlayer) const
{
  bool bWinner = true;
  for (int x = 0; bWinner && x < BOARD_SIZE; x++)
  {
    if (ePlayer != maeBoard[row][x])
    {
      bWinner = false;
    }
  }
  return bWinner;
}

//***************************************************************************
// Function:    checkColumnWinner
//
// Description: Determine if the given player is a winner in a given column
//
// Parameters:   col - the column to check
//               ePlayer - the player to check
//
// Returned:    return true if the player has won, false otherwise
//***************************************************************************
bool TicTacToeBoard::checkColumnWinner (int col, Player ePlayer) const
{
  bool bWinner = true;
  for (int x = 0; bWinner && x < BOARD_SIZE; x++)
  {
    if (ePlayer != maeBoard[x][col])
    {
      bWinner = false;
    }
  }
  return bWinner;
}
