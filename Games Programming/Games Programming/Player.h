#pragma once
#include "Sprite.h"

class Player: public Sprite
{
public:
	void Update();

	Player(Input* input);
	~Player();
};

