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

				//Apply the image
				SDL_BlitSurface(gXOut, NULL, gScreenSurface, NULL);

				//Update the surface
				SDL_UpdateWindowSurface(gWindow);
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
		//Create window
		gWindow = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (gWindow == NULL)
		{
			printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
			success = false;
		}
		else
		{
			//Get window surface
			gScreenSurface = SDL_GetWindowSurface(gWindow);
		}
	}

	return success;
}

bool Game::loadMedia()
{
	//Loading success flag
	bool success = true;

	//Load splash image
	gXOut = IMG_Load("x.bmp");
	if (gXOut == NULL)
	{
		printf("Unable to load image! x.bmp", SDL_GetError());
		success = false;
	}

	return success;
}

void Game::close()
{
	//Deallocate surface
	SDL_FreeSurface(gXOut);
	gXOut = NULL;

	//Destroy window
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;

	//Quit SDL subsystems
	SDL_Quit();
}