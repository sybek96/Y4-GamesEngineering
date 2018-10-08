#include "Crouching.h"
#include "Jumping.h"
#include "Idle.h"
#include "Shielding.h"
#include "Meleeing.h"
#include "Firing.h"
#include "Game.h"

Crouching::Crouching()
{
}


Crouching::~Crouching()
{
}

void Crouching::handleInput()
{
}

void Crouching::update()
{
}

void Crouching::jumping(Animation * a)
{
	std::cout << "Crouching -> Jumping" << std::endl;
	a->setCurrent(new Jumping());
	delete this;
}

void Crouching::shielding(Animation * a)
{
	std::cout << "Crouching -> Shielding" << std::endl;
	a->setCurrent(new Shielding());
	delete this;
}

void Crouching::meleeing(Animation * a)
{
	std::cout << "Crouching -> Meleeing" << std::endl;
	a->setCurrent(new Meleeing());
	delete this;
}

void Crouching::firing(Animation * a)
{
	std::cout << "Crouching -> Firing" << std::endl;
	a->setCurrent(new Firing());
	delete this;
}

void Crouching::idle(Animation * a)
{
	std::cout << "Crouching -> Idle" << std::endl;
	a->setCurrent(new Idle());
	delete this;
}
