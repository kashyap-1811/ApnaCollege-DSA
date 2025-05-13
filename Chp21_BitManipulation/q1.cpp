#include <iostream>

using namespace std;

int clear(int num,int i,int j)
{
    int a=(~0)<<(j+1);
    int b=(1<<i)-1;

    int mask=a|b;
    return (num&mask);
}

int main()
{
    int num;
    cout<<"Enter the number: ";
    cin>>num;

    cout<<"Enter bit 1: ";
    int i;cin>>i;

    cout<<"Enter bit 2: ";
    int j;cin>>j;

    int ans=clear(num,i,j);

    cout<<ans;
    return 0;
}