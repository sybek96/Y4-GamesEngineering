#include "Line.h"

Line::Line(Vector2D _p1, Vector2D _p2)
{
	p1 = _p1;
	p2 = _p2;
}

void Line::draw(SDL_Renderer * renderer)
{
	SDL_SetRenderDrawColor(renderer, r, g, b, a);
	SDL_RenderDrawLine(renderer, p1.x, p1.y, p2.x, p2.y);
}
