#pragma once
#include "State.h"
class Crouching :
	public State
{
public:
	Crouching();
	~Crouching();
	void handleInput() override;
	void update() override;
	void jumping(Animation* a) override;
	void shielding(Animation* a) override;
	void meleeing(Animation* a) override;
	void firing(Animation* a) override;
	void idle(Animation* a) override;
};

