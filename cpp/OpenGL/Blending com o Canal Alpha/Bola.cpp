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

Bola::Bola(float x, float y, float r, float cor[4])
{
	set_x(x);
	set_y(y);
	m_raio=r;
    set_cor(cor);
}

Bola::~Bola()
{

}

float Bola::get_raio()
{
    return m_raio;
}

float Bola::get_x()
{
    return m_x;
}

float Bola::get_y()
{
    return m_y;
}

void Bola::set_x(float x)
{
    m_x=x;
}

void Bola::set_y(float y)
{
    m_y=y;
}

void Bola::set_raio(float r)
{
    m_raio=r;
}

void Bola::set_cor(float cor[4])
{
    m_cor[0]=cor[0];
    m_cor[1]=cor[1];
    m_cor[2]=cor[2];
    m_cor[3]=cor[3];
}

void Bola::show()
{
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);

    glColor4fv(m_cor);
	glBegin(GL_POLYGON);
		for(float theta=0;theta<2*PI;theta+=0.1)
		{
			float x=m_x+m_raio*cos(theta);
			float y=m_y+m_raio*sin(theta);
			glVertex2f(x,y);
		}
	glEnd();
	glDisable(GL_BLEND);
}

float Bola::aleatorio(float a, float b)
{
    float n=((float)rand())/(float)RAND_MAX;
    float amplitude=b-a;
    float result=n*amplitude+a;
    return result;
}
void Bola::update()
{
    m_x+=veloc.x;
    m_y+=veloc.y;
    m_cor[3]-=0.005;
}
bool Bola::continua()
{
    if(m_cor[3]<0)
       destroi=true;
    return destroi;
}
