#pragma once
#include "Common.h"
#include "Input.h"
#include "Texture.h"

class Sprite
{
protected:
	Input* input;
	GLuint GLTextureID;

public:
	//Varibles
	vec2 Position;
	float Rotation;
	vec2 Scale;
	bool IsStatic;

	vec2 PivotOffset;

	//Physics
	vec2 Velocity;
	float Torque;
	float Mass;

	//Methods
	void Render();
	void FixedUpdate();
	void AssignTexture(GLuint t);

	//Virtual
	virtual void Update();

	//Physics
	void AddForce(vec2 f);
	void AddTorque(float t);

	Sprite(Input* input);
	~Sprite();
};