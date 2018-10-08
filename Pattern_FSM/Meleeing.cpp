#include "Meleeing.h"
#include "Jumping.h"
#include "Crouching.h"
#include "Shielding.h"
#include "Idle.h"
#include "Firing.h"



Meleeing::Meleeing()
{
}


Meleeing::~Meleeing()
{
}

void Meleeing::handleInput()
{
}

void Meleeing::update()
{
}

void Meleeing::jumping(Animation * a)
{
	std::cout << "Melee -> Jumping" << std::endl;
	a->setCurrent(new Jumping());
	delete this;
}

void Meleeing::crouching(Animation * a)
{
	std::cout << "Melee -> Crouching" << std::endl;
	a->setCurrent(new Crouching());
	delete this;
}

void Meleeing::shielding(Animation * a)
{
	std::cout << "Melee -> Shielding" << std::endl;
	a->setCurrent(new Shielding());
	delete this;
}

void Meleeing::firing(Animation * a)
{
	std::cout << "Melee -> Firing" << std::endl;
	a->setCurrent(new Firing());
	delete this;
}

void Meleeing::idle(Animation * a)
{
	std::cout << "Melee -> Idle" << std::endl;
	a->setCurrent(new Idle());
	delete this;
}
