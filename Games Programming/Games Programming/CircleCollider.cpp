#include "CircleCollider.h"


CircleCollider::CircleCollider()
{
	radius = 100;
}


CircleCollider::~CircleCollider()
{
}

void CircleCollider::Update()
{
	IsColliding();
}

bool CircleCollider::IsColliding()
{
	return false;
}
