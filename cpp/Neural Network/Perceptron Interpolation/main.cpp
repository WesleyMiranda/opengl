#include<GL/freeglut.h>
#include<vector>
#include<cmath>
#include<iostream>
#include<windows.h>
#include <numeric>

#include "cg.h"
#include "Perceptron.h"


int LARGURA=640;
int ALTURA=480;
const int FPS=300;
unsigned int nPts=10;

float xmin=-2;
float xmax=2;
float ymin=-2;
float ymax=2;


double funcao(double x);
void display();
void init();
void trainingNeuron(int botao, int status, int x, int y);
void idle(int x);

Knots data; // vector of points(x,y)
POINT p;

Perceptron neuron=Perceptron();

std::vector<double>average;
std::vector<double>stdev;

Function myFunc;

int main(int argc, char* argv[])
{
    SetConsoleTitle(" Curve Fitting with Single Layer Perceptron - UFR -  May 2019");
	glutInit(&argc, argv);
    init();

	glutDisplayFunc(display);
	glutTimerFunc(1000/FPS,idle,0);

	glutMainLoop();

	return 0;
}

double funcao(double x)
{
    return sin(x)*cos(2*x);
}

void init()
{
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowSize(LARGURA, ALTURA);
	glutInitWindowPosition(800,150);

	glutCreateWindow("Ajuste de Curvas - Perceptron  - UFR - Maio de  2019");

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluOrtho2D(xmin,xmax,ymin,ymax);

    myFunc=funcao;
    cg::ExtractPoints(myFunc,nPts,data,xmin,xmax);// Extract 10 points from f(x), x in [xmin. xmax] and stpres it in data


    std::cout<<"----------------------------------------"<<std::endl;
    std::cout<<"Fitting f(x)=SIN(X)*COS(2X)\n"<<std::endl;
    std::cout<<"Approximate f(x) by a polynomial of degree 5\n";
    std::cout<<"Extracting "<<nPts<<" points.\n";
    std::cout<<"p(X)=wo+w1X+w2X^2+w3X^3+w4X^4+w5X^5\n\n";

    std::cout<<"\n\n Weights by Linear Activate Function F(x)=x\n";



}


void display()
{
    glClearColor(1, 1, 1, 1);
    glClear(GL_COLOR_BUFFER_BIT);

    float cor[]={0,1,1};
    cg::Line(xmin,0,xmax,0,cor,3.0);
    cg::Line(0,ymin,0,ymax,cor,3.0);

    float corFunc[]={1,0,0};

    float colorPoints[]={0.3,0.5,1.0};

    cg::PlotPoints(data,colorPoints);

   float PerceptronColor[]={0,0,0};
   neuron.plot(xmin,xmax,PerceptronColor);
   neuron.print();


    glutSwapBuffers();
}

void idle(int x)
{
    neuron.training(data);
   	glutPostRedisplay();
	glutTimerFunc(1000/FPS,idle,0);
}

