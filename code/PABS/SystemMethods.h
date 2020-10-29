// SystemMethods.h

#ifndef _SYSTEMMETHODS_h
#define _SYSTEMMETHODS_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "Arduino.h"
#else
	#include "WProgram.h"
#endif



#ifdef OldDisplay
#include "LedControl.h"
#endif


class SystemMethods
{

 public:
	 void SetDisplayNumber(int number, bool faultStart = false);
	 void ClearDisplay();
	 void SetUserLed(int number);
	 void SetUserLedWithByte(uint8_t rawData);
	 void PlaySound(int frequency, int milliseconds);
	 void initDisplay();

	 void SetupSerial();
	 void WriteDebug(char* message);
	 void WriteDebug(int number);

private:
	 void ShiftToDisplay(uint8_t rawData, bool faultStart);
};

extern SystemMethods SystemMethodsObject;

#endif

