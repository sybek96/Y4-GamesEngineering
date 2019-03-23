#ifndef _ENEMY_H
#define _ENEMY_H

#include "Square.h"

class Enemy {
public:
	Enemy(Vector2D pos);
#pragma region Copy/move constructors
	Enemy(Enemy const &) = default;
	Enemy & operator=(Enemy const &) = default;

	Enemy(Enemy &&) = default;
	Enemy & operator=(Enemy &&) = default;

#pragma endregion

	void draw(SDL_Renderer* renderer);
private:
	std::unique_ptr<Square> m_square;
	Vector2D m_position;
};

#endif // !_ENEMY_H
