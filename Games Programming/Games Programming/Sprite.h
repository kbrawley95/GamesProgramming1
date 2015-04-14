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
	float speed;
	bool collisionEnabled;
	vec2 PivotOffset;
	float radius;

	//Physics
	vec2 Velocity;
	float Torque;
	float Mass;

	//Methods
	void Render();
	void FixedUpdate();
	void AssignTexture(GLuint t);
	void AddCollision(float radius);

	//Virtual
	virtual void Update();

	//Physics
	void AddForce(vec2 f);
	void AddTorque(float t);

	//Bounding Box
	void getBoundingRect(RECT* Rect);

	Sprite();
	Sprite(Input* input);
	~Sprite();
};