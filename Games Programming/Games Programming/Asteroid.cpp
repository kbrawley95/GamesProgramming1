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
	

	
	Position.y += speed;
	
	if (Position.y > 599)
	{
		Position = vec2(rand() % (800 - 1), -100);
	}

}

