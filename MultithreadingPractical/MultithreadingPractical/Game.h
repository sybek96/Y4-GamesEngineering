#ifndef GAME_H
#define GAME_H


#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <functional>
#include <vector>
#include <ctime>
#include <chrono>
#include <iostream>
#include "Screen.h"
#include "InputManager.h"
#include "Primitive.h"
#include "Square.h"
#include "Point.h"
#include "Line.h"
#include "Circle.h"
#include "Grid.h"
#include "Enemy.h"
#include "Player.h"

class Game
{
public:
	Game(int fps);
	~Game();
	//Starts up SDL and creates window
	bool init();

	//Loads media
	bool loadMedia();
	//method to load a texture
	SDL_Texture* loadTexture(std::string path);
	void processEvents(SDL_Event& e);
	void displayFPS(double& timer, int& frames);
	void handlePlayerMovement();

	//Frees media and shuts down SDL
	void close();
	//update game
	void update(double dt);
	//draw method
	void draw();

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

	SDL_Texture* m_playerIdle = NULL;

	SDL_Texture* m_playerJump = NULL;

	std::vector<SDL_Texture*> m_wallTextures;
	float m_msPerFrame;
	InputManager inputHandler;
	bool m_exit;

	std::unique_ptr<Grid> grid;
	std::vector<std::shared_ptr<Enemy>> enemies;
	std::unique_ptr<Player> player;

};

#endif // !GAME_H
