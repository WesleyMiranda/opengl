#pragma once

#include<vector>
#include<string>


using std::vector;
using std::string;

struct MyRGB{
	float R;
	float G;
	float B;
	MyRGB(float R_, float G_, float B_)
	{
		R=R_;
		G=G_;
		B=B_;
	}	
};

struct Ponto2{
	double x;
	double y;
	Ponto2(double x_, double y_)
	{
		x=  x_;
		y=y_;	
	}
};


typedef double (*Funcao)(double);
typedef vector<Ponto2> Pontos;
typedef vector<double> Coeficiente;


void cgLinha(double x1, double y1, double x2, double y2,MyRGB cor);
void cgDesenhaEixos(double xmin_,double xmax_, double ymin_, double ymax_, MyRGB cor);
void cgCriaPontos(Funcao f, int n, Pontos& P, double xmin_, double xmax_);
void cgPlotPontos(Pontos P, MyRGB cor);
void cgPlotFunc(Funcao f, double xmin_, double xmax_,MyRGB cor, int n);
void cgText(string mytext, float x,float y);
