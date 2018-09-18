#pragma once
#include "Character.h"

class Player : public Character
{
public:
	Player(DrawAPI* api);
	~Player();
	void Draw() override;
private:
	DrawAPI* api;
};

