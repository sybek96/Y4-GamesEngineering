#include "Animation.h"
#include "Idle.h"


Animation::Animation()
	: m_current(new Idle())
{
}


Animation::~Animation()
{
}

void Animation::setCurrent(State * s)
{
	m_current = s;
}

void Animation::setPrevious(State * s)
{
	m_previous = s;
}

State * Animation::getCurrent()
{
	return m_current;
}

State * Animation::getPrevious()
{
	return m_previous;
}

void Animation::idle()
{
	m_current->idling(this);
}

void Animation::jumping()
{
	m_current->jumping(this);
}

void Animation::climbing()
{
}
