#pragma once
#include"Sprite.h"
class HUD:public Sprite
{
public:

	float score;

	void Update();
	HUD();
	~HUD();
};

