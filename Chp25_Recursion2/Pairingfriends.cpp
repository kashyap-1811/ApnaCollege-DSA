#include <iostream>

using namespace std;

int pairing(int n)
{
    if(n==0||n==1)
        return 1;

    //single
    int ans1=pairing(n-1);

    //pair
    int ans2=(n-1)*pairing(n-2);

    return ans1+ans2;
}

int main()
{
    int n;
    cout<<"Enter number of friends: ";
    cin>>n;

    cout<<pairing(n);
    return 0;
}