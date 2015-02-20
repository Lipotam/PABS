// OwnGameMode.h

#ifndef _OWNGAMEMODE_h
#define _OWNGAMEMODE_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "Arduino.h"
#else
	#include "WProgram.h"
#endif

#include "GameModeBase.h"

class OwnGameModeClass: GameModeBase
{
  public:
	 void PlayerButtonPush(int playerNumber);
	 void AdminButtonPush(int buttonNumber);
	void init();
};
#endif

