//***************************************************************************
// File name:  TextBoardView.h
// Author:     Chadd Williams
// Date:       3/22/2017
// Class:      CS485
// Assignment: Model View Presenter Example
// Purpose:    Demonstrate how the Model View Presenter is used
//***************************************************************************
#include "TextBoardView.h"

//***************************************************************************
// Function:    clear
//
// Description: Clear the board
//
// Parameters:  None
//
// Returned:    None
//***************************************************************************
void TextBoardView::clear ()
{
  for (int i = 0; i < 3; i++)
  {
    for (int k = 0; k < 3; k++)
    {
      macBoard[i][k]->setData ("");
    }
  }
}

//***************************************************************************
// Function:    setMove
//
// Description: set a move on the board
//
// Parameters:  x - x coordinate
//              y - y coordinate
//              symbol - symbol to use
//
// Returned:    None
//***************************************************************************

void TextBoardView::setMove (int x, int y, std::string symbol)
{
  macBoard[x][y]->setData (symbol);
}

//***************************************************************************
// Function:    setWidget
//
// Description: set the widget at a given location
//
// Parameters:  x - x coordinate
//              y - y coordinate
//              pcWidget - widget to use
//
// Returned:    None
//***************************************************************************

void TextBoardView::setWidget (int x, int y, TextUITextWidget * pcWidget)
{
  macBoard[x][y] = pcWidget;
}


//***************************************************************************
// Constructor: TextBoardView
//
// Description: Initialze board to nullptrs for widgets
//
// Parameters:  None
//
// Returned:    None
//***************************************************************************

TextBoardView::TextBoardView ()
{
  for (int i = 0; i < 3; i++)
  {
    for (int k = 0; k < 3; k++)
    {
      macBoard[i][k] = nullptr;
    }
  }
}
