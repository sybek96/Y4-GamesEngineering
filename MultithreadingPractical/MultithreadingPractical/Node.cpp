#include "Node.h"

Node::Node(Vector2D position, Vector2D size, int id)
	: m_position(position)
	, m_square(std::make_unique<Square>(false))
	, m_id(id)
{
	m_adjecancySet.reserve(4);
	m_square->setPosition(m_position);
	m_square->setSize(size);
	m_square->setRGBA(192, 196, 192);
}

//bool Node::operator<(const std::shared_ptr<Node>& other) const
//{
//	return h < other->h;
//}
//
//bool Node::operator>(const std::shared_ptr<Node>& other) const
//{
//	return h > other->h;
//}

void Node::draw(SDL_Renderer * renderer)
{
	m_square->draw(renderer);
}

void Node::setRGBA(int r, int g, int b, int a)
{
	m_square->setRGBA(r, g, b, a);
}
