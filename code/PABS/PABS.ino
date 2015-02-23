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
	pinMode(Constants.ledPin, OUTPUT);
	pinMode(Constants.displayShiftRegisterClk, OUTPUT);
	pinMode(Constants.displayShiftRegisterData, OUTPUT);
	pinMode(Constants.displayShiftRegisterRefresh, OUTPUT);
	pinMode(Constants.gameStateHighBit, INPUT);
	pinMode(Constants.gameStateLowBit, INPUT);

	int highModeValue = analogRead(Constants.gameStateHighBit);
	int lowModeValue = analogRead(Constants.gameStateLowBit);


	if(highModeValue < Constants.analogSeparator && lowModeValue < Constants.analogSeparator)
	{
		gameMode = new TestMode();
	}
	else
	{
		if(highModeValue < Constants.analogSeparator && lowModeValue > Constants.analogSeparator)
		{
			gameMode = new BrainRingMode();
		}
		else
		{
			if(highModeValue > Constants.analogSeparator && lowModeValue < Constants.analogSeparator)
			{
				gameMode = new OwnGameMode();
			}
			else
			{
				if(highModeValue > Constants.analogSeparator && lowModeValue > Constants.analogSeparator)
				{
					gameMode = new WwwMode();
					  Timer1.initialize(1000000);        
				      Timer1.attachInterrupt(TimerInterrupt);
				}
			}
		}
	}

	attachInterrupt(0,AdminInterrupt,HIGH);
	attachInterrupt(1,UserInterrupt,HIGH);
}

void loop()
{

}


void AdminInterrupt()
{
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
}

void UserInterrupt()
{
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
}


void TimerInterrupt()
{
   gameMode ->PlayerButtonPush(Constants.player5);
}