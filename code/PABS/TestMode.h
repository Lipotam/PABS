// TestMode.h

#ifndef _TESTMODE_h
#define _TESTMODE_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "Arduino.h"
#else
	#include "WProgram.h"
#endif

#include "GameModeBase.h"

class TestMode: public GameModeBase
{
   public:
	   TestMode();
	   ~TestMode();
	 void PlayerButtonPush(int playerNumber);
	 void AdminButtonPush(int buttonNumber);
};


#endif