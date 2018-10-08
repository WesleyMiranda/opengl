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


Matriz rref(Matriz M)
{
	int lead = 0;
	int rowCount = M.linha;
	int columnCount = M.coluna;

	for (int r = 0; r < rowCount; r++)
	{
		if (columnCount <= lead)
			break;
		int i = r;
		while (saoIguais(M.valor[i][lead], 0.0))
		{
			i++;
			if (i == rowCount)
			{
				i = r;
				lead++;
				if (lead == columnCount)
					return M;
			}
		}//while

		trocarLinhas(i, r, &M);
		double pivo = M.valor[r][lead];
		divideMatriz(r, pivo, M);
		for (int k = 0; k < M.linha; k++)
		{
			if (k != r)
			{
				pivo = -M.valor[k][lead];
				for (int j = 0; j < M.coluna; j++)
					M.valor[k][j] += pivo * M.valor[r][j];
			}
		}
		lead++;
	}//prox r

	return M;
}

Matriz criarIdentidade(int x) {

	Matriz Temp;
	Temp.linha = Temp.coluna = x;

	for (int i = 0; i < x; i++) {
		for (int j = 0; j < x; j++) {
			if (i == j)
				Temp.valor[i][j] = 1.0;
			else
				Temp.valor[i][j] = 0.0;
		}
	}

	return Temp;
}

Matriz Merge(Matriz M, Matriz N) {

	if (N.linha == M.linha) {
		Matriz Temp;
		Temp.linha = M.linha;
		Temp.coluna = M.coluna + N.coluna;

		//Bloco1
		for (int i = 0; i < M.linha; i++)
			for (int j = 0; j < M.coluna; j++)
				Temp.valor[i][j] = M.valor[i][j];

		//Bloco2
		for (int i = 0; i < N.linha; i++)
			for (int j = 0; j < N.linha; j++)
				Temp.valor[i][M.coluna + j] = N.valor[i][j];

		return Temp;
	}

	else
	{
		cout << "ERRO! Não eh possivel mesclar matrizes com quantidade  de linhas diferentes\n";
		system("pause");
		exit(EXIT_FAILURE);
	}
}

void SplitMatriz(Matriz M, int d1, int d2, int dd1, int dd2, Matriz* A, Matriz* B) {

	A->linha = d1;
	A->coluna = d2;
	B->linha = dd1;
	B->coluna = dd2;

	//Bloco1
	for (int i = 0; i < d1; i++)
		for (int j = 0; j < d2; j++)
			A->valor[i][j] = M.valor[i][j];

	//Bloco2
	for (int i = 0; i < dd1; i++)
		for (int j = 0; j < dd2; j++)
			B->valor[i][j] = M.valor[i][j + d2];
}

bool ehIdentidade(Matriz M) {
	for (int i = 0; i < M.linha; i++) {
		for (int j = 0; j < M.coluna; j++) {
			if ((i == j) && !saoIguais(M.valor[i][j], 1.0))
				return false;

			if ((i != j) && !saoIguais(M.valor[i][j], 0.0))
				return false;

		}
	}
	return true;
}
