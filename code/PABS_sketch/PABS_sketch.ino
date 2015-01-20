#include "constants.h"



void setup() {                
  pinMode(led, OUTPUT);     
  
   pinMode(displayShiftRegisterClk, OUTPUT);
   pinMode(displayShiftRegisterRefresh, OUTPUT);
   pinMode(displayShiftRegisterData, OUTPUT); 
   pinMode(ledShiftRegisterClk, OUTPUT);
   pinMode(ledShiftRegisterData, OUTPUT);
   pinMode(ledShiftRegisterRefresh, OUTPUT);

}

void loop() {
  digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);               // wait for a second
  digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);               // wait for a second
  CheckDigits();
  CheckLeds();
}

void CheckDigits()
{
  for (int i = 0; i < 11; i++)
  {
    digitalWrite(displayShiftRegisterRefresh, LOW);
    shiftOut(displayShiftRegisterData, displayShiftRegisterClk, LSBFIRST, digit[i]);
    digitalWrite(displayShiftRegisterRefresh, HIGH);
    delay(1000);
  }
}

void CheckLeds()
{
  digitalWrite(ledShiftRegisterRefresh, LOW);
  shiftOut(ledShiftRegisterData, ledShiftRegisterClk, LSBFIRST, 0b11111111);
  digitalWrite(ledShiftRegisterRefresh, HIGH);
  delay(1000);
}
