#include<glut.h>
#include"cg.h"

static Coeficiente a,b,c;


void splinePlotQuad(double ai, double bi, double ci,double xmin_, double xmax_)
{
	double x,y;
	double xi=xmax_;
	int n=10;
	int nSubIntervalos=n-1;
	
	double incr=(xmax_-xmin_)/nSubIntervalos;
	glLineStipple(2, 0xAAAA);
	glEnable(GL_LINE_STIPPLE);  
	glColor3f(0.5,0.2,0.2);
	glBegin(GL_LINE_STRIP);		
	x=xmin_;
	for(int i=1; i<=n; i++)
	{
		y=ai*(x-xi)*(x-xi)+bi*(x-xi)+ci;	
		glVertex2f(x,y);
		x+=incr;		
	}				
	glEnd();	
	glDisable(GL_LINE_STIPPLE);
}


void splineInterpola(Pontos P)
{
	vector<double>h;
	int num=P.size();// numero de Pontos
	h.clear();
	a.clear();
	b.clear();
	c.clear();
	
	for(int i=1;i<num;i++)
		h.push_back(P[i].x-P[i-1].x);
	
	a.push_back(0);//a1=0
	double valor=(P[1].y-P[0].y)/h[1];
	b.push_back(valor); // b1
	
	// Calcula c[i] 
	for(int i=1;i<num;i++)
		c.push_back(P[i].y);
	
	// Calcula b[i]
	for(int i=1;i<num;i++)
	{
		valor=2/h[i]*(P[i+1].y-P[i].y)-b[i-1];
		b.push_back(valor);		
	}
	// Calcula a[i]
	for(int i=1;i<num-1;i++)
	{
		valor=(b[i]-b[i-1])/(2*h[i]);
		a.push_back(valor);		
	}
	
	for(int i=0;i<a.size();i++)
	{
		splinePlotQuad(a[i],b[i],c[i],P[i].x,P[i+1].x);
	
	}		
	
}



