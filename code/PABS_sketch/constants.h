#include "Stdint.h"

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
int displayShiftRegisterClk = 14;
int displayShiftRegisterData = 15;
int displayShiftRegisterRefresh = 16;
int gameStateHighBit = 17;
int gameStateLowBit = 18;

const uint8_t digit[] = {0b00001000,0b00111110,0b00010001,0b00010100, 0b00100110, 0b01000100, 0b01000000, 0b00011110,0b00000000,0b00000100, 0b01111111, 0};

