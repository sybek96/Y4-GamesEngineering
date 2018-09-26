#pragma once
#include <SDL.h>
#include <stdio.h>
#include <functional>
#include <SDL_image.h>
#include "InputHandler.h"
#include "Player.h"

class Game
{
public:
	enum class bindCommand {JUMP};
	Game();
	~Game();
	//Starts up SDL and creates window
	bool init();

	//Loads media
	bool loadMedia();

	//Frees media and shuts down SDL
	void close();
private:
	//Screen dimension constants
	const int SCREEN_WIDTH = 640;
	const int SCREEN_HEIGHT = 480;
	//The window we'll be rendering to
	SDL_Window* gWindow = NULL;

	//The surface contained by the window
	SDL_Surface* gScreenSurface = NULL;

	//The image we will load and show on the screen
	SDL_Surface* gXOut = NULL;

	std::unique_ptr<InputHandler> m_inputHandler;

	std::unique_ptr<Player> m_player;

	Command* m_playerCommand;
};

