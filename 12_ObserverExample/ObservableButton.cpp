//***************************************************************************
// File name:  ObservableButton.cpp
// Author:     Chadd Williams
// Date:       4/20/2017
// Class:      CS485
// Assignment: Observer Example
// Purpose:    Demonstrate how the observer pattern works
//***************************************************************************
#include "ObservableButton.h"

ObservableButton::ObservableButton () : SDLSprite()
{
  registerClickEventHandler (
    std::bind (&ObservableButton::onClick, this)
  );
}

ObservableButton::ObservableButton (SDLApp * pcApp, std::string spriteName, 
  int x, int y) : SDLSprite(pcApp, spriteName, x, y)
{
  registerClickEventHandler (
    std::bind (&ObservableButton::onClick, this)
  );
}

void ObservableButton::onClick ()
{
  notifyAll ("Hello");
}


