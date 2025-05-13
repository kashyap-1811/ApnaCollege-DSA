#include <iostream>

using namespace std;

void fibonacci(int num,int a,int b)
{
    if(num==0)
    {
        return;
    }

    cout<<a<<" ";
    fibonacci(num-1,b,a+b);
}

int main()
{
    int n;
    cout<<"Enter the element: ";
    cin>>n;

    if(n==1)
    {
        cout<<0;
        return 0;
    }

    fibonacci(n,0,1);
    return 0;
}