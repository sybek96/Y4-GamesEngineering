#include "Player.h"

Player::Player(Vector2D pos, int id)
	: m_position(pos)
	, m_nodeID(id)
	, tileSize(0,0)
{
	m_circle = std::make_unique<Circle>(10);
	m_circle->setPosition(pos + tileSize);
	m_circle->setRGBA(44, 178, 26);
}

void Player::draw(SDL_Renderer * renderer)
{
	m_circle->draw(renderer);
}

void Player::update(float dt)
{
	if (m_circle->getPosition() != m_position + tileSize)
	{
		m_circle->setPosition(m_position + tileSize);
	}
}

void Player::setTileSize(const Vector2D & size)
{
	tileSize = size;
	m_circle->setPosition(m_position + size);
	m_circle->setRadius(size.x);
}


