#include "Input.h"


Input::Input()
{
}


Input::~Input()
{
}

bool Input::GetKey(KEYS k)
{
	return keysPressed[k];
}

void Input::SetKey(KEYS k, bool b)
{
	keysPressed[k] = b;
}