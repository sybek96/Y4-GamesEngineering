#ifndef _LINE_H
#define _LINE_H

#include "Primitive.h"
class Line : public Primitive {
public:
	Line(Vector2D _p1, Vector2D _p2);
	~Line() = default;
	void draw(SDL_Renderer* renderer) override;

#pragma region Getters/Setters

	//getters and setters
	void setP1(Vector2D _p1) { p1 = _p1; }
	void setP1(int x, int y) { p1 = Vector2D(x, y); }
	void setP2(Vector2D _p2) { p2 = _p2; }
	void setP2(int x, int y) { p2 = Vector2D(x, y); }

#pragma endregion
private:
	Vector2D p1, p2;
};
#endif // !_LINE_H