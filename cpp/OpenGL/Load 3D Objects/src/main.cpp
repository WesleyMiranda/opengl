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



int carregaObjeto(const char* nomeArq)
{
	vector<string> linhas;//linhas do arquivo
	vector<Coord3d> vertice;
	vector<Coord3d> normal;
	vector<Face> faces;

	ifstream arq;

	arq.open(nomeArq);
	if (!arq.is_open())
		cout << "Erro ao abrir o arquivo!" << endl;


	while (arq.good())
	{
		string linha;
		getline(arq, linha);
		linhas.push_back(linha);
	}

	for (int i = 0; i < linhas.size(); i++)
	{
		if (linhas[i][0] == '#')
			continue;
		else if (linhas[i][0] == 'v' && (linhas[i])[1] == ' ')
		{
			vertice.push_back(getVertex(linhas[i]));
		}
		else if ((linhas[i][0] == 'v') && (linhas[i][1] == 'n'))
		{
			normal.push_back(getNormal(linhas[i]));
		}
		else if (linhas[i][0] == 'f')
		{
			int a, b, c, d, e;
			if (count(linhas[i].begin(), linhas[i].end(), ' ') == 4)
			{
				faces.push_back(getFace(linhas[i], true));
			}
			else
			{
				faces.push_back(getFace(linhas[i], false));
			}
		}
	}

	//Desenha
	int num;
	num = glGenLists(1);
	glNewList(num, GL_COMPILE);
	for (int i = 0; i < faces.size(); i++)
	{
		if (faces[i].quad)
		{
			glBegin(GL_QUADS);
			glNormal3f(normal[faces[i].facenum - 1].x, normal[faces[i].facenum - 1].y, normal[faces[i].facenum - 1].z);
			glVertex3f(vertice[faces[i].vertices[0] -1].x, vertice[faces[i].vertices[0] - 1].y, vertice[faces[i].vertices[0] - 1].z);
			glVertex3f(vertice[faces[i].vertices[1] -1].x, vertice[faces[i].vertices[1] - 1].y, vertice[faces[i].vertices[1] - 1].z);
			glVertex3f(vertice[faces[i].vertices[2] -1].x, vertice[faces[i].vertices[2] - 1].y, vertice[faces[i].vertices[2] - 1].z);
			glVertex3f(vertice[faces[i].vertices[3] -1].x, vertice[faces[i].vertices[3] - 1].y, vertice[faces[i].vertices[3] - 1].z);
			glEnd();
		}
		else {
			glBegin(GL_TRIANGLES);
			glNormal3f(normal[faces[i].facenum - 1].x, normal[faces[i].facenum - 1].y, normal[faces[i].facenum - 1].z);
			glVertex3f(vertice[faces[i].vertices[0] - 1].x, vertice[faces[i].vertices[0] - 1].y, vertice[faces[i].vertices[0] - 1].z);
			glVertex3f(vertice[faces[i].vertices[1] - 1].x, vertice[faces[i].vertices[1] - 1].y, vertice[faces[i].vertices[1] - 1].z);
			glVertex3f(vertice[faces[i].vertices[2] - 1].x, vertice[faces[i].vertices[2] - 1].y, vertice[faces[i].vertices[2] - 1].z);

			glEnd();
		}
	}
	glEndList();

	// Apagar o vetor
	vertice.clear();
	normal.clear();
	faces.clear();

	//
	cout << num;
	return num;
}


void desenha()
{

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glLoadIdentity();
	float pos[] = { 2,2,5,1 };
	glLightfv(GL_LIGHT0, GL_POSITION, pos);

	glTranslatef(0, 0, -5);
	glRotatef(ang, 1, 1, 1);

	glCallList(objeto);

	glutSwapBuffers();

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
	objeto = carregaObjeto("3D Objects/monkey.obj");
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
