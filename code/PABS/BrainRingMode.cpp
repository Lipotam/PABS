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
		SystemMethodsObject.PlaySound(Constants.playerSignalPeriodFrequency, Constants.signalPeriod);
		SystemMethodsObject.SetDisplayNumber(playerNumber, true);
	}
	else
	{
		if (status == 1)
		{
			if(state[playerNumber] == 0)
			{
				state[playerNumber] = 1;
				SystemMethodsObject.SetUserLed(playerNumber);
				SystemMethodsObject.SetDisplayNumber(playerNumber+1);
				status = 2;
				SystemMethodsObject.PlaySound(Constants.playerSignalPeriodFrequency, Constants.signalPeriod);
			}
			else
			{
				if (state[Constants.player1] == 0 && digitalRead(Constants.firstPlayerButton) == HIGH)
				{
					state[Constants.player1] = 1;
					SystemMethodsObject.SetUserLed(Constants.player1);
					SystemMethodsObject.SetDisplayNumber(Constants.player1+1);
					status = 2;
					SystemMethodsObject.PlaySound(Constants.playerSignalPeriodFrequency, Constants.signalPeriod);
				}
				else
				{
					if (state[Constants.player2] == 0 && digitalRead(Constants.secondPlayerButton) == HIGH)
					{
						state[Constants.player2] = 1;
						SystemMethodsObject.SetUserLed(Constants.player2);
						SystemMethodsObject.SetDisplayNumber(Constants.player2+1);
						status = 2;
						SystemMethodsObject.PlaySound(Constants.playerSignalPeriodFrequency, Constants.signalPeriod);
					}
					else
					{
						if (state[Constants.player3] == 0 && digitalRead(Constants.thirdPlayerButton) == HIGH)
						{
							state[Constants.player3] = 1;
							SystemMethodsObject.SetUserLed(Constants.player3);
							SystemMethodsObject.SetDisplayNumber(Constants.player3+1);
							status = 2;
							SystemMethodsObject.PlaySound(Constants.playerSignalPeriodFrequency, Constants.signalPeriod);
						}
						else
						{
							if (state[Constants.player4] == 0 && digitalRead(Constants.fourthPlayerButton) == HIGH)
							{
								state[Constants.player4] = 1;
								SystemMethodsObject.SetUserLed(Constants.player4);
								SystemMethodsObject.SetDisplayNumber(Constants.player4+1);
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