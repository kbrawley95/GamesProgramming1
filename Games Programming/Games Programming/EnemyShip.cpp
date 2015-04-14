#include "EnemyShip.h"


EnemyShip::EnemyShip() :  Sprite()
{
	bulletDelay = 1;
	shootDelay = 1;
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
		Texture* l = new Texture("Images/EnemyLaserBeam.png");
		Laser* laser = new Laser(input);
		laser->AssignTexture(l->getTexture());
		laser->Scale = vec2(50, 50);
		laser->AddCollision(50);
		laser->Position = vec2(EnemyShip::Position.x + Scale.x / 2 - 25, EnemyShip::Position.y + Scale.y / 2 - 25);
		PlaySound("Audio/laser6.wav", NULL, SND_ASYNC | SND_FILENAME);

		if (laserBeams.capacity() < 20)
		{
			laser->isVisible = true;
			laserBeams.push_back(laser);
		}

		if (laserBeams.capacity() > 20)
		{
			laserBeams.clear();
		}

	}

	//Reset bulletDelay
	if (bulletDelay == 0)
		bulletDelay = 20;
}

void EnemyShip::Update()
{
	Position.y += 6;

	if (Position.y > 768)
	{
		Position = vec2(rand() % (1024 - 100), -100);
	}


	if (shootDelay == 0)
	{
		Shoot();
		shootDelay = 20;
	}

	if (shootDelay > 0)
		shootDelay--;



	UpdateBullets();
	RenderBullets();
}

void EnemyShip::UpdateBullets()
{
	float newSpeed = 10;


	for (Laser* l : laserBeams)
	{
		l->Position.y = l->Position.y + newSpeed;
		l->FixedUpdate();

	}



}

void EnemyShip::RenderBullets()
{
	for (Laser* l : laserBeams)
	{
		l->Render();
	}
}
