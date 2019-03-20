#ifndef _PRIMITIVE_H
#define _PRIMITIVE_H

#include <SDL.h>
#include "Vector2D.h"

class Primitive {
public:
	Primitive();
	~Primitive() = default;
	virtual void draw(SDL_Renderer* renderer) = 0;
	
#pragma region Getters/Setters
	int getR() { return r; }
	int getG() { return g; }
	int getB() { return b; }
	int getA() { return a; }
	void setRGBA(int _r, int _g, int _b, int _a = 255);
	const Vector2D& getPosition() { return position; }
	void setPosition(Vector2D _position);
	void setPosition(float x, float y);
	const Vector2D& getOrigin() { return origin; }
	void setOrigin(Vector2D _origin) { origin = _origin; }
	void setOrigin(float x, float y) { origin = Vector2D(x, y); }

#pragma endregion


protected:
	int r,g,b,a;
	Vector2D position = Vector2D(0.0f,0.0f);
	Vector2D origin = Vector2D(0.0f, 0.0f);
};

#endif // !_PRIMITIVE_H
