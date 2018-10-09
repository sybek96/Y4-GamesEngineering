#pragma once
#include "State.h"
#include "SDL.h"
#include <SDL_image.h>
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

	SDL_Texture* m_texture = NULL;
};

