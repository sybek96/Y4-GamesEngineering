#pragma once
#include <SDL.h>
#include <stdio.h>
#include <functional>
#include <SDL_image.h>
#include <memory>
#include <vector>
#include "Entity.h"
#include "Component.h"
#include "HealthComponent.h"
#include "PositionComponent.h"
#include "controlComponent.h"
#include "AISystem.h"
#include "ControlSystem.h"
#include "RenderSystem.h"

class Game
{
public:
	Game();
	~Game();
	//Starts up SDL and creates window
	bool init();

	//Loads media
	bool loadMedia();
	//method to load a texture
	SDL_Texture* loadTexture(std::string path);

	//Frees media and shuts down SDL
	void close();
	//draw method
	void draw();
	void update();

private:
	//Screen dimension constants
	const int SCREEN_WIDTH = 800;
	const int SCREEN_HEIGHT = 600;
	//The window we'll be rendering to
	SDL_Window* gWindow = NULL;

	//The surface contained by the window
	SDL_Surface* gScreenSurface = NULL;

	//The image we will load and show on the screen
	SDL_Surface* gXOut = NULL;

	//The window renderer
	SDL_Renderer* gRenderer = NULL;

	//Current displayed texture
	SDL_Texture* gTexture = NULL;

	SDL_Texture* gTexture2 = NULL;

	std::vector<SDL_Texture*> m_wallTextures;

	std::unique_ptr<Entity> m_player;
	std::unique_ptr<Entity> m_dog;
	std::unique_ptr<Entity> m_cat;
	std::unique_ptr<Entity> m_alien;

	AISystem m_aiSystem;
	RenderSystem m_renderSystem;
	ControlSystem m_controlSystem;
};

