#include "Common.h"
#include "Input.h"
#include "Sprite.h"
#include "Player.h"
#include "EnemyShip.h"
#include "Background.h"
#include "Asteroid.h"
#include "Laser.h"
#include "HUD.h"


enum States
{
	MainMenu,
	Playing,
	GameOver

};

States gameStates;

//Public Varibles
vector<Sprite*> sprites;
vector<Asteroid*> asteroids;
vector<EnemyShip*> enemyShips;


//Instances
Input* input;
Background* bkGround = new Background(input);
Background* bkGround2 = new Background(input);
Background* bkGround3 = new Background(input);
HUD* hud;
Player* p;



int width = 1024;
int height = 768;

//Open GL Methods
void Reshape(int w, int h);
void Render();
void Update(int i);
void KeyboardUp(unsigned char k, int x, int y);
void KeyboardDown(unsigned char k, int x, int y);
void ChangeScene();
//void glutLeaveMainLoop(void);

int main(int argc, char **argv)
{
	//Initialize Glut
	glutInit(&argc, argv);

	//Initialize Core
	input = new Input();
	gameStates = MainMenu;


	//setup some memory buffers for our display
	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGBA|GLUT_DEPTH);

	//Setup Glut Window
	glutInitWindowSize(width, height);
	glutCreateWindow("Rock N Load");

	/*if (input->GetKey(KEYS::EscapeKey))
	{
		glutLeaveMainLoop();

	mciSendString("open C:\\M0.wav alias MY_SND");
	mciSendString("play MY_SND");
	mciSendString("pause MY_SND");
	mciSendString("resume MY_SND");
	mciSendString("stop MY_SND");
	*/


	//Setup OpenGL Methods
	glutReshapeFunc(Reshape);
	ChangeScene();
	glutTimerFunc(10, Update, 0);
	glutKeyboardUpFunc(KeyboardUp);
	glutKeyboardFunc(KeyboardDown);
	glutDisplayFunc(Render);

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

