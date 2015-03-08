// 
// 
// 

#include "Constants.h"

void ConstantsClass::init()
{
	adminStartButton = 19;
	adminResetButton = 13;
	adminInterrupt = 2;
	playerInerrupt = 3;
	firstPlayerButton = 8;
	secondPlayerButton = 7;
	thirdPlayerButton = 4;
	fourthPlayerButton = 6;
	fifthPlayerButton = 5;
	speakerPin = 9;
	ledShiftRegisterClk = 14;
	ledShiftRegisterData = 15;
	ledShiftRegisterRefresh = 16;
	//ledPin = 13;
	displayShiftRegisterClk = 10;
	displayShiftRegisterData = 11;
	displayShiftRegisterRefresh = 12;
	gameStateHighBit = 17;
	gameStateLowBit = 18;

	player1 = 0;
	player2 = 1;
	player3 = 2;
	player4 = 3;
	player5 = 4;

	signalPeriod = 1000;
	playerSignalPeriodFrequency = 1000;
	adminSignalPeriodFrequency = 2000;
	wwwTenSecondsLeftFrequency = 2000;
	wwwPeriodExpiredFrequency = 3000;
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

    analogSeparator = 600;
}

ConstantsClass::ConstantsClass()
{
	init();
}

ConstantsClass::~ConstantsClass()
{
}
ConstantsClass Constants;

