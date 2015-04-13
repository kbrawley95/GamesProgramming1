#pragma once
#include "Sprite.h"
class Laser:public Sprite
{
public:

	void Update();

	Laser(Input* input);
	Laser();
	~Laser();
};

