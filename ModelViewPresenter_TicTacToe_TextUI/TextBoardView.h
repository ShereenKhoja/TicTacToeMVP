//***************************************************************************
// File name:  TextBoardView.h
// Author:     Chadd Williams
// Date:       3/22/2017
// Class:      CS485
// Assignment: Model View Presenter Example
// Purpose:    Demonstrate how the Model View Presenter is used
//***************************************************************************
#pragma once

#include "TextUI.h"
#include "TextUITextWidget.h"

class TextBoardView
{
public:
  TextBoardView ();
  ~TextBoardView () = default;
  void clear ();
  void setMove (int x, int y, std::string symbol);
  void setWidget (int x, int y, TextUITextWidget *pcWidget);

private:
  TextUITextWidget* macBoard[3][3];
};
 