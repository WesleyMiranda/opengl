#include<iostream>
#include<string>
#include "matriz.h"
#include<cstdlib>
#include<iomanip>
#include<cmath>

using namespace std;
using std::setw;
using std::cout;
using std::endl;
using std::cin;
using std::string;

void criarMatriz(string s, Matriz* M)
{
	cout<<s<<endl;
	cout<<"Informe o temanho da matriz quadrada: ";
	cin>>M->linha;
	M->coluna=M->linha;
	
	for(int i=0;i<M->linha;i++)
		for(int j=0;j<M->coluna;j++){
			cout<<"("<<i+1<<","<<j+1<<")= ";	
			cin>>M->valor[i][j];
		}
	cout<<endl;
}


void imprimeMatriz(string s, Matriz M)
{
	cout<<s<<endl;
	for(int i=0;i<M.linha;i++)
	{
		for(int j=0;j<M.coluna;j++)
		{
			cout<<setw(5)<<M.valor[i][j]<<" ";
		}
		cout<<endl;	
	}
	cout<<endl;

}

Matriz transpostaMatriz(Matriz M)
{
	Matriz temp;
	
	temp.linha=M.coluna;
	temp.coluna=M.linha;
	for(int i=0;i<temp.linha;i++)
		for(int j=0;j<temp.coluna;j++)
			temp.valor[i][j]=M.valor[j][i];
	
	return temp;
}
Matriz somaMatriz(Matriz M, Matriz N)
{
	Matriz temp;

	
	temp.linha=M.linha;
	temp.coluna=M.coluna;
	if(M.linha==N.linha && M.coluna==N.coluna)
	{
		for(int i=0;i<M.linha;i++)
			for(int j=0; j<M.coluna;j++)
				temp.valor[i][j]=M.valor[i][j]+N.valor[i][j];
	}
	else
	{
		cout<<"Erro!!! A soma deve ser realizada com matrizes de mesma dimensao!!\n";
		exit(EXIT_FAILURE);
		
	}
	return temp;
	
}

void trocarLinhas(int i, int j, Matriz* M)
{
	double t;
	for(int k=0;k<M->coluna;k++)
	{
		t=M->valor[i][k];
		M->valor[i][k]=M->valor[j][k];
		M->valor[j][k]=t;
	}
}


bool saoIguais(double a, double b)
{

	double precisao=1.0e-8;
	return abs(a-b)<precisao;
	
}

void divideMatriz(int l,double num,Matriz &M, Matriz &N)
{
	for(int j=0;j<M.coluna;j++){
		M.valor[l][j]/=num;
		N.valor[l][j]/=num;
		}
}

Matriz Identidade(double x)
{
	Matriz I;
	I.coluna=I.linha=x;
	for(int i=0; i<x; i++){
		for(int j=0; j<x; j++){
			if (j==i)
				I.valor[i][j]=1;
			else
				I.valor[i][j]=0;
		}
	}
	return I;	
}

Matriz Inversa(Matriz M)
{
	int lead=0;
	int rowCount=M.linha;
	int columnCount=M.coluna;
	Matriz I=Identidade(M.linha);
	
	for(int r=0;r<rowCount;r++)
	{
		if(columnCount<=lead)
		break;
		int i=r;
		while(saoIguais(M.valor[i][lead],0.0))
		{
			i++;
			if(i>rowCount)
			{
				cout<<"Esta matriz nao possue inversa";
				exit(EXIT_FAILURE);
			}
		}//while
		
		trocarLinhas(i,r, &M);
		trocarLinhas(i,r, &I);
		double pivo=M.valor[r][lead];
		divideMatriz(r,pivo,M, I);
		for(int k=0;k<M.linha;k++)
		{
			if(k!=r)
			{
				pivo=-M.valor[k][lead];
				for(int j=0;j<M.coluna;j++)
				{
					M.valor[k][j]+=pivo*M.valor[r][j];
					I.valor[k][j]+=pivo*I.valor[r][j];
				}
			}
		}
		lead++;
	}//prox r
	return I;
}

int main()
{
	Matriz A;
	
	criarMatriz("Criar Matriz A",&A);
	Matriz B = Inversa(A);
	imprimeMatriz("Imprimindo Nova Matriz Inversa", B);
	return 0;
}
