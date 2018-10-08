#include "Animation.h"
#include "Idle.h"


Animation::Animation()
	: m_current(new Idle())
{
}


Animation::~Animation()
{
	if (nullptr != m_current)
	{
		delete m_current;
	}
	if (nullptr != m_previous)
	{
		delete m_previous;
	}
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

void Animation::firing()
{
	m_current->firing(this);
}

void Animation::shielding()
{
	m_current->shielding(this);
}

void Animation::meleeing()
{
	m_current->meleeing(this);
}

void Animation::crouching()
{
	m_current->crouching(this);
}
