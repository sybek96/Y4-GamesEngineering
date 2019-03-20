#include "Point.h"

Point::Point(int x = 0, int y = 0)
{
	position = Vector2D(x, y);
}

void Point::draw(SDL_Renderer * renderer)
{
	SDL_SetRenderDrawColor(renderer, r, g, b, a);
	SDL_RenderDrawPoint(renderer, position.x, position.y);
}
