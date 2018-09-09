#include<glut.h>
#include<iostream>
#include <cstdlib>
#include <cmath>
#include <vector>

using namespace std;

typedef float(*Funcao )(float);

float xmin=-5;
float xmax=5;
float ymin=-1;
float ymax=1.5;

Funcao f;
int nPts = 5;


struct Ponto2D{
	float x;
	float y;
	/*Ponto2D(float x_, float y_)
	{
		float x = x_;
		float y = y_;
	}
	*/
};

typedef vector<Ponto2D>Pontos;
Pontos nos;

struct RGB{
	float R;
	float G;
	float B;
};

void cgCriarPontos( Funcao f, Pontos& P, int totalpts)
{
	int nSubInt = totalpts - 1;
	float incr = (xmax-xmin)/nSubInt;
	float x=xmin;
	float y=f(x);
	
	P.clear();//Para limpar a lista, caso ela esteja suja.
	
	for(int i=0; i<totalpts; i++)
	{
		Ponto2D Q;
		Q.x=x;
		Q.y=y;
		P.push_back(Q);
		cout<<"x="<<x<<", y="<<y<<endl;
		
		x+=incr;
		y=f(x);
	}
}

float fx(float x)
{
	return 1.0/(1.0+x*x); 	
}

float fx2(float x)
{
	return cos(x); 	
}


void cgPlotPoint(Pontos P)
{
	
	RGB cor  = {1.0, 0.0, 0.0};
	glColor3f(cor.R,cor.G,cor.B);
	
	glPointSize(4.0);
	glBegin(GL_POINTS);	
	for(int i=0; i<P.size(); i++)
		{
			glVertex2f(P[i].x, P[i].y);
			//cout<<"x="<<P[i].x<<", y="<<P[i].y<<endl;
		}				
	glEnd();
}

void Eixo(float x1, float y1, float x2, float y2)
{
	glColor3f(0,0,1);
	glLineWidth(3.0);
	glBegin(GL_LINES);
		glVertex2f(x1,y1);
		glVertex2f(x2,y2);
	glEnd();
	
}

void desenha()
{
	glClear(GL_COLOR_BUFFER_BIT);
	Eixo(xmin,0,xmax,0);
	Eixo(0,ymin,0,ymax);
	cgCriarPontos(f, nos, nPts);
	cgPlotPoint(nos);
	//desenha_fx();
	//glFlush();
	glutSwapBuffers();
}

void esc(unsigned char tecla, int x, int y)
{
	switch(tecla)
	{
		case 27:
			exit(0);
	}
}

void criaPts(int botao, int status, int x, int y)
{
	if(botao==GLUT_LEFT_BUTTON)
		if(status==GLUT_DOWN)
			nPts++;
			
	if(botao==GLUT_RIGHT_BUTTON)
		if(status==GLUT_DOWN)
			if(nPts>5)
				nPts--;
	glutPostRedisplay();			
				
				
}

int main(int argc, char* argv[])
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	//glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
	glutInitWindowSize(800,600);
	glutCreateWindow("Desenha Funcao");
	glClearColor(1,1,1,1);
	
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluOrtho2D(xmin,xmax,ymin, ymax);
	
	//f = fx;
	f = fx2;
	//cout << f(0);
	
	glutDisplayFunc(desenha);
	glutKeyboardFunc(esc);
	glutMouseFunc(criaPts);
	glutMainLoop();
	
	return 0;
}
