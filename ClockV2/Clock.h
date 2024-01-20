#pragma once
#include <iostream>
#include <string>
enum Magnitudes
{
	hour,
	minute,
	second
};

class Clock
{
protected:
	int m_hours = 0;
	int m_minutes = 0;
	int m_seconds = 0;
	int m_maxHours = 0;
	const int MAX_MINUTES = 60;
	const int MAX_SECONDS = 60;

	bool isOverflowing(int currTime, int maxTime);
	
	virtual void handleOverflowHours();
	void handleOverflowMinutes();
	void handleOverflowSeconds();

	
	std::string formatMagnitude(int time);

public:
	Clock();
	Clock(int hours, int minutes, int seconds);

	void setHours(int hour);
	void setMinutes(int minute);
	void setSeconds(int second);
	void setMaxHour(int maxHour);

	virtual void incrementHours();
	void incrementMinutes();
	void incrementSeconds();

	virtual std::string getTime();

	int getCurrHour();
	int getCurrMinute();
	int getCurrSecond();
	int getMaxHour();
	int getMaxMinute();
	int getMaxSecond();
};