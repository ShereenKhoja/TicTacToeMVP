//***************************************************************************
// File name:  SDLSpriteBoardView.h
// Author:     Chadd Williams
// Date:       3/22/2017
// Class:      CS485
// Assignment: Model View Presenter Example
// Purpose:    Demonstrate how the Model View Presenter is used
//***************************************************************************
#pragma once

#include "SDLSprite.h"

class SDLSpriteBoardView
{
public:

  //need to be able to send in the three icons!

  SDLSpriteBoardView ();

  void setIcons (const std::string &rcEmpty, const std::string &rcPlayer1,
    const std::string &rcPlayer2);

  SDLSpriteBoardView (SDLApp &rcApp, int x, int y);
  ~SDLSpriteBoardView ();

  void load (SDLApp *pcApp, int x, int y);

  void clear ();
  void setMove (int x, int y, const std::string& rcSymbol);
  void setSprite (int x, int y, SDLSprite *pcSprite);
  void draw (SDLApp &rcApp) const;
  bool clicked (int x, int y, int &rcRow, int &rcCol) const;
private:
  SDLSprite* macBoard[3][3];
  SDLApp *mpApp = nullptr;

  std::string mEmpty;
  std::string mPlayer1;
  std::string mPlayer2;
};

