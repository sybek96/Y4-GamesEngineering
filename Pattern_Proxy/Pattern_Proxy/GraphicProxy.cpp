#include "GraphicProxy.h"



GraphicProxy::GraphicProxy()
{
}


GraphicProxy::~GraphicProxy()
{
}

void GraphicProxy::Draw()
{
	getInstance()->Draw();
}

Graphic * GraphicProxy::getInstance()
{
	if (!graphic)
	{
		graphic = new Graphic();
	}
	return graphic;
}
