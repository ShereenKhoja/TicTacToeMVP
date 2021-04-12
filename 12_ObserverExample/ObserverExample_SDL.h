//***************************************************************************
// File name:  ObserverExample_SDL.h
// Author:     Chadd Williams
// Date:       4/20/2017
// Class:      CS485
// Assignment: Observer Example
// Purpose:    Demonstrate how the observer pattern works
//***************************************************************************

#pragma once

#include "ObservableButton.h"
#include "ObservingTextWidget.h"
#include <vector>

#include "SDLApp.h"

class ObserverExample_SDL : public SDLApp
{
public:

  ObserverExample_SDL ();
  ~ObserverExample_SDL ();

  // subclasses should implement each of the
  // following methods as necessary to customize
  // their App.
  virtual void initGame ();
  virtual void render ();

private:

  ObservableButton *mpcObsButton;

  std::vector<ObservingTextWidget *> mcObsTextWidgets;

  std::vector<bool> mcObsTextWidgetsObserving;

  void toggleObserver (int index);
};