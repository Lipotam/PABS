#include <LedControl.h>
#include "SystemMethods.h"
#include "Constants.h"

void setup() {
	SystemMethodsObject.initDisplay();
}

void loop()
{
	test_display();
}

void test_display()
{
	SystemMethodsObject.SetDisplayNumber(-1, false);
	delay(400);

	for (int i = 0; i < 60; i++)
	{
		SystemMethodsObject.SetDisplayNumber(i, false);
		delay(400);
	}

	SystemMethodsObject.SetDisplayNumber(-1, false);
	delay(400);

	for (int i = 0; i < 6; i++)
	{
		SystemMethodsObject.SetDisplayNumber(i, true);
		delay(400);
	}
}


