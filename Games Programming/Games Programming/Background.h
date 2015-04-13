#pragma once
#include "Sprite.h"

class Background : public Sprite
{
public:
	void Update();

	float speed=3;

	Background(Input* input);
	~Background();
};