#include "Arduino.h"
#include "Button.h"

Button::Button(int trigPin, boolean state){
  pinMode(trigPin, INPUT);
  Button::trigPin = trigPin;
  Button::state = state;
  Button::isPressed = false;
}

void Button::pressButton(){
  state = !state;
}

void Button::update(){
  boolean buttonInput = !digitalRead(trigPin);
  if (buttonInput){
    isPressed = true;
  } else if (!buttonInput && isPressed){
    isPressed = false;
    pressButton();
  }
}
