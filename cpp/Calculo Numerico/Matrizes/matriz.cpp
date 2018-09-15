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


