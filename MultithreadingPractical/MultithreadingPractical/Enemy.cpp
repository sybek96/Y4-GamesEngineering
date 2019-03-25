#include "Enemy.h"

Enemy::Enemy(Vector2D pos, Vector2D size)
	: m_position(pos)
{
	m_square = std::make_unique<Square>();
	m_square->setRGBA(147, 23, 23);
	m_square->setPosition(m_position);
	m_square->setSize(size);
}

void Enemy::draw(SDL_Renderer * renderer)
{
	m_square->draw(renderer);
}
