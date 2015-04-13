#pragma once
#include "Sprite.h"
#include "BoundingBox.h"

class Player: public Sprite
{



public:
	BoundingBox _boundingBox;

	void setBoundingBox(BoundingBox boundingBox);

	void Update();
	
	Player(Input* input);
	~Player();
};

