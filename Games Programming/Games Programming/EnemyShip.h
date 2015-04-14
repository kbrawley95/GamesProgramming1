#pragma once
#include "Sprite.h"
#include "BoundingBox.h"
#include "Laser.h"

class EnemyShip: public Sprite
{
private:
	float bulletDelay;
	float shootDelay;
public:
	BoundingBox _boundingBox;
	vector<Laser*> laserBeams;

	void setBoundingBox(BoundingBox boundingBox);

	void Shoot();

	void Update();

	void UpdateBullets();
	void RenderBullets();

	EnemyShip();
	~EnemyShip();

	
};

