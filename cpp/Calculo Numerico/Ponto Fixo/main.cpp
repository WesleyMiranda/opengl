#include <iostream>
#include<cmath>
#include"ponto_fixo.h"


using namespace std;


int main()
{
 //   ponto_fixo num(4,4.1);

    ponto_fixo num;
    num.mvalor=4.1;

    cout.precision(10);
    num.mprint();
    num.mescala=8;
    num.mprint();
    num.mescala=10;
    num.mprint();
    return 0;
}


