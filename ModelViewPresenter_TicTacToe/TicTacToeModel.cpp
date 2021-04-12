//***************************************************************************
// File name:  TicTacToeModel.cpp
// Author:     Chadd Williams
// Date:       3/22/2017
// Class:      CS485
// Assignment: Model View Presenter Example
// Purpose:    Demonstrate how the Model View Presenter is used
//***************************************************************************
#include "TicTacToeModel.h"

//***************************************************************************
// Constructor: TicTacToeModel
//
// Description: Initializes data members to default values
//
// Parameters:  None
//
// Returned:    None
//***************************************************************************
TicTacToeModel::TicTacToeModel ():mPlayer1(TicTacToeBoard::Player::ONE),
mPlayer2 (TicTacToeBoard::Player::TWO)
{
  mpcCurrTurn = &mPlayer1;
  mPlayer1.setSymbol ("X");
  mPlayer2.setSymbol ("O");
}

//***************************************************************************
// Function:    setPlayer1Name
//
// Description: Set player 1's name
//
// Parameters:  rcStr - the string to set the name to
//
// Returned:    None
//***************************************************************************
void TicTacToeModel::setPlayer1Name (const std::string & rcStr)
{
  mPlayer1.setName (rcStr);
}

//***************************************************************************
// Function:    setPlayer1Symbol
//
// Description: Set player 1's symbol
//
// Parameters:  rcStr - the string to set the symbol to
//
// Returned:    None
//***************************************************************************
void TicTacToeModel::setPlayer1Symbol (const std::string & rcStr)
{
  mPlayer1.setSymbol (rcStr);
}

//***************************************************************************
// Function:    setPlayer2Name
//
// Description: Set player 2's name
//
// Parameters:  rcStr - the string to set the name to
//
// Returned:    None
//***************************************************************************
void TicTacToeModel::setPlayer2Symbol (const std::string & rcStr)
{
  mPlayer2.setSymbol (rcStr);
}

//***************************************************************************
// Function:    setPlayer2Symbol
//
// Description: Set player 2's Symbol
//
// Parameters:  rcStr - the string to set the Symbol to
//
// Returned:    None
//***************************************************************************
void TicTacToeModel::setPlayer2Name (const std::string & rcStr)
{
  mPlayer2.setName (rcStr);
}

//***************************************************************************
// Function:    isBoardFull
//
// Description: Check if the board is full
//
// Parameters:  None
//
// Returned:    True if the board is full, false otherwise.
//***************************************************************************
bool TicTacToeModel::isBoardFull () const
{
  return mBoard.isBoardFull ();
}

//***************************************************************************
// Function:    isWinner
//
// Description: Check if the given player is a winner 
//
// Parameters:  rcPlayer - the player to check for winning
//
// Returned:    True if the player won, false otherwise
//***************************************************************************
bool TicTacToeModel::isWinner (const TicTacToePlayer & rcPlayer) const
{
  return mBoard.isWinner (rcPlayer.getID ());
}

//***************************************************************************
// Function:    makeMove
//
// Description: Make a move if legal, also track the current player correctly
//
// Parameters:  x - x coordinate of move
//              y - y coordinate of move
//              rcSymbol - the symbol to use in the board
//              bWin - set to true if the move is a winner
//
// Returned:    true if the move succeeded, false otherwise
//***************************************************************************
bool TicTacToeModel::makeMove (int x, int y, std::string &rcSymbol,
  bool &rbWin)
{
  bool bRetVal = false;
  rbWin = false;
  rcSymbol = mpcCurrTurn->getSymbol ();
  if (mBoard.makeMove (x, y, mpcCurrTurn->getID ()))
  {
    bRetVal = true;
    rbWin = false;
    if (isWinner ())
    {
      rbWin = true;
    }
    else
    {
    
      if (&mPlayer1 == mpcCurrTurn)
      {
        mpcCurrTurn = &mPlayer2;
      }
      else
      {
        mpcCurrTurn = &mPlayer1;
      }
    }
  }
  return bRetVal;
}


//***************************************************************************
// Function:    getCurrentPlayerName
//
// Description: Get the name of the current player
//
// Parameters:  None
//
// Returned:    The current player's name
//***************************************************************************
std::string TicTacToeModel::getCurrentPlayerName () const
{
 return mpcCurrTurn->getName ();
}

//***************************************************************************
// Function:    isWinner
//
// Description: check to see if the current player has won
//
// Parameters:  None
//
// Returned:    True if the player has won, false otherwise
//***************************************************************************
bool TicTacToeModel::isWinner () const
{
  return isWinner(*mpcCurrTurn);
}

//***************************************************************************
// Function:    resetGame
//
// Description: set the current player back to player 1 and reset the board
//
// Parameters:  None
//
// Returned:    None
//***************************************************************************
void TicTacToeModel::resetGame ()
{
  mpcCurrTurn = &mPlayer1;
  mBoard.reset ();
}

//***************************************************************************
// Function:    flipStartingPlayer
//
// Description: make the current player player2
//
// Parameters:  None
//
// Returned:    None
//***************************************************************************
void TicTacToeModel::flipStartingPlayer ()
{
  mpcCurrTurn = &mPlayer2;
}
