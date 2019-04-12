#include "Perceptron.h"
#include<cstdlib>
#include<GL/freeglut.h>
#include<iostream>
#include<iomanip>
#include<cmath>


using std::cout;
using std::endl;

Perceptron::Perceptron()
{
    //weights.resize(3);// reserva 3
    weightsNum=6;
    for(unsigned i=0;i<weightsNum;i++)//wo,w1,w2,w3,w4 e w5
    {
        double w=random(-1,1);
        weights.push_back(w);
    }
    drawCurve=0;//default

}

Perceptron::~Perceptron()
{
    //dtor

}

void Perceptron::print()
{
    using std::setprecision;
    cout<< '\r';
    for(unsigned i=0;i<weights.size();i++)
        cout<<"w["<<i<<"]="<<setprecision(3)<< std::fixed<< weights[i] << " ";
    cout<<std::flush;
}

double Perceptron::random(double a, double b)
{
    double random = ((double) rand()) / (double) RAND_MAX;
    double diff = b - a;
    double r = random * diff;
    return a + r;
}

 double Perceptron::dotProduct(std::vector<double> u, std::vector<double> v)
{
    double sum=0;
    for(unsigned i=0;i<v.size();i++)
        sum+=u[i]*v[i];

    return sum;
}

double Perceptron::predict(std::vector<double> inputs)
{
    double output=dotProduct(inputs,weights);

    return output;
}

double Perceptron::activation(double x) // Activation Function
{


    switch(drawCurve)
    {
    case 1:
        return 1/(1+exp(-x)); // sigmoid(x)
    case 2:
        return (exp(x)-exp(-x))/(exp(x)+exp(-x));//tanh(x)
    default:
            return x; // linear
    }
}

void Perceptron::training(Knots data)
{
    std::vector<double> inputs;
    int m=data.size();

    for(unsigned j=0;j<weights.size();j++)
    {
        double dW=0;
        for(unsigned i=0;i<data.size();i++)
        {

            for(unsigned k=0;k<weightsNum;k++)
                inputs.push_back(pow(data[i].x,k));// enter:1,x,x^2,..,x^n



            double finded=activation(predict(inputs));
            double goal=activation(data[i].y);
           // float actived=1.0/(1.0+exp(-finded));
            //float goal =1.0/(1.0+exp(-data[i].y));
            double error=finded-goal;
            //float error=actived-goal;

            dW+=error*pow(data[i].x,j);
            //somaError+=error*inputs[j];


            inputs.clear();
        }
        weights[j]-=learningCoef*1/m*dW;
    }

}

void Perceptron::plot(double xmin_, double xmax_,float cor[3])
{
    unsigned int totalpts=200;
    int nSubIntervalos=totalpts-1;
    double x=xmin_;
	double y=curve(x);
    double incr=(xmax_-xmin_)/nSubIntervalos;

	glLineWidth(2.5);
	glLineStipple(1, 0xAAAA);
	glEnable(GL_LINE_STIPPLE);
	glColor3fv(cor);
	glBegin(GL_LINE_STRIP);
    for(unsigned i=1; i<=totalpts; i++)
    {
			glVertex2f(x,y);
			x+=incr;
			y=curve(x);
	}
	glEnd();
    glDisable(GL_LINE_STIPPLE);

}

double Perceptron::curve(double x)
{
    double result=0.0;
    for(unsigned i=0;i<weights.size();i++)
        result+=weights[i]*pow(x,i);
    //return weights[0]+x*weights[1]+pow(x,2)*weights[2]+pow(x,3)*weights[3]+pow(x,4)*weights[4]+pow(x,5)*weights[5];
    return result;
}

