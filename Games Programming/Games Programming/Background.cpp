#include"Background.h"

Background::Background(Input* input) : Sprite(input)
{
	Sprite::input = input;
}


Background::~Background()
{
}

void Background::Update()
{
	//Scroll Speed
	Position.y += 3;

	//If the texture reaches the bottom of the screen, reset position
	if (Position.y > 599)
	{
		Position.y = 0;
	}
}