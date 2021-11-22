// 
// 
// 

#include "Constants.h"

ConstantsClass::ConstantsClass()
{
	adminStartButton = 3;
	adminResetButton = 2;

	parallelInInterruptPin = 13;
	parallelOutInterruptPin = A0;

	firstPlayerButton = 11;
	secondPlayerButton = 10;
	thirdPlayerButton = 9;
	fourthPlayerButton = 8;
	fifthPlayerButton = 7;

	speakerPin = 12;

	ledShiftRegisterClk = A4;
	ledShiftRegisterData = A2;
	ledShiftRegisterRefresh = A3;
	
	displayShiftRegisterClk = 4;
	displayShiftRegisterData = 5;
	displayShiftRegisterRefresh = 6;

	player1 = 0;
	player2 = 1;
	player3 = 2;
	player4 = 3;
	player5 = 4;

	signalPeriod = 600;
	timeIsEndingPeriod = 300;
	playerSignalPeriodFrequency = 3800;
	brainFaultStartFrequency = 3650;
	adminSignalPeriodFrequency = 3950;
	wwwTenSecondsLeftFrequency = 3500;
	wwwPeriodExpiredFrequency = 3800;

	timeIsEndingFrequency = 500;

	adminSet = 0;
	adminReset = 1;

	led[5] = 0b11100000;
	led[0] = 0b10100001;
	led[1] = 0b11000010;
	led[2] = 0b10100100;
	led[3] = 0b11001000;
	led[4] = 0b11110000;

	digit[0] = 0b00000011;
	digit[1] = 0b10011111;
	digit[2] = 0b00100101;
	digit[3] = 0b00001101;
	digit[4] = 0b10011001;
	digit[5] = 0b01001001;
	digit[6] = 0b01000001;
	digit[7] = 0b00011111;
	digit[8] = 0b00000001;
	digit[9] = 0b00001001;
	digit[10] = 0b11111111; // empty
	digit[11] = 0b01110001; // F without a dot

	ownGameMainTimer= 30;
	ownGameSecondaryTimer = 10;

	brainRingMainTimer = 30;
	brainRingSecondaryTimer = 10;
}

ConstantsClass::~ConstantsClass()
{
}
ConstantsClass Constants;

