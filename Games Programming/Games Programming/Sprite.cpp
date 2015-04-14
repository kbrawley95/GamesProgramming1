#include "Sprite.h"


Sprite::Sprite(Input* input)
{
	Sprite::input = input;
	Position = vec2(0, 0);
	Rotation = 0;
	Scale = vec2(10, 10);
	IsStatic = false;
	PivotOffset = vec2(0, 0);
	Velocity = vec2(0, 0);
	Torque = 0;
	Mass = 1;
	speed = 2;
	collisionEnabled = false;
}

Sprite::Sprite()
{

}


Sprite::~Sprite()
{

}

void Sprite::AddCollision(float radius)
{
	Sprite::radius = radius;
	collisionEnabled = true;
}

void Sprite::Render()
{
	glPushMatrix();
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_BLEND);
	
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glBindTexture(GL_TEXTURE_2D, GLTextureID);

	glTranslatef(Position.x, Position.y, 0);
	glRotatef(Rotation, 0, 0, 1);
	glTranslatef((-Scale.x / 2) + PivotOffset.x, (-Scale.y / 2) + PivotOffset.y, 0);
	glScalef(Scale.x, Scale.y, 0);

	glBegin(GL_QUADS);
	
	glColor3f(255, 255, 255);
	
	glTexCoord2i(0, 0);
	glVertex2i(0, 0);
	
	glTexCoord2i(1, 0);
	glVertex2i(1, 0);
	
	glTexCoord2i(1, 1);
	glVertex2i(1, 1);
	
	glTexCoord2i(0, 1);
	glVertex2i(0, 1);


	glEnd();

	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
	Update();
}

void Sprite::Update(){ }

void Sprite::FixedUpdate()
{
	if (!IsStatic)
	{
		Position += Velocity;
		Rotation += Torque;
	}
}

void Sprite::AddForce(vec2 f)
{
	Velocity += f / Mass;
}

void Sprite::AddTorque(float t)
{
	Torque = t / Mass;
}

void Sprite::AssignTexture(GLuint t)
{
	GLTextureID = t;
}
