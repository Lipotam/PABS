// 
// 
// 

#include "HamsaMode.h"
#include "SystemMethods.h"
#include "Constants.h"

HamsaMode::HamsaMode()
{
	ResetState();
}

HamsaMode::~HamsaMode() {}

void HamsaMode::SetPlayerLights()
{
	ledByte = 0b11100000;

	if(readyPlayers[0] == 1)
	{
		ledByte = ledByte | Constants.led[0];
	}

		if(readyPlayers[1] == 1)
	{
		ledByte = ledByte | Constants.led[1];
	}

		if(readyPlayers[2] == 1)
	{
		ledByte = ledByte | Constants.led[2];
	}

		if(readyPlayers[3] == 1)
	{
		ledByte = ledByte | Constants.led[3];
	}

		if(readyPlayers[4] == 1)
	{
		ledByte = ledByte | Constants.led[4];
	}

	ledByte = ledByte | Constants.led[5];
	SystemMethodsObject.SetUserLedWithByte(ledByte);	

	if(answerIndex == -1 || isUserAnswering == 0)
	{
		SystemMethodsObject.ClearDisplay();
	}
	else
	{
		SystemMethodsObject.SetDisplayNumber(playersQueue[currentAsweringUser] +1);
	}
}

void HamsaMode::PlayerButtonPush(int playerNumber)
{
	if (blocked[playerNumber] == 0)
	{
		if(readyPlayers[playerNumber] == 0)
		{
			readyPlayers[playerNumber] = 1;

            if(currentAsweringUser == -1)
			{
				currentAsweringUser = 0;
				answerIndex = 0;
				playersQueue[answerIndex] = playerNumber;
				isUserAnswering = 1;
			}
			else
			{
				answerIndex++;
				playersQueue[answerIndex] = playerNumber;

				if(isUserAnswering == 0)
				{
					isUserAnswering = 1;
					currentAsweringUser++;
				}
			}

			SetPlayerLights();
			SystemMethodsObject.PlaySound(Constants.playerSignalPeriodFrequency, Constants.signalPeriod);
		}
	}
}

void HamsaMode::AdminButtonPush(int buttonNumber)
{
	if (buttonNumber == Constants.adminReset)
	{
		ResetState();
	}
	else
	{
		if (buttonNumber == Constants.adminSet)
		{
			if(lastAdminSetClickSecond != timer && lastAdminSetClickSecond != timer + 1) //delay for 1.1-1.9 seconds for startbutton
			{
				if(currentAsweringUser > -1)
				{
					readyPlayers[playersQueue[currentAsweringUser]] = 0;
					blocked[playersQueue[currentAsweringUser]] = 1;

					if(currentAsweringUser < answerIndex ) // if we have more answers
					{
						currentAsweringUser++;
						SetPlayerLights();
					}
					else
					{
						isUserAnswering = 0;
						SystemMethodsObject.ClearDisplay();
						SystemMethodsObject.SetUserLed(-1);
					}
				}
				else
				{
					SystemMethodsObject.SetUserLed(-1);
					SystemMethodsObject.ClearDisplay();
				}

				SystemMethodsObject.PlaySound(Constants.adminSignalPeriodFrequency, Constants.signalPeriod);

				lastAdminSetClickSecond = timer;
			}
		}
	}
}

void HamsaMode::ResetState()
{
	SystemMethodsObject.ClearDisplay();
	SystemMethodsObject.LowerParallelInterrupt();
	SystemMethodsObject.SetUserLed(-1);

	answerIndex = -1;
	currentAsweringUser = -1;
	isUserAnswering = 0;

	lastAdminSetClickSecond = 0;
	timer = 1;

	readyPlayers[0] = 0;
	readyPlayers[1] = 0;
	readyPlayers[2] = 0;
	readyPlayers[3] = 0;
	readyPlayers[4] = 0;

	blocked[0] = 0;
	blocked[1] = 0;
	blocked[2] = 0;
	blocked[3] = 0;
	blocked[4] = 0;
}

void HamsaMode::ParallelInterruptPush(){};

void HamsaMode::TimerPush() {
	timer++;
	if(timer > 32500)
	{
		timer = 0;
	}

	if(timer == lastAdminSetClickSecond)
	{
		timer++;
		timer++;
	}
};