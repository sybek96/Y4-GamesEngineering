#pragma once

#include <iostream>
#include <typeinfo>
#include "Animation.h"
/// <summary>
/// Base state class, interface of state.
/// 
/// </summary>
class State
{
public:
	virtual void handleInput() = 0;

	virtual void update() = 0;

	virtual void idling(Animation* a)
	{
		std::cout << "State::Idling" << std::endl;
	}

	virtual void crouching(Animation* a)
	{
		std::cout << "State::Crouching" << std::endl;
	}
	virtual void firing(Animation* a)
	{
		std::cout << "State::Firing" << std::endl;
	}
	virtual void jumping(Animation* a)
	{
		std::cout << "State::Jumping" << std::endl;
	}
	virtual void shielding(Animation* a)
	{
		std::cout << "State::Shielding" << std::endl;
	}
	virtual void meleeing(Animation* a)
	{
		std::cout << "State::Meleeing" << std::endl;
	}
	virtual void idle(Animation* a)
	{
		std::cout << "State::Idling" << std::endl;
	}
};