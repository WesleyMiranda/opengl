#include<iostream>

int main()
{
    int n;
    int mask=1;

    std::cout<<"Digite n: ";
    std::cin>>n;
    if(n&mask)
        std::cout<<"Impar\n";
    else
        std::cout<<"Par\n";
    return 0;
}
