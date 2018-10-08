#pragma once
#include "State.h"
class Idle :
	public State
{
public:
	Idle();
	~Idle();
	void handleInput() override;
	void update() override;
	void jumping(Animation* a) override;
	void crouching(Animation* a) override;
	void shielding(Animation* a) override;
	void meleeing(Animation* a) override;
	void firing(Animation* a) override;
};

