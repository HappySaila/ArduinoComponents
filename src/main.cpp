/*
 * created by Rui Santos, https://randomnerdtutorials.com
 *
 * Complete Guide for Ultrasonic Sensor HC-SR04
 *
    Ultrasonic sensor Pins:
        VCC: +5VDC
        Trig : Trigger (INPUT) - Pin11
        Echo: Echo (OUTPUT) - Pin 12
        GND: GND
 */
#include <Arduino.h>
#include <StepMotor/StepMotor.h>
#include <UltraSound/UltraSound.h>
#include <Buzzer/Buzzer.h>
#include <Button/Button.h>

StepMotor stepMotor(2, 3, 4, 5);
UltraSound ultraSound(12, 13);
Buzzer buzzer(6);
Button button(11, false);

int buttonPin = 11;
int credits = 2;
int ledPin = 8

void setup() {
  Serial.begin (9600);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  button.update();
  if (!button.state){
    digitalWrite(ledPin,  LOW);
    return;
  }
  digitalWrite(ledPin,  HIGH);

  if (ultraSound.getDistance() < 20 && credits > 0){
    buzzer.buzz(250);
    stepMotor.rotate(720);
    credits--;
  }
}
