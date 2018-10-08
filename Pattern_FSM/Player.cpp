#include "Player.h"
#include "Idle.h"
#include "Jumping.h"


Player::Player()
{
	m_animation.setCurrent(new Idle());
	m_animation.setPrevious(new Idle());
}


Player::~Player()
{
}

void Player::jump()
{
	std::cout << "Player has jumped!" << std::endl;
	m_animation.jumping();
}

void Player::fire()
{
	std::cout << "Player has fired!" << std::endl;
}

void Player::crouch()
{
	std::cout << "Player has crouched!" << std::endl;
}

void Player::shield()
{
	std::cout << "Player has shielded!" << std::endl;
}

void Player::melee()
{
	std::cout << "Player has used melee!" << std::endl;
}

void Player::update()
{
}

void Player::draw()
{
}
