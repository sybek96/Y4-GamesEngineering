#include "Primitive.h"

Primitive::Primitive()
	: r(0)
	, g(0)
	, b(0)
	, a(255)
{
}

void Primitive::setRGBA(int _r, int _g, int _b, int _a)
{
	r = _r;
	g = _g;
	b = _b;
	a = _a;
}

void Primitive::setPosition(Vector2D _position)
{
	position = _position;
}

void Primitive::setPosition(float x, float y)
{
	position.x = x;
	position.y = y;
}
