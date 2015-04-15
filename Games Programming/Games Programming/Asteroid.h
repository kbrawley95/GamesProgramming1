#pragma once
#include "Sprite.h"

class Asteroid: public Sprite
{
private: 
	vec2 origin;
	float rotationAngle;

public:

	void Update();
	Asteroid();
	Asteroid(Input* input);
	~Asteroid();

};

