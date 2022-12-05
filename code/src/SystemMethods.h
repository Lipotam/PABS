// SystemMethods.h

#ifndef _SYSTEMMETHODS_h
#define _SYSTEMMETHODS_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "Arduino.h"
#else
	#include "WProgram.h"
#endif

#include "LedControl.h"


class SystemMethods
{

 public:
	 void SetDisplayNumber(int number, bool faultStart = false);
	 void ClearDisplay();
	 void SetUserLed(int number);
	 void SetUserLedWithByte(uint8_t rawData);
	 void PlaySound(int frequency, int milliseconds);
	 void init();
	 void initDisplay();

	 void SetupSerial();
	 void WriteDebug(const char* message);
	 void WriteDebug(int number);
};

extern SystemMethods SystemMethodsObject;

#endif

