#include "ponto_fixo.h"
#include<iostream>

ponto_fixo::ponto_fixo(unsigned int escala, float valor)
{
    mvalor=valor;
    mescala=escala;
    calcula();

}

ponto_fixo::ponto_fixo()
{
    mescala=4;
    mvalor=0;
}

void ponto_fixo::cvtFloat_Fixo()
{
   mfixo=mvalor*(1<<mescala);
   // return f*pow(2,escala);
}

