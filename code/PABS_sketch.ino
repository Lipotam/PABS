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

void setup() {                
  pinMode(led, OUTPUT);     
}


void loop() {
  digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);               // wait for a second
  digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);               // wait for a second
}
