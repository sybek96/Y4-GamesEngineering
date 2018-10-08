#include "Firing.h"
#include "Jumping.h"
#include "Crouching.h"
#include "Shielding.h"
#include "Meleeing.h"
#include "Idle.h"


Firing::Firing()
{
}


Firing::~Firing()
{
}

void Firing::handleInput()
{
}

void Firing::update()
{
}

void Firing::jumping(Animation * a)
{
	std::cout << "Firing -> Jumping" << std::endl;
	a->setCurrent(new Jumping());
	delete this;
}

void Firing::crouching(Animation * a)
{
	std::cout << "Firing -> Crouching" << std::endl;
	a->setCurrent(new Crouching());
	delete this;
}

void Firing::shielding(Animation * a)
{
	std::cout << "Firing -> Shielding" << std::endl;
	a->setCurrent(new Shielding());
	delete this;
}

void Firing::meleeing(Animation * a)
{
	std::cout << "Firing -> Meleeing" << std::endl;
	a->setCurrent(new Meleeing());
	delete this;
}

void Firing::idle(Animation * a)
{
	std::cout << "Firing -> Idle" << std::endl;
	a->setCurrent(new Idle());
	delete this;
}

