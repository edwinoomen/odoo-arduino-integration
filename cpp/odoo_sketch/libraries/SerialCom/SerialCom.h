/*
  SerialCom.h - Base class for Arduino Serial messaging.
  Created by E. Oomen, August 22, 2023.
*/
#ifndef SerialCom_h
#define SerialCom_h

#include <Arduino.h>
#include <string.h>

class SerialCom
{
  public:
    SerialCom();

    /* Initialize */ 
    void init(int);
    
    /* Message sending */
    void startMessage();
    void endMessage();
    void send(int);
    
  protected:
    int _message_id = 0;

};

#endif

