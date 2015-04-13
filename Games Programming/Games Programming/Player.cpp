#include "Player.h"


Player::Player(Input* input) : Sprite(input)
{
	Sprite::input = input;
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
}
//Where is the code where if you press space it goes to the next scene?