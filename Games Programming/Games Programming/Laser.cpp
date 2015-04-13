#include "Laser.h"


Laser::Laser(Input* input) :Sprite(input)
{
	Sprite::input = input;
	isVisible = false;
}

Laser::Laser()
{

}


Laser::~Laser()
{
}

void Laser::Update()
{
	
}

