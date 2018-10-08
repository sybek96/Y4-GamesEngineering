#include "Idle.h"
#include "Jumping.h"

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
	std::cout << "Idle -> Crouch" << std::endl;
}

void Idle::shielding(Animation* a)
{
	std::cout << "Idle -> Shield" << std::endl;
}

void Idle::meleeing(Animation* a)
{
	std::cout << "Idle -> Melee" << std::endl;
}

void Idle::firing(Animation* a)
{
	std::cout << "Idle -> Fire" << std::endl;
}
