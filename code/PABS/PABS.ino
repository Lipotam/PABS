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
	Serial.begin(9600);

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

	SystemMethodsObject.PlaySound(1000, 1000);
	Serial.write("Started!");

	SystemMethodsObject.initDisplay();

	int state = 0;
	while (digitalRead(Constants.adminStartButton) != HIGH)
	{
		SystemMethodsObject.SetDisplayNumber(state);
		if (digitalRead(Constants.adminResetButton) == HIGH)
		{
			state++;
			if (state > 4)
			{
				state = 0;
			}
			delay(200);
		}
	}

	delay(500);

	switch (state)
	{
		case 0: 
			SystemMethodsObject.SetDisplayNumber(11);
			gameMode = new TestMode();
			Serial.write("TestMode");
			SetupPlayerInts();
			break;
		case 1: 
			SystemMethodsObject.SetDisplayNumber(22);
			gameMode = new BrainRingMode();
			Serial.write("BrainMode");
			SetupPlayerInts();
			break;
		case 2:
			SystemMethodsObject.SetDisplayNumber(33);
			gameMode = new OwnGameMode();
			Serial.write("OwnGameMode");
			SetupPlayerInts();
			break;
		case 3: 
			SystemMethodsObject.SetDisplayNumber(44);
			gameMode = new WwwMode();
			Timer1.initialize(1000000);
			Timer1.attachInterrupt(TimerInterrupt);
			Serial.write("WwwMode!");
			break;
		case 4:
			SystemMethodsObject.SetDisplayNumber(55);
			gameMode = new BrainRingWithTimerMode();
			Timer1.initialize(1000000);
			Timer1.attachInterrupt(TimerInterrupt);
			Serial.write("BrainRingWithTimerMode!");
			break;
		default:
			break;
	}

	SystemMethodsObject.SetUserLed(-1);
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
	Serial.println("Admin start pressed!");
	gameMode->AdminButtonPush(Constants.adminSet);
	interrupts();
}

void AdminResetPush()
{
	noInterrupts();
	Serial.println("Admin reset pressed!");
	gameMode->AdminButtonPush(Constants.adminReset);
	interrupts();
}

void Player1Push()
{
	noInterrupts();
	Serial.write("Player 1 pressed!");
	gameMode->PlayerButtonPush(Constants.player1);
	interrupts();
}

void Player2Push()
{
	noInterrupts();
	Serial.write("Player 2 pressed!");
	gameMode->PlayerButtonPush(Constants.player2);
	interrupts();
}

void Player3Push()
{
	noInterrupts();
	Serial.write("Player 3 pressed!");
	gameMode->PlayerButtonPush(Constants.player3);
	interrupts();
}

void Player4Push()
{
	noInterrupts();
	Serial.write("Player 4 pressed!");
	gameMode->PlayerButtonPush(Constants.player4);
	interrupts();
}

void Player5Push()
{
	noInterrupts();
	Serial.write("Player 5 pressed!");
	gameMode->PlayerButtonPush(Constants.player5);
	interrupts();
}

void TimerInterrupt()
{
	gameMode->TimerPush();
}