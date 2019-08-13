#include<iostream>
#include<bitset>
#include<cstring>

using namespace std;

template<typename T1, typename T2>
void copia(T1& fonte, T2& destino) {
	memcpy(&destino, &fonte,4);
}

int main() {

	float f; 
	int n=1;
	bitset<32> fbits;
	float minSubnormal = numeric_limits<float>::denorm_min();
	
	copia(n, f);
	fbits = n;

	cout << "Float: " << f << endl;
	cout<<"Bits: " << fbits<<" = "<<hex << n << endl;
	cout << "Valor: " << minSubnormal << endl;
	cout << "--- PRESSIONE <ENTER> PARA SAIR ---\n";

	cin.get();
	return 0;
}