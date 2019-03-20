#include "Game.h"
#include "Time.h"

Game::Game(int fps) 
	: m_msPerFrame(1 / fps)
	, m_exit(false)
{
	//Start up SDL and create window
	if (!init())
	{
		printf("Failed to initialize!\n");
	}
	else
	{
		//Load media
		if (!loadMedia())
		{
			printf("Failed to load media!\n");
		}
		else
		{
			SDL_Event e;
			bool quit = 0;
			double dt = 0;
			double frameTime = 0;
			double timer = 0;
			int frames = 0;
			auto now = std::chrono::system_clock::now();
			auto before = std::chrono::system_clock::now();

			while (!m_exit)
			{
				now = std::chrono::system_clock::now();
				dt = std::chrono::duration<double>(now - before).count();
				timer += dt;
				frameTime += dt;

				//Update the game
				update(dt);

				//draw if time reached msperframe
				if (frameTime >= m_msPerFrame)
				{
					processEvents(e);

					//Draw the Game
					draw();
					//take ms from frametime
					frameTime -= m_msPerFrame;
				}

				frames++;

				displayFPS(timer, frames);


				//before time is now
				before = now;
			}
		}
	}

	//Free resources and close SDL
	close();
} 

void Game::processEvents(SDL_Event& e)
{
	//Handle events
	while (SDL_PollEvent(&e) != 0)
	{
		if (e.type == SDL_QUIT)
		{
			m_exit = true;
		}

		if (e.type == SDL_KEYDOWN)
		{
			if (e.key.keysym.sym == SDLK_ESCAPE)
			{
				m_exit = true;
			}
		}
	}
}

void Game::displayFPS(double& timer, int& frames)
{
	//If 1 second passed
	if (timer >= 1.0f)
	{
		timer -= 1;
		std::cout << "Frames per sec: " << frames << "\n";
		frames = 0;
	}
}


Game::~Game()
{
}

bool Game::init()
{
	//Initialization flag
	bool success = true;

	//Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
		success = false;
	}
	else
	{
		//Set texture filtering to linear
		if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
		{
			printf("Warning: Linear texture filtering not enabled!");
		}
		//Create window
		gWindow = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (gWindow == NULL)
		{
			printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
			success = false;
		}
		else
		{
			//Create renderer for window
			gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
			if (gRenderer == NULL)
			{
				printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
				success = false;
			}
			else
			{
				//Initialize renderer color
				SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);

				//Initialize PNG loading
				int imgFlags = IMG_INIT_PNG;
				if (!(IMG_Init(imgFlags) & imgFlags))
				{
					printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
					success = false;
				}
			}
		}
	}

	return success;
}

bool Game::loadMedia()
{
	//Loading success flag
	bool success = true;

	//Load PNG texture
	gTexture = loadTexture("wall.png");
	if (gTexture == NULL)
	{
		printf("Failed to load texture image wall.png!\n");
		success = false;
	}

	return success;
}

void Game::close()
{
	//Free loaded image
	SDL_DestroyTexture(gTexture);
	gTexture = NULL;

	//Destroy window	
	SDL_DestroyRenderer(gRenderer);
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;
	gRenderer = NULL;


	//Quit SDL subsystems
	IMG_Quit();
	SDL_Quit();
}

void Game::update(double dt)
{
	inputHandler.update();
	if (inputHandler.isPressed("Space"))
	{
		std::cout << "PRESSED SPACE" << std::endl;
	}
}


void Game::draw()
{
	//Clear screen
	SDL_RenderClear(gRenderer);

	//Render texture to screen
	SDL_RenderCopy(gRenderer, gTexture, NULL, NULL);
	SDL_Rect* rect = new SDL_Rect();
	rect->h = 100;
	rect->w = 200;
	rect->x = 300;
	rect->y = 200;
	SDL_RenderCopy(gRenderer, gTexture2, NULL, rect);

	for (auto& wall : m_wallTextures)
	{
		SDL_RenderCopy(gRenderer, gTexture2, NULL, rect);
		rect->x += rect->w;
	}	
	SDL_RenderCopy(gRenderer, m_playerIdle, NULL, rect);
	//Update screen
	SDL_RenderPresent(gRenderer);
}

SDL_Texture* Game::loadTexture(std::string path)
{
	//The final texture
	SDL_Texture* newTexture = NULL;

	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load(path.c_str());
	if (loadedSurface == NULL)
	{
		printf("Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError());
	}
	else
	{
		//Create texture from surface pixels
		newTexture = SDL_CreateTextureFromSurface(gRenderer, loadedSurface);
		if (newTexture == NULL)
		{
			printf("Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
		}

		//Get rid of old loaded surface
		SDL_FreeSurface(loadedSurface);
	}
	
	return newTexture;
}