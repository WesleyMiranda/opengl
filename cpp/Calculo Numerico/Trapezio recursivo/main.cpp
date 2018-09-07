/// MÉTODO DOS TRAPÉZIOS

#include <iostream>
#include <cmath>

using namespace std;

typedef double(*Function)(double);

double g(double x) {
    //return((4 + 8 * x) * cosh(2 * x));
    return x * x;
}

double Trapezio(Function f, double a, double b, int m) {

    if (a > b) { ///condição para que o valor de b seja sempre o maior valor
        double aux;
        aux = a;
        a = b;
        b = aux;
    }

    double n = pow(2, m), aux = pow(2, m - 1);
    double h = (b - a) / n;

    if (m == 0) {

        return h * (f(a) + f(b)) / 2;

    }

    double I = Trapezio(f, a, b, m - 1);



    double x, y = 0;

    for (int i = 0; i < aux; i++) {
        x = a + (2 * i + 1) * h;
        y += f(x);
    }

    I = I / 2 + y * h;


    return I;
}

int main() {
    double a = 0, b = 1;
    double result_trapezio = Trapezio(g, a, b, 3);

    std::cout.precision(20);
    std::cout << "Trapezio: " << result_trapezio << "\n";

    std::cin.get();
    return 0;
}