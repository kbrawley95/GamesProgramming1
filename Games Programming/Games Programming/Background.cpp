#include"Background.h"

Background::Background(Input* input) : Sprite(input)
{
	Sprite::input = input;
	speed = 3;
}


Background::~Background()
{
}

void Background::Update()
{
	//Scroll Speed
	Position.y += speed;

	//If the texture reaches the bottom of the screen, reset position
	if (Position.y > 1023)
	{
		Position.y = 0;
	}
}