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
		status = 1;
		if(state[playerNumber] == 0)
		{
			state[playerNumber] = 1;
			SystemMethodsObject.SetUserLed(playerNumber);
		}
		else
		{
			if (state[Constants.player1] == 0 && digitalRead(Constants.firstPlayerButton) == HIGH)
			{
				state[Constants.player1] = 1;
				SystemMethodsObject.SetUserLed(Constants.player1);
			}
			else
			{
				if (state[Constants.player2] == 0 && digitalRead(Constants.secondPlayerButton) == HIGH)
				{
					state[Constants.player2] = 1;
					SystemMethodsObject.SetUserLed(Constants.player2);
				}
				else
				{
					if (state[Constants.player3] == 0 && digitalRead(Constants.thirdPlayerButton) == HIGH)
					{
						state[Constants.player3] = 1;
						SystemMethodsObject.SetUserLed(Constants.player3);
					}
					else
					{
						if (state[Constants.player4] == 0 && digitalRead(Constants.fourthPlayerButton) == HIGH)
						{
							state[Constants.player4] = 1;
							SystemMethodsObject.SetUserLed(Constants.player4);
						}
						else
						{
							if (state[Constants.player5] == 0 && digitalRead(Constants.fifthPlayerButton) == HIGH)
							{
								state[Constants.player5] = 1;
								SystemMethodsObject.SetUserLed(Constants.player5);
							}
						}
					}
				}
			}
		}
		SystemMethodsObject.PlaySound(1000,800);
	}
}

void BrainRingMode::AdminButtonPush(int buttonNumber)
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