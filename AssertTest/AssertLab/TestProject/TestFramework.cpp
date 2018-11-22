#include <iostream>
#include <assert.h>
#include <vector>
#include "../ProductionProject/Production.h"


using namespace std;
class Production;

int main()
{
	Production p;

	std::vector<int> validInput = { 2,5,4,1,6,8 };
	std::vector<int> invalidInput = {2,5,6,7,8,'a'};
	//std::pair<bool, std::vector<int>> inputPair;
	//inputPair.first = false;
	//inputPair.second = invalidInput;
	int totalTests = 6;
	int counter = 0;


	//////////////////////////////////////////////////
	////   VALID INPUT TESTS
	//////////////////////////////////////////////////
	
	//assert numbers are bettween 1 and 46
	assert(p.isInRange(validInput));
	counter++;
	//assert we have 6 elements
	assert(p.has6Elements(validInput));
	counter++;
	//assert no repeats
	assert(p.hasUniqueNums(validInput));
	counter++;
	//////////////////////////////////////////////////
	//// INVALID INPUT TESTS
	//////////////////////////////////////////////////

	//assert numbers are bettween 1 and 46
	assert(!p.isInRange(invalidInput));
	counter++;
	//assert we have 6 elements
	assert(!p.has6Elements(invalidInput));
	counter++;
	//assert no repeats
	assert(!p.hasUniqueNums(invalidInput));
	counter++;
	std::cout << counter << "/" << totalTests << " tests passed" << std::endl;
	system("PAUSE");



}