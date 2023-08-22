/*
  Switch.h - Implement switch.
  Switch uses internal pullup resistors
  Created by E. Oomen, Januari 3, 2015.
*/
#ifndef Switch_h
#define Switch_h

#include <DigitalInput.h>

class Switch
{
  public:
    Switch(int pin);
    
    /* Determine if switch is closed, debounced */
    bool isClosed();

  private:
    DigitalInput _pin;
};

#endif
