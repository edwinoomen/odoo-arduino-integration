/*
  AnalogOutput.h - Common functions for Analog Outputs.
  Created by E. Oomen, Januari 7, 2015.
*/
#ifndef AnalogOutput_h
#define AnalogOutput_h

#include <Output.h>

class AnalogOutput : protected Output
{
  public:
    AnalogOutput(int pin);
    
    /* Implement Output interface */
    void write(int value);

    /* Set pin High / Low */
    void setHigh();
    void setLow();


  protected:   
};

#endif
