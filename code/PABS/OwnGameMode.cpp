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

void OwnGameMode::PlayerButtonPush(int playerNumber)
{
	if (status == 0)
	{
		status = 1;
		if(state[playerNumber] == 0)
		{
			state[playerNumber] = 1;
			SystemMethodsObject.SetUserLed(playerNumber);
			SystemMethodsObject.SetDisplayNumber(playerNumber+1);
		}
		else
		{
			if (state[Constants.player1] == 0 && digitalRead(Constants.firstPlayerButton) == HIGH)
			{
				state[Constants.player1] = 1;
				SystemMethodsObject.SetUserLed(Constants.player1);
				SystemMethodsObject.SetDisplayNumber(Constants.player1+1);
			}
			else
			{
				if (state[Constants.player2] == 0 && digitalRead(Constants.secondPlayerButton) == HIGH)
				{
					state[Constants.player2] = 1;
					SystemMethodsObject.SetUserLed(Constants.player2);
					SystemMethodsObject.SetDisplayNumber(Constants.player2+1);
				}
				else
				{
					if (state[Constants.player3] == 0 && digitalRead(Constants.thirdPlayerButton) == HIGH)
					{
						state[Constants.player3] = 1;
						SystemMethodsObject.SetUserLed(Constants.player3);
						SystemMethodsObject.SetDisplayNumber(Constants.player3+1);
					}
					else
					{
						if (state[Constants.player4] == 0 && digitalRead(Constants.fourthPlayerButton) == HIGH)
						{
							state[Constants.player4] = 1;
							SystemMethodsObject.SetUserLed(Constants.player4);
							SystemMethodsObject.SetDisplayNumber(Constants.player4+1);
						}
						else
						{
							if (state[Constants.player5] == 0 && digitalRead(Constants.fifthPlayerButton) == HIGH)
							{
								state[Constants.player5] = 1;
								SystemMethodsObject.SetUserLed(Constants.player5);
								SystemMethodsObject.SetDisplayNumber(Constants.player5+1);
							}
						}
					}
				}
			}
		}
		SystemMethodsObject.PlaySound(1000,800);
	}
}
void OwnGameMode::AdminButtonPush(int buttonNumber)
{
	if (buttonNumber == Constants.adminReset)
	{
		ResetState();
		SystemMethodsObject.PlaySound(1000,800);
	}
	else
	{
		if(buttonNumber == Constants.adminSet)
		{
			status = 0;
			SystemMethodsObject.PlaySound(1000,800);
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