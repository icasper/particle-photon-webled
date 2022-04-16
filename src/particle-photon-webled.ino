/*
 * Project      : particle-photon-webled
 * Description  : Cloud function for LED on or off
 * Author       : Ian Casper
 * Date         : 15.4.2022
 */

int led = D7;
String blinkState = "";

void setup() {
  pinMode(led, OUTPUT);
  digitalWrite(led, LOW);
  Particle.function("webLed", webLed);
  Particle.variable("blinkState", blinkState);
}

void loop() {

}

int webLed(String command){
  if(command == "on"){
    blinkState = "off";
    digitalWrite(led, HIGH);;
    Particle.publish("webLed", "is_on");
    return 1;
  }
  else if(command == "off"){
    blinkState = "off";    
    digitalWrite(led, LOW);
    Particle.publish("webLed", "is_off");
    return 1;
  }
  else if(command == "blink"){
    blinkState = "on";
    Particle.publish("webLed", "is_blinking");
    while(blinkState == "on"){
      digitalWrite(led, HIGH);
      delay(64ms);
      digitalWrite(led, LOW);
      delay(1000ms);
    }
    return 1;
  }
  else{
    return -1;
  }
}