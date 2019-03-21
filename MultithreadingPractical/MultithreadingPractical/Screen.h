#ifndef _SCREEN_H
#define _SCREEN_H
//static class to  access screen width and height
class Screen {
public:
	static int getWidth() { return SCREEN_WIDTH; }
	static int getHeight() { return SCREEN_HEIGHT; }
private:
	Screen() {}
	static int SCREEN_WIDTH;
	static int SCREEN_HEIGHT;
};
#endif // !_SCREEN_H