#include "EnemyShip.h"


EnemyShip::EnemyShip() :  Sprite()
{
	bulletDelay = 1;
}


EnemyShip::~EnemyShip()
{
}

void EnemyShip::Shoot()
{
	//Shoot only if the bullet delay is reset
	if (bulletDelay >= 0)
		bulletDelay--;

	//If bulletDelay is at 0: Create new bullet at player position and add to list

	if (bulletDelay <= 0)
	{
		Texture* l = new Texture("Images/LaserBeam.png");
		Laser* laser = new Laser(input);
		laser->AssignTexture(l->getTexture());
		laser->Scale = vec2(50, 50);
		laser->Position = vec2(EnemyShip::Position.x / 2 + 200, EnemyShip::Position.y / 2);

		if (laserBeams.capacity() < 20)
		{
			laser->isVisible = true;
			laserBeams.push_back(laser);
		}

		if (laserBeams.capacity() >= 20)
		{
			laserBeams.clear();
		}

	}

	//Reset bulletDelay
	if (bulletDelay == 0)
		bulletDelay = 20;
}

void EnemyShip::UpdateBullets()
{

}

void EnemyShip::RenderBullets()
{

}
