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
	Position += vec2(0, 1);
}