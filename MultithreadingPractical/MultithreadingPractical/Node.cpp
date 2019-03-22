#include "Node.h"

Node::Node(Vector2D position, Vector2D size)
	: m_position(position)
	, m_square(std::make_unique<Square>(true))
{
	m_square->setPosition(m_position);
	m_square->setSize(size);
	m_square->setRGBA(255, 255, 255);
}

void Node::draw(SDL_Renderer * renderer)
{
	m_square->draw(renderer);
}

void Node::setRGBA(int r, int g, int b, int a)
{
	m_square->setRGBA(r, g, b, a);
}
