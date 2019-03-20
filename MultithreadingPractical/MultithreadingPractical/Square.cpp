#include "Square.h"

Square::Square()
{
}

void Square::draw(SDL_Renderer * renderer)
{
	SDL_Rect fillRect = { position.x - origin.x, position.y - origin.y, size.x, size.y };
	SDL_SetRenderDrawColor(renderer, r, g, b, a);
	SDL_RenderFillRect(renderer, &fillRect);
}
