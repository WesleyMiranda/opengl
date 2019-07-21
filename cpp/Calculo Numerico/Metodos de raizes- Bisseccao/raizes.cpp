#include<iostream>
#include<cmath>
#include<cstdlib>
#include<windows.h>
using namespace std;

typedef double(*Func)(double);
void buscaIntervalo(Func f, double& a, double& b, double dx);
double bissec(Func f, double a, double b,double precisao);
void listaRaizes(Func f, double a, double b,double dx);

double p7(double x)
{
    return pow(x,7)+10*pow(x,6)+27*pow(x,5)-57*pow(x,3)-30*x*x+29*x+20;
} //x^7+10x^6+27x^5-57x^3-30x^3+29x^2+20
double p2(double x)
{
    return x*x-4;//x^2-4=0
}
double p31(double x)
{
    return x*x*x-10*x*x+5; //x^3-10x^2+5=0
}
double p32(double x)
{
    return x*x*x+2*x*x-5*x-6;//x^3+2x^2-5x-6=0
}

int main()
{
    SetConsoleTitle("Encontra Raizes --- UFR/ICAT/EngMec/2019_02");
    listaRaizes(p7,-100,100,1e-9);

    return 0;
}

void listaRaizes(Func f, double ao, double bo,double dx)
{
    double a=ao;
    double b=bo;
    bool continua=true;

    while(continua)
    {
        buscaIntervalo(f,a,b,0.2);
        if(!isnan(a))
        {
            double raiz=bissec(f,a,b,dx);
            cout<<"Raiz="<<raiz<<endl;
            a=b;
            b=bo;
        }
        else
        {
            cout<<" --- Fim --- "<<endl;
            break;
        }
    }


}
void buscaIntervalo(Func f, double& a, double& b, double dx)
{
    double x1=a;
    double f1=f(a);
    double x2=a+dx;
    double f2=f(x2);
    int passos=0;
    while(f1*f2>0)
    {
        x1=x2;
        x2=x1+dx;
        f2=f(x2);
        passos++;
        if(x1>=b)
            {
                x1=NAN;
                x2=NAN;
                break;
            }
    }
    a=x1;
    b=x2;
}

double bissec(Func f, double a, double b,double precisao)
{
    double x1=a;
    double f1=f(x1);
    if(f1==0)
        return x1;

    double x2=b;
    double f2=f(x2);
    if(f2==0)
        return x2;

    if(f1*f2>0)
    {
        cout<<"Erro na escolha do Intervalo!!!"<<endl;
        exit(0);
    }

    int n=ceil(log(abs(x2-x1)/precisao)/log(2));
    for(int i=0;i<n;i++)
    {
        double xk=0.5*(x1+x2);
        double fk=f(xk);
        if(fk==0)
            return xk;
        if(f1*fk<0)
        {
            x2=xk;
        }
        else
        {
            x1=xk;
        }
    }
    return (x1+x2)/2;
}
