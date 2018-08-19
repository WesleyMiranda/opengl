#include<GL/freeglut.h>
#include <iostream>
#include <cstdlib> 
#include<cstdio>
#include <vector>
#include<string>
#include<fstream>
#include<sstream>
#include<algorithm>


using namespace std;

// -lglut32 -lglu32 -lopengl32

const int LARGURA = 800;
const int ALTURA = 600;
const int FPS = 50;

float ang = 0;
int objeto;

struct Coord3d {
	float x, y, z;
	Coord3d(float x_, float y_, float z_)
	{
		x = x_;
		y = y_;
		z = z_;
	}
};





void inicia3D()
{

	glClearColor(0, 0, 0, 1);
	//glClearColor(0.6,0.6,0.6,1);//FOG Color
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45, (double)LARGURA / ALTURA, 1.0, 500);
	glMatrixMode(GL_MODELVIEW);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	float color[] = { 1,1,1,1 };
	glLightfv(GL_LIGHT0, GL_DIFFUSE, color);

	//glEnable(GL_FOG);
	//glFogi(GL_FOG_MODE,GL_LINEAR);
	//glFogf(GL_FOG_START,1.0);
	//glFogf(GL_FOG_END,5.0);
	//float colorFog[]={0.6,0.6,0.6,1.0};
	//glFogfv(GL_FOG_COLOR,colorFog);
	objeto = carregaObjeto("monkey.obj");
}

void teclado(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 27: //Esc
		exit(0);

	}
}

void move(int valor)
{
	ang += 0.5;
	glutPostRedisplay();
	glutTimerFunc(1000 / FPS, move, 0);
}

int main(int argc, char* argv[]) {

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(800, 600);
	glutCreateWindow("UFR - Blender");

	inicia3D();

	glutDisplayFunc(desenha);
	glutKeyboardFunc(teclado);
	glutTimerFunc(1000 / FPS, move, 0);

	glutMainLoop();
	return 0;
}
