#pragma once

typedef double(*func)(double);
void rootSearch(func f, double a, double b, double dx);