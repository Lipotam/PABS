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
	pinMode(Constants.adminStartButton, INPUT);
	pinMode(Constants.adminResetButton, INPUT);
	pinMode(Constants.adminInterrupt, INPUT);
	pinMode(Constants.playerInerrupt, INPUT);
	pinMode(Constants.firstPlayerButton, INPUT);
	pinMode(Constants.secondPlayerButton, INPUT);
	pinMode(Constants.thirdPlayerButton, INPUT);
	pinMode(Constants.fourthPlayerButton, INPUT);
	pinMode(Constants.fifthPlayerButton, INPUT);
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
			if (state > 4)
			{
				state = 0;
			}
			delay(200);
		}
	}

	delay(1000);

	if(state == 0)
	{
		SystemMethodsObject.SetDisplayNumber(11);
		gameMode = new TestMode();
		Serial.write("TestMode");
		attachInterrupt(1,UserInterrupt,RISING);
	}
	else
	{
		if(state ==1)
		{
			SystemMethodsObject.SetDisplayNumber(22);
			gameMode = new BrainRingMode();
			Serial.write("BrainMode");
			attachInterrupt(1,UserInterrupt,RISING);
		}
		else
		{
			if(state == 2)
			{
				SystemMethodsObject.SetDisplayNumber(33);
				gameMode = new OwnGameMode();
				Serial.write("OwnGameMode");
				attachInterrupt(1,UserInterrupt,RISING);
			}
			else
			{
				if(state == 3)
				{
					SystemMethodsObject.SetDisplayNumber(44);
					gameMode = new WwwMode();
					Timer1.initialize(1000000);        
					Timer1.attachInterrupt(TimerInterrupt);
					Serial.write("WwwMode!");
				}
				else
				{
					if (state == 4)
					{
						SystemMethodsObject.SetDisplayNumber(55);
						gameMode = new BrainRingWithTimerMode();
						Timer1.initialize(1000000);
						Timer1.attachInterrupt(TimerInterrupt);
						Serial.write("Brain with Timer!");
						attachInterrupt(1, UserInterrupt, RISING);
					}
				}
			}
		}
	}

	SystemMethodsObject.SetUserLed(-1);
	SystemMethodsObject.PlaySound(2000, 1000);
	attachInterrupt(0,AdminInterrupt,RISING);
}

void loop()
{
}


void AdminInterrupt()
{
	noInterrupts();
	if(digitalRead(Constants.adminResetButton) == HIGH )
	{
		gameMode ->AdminButtonPush(Constants.adminReset);
	}
	else
	{
		if(digitalRead(Constants.adminStartButton) == HIGH )
		{
			gameMode ->AdminButtonPush(Constants.adminSet);
		}
	}
	interrupts();
}

void UserInterrupt()
{
	noInterrupts();
	if (digitalRead(Constants.firstPlayerButton) == HIGH)
	{
		gameMode ->PlayerButtonPush(Constants.player1);
	}
	else
	{
		if (digitalRead(Constants.secondPlayerButton) == HIGH)
		{
			gameMode ->PlayerButtonPush(Constants.player2);
		}
		else
		{
			if (digitalRead(Constants.thirdPlayerButton) == HIGH)
			{
				gameMode ->PlayerButtonPush(Constants.player3);
			}
			else
			{
				if (digitalRead(Constants.fourthPlayerButton) == HIGH)
				{
					gameMode ->PlayerButtonPush(Constants.player4);
				}
				else
				{
					if (digitalRead(Constants.fifthPlayerButton) == HIGH)
					{
						gameMode ->PlayerButtonPush(Constants.player5);
					}
				}
			}
		}
	}
	interrupts();
}


void TimerInterrupt()
{
	gameMode->TimerPush();
}