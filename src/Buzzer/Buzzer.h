#ifndef Buzzer_h
#define Buzzer_h

#include "Arduino.h"

class Buzzer
{
  public:
    Buzzer(int trigPin);
    void buzz(int duration);
  private:
    int trigPin;
};

#endif
