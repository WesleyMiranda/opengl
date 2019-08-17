#include "roots.h"
#include <iostream>
#include <locale.h>
using namespace std;

void rootSearch(func f, double a, double b, double dx)
{
	setlocale(LC_ALL, "Portuguese");
	double x1, f1, x2, f2, esp;
	x1 = a;
	f1 = f(a); //f recebe a função px (faz a * a + 1), portanto f1 é y de x = a
	x2 = a + dx;
	f2 = f(x2);
	esp = (b - a) / dx;
	int cont = 1, c1 = 0;
	while (x2 < b)
	{
		if (f1 * f2 > 0)
		{
			c1 = c1 + 1;
		}
		if (f1 * f2 < 0)
		{
			cout << "A " << cont << "ª raíz está entre " << x1 << " e " << x2 << endl;
			cont = cont + 1;
		}
		x1 = x2;
		f1 = f2;
		x2 = x1 + dx;
		f2 = f(x2);
	}
	if (esp == c1)
	{
		cout << "Não há raízes entre " << a << " e " << b << endl;
	}
}