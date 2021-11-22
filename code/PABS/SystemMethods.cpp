// 
// 
// 

//#define OldDisplay
#define DEBUG

#include "SystemMethods.h"
#include "Constants.h"

#ifdef OldDisplay

#include <LedControl.h>

LedControl display = LedControl(Constants.displayShiftRegisterRefresh, Constants.displayShiftRegisterClk, Constants.displayShiftRegisterData, 1);

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

	if (faultStart)
	{
		display.setChar(0, 0, 'f', true);
	}
	else
	{
		int highByte = (number / 10) % 10;
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

void SystemMethods::SetDashesDisplay()
{
	display.setChar(0, 0, '-', false);
	display.setChar(0, 1, '-', false);
}

#else

void SystemMethods::initDisplay()
{
	ClearDisplay();
}

void SystemMethods::SetDisplayNumber(int number, bool faultStart)
{
	SystemMethodsObject.WriteDebug("Display ");
	SystemMethodsObject.WriteDebug(number);
	SystemMethodsObject.WriteDebug(" set!");

	digitalWrite(Constants.displayShiftRegisterClk, LOW);

	bool dotsEnable = false;

	if (number < 0)
	{
		number = number * -1;
		dotsEnable = true;
	}

	int lowDigit = number % 10;

	ShiftToDisplay(Constants.digit[lowDigit], dotsEnable);

	if (faultStart)
	{
		ShiftToDisplay(Constants.digit[11], true);
	}
	else
	{
		int highByte = (number / 10) % 10;
		if (highByte == 0)
		{
			ShiftToDisplay(Constants.digit[10], dotsEnable);
		}
		else
		{
			ShiftToDisplay(Constants.digit[highByte], dotsEnable);
		}
	}

	digitalWrite(Constants.displayShiftRegisterClk, HIGH);
}

void SystemMethods::ClearDisplay()
{
	digitalWrite(Constants.displayShiftRegisterClk, LOW);
	ShiftToDisplay(Constants.digit[10], false);
	ShiftToDisplay(Constants.digit[10], false);
	digitalWrite(Constants.displayShiftRegisterClk, HIGH);
}

void SystemMethods::SetDashesDisplay()
{
	digitalWrite(Constants.displayShiftRegisterClk, LOW);
	ShiftToDisplay(0b11111101, false);
	ShiftToDisplay(0b11111101, false);
	digitalWrite(Constants.displayShiftRegisterClk, HIGH);
}

void SystemMethods::ShiftToDisplay(uint8_t rawData, bool addDot)
{
	if (addDot)
	{
		shiftOut(Constants.displayShiftRegisterRefresh, Constants.displayShiftRegisterData, LSBFIRST, rawData & 0b11111110 );
	}
	else
	{
		shiftOut(Constants.displayShiftRegisterRefresh, Constants.displayShiftRegisterData, LSBFIRST, rawData);
	}
}

#endif

void SystemMethods::SetUserLed(int number)
{
	digitalWrite(Constants.ledShiftRegisterRefresh, LOW);

	if (number == -1)
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

void SystemMethods::RaiseParallelInterrupt()
{
	digitalWrite(Constants.parallelOutInterruptPin, HIGH);
}
void SystemMethods::LowerParallelInterrupt()
{
	digitalWrite(Constants.parallelOutInterruptPin, LOW);
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
	Serial.print(number);
#endif
}

SystemMethods SystemMethodsObject;