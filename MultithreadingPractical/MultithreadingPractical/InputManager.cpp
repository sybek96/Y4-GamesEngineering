#include "InputManager.h"

InputManager::InputManager()
	: mouseX(0.0f)
	, mouseY(0.0f)
{
	m_keyStates = SDL_GetKeyboardState(NULL);

	m_current["Space"] = false;
	m_current["Right-Click"] = false;
	m_current["Left-Click"] = false;
}

void InputManager::update()
{
	m_previous = m_current;
	auto mousePosition = SDL_GetRelativeMouseState(&mouseX, &mouseY);

	m_current["Space"] = m_keyStates[SDL_SCANCODE_SPACE];
}

bool InputManager::isPressed(std::string key)
{
	return m_current[key] && !m_previous[key];
}

bool InputManager::isDown(std::string key)
{
	return m_current[key];
}
