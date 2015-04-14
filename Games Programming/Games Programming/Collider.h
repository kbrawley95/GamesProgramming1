#pragma once

class Collider
{
public:
	float top;
	float right;
	float left;
	float bottom;

	bool IsColliding;

	Collider()
	{
		IsColliding = false;
		top = 0;
		right = 0;
		left = 0;
		bottom = 0;
	}
	~Collider()
	{
		
	}
};