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
	void crouching(Animation* a) override;
	void shielding(Animation* a) override;
	void meleeing(Animation* a) override;
	void firing(Animation* a) override;
};

