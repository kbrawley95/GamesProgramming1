#include "Asteroid.h"
#include <ctime>
#include <math.h>
	  

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
	origin.x = Position.x + Scale.x / 2 - 25;
	origin.y = Position.y + Scale.y / 2 - 25;

	clock_t begin = clock();
	clock_t end = clock();

	double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;

	rotationAngle += elapsed_secs;

	Rotation += 20 % (int)rotationAngle;
	
	Position.y += speed;
	 
	if (Position.y > 768)
	{
		Position = vec2(rand() % (1024 - 100), -100);
	}

}