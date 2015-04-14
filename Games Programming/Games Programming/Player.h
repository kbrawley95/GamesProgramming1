#pragma once
#include "Sprite.h"
#include "Laser.h"

class Player: public Sprite
{
private:

	float bulletDelay;
	


public:
	vector<Laser*> laserBeams;

	void Update();
	void Shoot();
	


	void UpdateBullets();
	void RenderBullets();
	
	Player(Input* input);
	~Player();
};

