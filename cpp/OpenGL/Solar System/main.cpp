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

void desenha()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glLoadIdentity();

	glTranslatef(0, 0, -15);

	//Sol
	glPushMatrix();
	glRotatef(ang, 0, 1, 0);
	glColor3f(1, 1, 0);
	glutSolidSphere(1, 20, 20);
	glPopMatrix();

	//Mercúrio
	glPushMatrix();
	glColor3f(1, 0, 0);
	glRotatef(ang3, 0, 1, 0);
	glTranslatef(2, 0, 0);
	glutSolidSphere(0.02, 20, 20);
	glPopMatrix();

	//Vênus
	glPushMatrix();
	glColor3f(1, 0.5, 0);
	glRotatef(ang2, 0, 1, 0);
	glTranslatef(2.5, 0, 0);
	glutSolidSphere(0.05, 20, 20);
	glPopMatrix();

	//Terra
	glPushMatrix();
	glColor3f(0, 1, 0.2);
	glRotatef(ang3, 0, 1, 0);
	glTranslatef(3, 0, 0);
	glutSolidSphere(0.1, 20, 20);

	glColor3f(1, 1, 1);
	glRotatef(ang3, 1, 1, 0);
	glTranslatef(0.5, 0, 0);
	glutSolidSphere(0.05, 20, 20);
	glPopMatrix();

	//Marte
	glPushMatrix();
	glColor3f(0.6, 0.5, 0);
	glRotatef(ang2, 0, 1, 0);
	glTranslatef(3.5, 0, 0);
	glutSolidSphere(0.08, 20, 20);
	glPopMatrix();

	//Júpter
	glPushMatrix();
	glColor3f(0.7, 1, 0.2);
	glRotatef(ang, 0, 1, 0);
	glTranslatef(6, 0, 0);
	glutSolidSphere(0.8, 20, 20);
	glPopMatrix();

	//Saturno
	glPushMatrix();
	glColor3f(0.2, 0.7, 0.1);
	glRotatef(ang2, 0, 1, 0);
	glTranslatef(9, 0, 0);
	glutSolidSphere(0.5, 20, 20);
	glPopMatrix();

	//Urano
	glPushMatrix();
	glColor3f(0, 0, 1);
	glRotatef(ang2, 0, 1, 0);
	glTranslatef(11.5, 0, 0);
	glutSolidSphere(0.6, 20, 20);
	glPopMatrix();

	//Netuno
	glPushMatrix();
	glColor3f(0, 1, 0.2);
	glRotatef(ang3, 0, 1, 0);
	glTranslatef(13, 0, 0);
	glutSolidSphere(0.5, 20, 20);
	glPopMatrix();

	//Plutão por que ninguém pode excluir ele do sistema
	glPushMatrix();
	glColor3f(1, 1, 1);
	glRotatef(ang, 0, 1, 0);
	glTranslatef(14, 0, 0);
	glutSolidSphere(0.02, 20, 20);
	glPopMatrix();

	glBegin(GL_QUADS);
	glVertex3f(1, 2, 0);
	glVertex3f(-1, 2, 0);
	glVertex3f(-1, 4, 4);
	glVertex3f(1, 4, 0);
	glEnd();

	glMatrixMode(GL_MODELVIEW);
	gluLookAt(14 * cos(ang), 0, 14 * sin(ang), 0, 0, 0, 1, -1, 0);
	glutSwapBuffers();
}

void move(int valor)
{
	ang += 0.5;
	ang2 += 1.5;
	ang3 += 2.5;
	glutPostRedisplay();
	glutTimerFunc(1000 / FPS, move, 0);
}


int main(int argc, char* argv[]) {

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(LARGURA, ALTURA);
	glutCreateWindow("UFR - Sistema Solar");

	inicia3D();

	glutDisplayFunc(desenha);
	glutTimerFunc(1000 / FPS, move, 0);

	glutMainLoop();
	return 0;
}