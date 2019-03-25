#include "InputManager.h"

InputManager::InputManager()
	: mouseX(0.0f)
	, mouseY(0.0f)
{
	m_keyStates = SDL_GetKeyboardState(NULL);

	m_current["Space"] = false;
	m_current["Right-Click"] = false;
	m_current["Left-Click"] = false;
	m_current["W"] = false;
	m_current["S"] = false;
	m_current["A"] = false;
	m_current["D"] = false;
}

void InputManager::update()
{
	m_previous = m_current;
	auto mousePosition = SDL_GetRelativeMouseState(&mouseX, &mouseY);

	m_current["Space"] = m_keyStates[SDL_SCANCODE_SPACE];
	m_current["W"] = m_keyStates[SDL_SCANCODE_W];
	m_current["S"] = m_keyStates[SDL_SCANCODE_S];
	m_current["A"] = m_keyStates[SDL_SCANCODE_A];
	m_current["D"] = m_keyStates[SDL_SCANCODE_D];
}

bool InputManager::isPressed(std::string key)
{
	return m_current[key] && !m_previous[key];
}

bool InputManager::isDown(std::string key)
{
	return m_current[key];
}
