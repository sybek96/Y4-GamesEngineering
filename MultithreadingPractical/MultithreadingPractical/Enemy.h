#ifndef _ENEMY_H
#define _ENEMY_H

#include "Square.h"
#include <iostream>

class Enemy {
public:
	Enemy(Vector2D pos, Vector2D size, int id);
#pragma region Copy/move constructors
	Enemy(Enemy const &) = default;
	Enemy & operator=(Enemy const &) = default;

	Enemy(Enemy &&) = default;
	Enemy & operator=(Enemy &&) = default;

#pragma endregion

	void draw(SDL_Renderer* renderer);
	void update(float dt);

	const int& getNodeID() { return m_nodeID; }

	void setPath(const std::vector<Vector2D> path) { m_pathToGoal = path; }
	const std::vector<Vector2D>& getPath() { return m_pathToGoal; }

	const Vector2D& getPosition() { return m_position; }
	void setPosition(const Vector2D& newPos);
private:
	std::unique_ptr<Square> m_square;
	Vector2D m_position;
	std::vector<Vector2D> m_pathToGoal;
	float m_moveTimer = 0;
	int m_nodeID;

};

#endif // !_ENEMY_H
