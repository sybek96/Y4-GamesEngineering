#pragma once
#include <iostream>
/// <summary>
/// This is the base character class and is abstract.
/// The draw method is a pure virtual and will be overridden in the inherited classes.
/// </summary>
class Character
{
public:
	Character() {};
	~Character() {};
	virtual void draw() = 0; //pure virtual draw
};

