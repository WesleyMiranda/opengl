#pragma once

#include <string>
#define DIM 20

using std::string;

struct Matriz
{
	int linha;
	int coluna;
	double valor[DIM][DIM];
};

void criarMatriz(string s, Matriz* M);
void imprimeMatriz(string s, Matriz M);
Matriz transpostaMatriz(Matriz M);
Matriz somaMatriz(Matriz M, Matriz N);
void trocarLinhas(int i, int j, Matriz* M);
bool saoIguais(double a, double b);
void divideMatriz(int l, double num, Matriz &M);
Matriz rref(Matriz M);
Matriz criarIdentidade(int x);
Matriz Merge(Matriz M, Matriz N);
void SplitMatriz(Matriz M, int d1, int d2, int dd1, int dd2, Matriz* A, Matriz* B);
bool ehIdentidade(Matriz M);
Matriz inversaMatriz(Matriz M);
