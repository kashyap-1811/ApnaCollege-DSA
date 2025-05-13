//ForapositiveN,WAPthatprintsthefirstNFibonaccinumbers.

#include <iostream>

using namespace std;

int main()
{
    int number;
    cout<<"How many numbers to be printed: ";
    cin>>number;
    int count=0;
    int a=0,b=1,temp;
    while(count!=number)
    {
        cout<<a<<" ";
        temp=b;
        b=a+b;
        a=temp;
        count++;
    }
    return 0;
}