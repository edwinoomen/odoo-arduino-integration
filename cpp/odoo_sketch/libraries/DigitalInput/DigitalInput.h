/*
  DigitalInput.h - Common functions for Digital Inputs.
  Created by E. Oomen, Januari 3, 2015.
*/
#ifndef DigitalInput_h
#define DigitalInput_h

#include <Input.h>

class DigitalInput : protected Input
{
  public:
    DigitalInput(int pin);
    
    /* Implement Input interface */
    int read();

    /* Read debounced (stable) pin value */
    int readDebounced();

    /* read Pulse width on pin in microseconds */
    unsigned long readPulse();

    /* Enable/Disable internal pull up resisitor on this pin */
    void pullUp();
    void pullDown();

  protected:
    bool _pullUp;    
};

#endif
