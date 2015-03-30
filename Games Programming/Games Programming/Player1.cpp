#include "Player1.h"

Player1::Player1(Input* input): Entity(input)
{
	Entity::input = input;
	Speed = 1;
	RotationSpeed = 1;
}


Player1::~Player1()
{

}

void Player1::Update()
{
	if (Entity::input->GetKey(KEYS::W))
	{
		Entity::AddForce(vec2(sin(Rotation * 3.14 / 180) * Speed, -cos(Rotation* 3.14 / 180) * Speed));
	}
	else if (Entity::input->GetKey(KEYS::S))
	{
		Entity::AddForce(vec2(-sin(Rotation * 3.14 / 180) * Speed, cos(Rotation* 3.14 / 180) * Speed));
	}

	if (input->GetKey(KEYS::A))
	{
		Entity::Rotation += -RotationSpeed;
	}
	else if (Entity::input->GetKey(KEYS::D))
	{
		Entity::Rotation += RotationSpeed;
	}
}