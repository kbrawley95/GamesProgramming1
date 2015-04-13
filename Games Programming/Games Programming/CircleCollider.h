#pragma once
#include "Sprite.h"

class CircleCollider
{
public:

	float radius;
	vec2 offSet;


	virtual void Update();
	float Distance(vec2 v1, vec2 v2);
	vec2 NormaliseVector(vec2 v);
	bool IsColliding();

	CircleCollider();
	~CircleCollider();
};

