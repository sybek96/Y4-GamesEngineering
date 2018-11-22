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
	std::vector<int> invalidInput = {2,5,6,7,8,'a',2};
	std::vector<int> invalidEmptyInput = {};
	std::vector<int> invalidSingleInput = { 1 };
	int totalTests = 10;
	int counter = 0;

	//////////////////////////////////////////////////
	////   has6Elems tests
	//////////////////////////////////////////////////
	assert(p.has6Elements(validInput));
	counter++;
	assert(!p.has6Elements(invalidInput));
	counter++;
	assert(!p.has6Elements(invalidEmptyInput));
	counter++;
	//////////////////////////////////////////////////
	////   hasUniqueNums tests
	//////////////////////////////////////////////////
	assert(p.hasUniqueNums(validInput));
	counter++;
	assert(!p.hasUniqueNums(invalidInput));
	counter++;
	assert(p.hasUniqueNums(invalidEmptyInput));
	counter++;
	assert(p.hasUniqueNums(invalidSingleInput));
	counter++;
	//////////////////////////////////////////////////
	//// insInRange tests
	//////////////////////////////////////////////////
	assert(p.isInRange(validInput));
	counter++;
	assert(!p.isInRange(invalidInput));
	counter++;
	assert(!p.isInRange(invalidEmptyInput));
	counter++;



	std::cout << counter << "/" << totalTests << " tests passed" << std::endl;
	system("PAUSE");



}