#ifndef _PLAYER_H
#define _PLAYER_H

#include "Square.h"
#include "Circle.h"

class Player {
public:
	Player(Vector2D pos, int id);
#pragma region Copy/move constructors
	Player(Player const &) = default;
	Player & operator=(Player const &) = default;

	Player(Player &&) = default;
	Player & operator=(Player &&) = default;
#pragma endregion
#pragma region Getters/Setters
	void setTileSize(const Vector2D& size);
	void setPosition(const Vector2D& pos) { m_position = pos; }
	void setNodeID(const int& id) { m_nodeID = id; }
	const Vector2D& getPosition() { return m_position; }
	const int& getNodeID() { return m_nodeID; }
#pragma endregion


	void draw(SDL_Renderer* renderer);
	void update(float dt);
private:
	std::unique_ptr<Circle> m_circle;
	Vector2D tileSize;
	Vector2D m_position;
	int m_nodeID;
};

#endif // !_PLAYER_H
