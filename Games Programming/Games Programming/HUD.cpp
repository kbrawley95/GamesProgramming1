#include "HUD.h"


HUD::HUD() :Sprite()
{
	score = 0;
}


HUD::~HUD()
{
}

void HUD::Update()
{
	score += 10;

	to_string(score);
}