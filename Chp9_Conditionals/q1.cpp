//WriteaC++programtogetanumberfromtheuserandprintwhetherit'spositive,negativeorzero.

#include<iostream>
using namespace std;

int main()
{
    cout<<"Enter a number: ";
    int number;
    cin>>number;

    if(number>0)
    {
        cout<<"Number is positive";
    }
    else if(number==0)
    {
        cout<<"Number is 0";
    }
    else
    {
        cout<<"Number is negative";
    }
    return 0;
}