#include "SystemMethods.h"
#include "Constants.h"

void setup() {
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


	SystemMethodsObject.initDisplay();
}

void loop()
{


	//analogWrite(9, 64);

	//analogWrite(6, 128);
	test_display();
	//test_leds();
}

void test_display()
{
	SystemMethodsObject.WriteDebug("Display testing!");
	SystemMethodsObject.SetDisplayNumber(-1, false);
	delay(400);

	for (int i = 0; i < 60; i++)
	{
		SystemMethodsObject.SetDisplayNumber(i, false);
		delay(400);
	}

	SystemMethodsObject.SetDisplayNumber(-1, false);
	delay(400);

	for (int i = 0; i < 6; i++)
	{
		SystemMethodsObject.SetDisplayNumber(i, true);
		delay(400);
	}
}

void test_leds() 
{
	SystemMethodsObject.WriteDebug("Led Testing!");
	
	for (int i = 0; i < 5; i++)
	{
		SystemMethodsObject.SetUserLed(i);
		delay(100);
	}
	

}
