#include<glut.h>

float xmin=-5;
float xmax=5;
float ymin=-1;
float ymax=1.5;


class Ponto2D{
	public:
		float x;
		float y;
	
	Ponto2D()
	{
		x=0;
		y=0;
	}
	Ponto2D(float x_, float y_)
	{
		x=x_;
		y=y_;
	}	
};


float fx(float x)
{
	return 1.0/(1.0+x*x); 	
}

void desenha_fx()
{
	int nSubIntervalos=100;
	int nPts=nSubIntervalos+1;
	float x=xmin;
	float incr=(xmax-xmin)/nSubIntervalos;
	glColor3f(1,1,1);
	glBegin(GL_LINE_STRIP);		
	for(int i=1; i<=nPts; i++)
		{
			float y=fx(x);
			glVertex2f(x,y);
			x+=incr;	
		}				
	glEnd();
}

void Eixo(Ponto2D P1, Ponto2D P2)
{
	glColor3f(0,0,1);
	glLineWidth(3.0);
	glBegin(GL_LINES);
		glVertex2f(P1.x,P1.y);
		glVertex2f(P2.x,P2.y);
	glEnd();	
}

void desenha_Eixos()
{
	Ponto2D P1(xmin, 0);
	Ponto2D P2(xmax,0);
	Ponto2D Q1(0,ymin);
	Ponto2D Q2(0,ymax);
	
	Eixo(P1,P2);
	Eixo(Q1,Q2);
	
}

void desenha()
{
	desenha_Eixos();
	desenha_fx();
	//glFlush();
	glutSwapBuffers();
}
int main(int argc, char* argv[])
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	//glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
	glutInitWindowSize(800,600);
	glutCreateWindow("Desenha Funcao");
	glClearColor(0,0,0,0);
	
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluOrtho2D(xmin,xmax,ymin, ymax);
	
	glutDisplayFunc(desenha);
	glutMainLoop();
		
	return 0;
}
