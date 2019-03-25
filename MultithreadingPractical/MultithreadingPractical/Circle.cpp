#include "Circle.h"

Circle::Circle(int r)
	: m_radius(r)
{
	////set origin of the circle to be its center rather than top left
	//setOrigin(r, r);
}

void Circle::draw(SDL_Renderer * renderer)
{
	SDL_SetRenderDrawColor(renderer, r, g, b, a);
	for (int w = 0; w < m_radius * 2; w++)
	{
		for (int h = 0; h < m_radius * 2; h++)
		{
			int dx = m_radius - w; // horizontal offset
			int dy = m_radius - h; // vertical offset
			if ((dx*dx + dy * dy) <= (m_radius * m_radius))
			{
				SDL_RenderDrawPoint(renderer, position.x + dx, position.y + dy);
			}
		}
	}
}


