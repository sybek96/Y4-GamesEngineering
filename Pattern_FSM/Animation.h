#pragma once
class Animation
{

private:
	class State* m_current; //m_current prior to setCurrent to avoid circular dependency

	class State* m_previous;
public:
	Animation();
	~Animation();
	void setCurrent(State* s);
	void setPrevious(State* s);
	State* getCurrent();
	State* getPrevious();

	void idle();
	void jumping();
	void firing();
	void shielding();
	void meleeing();
	void crouching();
};

