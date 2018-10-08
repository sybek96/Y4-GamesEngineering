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
}

void Player::draw()
{

}