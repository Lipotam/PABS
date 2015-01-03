int adminStartButton = 0;
int adminResetButton = 1;
int adminInterrupt = 2;
int playerInerrupt = 3;
int firstPlayerButton = 4;
int secondPlayerButton = 5;
int thirdPlayerButton = 6;
int fourthPlayerButton = 7;
int fifthPlayerButton = 8;
int speakerButton = 9;
int ledShiftRegisterClk = 10;
int ledShiftRegisterData = 11;
int ledShiftRegisterRefresh = 12;

int led = 13;

int displayShiftRegisterClk = A0;
int displayShiftRegisterData = A1;
int displayShiftRegisterRefresh = A2;
int gameStateHighBit = A3;
int gameStateLowBit = A4;


byte digit[11] = {0b00001000,0b00111110,0b00010001,0b00010100, 0b00100110, 0b01000100, 0b01000000, 0b00011110,0b00000000,0b00000100, 0b01111111};

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
