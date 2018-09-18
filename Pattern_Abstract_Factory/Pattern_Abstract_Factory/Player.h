#pragma once
#include "Character.h"
/// <summary>
/// The child of Character class, the player.
/// will override to do player stuff
/// </summary>
class Player : public Character
{
public:
	Player();
	~Player();
	void draw() override; //the overriden draw function
};

