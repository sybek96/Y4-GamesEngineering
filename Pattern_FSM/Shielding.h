#pragma once
#include "State.h"
class Shielding :
	public State
{
public:
	Shielding();
	~Shielding();
	void handleInput() override;
	void update() override;
	void jumping(Animation* a) override;
	void crouching(Animation* a) override;
	void meleeing(Animation* a) override;
	void firing(Animation* a) override;
	void idle(Animation* a) override;
};

