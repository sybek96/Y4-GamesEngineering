#pragma once
#include "Factory.h"
#include "Player.h"
#include "Boss.h"
class CharacterFactory : public Factory
{
public:
	CharacterFactory();
	~CharacterFactory();
	Character* CreatePlayer() override;
	Character* CreateOpponents() override;
};

