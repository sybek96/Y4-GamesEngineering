#pragma once
#include "Component.h"
#include <string>
class Entity
{
public:
	Entity() {};
	void removeComponent(Component c) {};
	void addComponent(Component c) { components.push_back(c); }
	std::vector<Component> getComponents() { return components; }
	int getEntityId() { return m_id; }
	void setName(std::string newName) { m_name = newName; }
	std::string getName() { return m_name; }
private:
	std::vector<Component> components;
	int m_id;
	std::string m_name;
};