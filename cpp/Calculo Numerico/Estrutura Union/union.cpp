#include <iostream>
#include <bitset>

using namespace std;

union wesley{
	float input;
	int output;
};

int main(){
	
	float f = 7.5;
	wesley w;
	
	w.input=f;
	bitset<32> b= w.output;
	cout<<b;
}