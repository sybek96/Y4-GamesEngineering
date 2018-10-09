#include "Player.h"
#include "Idle.h"
#include "Jumping.h"


Player::Player(SDL_Renderer& renderer)
	: m_renderer(renderer)
	, m_animatedSprite(renderer)
{
	m_animation.setCurrent(new Idle());
	m_animation.setPrevious(new Idle());
	m_playerIdle = loadTexture("player_idle.png");
	m_animatedSprite.addAnimRects(199, 288, 5, 4);
	m_playerJump = loadTexture("player_jump_loop.png");
	m_animatedSprite.setCurrentTexture(*m_playerIdle);

}




Player::~Player()
{
}

void Player::jump()
{
	std::cout << "Player has jumped!" << std::endl;
	m_animation.jumping();
	m_animatedSprite.addAnimRects(234, 344, 5, 4);
	m_animatedSprite.setCurrentTexture(*m_playerJump);
}

void Player::fire()
{
	std::cout << "Player has fired!" << std::endl;
	m_animation.firing();
}

void Player::crouch()
{
	std::cout << "Player has crouched!" << std::endl;
	m_animation.crouching();
}

void Player::shield()
{
	std::cout << "Player has shielded!" << std::endl;
	m_animation.shielding();
}

void Player::melee()
{
	std::cout << "Player has used melee!" << std::endl;
	m_animation.meleeing();
}

void Player::update()
{
	m_animatedSprite.update();
}

void Player::draw()
{
	m_animatedSprite.draw();

}

AnimatedSprite & Player::getAnimatedSprite()
{
	int frame = m_animatedSprite.getCurrentFrame();
	
	return m_animatedSprite;
}

SDL_Texture * Player::loadTexture(std::string path)
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
		newTexture = SDL_CreateTextureFromSurface(&m_renderer, loadedSurface);
		if (newTexture == NULL)
		{
			printf("Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
		}

		//Get rid of old loaded surface
		SDL_FreeSurface(loadedSurface);
	}

	return newTexture;
}
