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
OwnGameMode::~OwnGameMode(){}


void OwnGameMode::SetPlayerClick(int playerNumber)
{
	state[playerNumber] = 1;
	SystemMethodsObject.SetUserLed(playerNumber);
	SystemMethodsObject.SetDisplayNumber(playerNumber + 1);
	status = 1;
	SystemMethodsObject.PlaySound(Constants.playerSignalPeriodFrequency, Constants.signalPeriod);
}

void OwnGameMode::PlayerButtonPush(int playerNumber)
{
	if (status == 0)
	{
		if(state[playerNumber] == 0)
		{
			SetPlayerClick(playerNumber);
		}
		else
		{
			if (state[Constants.player1] == 0 && digitalRead(Constants.firstPlayerButton) == HIGH)
			{
				SetPlayerClick(Constants.player1);
			}
			else
			{
				if (state[Constants.player2] == 0 && digitalRead(Constants.secondPlayerButton) == HIGH)
				{
					SetPlayerClick(Constants.player2);
				}
				else
				{
					if (state[Constants.player3] == 0 && digitalRead(Constants.thirdPlayerButton) == HIGH)
					{
						SetPlayerClick(Constants.player3);
					}
					else
					{
						if (state[Constants.player4] == 0 && digitalRead(Constants.fourthPlayerButton) == HIGH)
						{
							SetPlayerClick(Constants.player4);
						}
						else
						{
							if (state[Constants.player5] == 0 && digitalRead(Constants.fifthPlayerButton) == HIGH)
							{
								SetPlayerClick(Constants.player5);
							}
						}
					}
				}
			}
		}
		
	}
}
void OwnGameMode::AdminButtonPush(int buttonNumber)
{
	if (buttonNumber == Constants.adminReset)
	{
		ResetState();
		SystemMethodsObject.SetUserLed(-1);
		SystemMethodsObject.SetDisplayNumber(-1);
	}
	else
	{
		if(buttonNumber == Constants.adminSet)
		{
			status = 0;
			SystemMethodsObject.PlaySound(Constants.adminSignalPeriodFrequency, Constants.signalPeriod);
			SystemMethodsObject.SetUserLed(-1);
			SystemMethodsObject.SetDisplayNumber(-1);
		}
	}
}

void OwnGameMode::ResetState()
{
	SystemMethodsObject.SetUserLed(-1);
	status = 0;
	state[0] = 0;
	state[1] = 0;
	state[2] = 0;
	state[3] = 0;
	state[4] = 0;
}