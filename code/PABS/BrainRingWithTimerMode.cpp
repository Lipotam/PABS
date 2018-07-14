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
				SetPlayerPush(playerNumber);
			}
			else
			{
				if (CheckAndSetPlayerPush(Constants.player1, Constants.firstPlayerButton)) return;
				if (CheckAndSetPlayerPush(Constants.player2, Constants.secondPlayerButton)) return;
				if (CheckAndSetPlayerPush(Constants.player3, Constants.thirdPlayerButton)) return;
				if (CheckAndSetPlayerPush(Constants.player4, Constants.fourthPlayerButton)) return;
				if (CheckAndSetPlayerPush(Constants.player5, Constants.fifthPlayerButton)) return;
			}
		}
	}
}

void BrainRingWithTimerMode::AdminButtonPush(int buttonNumber)
{
	if (buttonNumber == Constants.adminReset)
	{
		ResetState();
		SystemMethodsObject.ClearDisplay();
	}
	else
	{
		if (buttonNumber == Constants.adminSet)
		{
			if (status == 2 || status == 3)
			{
				timer = Constants.brainRingSecondaryTimer;
			}

			status = 1;
			SystemMethodsObject.ClearDisplay();
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

		if (timer < 5)
		{
			SystemMethodsObject.PlaySound(Constants.timeIsEndingFrequency, Constants.timeIsEndingPeriod);
		}

		if (timer ==0)
		{
			status = 2;
			SystemMethodsObject.PlaySound(Constants.brainFaultStartFrequency, Constants.signalPeriod);
		}
	}
};

void BrainRingWithTimerMode::ResetState()
{
	BrainRingMode::ResetState();
	timer = Constants.brainRingMainTimer;
}