#include "Laser.h"


Laser::Laser(Input* input) :Sprite(input)
{
	Sprite::input = input;
}

Laser::Laser()
{

}


Laser::~Laser()
{
}

void Laser::Update()
{
	if (input->GetKey(KEYS::Space))
	{
		Position += vec2(0,10);
	}
}
