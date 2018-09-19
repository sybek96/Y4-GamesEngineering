#pragma once
#include "IGraphic.h"
#include "Graphic.h"
//proxy for the graphics (real subject)
//upon first call on the object the proxy creates it in the getInstance if one does not exist
//That is "lazy loading"
class GraphicProxy :
	public IGraphic
{
public:
	GraphicProxy();
	~GraphicProxy();
	void Draw() override;
private:
	Graphic* graphic;
	Graphic*  getInstance();
};

