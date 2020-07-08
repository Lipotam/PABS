// 
// 
// 

#include "SystemMethods.h"
#include "Constants.h"


#define DEBUG

LedControl display = LedControl(Constants.displayShiftRegisterRefresh, Constants.displayShiftRegisterClk, Constants.displayShiftRegisterData, 1);

void SystemMethods::init()
{
}

void SystemMethods::initDisplay()
{
	display = LedControl(Constants.displayShiftRegisterRefresh, Constants.displayShiftRegisterClk, Constants.displayShiftRegisterData, 1);
	display.shutdown(0, false);
	display.setIntensity(0, 15); 
	display.clearDisplay(0); 
}

void SystemMethods::SetDisplayNumber(int number, bool faultStart)
{
	SystemMethodsObject.WriteDebug("Display ");
	SystemMethodsObject.WriteDebug(number);
	SystemMethodsObject.WriteDebug(" set!");

	bool dotsEnable = false;

	if (number < 0)
	{
		number = number * -1;
		dotsEnable = true;
	}

	int lowDigit = number % 10;

	if(faultStart)
	{
		display.setChar(0, 0, 'f', true);
	}
	else
	{
		

		int highByte= (number / 10) %10;
		if (highByte == 0)
		{
			display.setChar(0, 0, ' ', dotsEnable);
		}
		else
		{
			display.setDigit(0, 0, highByte, dotsEnable);
		}
	}

	display.setDigit(0, 1, lowDigit, dotsEnable);

	digitalWrite(Constants.displayShiftRegisterRefresh, LOW);
	digitalWrite(Constants.displayShiftRegisterClk, LOW);
	digitalWrite(Constants.displayShiftRegisterData, LOW);
}


void SystemMethods::ClearDisplay()
{
	display.setChar(0, 0, ' ', false);
	display.setChar(0, 1, ' ', false);
}

void SystemMethods::SetUserLed(int number)
{
	digitalWrite(Constants.ledShiftRegisterRefresh, LOW);

	if(number ==-1)
	{
		shiftOut(Constants.ledShiftRegisterData, Constants.ledShiftRegisterClk, LSBFIRST, Constants.led[5]);
	}
	else
	{
		SystemMethodsObject.WriteDebug("Led ");
		SystemMethodsObject.WriteDebug(Constants.led[number]);
		SystemMethodsObject.WriteDebug(" set!");
		shiftOut(Constants.ledShiftRegisterData, Constants.ledShiftRegisterClk, LSBFIRST, Constants.led[number]);
	}

	digitalWrite(Constants.ledShiftRegisterRefresh, HIGH);
}


void SystemMethods::SetUserLedWithByte(uint8_t rawData)
{
	digitalWrite(Constants.ledShiftRegisterRefresh, LOW);
	shiftOut(Constants.ledShiftRegisterData, Constants.ledShiftRegisterClk, LSBFIRST, rawData);
	digitalWrite(Constants.ledShiftRegisterRefresh, HIGH);
}

void SystemMethods::PlaySound(int frequency, int milliseconds)
{
	noTone(Constants.speakerPin);
	tone(Constants.speakerPin, frequency, milliseconds); 
}

void SystemMethods::SetupSerial()
{
	#ifdef DEBUG
		Serial.begin(9600);
	#endif
}

void SystemMethods::WriteDebug(char* message) 
{
	#ifdef DEBUG
		Serial.write(message);
	#endif
}

void SystemMethods::WriteDebug(int number)
{
#ifdef DEBUG
	Serial.write(number);
#endif
}

SystemMethods SystemMethodsObject;