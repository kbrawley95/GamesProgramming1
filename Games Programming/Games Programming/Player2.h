#pragma once
#include "Input.h"
#include "Entity.h"

class Player2: public Entity
{
public:
	float Speed;
	float RotationSpeed;

	void Update();

	Player2(Input* input);
	~Player2();
};