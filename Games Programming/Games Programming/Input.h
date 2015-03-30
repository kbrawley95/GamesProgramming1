#pragma once
#include "Common.h"
#include "KEYS.h"

class Input
{
private:
	map<KEYS, bool> keysPressed;

public:
	bool GetKey(KEYS k);
	void SetKey(KEYS k, bool b);

	Input();
	~Input();
};