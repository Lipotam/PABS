// 
// 
// 

#include "WwwMode.h"
#include "SystemMethods.h"
#include "Constants.h"

WwwMode::WwwMode()
{
	state = 0;
	timeLeft = 0;
}
WwwMode::~WwwMode(){}

void WwwMode::PlayerButtonPush(int playerNumber)
{
	if (state == 1)
	{
		SystemMethodsObject.SetDisplayNumber(timeLeft);
		timeLeft --;
	}

	if (timeLeft == 10)
	{
		SystemMethodsObject.PlaySound(Constants.wwwTenSecondsLeftFrequency, Constants.signalPeriod);
	}

	if (timeLeft == 0)
	{
		SystemMethodsObject.PlaySound(Constants.wwwPeriodExpiredFrequency, Constants.signalPeriod);
		state = 0;
	}
}

void WwwMode::AdminButtonPush(int buttonNumber)
{
	if (buttonNumber == Constants.adminReset)
	{
		state = 0;
		timeLeft = 0;
	}
	else
	{
		if(buttonNumber == Constants.adminSet)
		{
			state = 1;
			timeLeft = 60;
			SystemMethodsObject.PlaySound(Constants.adminSignalPeriodFrequency, Constants.signalPeriod);
		}
	}
}