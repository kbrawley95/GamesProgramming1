#pragma once
#include "Sprite.h"
#include "BoundingBox.h"

class Asteroid :public Sprite
{
private: 
	vec2 origin;
	float rotationAngle;
	float PI = 3.14159265358979323846;

public:
	BoundingBox _boundingBox;

	void setBoundingBox(BoundingBox boundingBox);

	void Update();
	Asteroid();
	Asteroid(Input* input);
	~Asteroid();

};

