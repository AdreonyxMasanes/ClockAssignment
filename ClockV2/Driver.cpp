#include "Driver.h"

void Driver::printMenu()
{
	const int LENGTH_OF_LINE = 37;
	const int SPACING = 11;


	// First Line
	std::cout << std::setfill(' ') << std::setw(SPACING) << "" << std::setfill('*') << std::setw(LENGTH_OF_LINE) << "" << std::endl;

	// Second Line
	// LENGTH OF LINE - 1 Because we have one final * at the end.
	std::cout << std::setfill(' ') << std::setw(SPACING) << "" << std::left << std::setw(LENGTH_OF_LINE - 1) << "* Press H to increment the hour" << "*" << std::endl;

	std::cout << std::right << std::setfill(' ') << std::setw(SPACING) << "" << std::left << std::setw(LENGTH_OF_LINE - 1) << "* Press M to increment the minute" << "*" << std::endl;

	std::cout << std::right << std::setfill(' ') << std::setw(SPACING) << "" << std::left << std::setw(LENGTH_OF_LINE - 1) << "* Press S to increment the second" << "*" << std::endl;
	
	std::cout << std::right << std::setfill(' ') << std::setw(SPACING) << "" << std::left << std::setw(LENGTH_OF_LINE - 1) << "* Press Q to Quit" << "*" << std::endl;
	
	std::cout << std::setfill(' ') << std::setw(SPACING) << "" << std::setfill('*') << std::setw(LENGTH_OF_LINE) << "" << std::endl;
	
	// Reset output format
	std::cout << std::right;
}

void Driver::printClocks(Clock militaryClock, MeridianClock standardClock)
{
	const int LENGTH_OF_LINE = 27;
	const int SPACING = 5;

	// First line
	std::cout << std::setfill('*') << std::setw(LENGTH_OF_LINE) << "";
	std::cout << std::setfill(' ') << std::setw(SPACING) << "";
	std::cout << std::setfill('*') << std::setw(LENGTH_OF_LINE) << "" << std::endl;

	// Second line first half
	std::cout << "*" << std::setfill(' ') << std::setw(LENGTH_OF_LINE - 8) << "12-Hour Clock" << std::setw(7) << "*";
	
	// Second line Spacing
	std::cout << std::setfill(' ') << std::setw(SPACING) << "";

	// Second line second half
	std::cout << "*" << std::setfill(' ') << std::setw(LENGTH_OF_LINE - 8) << "24-Hour Clock" << std::setw(7) << "*" << std::endl;
	

	// Third line first half
	std::cout << "*" << std::setfill(' ') << std::setw(LENGTH_OF_LINE - 9) << standardClock.getTime() << std::setw(8) << "*";

	// Third line Spacing
	std::cout << std::setfill(' ') << std::setw(SPACING) << "";

	// Second line second half
	std::cout << "*" << std::setfill(' ') << std::setw(LENGTH_OF_LINE - 10) << militaryClock.getTime() << std::setw(9) << "*" << std::endl;

	// Final line
	std::cout << std::setfill('*') << std::setw(LENGTH_OF_LINE) << "";
	std::cout << std::setfill(' ') << std::setw(SPACING) << "";
	std::cout << std::setfill('*') << std::setw(LENGTH_OF_LINE) << "" << std::endl;
}

// TODO: GET USERINPUT
void Driver::run()
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
		printClocks(militaryClock, normalClock);

		// Print Menu
		printMenu();

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
}
