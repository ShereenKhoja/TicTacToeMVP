//***************************************************************************
// File name:  driver.cpp
// Author:     Chadd Williams
// Date:       4/20/2017
// Class:      CS485
// Assignment: Observer Example
// Purpose:    Demonstrate how the observer pattern works
//***************************************************************************


// image of what the screen looks like. 
//
// SDLAPP
//
// OBSERVABLE_BUTTON    OBSERVERING_TEXT_WIDGET  
//                      OBSERVERING_TEXT_WIDGET  
//                      OBSERVERING_TEXT_WIDGET


#include "ObserverExample_SDL.h"
//#include <vld.h>

//***************************************************************************
// Function:    main
//
// Description: Build the Display, start the gameloop
//
// Parameters:  argc - number of command line arguments
//              argv - the command line arguments
//
// Returned:    EXIT_SUCCESS
//***************************************************************************
int main (int argc, char **argv)
{
  ObserverExample_SDL cTheDisplay;

  cTheDisplay.createWindow ("Observer",
    100, 100, 640, 640);

  cTheDisplay.setWindowBackgroundColor ({ 0,0,0,255 });

  cTheDisplay.gameLoop ();

  cTheDisplay.cleanup ();
  return EXIT_SUCCESS;

}
