#include "Clock.h"
// CONSTRUCTOR
Clock::Clock(){};
// OVERLOADED CONSTRUCTOR
Clock::Clock(int hours, int minutes, int seconds)
	: m_hours(hours), m_minutes(minutes), m_seconds(seconds)
{
	// MILITARY CLOCK
	setMaxHour(24);
}


void Clock::setHours(int hour)
{
	m_hours = hour;
}

void Clock::setMinutes(int minute)
{
	m_minutes = minute;
}

void Clock::setSeconds(int second)
{
	m_seconds = second;
}

void Clock::setMaxHour(int maxHour)
{
	m_maxHours = maxHour;
}

// DETERMINE IF THE TIME IS OVERFLOWING
bool Clock::isOverflowing(int currTime, int maxTime)
{
	if (currTime >= maxTime)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Clock::handleOverflowHours()
{
	m_hours = 0;
}

void Clock::handleOverflowMinutes()
{
	m_minutes = 0;
	incrementHours();
}

void Clock::handleOverflowSeconds()
{
	m_seconds = 0;
	incrementMinutes();
}

// FORMAT: 01 INSTEAD OF 1
std::string Clock::formatMagnitude(int time)
{
	std::string formattedTime = std::to_string(time);
	if (time < 10)
	{
		formattedTime = ("0" + std::to_string(time));
	}
	return formattedTime;
}

void Clock::incrementHours()
{
	m_hours++;
	if (isOverflowing(m_hours, m_maxHours))
	{
		handleOverflowHours();
	}
}
void Clock::incrementMinutes()
{
	m_minutes++;
	if (isOverflowing(m_minutes, MAX_MINUTES))
	{
		handleOverflowMinutes();
	}
}
void Clock::incrementSeconds()
{
	m_seconds++;
	if (isOverflowing(m_seconds, MAX_SECONDS))
	{
		handleOverflowSeconds();
	}
}
// RETURN THE TIME IN THE FORMAT OF HH:MM:SS
std::string Clock::getTime()
{
	std::string time = "";
	time += formatMagnitude(m_hours);
	time += ":";

	time += formatMagnitude(m_minutes);
	time += ":";

	time += formatMagnitude(m_seconds);
	return time;
}
int Clock::getCurrHour()
{
	return m_hours;
}
int Clock::getCurrMinute()
{
	return m_minutes;
}
int Clock::getCurrSecond()
{
	return m_seconds;
}
int Clock::getMaxHour()
{
	return m_maxHours;
}
int Clock::getMaxMinute()
{
	return MAX_MINUTES;
}
int Clock::getMaxSecond()
{
	return MAX_SECONDS;
}
