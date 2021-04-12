//***************************************************************************
// File name:  TicTacToePlayer.cpp
// Author:     Chadd Williams
// Date:       3/22/2017
// Class:      CS485
// Assignment: Model View Presenter Example
// Purpose:    Demonstrate how the Model View Presenter is used
//***************************************************************************
#include "TicTacToePlayer.h"


//***************************************************************************
// Constructor: TicTacToePlayer
//
// Description: Initializes data members to default values
//
// Parameters:  ePlayerID - the player ID for this player
//
// Returned:    None
//***************************************************************************

TicTacToePlayer::TicTacToePlayer (TicTacToeBoard::Player ePlayerID):
  mePlayerID(ePlayerID)
{
}

//***************************************************************************
// Function:    setName
//
// Description: Set the player's name
//
// Parameters:  name - the name to set
//
// Returned:    None
//**************************************************************************
void TicTacToePlayer::setName (std::string name)
{
  mName = name;
}

//***************************************************************************
// Function:    setSymbol
//
// Description: Set the player's symbol
//
// Parameters:  symbol - the symbol to set
//
// Returned:    None
//**************************************************************************
void TicTacToePlayer::setSymbol (std::string symbol)
{
  mSymbol = symbol;
}

//***************************************************************************
// Function:    getName
//
// Description: get the player's name
//
// Parameters:  None
//
// Returned:    The player's name
//**************************************************************************
std::string TicTacToePlayer::getName () const
{
  return mName;
}

//***************************************************************************
// Function:    getSymbol
//
// Description: get the player's symbol
//
// Parameters:  None
//
// Returned:    The player's symbol
//**************************************************************************
std::string TicTacToePlayer::getSymbol () const
{
  return mSymbol;
}

//***************************************************************************
// Function:    getID
//
// Description: get the player's ID
//
// Parameters:  None
//
// Returned:    The player's ID
//**************************************************************************
TicTacToeBoard::Player TicTacToePlayer::getID () const
{
  return mePlayerID;
}