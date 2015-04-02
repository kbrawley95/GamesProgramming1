#pragma once
#include "Sprite.h"

class Asteroid :public Sprite
{
public:
	void Update();
	Asteroid();
	Asteroid(Input* input);
	~Asteroid();

};

