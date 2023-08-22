/*
  Input.h - Base class for Arduino Inputs.
  Created by E. Oomen, Januari 3, 2015.
*/
#ifndef Input_h
#define Input_h

#include <Arduino.h>

class Input
{
  public:
    Input(int pin);

    /* Abstract Read value */ 
    virtual int read() = 0;

  protected:
    /* Pin ID */
    int _pin;

    /* Last read value */
    int _value = 0;
};

#endif

