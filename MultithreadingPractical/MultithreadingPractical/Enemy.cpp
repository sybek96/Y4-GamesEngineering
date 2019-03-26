#include "Enemy.h"

Enemy::Enemy(Vector2D pos, Vector2D size, int id)
	: m_position(pos)
	, m_nodeID(id)
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

void Enemy::update(float dt)
{
	m_moveTimer += dt;
	if (m_pathToGoal.size() > 0 &&  m_moveTimer > 0.1f)
	{
		//set position to front of vector
		setPosition(m_pathToGoal.front());
		m_pathToGoal.erase(m_pathToGoal.begin(), m_pathToGoal.begin() + 1); //delete first element
		m_moveTimer = 0;
	}
}

void Enemy::setPosition(const Vector2D & newPos)
{
	m_position = newPos;
	m_square->setPosition(newPos);
}
