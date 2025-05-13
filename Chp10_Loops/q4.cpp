//ForapositiveN,WAPthatprintsalltheprimenumbersfrom2toN
#include <iostream>
#include<cmath>
using namespace std;

bool primeCheck(int i)
{
    for(int j=2;j<=sqrt(i);j++)
    {
        if(i%j==0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int number;
    cout<<"Provide the Number: ";
    cin>>number;

    for(int i=2;i<=number;i++)
    {
        bool isPrime=primeCheck(i);
        if(isPrime==true)
        {
            cout<<"Prime Number is: "<<i<<endl;
        }
    }
    return 0;
}