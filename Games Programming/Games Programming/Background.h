#pragma once
#include "Sprite.h"

class Background : public Sprite
{
public:
	void Update();

	float speed;

	Background(Input* input);
	~Background();
};