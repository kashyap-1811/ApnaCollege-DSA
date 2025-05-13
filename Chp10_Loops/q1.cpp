//WAPtofindtheFactorialofanumberenteredbytheuser
#include <iostream>

using namespace std;

int main()
{
    int number;
    cout<<"Enter the number: ";
    cin>>number;
    int factorial=1;
    for(int i=2;i<=number;i++)
    {
       factorial*=i; 
    }
    cout<<"Factorial is: "<<factorial;
    return 0;
}