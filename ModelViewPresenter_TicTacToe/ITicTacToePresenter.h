//***************************************************************************
// File name:  ITicTacToePresenter.h
// Author:     Chadd Williams
// Date:       3/22/2017
// Class:      CS485
// Assignment: Model View Presenter Example
// Purpose:    Demonstrate how the Model View Presenter is used
//***************************************************************************
#pragma once
#include "ITicTacToeView.h"

class ITicTacToePresenter
{
public:

  virtual ~ITicTacToePresenter () = default;

  // from View
  virtual void setMove (int x, int y) = 0;
  virtual void setName1 (std::string name) =0;
  virtual void setName2 (std::string name) =0 ;

  virtual void setSymbol1 (std::string)=0;
  virtual void setSymbol2 (std::string)=0;

  virtual void resetGame () = 0;

};
