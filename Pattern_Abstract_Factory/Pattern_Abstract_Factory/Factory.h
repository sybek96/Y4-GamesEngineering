#pragma once
#include "Character.h"
/// <summary>
/// The abstract factory class, it is very generic
/// interface for all of the concrete factories,
/// holds virtual functions of the concrete factories
/// This is the interface to be used when creating objects
/// </summary>
class Factory
{
public:
	Factory();
	~Factory();
	virtual Character* CreatePlayer() = 0;
	virtual Character* CreateOpponents() = 0;
};

