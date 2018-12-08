// Desenha Interpolação
#include<glut.h>
#include"cg.h"

float L(int i,float x, Pontos P)
{
	float num=1.0;
	float denom=1.0;
	
	for(int j=0;j<P.size();j++)
		if(j!=i)
		{
			num=num*(x-P[j].x);
			denom=denom*(P[i].x-P[j].x);
		}	
	return num/denom;
}

float Lagrange(float x,Pontos P)
{
	float soma=0.0;
	for(int i=0;i<P.size();i++)
		soma=soma+L(i,x,P)*P[i].y;
	
	return soma;
}

void lagrangePlot(Pontos P,double xmin_, double xmax_,MyRGB cor, int n)
{
	int nSubIntervalos=n-1;
	double x=xmin_;
	double y=Lagrange(x,P);
	
	double incr=(xmax_-xmin_)/nSubIntervalos;
	
	glColor3f(cor.R,cor.G,cor.B);
	glBegin(GL_LINE_STRIP);		
	for(int i=1; i<=n; i++)
		{
			glVertex2f(x,y);
			x+=incr;
			y=Lagrange(x,P);			
		}				
	glEnd();
}



void lagrangeInterpola(Pontos P)
{
	float xmin=P[0].x;
	float xmax=P[P.size()-1].x;
	
	glLineStipple(1, 0xAAAA);
	glEnable(GL_LINE_STIPPLE);  
	MyRGB corLagrange(0,0.0,0.2);
	glLineWidth(2.0);
	lagrangePlot(P,xmin, xmax,corLagrange,150);
	glDisable(GL_LINE_STIPPLE);
	
}
	
