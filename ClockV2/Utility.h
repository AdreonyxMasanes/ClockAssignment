#pragma once
#include "MeridianClock.h"
#include <iomanip>
class Utility
{
public:
	static void printClocks(Clock militaryClock, MeridianClock standardClock);
	static void printMenu();
};