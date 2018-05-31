// 
// 
// 

#include "SystemMethods.h"
#include "Constants.h"
#include <LedControl.h>

LedControl display = LedControl(Constants.displayShiftRegisterRefresh, Constants.displayShiftRegisterClk, Constants.displayShiftRegisterData, 1);

void SystemMethods::init()
{
}

void SystemMethods::initDisplay()
{
	display = LedControl(Constants.displayShiftRegisterRefresh, Constants.displayShiftRegisterClk, Constants.displayShiftRegisterData, 1);
	display.shutdown(0, false); // включаем дисплей энергосбережение дисплей
	display.setIntensity(0, 8);// устанвливаем яркость (0-минимум, 15-максимум) 
	display.clearDisplay(0);// очищаем дисплей 
}

void SystemMethods::SetDisplayNumber(int number, bool faultStart)
{

	Serial.write("Display ");
	Serial.print(number);
	Serial.write(" set!");

		if(number == -1)
	{
		display.setChar(0, 0, ' ', false);
		display.setChar(0, 1, ' ', false);
	}
	else
	{
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
				display.setChar(0, 0, ' ', false);
			}
			else
			{
				display.setDigit(0, 0, highByte, false);
			}
		}

		display.setDigit(0, 1, lowDigit, false);
	}
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
		Serial.write("Led ");
		Serial.print(Constants.led[number]);
		Serial.write(" set!");
		shiftOut(Constants.ledShiftRegisterData, Constants.ledShiftRegisterClk, LSBFIRST, Constants.led[number]);
	}

	digitalWrite(Constants.ledShiftRegisterRefresh, HIGH);
}

void SystemMethods::PlaySound(int frequency, int milliseconds)
{
	noTone(Constants.speakerPin);
	tone(Constants.speakerPin, frequency, milliseconds); 
}

SystemMethods SystemMethodsObject;