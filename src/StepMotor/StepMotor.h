#ifndef StepMotor_h
#define StepMotor_h

#include "Arduino.h"

class StepMotor
{
  public:
    StepMotor(int pin1, int pin2, int pin3, int pin4);
    void rotate(int degrees);
    void reset();
  private:
    void update(int cs);
    int currentSpike;
    int pin1;
    int pin2;
    int pin3;
    int pin4;
};

#endif
