//***************************************************************************
// File name:  ObserverExample_SDL.cpp
// Author:     Chadd Williams
// Date:       4/20/2017
// Class:      CS485
// Assignment: Observer Example
// Purpose:    Demonstrate how the observer pattern works
//***************************************************************************

#include "ObserverExample_SDL.h"

//***************************************************************************
// Constructor: ObserverExample_SDL
//
// Description: Build the widgets ont he screen. Load a font
//
// Parameters:  None
//
// Returned:    None
//***************************************************************************
ObserverExample_SDL::ObserverExample_SDL ()
{
  ObservingTextWidget *pcTextWidget;
  mpcObsButton = new ObservableButton (); // (this, "Sprites\\O.png", 10, 10);

  loadFont ("c:/Windows/Fonts/Cour.ttf", 20);

  for (int i = 0; i < 3; i++)
  {
    pcTextWidget = new ObservingTextWidget ("label", "", 300,
      100 * i+50, 1, { 255,0,0,255 });

    mcObsTextWidgets.push_back (pcTextWidget);
    mcObsTextWidgetsObserving.push_back(false);
    pcTextWidget->setData ("Not Observing");

    pcTextWidget->registerClickEventHandler (
      std::bind(&ObserverExample_SDL::toggleObserver, this, i)
    );
    registerClickableWidget (pcTextWidget);
  }

  registerClickableWidget (mpcObsButton);
  

}

//***************************************************************************
// Destructor:  ObserverExample_SDL
//
// Description: Deallocate the widgets and Sprite
//
// Parameters:  None
//
// Returned:    None
//***************************************************************************
ObserverExample_SDL::~ObserverExample_SDL ()
{
  delete mpcObsButton;
  for (ObservingTextWidget* pcWidget : mcObsTextWidgets)
  {
    delete pcWidget;
  }
}

//***************************************************************************
// Function:    initGame
//
// Description: Load the sprite
//
// Parameters:  None
//
// Returned:    None
//***************************************************************************
void ObserverExample_SDL::initGame ()
{
  mpcObsButton->loadSprite (this, "Sprites\\O.png", 10, 10);
}

//***************************************************************************
// Function:    render
//
// Description: Draw all the widgets and sprite
//
// Parameters:  None
//
// Returned:    None
//***************************************************************************
void ObserverExample_SDL::render ()
{
  mpcObsButton->draw (*this);
  for (ObservingTextWidget* pcWidget : mcObsTextWidgets)
  {
    pcWidget->draw (*this);
  }

}

//***************************************************************************
// Function:    toggleObserver
//
// Description: toggle the widget between observing and not.
//
// Parameters:  index - the index of the clicked widget
//
// Returned:    None
//***************************************************************************
void ObserverExample_SDL::toggleObserver (int index)
{
  if (mcObsTextWidgetsObserving[index])
  {
    mpcObsButton->removeObserver (mcObsTextWidgets[index]);
    mcObsTextWidgets[index]->setData ("Not Observing");
  }
  else
  {
    mpcObsButton->addObserver (mcObsTextWidgets[index]);
    mcObsTextWidgets[index]->setData ("Observing");
  }
  mcObsTextWidgetsObserving[index] = !mcObsTextWidgetsObserving[index];
}
