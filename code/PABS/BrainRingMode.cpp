// 
// 
// 

#include "BrainRingMode.h"
#include "SystemMethods.h"
#include "Constants.h"

BrainRingMode::BrainRingMode()
{
	ResetState();
}
BrainRingMode::~BrainRingMode(){}

void BrainRingMode::PlayerButtonPush(int playerNumber)
{
	if (status == 0)
	{
		status= 2;
		state[playerNumber] = 1;
		SystemMethodsObject.SetUserLed(playerNumber);
		SystemMethodsObject.PlaySound(Constants.brainFaultStartFrequency, Constants.signalPeriod);
		SystemMethodsObject.SetDisplayNumber(playerNumber + 1, true);
	}
	else
	{
		if (status == 1)
		{
			if(state[playerNumber] == 0)
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

void BrainRingMode::AdminButtonPush(int buttonNumber)
{
	if (buttonNumber == Constants.adminReset)
	{
		ResetState();
		SystemMethodsObject.SetDisplayNumber(-1);
		SystemMethodsObject.SetUserLed(-1);
	}
	else
	{
		if(buttonNumber == Constants.adminSet)
		{
			status = 1;
			SystemMethodsObject.SetDisplayNumber(-1);
			SystemMethodsObject.PlaySound(Constants.adminSignalPeriodFrequency, Constants.signalPeriod);
			SystemMethodsObject.SetUserLed(-1);
		}
	}
}

void BrainRingMode::TimerPush(){};

void BrainRingMode::ResetState()
{
	SystemMethodsObject.SetUserLed(-1);
	status = 0;
	state[0] = 0;
	state[1] = 0;
	state[2] = 0;
	state[3] = 0;
	state[4] = 0;
}

bool BrainRingMode::CheckAndSetPlayerPush(int playerNumber, int playerPin) {
	if (state[playerNumber] == 0 && digitalRead(playerPin) == HIGH)
	{
		SetPlayerPush(playerNumber);

		return true;
	}
	else 
	{
		return false;
	}
}

void BrainRingMode::SetPlayerPush(int playerNumber) {
	state[playerNumber] = 1;
	SystemMethodsObject.SetUserLed(playerNumber);
	SystemMethodsObject.SetDisplayNumber(playerNumber + 1);
	status = 2;
	SystemMethodsObject.PlaySound(Constants.playerSignalPeriodFrequency, Constants.signalPeriod);
}