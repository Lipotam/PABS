// KlimovichSEBrainRingMode.h

#ifndef _KLIMOVICHSEBRAINRINGMODE_h
#define _KLIMOVICHSEBRAINRINGMODE_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif


#include "GameModeBase.h"

class KlimovichSEBrainRingMode : public GameModeBase
{
public:
	KlimovichSEBrainRingMode();
	~KlimovichSEBrainRingMode();

	virtual void PlayerButtonPush(int playerNumber);
	virtual void AdminButtonPush(int buttonNumber);
	virtual void TimerPush();

protected:
	bool state[5];
	int status;

	bool CheckAndSetPlayerPush(int playerNumber, int playerPin);
	void SetPlayerPush(int playerNumber);
	void ResetState();

};

#endif
