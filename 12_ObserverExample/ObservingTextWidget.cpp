//***************************************************************************
// File name:  ObservingTextWidget.cpp
// Author:     Chadd Williams
// Date:       4/20/2017
// Class:      CS485
// Assignment: Observer Example
// Purpose:    Demonstrate how the observer pattern works
//***************************************************************************
#include "ObservingTextWidget.h"


//***************************************************************************
// Constructor: ObservingTextWidget
//
// Description: Set label, data, screen position, font and color
//
// Parameters:  label - the widget's label
//              data - the widget's data
//              x - x coordinate on screen
//              y - y coordinate on screen
//              font - font to use
//              cColor - color to use
//
// Returned:    None
//***************************************************************************
ObservingTextWidget::ObservingTextWidget (std::string label, std::string data, 
  int x, int y, int font, Color cColor) : 
  SDLTextWidget(label, data, x,y,font, cColor)
{
}

//***************************************************************************
// Function:    notify
//
// Description: change the data in the text widget when notify is called
//
// Parameters:  rcData - The data to display
//
// Returned:    None
//***************************************************************************
void ObservingTextWidget::notify (const std::string & rcData)
{
  setData (rcData);
}
