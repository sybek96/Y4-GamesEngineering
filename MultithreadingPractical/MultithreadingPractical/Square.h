#ifndef _SQUARE_H
#define _SQUARE_H

#include "Primitive.h"
#include "Line.h"
class Square : public Primitive {
public:
	Square(bool _hasBorder = false);
	~Square() = default;
	void draw(SDL_Renderer* renderer) override;


#pragma region Getters/Setters
	void setSize(Vector2D _size);
	void setSize(float width, float height);
	const Vector2D& getSize() { return size; }
	virtual void setPosition(Vector2D _position) override;
	virtual  void setPosition(float x, float y) override;

#pragma endregion

private:
	void calculateBorder();
	Vector2D size = Vector2D(100, 100);
	bool hasBorders = false;
	std::vector<std::unique_ptr<Line>> lines;
};
#endif // !_SQUARE_H