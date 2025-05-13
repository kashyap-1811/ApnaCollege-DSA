//reverse a number

#include <iostream>
#include<cmath>
using namespace std;

int main()
{
    cout<<"Enter a Number: ";
    int number;
    cin>>number;
    int reverse=0,count=0,m=number;
    while(m!=0)
    {
        m/=10;
        count++;
    }
    cout<<"Number of Digits: "<<count<<endl;
    count--;
    while(number!=0)
    {
        int temp=number%10;
        reverse=reverse*10+temp;
        count--;
        number/=10;
    }
    cout<<"Reversed Number is: "<<reverse;
    return 0;
}