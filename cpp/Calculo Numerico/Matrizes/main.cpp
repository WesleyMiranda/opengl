#include "matriz.h"

int main()
{
	Matriz A;
	criarMatriz("Criar Matriz A", &A);
	imprimeMatriz("Sua inversa eh: \n", inversaMatriz(A));
	
	system("pause");
	return 0;
}
