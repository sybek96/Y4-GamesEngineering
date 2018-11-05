#pragma once
#include "Component.h"
class HealthComponent : public Component
{
public:
	HealthComponent();
	~HealthComponent();
	int getCurrent() { return m_current; }
	void setCurrent(int newHealth) { m_current = newHealth; }
private:
	int m_current;
};

