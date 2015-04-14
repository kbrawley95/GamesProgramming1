#include "BoundingBox.h"


BoundingBox::BoundingBox()
{
}

BoundingBox::~BoundingBox()
{
}


void BoundingBox::Update()
{
	top = sprite->Position.y + (size.y / 2);
	bottom = sprite->Position.y - (size.y / 2);
	right = sprite->Position.x + (size.x / 2);
	left = sprite->Position.x - (size.x / 2);
}

