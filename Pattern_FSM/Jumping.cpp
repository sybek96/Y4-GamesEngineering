#include "Jumping.h"
#include "Idle.h"
#include "Crouching.h"
#include "Shielding.h"
#include "Meleeing.h"
#include "Firing.h"

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

void Jumping::crouching(Animation * a)
{
	std::cout << "Jumping -> Crouching" << std::endl;
	a->setCurrent(new Crouching());
	delete this;
}

void Jumping::shielding(Animation * a)
{
	std::cout << "Jumping -> Shielding" << std::endl;
	a->setCurrent(new Shielding());
	delete this;
}

void Jumping::meleeing(Animation * a)
{
	std::cout << "Jumping -> Meleeing" << std::endl;
	a->setCurrent(new Meleeing());
	delete this;
}

void Jumping::firing(Animation * a)
{
	std::cout << "Jumping -> Firing" << std::endl;
	a->setCurrent(new Firing());
	delete this;
}
