#include <iostream>
#include <cstdint>
#include <cstring>

using namespace std;

int main(){
    uint32_t hexa;
    float decimal;

    cin >> hex >> hexa;

    memcpy(&decimal, &hexa, sizeof(hexa));

    cout << decimal;

    return 0;
}
