#pragma once
#include "State.h"
class Jumping :
	public State
{
public:
	Jumping();
	~Jumping();
	void handleInput() override;
	void update() override;
	void idle(Animation * a);
};

