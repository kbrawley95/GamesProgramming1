#pragma once
#include "Sprite.h"
class Laser:public Sprite
{
public:
	bool isVisible;
	void Update();

	Laser(Input* input);
	Laser();
	~Laser();
};

