#pragma once
#include "State.h"
class Firing :
	public State
{
public:
	Firing();
	~Firing();
	void handleInput() override;
	void update() override;
	void jumping(Animation* a) override;
	void crouching(Animation* a) override;
	void shielding(Animation* a) override;
	void meleeing(Animation* a) override;
	void idle(Animation* a) override;
};

