// implementation is copypasted from BrainRing.cpp with timer changes.
// 
// TODO: refactor this

#include "BrainRingWithTimerMode.h"
#include "SystemMethods.h"
#include "Constants.h"

BrainRingWithTimerMode::BrainRingWithTimerMode()
{
	ResetState();
}
BrainRingWithTimerMode::~BrainRingWithTimerMode() {}

void BrainRingWithTimerMode::PlayerButtonPush(int playerNumber)
{
	if (status == 0)
	{
		status = 3;
		state[playerNumber] = 1;
		SystemMethodsObject.SetUserLed(playerNumber);
		SystemMethodsObject.PlaySound(Constants.brainFaultStartFrequency, Constants.signalPeriod);
		SystemMethodsObject.SetDisplayNumber(playerNumber, true);
	}
	else
	{
		if (status == 1)
		{
			if (state[playerNumber] == 0)
			{
				state[playerNumber] = 1;
				SystemMethodsObject.SetUserLed(playerNumber);
				SystemMethodsObject.SetDisplayNumber(playerNumber + 1);
				status = 2;
				SystemMethodsObject.PlaySound(Constants.playerSignalPeriodFrequency, Constants.signalPeriod);
			}
			else
			{
				if (state[Constants.player1] == 0 && digitalRead(Constants.firstPlayerButton) == HIGH)
				{
					state[Constants.player1] = 1;
					SystemMethodsObject.SetUserLed(Constants.player1);
					SystemMethodsObject.SetDisplayNumber(Constants.player1 + 1);
					status = 2;
					SystemMethodsObject.PlaySound(Constants.playerSignalPeriodFrequency, Constants.signalPeriod);
				}
				else
				{
					if (state[Constants.player2] == 0 && digitalRead(Constants.secondPlayerButton) == HIGH)
					{
						state[Constants.player2] = 1;
						SystemMethodsObject.SetUserLed(Constants.player2);
						SystemMethodsObject.SetDisplayNumber(Constants.player2 + 1);
						status = 2;
						SystemMethodsObject.PlaySound(Constants.playerSignalPeriodFrequency, Constants.signalPeriod);
					}
					else
					{
						if (state[Constants.player3] == 0 && digitalRead(Constants.thirdPlayerButton) == HIGH)
						{
							state[Constants.player3] = 1;
							SystemMethodsObject.SetUserLed(Constants.player3);
							SystemMethodsObject.SetDisplayNumber(Constants.player3 + 1);
							status = 2;
							SystemMethodsObject.PlaySound(Constants.playerSignalPeriodFrequency, Constants.signalPeriod);
						}
						else
						{
							if (state[Constants.player4] == 0 && digitalRead(Constants.fourthPlayerButton) == HIGH)
							{
								state[Constants.player4] = 1;
								SystemMethodsObject.SetUserLed(Constants.player4);
								SystemMethodsObject.SetDisplayNumber(Constants.player4 + 1);
								status = 2;
								SystemMethodsObject.PlaySound(Constants.playerSignalPeriodFrequency, Constants.signalPeriod);
							}
						}
					}
				}
			}
		}
	}
}

void BrainRingWithTimerMode::AdminButtonPush(int buttonNumber)
{
	if (buttonNumber == Constants.adminReset)
	{
		ResetState();
		SystemMethodsObject.SetDisplayNumber(-1);
		SystemMethodsObject.SetUserLed(-1);
	}
	else
	{
		if (buttonNumber == Constants.adminSet)
		{
			if (status == 3)
			{
				timer = Constants.brainRingSecondaryTimer;
			}

			status = 1;
			SystemMethodsObject.SetDisplayNumber(-1);
			SystemMethodsObject.PlaySound(Constants.adminSignalPeriodFrequency, Constants.signalPeriod);
			SystemMethodsObject.SetUserLed(-1);
		}
	}
}

void BrainRingWithTimerMode::TimerPush() {
	if (status == 1)
	{
		timer--;
		SystemMethodsObject.SetDisplayNumber(timer);

		if (timer ==0)
		{
			status = 2;
			SystemMethodsObject.PlaySound(Constants.brainFaultStartFrequency, Constants.signalPeriod);
		}
	}
};

void BrainRingWithTimerMode::ResetState()
{
	SystemMethodsObject.SetUserLed(-1);
	status = 0;
	state[0] = 0;
	state[1] = 0;
	state[2] = 0;
	state[3] = 0;
	state[4] = 0;

	timer = Constants.brainRingMainTimer;
}