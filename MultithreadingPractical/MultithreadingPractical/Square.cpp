#include "Square.h"

Square::Square(bool _hasBorder) 
	: hasBorders(_hasBorder)
{
	lines.reserve(4);
	if (hasBorders)
	{
		calculateBorder();
	}
}

void Square::draw(SDL_Renderer * renderer)
{
	SDL_Rect fillRect = { position.x - origin.x, position.y - origin.y, size.x, size.y };
	SDL_SetRenderDrawColor(renderer, r, g, b, a);
	SDL_RenderFillRect(renderer, &fillRect);
	for (auto & line : lines)
	{
		line->draw(renderer);
	}
}

#pragma region Getters/Setters

void Square::setSize(Vector2D _size)
{
	size = _size;
	if (hasBorders)
	{
		calculateBorder();
	}
}

void Square::setSize(float width, float height)
{
	size = Vector2D(width, height);
	if (hasBorders)
	{
		calculateBorder();
	}
}

void Square::setPosition(Vector2D _position)
{
	Primitive::setPosition(_position);
	if (hasBorders)
	{
		calculateBorder();
	}
}

void Square::setPosition(float x, float y)
{
	Primitive::setPosition(x, y);
	if (hasBorders)
	{
		calculateBorder();
	}
}

#pragma endregion


void Square::calculateBorder()
{
	lines.clear();
	lines.push_back(std::make_unique<Line>(Line(Vector2D(position.x, position.y),
		Vector2D(position.x + size.x, position.y))));
	lines.push_back(std::make_unique<Line>(Line(Vector2D(position.x + size.x, position.y),
		Vector2D(position.x + size.x, position.y + size.y))));
	lines.push_back(std::make_unique<Line>(Line(Vector2D(position.x + size.x, position.y + size.y),
		Vector2D(position.x, position.y + size.y))));
	lines.push_back(std::make_unique<Line>(Line(Vector2D(position.x, position.y + size.y),
		Vector2D(position.x, position.y))));
}

