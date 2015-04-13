#pragma once
class BoundingBox
{
public:

	int top;
	int bottom;
	int left;
	int right;

	BoundingBox getBoundingBox(int top, int bottom, int left, int right);

};

