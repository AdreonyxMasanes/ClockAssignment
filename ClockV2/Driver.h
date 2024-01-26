#pragma once
#include "MeridianClock.h"
#include <iomanip>
class Driver
{
private:
	static void printClocks(Clock militaryClock, MeridianClock standardClock);
	static void printMenu();
	
public:
	static void run();
};