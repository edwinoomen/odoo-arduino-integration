/*
  DigitalInput.cpp - Digital Input implementation.
  Created by E. Oomen, January 3, 2014.
*/
#include <DigitalInput.h>

DigitalInput::DigitalInput(int pin) : Input (pin)
{
  /* Default set input low */
  pullDown();
}

/* Read digital value */
int DigitalInput::read()
{
    int _value = digitalRead(_pin);
    return _value;
}


/* Read length of pulse */
unsigned long DigitalInput::readPulse()
{
    unsigned long _value = pulseIn(_pin, HIGH);
    return _value;
}

/* Read debounced value */
int DigitalInput::readDebounced()
{
   /* Sample input value several times */
   const int debounce_delay = 5;
   int value = 0;
   
   for ( int i = 0; i < debounce_delay ; i ++ )
   {
      /* Wait 1 millisecond */
      delay(1);
      
      /* Read pin value */
      value += read();
    }   
   
   /* Now the value is considered stable */   
   return value;
}

/* Enable internal pull up resistor */
void DigitalInput::pullUp()
{
   _pullUp = true;
    digitalWrite(_pin, HIGH);
}

/* Disable internal pull up resistor */
void DigitalInput::pullDown()
{
   _pullUp = false;
    digitalWrite(_pin, LOW);
}


