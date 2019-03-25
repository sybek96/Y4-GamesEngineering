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
			grid.reset(new Grid(10, 10));

			//setting color of a line (wall)
			for (int i = 11; i < 17; i++)
			{
				grid->getNodes().at(i)->setRGBA(99, 57, 5);
				grid->getNodes().at(i)->setBlocked(true);
			}

			for (int i = 50; i < 56; i++)
			{
				grid->getNodes().at(i)->setRGBA(99, 57, 5);
				grid->getNodes().at(i)->setBlocked(true);
			}
			enemies.push_back(std::make_shared<Enemy>(grid->getNodes().at(5)->getPosition(), grid->getNodes().at(0)->getSize()));
			player.reset(new Player(grid->getNodes().at(70)->getPosition(), 70));
			player->setTileSize(grid->getNodes().at(0)->getSize() / 2);
			SDL_Event e;
			bool quit = 0;
			double dt = 0;
			double frameTime = 0;
			double timer = 0;
			int frames = 0;
			auto now = std::chrono::system_clock::now();
			auto before = std::chrono::system_clock::now();

			#pragma region GameLoop
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

			#pragma endregion
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
		system("CLS");
		std::cout << "Frames per sec: " << frames << "\n";
		frames = 0;
	}
}

void Game::handlePlayerMovement()
{
	if (inputHandler.isPressed("W"))
	{
		auto id = player->getNodeID();
		if (id - 1 >= 0) //check node is within valid range
		{
			auto& newNode = grid->getNodes().at(id - 1);
			if (!newNode->isBlocked() && newNode->getPosition().y < grid->getNodes().at(id)->getPosition().y) //check node not blocked and position is above current
			{
				player->setPosition(newNode->getPosition());
				player->setNodeID(player->getNodeID() - 1);
				std::cout << "CURRENT ID = " << player->getNodeID() << std::endl;
			}
		}
	}
	if (inputHandler.isPressed("S"))
	{
		auto& id = player->getNodeID();
		if (id + 1 < grid->getNodes().size()) //check node is within valid range
		{
			auto& newNode = grid->getNodes().at(id + 1);
			if (!newNode->isBlocked() && newNode->getPosition().y > grid->getNodes().at(id)->getPosition().y) //check node not blocked and position is below current
			{
				player->setPosition(newNode->getPosition());
				player->setNodeID(player->getNodeID() + 1);
				std::cout << "CURRENT ID = " << player->getNodeID() << std::endl;

			}
		}
	}
	if (inputHandler.isPressed("A"))
	{
		auto& id = player->getNodeID();
		auto& gridHeight = grid->getGridHeight();
		if (id - gridHeight >= 0) //check node is within valid range
		{
			auto& newNode = grid->getNodes().at(id - gridHeight);
			if (!newNode->isBlocked())
			{
				player->setPosition(newNode->getPosition());
				player->setNodeID(player->getNodeID() - gridHeight);
				std::cout << "CURRENT ID = " << player->getNodeID() << std::endl;
			}
		}
	}
	if (inputHandler.isPressed("D"))
	{
		auto& id = player->getNodeID();
		auto& gridHeight = grid->getGridHeight();
		if (id + gridHeight < grid->getNodes().size()) //check node is within valid range
		{
			auto& newNode = grid->getNodes().at(id + gridHeight);
			if (!newNode->isBlocked())
			{
				player->setPosition(newNode->getPosition());
				player->setNodeID(player->getNodeID() + gridHeight);
				std::cout << "CURRENT ID = " << player->getNodeID() << std::endl;
			}
		}
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
		gWindow = SDL_CreateWindow("A* Ambush - Sebastian Kruzel", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, Screen::getWidth(), Screen::getHeight(), SDL_WINDOW_SHOWN);
		gScreenSurface = SDL_GetWindowSurface(gWindow);
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
	handlePlayerMovement();

	player->update(dt);
}


void Game::draw()
{
	//Clear screen
	SDL_RenderClear(gRenderer);

	//Render texture to screen
	SDL_RenderCopy(gRenderer, gTexture, NULL, NULL);
	grid->draw(gRenderer);
	player->draw(gRenderer);
	for (auto & enemy : enemies)
	{
		enemy->draw(gRenderer);
	}
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