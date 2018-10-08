#pragma once
/// <summary>
/// This is a character abstract class,
/// it defines a character in the game
/// it is a base class, an interface fow a game character
/// </summary>
class Character
{
public:
	virtual void update() = 0;
	virtual void draw() = 0;
	virtual void jump() = 0;
	virtual void fire() = 0;
	virtual void crouch() = 0;
	virtual void shield() = 0;
	virtual void melee() = 0;
};

