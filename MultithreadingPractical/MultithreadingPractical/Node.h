#ifndef _NODE_H
#define _NODE_H

#include <memory>
#include "Vector2D.h"
#include "Square.h"

class Node {
public:
	Node(Vector2D position, Vector2D width);
	~Node() = default;


#pragma region Copy/move constructors
	Node(Node const &) = default;
	Node & operator=(Node const &) = default;

	Node(Node &&) = default;
	Node & operator=(Node &&) = default;

#pragma endregion


#pragma region Getters/Setters
	void setPosition(const Vector2D& position) { m_position = position; }
	void setID(const int& id) { m_id = id; }
	void setParent(const std::shared_ptr<Node> & parent) { m_parent = parent; }
	void setBlocked(const bool& blocked) { m_blocked = blocked; }
	void setVisited(const bool& visited) { m_visited = visited; }

	const Vector2D& getPosition() { return m_position; }
	const int& getID() { return m_id; }
	const std::shared_ptr<Node>& getParent() { return m_parent; }
	const bool& isBlocked() { return m_blocked; }
	const bool& isVisited() { return m_visited; }
#pragma endregion

	void draw(SDL_Renderer* renderer);
	void setRGBA(int r, int g, int b, int a = 255);

private:
	Vector2D m_position;
	int m_id;
	std::shared_ptr<Node> m_parent;
	bool m_blocked = false;
	bool m_visited = false;

	std::unique_ptr<Square> m_square;
};

#endif // !_NODE_H
