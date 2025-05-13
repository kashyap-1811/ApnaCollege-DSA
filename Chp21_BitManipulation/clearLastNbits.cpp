#include <iostream>

using namespace std;

void clearNbits(int num, int i)
{
    int mask=~0<<i;

    num=num&mask;
    cout<<num;
}

int main()
{
    clearNbits(15,2);
    return 0;
}