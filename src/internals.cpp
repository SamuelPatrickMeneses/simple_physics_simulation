#include "./game.hpp"
using game::lifeCicle::step;
using game::properts::positionIteration;
using game::properts::stepDuration;
using game::properts::velocityIteration;

float game::runtimeVariables::lestStep = 0;
int game::runtimeVariables::width = game::properts::width;
int game::runtimeVariables::height = game::properts::height;
b2World *game::physic::world = nullptr;
keyBuffer* game::input::keyboard = nullptr;

using game::physic::world;
using game::runtimeVariables::lestStep;
using game::runtimeVariables::width;
using game::runtimeVariables::height;
using game::input::keyboard;

void game::lifeCicle::config(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitWindowPosition(GLUT_SCREEN_HEIGHT / 2, GLUT_SCREEN_WIDTH / 2);
	glutInitWindowSize(width, height);
	glutInitDisplayMode(GLUT_DOUBLE| GLUT_RGBA);
    glDisable(GL_DEPTH_TEST);
    glClearColor(0x1, 0x1, 0x1, 0x1);
	glutCreateWindow("Test");
	keyboard = new keyBuffer();
	world = new b2World(game::physic::initialGravity);
}
void game::lifeCicle::start()
{
	internalResize(width, height);
	game::lifeCicle::load();
	glutDisplayFunc(internalStep);
	glutKeyboardFunc(internalKeyDown);
	glutReshapeFunc(internalResize);
    glutIgnoreKeyRepeat(GLUT_KEY_REPEAT_OFF);
	glutMainLoop();
	
}

void internalStep(void)
{
	world->Step(stepDuration / 1000, velocityIteration, positionIteration);

	// rotatePoint(point,angle);
	glClear(GL_COLOR_BUFFER_BIT);
	internalResize(width, height);
	
	step();
	keyboard->swap();
	b2Body* bodys = world->GetBodyList();
	do{
		drawBody(bodys);
		bodys = bodys->GetNext();
	}while(bodys != nullptr);
	glutPostRedisplay();
	glutSwapBuffers();
	glFlush();
	long int sleepTime = now() - lestStep + stepDuration;
	sleep(sleepTime);
	lestStep = now();
}

void internalKeyDown(unsigned char key, int x, int y)
{
	if (27 == key)
		exit(0);
	print("------------------------");
		
		keyboard->put(key);
}
void internalResize(int width_, int height_)
{
	glViewport(0, 0, width_, height_);
	width = width_;
	height = height_;
	float aspectw = height / (width * 1.f);
	//float aspecth = width / (height * 1.f);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, 10 / aspectw, 0, 10, 1, -1);
}
