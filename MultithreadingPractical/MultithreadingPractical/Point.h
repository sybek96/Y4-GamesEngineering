#ifndef _POINT_H
#define _POINT_H	

#include "Primitive.h"
class Point : public Primitive {
public:
	Point(int x, int y);
	void draw(SDL_Renderer* renderer) override;
private:
};
#endif // !_POINT_H