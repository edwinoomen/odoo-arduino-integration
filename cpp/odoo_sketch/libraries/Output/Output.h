/*
  Output.h - Base class for Arduino Outputs.
  Created by E. Oomen, Januari 3, 2015.
*/
#ifndef Output_h
#define Output_h

#include <Arduino.h>

class Output
{
  public:
    Output(int pin);

    /* Abstract Write value */ 
    virtual void write(int value) = 0;

  protected:
    /* Pin ID */
    int _pin;

    /* Last set value */
    int _value = 0;
};

#endif

