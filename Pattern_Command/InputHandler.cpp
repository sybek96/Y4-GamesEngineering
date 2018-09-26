#include "InputHandler.h"

InputHandler::InputHandler()
{
	
}

InputHandler::~InputHandler()
{
	if (nullptr != m_keyboardSpace)
	{
		delete m_keyboardSpace;
	}
	if (nullptr != m_keyboardC)
	{
		delete m_keyboardC;
	}	
	if (nullptr != m_keyboardX)
	{
		delete m_keyboardX;
	}	
	if (nullptr != m_mouseRight)
	{
		delete m_mouseRight;
	}	
	if (nullptr != m_mouseLeft)
	{
		delete m_mouseLeft;
	}
}

Command* InputHandler::handleKeyboardInput(SDL_Keysym key)
{
	if (key.sym == SDLK_SPACE)  return m_keyboardSpace; 
	if (key.sym == SDLK_x)  return m_keyboardX; 
	if (key.sym == SDLK_c) return m_keyboardC;
	return nullptr;
}

Command * InputHandler::handleMouseInput(Uint8 key)
{
	if (key == SDL_BUTTON_LEFT) return m_mouseLeft;
	if (key == SDL_BUTTON_RIGHT) return m_mouseRight;
	return nullptr;
}

void InputHandler::bindSpace(Command* command)
{
	m_keyboardSpace = command;
}

void InputHandler::bindX(Command* command)
{
	m_keyboardX = command;
}

void InputHandler::bindC(Command* command)
{
	m_keyboardC = command;
}

void InputHandler::bindMouseLeft(Command * command)
{
	m_mouseLeft = command;
}

void InputHandler::bindMouseRight(Command * command)
{
	m_mouseRight = command;
}
