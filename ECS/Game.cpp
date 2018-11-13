#include "Game.h"

Game::Game()
{
	//init the systems
	m_aiSystem = AISystem();
	m_controlSystem = ControlSystem();
	m_renderSystem = RenderSystem();

	//////////////////////////////
	//create player
	//////////////////////////////
	m_player = std::make_unique<Entity>(Entity());
	HealthComponent hc =  HealthComponent();
	PositionComponent pc =  PositionComponent();
	//controlComponent cc =  controlComponent();
	m_player->addComponent(hc);
	m_player->addComponent(pc);
	//m_player->addComponent(cc);
	m_player->setName("Player");

	//assign player to his systems
	m_renderSystem.addEntity(*m_player);
	//m_controlSystem.addEntity(*m_player);


	//////////////////////////////
	//create dog
	//////////////////////////////
	m_dog = std::make_unique<Entity>(Entity());
	HealthComponent hc1 = HealthComponent();
	PositionComponent pc1 = PositionComponent();
	controlComponent cc1 = controlComponent();
	m_dog->addComponent(hc1);
	m_dog->addComponent(pc1);
	m_dog->addComponent(cc1);
	m_dog->setName("Dog");

	//assign dog to his systems
	m_renderSystem.addEntity(*m_dog);
	//m_aiSystem.addEntity(*m_dog);
	m_controlSystem.addEntity(*m_dog);


	//////////////////////////////
	//create cat
	//////////////////////////////
	m_cat = std::make_unique<Entity>(Entity());
	HealthComponent hc2 = HealthComponent();
	PositionComponent pc2 = PositionComponent();
	m_cat->addComponent(hc2);
	m_cat->addComponent(pc2);
	m_cat->setName("Cat");

	//assign cat to his systems
	m_aiSystem.addEntity(*m_cat);
	m_renderSystem.addEntity(*m_cat);

	//////////////////////////////
	//create alien
	//////////////////////////////
	m_alien = std::make_unique<Entity>(Entity());
	HealthComponent hc3 = HealthComponent();
	PositionComponent pc3 = PositionComponent();
	m_alien->addComponent(hc3);
	m_alien->addComponent(pc3);
	m_alien->setName("Alien");

	//assign alien to his system
	m_aiSystem.addEntity(*m_alien);
	m_renderSystem.addEntity(*m_alien);



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
						break;
					default:
						break;
					}
				}
				update();
				draw();
			}
		}
	}

	//Free resources and close SDL
	close();
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
	return true;
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
	m_player->getComponents().at(1);
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

	//Update screen
	SDL_RenderPresent(gRenderer);
}

void Game::update()
{
	m_aiSystem.update();
	m_renderSystem.update();
	m_controlSystem.update();
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