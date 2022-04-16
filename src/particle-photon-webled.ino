/*
 * Project      : particle-photon-webled
 * Description  : Cloud function for LED on or off
 * Author       : Ian Casper
 * Date         : 15.4.2022
 */

int led7 = D7;
int led6 = D6;
String blinkState = "";

void setup() {
  pinMode(led7, OUTPUT);
  pinMode(led6, OUTPUT);
  digitalWrite(led7, LOW);
  digitalWrite(led6, HIGH);
  Particle.function("webLed", webLed);
  Particle.variable("blinkState", blinkState);
}

void loop() {

}

int webLed(String command){
  if(command == "on"){
    blinkState = "off";
    digitalWrite(led7, HIGH);
    digitalWrite(led6, LOW);
    Particle.publish("webLed", "is_on");
    return 1;
  }
  else if(command == "off"){
    blinkState = "off";    
    digitalWrite(led7, LOW);
    digitalWrite(led6, HIGH);
    Particle.publish("webLed", "is_off");
    return 1;
  }
  else if(command == "blink"){
    blinkState = "on";
    Particle.publish("webLed", "is_blinking");
    while(blinkState == "on"){
      digitalWrite(led7, HIGH);
      digitalWrite(led6, LOW);
      delay(64ms);
      digitalWrite(led7, LOW);
      digitalWrite(led6, HIGH);
      delay(1000ms);
    }
    return 1;
  }
  else{
    return -1;
  }
}