#include <GL/freeglut.h>
#include <cmath>
const int LARGURA = 800, ALTURA = 600, FPS = 35;
float ang, ang2, ang3;

void inicia3D()
{
	glClearColor(0, 0, 0, 1);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, //Define o ângulo de visão
		(double) LARGURA/ALTURA,//Razão W/H
		1.0, //menor distância
		500.0); //Maior distância
	glMatrixMode(GL_MODELVIEW);
	glEnable(GL_DEPTH_TEST);
}

void desenhaCubo(float size)
{
	//Right face
	glBegin(GL_QUADS);
	glColor3f(1, 0, 1);
	glVertex3f(size / 2, size / 2, size / 2);
	glVertex3f(size / 2, size / 2, -size / 2);
	glVertex3f(size / 2, -size / 2, -size / 2);
	glVertex3f(size / 2, -size / 2, size / 2);
	glEnd();

	//Left face
	glBegin(GL_QUADS);
	glColor3f(0, 1, 0);
	glVertex3f(-size / 2, size / 2, size / 2);
	glVertex3f(-size / 2, size / 2, -size / 2);
	glVertex3f(-size / 2, -size / 2, -size / 2);
	glVertex3f(-size / 2, -size / 2, size / 2);
	glEnd();

	//Front face
	glBegin(GL_QUADS);
	glColor3f(1, 1, 1);
	glVertex3f(size / 2, size / 2, size / 2);
	glVertex3f(-size / 2, size / 2, size / 2);
	glVertex3f(-size / 2, -size / 2, size / 2);
	glVertex3f(size / 2, -size / 2, size / 2);
	glEnd();

	//Back face
	glBegin(GL_QUADS);
	glColor3f(1, 1, 0);
	glVertex3f(size / 2, size / 2, -size / 2);
	glVertex3f(-size / 2, size / 2, -size / 2);
	glVertex3f(-size / 2, -size / 2, -size / 2);
	glVertex3f(size / 2, -size / 2, -size / 2);
	glEnd();

	//Top face
	glBegin(GL_QUADS);
	glColor3f(0, 0, 1);
	glVertex3f(size / 2, size / 2, size / 2);
	glVertex3f(-size / 2, size / 2, size / 2);
	glVertex3f(-size / 2, size / 2, -size / 2);
	glVertex3f(size / 2, size / 2, -size / 2);
	glEnd();

	//Bottom face
	glBegin(GL_QUADS);
	glColor3f(1, 0, 0);
	glVertex3f(size / 2, -size / 2, size / 2);
	glVertex3f(-size / 2, -size / 2, size / 2);
	glVertex3f(-size / 2, -size / 2, -size / 2);
	glVertex3f(size / 2, -size / 2, -size / 2);
	glEnd();
}

void desenha()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glLoadIdentity();
	desenhaCubo(0.2);

	glutSwapBuffers();
}

int main(int argc, char* argv[]) {

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(LARGURA, ALTURA);
	glutCreateWindow("UFR - Cubo");

	inicia3D();

	glutDisplayFunc(desenha);
	glutTimerFunc(1000 / FPS, move, 0);

	glutMainLoop();
	return 0;
}