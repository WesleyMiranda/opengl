#include<iostream>
#include<bitset>
#include<cstring>
#include<cmath>
using namespace std;

int main()
{
	float f ; // Not a number
	float fMax = FLT_MIN;

	int n=0x00800000; // auxiliar para passar os bits para o bitset
	
	bitset<32> fbits; //  recebe os bits do float

	memcpy(&f, &n, sizeof(float)); // (destino, fonte, copia sizeof bytes da fonte para o destino)
	
	fbits = n;

	cout << " Bits do FLOAT " << f << " = " << fbits << hex << uppercase << " = " << n << endl;
	cout << "Maior Float = " << fMax << endl;

	cout << "--- PRESSIONE <ENTER> PARA SAIR ---\n";
	cin.get();
	return 0;
}