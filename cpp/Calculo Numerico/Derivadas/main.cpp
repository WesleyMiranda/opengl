#include<iostream>
#include<cmath>

using namespace std;

struct Vetor
{
    float x,y;
    Vetor();
    Vetor(float a, float b);
    void imprimeVetor(char c);
    float norma();

};

Vetor::Vetor()
{
    x=0;
    y=0;
}

Vetor::Vetor(float a, float b)
{
    x=a;
    y=b;
}

void Vetor::imprimeVetor(char c)
{
    cout<<c<<"=("<<x<<","<<y<<")"<<endl;
}

float Vetor::norma()
{
    return sqrt(x*x+y*y);
}

int main()
{
    Vetor u;
    Vetor v=Vetor(3,4);
    u.imprimeVetor('u');
    v.imprimeVetor('v');
    cout<<"Norma de u="<<u.norma()<<endl;
    cout<<"Norma de v="<<v.norma()<<endl;
    return 0;
}
