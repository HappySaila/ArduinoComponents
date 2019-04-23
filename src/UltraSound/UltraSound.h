#ifndef UltraSound_h
#define UltraSound_h

#include "Arduino.h"

class UltraSound
{
  public:
    UltraSound(int trigPin, int echoPin);
    int getDistance();
  private:
    int trigPin;
    int echoPin;
};

#endif
