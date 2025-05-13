#include <iostream>

using namespace std;

int sum(int n)
{
    if(n==1)
        return 1;

    return n+sum(n-1);
}

int main()
{
    int n;
    cout<<"Enter the element: ";
    cin>>n;

    cout<<"sum of first "<<n<<" numbers is:  "<<sum(n);
    return 0;
}