#include "Arduino.h"
#include "StepMotor.h"

StepMotor::StepMotor(int pin1, int pin2, int pin3, int pin4){
  pinMode(pin1, OUTPUT);
  pinMode(pin2, OUTPUT);
  pinMode(pin3, OUTPUT);
  pinMode(pin4, OUTPUT);
  StepMotor::pin1 = pin1;
  StepMotor::pin2 = pin2;
  StepMotor::pin3 = pin3;
  StepMotor::pin4 = pin4;
  currentSpike = 0;
}

void StepMotor::rotate(int degrees){
  int stepsToMove = degrees/0.1757813*2;
  for (size_t i = 0; i < stepsToMove; i++) {
    currentSpike = (currentSpike + 1) % 2048;
    update(currentSpike);
  }
}

void StepMotor::update(int cs){
  cs %= 8;
  digitalWrite(pin1, cs == 0 || cs == 1 || cs == 7);
  digitalWrite(pin2, cs == 1 || cs == 2 || cs == 3);
  digitalWrite(pin3, cs == 3 || cs == 4 || cs == 5);
  digitalWrite(pin4, cs == 5 || cs == 6 || cs == 7);

  delay(1);
}

void StepMotor::reset(){
  int startingSpike = currentSpike;
  for (size_t i = 0; i < 16 - startingSpike; i++) {
    currentSpike++;
    update(currentSpike);
  }
}
