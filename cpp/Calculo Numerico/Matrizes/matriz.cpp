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

