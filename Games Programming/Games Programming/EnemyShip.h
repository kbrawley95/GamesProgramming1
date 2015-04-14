#pragma once
#include "Sprite.h"
#include "BoundingBox.h"
#include "Laser.h"

class EnemyShip: public Sprite
{
private:
	float bulletDelay;
public:
	BoundingBox _boundingBox;
	vector<Laser*> laserBeams;

	void setBoundingBox(BoundingBox boundingBox);

	void Shoot();

	void UpdateBullets();
	void RenderBullets();

	EnemyShip();
	~EnemyShip();

	
};

