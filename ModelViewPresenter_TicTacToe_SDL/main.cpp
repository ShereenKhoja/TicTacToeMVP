//****************************************************************************
// File name:	main.cpp
// Author:		Chadd Williams
// Date:		  3/28/2017
// Class:		  CS 485
// Assignment:ModelViewPresenter TicTacToe SDL
// Purpose:		Demonstrate MVP
//****************************************************************************

#include <iostream>
#include <fstream>
#include "TicTacToeView_SDL.h"
#include "vld.h"

using namespace std;

//***************************************************************************
// Function:    main
//
// Description: Main driver. Assemble the SDL display and launch
//
// Parameters:  argc -  number of command line arguments
//              argv - the command line arguments
//
// Returned:    EXIT_SUCCESS
//***************************************************************************

int main(int argc, char *argv[])
{
  TicTacToeView_SDL cTheDisplay;
  
  cTheDisplay.createWindow ("MVP TicTacToe",
    100, 100, 640, 640);

  cTheDisplay.setWindowBackgroundColor ({ 0,0,0,255 });

  cTheDisplay.gameLoop();

  cTheDisplay.cleanup ();
  return EXIT_SUCCESS;
}