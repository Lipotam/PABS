// BrainRingMode.h

#ifndef _BRAINRINGMODE_h
#define _BRAINRINGMODE_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "Arduino.h"
#else
	#include "WProgram.h"
#endif

#include "GameModeBase.h"

class BrainRingMode : public GameModeBase
{
private:
	bool state[5];
	int status;

	void ResetState();
	

  public:
	  BrainRingMode();
	  ~BrainRingMode();

	 virtual void PlayerButtonPush(int playerNumber);
	 virtual void AdminButtonPush(int buttonNumber);
	 virtual void TimerPush();

	protected:
		bool CheckAndSetPlayerPush(int playerNumber, int playerPin);
		void SetPlayerPush(int playerNumber);
};


#endif

