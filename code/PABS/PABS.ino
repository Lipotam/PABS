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
		Serial.write("TestMode");
	}
	else
	{
		if(highModeValue < Constants.analogSeparator && lowModeValue > Constants.analogSeparator)
		{
			gameMode = new BrainRingMode();
			Serial.write("BrainMode");
		}
		else
		{
			if(highModeValue > Constants.analogSeparator && lowModeValue < Constants.analogSeparator)
			{
				gameMode = new OwnGameMode();
				Serial.write("OwnGameMode");
			}
			else
			{
				if(highModeValue > Constants.analogSeparator && lowModeValue > Constants.analogSeparator)
				{
					gameMode = new WwwMode();
					  Timer1.initialize(1000000);        
				      Timer1.attachInterrupt(TimerInterrupt);
					  Serial.write("WwwMode");
				}
			}
		}
	}
	
	Serial.write("setDisplay");
	SystemMethodsObject.SetDisplayNumber(-1);

	Serial.write("setLeds");
	SystemMethodsObject.SetUserLed(-1);
	Serial.write("setMusic");
	SystemMethodsObject.PlaySound(1000,1000);

	attachInterrupt(0,AdminInterrupt,RISING);
	attachInterrupt(1,UserInterrupt,RISING);
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
		Serial.write("AdminResetClicked");
	}
	else
	{
		if(digitalRead(Constants.adminStartButton) == HIGH )
		{
			gameMode ->AdminButtonPush(Constants.adminSet);
			Serial.write("AdminSetClicked");
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
		Serial.write("Player1Clicked");
	}
	else
	{
		if (digitalRead(Constants.secondPlayerButton) == HIGH)
		{
			gameMode ->PlayerButtonPush(Constants.player2);
			Serial.write("Player2Clicked");
		}
		else
		{
			if (digitalRead(Constants.thirdPlayerButton) == HIGH)
			{
				gameMode ->PlayerButtonPush(Constants.player3);
				Serial.write("Player3Clicked");
			}
			else
			{
				if (digitalRead(Constants.fourthPlayerButton) == HIGH)
				{
					gameMode ->PlayerButtonPush(Constants.player4);
					Serial.write("Player4Clicked");
				}
				else
				{
					if (digitalRead(Constants.fifthPlayerButton) == HIGH)
					{
						gameMode ->PlayerButtonPush(Constants.player5);
						Serial.write("Player5Clicked");
					}
				}
			}
		}
	}
	 interrupts();
}


void TimerInterrupt()
{
   gameMode ->PlayerButtonPush(Constants.player5);
}