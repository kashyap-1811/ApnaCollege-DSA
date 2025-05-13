#include <iostream>

using namespace std;

void decendingPrint(int num)
{
    if(num==0)
        return;
    
    cout<<num<<" ";
    decendingPrint(num-1);
}

void ascendingPrint(int num)
{
    if(num==0)
        return;
    
    ascendingPrint(num-1);
    cout<<num<<" ";
}


int main()
{
    int n;
    cout<<"Enter the element: ";
    cin>>n;

    decendingPrint(n);
    cout<<endl;
    ascendingPrint(n);
    return 0;
}