#pragma once
#include "State.h"
class Meleeing :
	public State
{
public:
	Meleeing();
	~Meleeing();
	void handleInput() override;
	void update() override;
	void jumping(Animation* a) override;
	void crouching(Animation* a) override;
	void shielding(Animation* a) override;
	void firing(Animation* a) override;
	void idle(Animation* a) override;
};

