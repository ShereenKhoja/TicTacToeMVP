//***************************************************************************
// File name:  ObservingTextWidget.h
// Author:     Chadd Williams
// Date:       4/20/2017
// Class:      CS485
// Assignment: Observer Example
// Purpose:    Demonstrate how the observer pattern works
//***************************************************************************
#pragma once

#include "SDLTextWidget.h"
#include "IObserver.h"

class ObservingTextWidget : public SDLTextWidget, public IObserver
{
public:

  ObservingTextWidget (std::string label, std::string data, int x, int y,
    int font, Color cColor);

  virtual ~ObservingTextWidget () = default;

  virtual void notify (const std::string &rcData);

private:


};