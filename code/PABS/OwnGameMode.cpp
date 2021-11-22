// 
// 
// 

#include "OwnGameMode.h"
#include "SystemMethods.h"
#include "Constants.h"

OwnGameMode::OwnGameMode()
{
	ResetState();
}
OwnGameMode::~OwnGameMode() {}

void OwnGameMode::SetPlayerClick(int playerNumber)
{
	noParallelInterrupt = false;
	SystemMethodsObject.RaiseParallelInterrupt();
	state[playerNumber] = 1;
	SystemMethodsObject.SetUserLed(playerNumber);
	SystemMethodsObject.SetDisplayNumber(playerNumber + 1);
	status = 1;
	SystemMethodsObject.PlaySound(Constants.playerSignalPeriodFrequency, Constants.signalPeriod);
}

bool OwnGameMode::CheckAndSetPlayerClick(int playerNumber, int playerPin)
{
	if (state[playerNumber] == 0 && digitalRead(playerPin) == HIGH)
	{
		SetPlayerClick(playerNumber);
		return true;
	}
	else
	{
		return false;
	}
}

void OwnGameMode::PlayerButtonPush(int playerNumber)
{
	if (status == 0)
	{
		if (state[playerNumber] == 0)
		{
			SetPlayerClick(playerNumber);
		}
		else
		{
			if (CheckAndSetPlayerClick(Constants.player1, Constants.firstPlayerButton)) return;
			if (CheckAndSetPlayerClick(Constants.player2, Constants.secondPlayerButton)) return;
			if (CheckAndSetPlayerClick(Constants.player3, Constants.thirdPlayerButton)) return;
			if (CheckAndSetPlayerClick(Constants.player4, Constants.fourthPlayerButton)) return;
			if (CheckAndSetPlayerClick(Constants.player5, Constants.fifthPlayerButton)) return;
		}
	}
}

void OwnGameMode::AdminButtonPush(int buttonNumber)
{
	if (buttonNumber == Constants.adminReset)
	{
		ResetState();
	}
	else
	{
		if (buttonNumber == Constants.adminSet)
		{
			status = 0;
			SystemMethodsObject.PlaySound(Constants.adminSignalPeriodFrequency, Constants.signalPeriod);
			SystemMethodsObject.SetUserLed(-1);
			SystemMethodsObject.ClearDisplay();

		}
	}
}

void OwnGameMode::ParallelInterruptPush()
{
	if (!noParallelInterrupt)
	{
		status = 1;
		SystemMethodsObject.SetDashesDisplay();
	}
}



void OwnGameMode::TimerPush() {};


void OwnGameMode::ResetState()
{
	SystemMethodsObject.ClearDisplay();
	SystemMethodsObject.LowerParallelInterrupt();
	SystemMethodsObject.SetUserLed(-1);
	noParallelInterrupt = false;
	status = 0;
	state[0] = 0;
	state[1] = 0;
	state[2] = 0;
	state[3] = 0;
	state[4] = 0;
}