#include "Shielding.h"
#include "Idle.h"
#include "Jumping.h"
#include "Crouching.h"
#include "Firing.h"
#include "Meleeing.h"


Shielding::Shielding()
{
}


Shielding::~Shielding()
{
}

void Shielding::handleInput()
{
}

void Shielding::update()
{
}

void Shielding::jumping(Animation * a)
{
	std::cout << "Shielding -> Jumping" << std::endl;
	a->setCurrent(new Jumping());
	delete this;
}

void Shielding::crouching(Animation * a)
{
	std::cout << "Shielding -> Crouching" << std::endl;
	a->setCurrent(new Crouching());
	delete this;
}

void Shielding::meleeing(Animation * a)
{
	std::cout << "Shielding -> Meleeing" << std::endl;
	a->setCurrent(new Meleeing());
	delete this;
}

void Shielding::firing(Animation * a)
{
	std::cout << "Shielding -> Firing" << std::endl;
	a->setCurrent(new Firing());
	delete this;
}

void Shielding::idle(Animation * a)
{
	std::cout << "Shielding -> Idle" << std::endl;
	a->setCurrent(new Idle());
	delete this;
}
