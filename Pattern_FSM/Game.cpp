#include "Game.h"
#include "JumpCommand.h"
#include "CrouchCommand.h"
#include "FireCommand.h"
#include "MeleeCommand.h"
#include "ShieldCommand.h"


Game::Game()
{
	m_inputHandler = std::unique_ptr<InputHandler>(new InputHandler());
	m_player = std::unique_ptr<Player>(new Player());
	m_inputHandler->bindSpace(new JumpCommand());
	m_inputHandler->bindC(new CrouchCommand());
	m_inputHandler->bindX(new ShieldCommand());
	m_inputHandler->bindMouseLeft(new FireCommand());
	m_inputHandler->bindMouseRight(new MeleeCommand());
	m_wallTextures.push_back(NULL);
	m_wallTextures.push_back(NULL);


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
			//Main loop flag
			bool quit = false;

			//Event handler
			SDL_Event e;

			//While application is running
			while (!quit)
			{
				//Handle events on queue
				while (SDL_PollEvent(&e) != 0)
				{
					//User requests quit
					if (e.type == SDL_QUIT)
					{
						quit = true;
					}
					switch (e.type)
					{
					case SDL_KEYDOWN:
						if (e.key.keysym.sym == SDLK_DOWN)
						{

						}
						if (e.key.keysym.sym == SDLK_ESCAPE) //if escape pressed undo last command
						{
							if (nullptr != m_playerCommand)
							{
								m_playerCommand->undo(*m_player);
							}
						}
						m_playerCommand = m_inputHandler->handleKeyboardInput(e.key.keysym);
						if (m_playerCommand)
						{
							m_playerCommand->execute(*m_player);
						}
						break;
					case SDL_MOUSEBUTTONDOWN:
						m_playerCommand = m_inputHandler->handleMouseInput(e.button.button);
						if (m_playerCommand)
						{
							m_playerCommand->execute(*m_player);
						}
						break;
					default:
						break;
					}
				}

				draw();
			}
		}
	}

	//Free resources and close SDL
	close();
} 


Game::~Game()
{
	if (nullptr != m_playerCommand)
	{
		delete m_playerCommand;
	}
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
	gTexture2 = loadTexture("x.bmp");
	if (gTexture2 == NULL)
	{
		printf("Failed to load texture image x.png!\n");
		success = false;
	}
	m_playerIdle = loadTexture("idle.png");
	if (m_playerIdle == NULL)
	{
		printf("Failed to load texture image idle.png!\n");
		success = false;
	}
	m_playerJump = loadTexture("jump.png");
	if (m_playerIdle == NULL)
	{
		printf("Failed to load texture image jump.png!\n");
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