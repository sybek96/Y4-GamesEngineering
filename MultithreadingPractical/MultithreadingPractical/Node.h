#ifndef _NODE_H
#define _NODE_H

#include <memory>
#include "Vector2D.h"
#include "Square.h"

class Node {
public:
	Node(Vector2D position, Vector2D width, int id);
	~Node() = default;
	struct GreaterThanNode
	{
		bool operator()(const std::shared_ptr<Node>& lhs, const std::shared_ptr<Node>& rhs)
		{
			return lhs->getH() > rhs->getH();
		}
	};


#pragma region Copy/move constructors
	Node(Node const &) = default;
	Node & operator=(Node const &) = default;

	Node(Node &&) = default;
	Node & operator=(Node &&) = default;

#pragma endregion
	//bool operator <(const std::shared_ptr<Node>& other) const;
	//bool operator >(const std::shared_ptr<Node>& other) const;



#pragma region Getters/Setters
	void setPosition(const Vector2D& position) { m_position = position; }
	void setID(const int& id) { m_id = id; }
	void setParent(const std::shared_ptr<Node> & parent) { m_parent = parent; }
	void setBlocked(const bool& blocked) { m_blocked = blocked; }
	void setVisited(const bool& visited) { m_visited = visited; }
	void setG(const int& newG) { g = newG; }
	void setH(const float& newH) { h = newH; }
		
	const Vector2D& getPosition() { return m_position; }
	const int& getID() { return m_id; }
	const std::shared_ptr<Node>& getParent() { return m_parent; }
	const bool& isBlocked() { return m_blocked; }
	const bool& isVisited() { return m_visited; }
	const Vector2D& getSize() { return m_square->getSize(); }
	const int& getF() { return g + h; }
	const int& getG() { return g; }
	const float& getH() { return h; }
#pragma endregion

	void draw(SDL_Renderer* renderer);
	void setRGBA(int r, int g, int b, int a = 255);

	std::vector<std::shared_ptr<Node>> m_adjecancySet;
private:
	Vector2D m_position;
	int m_id;
	
	int g; //accumulated distance from starting node
	float h = 999999.0f; //heuristic to destination
	
	std::shared_ptr<Node> m_parent;
	bool m_blocked = false;
	bool m_visited = false;

	std::unique_ptr<Square> m_square;

};

#endif // !_NODE_H
