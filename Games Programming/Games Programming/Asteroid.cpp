#include "Asteroid.h"

float speed = rand() % (7 + 5);

Asteroid::Asteroid(Input* input) :Sprite(input)
{
	Sprite::input = input;
}

Asteroid::Asteroid()
{
	
}

Asteroid::~Asteroid()
{

}


void Asteroid::Update()
{
	Rotation += 16;
	
	Position.y += speed;
	
	if (Position.y > 768)
	{
		Position = vec2(rand() % (1024 - 100), -100);
	}

}

void Asteroid::setBoundingBox(BoundingBox boundingBox)
{
	_boundingBox = boundingBox;
}

