//***************************************************************************
// File name:  TicTacToePresenter.h
// Author:     Chadd Williams
// Date:       3/22/2017
// Class:      CS485
// Assignment: Model View Presenter Example
// Purpose:    Demonstrate how the Model View Presenter is used
//             This project was based on some ideas presented here:
//             https://github.com/ericmaxwell2003/ticTacToe
//***************************************************************************
#pragma once
#include "TicTacToeModel.h"
#include "ITicTacToePresenter.h"
#include "ITicTacToePresenter.h"

class TicTacToePresenter : public ITicTacToePresenter
{
public:

  TicTacToePresenter (ITicTacToeView *pcView) ;

  virtual ~TicTacToePresenter () = default;

  // from View
  virtual void setMove (int x, int y);
  virtual void setName1 (std::string name);
  virtual void setName2 (std::string name);

  virtual void setSymbol1 (std::string);
  virtual void setSymbol2 (std::string);

  virtual void resetGame ();

private:
  ITicTacToeView *mpcTTTView;

  TicTacToeModel mcTTTModel;
};