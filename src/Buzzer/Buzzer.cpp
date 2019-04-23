#include "Arduino.h"
#include "Buzzer.h"

Buzzer::Buzzer(int trigPin){
  pinMode(trigPin, OUTPUT);
  Buzzer::trigPin = trigPin;
}

void Buzzer::buzz(int duration){
  digitalWrite(trigPin, HIGH);
  delay(duration);
  digitalWrite(trigPin, LOW);
}
