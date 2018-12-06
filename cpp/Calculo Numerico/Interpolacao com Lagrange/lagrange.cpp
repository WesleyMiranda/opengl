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

