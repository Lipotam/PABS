// BrainRingMode.h

#ifndef _BRAINRINGWITHTIMERMODE_h
#define _BRAINRINGWITHTIMERMODE_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

#include "BrainRingMode.h"

class BrainRingWithTimerMode : public BrainRingMode
{
private:
	bool state[5];
	int status; // 0 - default, 1 - timer, 2 - user clicked, 3 - fault start
	int timer;

	void ResetState();

public:
	BrainRingWithTimerMode();
	~BrainRingWithTimerMode();

	virtual void PlayerButtonPush(int playerNumber);
	virtual void AdminButtonPush(int buttonNumber);
	virtual void TimerPush();
};


#endif

