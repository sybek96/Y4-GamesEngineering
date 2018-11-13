#include <iostream>
#include <assert.h>
#include <vector>
#include "../ProductionProject/Production.h"


using namespace std;
class Production;

int main()
{
	Production p;
	std::vector<int> inputNums;


	//Take in input
	//currently commented since production not existing
	inputNums = p.takeInput();

	int counter = 0;
	for (auto& number : inputNums)
	{
		counter++;
		//assert we only have numbers
		assert(number == floor(number));

		//assert numbers are bettween 1 and 46
		assert(number > 0 && number < 47);

	}
	//assert we have 6 elements
	assert(counter == 6);


	//assert no repeats
	for (int i = 0; i < inputNums.size(); i++)
	{
		for (int j = i + 1; j < inputNums.size(); j++)
		{
			assert(inputNums[i] != inputNums[j]);
		}
	}


}