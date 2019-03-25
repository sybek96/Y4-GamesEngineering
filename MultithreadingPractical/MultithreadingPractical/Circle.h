#ifndef _CIRCLE_H
#define _CIRCLE_H

#include "Primitive.h"
#include <cstdint>

class Circle : public Primitive{
public:
	Circle(int r);
	~Circle() = default;
	void draw(SDL_Renderer* renderer) override;

#pragma region Getters/Setters
	const int& getRadius() { return m_radius; }

	void setRadius(const int& radius) { m_radius = radius; }
#pragma endregion

private:
	typedef int32_t s32;
	int m_radius;
};

#endif // !_CIRCLE_H
