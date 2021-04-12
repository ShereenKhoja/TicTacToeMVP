//***************************************************************************
// File name:  SDLTextBoardView.h
// Author:     Chadd Williams
// Date:       3/22/2017
// Class:      CS485
// Assignment: Model View Presenter Example
// Purpose:    Demonstrate how the Model View Presenter is used
//***************************************************************************
#pragma once

#include "SDLTextWidget.h"

class SDLTextBoardView
{
public:
  SDLTextBoardView ();
  ~SDLTextBoardView ();
  void clear ();
  void setMove (int x, int y, const std::string &rcSymbol);
  void draw (SDLApp &rcApp) const;
  bool clicked (int x, int y, int &rcRow, int &rcCol) const;
private:
  SDLTextWidget* macBoard[3][3];
};
