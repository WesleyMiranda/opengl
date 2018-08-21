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


struct Face {
	int facenum;
	bool quad; // topologia eh Quad ou Triângulo?
	int vertices[4];
	Face(int num, int f1, int f2, int f3)
	{
		facenum = num;
		vertices[0] = f1;
		vertices[1] = f2;
		vertices[2] = f3;
		quad = false;// é um triângulo
	}
	Face(int num, int f1, int f2, int f3, int f4)
	{
		facenum = num;
		vertices[0] = f1;
		vertices[1] = f2;
		vertices[2] = f3;
		vertices[3] = f4;
		quad = true;// é um quadrado
	}

};


Coord3d getVertex(string s)
{
	stringstream saved;
	saved << s;
	char c;
	float x, y, z;
	saved >> c >> x >> y >> z;
	Coord3d tmp = Coord3d(x, y, z);
	return tmp;
}

Coord3d getNormal(string s)
{
	stringstream saved;
	saved << s;
	string c;
	float x, y, z;
	saved >> c >> x >> y >> z;
	Coord3d tmp = Coord3d(x, y, z);
	return tmp;
}


Face getFace(string s, bool isQuad)
{
	int a, b, c, d;
	int n;

	if (isQuad)
	{
		Face f = Face(0, 0, 0, 0, 0);
		sscanf_s(s.c_str(), "f %d//%d %d//%d %d//%d %d//%d", &a, &n, &b, &n, &c, &n, &d, &n);
		f.quad = true;
		f.facenum = n;
		f.vertices[0] = a;
		f.vertices[1] = b;
		f.vertices[2] = c;
		f.vertices[3] = d;
		return f;
	}
	else
	{
		Face f = Face(0, 0, 0, 0);
		sscanf_s(s.c_str(), "f %d//%d %d//%d %d//%d", &a, &n, &b, &n, &c, &n);
		f.quad = false;
		f.facenum = n;
		f.vertices[0] = a;
		f.vertices[1] = b;
		f.vertices[2] = c;
		return f;
	}


}



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
