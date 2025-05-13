#include <iostream>

using namespace std;

int main()
{
    int a=32;
    int *ptr=&a;

    char ch='A';
    char &cho=ch;

    cho+=a;
    *ptr+=ch;
    cout<<*ptr<<" "<<cho;
    return 0;
}