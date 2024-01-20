#pragma once
#include "Clock.h"

enum Meridians 
{
	AM,
	PM
};

class MeridianClock : public Clock
{
private:
	Meridians currentMeridian = Meridians::AM;
	void convertFromMilTime();
	void handleOverflowHours() override;

	void setMeridian(Meridians newMeridian);
	bool meridianChanged(int hour);
	void swapMeridian();
	std::string getMeridian();
	
	
public:
	MeridianClock();
	MeridianClock(int hour, int minute, int second);
	std::string getTime() override;
	void incrementHours() override;
	
};