/*
  RGBLED.cpp - RGBLED implementation.
  Created by E. Oomen, Februari 13, 2014.
*/
#include <RGBLED.h>

RGBLED::RGBLED(int redpin, int greenpin, int bluepin):
    _red_led(redpin), _green_led(greenpin), _blue_led(bluepin)
{
   /* Configure outputs */
   _red   = 255;
   _green = 255;
   _blue  = 255;
}

/* Switch on LED */
void RGBLED::on()
{
   _red_led.write(_red);
   _green_led.write(_green);
   _blue_led.write(_blue);
}

/* Switch on RGB LED */
void RGBLED::on(int red, int green, int blue)
{
   rgb(red, green,blue);
   on();
}

/* Switch off LED */
void RGBLED::off()
{
   _red_led.write(0);
   _green_led.write(0);
   _blue_led.write(0);
}

void RGBLED::rgb(int red, int green, int blue)
{
   _red   = red;
   _green = green;
   _blue  = blue;
}

