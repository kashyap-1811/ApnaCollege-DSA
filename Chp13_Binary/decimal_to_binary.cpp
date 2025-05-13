#include <iostream>
#include<cmath>
using namespace std;

int main()
{
    int number;
    cout<<"Provide the number: ";
    cin>>number;
    int binary=0;
    int power=0;

    while(number!=0)
    {
        int remainder=number%2;
        cout<<remainder<<" ";
        binary+=remainder*(pow(10,power));
        number/=2;
        power++;
    }
    cout<<endl<<"Binary bits are: "<<binary;
    return 0;
}