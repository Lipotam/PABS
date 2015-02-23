// 
// 
// 

#include "Constants.h"

void ConstantsClass::init()
{
	adminStartButton = 0;
	adminResetButton = 1;
	adminInterrupt = 2;
	playerInerrupt = 3;
	firstPlayerButton = 4;
	secondPlayerButton = 5;
	thirdPlayerButton = 6;
	fourthPlayerButton = 7;
	fifthPlayerButton = 8;
	speakerPin = 9;
	ledShiftRegisterClk = 10;
	ledShiftRegisterData = 11;
	ledShiftRegisterRefresh = 12;
	ledPin = 13;
	displayShiftRegisterClk = 14;
	displayShiftRegisterData = 15;
	displayShiftRegisterRefresh = 16;
	gameStateHighBit = 17;
	gameStateLowBit = 18;

	player1 = 0;
	player2 = 1;
	player3 = 2;
	player4 = 3;
	player5 = 4;

	adminSet = 0;
	adminReset = 1;
	
	digit[0] =  0b00001000;
	digit[1] =  0b00111110;
	digit[2] =  0b00010001;
	digit[3] =  0b00010100;
	digit[4] =  0b00100110;
	digit[5] =  0b01000100;
	digit[6] =  0b01000000;
	digit[7] =  0b00011110;
	digit[8] =  0b00000000;
	digit[9] =  0b00000100;
	digit[10] = 0b01111111;

	led[0] = 0b01000000;
	led[1] = 0b00100000;
	led[2] = 0b00010000;
	led[3] = 0b00001000;
	led[4] = 0b00000100;
	led[5] = 0b00000000;

    analogSeparator = 500;
}


ConstantsClass Constants;

