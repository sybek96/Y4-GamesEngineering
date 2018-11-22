#include "Production.h"


int main()
{
	Production p;
	std::vector<int> numbers;

	//////////////////////////////////////////
	/////   USING IF STATEMENTS FOR TESTS
	//////////////////////////////////////////
	try {
		std::pair<bool, std::vector<int>> inputPair = p.takeInput();
		if (!inputPair.first)
		{
			throw std::string("Input element is not a number, please use only numbers");
		}
		numbers = inputPair.second;
		if (!p.hasUniqueNums(numbers))
		{
			throw std::string("You have repeated a number! Numbers may not repeat.");
		}
		if (!p.has6Elements(numbers))
		{
			throw std::string("Number of parameters is not 6!");
		}
		if (!p.isInRange(numbers))
		{
			throw std::string("Number not within valid range, please use only numbers from 1 to 47");
		}
	}
	catch (std::string exception) {
		std::cout << exception << std::endl;
		std::cout << "press any key to close program" << std::endl;
		system("PAUSE");
		return 0;
	}
	std::cout << "You successfuly input 6 numbers!" << std::endl;
	system("PAUSE");
	return 0;
}