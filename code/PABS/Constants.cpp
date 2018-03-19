// 
// 
// 

#include "Constants.h"

ConstantsClass::ConstantsClass()
{
	adminStartButton = 3;
	adminResetButton = 2;

	firstPlayerButton = 11;
	secondPlayerButton = 10;
	thirdPlayerButton = 9;
	fourthPlayerButton = 8;
	fifthPlayerButton = 7;

	speakerPin = 13;

	ledShiftRegisterClk = A2;
	ledShiftRegisterData = A3;
	ledShiftRegisterRefresh = A4;
	
	displayShiftRegisterClk = A6;
	displayShiftRegisterData = A7;
	displayShiftRegisterRefresh = A5;

	player1 = 0;
	player2 = 1;
	player3 = 2;
	player4 = 3;
	player5 = 4;

	signalPeriod = 600;
	playerSignalPeriodFrequency = 1000;
	brainFaultStartFrequency = 900;
	adminSignalPeriodFrequency = 2000;
	wwwTenSecondsLeftFrequency = 2000;
	wwwPeriodExpiredFrequency = 3000;
	adminSet = 0;
	adminReset = 1;
	
	digit[0] =  0b00000011;
	digit[1] =  0b10011111;
	digit[2] =  0b00100101;
	digit[3] =  0b00001101;
	digit[4] =  0b10011001;
	digit[5] =  0b01001001;
	digit[6] =  0b01000001;
	digit[7] =  0b00011111;
	digit[8] =  0b00000001;
	digit[9] =  0b00001001;
	digit[10] = 0b11111111;
	digit[11] = 0b01110001;

	led[0] = 0b00000000;
	led[1] = 0b00000001;
	led[2] = 0b00000010;
	led[3] = 0b00000100;
	led[4] = 0b00001000;
	led[5] = 0b00010000;

	ownGameMainTimer= 30;
	ownGameSecondaryTimer = 10;

	brainRingMainTimer = 30;
	brainRingSecondaryTimer = 10;
}

ConstantsClass::~ConstantsClass()
{
}
ConstantsClass Constants;

