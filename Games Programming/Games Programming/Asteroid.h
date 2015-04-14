#pragma once
#include "Sprite.h"
#include "BoundingBox.h"

class Asteroid :public Sprite
{
public:
	BoundingBox _boundingBox;

	void setBoundingBox(BoundingBox boundingBox);

	void Update();
	Asteroid();
	Asteroid(Input* input);
	~Asteroid();

};

