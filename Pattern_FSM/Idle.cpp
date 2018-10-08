#include "Idle.h"
#include "Jumping.h"
#include "Firing.h"
#include "Crouching.h"
#include "Shielding.h"
#include "Meleeing.h"

Idle::Idle()
{
}


Idle::~Idle()
{
}

void Idle::handleInput()
{
}

void Idle::update()
{
}

void Idle::jumping(Animation* a)
{
	std::cout << "Idle -> Jumping" << std::endl;
	a->setCurrent(new Jumping());
	delete this;
}

void Idle::crouching(Animation* a)
{
	std::cout << "Idle -> Crouching" << std::endl;
	a->setCurrent(new Crouching());
	delete this;
}

void Idle::shielding(Animation* a)
{
	std::cout << "Idle -> Shielding" << std::endl;
	a->setCurrent(new Shielding());
	delete this;
}

void Idle::meleeing(Animation* a)
{
	std::cout << "Idle -> Meleeing" << std::endl;
	a->setCurrent(new Meleeing());
	delete this;
}

void Idle::firing(Animation* a)
{
	std::cout << "Idle -> Firing" << std::endl;
	a->setCurrent(new Firing());
	delete this;
}
