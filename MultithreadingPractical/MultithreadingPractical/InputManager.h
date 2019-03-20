#ifndef INPUT_MANAGER_H
#define INPUT_MANAGER_H

#include <SDL.h>
#include <map>

class InputManager
{
public:
	InputManager();

	void update();
	bool isPressed(std::string key);
	bool isDown(std::string key);
private:
	int mouseX, mouseY;
	std::map<std::string, bool> m_current;
	std::map<std::string, bool> m_previous;
	const Uint8* m_keyStates;
};
#endif // !INPUT_MANAGER_H