#pragma once
#include "Sprite.h"
#include "Laser.h"

class EnemyShip: public Sprite
{
private:
	float bulletDelay;
	float shootDelay;
public:
	vector<Laser*> laserBeams;

	void Shoot();

	void Update();

	void UpdateBullets();
	void RenderBullets();

	EnemyShip();
	~EnemyShip();

	
};

