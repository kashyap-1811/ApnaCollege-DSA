#include<iostream>
#include<cmath>
using namespace std;

int main()
{
    int binary;
    cout<<"Provide the binary number: ";
    cin>>binary;
    int power=0;
    int result=0;

    while(binary!=0)
    {
        int temp=binary%2;
        result+=temp*pow(2,power);
        power++;
        binary/=10;
    }
    cout<<"the decimal number is: "<<result;
    return 0;
}