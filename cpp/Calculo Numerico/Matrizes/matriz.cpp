#include<iostream>
#include<string>
#include<cstdlib>
#include<iomanip>
#include<cmath>
#include "matriz.h"

using namespace std;

using std::setw;
using std::cout;
using std::endl;
using std::cin;
using std::string;

void criarMatriz(string s, Matriz* M)
{
	cout<<s<<endl;
	cout<<"Linhas: ";
	cin>>M->linha;
	cout<<"Colunas: ";
	cin>>M->coluna;
	
	for(int i=0;i<M->linha;i++)
		for(int j=0;j<M->coluna;j++){
			cout<<"("<<i+1<<","<<j+1<<")= ";	
			cin>>M->valor[i][j];
		}
	cout<<endl;
}

void imprimeMatriz(string s, Matriz M)
{
	cout << s << endl;
	for (int i = 0; i < M.linha; i++)
	{
		for (int j = 0; j < M.coluna; j++)
		{
			cout << setw(5) << M.valor[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;

}

Matriz transpostaMatriz(Matriz M)
{
	Matriz temp;

	temp.linha = M.coluna;
	temp.coluna = M.linha;
	for (int i = 0; i < temp.linha; i++)
		for (int j = 0; j < temp.coluna; j++)
			temp.valor[i][j] = M.valor[j][i];

	return temp;
}


Matriz somaMatriz(Matriz M, Matriz N)
{
	Matriz temp;


	temp.linha = M.linha;
	temp.coluna = M.coluna;
	if (M.linha == N.linha && M.coluna == N.coluna)
	{
		for (int i = 0; i < M.linha; i++)
			for (int j = 0; j < M.coluna; j++)
				temp.valor[i][j] = M.valor[i][j] + N.valor[i][j];
	}
	else
	{
		cout << "Erro!!! A soma deve ser realizada com matrizes de mesma dimensao!!\n";
		exit(EXIT_FAILURE);

	}
	return temp;

}

void trocarLinhas(int i, int j, Matriz* M)
{
	double t;
	for (int k = 0; k < M->coluna; k++)
	{
		t = M->valor[i][k];
		M->valor[i][k] = M->valor[j][k];
		M->valor[j][k] = t;
	}
}

bool saoIguais(double a, double b)
{

	double precisao = 1.0e-8;
	return abs(a - b) < precisao;

}

void divideMatriz(int l, double num, Matriz& M)
{
	for (int j = 0; j < M.coluna; j++)
		M.valor[l][j] /= num;
}
