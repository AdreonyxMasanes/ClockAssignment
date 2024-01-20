#include "Driver.h"

void Driver::printMenu()
{
	// First Line
	std::cout << std::setfill('*') << std::setw(37) << "" << std::endl;

	// Second Line
	std::cout << "* " << std::setfill(' ') << std::setw(19) << "Press H to increment the hour" << std::setw(6) << "*" << std::endl;

	std::cout << "* " << std::setfill(' ') << std::setw(19) << "Press M to increment the hour" << std::setw(6) << "*" << std::endl;

	std::cout << "* " << std::setfill(' ') << std::setw(19) << "Press S to increment the hour" << std::setw(6) << "*" << std::endl;

	std::cout << "* " << std::setfill(' ') << std::setw(15) << "Press Q to quit" << std::setw(20) << "*" << std::endl;

	std::cout << std::setfill('*') << std::setw(37) << "" << std::endl;
}
// TODO: GET USERINPUT
void Driver::run()
{
	Clock militaryClock(23, 55, 55);
	MeridianClock normalClock(23, 55, 55);
	char userInput;
	do
	{
		// Clear Screen
		system("CLS");
		// Print Clocks
		std::cout << militaryClock.getTime() << std::endl;
		std::cout << normalClock.getTime() << std::endl;
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
		if (userInput != 'q')
		{
			system("Pause");
		}


	} while (userInput != 'q');
}
