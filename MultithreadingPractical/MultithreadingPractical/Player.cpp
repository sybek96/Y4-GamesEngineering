#include "Player.h"

Player::Player(Vector2D pos)
	: m_position(pos)
{
	m_square = std::make_unique<Square>();
	m_square->setPosition(pos);
	m_square->setRGBA(44, 178, 26);
}

void Player::draw(SDL_Renderer * renderer)
{
	m_square->draw(renderer);
}
