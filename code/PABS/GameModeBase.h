// GameModeBase.h

#ifndef _GAMEMODEBASE_h
#define _GAMEMODEBASE_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "Arduino.h"
#else
	#include "WProgram.h"
#endif

class GameModeBase
{
 public:
	 virtual void PlayerButtonPush(int playerNumber);
	 virtual void AdminButtonPush(int buttonNumber);
};


#endif

