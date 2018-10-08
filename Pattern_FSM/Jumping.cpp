#include "Jumping.h"
#include "Idle.h"


Jumping::Jumping()
{
}


Jumping::~Jumping()
{
}

void Jumping::handleInput()
{
}

void Jumping::update()
{
}

void Jumping::idle(Animation * a)
{
	std::cout << "Jumping -> Idle" << std::endl;
	a->setCurrent(new Idle());
	delete this;
}