//Change scene, destroys the old one (frees up space in memory)
void ChangeScene()
{
	sprites.clear();
	enemyShips.clear();
	asteroids.clear();

	switch (gameStates)
	{

		case MainMenu:
		{
			mciSendString("open Audio\\goinghigher.mp3 type mpegvideo alias song1", NULL, 0, 0);
			mciSendString("play song1", NULL, 0, 0);

			
			//Background 1
			Texture* bkGroundTexture = new Texture("Images/space.jpg");
			bkGround->AssignTexture(bkGroundTexture->getTexture());
			bkGround->Scale = vec2(width * 2, height * 2);
			bkGround->Position = vec2(0, 0);
			sprites.push_back(bkGround);

			//Background2
			Texture* bkGroundTexture2 = new Texture("Images/space.jpg");
			bkGround2->AssignTexture(bkGroundTexture2->getTexture());
			bkGround2->Scale = vec2(width * 2, height * 2);
			bkGround2->Position = vec2(0, 0);
			sprites.push_back(bkGround2);


			//Text Overly
			Texture* bkGroundTexture3 = new Texture("Images/MainMenu.png");
			bkGround3->AssignTexture(bkGroundTexture3->getTexture());
			bkGround3->Scale = vec2(width  , height  );
			bkGround3->Position = vec2(width/2, height/2);
			bkGround3->speed = 0;
			sprites.push_back(bkGround2);
			break;
				
		}
		case Playing:
		{
			mciSendString("stop song1", NULL, 0, 0);
			mciSendString("open Audio\\rumble.mp3 type mpegvideo alias song2", NULL, 0, 0);
			mciSendString("play song2", NULL, 0, 0);

			//Background 1
			Texture* bkGroundTexture = new Texture("Images/space.jpg");
			bkGround->AssignTexture(bkGroundTexture->getTexture());
			bkGround->Scale = vec2(width * 2, height * 2);
			bkGround->Position = vec2(0, 0);
			sprites.push_back(bkGround);

			//Background2
			Texture* bkGroundTexture2 = new Texture("Images/space.jpg");
			bkGround2->AssignTexture(bkGroundTexture2->getTexture());
			bkGround2->Scale = vec2(width * 2, height * 2);
			bkGround2->Position = vec2(0, 0);
			sprites.push_back(bkGround2);

			//Player Ship
			Texture* t = new Texture("Images/ship.png");
			Player* p = new Player(input);
			p->AssignTexture(t->getTexture());
			p->AddCollision(50);
			p->Scale = vec2(50, 50);
			p->Position = vec2(400, 500);
			sprites.push_back(p);


			//Enemy Ships
			for (int i = 0; i < 3; i++)
			{
				Texture* e = new Texture("Images/enemyship.png");
				enemyShips.push_back(new EnemyShip());
				enemyShips[i]->AssignTexture(e->getTexture());
				enemyShips[i]->Scale = vec2(50, 50);
				enemyShips[i]->Rotation = 0;
				enemyShips[i]->AddCollision(50);
				enemyShips[i]->Position = vec2(rand() % (width + 1), rand() % (-height - (-100)));

			}

			//Asteroids
			for (int i = 0; i < 7; i++)
			{
				Texture* a = new Texture("Images/asteroid.png");
				asteroids.push_back(new Asteroid());
				asteroids[i]->AssignTexture(a->getTexture());
				asteroids[i]->Scale = vec2(120, 120);
				asteroids[i]->Rotation = 0;
				asteroids[i]->AddCollision(50);
				asteroids[i]->Position = vec2(rand() % (width + 1), rand() % (-height - (-100)));
			}

			//HUD 
			Texture* h = new Texture("Images/healthbar.png");
			hud = new HUD();
			hud->AssignTexture(h->getTexture());
			hud->Scale=vec2(228, 20);
			hud->Position=  vec2(128, 10);
			hud->Rotation = 0;
			sprites.push_back(hud);

			
			break;
		}
		case GameOver:
		{	
			mciSendString("stop song2", NULL, 0, 0);
			PlaySound("Audio/gameoversound.wav", NULL, SND_ASYNC | SND_FILENAME);
			//Background 1
			Texture* bkGroundTexture = new Texture("Images/space.jpg");
			bkGround->AssignTexture(bkGroundTexture->getTexture());
			bkGround->Scale = vec2(width * 2, height * 2);
			bkGround->Position = vec2(0, 0);
			sprites.push_back(bkGround);

			//Background2
			Texture* bkGroundTexture2 = new Texture("Images/space.jpg");
			bkGround2->AssignTexture(bkGroundTexture2->getTexture());
			bkGround2->Scale = vec2(width * 2, height * 2);
			bkGround2->Position = vec2(0, 0);
			sprites.push_back(bkGround2);

			break;
		}
	}
}

//Reshapes Window
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


//Draws sprties on screen
void Render()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);


	switch (gameStates)
	{

		case MainMenu:
		{
			bkGround->Render();
			bkGround2 ->Render();
			bkGround3->Render();

			break;
		}

		case Playing:
		{
			//for (list<Entity>::iterator iter=entities.begin();iter!=entities.end();++iter)
			for (Sprite* s : sprites)
			{
				s->Render();
			}

			for (Asteroid* a : asteroids)
			{
				a->Render();
			}

			for (EnemyShip* e : enemyShips)
			{
				e->Render();
			}

			break;
		}

		case GameOver:
		{
			for (Sprite* s : sprites)
			{
				s->Render();
			}
			break;
		}
	}

	

	glutSwapBuffers();
}
	
