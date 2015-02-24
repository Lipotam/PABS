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
	SystemMethodsObject.PlaySound(1000*playerNumber,1000);
}
void TestMode::AdminButtonPush(int buttonNumber)
{
	SystemMethodsObject.SetDisplayNumber(10+buttonNumber);
	SystemMethodsObject.SetUserLed(buttonNumber);
	SystemMethodsObject.PlaySound(1000*(10+buttonNumber),1000);
}