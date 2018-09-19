#pragma once
#include "IGraphic.h"
#include <iostream>
//real subject inherits subject interface
class Graphic :
	public IGraphic
{
public:
	Graphic();
	~Graphic();
	void Draw() override;
};

