#ifndef _SQUARE_H
#define _SQUARE_H


#include "Primitive.h"
class Square : public Primitive {
public:
	Square();
	~Square() = default;
	void draw(SDL_Renderer* renderer) override;

#pragma region Getters/Setters
	void setSize(Vector2D _size) { size = _size; }
	void setSize(float width, float height) { size = Vector2D(width, height); }
	const Vector2D& getSize() { return size; }

#pragma endregion

private:
	Vector2D size = Vector2D(100, 100);
};
#endif // !_SQUARE_H