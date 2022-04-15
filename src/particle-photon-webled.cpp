/******************************************************/
//       THIS IS A GENERATED FILE - DO NOT EDIT       //
/******************************************************/

#include "Particle.h"
#line 1 "/Volumes/Data-01/Projects/Particle/particle-photon-webled/src/particle-photon-webled.ino"
/*
 * Project      : particle-photon-webled
 * Description  : Cloud function for LED on or off
 * Author       : Ian Casper
 * Date         : 15.4.2022
 */

void setup();
void loop();
int webLed(String command);
#line 8 "/Volumes/Data-01/Projects/Particle/particle-photon-webled/src/particle-photon-webled.ino"
int led = D7;

void setup() {
  pinMode(led, OUTPUT);
  digitalWrite(led, LOW);
  Particle.function("webLed", webLed);
}

void loop() {
  
}

int webLed(String command){
  if(command == "on"){
    digitalWrite(led, HIGH);
    return 1;
  }
  else if(command == "off"){
    digitalWrite(led, LOW);
    return 1;
  }
  else{
    return -1;
  }
}