#include "SystemMethods.h"
#include "TestMode.h"
#include "WwwMode.h"
#include "OwnGameMode.h"
#include "BrainRingMode.h"
#include "GameModeBase.h"
#include "Constants.h"

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
				}
			}
		}
	}


}

void loop()
{

  /* add main program code here */

}
