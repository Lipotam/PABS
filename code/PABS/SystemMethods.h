// SystemMethods.h

#ifndef _SYSTEMMETHODS_h
#define _SYSTEMMETHODS_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "Arduino.h"
#else
	#include "WProgram.h"
#endif

class SystemMethods
{

 public:
	 void SetDisplayNumber(int number, bool faultStart = false);
	 void SetUserLed(int number);
	 void PlaySound(int frequency, int milliseconds);
	void init();
};

extern SystemMethods SystemMethodsObject;

#endif

