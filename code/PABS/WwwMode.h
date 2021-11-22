// WwwMode.h

#ifndef _WWWMODE_h
#define _WWWMODE_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "Arduino.h"
#else
	#include "WProgram.h"
#endif

#include "GameModeBase.h"

class WwwMode: public GameModeBase
{
private:
	int state;
	int timeLeft;
  public:
	  WwwMode();
	  ~WwwMode();
	 void PlayerButtonPush(int playerNumber);
	 void AdminButtonPush(int buttonNumber);
	 void TimerPush();
};



#endif
