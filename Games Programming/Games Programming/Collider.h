#pragma once
#include "Sprite.h"

class Collider
{
public:
	bool colliding;

	float top;
	float bottom;
	float right;
	float left;

	virtual void Update()
	{

	}
	virtual bool IsColliding()
	{
		return colliding;
	}

	Collider()
	{
		top = 0;
		left = 0;
		right = 0;
		bottom = 0;
	}
	~Collider()
	{

	}
};