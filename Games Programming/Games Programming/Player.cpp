#include "Player.h"


Player::Player(Input* input) : Sprite(input)
{
	Sprite::input = input;
}


Player::~Player()
{
}

void Player::Update()
{
	if (input->GetKey(KEYS::W))
	{
		Position += vec2(0, -1);
	}

	if (input->GetKey(KEYS::S))
	{
		Position += vec2(0, 1);
	}

	if (input->GetKey(KEYS::A))
	{
		Position += vec2(-1, 0);
	}

	if (input->GetKey(KEYS::D))
	{
		Position += vec2(1, 0);
	}
}
