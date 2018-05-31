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

	speakerPin = 12;

	ledShiftRegisterClk = A4;
	ledShiftRegisterData = A2;
	ledShiftRegisterRefresh = A3;
	
	displayShiftRegisterClk = 6;
	displayShiftRegisterData = 5;
	displayShiftRegisterRefresh = 4;

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

	led[5] = 0b00000000;
	led[0] = 0b00000001;
	led[1] = 0b00000010;
	led[2] = 0b00000100;
	led[3] = 0b00001000;
	led[4] = 0b00010000;

	ownGameMainTimer= 30;
	ownGameSecondaryTimer = 10;

	brainRingMainTimer = 30;
	brainRingSecondaryTimer = 10;
}

ConstantsClass::~ConstantsClass()
{
}
ConstantsClass Constants;

