#include "Player.h"



Player::Player()
{
}


Player::~Player()
{
}

void Player::jump()
{
	std::cout << "Player has jumped!" << std::endl;
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
