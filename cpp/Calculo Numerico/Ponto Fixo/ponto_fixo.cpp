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

float ponto_fixo::cvtFixo_Float(int i)
{
    //return i/pow(2,escala);
    return (float)i/(1<<mescala);
}

void ponto_fixo::calcula()
{
    cvtFloat_Fixo();
    mresult=cvtFixo_Float(mfixo);
}

float ponto_fixo::show()
{
    calcula();
    return mresult;
}

void ponto_fixo::mprint()
{
    calcula();
    std::cout<< mresult<<std::endl;
}
