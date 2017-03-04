#include <PinChangeInterruptSettings.h>
#include <PinChangeInterruptPins.h>
#include <PinChangeInterruptBoards.h>
#include <PinChangeInterrupt.h>
#include "SystemMethods.h"
#include "TestMode.h"
#include "WwwMode.h"
#include "OwnGameMode.h"
#include "BrainRingMode.h"
#include "GameModeBase.h"
#include "Constants.h"
#include "TimerOne.h"  

GameModeBase* gameMode;
void setup()
{
	Serial.begin(9600);
	pinMode(Constants.adminStartButton, INPUT);
	pinMode(Constants.adminResetButton, INPUT);
	pinMode(Constants.firstPlayerButton, INPUT);
	pinMode(Constants.secondPlayerButton, INPUT);
	pinMode(Constants.thirdPlayerButton, INPUT);
	pinMode(Constants.fourthPlayerButton, INPUT);
	pinMode(Constants.speakerPin, INPUT);
	pinMode(Constants.ledShiftRegisterClk, OUTPUT);
	pinMode(Constants.ledShiftRegisterData, OUTPUT);
	pinMode(Constants.ledShiftRegisterRefresh, OUTPUT);
	pinMode(Constants.displayShiftRegisterClk, OUTPUT);
	pinMode(Constants.displayShiftRegisterData, OUTPUT);
	pinMode(Constants.displayShiftRegisterRefresh, OUTPUT);
	pinMode(Constants.gameStateHighBit, INPUT);
	pinMode(Constants.gameStateLowBit, INPUT);


	SystemMethodsObject.PlaySound(1000, 1000);

	int state = 0;
	while (digitalRead(Constants.adminStartButton) != HIGH)
	{
		SystemMethodsObject.SetDisplayNumber(state);
		if (digitalRead(Constants.adminResetButton) == HIGH)
		{
			state++;
			if (state > 3)
			{
				state = 0;
			}
			delay(200);
		}
	}

	delay(1000);

	if (state == 0)
	{
		SystemMethodsObject.SetDisplayNumber(11);
		gameMode = new TestMode();
		Serial.write("TestMode");
		SetupPlayerInts();
	}
	else
	{
		if (state == 1)
		{
			SystemMethodsObject.SetDisplayNumber(22);
			gameMode = new BrainRingMode();
			Serial.write("BrainMode");
			SetupPlayerInts();
		}
		else
		{
			if (state == 2)
			{
				SystemMethodsObject.SetDisplayNumber(33);
				gameMode = new OwnGameMode();
				Serial.write("OwnGameMode");
				SetupPlayerInts();
			}
			else
			{
				if (state == 3)
				{
					SystemMethodsObject.SetDisplayNumber(44);
					gameMode = new WwwMode();
					Timer1.initialize(1000000);
					Timer1.attachInterrupt(TimerInterrupt);
					Serial.write("WwwMode!");
				}
			}
		}
	}

	SystemMethodsObject.SetUserLed(-1);
	SystemMethodsObject.PlaySound(2000, 1000);
	SetupAdminInts();
}

void loop()
{
}

void SetupAdminInts()
{
	attachPCINT(digitalPinToPCINT(Constants.adminResetButton), AdminResetPush, RISING);
	attachPCINT(digitalPinToPCINT(Constants.adminStartButton), AdminStartPush, RISING);
}

void SetupPlayerInts()
{
	attachPCINT(digitalPinToPCINT(Constants.firstPlayerButton), Player1Push, RISING);
	attachPCINT(digitalPinToPCINT(Constants.secondPlayerButton), Player2Push, RISING);
	attachPCINT(digitalPinToPCINT(Constants.thirdPlayerButton), Player3Push, RISING);
	attachPCINT(digitalPinToPCINT(Constants.fourthPlayerButton), Player4Push, RISING);
}

void AdminStartPush()
{
	noInterrupts();
	gameMode->AdminButtonPush(Constants.adminSet);
	interrupts();
}

void AdminResetPush()
{
	noInterrupts();
	gameMode->AdminButtonPush(Constants.adminReset);
	interrupts();
}

void Player1Push()
{
	noInterrupts();
	gameMode->PlayerButtonPush(Constants.player1);
	interrupts();
}

void Player2Push()
{
	noInterrupts();
	gameMode->PlayerButtonPush(Constants.player1);
	interrupts();
}

void Player3Push()
{
	noInterrupts();
	gameMode->PlayerButtonPush(Constants.player1);
	interrupts();
}

void Player4Push()
{
	noInterrupts();
	gameMode->PlayerButtonPush(Constants.player1);
	interrupts();
}

void TimerInterrupt()
{
	gameMode->TimerPush();
}