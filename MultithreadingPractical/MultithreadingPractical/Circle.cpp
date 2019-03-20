#include "Circle.h"

Circle::Circle(int r)
	: radius(r)
{
	////set origin of the circle to be its center rather than top left
	//setOrigin(r, r);
}

void Circle::draw(SDL_Renderer * renderer)
{
	SDL_SetRenderDrawColor(renderer, r, g, b, a);
	for (int w = 0; w < radius * 2; w++)
	{
		for (int h = 0; h < radius * 2; h++)
		{
			int dx = radius - w; // horizontal offset
			int dy = radius - h; // vertical offset
			if ((dx*dx + dy * dy) <= (radius * radius))
			{
				SDL_RenderDrawPoint(renderer, position.x + dx, position.y + dy);
			}
		}
	}
}


