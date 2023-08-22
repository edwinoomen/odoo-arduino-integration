/*
  RGBLED.h - Implement RGB LED.
  Created by E. Oomen, Februari 13, 2015.
*/
#ifndef RGBLED_h
#define RGBLED_h

#include <AnalogOutput.h>

#define MAX_RGBLED_BRIGHTNESS 255
class RGBLED
{
  public:
    RGBLED(int redpin, int greenpin, int bluepin);
    
    /* Switch LED On and OFF */
    void on();
    void on(int red, int green, int blue);
    void off();
    void rgb(int red, int green, int blue);/* values between 0 and 255 */

  private:
    AnalogOutput  _red_led;
    AnalogOutput  _green_led;
    AnalogOutput  _blue_led;
    int _red;
    int _green;
    int _blue;
};

#endif
