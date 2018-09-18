#pragma once
#include "Character.h"
/// <summary>
/// Child of the Character class the boss
/// will override the draw to do boss stuff
/// </summary>
class Boss : public Character
{
public:
	Boss();
	~Boss();
	void draw() override;
};

