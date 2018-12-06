#pragma once
#include"cg.h"

float L(int i,float x, Pontos P);
void lagrangeInterpola(Pontos P);
void lagrangePlot(Pontos P,double xmin_, double xmax_,MyRGB cor, int n);
float Lagrange(float x, Pontos P);

