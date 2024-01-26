#include "Utility.h"

void Utility::printMenu()
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

void Utility::printClocks(Clock militaryClock, MeridianClock standardClock)
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
