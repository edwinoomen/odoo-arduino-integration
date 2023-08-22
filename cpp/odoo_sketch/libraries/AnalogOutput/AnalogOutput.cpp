/*
  AnalogOutput.cpp - Analog Output implementation.
  Created by E. Oomen, January 7, 2014.
*/
#include <assert.h>
#include <Arduino.h>
#include <AnalogOutput.h>

AnalogOutput::AnalogOutput(int pin) : Output (pin)
{
  /* Only these pins are analog outputs */
  if (pin == 3 || pin ==5 || pin == 6 || pin == 9 || pin ==10 || pin == 11)
  {
    //pass
  }
  else
  {
    assert(false);
  }

  /* Set pin low */
  write(LOW);
}

/* Write Analog value */
void AnalogOutput::write(int value)
{
    assert(0 <= value <= 255);
    _value = value;

    /* 0 value -> LOW, anything else -> HIGH */
    analogWrite(_pin, _value);
}

/* Set pin HIGH */
void AnalogOutput::setHigh()
{
    write(255);  
}

/* Set pin LOW */
void AnalogOutput::setLow()
{
    write(0); 
}

