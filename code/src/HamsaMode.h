// HamsaMode.h

#ifndef _HAMSAMODE_h
#define _HAMSAMODE_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

#include "GameModeBase.h"

class HamsaMode: public GameModeBase
{
private:
	bool readyPlayers[5];
	bool blocked[5];
	int playersQueue[5];
	int currentAsweringUser;
	int answerIndex;
	bool isUserAnswering;

	int timer;
	int lastAdminSetClickSecond;
	uint8_t ledByte;

	void SetPlayerLights();
	void ResetState();

public:
	HamsaMode();
	~HamsaMode();

	virtual void PlayerButtonPush(int playerNumber);
	virtual void AdminButtonPush(int buttonNumber);
	virtual void ParallelInterruptPush();
	virtual void TimerPush();
};
#endif

