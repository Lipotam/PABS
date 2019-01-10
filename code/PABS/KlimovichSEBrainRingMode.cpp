// 
// 
// 

#include "KlimovichSEBrainRingMode.h"
#include "SystemMethods.h"
#include "Constants.h"

KlimovichSEBrainRingMode::KlimovichSEBrainRingMode()
{
	ResetState();
}

KlimovichSEBrainRingMode::~KlimovichSEBrainRingMode() {}

void KlimovichSEBrainRingMode::PlayerButtonPush(int playerNumber)
{
	if (status == 0)
	{
		status = 2;
		state[playerNumber] = 1;

		if(playerNumber == 0)
		{
			SystemMethodsObject.SetUserLedWithByte(0b01000001);
		}
		else
		{
			if (playerNumber == 1)
			{
				SystemMethodsObject.SetUserLedWithByte(0b00100010);
			}
			else
			{
				SystemMethodsObject.SetUserLed(playerNumber);
			}
		}
		
		SystemMethodsObject.PlaySound(Constants.brainFaultStartFrequency, Constants.signalPeriod);
		SystemMethodsObject.SetDisplayNumber(playerNumber + 1, true);
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
				if (playerNumber == 0)
				{
					SystemMethodsObject.SetUserLedWithByte(0b01010001);
					SystemMethodsObject.SetDisplayNumber(playerNumber + 1);
					status = 2;
					SystemMethodsObject.PlaySound(Constants.playerSignalPeriodFrequency, Constants.signalPeriod);
				}
				else
				{
					if (playerNumber == 1)
					{
						SystemMethodsObject.SetUserLedWithByte(0b00110010);
						SystemMethodsObject.SetDisplayNumber(playerNumber + 1);
						status = 2;
						SystemMethodsObject.PlaySound(Constants.playerSignalPeriodFrequency, Constants.signalPeriod);
					}
					else
					{
						SystemMethodsObject.SetUserLed(playerNumber);
					}
				}
				

				if (CheckAndSetPlayerPush(Constants.player3, Constants.thirdPlayerButton)) return;
				if (CheckAndSetPlayerPush(Constants.player4, Constants.fourthPlayerButton)) return;
				if (CheckAndSetPlayerPush(Constants.player5, Constants.fifthPlayerButton)) return;
			}
		}
	}
}

void KlimovichSEBrainRingMode::AdminButtonPush(int buttonNumber)
{
	if (buttonNumber == Constants.adminReset)
	{
		ResetState();
		SystemMethodsObject.ClearDisplay();
		SystemMethodsObject.SetUserLedWithByte(0b00000000);
	}
	else
	{
		if (status != 2 && buttonNumber == Constants.adminSet)
		{
			status = 1;
			SystemMethodsObject.ClearDisplay();
			SystemMethodsObject.SetUserLedWithByte(0b00010000);
			SystemMethodsObject.PlaySound(Constants.adminSignalPeriodFrequency, Constants.signalPeriod);
		}
	}
}

void KlimovichSEBrainRingMode::TimerPush() {};

void KlimovichSEBrainRingMode::ResetState()
{
	SystemMethodsObject.SetUserLedWithByte(0b00000000);
	status = 0;
	state[0] = 0;
	state[1] = 0;
	state[2] = 0;
	state[3] = 0;
	state[4] = 0;
}

bool KlimovichSEBrainRingMode::CheckAndSetPlayerPush(int playerNumber, int playerPin) {
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

void KlimovichSEBrainRingMode::SetPlayerPush(int playerNumber) {
	state[playerNumber] = 1;
	SystemMethodsObject.SetUserLed(playerNumber);
	SystemMethodsObject.SetDisplayNumber(playerNumber + 1);
	status = 2;
	SystemMethodsObject.PlaySound(Constants.playerSignalPeriodFrequency, Constants.signalPeriod);
}