#include "Common.h"
#include "Input.h"
#include "Sprite.h"
#include "Player.h"
#include "Background.h"
#include "Asteroid.h"

//Public Varibles
vector<Sprite*> sprites;
vector<Asteroid*> asteroids;
Input* input;
int width = 800;
int height = 600;

//Open GL Methods
void Reshape(int w, int h);
void Render();
void Update(int i);
void KeyboardUp(unsigned char k, int x, int y);
void KeyboardDown(unsigned char k, int x, int y);
//void glutLeaveMainLoop(void);

int main(int argc, char **argv)
{
	//Initialize Glut
	glutInit(&argc, argv);

	//Initialize Core
	input = new Input();



	//setup some memory buffers for our display
	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGBA|GLUT_DEPTH);

	//Setup Glut Window
	glutInitWindowSize(width, height);
	glutCreateWindow("Rock N Load");

	/*if (input->GetKey(KEYS::EscapeKey))
	{
		glutLeaveMainLoop();
	}*/

	//Background 1
	Texture* bkGroundTexture = new Texture("Images/space.jpg");
	Background* bkGround = new Background(input);
	bkGround->AssignTexture(bkGroundTexture->getTexture());
	bkGround->Scale = vec2(width * 2, height * 2);
	bkGround->Position = vec2(0, 0);
	sprites.push_back(bkGround);

	//Background2
	Texture* bkGroundTexture2 = new Texture("Images/space.jpg");
	Background* bkGround2 = new Background(input);
	bkGround2->AssignTexture(bkGroundTexture2->getTexture());
	bkGround2->Scale = vec2(width * 2, height * 2);
	bkGround2->Position = vec2(0, 0);
	sprites.push_back(bkGround2);

	//Player Ship
	Texture* t = new Texture("Images/ship.png");
	Player* p = new Player(input);
	p->AssignTexture(t->getTexture());
	p->Scale = vec2(50, 50);
	p->Position = vec2(400, 500);
	sprites.push_back(p);

	//Asteroids
	for (int i = 0; i < 5; i++)
	{
		Texture* a = new Texture("Images/asteroid.png");
		asteroids.push_back(new Asteroid);
		asteroids[i]->AssignTexture(a->getTexture());
		asteroids[i]->Scale = vec2(120, 120);
		asteroids[i]->Position = vec2(rand() % (800 + 1), rand()%(-600-(-100)));
	}

	/*Texture* asteroidTexture = new Texture("Images/asteroid.png");
	Asteroid* a = new Asteroid(input);
	a->AssignTexture(asteroidTexture->getTexture());
	a->Scale = vec2(120, 120);
	a->Position = vec2(rand() % (800 - 1), -100);
	sprites.push_back(a);*/
	

	



	//Setup OpenGL Methods
	glutReshapeFunc(Reshape);
	glutDisplayFunc(Render);
	glutTimerFunc( 10 , Update, 0);
	glutKeyboardUpFunc(KeyboardUp);
	glutKeyboardFunc(KeyboardDown);

	//Very important! This initializes the entry point in the OpenGL driver so we can 
	//call the functions in the api
	GLenum err = glewInit();
	if (GLEW_OK != err)
	{
		fprintf(stderr, "GLEW error");
		return 1;
	}

	//Start up a loop that runs in the background
	glutMainLoop();
	return 0;
}

void Reshape(int w, int h)
{
	width = w;
	height = h;
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	glOrtho(0, w, h, 0, -1, 1);
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glLoadIdentity();
}

void Render()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

	//for (list<Entity>::iterator iter=entities.begin();iter!=entities.end();++iter)
	for (Sprite* s : sprites)
	{
		s->Render();
	}
	for (Asteroid* a : asteroids)
	{
		a->Render();
	}

	glutSwapBuffers();
}
	
void Update(int i)
{
	for (Sprite* s : sprites)
	{
		s->FixedUpdate();
	}

	for (Asteroid* a: asteroids)
	{
		a->FixedUpdate();
	}

	// Reset timer
	glutTimerFunc( 10, Update, 0);
	//Update the display
	glutPostRedisplay();
}

void KeyboardUp(unsigned char k, int x, int y)
{
	input->SetKey((KEYS)((int)toupper(k)), false);
}

void KeyboardDown(unsigned char k, int x, int y)
{
	input->SetKey((KEYS)((int)toupper(k)), true);
}

