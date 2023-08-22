/*
  Switch.cpp - Switch implementation.
  Created by E. Oomen, January 3, 2014.
*/
#include <Switch.h>

Switch::Switch(int pin) :
    _pin(pin)
{
  /* Configure Digital Input */
  _pin.pullUp();
}

/* Check if switch is closed, debounced*/
bool Switch::isClosed()
{
   bool closed = (_pin.readDebounced() == LOW);  /* using pullups */
   return closed;
}


