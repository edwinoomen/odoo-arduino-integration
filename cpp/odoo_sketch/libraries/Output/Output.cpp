/*
  Output.cpp - Output implementation.
  Created by E. Oomen, January 3, 2014.
*/

#include <assert.h>
#include <Arduino.h>
#include <Output.h>

Output::Output(int pin)
{
  /* Pin numer has to lie between 0 and 13 */
  assert(0 <= pin <=13);
  _pin      = pin;
  _value    = 0;
  pinMode(_pin, OUTPUT);
}


