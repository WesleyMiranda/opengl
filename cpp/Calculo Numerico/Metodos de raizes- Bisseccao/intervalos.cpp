#include<iostream>
#include<cmath>

using namespace std;

typedef float(*Func)(float);

float p3(float x)
{
    return x*x*x-10*x*x+5;
}

float p2(float x)
{
    return x*x-1;
}

void buscaIntervalo(Func f, float& a, float& b, float dx);

int main()
{
    float a=0,b=6;
    buscaIntervalo(p3,a,b,0.002);
    //buscaIntervalo(p2,a,b,0.002);
    cout<<a<<" "<<b<<endl;

    return 0;
}

void buscaIntervalo(Func f, float& a, float& b, float dx)
{
    float x1=a;
    float f1=f(a);
    float x2=a+dx;
    float f2=f(x2);

    while(f1*f2>0)
    {
        x1=x2;
        x2=x1+dx;
        f2=f(x2);
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
