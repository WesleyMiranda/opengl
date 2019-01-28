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


