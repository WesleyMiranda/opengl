#include<glut.h>
#include"cg.h"


void cgLinha(double x1, double y1, double x2, double y2,MyRGB cor)
{
	glColor3f(cor.R,cor.G,cor.B);
	glLineWidth(3.0);
	glBegin(GL_LINES);
		glVertex2f(x1,y1);
		glVertex2f(x2,y2);
	glEnd();	
}

void cgDesenhaEixos(double xmin_,double xmax_, double ymin_, double ymax_, MyRGB cor)
{
	cgLinha(xmin_,0,xmax_,0, cor);
	cgLinha(0,ymin_,0,ymax_, cor);	
}


void cgCriaPontos(Funcao f, int n, Pontos& P, double xmin_, double xmax_)
{
	int nSubIntervalos=n-1;
	double x=xmin_;
	double y=f(x);
	double incr=(xmax_-xmin_)/nSubIntervalos;
	P.clear();
	for(int i=0; i<n; i++)
	{
		Ponto2 p(x,y);
		//Pts.push_back(p);
		P.push_back(p);
		x+=incr;
		y=f(x);			
	}
	
}

void cgPlotPontos(Pontos P, MyRGB cor)
{
	glColor3f(cor.R,cor.G,cor.B);
	glPointSize(8.0);
	glBegin(GL_POINTS);		
	for(int i=0; i<P.size(); i++)
		{
			glVertex2f(P[i].x,P[i].y);						
		}				
	glEnd();	
}

void cgPlotFunc(Funcao f, double xmin_, double xmax_,MyRGB cor, int n)
{
	int nSubIntervalos=n-1;
	double x=xmin_;
	double y=f(x);
	

	double incr=(xmax_-xmin_)/nSubIntervalos;
	
	glColor3f(cor.R,cor.G,cor.B);
	glBegin(GL_LINE_STRIP);		
	for(int i=1; i<=n; i++)
		{
			glVertex2f(x,y);
			x+=incr;
			y=f(x);			
		}				
	glEnd();
}


void cgText(string mytext, float x,float y)
{
	
	int n=mytext.length();
	
	char text[n+1];
	strcpy(text,mytext.c_str());
	
	glColor3f(0, 0, 0);	
	// Position of the text to be printer
	glRasterPos2f(x,y);
	for(int i = 0; text[i] != '\0'; i++)
    	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);
	
}

