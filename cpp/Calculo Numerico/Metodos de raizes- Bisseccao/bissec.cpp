#include<iostream>
#include<cstdlib>
#include<cmath>

using namespace std;

typedef float(*Func)(float);
float bissec(Func f, float a, float b,float precisao);


float p3(float x)
{
    return x*x*x-10*x*x+5;
}

float p2(float x)
{
    return x*x+x-6;// raizes -3 e 2
}

int main()
{
    float raiz=bissec(p3,0,6,1e-4);
   // float raiz=bissec(p2,-10,0,1e-9);
    cout.precision(10);
    cout<<"Raiz = "<<raiz<<endl;

    return 0;
}

float bissec(Func f, float a, float b,float precisao)
{
    float x1=a;
    float f1=f(x1);
    if(f1==0)
        return x1;

    float x2=b;
    float f2=f(x2);
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
        float xk=0.5*(x1+x2);
        float fk=f(xk);
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
