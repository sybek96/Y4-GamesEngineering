#pragma once
#include "Character.h"
#include <iostream>
#include <SDL.h>
#include "Animation.h"
#include "AnimatedSprite.h"

/// <summary>
/// The player class, inherits the character class.
/// 
/// </summary>
class Player : public Character
{
private:
	Animation m_animation;
	AnimatedSprite m_animatedSprite;
	SDL_Renderer& m_renderer;
	SDL_Texture* m_playerIdle;
	SDL_Texture* m_playerJump;

public:
	Player(SDL_Renderer& renderer);
	~Player();

	void jump() override;
	void fire() override;
	void crouch() override;
	void shield() override;
	void melee() override;
	void update() override;
	void draw() override;
	//void addAnimRects(int width, int height, int framesWidth, int framesHeight);
	SDL_Texture * loadTexture(std::string path);
	AnimatedSprite& getAnimatedSprite();

};

