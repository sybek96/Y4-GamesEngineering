#include "Production.h"


int main()
{
	Production p;
	std::vector<int> numbers = p.takeInput();

	//////////////////////////////////////////
	/////   USING IF STATEMENTS FOR TESTS
	//////////////////////////////////////////
	p.has6Elements(numbers);
	p.isInRange(numbers);
	p.isRepeated(numbers);
	p.onlyNumbers(numbers);

	system("PAUSE");
	return 0;
}