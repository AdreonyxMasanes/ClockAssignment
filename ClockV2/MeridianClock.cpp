#include "MeridianClock.h"

// CONVERT
void MeridianClock::convertFromMilTime()
{
	int currHour = getCurrHour();
	// In Mil time 12 - 23 are all PM 
	if (currHour > 11)
	{
		setMeridian(Meridians::PM);
		if (currHour > 12)
		{
			// IF IT IS HIGHER THAN 12 CONVERT TO STANDARD HOUR FORMAT
			setHours(currHour - 12);
		}
	}
	else
	{
		setMeridian(Meridians::AM);
	}
}

// SET THE MERIDIAN ONLY IF IT IS DIFFERENT THAN THE CURRENT MERIDIAN
void MeridianClock::setMeridian(Meridians newMeridian)
{
	if (currentMeridian != newMeridian)
	{
		currentMeridian = newMeridian;
	}
}

// CHANGE MERIDAN FROM AM TO PM OR VICE VERSA
void MeridianClock::swapMeridian()
{
	if (currentMeridian == Meridians::AM)
	{
		currentMeridian = Meridians::PM;
	}
	else
	{
		currentMeridian = Meridians::AM;
	}
}
// CONSTRUCTOR
MeridianClock::MeridianClock()
{
	Clock::setMaxHour(12);
}

// OVERLOADED CONSTRUCTOR
MeridianClock::MeridianClock(int hour, int minute, int second)
{
	// SET TIME
	Clock::setHours(hour);
	Clock::setMinutes(minute);
	Clock::setSeconds(second);
	// SET MAX HOUR FOR OVERFLOW
	Clock::setMaxHour(13);

	convertFromMilTime();
}

// GET THE TIME IN THE FORMAT OF HH:MM:SS MERIDIAN AS A STRING
std::string MeridianClock::getTime()
{
	std::string time = Clock::getTime();
	time += getMeridian();
	return time;
}

// Increase Hour
void MeridianClock::incrementHours()
{
	m_hours++;
	if (meridianChanged(getCurrHour()))
	{
		swapMeridian();
	}

	if (isOverflowing(m_hours, m_maxHours))
	{
		handleOverflowHours();
	}

}

// Get the current meridian
std::string MeridianClock::getMeridian()
{
	std::string meridian = "";
	if (currentMeridian == Meridians::AM)
	{
		meridian = " AM";
	}
	else
	{
		meridian = " PM";
	}
	return meridian;
}

// Check if the time has passed from AM to PM or Vice Versa
bool MeridianClock::meridianChanged(int hour)
{
	if (hour == 12)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void MeridianClock::handleOverflowHours()
{
	Clock::setHours(1);
}
