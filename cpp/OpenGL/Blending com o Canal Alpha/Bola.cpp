#include "Bola.h"
#include<GL/freeglut.h>
#include<cmath>
#include<cstdlib>

extern int LARGURA;
extern int ALTURA;


Vetor::Vetor()
{
    x=LARGURA/2;
    y=ALTURA/2;
}

Vetor::Vetor(float x_, float y_)
{
    x=x_;
    y=y_;
}

Bola::Bola()
{
    set_x(LARGURA/2);
    set_y(ALTURA/2);
    set_raio(8);

	m_cor[0]=1;
	m_cor[1]=0;
	m_cor[2]=0;
	m_cor[3]=0.3;
}

Bola::Bola(float x, float y)
{
	destroi=false;
	set_x(x);
	set_y(y);
	set_raio(5);
	alpha=1;
	m_cor[0]=1;
	m_cor[1]=0;
	m_cor[2]=0;
	m_cor[3]=alpha;
	veloc=Vetor(aleatorio(-0.5,0.5),aleatorio(2,2.5));
}

