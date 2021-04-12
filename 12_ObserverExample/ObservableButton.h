//***************************************************************************
// File name:  ObservableButton.h
// Author:     Chadd Williams
// Date:       4/20/2017
// Class:      CS485
// Assignment: Observer Example
// Purpose:    Demonstrate how the observer pattern works
//***************************************************************************
#pragma once

#include "SDLSprite.h"
#include "Observable.h"

class ObservableButton : public SDLSprite, public Observable
{
public:

  ObservableButton ();
  ObservableButton(SDLApp *pcApp, std::string spriteName, int x, int y);

private:

  void onClick ();

};

