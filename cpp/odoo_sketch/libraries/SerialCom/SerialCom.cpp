/*
  SerialCom.cpp - SerialCom implementation.
  Created by E. Oomen, August 22, 2023.
*/

/* system includes */
#include <limits.h>

#include <assert.h>
#include <Arduino.h>
#include <SerialCom.h>

SerialCom::SerialCom() {    
}

void SerialCom::init(int baud_rate) {    
    Serial.begin(baud_rate);   
}

void SerialCom::startMessage(){
    _iterations = (_iterations == INT_MAX) ? 0 : _iterations + 1;

    send(INT_MAX);     // use int max value to indicate the start of a message
    send(_iterations); // Message sequence number
}


void SerialCom::endMessage(){
    send(INT_MIN);
}

void SerialCom::send(int value){
    // send the two bytes that comprise an integer (Big Endian).
    Serial.write(highByte(value));  // send the high byte
    Serial.write(lowByte(value));   // send the low byte
}

