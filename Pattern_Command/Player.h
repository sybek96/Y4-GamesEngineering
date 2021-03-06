#pragma once
#include "Character.h"
#include <iostream>
#include <SDL.h>

/// <summary>
/// The player class, inherits the character class.
/// 
/// </summary>
class Player : public Character
{
public:
	Player();
	~Player();
	void jump() override;
	void fire() override;
	void crouch() override;
	void shield() override;
	void melee() override;
	void update() override;
	void draw() override;
};

