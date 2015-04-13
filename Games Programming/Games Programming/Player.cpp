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
	if (input->GetKey(KEYS::W) && Position.y<=_boundingBox.top)
	{
		Position += vec2(0, -1);
	}

	if (input->GetKey(KEYS::S) && Position.y >= _boundingBox.bottom)
	{
		Position += vec2(0, 1);
	}

	if (input->GetKey(KEYS::A) && Position.y >= _boundingBox.left)
	{
		Position += vec2(-1, 0);
	}

	if (input->GetKey(KEYS::D) && Position.y <= _boundingBox.right)
	{
		Position += vec2(1, 0);
	}
}
