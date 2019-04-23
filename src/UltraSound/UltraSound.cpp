#include "Arduino.h"
#include "UltraSound.h"

UltraSound::UltraSound(int trigPin, int echoPin){
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  UltraSound::trigPin = trigPin;
  UltraSound::echoPin = echoPin;
}

int UltraSound::getDistance(){
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  int duration = pulseIn(echoPin, HIGH);
  int distance = (duration/2) / 29.1;

  return distance > 50 ? 50 : distance;
}
