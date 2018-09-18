#pragma once
#include "DrawAPI.h"

/// <summary>
/// Abstract  character class
/// </summary>
class Character
{
public:
	Character() {};
	~Character() {};
	virtual void Draw() = 0;
};

