// 
// 
// 

#include "SystemMethods.h"
#include "Constants.h"

void SystemMethods::init()
{
	// do nothing
}


void SystemMethods::SetDisplayNumber(int number)
{
	digitalWrite(Constants.displayShiftRegisterRefresh, LOW);


	if(number == -1)
	{
		shiftOut(Constants.displayShiftRegisterData, Constants.displayShiftRegisterClk, LSBFIRST, Constants.digit[10]);
		shiftOut(Constants.displayShiftRegisterData, Constants.displayShiftRegisterClk, LSBFIRST, Constants.digit[10]);
	}
	else
	{
		int lowDigit = number % 10;
		int highByte= (number / 10) %10;
		if (highByte == 0)
		{
			highByte = 10;
		}

		shiftOut(Constants.displayShiftRegisterData, Constants.displayShiftRegisterClk, LSBFIRST, Constants.digit[lowDigit]);
		shiftOut(Constants.displayShiftRegisterData, Constants.displayShiftRegisterClk, LSBFIRST, Constants.digit[highByte]);
	}

	digitalWrite(Constants.displayShiftRegisterRefresh, HIGH);
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

