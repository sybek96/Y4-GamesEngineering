#pragma once
//Common interface of the Subject
class IGraphic
{
public:
	IGraphic() {};
	~IGraphic() {};
	virtual void Draw() = 0;
};

