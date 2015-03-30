#pragma once
#include "Sprite.h"

class Background : public Sprite
{
public:
	void Update();

	Background(Input* input);
	~Background();
};