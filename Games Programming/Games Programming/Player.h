#pragma once
#include "Sprite.h"
#include "BoundingBox.h"
#include "Laser.h"

class Player: public Sprite
{
private:

	float bulletDelay;
	


public:
	BoundingBox _boundingBox;
	vector<Laser*> laserBeams;

	void setBoundingBox(BoundingBox boundingBox);

	void Update();

	void Shoot();

	void UpdateBullets();
	void RenderBullets();
	
	Player(Input* input);
	~Player();
};

