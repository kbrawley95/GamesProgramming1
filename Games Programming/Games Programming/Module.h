#pragma once
class Module
{
public:
	bool Enabled;

	virtual void Update();

	Module();
	~Module();
};