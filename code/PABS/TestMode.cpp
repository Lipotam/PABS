// 
// 
// 

#include "TestMode.h"
#include "SystemMethods.h"
#include "Constants.h"

TestMode::TestMode(){}
TestMode::~TestMode(){}

void TestMode::PlayerButtonPush(int playerNumber)
{
	SystemMethodsObject.SetDisplayNumber(playerNumber);
	SystemMethodsObject.SetUserLed(playerNumber);
	SystemMethodsObject.PlaySound(Constants.playerSignalPeriodFrequency * playerNumber,Constants.signalPeriod);
}
void TestMode::AdminButtonPush(int buttonNumber)
{
	SystemMethodsObject.SetDisplayNumber(10+buttonNumber);
	SystemMethodsObject.SetUserLed(buttonNumber);
	SystemMethodsObject.PlaySound(Constants.adminSignalPeriodFrequency * (5+buttonNumber),Constants.signalPeriod);
}