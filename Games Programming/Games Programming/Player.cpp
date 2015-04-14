#include "Player.h"


Player::Player(Input* input) : Sprite(input)
{
	Sprite::input = input;
	bulletDelay = 1;
}


Player::~Player()
{
}

void Player::setBoundingBox(BoundingBox boundingBox)
{
	_boundingBox = boundingBox;
}

void Player::Update()
{
	if (input->GetKey(KEYS::W) )
	{
		Position += vec2(0, -speed);
	}

	if (input->GetKey(KEYS::S))
	{
		Position += vec2(0, speed);
	}

	if (input->GetKey(KEYS::A) )
	{
		Position += vec2(-speed, 0);
	}

	if (input->GetKey(KEYS::D) )
	{
		Position += vec2(speed, 0);
	}

	if (input->GetKey(KEYS::Space))
	{
		Shoot();
	}

	UpdateBullets();
	RenderBullets();
}

void Player::Shoot()
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
		laser->Position = vec2(Player::Position.x/2+200, Player::Position.y/2+200);

		if (laserBeams.capacity() < 20)
		{
			laser->isVisible = true;
			laserBeams.push_back(laser);
		}

		if (laserBeams.capacity() >=20)
		{
			laserBeams.clear();
		}
		
	}

	//Reset bulletDelay
	if (bulletDelay == 0)
		bulletDelay = 20;

}

void Player::UpdateBullets()
{
	float newSpeed=10;
	

	for (Laser* l : laserBeams)
	{
		l->Position.y= l->Position.y-newSpeed;

	}

}

void Player::RenderBullets()
{
	for (Laser* l: laserBeams)
	{
		l->Render();
	}
}
