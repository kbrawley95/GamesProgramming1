#pragma once
#include "Common.h"
#include "Sprite.h"
#include "CircleCollider.h"
#include "Collider.h"

class BoundingBox:public Collider
{
public:
	Sprite* sprite;

	vec2 size;

	void Update();

	BoundingBox();
	~BoundingBox();

};

