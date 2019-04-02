#include "KlimovichSEBrainRingMode.h"
#include <LedControl.h>
#include <EnableInterrupt.h>
#include "SystemMethods.h"
#include "TestMode.h"
#include "WwwMode.h"
#include "OwnGameMode.h"
#include "BrainRingMode.h"
#include "BrainRingWithTimerMode.h"
#include "GameModeBase.h"
#include "Constants.h"
#include "TimerOne.h"

GameModeBase* gameMode;

void setup()
{
	SystemMethodsObject.SetupSerial();

	pinMode(Constants.adminStartButton, INPUT_PULLUP);
	pinMode(Constants.adminResetButton, INPUT_PULLUP);

	pinMode(Constants.firstPlayerButton, INPUT_PULLUP);
	pinMode(Constants.secondPlayerButton, INPUT_PULLUP);
	pinMode(Constants.thirdPlayerButton, INPUT_PULLUP);
	pinMode(Constants.fourthPlayerButton, INPUT_PULLUP);
	pinMode(Constants.fifthPlayerButton, INPUT_PULLUP);

	pinMode(Constants.speakerPin, OUTPUT);
	pinMode(Constants.ledShiftRegisterClk, OUTPUT);
	pinMode(Constants.ledShiftRegisterData, OUTPUT);
	pinMode(Constants.ledShiftRegisterRefresh, OUTPUT);
	pinMode(Constants.displayShiftRegisterClk, OUTPUT);
	pinMode(Constants.displayShiftRegisterData, OUTPUT);
	pinMode(Constants.displayShiftRegisterRefresh, OUTPUT);

	
	SystemMethodsObject.WriteDebug("Started!");

	SystemMethodsObject.initDisplay();

	SystemMethodsObject.SetUserLed(-1);
	SystemMethodsObject.ClearDisplay();

	int state = 0;

	if (digitalRead(Constants.adminResetButton) != HIGH) 
	{
		// set Brain mode as default
		state = 1;
	}
	else
	{
		SystemMethodsObject.PlaySound(1000, 1000);
		while (digitalRead(Constants.adminStartButton) != HIGH)
		{
			SystemMethodsObject.SetDisplayNumber(state);
			if (digitalRead(Constants.adminResetButton) == HIGH)
			{
				state++;
				if (state > 5)
				{
					state = 0;
				}
				delay(200);
			}
		}
	}

	delay(500);

	switch (state)
	{
		case 0: 
			gameMode = new TestMode();
			SystemMethodsObject.WriteDebug("TestMode");
			SetupPlayerInts();
			break;
		case 1: 
			gameMode = new BrainRingMode();
			SystemMethodsObject.WriteDebug("BrainMode");
			SetupPlayerInts();
			break;
		case 2:
			gameMode = new OwnGameMode();
			SystemMethodsObject.WriteDebug("OwnGameMode");
			SetupPlayerInts();
			break;
		case 3: 
			gameMode = new WwwMode();
			Timer1.initialize(1000000);
			Timer1.attachInterrupt(TimerInterrupt);
			SystemMethodsObject.WriteDebug("WwwMode!");
			break;
		case 4:
			gameMode = new BrainRingWithTimerMode(30);
			Timer1.initialize(1000000);
			Timer1.attachInterrupt(TimerInterrupt);
			SystemMethodsObject.WriteDebug("BrainRingWithTimerMode 30!");
			SetupPlayerInts();
			break;
		case 5:
			gameMode = new BrainRingWithTimerMode(60);
			Timer1.initialize(1000000);
			Timer1.attachInterrupt(TimerInterrupt);
			SystemMethodsObject.WriteDebug("BrainRingWithTimerMode 60!");
			SetupPlayerInts();
			break;
		case 6:
			gameMode = new KlimovichSEBrainRingMode();
			SystemMethodsObject.WriteDebug("Klimovich SE BrainMode");
			SetupPlayerInts();
			break;
		default:
			break;
	}

	SystemMethodsObject.SetUserLed(-1);
	SystemMethodsObject.ClearDisplay();
	SystemMethodsObject.PlaySound(2000, 1000);
	SetupAdminInts();
}

void loop(){}

void SetupAdminInts()
{
	enableInterrupt(Constants.adminResetButton, AdminResetPush, RISING);
	enableInterrupt(Constants.adminStartButton, AdminStartPush, RISING);
}

void SetupPlayerInts()
{
	enableInterrupt(Constants.firstPlayerButton, Player1Push, RISING);
	enableInterrupt(Constants.secondPlayerButton, Player2Push, RISING);
	enableInterrupt(Constants.thirdPlayerButton, Player3Push, RISING);
	enableInterrupt(Constants.fourthPlayerButton, Player4Push, RISING); 
	enableInterrupt(Constants.fifthPlayerButton, Player5Push, RISING);
}

void AdminStartPush()
{
	noInterrupts();
	SystemMethodsObject.WriteDebug("Admin start pressed!");
	gameMode->AdminButtonPush(Constants.adminSet);
	interrupts();
}

void AdminResetPush()
{
	noInterrupts();
	SystemMethodsObject.WriteDebug("Admin reset pressed!");
	gameMode->AdminButtonPush(Constants.adminReset);
	interrupts();
}

void Player1Push()
{
	noInterrupts();
	SystemMethodsObject.WriteDebug("Player 1 pressed!");
	gameMode->PlayerButtonPush(Constants.player1);
	interrupts();
}

void Player2Push()
{
	noInterrupts();
	SystemMethodsObject.WriteDebug("Player 2 pressed!");
	gameMode->PlayerButtonPush(Constants.player2);
	interrupts();
}

void Player3Push()
{
	noInterrupts();
	SystemMethodsObject.WriteDebug("Player 3 pressed!");
	gameMode->PlayerButtonPush(Constants.player3);
	interrupts();
}

void Player4Push()
{
	noInterrupts();
	SystemMethodsObject.WriteDebug("Player 4 pressed!");
	gameMode->PlayerButtonPush(Constants.player4);
	interrupts();
}

void Player5Push()
{
	noInterrupts();
	SystemMethodsObject.WriteDebug("Player 5 pressed!");
	gameMode->PlayerButtonPush(Constants.player5);
	interrupts();
}

void TimerInterrupt()
{
	gameMode->TimerPush();
}