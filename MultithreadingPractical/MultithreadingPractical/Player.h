#ifndef _PLAYER_H
#define _PLAYER_H

#include "Square.h"

class Player {
public:
	Player(Vector2D pos);
#pragma region Copy/move constructors
	Player(Player const &) = default;
	Player & operator=(Player const &) = default;

	Player(Player &&) = default;
	Player & operator=(Player &&) = default;
#pragma endregion
	void draw(SDL_Renderer* renderer);
private:
	std::unique_ptr<Square> m_square;
	Vector2D m_position;
};

#endif // !_PLAYER_H
