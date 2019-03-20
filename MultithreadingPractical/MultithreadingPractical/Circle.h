#ifndef _CIRCLE_H
#define _CIRCLE_H

#include "Primitive.h"
#include <cstdint>

class Circle : public Primitive{
public:
	Circle(int r);
	~Circle() = default;
	void draw(SDL_Renderer* renderer) override;
private:
	void drawCircle(SDL_Renderer* renderer);
	typedef int32_t s32;
	int radius;
};

#endif // !_CIRCLE_H