//Updates game logic
void Update(int i)
{
	switch (gameStates)
	{
		case MainMenu:
		{
			//If the return key is pressed in menu, gameplay is initated
			if (input->GetKey(KEYS::Return))
			{
				if (gameStates != Playing)
				{
					gameStates = Playing;
					ChangeScene();
				}
			}
			bkGround->FixedUpdate();
			bkGround2->FixedUpdate();
			bkGround3->speed = 0;

			break;
		}

		case Playing:
		{
			
			for (Sprite* s : sprites)
			{

				s->FixedUpdate();

			}

			for (Asteroid* a : asteroids)
			{

				a->FixedUpdate();

			}
			for (EnemyShip* e : enemyShips)
			{
				e->FixedUpdate();
			}


			break;
		}
			
		case GameOver:
		{
			for (Sprite* s : sprites)
			{
				s->FixedUpdate();
			}

			break;
		}
	}


	//Collisions
	if (gameStates == Playing)
	{
		//Player Ship/EnemyShip Collision
		for (EnemyShip* e : enemyShips)
		{
			if (glm::distance(e->Position, sprites[2]->Position) < (e->radius + sprites[2]->radius) / 2)
			{
				vec2 normal = glm::normalize(sprites[2]->Position - e->Position);
				sprites[2]->Position += normal;
				//Its colliding

				if (gameStates!=GameOver)
				{
					PlaySound("Audio/explosion.wav", NULL, SND_ASYNC | SND_FILENAME);
					gameStates = GameOver;
					ChangeScene();

				}
				
				
			}
		}
		//Asteroid/Player Collision
		for (Asteroid* a : asteroids)
		{
			if (glm::distance(a->Position, sprites[2]->Position) < (a->radius + sprites[2]->radius) / 2)
			{
				vec2 normal = glm::normalize(sprites[2]->Position - a->Position);
				sprites[2]->Position += normal;
				//Its colliding
				if (gameStates != GameOver)
				{
					PlaySound("Audio/explosion.wav", NULL, SND_ASYNC | SND_FILENAME);
					gameStates = GameOver;
					ChangeScene();

				}
			}
		}

		//Player Laser/Asteroid Collision
		for (Asteroid* a : asteroids)
		{
			Player* p = dynamic_cast<Player*>(sprites[2]);
			for (Laser* l : p->laserBeams)
			{
				if (glm::distance(a->Position, l->Position) < (a->radius + l->radius) / 2)
				{
					PlaySound("Audio/explosion.wav", NULL, SND_ASYNC | SND_FILENAME);
					a->Position = vec2(0, 800);
				}
			}
		}
		//Player Laser/EnemyShip Collision
		for (EnemyShip* e : enemyShips)
		{
			Player* p = dynamic_cast<Player*>(sprites[2]);
			for (Laser* l : p->laserBeams)
			{
				if (glm::distance(e->Position, l->Position) < (e->radius + l->radius) / 2)
				{
					PlaySound("Audio/explosion.wav", NULL, SND_ASYNC | SND_FILENAME);
					e->Position = vec2(0, 800);
				}
			}
		}

		//Enemy Laser/Player Collision
		for (Sprite* s: sprites)
		{
			s=dynamic_cast<Player*>(sprites[2]);

			for (EnemyShip* e: enemyShips)
			{
				for (Laser* l :e->laserBeams )
				{
					if (glm::distance(s->Position, l->Position) < (s->radius + l->radius) / 2)
					{
						if (gameStates != GameOver)
						{
							PlaySound("Audio/explosion.wav", NULL, SND_ASYNC | SND_FILENAME);
							gameStates = GameOver;
							ChangeScene();

						}
						cout << "Player Hit";
					}
				}
			}
			
		}
		
	}

	// Reset timer
	glutTimerFunc( 10, Update, 0);
	//Update the display
	glutPostRedisplay();
}

bool Collision()
{
	return 0;
}

//Sets key pressed to false
void KeyboardUp(unsigned char k, int x, int y)
{
	input->SetKey((KEYS)((int)toupper(k)), false);
}

//Sets key pressed to true
void KeyboardDown(unsigned char k, int x, int y)
{
	input->SetKey((KEYS)((int)toupper(k)), true);
}

