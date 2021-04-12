//****************************************************************************
// File name:	driver.cpp
// Author:		Chadd Williams
// Date:		  3/26/2017
// Class:		  CS 485
// Assignment:ModelViewPresenter TicTacToe TextUI
// Purpose:		Demonstrate MVP
//****************************************************************************
#include <iostream>
#include <chrono>
#include <thread>
#include "vld.h"
#include "TicTacToeView_TextUI.h"

//***************************************************************************
// Function:    main
//
// Description: Launch the TextUI
//
// Parameters:  None
//
// Returned:    EXIT_SUCCESS
//***************************************************************************
int main ()
{
  TicTacToeView_TextUI cView;

  cView.UIEventLoop ();

  return EXIT_SUCCESS;
}
//int main ()
//{
//  TextUI cTheUI (std::cout, std::cin);
//  TextBoardView cTheBoard;
//  TextUITextWidget *pcWidget;
//
//  cTheUI.addWidget (1, 1, new TextUITextWidget ("Label","TextField1"));
//  //cTheUI.addWidget (20, 1, new TextUITextWidget ("Label", "TextField2"));
//
//  //cTheUI.addWidget (3, 4, new TextUITextWidget ("Label", "TextField3"));
//  //cTheUI.addWidget (6, 10, new TextUITextWidget ("", "NOLABELTextField1"));
//
//  for (int x = 0; x < 3; x++)
//  {
//    for (int y = 0; y < 3; y++)
//    {
//      pcWidget = new TextUITextWidget ("", "_");
//      cTheUI.addWidget (x + 10, y + 10, pcWidget);
//      cTheBoard.setWidget (x, y,pcWidget);
//    }
//  }
//
//  cTheUI.drawScreen ();
//
//  std::this_thread::sleep_for (std::chrono::milliseconds (2000));
//
//  cTheBoard.setMove (1, 1, "X");
//  cTheUI.drawScreen ();
//
//  std::this_thread::sleep_for (std::chrono::milliseconds (2000));
//
//  cTheBoard.setMove (0, 2, "X");
//  cTheUI.drawScreen ();
//  std::this_thread::sleep_for (std::chrono::milliseconds (2000));
//
//  return EXIT_SUCCESS;
//}