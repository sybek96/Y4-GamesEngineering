#pragma once
#include "Command.h"
#include <SDL.h>
#include "Character.h"


class InputHandler
{
public:
	InputHandler();
	~InputHandler();
	Command* handleKeyboardInput(SDL_Keysym key);
	Command* handleMouseInput(Uint8 btn);

	void bindSpace(Command* command);
	void bindX(Command* command);
	void bindC(Command* command);
	void bindMouseLeft(Command* command);
	void bindMouseRight(Command* command);

private:
	Command* m_keyboardSpace;
	Command* m_keyboardC;
	Command* m_keyboardX;
	Command* m_mouseRight;
	Command* m_mouseLeft;

};

