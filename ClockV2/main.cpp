#include "Utility.h"
/*
	Adreonyx Masanes
	27 Jan, 2024
	Project One
*/
int main()
{
	// User input
	int userHour = 0;
	int userMinute = 0;
	int userSecond = 0;
	std::cout << "Enter a start time in military standard formated like so: HH MM SS. EX. 23:22:02" << std::endl;
	std::cin >> userHour >> userMinute >> userSecond;

	// Create clocks
	Clock militaryClock(userHour, userMinute, userSecond);
	MeridianClock normalClock(userHour, userMinute, userSecond);

	// Start main loop.
	char userInput;
	do
	{
		// Clear Screen
		system("CLS");

		// Print Clocks
		Utility::printClocks(militaryClock, normalClock);

		// Print Menu
		Utility::printMenu();

		// User input
		std::cin >> userInput;
		switch (userInput)
		{
		case 'h':
			militaryClock.incrementHours();
			normalClock.incrementHours();
			break;
		case 'm':
			militaryClock.incrementMinutes();
			normalClock.incrementMinutes();
			break;
		case 's':
			militaryClock.incrementSeconds();
			normalClock.incrementSeconds();
			break;
		case 'q':
			break;
		default:
			std::cout << "Enter a valid option please." << std::endl;
		}
		// Pause console if they did not quit.
		if (userInput != 'q')
		{
			system("Pause");
		}
		// Continue until they quit
	} while (userInput != 'q');
	return 0;
}