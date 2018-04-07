// Constants.h

#ifndef _CONSTANTS_h
#define _CONSTANTS_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "Arduino.h"
#else
	#include "WProgram.h"
#endif

class ConstantsClass
{
public:

	int  adminStartButton;
	int adminResetButton;

	int firstPlayerButton;
	int secondPlayerButton;
	int thirdPlayerButton;
	int fourthPlayerButton;
	int fifthPlayerButton;
	
	int speakerPin;

	int ledShiftRegisterClk;
	int ledShiftRegisterData;
	int ledShiftRegisterRefresh;

	int displayShiftRegisterClk;
	int displayShiftRegisterData;
	int displayShiftRegisterRefresh;

	int player1;
	int player2;
	int player3;
	int player4;
	int player5;

	int signalPeriod;
	int playerSignalPeriodFrequency;
	int adminSignalPeriodFrequency;
	int wwwTenSecondsLeftFrequency;
	int wwwPeriodExpiredFrequency;
	int brainFaultStartFrequency;
	int adminSet;
	int adminReset;
	uint8_t led[6];

	int ownGameMainTimer;
	int ownGameSecondaryTimer;

	int brainRingMainTimer;
	int brainRingSecondaryTimer;

	ConstantsClass();
	~ConstantsClass();
};

extern ConstantsClass Constants;

#endif

