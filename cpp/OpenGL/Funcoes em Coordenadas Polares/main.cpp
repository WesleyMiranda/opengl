#include <glut.h>
#include <cmath>

const float PI = 3.1416;
float tmax=2*PI;
float xmin = -2*PI;
float xmax = 2*PI;
float ymin = -2;
float ymax = 2;

float r(float t){
	return 1-cos(t);
}

void desenha_r()
{
	int nSubInt = 100;
	int nPts = nSubInt + 1;
//	float x = xmin;
	float incr = (tmax-0)/nSubInt;
	glColor3f(1, 1, 1);
	glBegin(GL_LINE_STRIP);
		for(float t=0.0; t<tmax; t+=incr)
		{
			float x=cos(t)*r(t);
			float y=sin(t)*r(t);
			glVertex2f(x, y);
		}
	glEnd();
	 
}

void Eixo(float x1, float y1, float x2, float y2)
{
	glColor3f(0.0, 0.0, 1.0);
	
	glBegin(GL_LINES);
		glVertex2f(x1,y1);
		glVertex2f(x2,y2);
	glEnd();
}

void desenha()
{
	Eixo(xmin, 0, xmax, 0);
	Eixo(0, ymin, 0, ymax);
	desenha_r();
	//	glFlush();
	glutSwapBuffers();
}

int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
//	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
	glutInitWindowSize(800, 800);
	glutCreateWindow("UFMT");
	glClearColor(0,0,0,0);
	
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluOrtho2D(-2, 2, -2, 2);
	
	glutDisplayFunc(desenha);
	glutMainLoop();
	return 0;
}
