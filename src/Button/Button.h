#ifndef Button_h
#define Button_h

#include "Arduino.h"

class Button
{
  public:
    Button(int trigPin, boolean state);
    void pressButton();
    void update();
    boolean state;
  private:
    int trigPin;
    boolean isPressed;
};

#endif
