#include <Wire.h>
#include "rgb_lcd.h"
rgb_lcd lcd;
#include <Arduino.h>
#include "BasicStepperDriver.h"

#define MOTOR_STEPS 200
#define DIR A0
#define STEP A1
#define knob A2
int val = 0;
#define MICROSTEPS 16
BasicStepperDriver stepper(MOTOR_STEPS, DIR, STEP);

void setup() {

Serial.begin(9600);
lcd.begin(16, 2);
lcd.setCursor(0, 0);
lcd.print ("YARN BALL WINIDIGN");
lcd.setCursor(0, 1);
lcd.print ("MACHINE");
lcd.clear();
}

void loop() {

val = map(analogRead(knob),0,1023,0,100);
stepper.begin(val, MICROSTEPS);
stepper.rotate(360);
lcd.print ("WINDING");

}
