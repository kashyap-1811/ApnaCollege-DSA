#include <iostream>

using namespace std;

int main()
{
    int num;
    cout<<"Enter the number: ";
    cin>>num;

    if((num&(num-1))==0)
    {
        cout<<num<<" is a power of 2";
    }
    else
    {
        cout<<num<<" is not a power of 2";
    }
    return 0;
}